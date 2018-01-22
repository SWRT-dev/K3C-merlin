/* eip97_global_prng.h
 *
 * EIP-97 Global Control Driver Library API:
 * PRNG Re-Seed use case
 *
 * Refer to the EIP-97 Driver Library User Guide for information about
 * re-entrance and usage from concurrent execution contexts of this API
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

#ifndef EIP97_GLOBAL_PRNG_H_
#define EIP97_GLOBAL_PRNG_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // uint32_t

// EIP-97 Global Control Driver Library Types API
#include "eip97_global_types.h" // EIP97_* types


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// EIP-96 PRNG Re-seed data
typedef struct
{
    // Seed value low 32-bit word
    uint32_t SeedLo;

    // Seed value high 32-bit word
    uint32_t SeedHi;

    // Key register 0 value low 32-bit word
    uint32_t Key0Lo;

    // Key register 0 value high 32-bit word
    uint32_t Key0Hi;

    // Key register 1 value low 32-bit word
    uint32_t Key1Lo;

    // Key register 1 value high 32-bit word
    uint32_t Key1Hi;

    // Seed value low 32-bit word
    uint32_t LFSRLo;

    // Seed value high 32-bit word
    uint32_t LFSRHi;
} EIP96_PRNG_Reseed_t;


/*----------------------------------------------------------------------------
 * EIP97_Global_PRNG_Reseed
 *
 * This function returns hardware revision information in the Capabilities_p
 * data structure.
 *
 * IOArea_p (input)
 *     Pointer to the place holder in memory for the IO Area.
 *
 * PE_Number (input)
 *     Number of the PE that must be re-seed.
 *
 * ReseedData_p (input)
 *     Pointer to the PRNG seed and key data.
 *
 * Return value
 *     EIP97_GLOBAL_NO_ERROR : operation is completed
 *     EIP97_GLOBAL_ARGUMENT_ERROR : Passed wrong argument
 *     EIP97_GLOBAL_ILLEGAL_IN_STATE : invalid API state transition
 */
EIP97_Global_Error_t
EIP97_Global_PRNG_Reseed(
        EIP97_Global_IOArea_t * const IOArea_p,
        const unsigned int PE_Number,
        const EIP96_PRNG_Reseed_t * const ReseedData_p);


#endif /* EIP97_GLOBAL_PRNG_H_ */


/* end of file eip97_global_prng.h */
