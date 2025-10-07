/*
	Copyright 2024-2025 ChipFoundry, a DBA of Umbralogic Technologies LLC.

	Original Copyright 2024 Efabless Corp.
	Author: Efabless Corp. (ip_admin@efabless.com)

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/


/*! \file CF_TMR32.c
    \brief C file for TMR32 APIs which contains the function implmentations 
    
*/

#ifndef CF_TMR32_C
#define CF_TMR32_C

/******************************************************************************
* Includes
******************************************************************************/
#include "CF_TMR32.h"

/******************************************************************************
* File-Specific Macros and Constants
******************************************************************************/



/******************************************************************************
* Static Variables
******************************************************************************/



/******************************************************************************
* Static Function Prototypes
******************************************************************************/



/******************************************************************************
* Function Definitions
******************************************************************************/

CF_DRIVER_STATUS CF_TMR32_setGclkEnable(CF_TMR32_TYPE_PTR tmr32, uint32_t value) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if (value > (uint32_t)0x1) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        tmr32->GCLK = value; // Set the GCLK enable bit to the provided value
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_enable(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= CF_TMR32_CTRL_REG_TE_MASK; // Set the enable bit to 1
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_disable(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL &= ~CF_TMR32_CTRL_REG_TE_MASK; // Clear the enable bit
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_restart(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= CF_TMR32_CTRL_REG_TS_MASK;  // Set the restart bit
        tmr32->CTRL &= ~CF_TMR32_CTRL_REG_TS_MASK; // Clear the restart bit
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_PWM0Enable(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= CF_TMR32_CTRL_REG_P0E_MASK; // Enable PWM0
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_PWM1Enable(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= CF_TMR32_CTRL_REG_P1E_MASK; // Enable PWM1
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_PWMDeadtimeEnable(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= CF_TMR32_CTRL_REG_DTE_MASK; // Enable dead-time
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_PWM0Invert(CF_TMR32_TYPE_PTR tmr32){
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= CF_TMR32_CTRL_REG_PI0_MASK; // Invert PWM0 output
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_PWM1Invert(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CTRL |= CF_TMR32_CTRL_REG_PI1_MASK; // Invert PWM1 output
    }

    return status;
}



CF_DRIVER_STATUS CF_TMR32_setUpCount(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG &= ~CF_TMR32_CFG_REG_DIR_MASK; // Clear the direction field
        tmr32->CFG |= (((uint32_t)0b10 << CF_TMR32_CFG_REG_DIR_BIT) & CF_TMR32_CFG_REG_DIR_MASK); // Set up-count direction
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setDownCount(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG &= ~CF_TMR32_CFG_REG_DIR_MASK; // Clear the direction field
        tmr32->CFG |= (((uint32_t)0b01 << CF_TMR32_CFG_REG_DIR_BIT) & CF_TMR32_CFG_REG_DIR_MASK); // Set down-count mode
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setUpDownCount(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG &= ~CF_TMR32_CFG_REG_DIR_MASK; // Clear the direction field
        tmr32->CFG |= (((uint32_t)0b11 << CF_TMR32_CFG_REG_DIR_BIT) & CF_TMR32_CFG_REG_DIR_MASK); // Set up-down-count mode
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPeriodic(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG |= CF_TMR32_CFG_REG_P_MASK; // Enable periodic mode
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setOneShot(CF_TMR32_TYPE_PTR tmr32) {
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else {
        tmr32->CFG &= ~CF_TMR32_CFG_REG_P_MASK; // Disable periodic mode to set one-shot mode
    }

    return status;
}



CF_DRIVER_STATUS CF_TMR32_setPWM0MatchingZeroAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~CF_TMR32_PWM0CFG_REG_E0_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << CF_TMR32_PWM0CFG_REG_E0_BIT) & CF_TMR32_PWM0CFG_REG_E0_MASK);
    }
    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM0MatchingCMPXUpCountAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~CF_TMR32_PWM0CFG_REG_E1_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << CF_TMR32_PWM0CFG_REG_E1_BIT) & CF_TMR32_PWM0CFG_REG_E1_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM0MatchingCMPYUpCountAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~CF_TMR32_PWM0CFG_REG_E2_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << CF_TMR32_PWM0CFG_REG_E2_BIT) & CF_TMR32_PWM0CFG_REG_E2_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM0MatchingRELOADAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~CF_TMR32_PWM0CFG_REG_E3_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << CF_TMR32_PWM0CFG_REG_E3_BIT) & CF_TMR32_PWM0CFG_REG_E3_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM0MatchingCMPYDownCountAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~CF_TMR32_PWM0CFG_REG_E4_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << CF_TMR32_PWM0CFG_REG_E4_BIT) & CF_TMR32_PWM0CFG_REG_E4_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM0MatchingCMPXDownCountAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM0CFG &= ~CF_TMR32_PWM0CFG_REG_E5_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM0CFG |= ((action << CF_TMR32_PWM0CFG_REG_E5_BIT) & CF_TMR32_PWM0CFG_REG_E5_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM1MatchingZeroAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~CF_TMR32_PWM1CFG_REG_E0_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << CF_TMR32_PWM1CFG_REG_E0_BIT) & CF_TMR32_PWM1CFG_REG_E0_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM1MatchingCMPXUpCountingAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~CF_TMR32_PWM1CFG_REG_E1_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << CF_TMR32_PWM1CFG_REG_E1_BIT) & CF_TMR32_PWM1CFG_REG_E1_MASK);
    }

    return status;
}



