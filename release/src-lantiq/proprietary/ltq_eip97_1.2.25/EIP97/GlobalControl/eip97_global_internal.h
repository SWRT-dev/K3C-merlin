/* eip97_global_internal.h
 *
 * EIP-97 Global Control Driver Library Internal interface
 */

/*****************************************************************************
* Copyright (c) 2011-2013 INSIDE Secure B.V. All Rights Reserved.
*
* This confidential and proprietary software may be used only as authorized
* by a licensing agreement from INSIDE Secure.
*
* The entire notice above must be reproduced on all authorized copies that
* may only be made to the extent permitted by a licensing agreement from
* INSIDE Secure.
*
* For more information or support, please go to our online support system at
* https://essoemsupport.insidesecure.com.
* In case you do not have an account for this system, please send an e-mail
* to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#ifndef EIP97_GLOBAL_INTERNAL_H_
#define EIP97_GLOBAL_INTERNAL_H_

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Default configuration
#include "c_eip97_global.h"

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // uint8_t, uint32_t

// Driver Framework Device API
#include "device_types.h"       // Device_Handle_t

// EIP-97 Driver Library Types API
#include "eip97_global_types.h" // EIP97_* types

/*----------------------------------------------------------------------------
 * Definitions and macros
 */

#define PE_DEFAULT_NR     0  // Default Processing Engine number

#if (PE_DEFAULT_NR >= EIP97_GLOBAL_MAX_NOF_PE_TO_USE)
#error "Error: PE_DEFAULT_NR must be less than EIP97_GLOBAL_MAX_NOF_PE_TO_USE"
#endif

// I/O Area, used internally
typedef struct
{
    Device_Handle_t Device;
    uint32_t State;
} EIP97_True_IOArea_t;

#define IOAREA(_p) ((volatile EIP97_True_IOArea_t *)_p)

#ifdef EIP97_GLOBAL_STRICT_ARGS
#define EIP97_GLOBAL_CHECK_POINTER(_p) \
    if (NULL == (_p)) \
        return EIP97_GLOBAL_ARGUMENT_ERROR;
#define EIP97_GLOBAL_CHECK_INT_INRANGE(_i, _min, _max) \
    if ((_i) < (_min) || (_i) > (_max)) \
        return EIP97_GLOBAL_ARGUMENT_ERROR;
#define EIP97_GLOBAL_CHECK_INT_ATLEAST(_i, _min) \
    if ((_i) < (_min)) \
        return EIP97_GLOBAL_ARGUMENT_ERROR;
#define EIP97_GLOBAL_CHECK_INT_ATMOST(_i, _max) \
    if ((_i) > (_max)) \
        return EIP97_GLOBAL_ARGUMENT_ERROR;
#else
/* EIP97_GLOBAL_STRICT_ARGS undefined */
#define EIP97_GLOBAL_CHECK_POINTER(_p)
#define EIP97_GLOBAL_CHECK_INT_INRANGE(_i, _min, _max)
#define EIP97_GLOBAL_CHECK_INT_ATLEAST(_i, _min)
#define EIP97_GLOBAL_CHECK_INT_ATMOST(_i, _max)
#endif /*end of EIP97_GLOBAL_STRICT_ARGS */

#define TEST_SIZEOF(type, size) \
    extern int size##_must_bigger[1 - 2*((int)(sizeof(type) > size))]

// validate the size of the fake and real IOArea structures
TEST_SIZEOF(EIP97_True_IOArea_t, EIP97_GLOBAL_IOAREA_REQUIRED_SIZE);


#endif /* EIP97_GLOBAL_INTERNAL_H_ */


/* end of file eip97_global_internal.h */
