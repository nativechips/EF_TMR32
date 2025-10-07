from uvm.macros import (
    uvm_object_utils_begin,
    uvm_object_utils_end,
    uvm_field_int,
    uvm_object_utils,
    uvm_error,
    uvm_info,
)
from uvm.base.uvm_object_globals import UVM_ALL_ON, UVM_NOPACK, UVM_HIGH, UVM_MEDIUM
from uvm.base.sv import sv
from CF_UVM.ip_env.ip_item import ip_item


class tmr32_pwm_item(ip_item):

    pwm0 = "pwm0"
    pwm1 = "pwm1"

    def __init__(self, name="tmr32_pwm_item"):
        super().__init__(name)
        self.pattern = []
        self._source = None
        self.source = tmr32_pwm_item.pwm0  # source can be pwm0 or pwm1

    def convert2string(self):
        return sv.sformatf("pattern %s from %s", self.pattern, self.source)

    def do_compare(self, tr):
        def find_element_indexes(lst, element):
            return [index for index, value in enumerate(lst) if value == element]

        def patterns_equal(pattern1, pattern2):
            if pattern1 is None or pattern2 is None:
                return False

            if len(pattern1) != len(pattern2):
                return False

            if len(pattern1) < 2:
                return pattern1[0][0] == pattern2[0][0]
            # get index of first element in the other pattern
            # TODO: Add special case if index showed more than once
            index = find_element_indexes(pattern2, pattern1[0])
            if index == []:
                return False
            if index[0] == 0:
                return pattern1 == pattern2
            else:
                return pattern1 == pattern2[index[0] :] + pattern2[: index[0]]

        uvm_info(
            self.tag,
            "Comparing " + self.convert2string() + " with " + tr.convert2string(),
            UVM_MEDIUM,
        )
        return self.source == tr.source and patterns_equal(self.pattern, tr.pattern)

    @property
    def source(self):
        return self._source

    @source.setter
    def source(self, value):
        if value in [tmr32_pwm_item.pwm0, tmr32_pwm_item.pwm1]:
            self._source = value
        else:
            raise ValueError("source must be pwm0 or pwm1")


uvm_object_utils(tmr32_pwm_item)