CF_DRIVER_STATUS CF_TMR32_setPWM1MatchingCMPYUpCountingAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~CF_TMR32_PWM1CFG_REG_E2_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << CF_TMR32_PWM1CFG_REG_E2_BIT) & CF_TMR32_PWM1CFG_REG_E2_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM1MatchingRELOADAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~CF_TMR32_PWM1CFG_REG_E3_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << CF_TMR32_PWM1CFG_REG_E3_BIT) & CF_TMR32_PWM1CFG_REG_E3_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM1MatchingCMPYDownCountAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~CF_TMR32_PWM1CFG_REG_E4_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << CF_TMR32_PWM1CFG_REG_E4_BIT) & CF_TMR32_PWM1CFG_REG_E4_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM1MatchingCMPXDownCountAction(CF_TMR32_TYPE_PTR tmr32, uint32_t action) {

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
    } else if ((action > CF_TMR32_ACTION_MAX_VALUE)) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if value is out of valid range
    } else {
        // Clear the field bits in the register using the defined mask
        tmr32->PWM1CFG &= ~CF_TMR32_PWM1CFG_REG_E5_MASK;

        // Set the bits with the given value at the defined offset
        tmr32->PWM1CFG |= ((action << CF_TMR32_PWM1CFG_REG_E5_BIT) & CF_TMR32_PWM1CFG_REG_E5_MASK);
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setRELOAD (CF_TMR32_TYPE_PTR tmr32, uint32_t value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else {

        tmr32->RELOAD = value;
    }
    return status;

}



CF_DRIVER_STATUS CF_TMR32_setCMPX (CF_TMR32_TYPE_PTR tmr32, uint32_t value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else {

        tmr32->CMPX = value;
    }

    return status;
}

CF_DRIVER_STATUS CF_TMR32_getCMPX (CF_TMR32_TYPE_PTR tmr32, uint32_t *value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (value == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else {
        *value = tmr32->CMPX;
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_getCMPY (CF_TMR32_TYPE_PTR tmr32, uint32_t *value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (value == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else {
        *value = tmr32->CMPY;
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setCMPY (CF_TMR32_TYPE_PTR tmr32, uint32_t value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else {

        tmr32->CMPY = value;
    }

    return status;
}



CF_DRIVER_STATUS CF_TMR32_getTMR (CF_TMR32_TYPE_PTR tmr32, uint32_t* tmr_value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (tmr_value == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer value pointer is NULL
    }else{
        *tmr_value = tmr32->TMR;
    }
    return status;

}


CF_DRIVER_STATUS CF_TMR32_setPWMDeadtime (CF_TMR32_TYPE_PTR tmr32, uint32_t value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (value > CF_TMR32_PWMDT_MAX_VALUE) {

        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL   

    }else {
                tmr32->PWMDT = value;
    }
    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPR(CF_TMR32_TYPE_PTR tmr32, uint32_t value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (value > CF_TMR32_PR_MAX_VALUE) {

        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
        
    }else{
        tmr32->PR = value;
    }
 
    return status;
}


CF_DRIVER_STATUS CF_TMR32_getRIS(CF_TMR32_TYPE_PTR tmr32, uint32_t* RIS_value){
    
    CF_DRIVER_STATUS status = CF_DRIVER_OK; 

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if tmr32 is NULL
    } else if (RIS_value == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if RIS_value is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *RIS_value = tmr32->RIS;
        
    }
    return status;
}

CF_DRIVER_STATUS CF_TMR32_getMIS(CF_TMR32_TYPE_PTR tmr32, uint32_t* MIS_value){
    
    CF_DRIVER_STATUS status = CF_DRIVER_OK; 

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if tmr32 is NULL
    } else if (MIS_value == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if MIS_value is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *MIS_value = tmr32->MIS;
        
    }
    return status;
}

CF_DRIVER_STATUS CF_TMR32_setIM(CF_TMR32_TYPE_PTR tmr32, uint32_t mask){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (mask > CF_TMR32_IM_MAX_VALUE) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL   
    }else{
        tmr32->IM = mask;
    }
    return status;
}


CF_DRIVER_STATUS CF_TMR32_getIM(CF_TMR32_TYPE_PTR tmr32, uint32_t* IM_value){
    
    CF_DRIVER_STATUS status = CF_DRIVER_OK; 

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if tmr32 is NULL
    } else if (IM_value == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if IM_value is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *IM_value = tmr32->IM;
        
    }
    return status;
}

CF_DRIVER_STATUS CF_TMR32_setICR(CF_TMR32_TYPE_PTR tmr32, uint32_t mask){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL    
    } else if (mask > CF_TMR32_ICR_MAX_VALUE) {

        status = CF_DRIVER_ERROR_PARAMETER; // Return error if the timer pointer is NULL
        
    }else{
        tmr32->IC = mask;
    }
    return status;
}

CF_DRIVER_STATUS CF_TMR32_isTimout(CF_TMR32_TYPE_PTR tmr32, bool* timeout_status){
    
    CF_DRIVER_STATUS status = CF_DRIVER_OK; 

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if tmr32 is NULL
    } else if (timeout_status == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if timeout_status is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        uint32_t ris_value;
        status = CF_TMR32_getRIS(tmr32, &ris_value);
        if (status == CF_DRIVER_OK) {
            *timeout_status = (ris_value & CF_TMR32_TO_FLAG) ? true : false;
        }else{}
    }
    return status;
}

CF_DRIVER_STATUS CF_TMR32_isCMPXMatch(CF_TMR32_TYPE_PTR tmr32, bool* match_status){
    
    CF_DRIVER_STATUS status = CF_DRIVER_OK; 

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if tmr32 is NULL
    } else if (match_status == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if match_status is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        uint32_t ris_value;
        status = CF_TMR32_getRIS(tmr32, &ris_value);
        if (status == CF_DRIVER_OK) {
            *match_status = (ris_value & CF_TMR32_MX_FLAG) ? true : false;
        }else{}
    }
    return status;
}

CF_DRIVER_STATUS CF_TMR32_isCMPYMatch(CF_TMR32_TYPE_PTR tmr32, bool* match_status){

    CF_DRIVER_STATUS status = CF_DRIVER_OK; 

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if tmr32 is NULL
    } else if (match_status == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;                // Return CF_DRIVER_ERROR_PARAMETER if match_status is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        uint32_t ris_value;
        status = CF_TMR32_getRIS(tmr32, &ris_value);
        if (status == CF_DRIVER_OK) {
            *match_status = (ris_value & CF_TMR32_MY_FLAG) ? true : false;
        }else{}
    }
    return status;
}


