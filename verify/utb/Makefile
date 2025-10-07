SOURCE = ../../hdl/rtl/CF_TMR32.v
SOURCE_APB =  ../../hdl/rtl/bus_wrappers/CF_TMR32_APB.v
SOURCE_AHBL = ../../hdl/rtl/bus_wrappers/CF_TMR32_AHBL.v
SOURCE_WB = ../../hdl/rtl/bus_wrappers/CF_TMR32_WB.v
TESTBENCH_APB = CF_TMR32_APB_tb.v
TESTBENCH_AHBL = CF_TMR32_AHBL_tb.v
TESTBENCH_WB = CF_TMR32_WB_tb.v
RTL_LIB = ../../../IP_Utilities/rtl/aucohl_lib.v
AUCOHL_RTL_INCLUDES = ../../../IP_Utilities/rtl/
RTL_INCLUDE_DIR = ../../../BusWrap/includes/rtl/
TB_INCLUDE_DIR = ../../../BusWrap/includes/tb/

APB-RTL: 
	iverilog -o run.vvp -I$(TB_INCLUDE_DIR) -I$(RTL_INCLUDE_DIR) -I$(AUCOHL_RTL_INCLUDES) $(RTL_LIB)  $(SOURCE) $(SOURCE_APB) $(TESTBENCH_APB)
	./run.vvp

AHBL-RTL: 
	iverilog -o run.vvp -I$(TB_INCLUDE_DIR) -I$(RTL_INCLUDE_DIR) -I$(AUCOHL_RTL_INCLUDES) $(RTL_LIB)  $(SOURCE) $(SOURCE_AHBL) $(TESTBENCH_AHBL)
	./run.vvp

WB-RTL: 
	iverilog -o run.vvp -I$(TB_INCLUDE_DIR) -I$(RTL_INCLUDE_DIR) -I$(AUCOHL_RTL_INCLUDES) $(RTL_LIB)  $(SOURCE) $(SOURCE_WB) $(TESTBENCH_WB)
	./run.vvp

clean:
	rm -f *.vvp
	rm -f *.vcd

all: APB-RTL