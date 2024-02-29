`timescale          1ns/1ps
`default_nettype    none




                                                    /*
	Copyright 2020 AUCOHL

    Author: Mohamed Shalan (mshalan@aucegypt.edu)
	
	Licensed under the Apache License, Version 2.0 (the "License"); 
	you may not use this file except in compliance with the License. 
	You may obtain a copy of the License at:

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software 
	distributed under the License is distributed on an "AS IS" BASIS, 
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
	See the License for the specific language governing permissions and 
	limitations under the License.
*/

`timescale			    1ns/1ps
`default_nettype		none




/*
    Brute-force Synchronizer
*/
module aucohl_sync #(parameter NUM_STAGES = 2) (
    input clk,
    input in,
    output out
);

    reg [NUM_STAGES-1:0] sync;

    always @(posedge clk)
        sync <= {sync[NUM_STAGES-2:0], in};

    assign out = sync[NUM_STAGES-1];

endmodule

/*
    A positive edge detector
*/
module aucohl_ped (
    input clk,
    input in,
    output out
);
    reg last_in; always @(posedge clk) last_in <= in; assign out = in & ~last_in;
endmodule

/*
    A negative edge detector
*/
module aucohl_ned (
    input clk,
    input in,
    output out
);
    reg last_in; always @(posedge clk) last_in <= in; assign out = ~in & last_in;
endmodule

/*
    A tick generator
*/
module aucohl_ticker #(parameter W=8) (
    input   wire            clk, 
    input   wire            rst_n,
    input   wire            en,
    input   wire [W-1:0]    clk_div,
    output  wire            tick
);

    reg [W-1:0] counter;
    wire        counter_is_zero = (counter == 'b0);
    wire        tick_w;
    reg         tick_reg;

    always @(posedge clk, negedge rst_n)
        if(~rst_n)
            counter <=  'b0;
        else if(en) 
            if(counter_is_zero)
                counter <=  clk_div;
            else
                counter <=  counter - 'b1; 

	assign tick_w = (clk_div == 'b0)  ?   1'b1 : counter_is_zero;

    always @(posedge clk or negedge rst_n)
        if(!rst_n)
            tick_reg <= 1'b0;
        else if(en)
            tick_reg <= tick_w;
        else
            tick_reg <= 0;

    assign tick = tick_reg;

endmodule

/*
    A glitch filter
*/
module aucohl_glitch_filter #(parameter N = 8, CLKDIV = 8'b1) (
    input   wire    clk,
    input   wire    rst_n,
    input   wire    in,
    input   wire    en,
    output  reg     out
);

    reg [N-1:0] shifter;
    wire        tick;

    aucohl_ticker#(8) ticker (
        .clk(clk),
        .rst_n(rst_n),
	.en(en),
        .clk_div(CLKDIV),
        .tick(tick)
    );

    always @(posedge clk, negedge rst_n)
        if(!rst_n)
            shifter = 'b0;
        else if(tick)
            shifter <= {shifter[N-2:0], in};

    wire all_ones   = & shifter;
    wire all_zeros  = ~| shifter;

    always @(posedge clk, negedge rst_n)
        if(!rst_n)
            out <= 1'b0;
        else
            if(all_ones) 
                out <= 1'b1;
            else if(all_zeros) 
                out <= 1'b0;
endmodule