CF_DRIVER_STATUS CF_TMR32_clearTimoutFlag(CF_TMR32_TYPE_PTR tmr32){
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;
    } else {
        tmr32->IC |= CF_TMR32_TO_FLAG;
    }

    return status;
}

CF_DRIVER_STATUS CF_TMR32_clearCMPXMatchFlag(CF_TMR32_TYPE_PTR tmr32){
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;
    } else {
        tmr32->IC |= CF_TMR32_MX_FLAG;
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_clearCMPYMatchFlag(CF_TMR32_TYPE_PTR tmr32){
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;
    } else {
        tmr32->IC |= CF_TMR32_MY_FLAG;
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM0EdgeAlignmentMode(CF_TMR32_TYPE_PTR tmr32, uint32_t reload_value, uint32_t duty_cycle){
    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;
    }else if (duty_cycle > 100) {
        status = CF_DRIVER_ERROR_PARAMETER;

    } else{

        // set the timer to up-count mode
        // set the timer to periodic mode
        // set the zero action to high
        // only use one compare register
        // set the action of the X Compare register up count to low
        // set the action of the Y Compare register up count to no change
        // calculate the X compare register value given the duty cycle
        // set the reload value
        // set X compare register value
        // set the top action to no change

        //  |
        //  |       /|      /|
        //  |_____/__|____/  |
        //  |   / |  |  / |  |
        //  |_/___|__|/___|__|____
        //        |       |
        //        V       V
        //    ____    ____    ___   ___
        //        |__|    |__|   |__|
        //    duty    duty
        //    cycle   cycle


        status = CF_TMR32_setUpCount(tmr32);
        
        if (status == CF_DRIVER_OK) {
            uint32_t cmpY;
            status = CF_TMR32_getCMPY(tmr32, &cmpY);
            if (cmpY == (uint32_t)0) {
                status = CF_TMR32_setCMPY(tmr32, (uint32_t)10); // Set CMPX to a dummy value to prevent the timer from firing two concurrent interrupts
            } else {}
        }else{}

        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPeriodic(tmr32);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingZeroAction(tmr32, CF_TMR32_ACTION_HIGH);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingCMPXUpCountAction(tmr32, CF_TMR32_ACTION_LOW);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingCMPYUpCountAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingRELOADAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setRELOAD(tmr32, reload_value);}else{}

        if (status == CF_DRIVER_OK){
            uint32_t compare_value = (duty_cycle * reload_value) / 100;
            status = CF_TMR32_setCMPX(tmr32, compare_value);  
        }else{}
        
    }
    return status;
}

