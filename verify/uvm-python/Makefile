PLUSARGS += "+UVM_VERBOSITY=UVM_MEDIUM"
TOPLEVEL := top
MODULE   ?= top_module
VERILOG_SOURCES ?=  $(PWD)/top.v $(PWD)/../../hdl/rtl/bus_wrappers/EF_TMR32_APB.pp.v  $(PWD)/../../hdl/rtl/EF_TMR32.pp.v
RTL_MACROS ?= ""
YAML_FILE = $(PWD)/../../EF_TMR32.yaml
MAKEFLAGS += --no-print-directory

# List of tests
TESTS := tmr32_Try time_vary_test temp_test
TESTS := temp_test

# Variable for tag - set this as required
SIM_TAG ?= default_tag

# Define SIM_PATH variable
SIM_PATH := $(PWD)/sim/$(SIM_TAG)

clone_ef_uvm := $(shell if [ ! -d "EF_UVM" ]; then \
	echo "Cloning the EF_UVM repository..."; \
	git clone https://github.com/M0stafaRady/EF_UVM.git; \
fi;)

# clone_ip_util := $(shell if [ ! -d "IP_Utilities" ]; then \
# 	echo "Cloning the IP_Utilities repository..."; \
# 	git clone https://github.com/shalan/IP_Utilities.git; \
# fi;)

include EF_UVM/Makefile.test
