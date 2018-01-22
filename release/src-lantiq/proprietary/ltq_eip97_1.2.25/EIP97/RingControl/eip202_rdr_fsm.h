/* eip202_rdr_fsm.h
 *
 * EIP-202 Ring Control Driver Library API State Machine Internal Interface
 * for Result Descriptor Ring (RDR)
 *
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

#ifndef EIP202_RDR_FSM_H_
#define EIP202_RDR_FSM_H_

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

#include "eip202_ring_types.h"            // EIP202_Ring_Error_t

/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// EIP-202 Ring Control Driver Library API States for RDR
typedef enum
{
    EIP202_RDR_STATE_UNKNOWN = 1,
    EIP202_RDR_STATE_UNINITIALIZED,
    EIP202_RDR_STATE_INITIALIZED,
    EIP202_RDR_STATE_FREE,
    EIP202_RDR_STATE_FULL,
    EIP202_RDR_STATE_FATAL_ERROR
} EIP202_RDR_State_t;


/*----------------------------------------------------------------------------
 * EIP202_RDR_State_Set
 *
 * This function check whether the transition from the "CurrentState" to the
 * "NewState" is allowed and if yes changes the former to the latter.
 *
  * Return value
 *     EIP202_RING_NO_ERROR : operation is completed
 *     EIP202_RING_ILLEGAL_IN_STATE : state transition is not allowed
 */
EIP202_Ring_Error_t
EIP202_RDR_State_Set(
        volatile EIP202_RDR_State_t * const CurrentState,
        const EIP202_RDR_State_t NewState);


#endif /* EIP202_RDR_FSM_H_ */


/* end of file eip202_rdr_fsm.h */
