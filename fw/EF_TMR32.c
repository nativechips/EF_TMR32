/*! \file EF_UART.c
    \brief C file for UART APIs which contains the function implmentations 
    
*/

#ifndef EF_TMR32_C
#define EF_TMR32_C
#include <EF_TMR32.h>


void EF_TMR32_enable(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_TE_BIT);
}

void EF_TMR32_restart(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_TS_BIT);
}

void EF_TMR32_PWM0Enable(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_P0E_BIT);
}

void EF_TMR32_PWM1Enable(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_P1E_BIT);
}

void EF_TMR32_deadtimeEnable(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_DTE_BIT);
}

void EF_TMR32_PWM0Invert(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_PI0_BIT);
}

void EF_TMR32_PWM1Invert(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CTRL_REG_PI1_BIT);
}

void EF_TMR32_setUpCount(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->CFG |= ((0b10 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK);
}

void EF_TMR32_setDownCount(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->CFG |= ((0b01 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK);
}

void EF_TMR32_setUpDownCount(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->CFG &= ~EF_TMR32_CFG_REG_DIR_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->CFG |= ((0b11 << EF_TMR32_CFG_REG_DIR_BIT) & EF_TMR32_CFG_REG_DIR_MASK);
}

void EF_TMR32_setPeriodic(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // set the enable bit to 1 at the specified offset
    tmr32->CTRL |= (1 << EF_TMR32_CFG_REG_P_BIT);
}

void EF_TMR32_setOneShot(uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the enable bit using the specified  mask
    tmr32->CTRL &= ~EF_TMR32_CFG_REG_P_BIT;
}

void EF_TMR32_setPWM0MatchingZeroAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E0_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E0_BIT) & EF_TMR32_PWM0CFG_REG_E0_MASK);

}

void EF_TMR32_setPWM0MatchingCMPXAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E1_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E1_BIT) & EF_TMR32_PWM0CFG_REG_E1_MASK);

}

void EF_TMR32_setPWM0MatchingCMPYAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E2_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E2_BIT) & EF_TMR32_PWM0CFG_REG_E2_MASK);

}

void EF_TMR32_setPWM0MatchingRELOADAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E3_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E3_BIT) & EF_TMR32_PWM0CFG_REG_E3_MASK);

}

void EF_TMR32_setPWM0MatchingCMPYDownCountAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E4_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E4_BIT) & EF_TMR32_PWM0CFG_REG_E4_MASK);

}

void EF_TMR32_setPWM0MatchingCMPXDownCountAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM0CFG &= ~EF_TMR32_PWM0CFG_REG_E5_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM0CFG |= ((action << EF_TMR32_PWM0CFG_REG_E5_BIT) & EF_TMR32_PWM0CFG_REG_E5_MASK);

}

void EF_TMR32_setPWM1MatchingZeroAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E0_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E0_BIT) & EF_TMR32_PWM1CFG_REG_E0_MASK);

}

void EF_TMR32_setPWM1MatchingCMPXAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E1_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E1_BIT) & EF_TMR32_PWM1CFG_REG_E1_MASK);

}

void EF_TMR32_setPWM1MatchingCMPYAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E2_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E2_BIT) & EF_TMR32_PWM1CFG_REG_E2_MASK);

}

void EF_TMR32_setPWM1MatchingRELOADAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E3_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E3_BIT) & EF_TMR32_PWM1CFG_REG_E3_MASK);

}

void EF_TMR32_setPWM1MatchingCMPYDownCountAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E4_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E4_BIT) & EF_TMR32_PWM1CFG_REG_E4_MASK);

}

void EF_TMR32_setPWM1MatchingCMPXDownCountAction(uint32_t tmr32_base, enum actions action){

    EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

    // Clear the field bits in the register using the defined mask
    tmr32->PWM1CFG &= ~EF_TMR32_PWM1CFG_REG_E5_MASK;

    // Set the bits with the given value at the defined offset
    tmr32->PWM1CFG |= ((action << EF_TMR32_PWM1CFG_REG_E5_BIT) & EF_TMR32_PWM1CFG_REG_E5_MASK);

}

void EF_TMR32_setRELOAD (uint32_t tmr32_base, int value){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     tmr32->RELOAD = value;

}

int EF_TMR32_getRELOAD (uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     return (tmr32->RELOAD);

}

void EF_TMR32_setCMPX (uint32_t tmr32_base, int value){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     tmr32->CMPX = value;

}

int EF_TMR32_getCMPX (uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     return (tmr32->CMPX);

}

void EF_TMR32_setCMPY (uint32_t tmr32_base, int value){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     tmr32->CMPY = value;

}

int EF_TMR32_getCMPY (uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     return (tmr32->CMPY);

}

int EF_TMR32_getTMR (uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     return (tmr32->TMR);

}

void EF_TMR32_setDeadtime (uint32_t tmr32_base, int value){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     tmr32->PWMDT = value;

}

int EF_TMR32_getDeadtime (uint32_t tmr32_base){

     EF_TMR32_TYPE* tmr32 = (EF_TMR32_TYPE*)tmr32_base;

     return (tmr32->PWMDT);

}

#endif