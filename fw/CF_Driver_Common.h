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

/*! \file CF_Driver_Common.h
    \brief C header file for common driver definitions and types
    
*/


#ifndef CF_DRIVER_COMMON_H
#define CF_DRIVER_COMMON_H

/******************************************************************************
* Includes
******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


/******************************************************************************
* Macros and Constants
******************************************************************************/

/* IO types */
#ifndef IO_TYPES
#define IO_TYPES

    #define   __R     volatile const uint32_t       ///< Read only
    #define   __W     volatile       uint32_t       ///< Write only
    #define   __RW    volatile       uint32_t       ///< Read / Write

#endif

/* General return codes */
#define CF_DRIVER_OK                    ((uint32_t)0)   ///< Operation succeeded 
#define CF_DRIVER_ERROR                 ((uint32_t)1)   ///< Unspecified error
#define CF_DRIVER_ERROR_BUSY            ((uint32_t)2)   ///< Driver is busy
#define CF_DRIVER_ERROR_TIMEOUT         ((uint32_t)3)   ///< Timeout occurred
#define CF_DRIVER_ERROR_UNSUPPORTED     ((uint32_t)4)   ///< Operation not supported
#define CF_DRIVER_ERROR_PARAMETER       ((uint32_t)5)   ///< Parameter error
#define CF_DRIVER_ERROR_SPECIFIC        ((uint32_t)6)   ///< Start of driver specific errors 

#define CF_DRIVER_ERROR_I2C_INVALID_DATA ((uint32_t)7)  ///< Invalid data received on I2C bus


/******************************************************************************
* Typedefs and Enums
******************************************************************************/

typedef uint32_t CF_DRIVER_STATUS;      ///<  A type that is used to return the status of the driver functions


/******************************************************************************
* External Variables
******************************************************************************/


/******************************************************************************
* Function Prototypes
******************************************************************************/


#endif // CF_DRIVER_COMMON_H 

/******************************************************************************
* End of File
******************************************************************************/
