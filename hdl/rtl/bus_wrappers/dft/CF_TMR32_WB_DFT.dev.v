/*
	Copyright 2024-2025 ChipFoundry, a DBA of Umbralogic Technologies LLC.

	Original Copyright 2024 Efabless Corp.
	Author: Efabless Corp. (ip_admin@efabless.com)

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/

/* THIS FILE IS GENERATED, DO NOT EDIT */

`timescale			1ns/1ps
`default_nettype	none

`define				WB_AW		16

`include			"wb_wrapper.vh"

module CF_TMR32_WB #( 
	parameter	
		PRW = 16
) (
`ifdef USE_POWER_PINS
	inout VPWR,
	inout VGND,
`endif
	input	wire	sc_testmode,
	`WB_SLAVE_PORTS,
	output	wire	[1-1:0]	pwm0,
	output	wire	[1-1:0]	pwm1,
	input	wire	[1-1:0]	pwm_fault
);

	localparam	TMR_REG_OFFSET = `WB_AW'h0000;
	localparam	RELOAD_REG_OFFSET = `WB_AW'h0004;
	localparam	PR_REG_OFFSET = `WB_AW'h0008;
	localparam	CMPX_REG_OFFSET = `WB_AW'h000C;
	localparam	CMPY_REG_OFFSET = `WB_AW'h0010;
	localparam	CTRL_REG_OFFSET = `WB_AW'h0014;
	localparam	CFG_REG_OFFSET = `WB_AW'h0018;
	localparam	PWM0CFG_REG_OFFSET = `WB_AW'h001C;
	localparam	PWM1CFG_REG_OFFSET = `WB_AW'h0020;
	localparam	PWMDT_REG_OFFSET = `WB_AW'h0024;
	localparam	PWMFC_REG_OFFSET = `WB_AW'h0028;
	localparam	IM_REG_OFFSET = `WB_AW'hFF00;
	localparam	MIS_REG_OFFSET = `WB_AW'hFF04;
	localparam	RIS_REG_OFFSET = `WB_AW'hFF08;
	localparam	IC_REG_OFFSET = `WB_AW'hFF0C;

    reg [0:0] GCLK_REG;
    wire clk_g;

    wire clk_gated_en = sc_testmode ? 1'b1 : GCLK_REG[0];
    cf_util_gating_cell clk_gate_cell(
        `ifdef USE_POWER_PINS 
        .vpwr(VPWR),
        .vgnd(VGND),
        `endif // USE_POWER_PINS
        .clk(clk_i),
        .clk_en(clk_gated_en),
        .clk_o(clk_g)
    );
    
	wire		clk = clk_g;
	wire		rst_n = (~rst_i);


	`WB_CTRL_SIGNALS

	wire [1-1:0]	tmr_en;
	wire [1-1:0]	tmr_start;
	wire [1-1:0]	pwm0_en;
	wire [1-1:0]	pwm1_en;
	wire [32-1:0]	tmr_reload;
	wire [32-1:0]	cmpx;
	wire [32-1:0]	cmpy;
	wire [PRW-1:0]	prescaler;
	wire [3-1:0]	tmr_cfg;
	wire [12-1:0]	pwm0_cfg;
	wire [12-1:0]	pwm1_cfg;
	wire [1-1:0]	pwm0_inv;
	wire [1-1:0]	pwm1_inv;
	wire [8-1:0]	pwm_dt;
	wire [16-1:0]	pwm_fault_clr;
	wire [1-1:0]	pwm_dt_en;
	wire [32-1:0]	tmr;
	wire [1-1:0]	matchx_flag;
	wire [1-1:0]	matchy_flag;
	(* keep *)wire [1-1:0]	timeout_flag;

	// Register Definitions
	wire [32-1:0]	TMR_WIRE;
	assign	TMR_WIRE = tmr;

	reg [31:0]	RELOAD_REG;
	assign	tmr_reload = RELOAD_REG;
	`WB_REG(RELOAD_REG, 0, 32)

	reg [PRW-1:0]	PR_REG;
	assign	prescaler = PR_REG;
	`WB_REG(PR_REG, 'h0, PRW)

	reg [31:0]	CMPX_REG;
	assign	cmpx = CMPX_REG;
	`WB_REG(CMPX_REG, 0, 32)

	reg [31:0]	CMPY_REG;
	assign	cmpy = CMPY_REG;
	`WB_REG(CMPY_REG, 0, 32)

	reg [6:0]	CTRL_REG;
	assign	tmr_en	=	CTRL_REG[0 : 0];
	assign	tmr_start	=	CTRL_REG[1 : 1];
	assign	pwm0_en	=	CTRL_REG[2 : 2];
	assign	pwm1_en	=	CTRL_REG[3 : 3];
	assign	pwm_dt_en	=	CTRL_REG[4 : 4];
	assign	pwm0_inv	=	CTRL_REG[5 : 5];
	assign	pwm1_inv	=	CTRL_REG[6 : 6];
	`WB_REG(CTRL_REG, 0, 7)

	reg [2:0]	CFG_REG;
	assign	tmr_cfg = CFG_REG;
	`WB_REG(CFG_REG, 0, 3)

	reg [11:0]	PWM0CFG_REG;
	assign	pwm0_cfg = PWM0CFG_REG;
	`WB_REG(PWM0CFG_REG, 0, 12)

	reg [15:0]	PWM1CFG_REG;
	assign	pwm1_cfg = PWM1CFG_REG;
	`WB_REG(PWM1CFG_REG, 0, 16)

	reg [7:0]	PWMDT_REG;
	assign	pwm_dt = PWMDT_REG;
	`WB_REG(PWMDT_REG, 0, 8)

	reg [15:0]	PWMFC_REG;
	assign	pwm_fault_clr = PWMFC_REG;
	`WB_REG(PWMFC_REG, 0, 16)

	localparam	GCLK_REG_OFFSET = `WB_AW'hFF10;
	`WB_REG(GCLK_REG, 0, 1)

	reg [2:0] IM_REG;
	reg [2:0] IC_REG;
	reg [2:0] RIS_REG;

	`WB_MIS_REG(3)
	`WB_REG(IM_REG, 0, 3)
	`WB_IC_REG(3)

	wire [0:0] TO = timeout_flag;
	wire [0:0] MX = matchx_flag;
	wire [0:0] MY = matchy_flag;


	integer _i_;
	`WB_BLOCK(RIS_REG, 0) else begin
		for(_i_ = 0; _i_ < 1; _i_ = _i_ + 1) begin
			if(IC_REG[_i_]) RIS_REG[_i_] <= 1'b0; else if(TO[_i_ - 0] == 1'b1) RIS_REG[_i_] <= 1'b1;
		end
		for(_i_ = 1; _i_ < 2; _i_ = _i_ + 1) begin
			if(IC_REG[_i_]) RIS_REG[_i_] <= 1'b0; else if(MX[_i_ - 1] == 1'b1) RIS_REG[_i_] <= 1'b1;
		end
		for(_i_ = 2; _i_ < 3; _i_ = _i_ + 1) begin
			if(IC_REG[_i_]) RIS_REG[_i_] <= 1'b0; else if(MY[_i_ - 2] == 1'b1) RIS_REG[_i_] <= 1'b1;
		end
	end

	assign IRQ = |MIS_REG;

	CF_TMR32 #(
		.PRW(PRW)
	) instance_to_wrap (
		.clk(clk),
		.rst_n(rst_n),
		.tmr_en(tmr_en),
		.tmr_start(tmr_start),
		.pwm0_en(pwm0_en),
		.pwm1_en(pwm1_en),
		.tmr_reload(tmr_reload),
		.cmpx(cmpx),
		.cmpy(cmpy),
		.prescaler(prescaler),
		.tmr_cfg(tmr_cfg),
		.pwm0_cfg(pwm0_cfg),
		.pwm1_cfg(pwm1_cfg),
		.pwm0_inv(pwm0_inv),
		.pwm1_inv(pwm1_inv),
		.pwm_dt(pwm_dt),
		.pwm_fault_clr(pwm_fault_clr),
		.pwm_dt_en(pwm_dt_en),
		.tmr(tmr),
		.matchx_flag(matchx_flag),
		.matchy_flag(matchy_flag),
		.timeout_flag(timeout_flag),
		.pwm0(pwm0),
		.pwm1(pwm1),
		.pwm_fault(pwm_fault)
	);

	assign	dat_o = 
			(adr_i[`WB_AW-1:0] == TMR_REG_OFFSET)	? TMR_WIRE :
			(adr_i[`WB_AW-1:0] == RELOAD_REG_OFFSET)	? RELOAD_REG :
			(adr_i[`WB_AW-1:0] == PR_REG_OFFSET)	? PR_REG :
			(adr_i[`WB_AW-1:0] == CMPX_REG_OFFSET)	? CMPX_REG :
			(adr_i[`WB_AW-1:0] == CMPY_REG_OFFSET)	? CMPY_REG :
			(adr_i[`WB_AW-1:0] == CTRL_REG_OFFSET)	? CTRL_REG :
			(adr_i[`WB_AW-1:0] == CFG_REG_OFFSET)	? CFG_REG :
			(adr_i[`WB_AW-1:0] == PWM0CFG_REG_OFFSET)	? PWM0CFG_REG :
			(adr_i[`WB_AW-1:0] == PWM1CFG_REG_OFFSET)	? PWM1CFG_REG :
			(adr_i[`WB_AW-1:0] == PWMDT_REG_OFFSET)	? PWMDT_REG :
			(adr_i[`WB_AW-1:0] == PWMFC_REG_OFFSET)	? PWMFC_REG :
			(adr_i[`WB_AW-1:0] == IM_REG_OFFSET)	? IM_REG :
			(adr_i[`WB_AW-1:0] == MIS_REG_OFFSET)	? MIS_REG :
			(adr_i[`WB_AW-1:0] == RIS_REG_OFFSET)	? RIS_REG :
			(adr_i[`WB_AW-1:0] == IC_REG_OFFSET)	? IC_REG :
			32'hDEADBEEF;

	always @ (posedge clk_i or posedge rst_i)
		if(rst_i)
			ack_o <= 1'b0;
		else if(wb_valid & ~ack_o)
			ack_o <= 1'b1;
		else
			ack_o <= 1'b0;
endmodule
