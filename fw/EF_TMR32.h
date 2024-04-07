#ifndef EF_UART_H
#define EF_UART_H

#include <EF_TMR32_regs.h>
#include <stdint.h>
#include <stdbool.h>

enum actions {NONE = 0b00, LOW = 0b01, HIGH = 0b10, INVERT = 0b11};

//! enables timer by setting "TE" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_enable(uint32_t tmr32_base);

//! enables timer re-start; used in the one-shot mode to restart the timer.
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_restart(uint32_t tmr32_base);

//! enables PWM0 by setting "P0E" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_PWM0Enable(uint32_t tmr32_base);

//! enables PWM1 by setting "P1E" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_PWM1Enable(uint32_t tmr32_base);

//! enables deadtime by setting "DTE" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_deadtimeEnable(uint32_t tmr32_base);

//! invert PWM0 by setting "P0I" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_PWM0Invert(uint32_t tmr32_base);

//! invert PWM1 by setting "P1I" bit in the CTRL register to 1 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_PWM1Invert(uint32_t tmr32_base);

//! set the timer direction to be up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_setUpCount(uint32_t tmr32_base);

//! set the timer direction to be down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_setDownCount(uint32_t tmr32_base);

//! set the timer direction to be up/down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_setUpDownCount(uint32_t tmr32_base);

//! set the timer to be periodic
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_setPeriodic(uint32_t tmr32_base);

//! set the timer to be one shot
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
    */
void EF_TMR32_setOneShot(uint32_t tmr32_base);

//! set the action of PWM0 when the timer matches Zero value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM0MatchingZeroAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM0 when the timer matches CMPX value while up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM0MatchingCMPXAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM0 when the timer matches CMPY value while up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM0MatchingCMPYAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM0 when the timer matches Reload value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM0MatchingRELOADAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM0 when the timer matches CMPX value while down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM0MatchingCMPYDownCountAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM0 when the timer matches CMPY value while down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM0MatchingCMPXDownCountAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM1 when the timer matches Zero value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM1MatchingZeroAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM1 when the timer matches CMPX value while up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM1MatchingCMPXAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM1 when the timer matches CMPY value while up counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM1MatchingCMPXAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM1 when the timer matches Reload value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM1MatchingRELOADAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM1 when the timer matches CMPX value while down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM1MatchingCMPYDownCountAction(uint32_t tmr32_base, enum actions action);

//! set the action of PWM1 when the timer matches CMPY value while down counting 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param action enum actions could be NONE, LOW, HIGH, or INVERT
    */
void EF_TMR32_setPWM1MatchingCMPXDownCountAction(uint32_t tmr32_base, enum actions action);

//! set the timer reload value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param value timer reload value 
    */
void EF_TMR32_setRELOAD (uint32_t tmr32_base, int value);

//! get the timer reload value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \returns reload register value 
    */
int EF_TMR32_getRELOAD (uint32_t tmr32_base);

//! set the CMPX register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param value CMPX value 
    */
void EF_TMR32_setCMPX (uint32_t tmr32_base, int value);

//! get the CMPX register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \returns CMPX register value 
    */
int EF_TMR32_getCMPX (uint32_t tmr32_base);

//! set the CMPY register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param value CMPY value 
    */
void EF_TMR32_setCMPY (uint32_t tmr32_base, int value);

//! get the CMPY register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \returns CMPY register value 
    */
int EF_TMR32_getCMPY (uint32_t tmr32_base);

//! get the current value of the timer 
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \returns current timer value 
    */
int EF_TMR32_getTMR (uint32_t tmr32_base);

//! set the timer deadtime register value
    /*!
      \param tmr32_base The base memory address of TMR32 registers.
      \param value deadtime register value
    */
void EF_TMR32_setDeadtime (uint32_t tmr32_base, int value);

#endif