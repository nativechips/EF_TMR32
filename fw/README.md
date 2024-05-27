##  APIs Documentation

###  EF_TMR32_enable

```cpp
void EF_TMR32_enable(
    uint32_t tmr32_base
)
```

enables timer by setting "TE" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_restart

```cpp
void EF_TMR32_restart(
    uint32_t tmr32_base
)
```

enables timer re-start; used in the one-shot mode to restart the timer. 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_PWM0Enable

```cpp
void EF_TMR32_PWM0Enable(
    uint32_t tmr32_base
)
```

enables TMR0 by setting "P0E" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_PWM1Enable

```cpp
void EF_TMR32_PWM1Enable(
    uint32_t tmr32_base
)
```

enables TMR1 by setting "P1E" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_deadtimeEnable

```cpp
void EF_TMR32_deadtimeEnable(
    uint32_t tmr32_base
)
```

enables deadtime by setting "DTE" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_PWM0Invert

```cpp
void EF_TMR32_PWM0Invert(
    uint32_t tmr32_base
)
```

invert TMR0 by setting "P0I" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_PWM1Invert

```cpp
void EF_TMR32_PWM1Invert(
    uint32_t tmr32_base
)
```

invert TMR1 by setting "P1I" bit in the CTRL register to 1 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_setUpCount

```cpp
void EF_TMR32_setUpCount(
    uint32_t tmr32_base
)
```

set the timer direction to be up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_setDownCount

```cpp
void EF_TMR32_setDownCount(
    uint32_t tmr32_base
)
```

set the timer direction to be down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_setUpDownCount

```cpp
void EF_TMR32_setUpDownCount(
    uint32_t tmr32_base
)
```

set the timer direction to be up/down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_setPeriodic

```cpp
void EF_TMR32_setPeriodic(
    uint32_t tmr32_base
)
```

set the timer to be periodic 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_setOneShot

```cpp
void EF_TMR32_setOneShot(
    uint32_t tmr32_base
)
```

set the timer to be one shot 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


###  EF_TMR32_setPWM0MatchingZeroAction

```cpp
void EF_TMR32_setPWM0MatchingZeroAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR0 when the timer matches Zero value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM0MatchingCMPXAction

```cpp
void EF_TMR32_setPWM0MatchingCMPXAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR0 when the timer matches CMPX value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM0MatchingCMPYAction

```cpp
void EF_TMR32_setPWM0MatchingCMPYAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR0 when the timer matches CMPY value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM0MatchingRELOADAction

```cpp
void EF_TMR32_setPWM0MatchingRELOADAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR0 when the timer matches Reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM0MatchingCMPYDownCountAction

```cpp
void EF_TMR32_setPWM0MatchingCMPYDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR0 when the timer matches CMPX value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM0MatchingCMPXDownCountAction

```cpp
void EF_TMR32_setPWM0MatchingCMPXDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR0 when the timer matches CMPY value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM1MatchingZeroAction

```cpp
void EF_TMR32_setPWM1MatchingZeroAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR1 when the timer matches Zero value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM1MatchingCMPXAction

```cpp
void EF_TMR32_setPWM1MatchingCMPXAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR1 when the timer matches CMPX value while up counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT
  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


set the action of TMR1 when the timer matches CMPY value while up counting


set the action of TMR1 when the timer matches CMPX value while up counting


###  EF_TMR32_setPWM1MatchingRELOADAction

```cpp
void EF_TMR32_setPWM1MatchingRELOADAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR1 when the timer matches Reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM1MatchingCMPYDownCountAction

```cpp
void EF_TMR32_setPWM1MatchingCMPYDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR1 when the timer matches CMPX value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setPWM1MatchingCMPXDownCountAction

```cpp
void EF_TMR32_setPWM1MatchingCMPXDownCountAction(
    uint32_t tmr32_base,
    enum actions action
)
```

set the action of TMR1 when the timer matches CMPY value while down counting 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 
  * **action** enum actions could be NONE, LOW, HIGH, or INVERT 


###  EF_TMR32_setRELOAD

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


###  EF_TMR32_getRELOAD

```cpp
int EF_TMR32_getRELOAD(
    uint32_t tmr32_base
)
```

get the timer reload value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: reload register value 

###  EF_TMR32_setCMPX

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


###  EF_TMR32_getCMPX

```cpp
int EF_TMR32_getCMPX(
    uint32_t tmr32_base
)
```

get the CMPX register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: CMPX register value 

###  EF_TMR32_setCMPY

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


###  EF_TMR32_getCMPY

```cpp
int EF_TMR32_getCMPY(
    uint32_t tmr32_base
)
```

get the CMPY register value 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: CMPY register value 

###  EF_TMR32_getTMR

```cpp
int EF_TMR32_getTMR(
    uint32_t tmr32_base
)
```

get the current value of the timer 

**Parameters**: 

  * **tmr32_base** The base memory address of TMR32 registers. 


**Return**: current timer value 

###  EF_TMR32_setDeadtime

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