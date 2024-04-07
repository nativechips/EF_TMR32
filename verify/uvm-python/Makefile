PLUSARGS += "+UVM_VERBOSITY=UVM_MEDIUM"
TOPLEVEL := top
MODULE   ?= top_module
AHB_FILES ?= $(PWD)/../../hdl/rtl/bus_wrappers/EF_TMR32_AHBL.pp.v
APB_FILES ?= $(PWD)/../../hdl/rtl/bus_wrappers/EF_TMR32_APB.pp.v
WB_FILES ?= ""
HDL_FILES ?=  $(PWD)/../../hdl/rtl/EF_TMR32.pp.v
VERILOG_SOURCES ?=  $(PWD)/top.v $(AHB_FILES) $(APB_FILES) $(WB_FILES) $(HDL_FILES)
RTL_MACROS += ""
BUS_TYPE ?= APB
ifeq ($(BUS_TYPE),APB)
    RTL_MACROS += -DBUS_TYPE_APB
    DESIGN_NAME = EF_TMR32_APB
    export CLK_MAKEFILE = PCLK
    export RST_MAKEFILE = PRESETn
else ifeq ($(BUS_TYPE),AHB)
    RTL_MACROS += -DBUS_TYPE_AHB
    DESIGN_NAME = EF_TMR32_AHBL
    export CLK_MAKEFILE = HCLK
    export RST_MAKEFILE = HRESETn
else ifeq ($(BUS_TYPE),WISHBONE)
    RTL_MACROS += -DBUS_TYPE_WISHBONE
    DESIGN_NAME = EF_TMR32_WB
endif
## netlist Gen 
GL_MACROS += -DFUNCTIONAL $(RTL_MACROS) -DUNIT_DELAY=\#1
PRE_SYS_FILES = $(AHB_FILES) $(APB_FILES) $(WB_FILES) $(HDL_FILES)
PDK_DIR = $(HOME)/.volare/volare/sky130/versions/bdc9412b3e468c102d01b7cf6337be06ec6e9c9a/sky130A/
PDK_FILES = $(PDK_DIR)/libs.ref/sky130_fd_sc_hd/verilog/primitives.v $(PDK_DIR)/libs.ref/sky130_fd_sc_hd/verilog/sky130_fd_sc_hd.v # get this from openlane logs in the future 
POST_SYS_FILES = $(PWD)/top.v $(VIP_FILES) $(PWD)/../../hdl/gl/synthesis/nl/$(DESIGN_NAME).nl.v

YAML_FILE = $(PWD)/../../EF_TMR32.yaml
MAKEFLAGS += --no-print-directory

# List of tests
TESTS := pwm_actions_test time_vary_test pwm_pr_test pwm_tmr_test
# TESTS := pwm_tmr_test

# Variable for tag - set this as required
SIM_TAG ?= default_tag

# Define SIM_PATH variable
SIM_PATH := $(PWD)/sim/$(SIM_TAG)

clone_ef_uvm := $(shell if [ ! -d "EF_UVM" ]; then \
	echo "Cloning the EF_UVM repository..."; \
	git clone https://github.com/efabless/EF_UVM.git; \
fi;)

# clone_ip_util := $(shell if [ ! -d "IP_Utilities" ]; then \
# 	echo "Cloning the IP_Utilities repository..."; \
# 	git clone https://github.com/shalan/IP_Utilities.git; \
# fi;)

include EF_UVM/Makefile.test