/*
    A FIFO
*/
module aucohl_fifo #(parameter DW=8, AW=4)(
    input     wire            clk,
    input     wire            rst_n,
    input     wire            rd,
    input     wire            wr,
    input     wire [DW-1:0]   wdata,
    output    wire            empty,
    output    wire            full,
    output    wire [DW-1:0]   rdata,
    output    wire [AW-1:0]   level    
);

    localparam  DEPTH = 2**AW;

    //Internal Signal declarations
    reg [DW-1:0]  array_reg [DEPTH-1:0];
    reg [AW-1:0]  w_ptr_reg;
    reg [AW-1:0]  w_ptr_next;
    reg [AW-1:0]  w_ptr_succ;
    reg [AW-1:0]  r_ptr_reg;
    reg [AW-1:0]  r_ptr_next;
    reg [AW-1:0]  r_ptr_succ;

    // Level
    reg [AW-1:0] level_reg;
    reg [AW-1:0] level_next;      
    reg full_reg;
    reg empty_reg;
    reg full_next;
    reg empty_next;

    wire w_en;

    always @ (posedge clk)
        if(w_en) begin
            array_reg[w_ptr_reg] <= wdata;
        end

    assign rdata = array_reg[r_ptr_reg];   
    assign w_en = wr & ~full_reg;           

    //State Machine
    always @ (posedge clk, negedge rst_n) begin 
    if(!rst_n)
        begin
            w_ptr_reg <= 'b0;
            r_ptr_reg <= 'b0;
            full_reg  <= 1'b0;
            empty_reg <= 1'b1;
            level_reg <= 4'd0;
        end
    else
        begin
            w_ptr_reg <= w_ptr_next;
            r_ptr_reg <= r_ptr_next;
            full_reg  <= full_next;
            empty_reg <= empty_next;
            level_reg <= level_next;
        end
    end

    //Next State Logic
    always @* begin
        w_ptr_succ = w_ptr_reg + 1;
        r_ptr_succ = r_ptr_reg + 1;

        w_ptr_next = w_ptr_reg;
        r_ptr_next = r_ptr_reg;
        full_next = full_reg;
        empty_next = empty_reg;
        level_next = level_reg;

        case({w_en,rd})
            //2'b00: nop
            2'b01: 
                if(~empty_reg) begin
                    r_ptr_next = r_ptr_succ;
                    full_next = 1'b0;
                    level_next = level_reg - 1;
                    if (r_ptr_succ == w_ptr_reg)
                        empty_next = 1'b1;
                end
            
            2'b10: 
                if(~full_reg) begin
                    w_ptr_next = w_ptr_succ;
                    empty_next = 1'b0;
                    level_next = level_reg + 1;
                    if (w_ptr_succ == r_ptr_reg)
                        full_next = 1'b1;
                end
            
            2'b11: begin
                w_ptr_next = w_ptr_succ;
                r_ptr_next = r_ptr_succ;
            end
        endcase
    end

    //Set Full and Empty
    assign full = full_reg;
    assign empty = empty_reg;
    assign level = level_reg;
  
endmodule



