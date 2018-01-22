/* eip202_cdr_event.c
 *
 * EIP-202 Ring Control Driver Library
 * CDR Event Management API implementation
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

#include "eip202_cdr.h"


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Default configuration
#include "c_eip202_ring.h"

// EIP-202 Ring Control Driver Library Internal interfaces
#include "eip202_ring_internal.h"
#include "eip202_cdr_level0.h"         // EIP-202 Level 0 macros
#include "eip202_cdr_fsm.h"             // CDR State machine

// Driver Framework Basic Definitions API
#include "basic_defs.h"                // IDENTIFIER_NOT_USED, bool, uint32_t


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

/*----------------------------------------------------------------------------
 * Local variables
 */


/*----------------------------------------------------------------------------
 * EIP202_CDR_Status_Get
 */
EIP202_Ring_Error_t
EIP202_CDR_Status_Get(
        EIP202_Ring_IOArea_t * const IOArea_p,
        EIP202_CDR_Status_t * const Status_p)
{
    Device_Handle_t Device;
    EIP202_Ring_Error_t rv;
    volatile EIP202_CDR_True_IOArea_t * const TrueIOArea_p = CDRIOAREA(IOArea_p);

    EIP202_RING_CHECK_POINTER(IOArea_p);
    EIP202_RING_CHECK_POINTER(Status_p);

    Device = TrueIOArea_p->Device;

    EIP202_CDR_STAT_RD(Device,
                       &Status_p->fDMAError,
                       &Status_p->fTresholdInt,
                       &Status_p->fError,
                       &Status_p->fOUFlowError,
                       &Status_p->fTimeoutInt,
                       &Status_p->CDFIFOWordCount);

    // Transit to a new state
    if(Status_p->fDMAError)
        rv = EIP202_CDR_State_Set((volatile EIP202_CDR_State_t*)&TrueIOArea_p->State,
                                 EIP202_CDR_STATE_FATAL_ERROR);
    else
        // Remain in the current state
        rv = EIP202_CDR_State_Set((volatile EIP202_CDR_State_t*)&TrueIOArea_p->State,
                                 (EIP202_CDR_State_t)TrueIOArea_p->State);
    if(rv != EIP202_RING_NO_ERROR)
        return EIP202_RING_ILLEGAL_IN_STATE;

    return EIP202_RING_NO_ERROR;
}


/*----------------------------------------------------------------------------
 * EIP202_CDR_FillLevel_Low_INT_Enable
 */
EIP202_Ring_Error_t
EIP202_CDR_FillLevel_Low_INT_Enable(
        EIP202_Ring_IOArea_t * const IOArea_p,
        const unsigned int ThresholdDscrCount,
        const unsigned int Timeout)
{
    Device_Handle_t Device;
    EIP202_Ring_Error_t rv;
    volatile EIP202_CDR_True_IOArea_t * const TrueIOArea_p = CDRIOAREA(IOArea_p);

    EIP202_RING_CHECK_POINTER(IOArea_p);

    Device = TrueIOArea_p->Device;

    EIP202_CDR_THRESH_WR(Device,
                         (uint32_t)ThresholdDscrCount *
                               TrueIOArea_p->DescOffsWordCount,
                         (uint8_t)Timeout);

    // Remain in the current state
    rv = EIP202_CDR_State_Set((volatile EIP202_CDR_State_t*)&TrueIOArea_p->State,
                             (EIP202_CDR_State_t)TrueIOArea_p->State);
    if(rv != EIP202_RING_NO_ERROR)
        return EIP202_RING_ILLEGAL_IN_STATE;

    return EIP202_RING_NO_ERROR;
}


/*----------------------------------------------------------------------------
 * EIP202_CDR_FillLevel_Low_INT_ClearAndDisable
 */
EIP202_Ring_Error_t
EIP202_CDR_FillLevel_Low_INT_ClearAndDisable(
        EIP202_Ring_IOArea_t * const IOArea_p)
{
    Device_Handle_t Device;
    EIP202_Ring_Error_t rv;
    volatile EIP202_CDR_True_IOArea_t * const TrueIOArea_p = CDRIOAREA(IOArea_p);

    EIP202_RING_CHECK_POINTER(IOArea_p);

    Device = TrueIOArea_p->Device;

    // Disable timeout interrupt and stop timeout counter for
    // reducing power consumption
    EIP202_CDR_THRESH_DEFAULT_WR(Device);

    // Clear all CDR interrupts
    EIP202_CDR_STAT_CLEAR_ALL_IRQ_WR(Device);

    // Remain in the current state
    rv = EIP202_CDR_State_Set((volatile EIP202_CDR_State_t*)&TrueIOArea_p->State,
                             (EIP202_CDR_State_t)TrueIOArea_p->State);
    if(rv != EIP202_RING_NO_ERROR)
        return EIP202_RING_ILLEGAL_IN_STATE;

    return EIP202_RING_NO_ERROR;
}


/* end of file eip202_cdr_event.c */