CF_DRIVER_STATUS CF_TMR32_setPWM1EdgeAlignmentMode(CF_TMR32_TYPE_PTR tmr32, uint32_t reload_value,uint32_t duty_cycle){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;
    } else if (duty_cycle > 100) {
        status = CF_DRIVER_ERROR_PARAMETER;

    } else {

        // set the timer to up-count mode
        // set the timer to periodic mode
        // set the zero action to high
        // only use one compare register
        // set the action of the Y Compare register up count to low
        // set the action of the X Compare register up count to no change
        // calculate the Y compare register value given the duty cycle
        // set the reload value
        // set the Y compare register value
        // set the top action to no change

        //  |
        //  |       /|      /|
        //  |_____/__|____/  |
        //  |   / |  |  / |  |
        //  |_/___|__|/___|__|____
        //        |       |
        //        V       V
        //    ____    ____    ___   ___
        //        |__|    |__|   |__|
        //    duty    duty
        //    cycle   cycle

        status = CF_TMR32_setUpCount(tmr32);

        if (status == CF_DRIVER_OK) {
            uint32_t cmpX;
            status = CF_TMR32_getCMPX(tmr32, &cmpX);
            if (cmpX == (uint32_t)0) {
                status = CF_TMR32_setCMPX(tmr32, (uint32_t)10); // Set CMPX to a dummy value to prevent the timer from firing two concurrent interrupts
            } else {}
        }else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPeriodic(tmr32);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM1MatchingZeroAction(tmr32, CF_TMR32_ACTION_HIGH);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM1MatchingCMPYUpCountingAction(tmr32, CF_TMR32_ACTION_LOW);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM1MatchingCMPXUpCountingAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM1MatchingRELOADAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setRELOAD(tmr32, reload_value);}else{}

        if (status == CF_DRIVER_OK){
            uint32_t compare_value = (duty_cycle * reload_value) / 100;
            status = CF_TMR32_setCMPY(tmr32, compare_value);  
        }else{}
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM0CenterAlignedMode(CF_TMR32_TYPE_PTR tmr32, uint32_t reload_value, uint32_t cmpX_value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;
    }else if (reload_value < cmpX_value){
        status = CF_DRIVER_ERROR_PARAMETER;
    } else {

        // set the timer to up-down-count mode
        // set the timer to periodic mode
        // set the zero action to high
        // set the action of the X Compare register up count to low
        // set the action of the Y Compare register up count to no change
        // set the action of the X Compare register down count to high
        // set the action of the Y Compare register down count to no change
        // set the top action to no change
        // set the reload value
        // set the X compare value


        //  |
        //  |       /|\
        //  |_____/__|__\
        //  |   / |  |  | \
        //  |_/___|__|__|___\__
        //        |     |
        //        V     V
        //    ____       ____ 
        //        |_____|    

        status = CF_TMR32_setUpDownCount(tmr32);

        if (status == CF_DRIVER_OK) {
            uint32_t cmpY;
            status = CF_TMR32_getCMPY(tmr32, &cmpY);
            if (cmpY == (uint32_t)0) {
                status = CF_TMR32_setCMPY(tmr32, (uint32_t)10); // Set CMPX to a dummy value to prevent the timer from firing two concurrent interrupts
            } else {}
        }else{}

        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPeriodic(tmr32);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingZeroAction(tmr32, CF_TMR32_ACTION_HIGH);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingCMPXUpCountAction(tmr32, CF_TMR32_ACTION_LOW);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingCMPYUpCountAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingCMPXDownCountAction(tmr32, CF_TMR32_ACTION_HIGH);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingCMPYDownCountAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setPWM0MatchingRELOADAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setRELOAD(tmr32, reload_value);}else{}
        if (status == CF_DRIVER_OK){ status = CF_TMR32_setCMPX(tmr32, cmpX_value);}else{}
        
    }

    return status;
}


