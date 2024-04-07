---
title: EF_TMR32.c

---

# EF_TMR32.c



## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[EF_TMR32_enable](Files/EF__TMR32_8c.md#function-ef-tmr32-enable)**(uint32_t tmr32_base)<br>enables timer by setting "TE" bit in the CTRL register to 1  |
| void | **[EF_TMR32_restart](Files/EF__TMR32_8c.md#function-ef-tmr32-restart)**(uint32_t tmr32_base)<br>enables timer re-start; used in the one-shot mode to restart the timer.  |
| void | **[EF_TMR32_PWM0Enable](Files/EF__TMR32_8c.md#function-ef-tmr32-pwm0enable)**(uint32_t tmr32_base)<br>enables PWM0 by setting "P0E" bit in the CTRL register to 1  |
| void | **[EF_TMR32_PWM1Enable](Files/EF__TMR32_8c.md#function-ef-tmr32-pwm1enable)**(uint32_t tmr32_base)<br>enables PWM1 by setting "P1E" bit in the CTRL register to 1  |
| void | **[EF_TMR32_deadtimeEnable](Files/EF__TMR32_8c.md#function-ef-tmr32-deadtimeenable)**(uint32_t tmr32_base)<br>enables deadtime by setting "DTE" bit in the CTRL register to 1  |
| void | **[EF_TMR32_PWM0Invert](Files/EF__TMR32_8c.md#function-ef-tmr32-pwm0invert)**(uint32_t tmr32_base)<br>invert PWM0 by setting "P0I" bit in the CTRL register to 1  |
| void | **[EF_TMR32_PWM1Invert](Files/EF__TMR32_8c.md#function-ef-tmr32-pwm1invert)**(uint32_t tmr32_base)<br>invert PWM1 by setting "P1I" bit in the CTRL register to 1  |
| void | **[EF_TMR32_setUpCount](Files/EF__TMR32_8c.md#function-ef-tmr32-setupcount)**(uint32_t tmr32_base)<br>set the timer direction to be up counting  |
| void | **[EF_TMR32_setDownCount](Files/EF__TMR32_8c.md#function-ef-tmr32-setdowncount)**(uint32_t tmr32_base)<br>set the timer direction to be down counting  |
| void | **[EF_TMR32_setUpDownCount](Files/EF__TMR32_8c.md#function-ef-tmr32-setupdowncount)**(uint32_t tmr32_base)<br>set the timer direction to be up/down counting  |
| void | **[EF_TMR32_setPeriodic](Files/EF__TMR32_8c.md#function-ef-tmr32-setperiodic)**(uint32_t tmr32_base)<br>set the timer to be periodic  |
| void | **[EF_TMR32_setOneShot](Files/EF__TMR32_8c.md#function-ef-tmr32-setoneshot)**(uint32_t tmr32_base)<br>set the timer to be one shot  |
| void | **[EF_TMR32_setPWM0MatchingZeroAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm0matchingzeroaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches Zero value  |
| void | **[EF_TMR32_setPWM0MatchingCMPXAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm0matchingcmpxaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches CMPX value while up counting  |
| void | **[EF_TMR32_setPWM0MatchingCMPYAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm0matchingcmpyaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches CMPY value while up counting  |
| void | **[EF_TMR32_setPWM0MatchingRELOADAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm0matchingreloadaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches Reload value  |
| void | **[EF_TMR32_setPWM0MatchingCMPYDownCountAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm0matchingcmpydowncountaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches CMPX value while down counting  |
| void | **[EF_TMR32_setPWM0MatchingCMPXDownCountAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm0matchingcmpxdowncountaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM0 when the timer matches CMPY value while down counting  |
| void | **[EF_TMR32_setPWM1MatchingZeroAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm1matchingzeroaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches Zero value  |
| void | **[EF_TMR32_setPWM1MatchingCMPXAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm1matchingcmpxaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches CMPY value while up counting  |
| void | **[EF_TMR32_setPWM1MatchingCMPYAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm1matchingcmpyaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action) |
| void | **[EF_TMR32_setPWM1MatchingRELOADAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm1matchingreloadaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches Reload value  |
| void | **[EF_TMR32_setPWM1MatchingCMPYDownCountAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm1matchingcmpydowncountaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches CMPX value while down counting  |
| void | **[EF_TMR32_setPWM1MatchingCMPXDownCountAction](Files/EF__TMR32_8c.md#function-ef-tmr32-setpwm1matchingcmpxdowncountaction)**(uint32_t tmr32_base, enum [actions](Files/EF__TMR32_8h.md#enum-actions) action)<br>set the action of PWM1 when the timer matches CMPY value while down counting  |
| void | **[EF_TMR32_setRELOAD](Files/EF__TMR32_8c.md#function-ef-tmr32-setreload)**(uint32_t tmr32_base, int value)<br>set the timer reload value  |
| int | **[EF_TMR32_getRELOAD](Files/EF__TMR32_8c.md#function-ef-tmr32-getreload)**(uint32_t tmr32_base)<br>get the timer reload value  |
| void | **[EF_TMR32_setCMPX](Files/EF__TMR32_8c.md#function-ef-tmr32-setcmpx)**(uint32_t tmr32_base, int value)<br>set the CMPX register value  |
| int | **[EF_TMR32_getCMPX](Files/EF__TMR32_8c.md#function-ef-tmr32-getcmpx)**(uint32_t tmr32_base)<br>get the CMPX register value  |
| void | **[EF_TMR32_setCMPY](Files/EF__TMR32_8c.md#function-ef-tmr32-setcmpy)**(uint32_t tmr32_base, int value)<br>set the CMPY register value  |
| int | **[EF_TMR32_getCMPY](Files/EF__TMR32_8c.md#function-ef-tmr32-getcmpy)**(uint32_t tmr32_base)<br>get the CMPY register value  |
| int | **[EF_TMR32_getTMR](Files/EF__TMR32_8c.md#function-ef-tmr32-gettmr)**(uint32_t tmr32_base)<br>get the current value of the timer  |
| void | **[EF_TMR32_setDeadtime](Files/EF__TMR32_8c.md#function-ef-tmr32-setdeadtime)**(uint32_t tmr32_base, int value)<br>set the timer deadtime register value  |
| int | **[EF_TMR32_getDeadtime](Files/EF__TMR32_8c.md#function-ef-tmr32-getdeadtime)**(uint32_t tmr32_base) |

## Defines

|                | Name           |
| -------------- | -------------- |
|  | **[EF_TMR32_C](Files/EF__TMR32_8c.md#define-ef-tmr32-c)**  |


## Functions Documentation

### function EF_TMR32_enable

```cpp
void EF_TMR32_enable(
    uint32_t tmr32_base
)
```

enables timer by setting "TE" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_restart

```cpp
void EF_TMR32_restart(
    uint32_t tmr32_base
)
```

enables timer re-start; used in the one-shot mode to restart the timer. 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_PWM0Enable

```cpp
void EF_TMR32_PWM0Enable(
    uint32_t tmr32_base
)
```

enables PWM0 by setting "P0E" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_PWM1Enable

```cpp
void EF_TMR32_PWM1Enable(
    uint32_t tmr32_base
)
```

enables PWM1 by setting "P1E" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_deadtimeEnable

```cpp
void EF_TMR32_deadtimeEnable(
    uint32_t tmr32_base
)
```

enables deadtime by setting "DTE" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_PWM0Invert

```cpp
void EF_TMR32_PWM0Invert(
    uint32_t tmr32_base
)
```

invert PWM0 by setting "P0I" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_PWM1Invert

```cpp
void EF_TMR32_PWM1Invert(
    uint32_t tmr32_base
)
```

invert PWM1 by setting "P1I" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setUpCount

```cpp
void EF_TMR32_setUpCount(
    uint32_t tmr32_base
)
```

set the timer direction to be up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setDownCount

```cpp
void EF_TMR32_setDownCount(
    uint32_t tmr32_base
)
```

set the timer direction to be down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setUpDownCount

```cpp
void EF_TMR32_setUpDownCount(
    uint32_t tmr32_base
)
```

set the timer direction to be up/down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setPeriodic

```cpp
void EF_TMR32_setPeriodic(
    uint32_t tmr32_base
)
```

set the timer to be periodic 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setOneShot

```cpp
void EF_TMR32_setOneShot(
    uint32_t tmr32_base
)
```

set the timer to be one shot 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


### function EF_TMR32_setPWM0MatchingZeroAction

```cpp
void EF_TMR32_setPWM0MatchingZeroAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches Zero value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingCMPXAction

```cpp
void EF_TMR32_setPWM0MatchingCMPXAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches CMPX value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingCMPYAction

```cpp
void EF_TMR32_setPWM0MatchingCMPYAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches CMPY value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingRELOADAction

```cpp
void EF_TMR32_setPWM0MatchingRELOADAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches Reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingCMPYDownCountAction

```cpp
void EF_TMR32_setPWM0MatchingCMPYDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches CMPX value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM0MatchingCMPXDownCountAction

```cpp
void EF_TMR32_setPWM0MatchingCMPXDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM0 when the timer matches CMPY value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM1MatchingZeroAction

```cpp
void EF_TMR32_setPWM1MatchingZeroAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches Zero value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM1MatchingCMPXAction

```cpp
void EF_TMR32_setPWM1MatchingCMPXAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches CMPY value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


set the action of PWM1 when the timer matches CMPX value while up counting


### function EF_TMR32_setPWM1MatchingCMPYAction

```cpp
void EF_TMR32_setPWM1MatchingCMPYAction(
    uint32_t tmr32_base,
    enum actions action
)
```


### function EF_TMR32_setPWM1MatchingRELOADAction

```cpp
void EF_TMR32_setPWM1MatchingRELOADAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches Reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM1MatchingCMPYDownCountAction

```cpp
void EF_TMR32_setPWM1MatchingCMPYDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches CMPX value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setPWM1MatchingCMPXDownCountAction

```cpp
void EF_TMR32_setPWM1MatchingCMPXDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of PWM1 when the timer matches CMPY value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


### function EF_TMR32_setRELOAD

```cpp
void EF_TMR32_setRELOAD(
    uint32_t tmr32_base,
    int value
)
```

set the timer reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **value** timer reload value 


### function EF_TMR32_getRELOAD

```cpp
int EF_TMR32_getRELOAD(
    uint32_t tmr32_base
)
```

get the timer reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: reload register value 

### function EF_TMR32_setCMPX

```cpp
void EF_TMR32_setCMPX(
    uint32_t tmr32_base,
    int value
)
```

set the CMPX register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **value** CMPX value 


### function EF_TMR32_getCMPX

```cpp
int EF_TMR32_getCMPX(
    uint32_t tmr32_base
)
```

get the CMPX register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: CMPX register value 

### function EF_TMR32_setCMPY

```cpp
void EF_TMR32_setCMPY(
    uint32_t tmr32_base,
    int value
)
```

set the CMPY register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **value** CMPY value 


### function EF_TMR32_getCMPY

```cpp
int EF_TMR32_getCMPY(
    uint32_t tmr32_base
)
```

get the CMPY register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: CMPY register value 

### function EF_TMR32_getTMR

```cpp
int EF_TMR32_getTMR(
    uint32_t tmr32_base
)
```

get the current value of the timer 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: current timer value 

### function EF_TMR32_setDeadtime

```cpp
void EF_TMR32_setDeadtime(
    uint32_t tmr32_base,
    int value
)
```

set the timer deadtime register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **value** deadtime register value 


### function EF_TMR32_getDeadtime

```cpp
int EF_TMR32_getDeadtime(
    uint32_t tmr32_base
)
```




## Macros Documentation

### define EF_TMR32_C

```cpp
#define EF_TMR32_C 
```


## Source code

```cpp

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
```


-------------------------------

Updated on 2024-04-07 at 13:02:30 +0200