module EF_TMR32 #(parameter PRW = 16,
                                PWM_FAULT_CLR_C0 = 16'hA539,
                                PWM_FAULT_CLR_C1 = 16'hA953 
)
(
    input   wire            clk,
    input   wire            rst_n,

    input   wire            tmr_en,
    input   wire            tmr_start,
    input   wire            pwm0_en,
    input   wire            pwm1_en,
    input   wire [31:0]     tmr_reload,
    input   wire [31:0]     cmpx,
    input   wire [31:0]     cmpy,
    input   wire [PRW-1:0]  prescaler,
    input   wire [ 2:0]     tmr_cfg,     // [2]: Periodic/OneShot; [1:0]: 10: Up, 01: Down, 11: Up/Down
    input   wire [11:0]     pwm0_cfg,
    input   wire [11:0]     pwm1_cfg,
    input   wire            pwm0_inv,
    input   wire            pwm1_inv,
    input   wire [ 7:0]     pwm_dt,
    input   wire [15:0]     pwm_fault_clr,
    input   wire            pwm_dt_en,

    output  wire [31:0]     tmr,
    output  wire            matchx_flag,
    output  wire            matchy_flag,
    output  wire            timeout_flag,
    
    input   wire            pwm_fault,
    output  wire            pwm0,
    output  wire            pwm1
);

    wire [1:0]      tmr_mode        = tmr_cfg[1:0];
    wire            tmr_periodic    = tmr_cfg[2];

    reg [31:0]      tmr_reg;
    reg [PRW-1:0]   pr_reg;

    wire            tmr_clr;

    wire            tmr_en_pulse = tmr_clr;
    reg             tmr_run;

    reg             fault_reg;

    aucohl_ped TMREN_PE (
        .clk(clk),
        .in(tmr_en),
        .out(tmr_clr)
    );

    wire tick = (pr_reg == 0);
    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) pr_reg <= 1;
                                                    else
        if(tmr_en)
            if(tick) pr_reg <= prescaler; 
            else pr_reg <= pr_reg - 1; 
        else
            pr_reg <= prescaler ;

    reg         tmr_dir;        // 1: Up, 0: Down
    wire        tmr_eq_reload       =   (tmr == tmr_reload);
    wire        tmr_eq_zero         =   (tmr == 0);
    wire        tmr_eq_reload_m_1   =   (tmr == (tmr_reload - 1));
    wire        tmr_eq_one          =   (tmr == 1);
    wire        tmr_eq_cmpx         =   (tmr == cmpx);
    wire        tmr_eq_cmpy         =   (tmr == cmpy);

    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) tmr_run <= 0;
                                                    else
        if(tmr_en_pulse)
            tmr_run <= 1;
        else if(~tmr_periodic & tick)
            if((tmr_mode[0] == 1'b1) & tmr_eq_one & ~tmr_dir)
                tmr_run <= 0;
            else if((tmr_mode == 2'b10) & tmr_eq_reload_m_1 & tmr_dir)
                tmr_run <= 1;


    // The timer
    reg [31:0]  tmr_reg_next;

    always@* begin
        tmr_reg_next = tmr_reg;
        if(~tmr_run)
            tmr_reg_next = tmr_reg;    
        else if(tmr_start & (tmr_mode == 2'b01))
            tmr_reg_next = tmr_reload;
        else if(tmr_start & (tmr_mode == 2'b10))
            tmr_reg_next = 0;
        else if(tmr_start & (tmr_mode == 2'b11))
            tmr_reg_next = 0;
        else if(tmr_mode == 2'b11) begin
            if(tmr_dir)
                tmr_reg_next = tmr_reg + 1;
            else
                tmr_reg_next = tmr_reg - 1; 
        end
        else if((tmr_mode == 2'b01))
            if(tmr_eq_zero)
                tmr_reg_next = tmr_periodic ? tmr_reload : tmr_reg;
            else
                tmr_reg_next = tmr_reg_next - 1;    
        else if((tmr_mode == 2'b10))
            if(tmr_eq_reload)
                tmr_reg_next = tmr_periodic ? 0 : tmr_reg;
            else
                tmr_reg_next = tmr_reg_next + 1;
    end

    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) tmr_reg <= 0;
                                                    else
    if(tmr_en)
        if(tmr_clr)
            if(tmr_mode == 2'b01)
                tmr_reg <= tmr_reload;
            else
                tmr_reg <= 0;
        else 
            if(tick)
                tmr_reg <=  tmr_reg_next;

    // The counting direction flag
    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) tmr_dir <= 1;
                                                    else
        if(tmr_clr)
            if(tmr_mode == 2'b01)
                tmr_dir <= 0;
            else
                tmr_dir <= 1;
        else if(tick)
            if(tmr_mode == 2'b11) begin
                if(tmr_eq_one & ~tmr_dir) 
                    tmr_dir <= 1;
                else if(tmr_eq_reload_m_1 & tmr_dir)
                    tmr_dir <= 0;
            end
            else if(tmr_mode == 2'b10)
                tmr_dir <= 1'b1;
            else if(tmr_mode == 2'b01)
                tmr_dir <= 1'b0;
            else
                tmr_dir <= 1'b1;

    // PWM Generator
    function pwm_action(input [1:0] action, input sig);
        case (action)
            2'b00: pwm_action = sig;
            2'b01: pwm_action = 0;
            2'b10: pwm_action = 1;
            2'b11: pwm_action = ~sig; 
        endcase
    endfunction 

    reg     pwm0_reg, pwm0_reg_next;
    reg     pwm1_reg, pwm1_reg_next;

    always @* begin
        casez({tmr_dir, tmr_eq_zero, tmr_eq_cmpx, tmr_eq_cmpy, tmr_eq_reload})
            5'b?_1_00_0 : pwm0_reg_next = pwm_action(pwm0_cfg[ 1: 0], pwm0_reg);    // U/D, 0
            5'b1_0_10_0 : pwm0_reg_next = pwm_action(pwm0_cfg[ 3: 2], pwm0_reg);    // U, CMPX
            5'b1_0_01_0 : pwm0_reg_next = pwm_action(pwm0_cfg[ 5: 4], pwm0_reg);    // U, CMPY
            5'b?_0_00_1 : pwm0_reg_next = pwm_action(pwm0_cfg[ 7: 6], pwm0_reg);    // U/D, RELOAD
            5'b0_0_01_0 : pwm0_reg_next = pwm_action(pwm0_cfg[ 9: 8], pwm0_reg);    // D, CMPY
            5'b0_0_10_0 : pwm0_reg_next = pwm_action(pwm0_cfg[11:10], pwm0_reg);    // D, CMPX
            default     : pwm0_reg_next = pwm0_reg;
        endcase        
    end

    always @* begin
        casez({tmr_dir, tmr_eq_zero, tmr_eq_cmpx, tmr_eq_cmpy, tmr_eq_reload})
            5'b?_1_00_0 : pwm1_reg_next = pwm_action(pwm1_cfg[ 1: 0], pwm1_reg);    // U/D, 0
            5'b1_0_10_0 : pwm1_reg_next = pwm_action(pwm1_cfg[ 3: 2], pwm1_reg);    // U, CMPX
            5'b1_0_01_0 : pwm1_reg_next = pwm_action(pwm1_cfg[ 5: 4], pwm1_reg);    // U, CMPY
            5'b?_0_00_1 : pwm1_reg_next = pwm_action(pwm1_cfg[ 7: 6], pwm1_reg);    // U/D, RELOAD
            5'b0_0_01_0 : pwm1_reg_next = pwm_action(pwm1_cfg[ 9: 8], pwm1_reg);    // D, CMPY
            5'b0_0_10_0 : pwm1_reg_next = pwm_action(pwm1_cfg[11:10], pwm1_reg);    // D, CMPX
            default     : pwm1_reg_next = pwm1_reg;
        endcase        
    end

    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) pwm0_reg <= 0;
                                                    else
        if(pwm0_en & tick)
            if(pwm_fault)
                pwm0_reg <= 0;
            else
                pwm0_reg <= pwm0_reg_next;

    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) pwm1_reg <= 0;
                                                    else
        if(pwm1_en & tick)
            if(pwm_fault)
                pwm1_reg <= 0;
            else
                pwm1_reg <= pwm1_reg_next;


    // Dead time insertion
    reg pwm0_delayed;
    reg [7:0] dly_cntr;
    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) dly_cntr <= 0;
                                                    else
        if(tick)
            if(dly_cntr == 0)
                dly_cntr <= pwm_dt;
            else 
                dly_cntr <= dly_cntr - 1;
                
    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) pwm0_delayed <= 0;
                                                    else
        if(tick)
            if(dly_cntr == 0)
                pwm0_delayed <= pwm0_reg;

    reg pwm0_w_dt, pwm1_w_dt;
    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) pwm0_w_dt <= 0;
                                                    else
        pwm0_w_dt <= pwm_dt_en ? (pwm0_delayed & pwm0_reg) : pwm0_reg;

    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) pwm1_w_dt <= 0;
                                                    else
        pwm1_w_dt <= pwm_dt_en ? (~pwm0_delayed & ~pwm0_reg) : pwm1_reg;
    
    // PWM Fault Handeling
    reg fault_clr_reg;
    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) fault_clr_reg <= 0;
                                                    else
        if(pwm_fault_clr == PWM_FAULT_CLR_C0)
            fault_clr_reg <= 1;
        else if(pwm_fault_clr == PWM_FAULT_CLR_C1)
            fault_clr_reg <= 0;
    always @(posedge clk, negedge rst_n)
                                                    if(!rst_n) fault_reg <= 0;
                                                    else
        if(pwm_fault)
            fault_reg <= 1;
        else if( fault_clr_reg & (pwm_fault_clr == PWM_FAULT_CLR_C1) )
            fault_reg <= 0;
            
    // Connect the outputs
    assign  tmr             =   tmr_reg;
    assign  pwm0            =   pwm0_w_dt ^ pwm0_inv && ~fault_reg && pwm0_en;
    assign  pwm1            =   pwm1_w_dt ^ pwm1_inv && ~fault_reg && pwm1_en;
    assign  matchx_flag     =   tmr_eq_cmpx;
    assign  matchy_flag     =   tmr_eq_cmpy;
    assign  timeout_flag    =   tmr_dir ? tmr_eq_reload : tmr_eq_zero;
    
endmodule
