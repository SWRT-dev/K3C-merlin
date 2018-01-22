/* eip97_global_prng.c
 *
 * EIP-97 GLobal Control Driver Library
 * PRNG Module
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

/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
 */

#include "eip97_global_prng.h"


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Device API
#include "device_types.h"              // Device_Handle_t

// EIP-97 Global Control Driver Library Internal interfaces
#include "eip97_global_internal.h"
#include "eip96_level0.h"              // EIP-96 Level 0 macros
#include "eip97_global_fsm.h"          // State machine


/*----------------------------------------------------------------------------
 * Definitions and macros
 */


/*----------------------------------------------------------------------------
 * Local variables
 */


/*----------------------------------------------------------------------------
 * EIP97_Global_PRNG_Reseed
 */
EIP97_Global_Error_t
EIP97_Global_PRNG_Reseed(
        EIP97_Global_IOArea_t * const IOArea_p,
        const unsigned int PE_Number,
        const EIP96_PRNG_Reseed_t * const ReseedData_p)
{
    Device_Handle_t Device;
    volatile EIP97_True_IOArea_t * const TrueIOArea_p = IOAREA(IOArea_p);

    EIP97_GLOBAL_CHECK_POINTER(IOArea_p);

    if(PE_Number != PE_DEFAULT_NR)
        return EIP97_GLOBAL_ARGUMENT_ERROR;

    Device = TrueIOArea_p->Device;

#ifdef EIP97_GLOBAL_DEBUG_FSM
    {
        EIP97_Global_Error_t rv;

        // Remain in the current state
        rv = EIP97_Global_State_Set((volatile EIP97_Global_State_t*)&TrueIOArea_p->State,
                                    (EIP97_Global_State_t)TrueIOArea_p->State);
        if(rv != EIP97_GLOBAL_NO_ERROR)
            return EIP97_GLOBAL_ILLEGAL_IN_STATE;
    }
#endif // EIP97_GLOBAL_DEBUG_FSM

    EIP96_PRNG_CTRL_WR(Device,
                       PE_Number, // EIP-96 PE number
                       false,     // Disable PRNG
                       false);    // Set PRNG Manual mode

    // Write new seed data
    EIP96_PRNG_SEED_L_WR(Device, PE_Number, ReseedData_p->SeedLo);
    EIP96_PRNG_SEED_H_WR(Device, PE_Number, ReseedData_p->SeedHi);

    // Write new key data
    EIP96_PRNG_KEY_0_L_WR(Device, PE_Number, ReseedData_p->Key0Lo);
    EIP96_PRNG_KEY_0_H_WR(Device, PE_Number, ReseedData_p->Key0Hi);
    EIP96_PRNG_KEY_1_L_WR(Device, PE_Number, ReseedData_p->Key1Lo);
    EIP96_PRNG_KEY_1_H_WR(Device, PE_Number, ReseedData_p->Key1Hi);

    // Write new LFSR data
    EIP96_PRNG_LFSR_L_WR(Device, PE_Number, ReseedData_p->LFSRLo);
    EIP96_PRNG_LFSR_H_WR(Device, PE_Number, ReseedData_p->LFSRHi);

    EIP96_PRNG_CTRL_WR(Device,
                       PE_Number, // EIP-96 PE number
                       true,      // Enable PRNG
                       true);     // Set PRNG Auto mode

    return EIP97_GLOBAL_NO_ERROR;
}


/* end of file eip97_global_prng.c */