CF_DRIVER_STATUS CF_TMR32_setPWM1CenterAlignedMode(CF_TMR32_TYPE_PTR tmr32, uint32_t reload_value, uint32_t cmpY_value){

    CF_DRIVER_STATUS status = CF_DRIVER_OK;

    if (tmr32 == NULL) {
        status = CF_DRIVER_ERROR_PARAMETER;
    } else {
        // set the timer to up-down-count mode
        // set the timer to periodic mode
        // set the zero action to high
        // set the action of the Y Compare register up count to low
        // set the action of the X Compare register up count to no change
        // set the action of the Y Compare register down count to high
        // set the action of the X Compare register down count to no change
        // set the top action to no change
        // set the reload value
        // set the Y compare value

        //  |
        //  |       /|\
        //  |_____/__|__\
        //  |   / |  |  | \
        //  |_/___|__|__|___\__
        //        |     |
        //        V     V
        //    ____       ____ 
        //        |_____|

        status = CF_TMR32_setUpDownCount(tmr32);

        if (status == CF_DRIVER_OK) {
            uint32_t cmpX;
            status = CF_TMR32_getCMPX(tmr32, &cmpX);
            if (cmpX == (uint32_t)0) {
                status = CF_TMR32_setCMPX(tmr32, (uint32_t)10); // Set CMPX to a dummy value to prevent the timer from firing two concurrent interrupts
            } else {}
        }else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setPeriodic(tmr32);}else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setPWM1MatchingZeroAction(tmr32, CF_TMR32_ACTION_HIGH);}else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setPWM1MatchingCMPYUpCountingAction(tmr32, CF_TMR32_ACTION_LOW);}else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setPWM1MatchingCMPXUpCountingAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setPWM1MatchingCMPYDownCountAction(tmr32, CF_TMR32_ACTION_HIGH);}else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setPWM1MatchingCMPXDownCountAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setPWM1MatchingRELOADAction(tmr32, CF_TMR32_ACTION_NONE);}else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setRELOAD(tmr32, reload_value);}else{}
        if (status == CF_DRIVER_OK) {status = CF_TMR32_setCMPY(tmr32, cmpY_value);}else{}


    }
    return status;
}



/******************************************************************************
* Static Function Definitions
******************************************************************************/


#endif // CF_TMR32_C

/******************************************************************************
* End of File
******************************************************************************/