/* adapter_interrupts_ext.h
 *
 * Host hardware specific extensions for the Adapter Interrupts interface
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

#ifndef ADAPTER_INTERRUPTS_EXT_H_
#define ADAPTER_INTERRUPTS_EXT_H_

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Adapter EIP-202 Default configuration
#include "c_adapter_eip202.h"


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Adapter logical EIP-(1)97 interrupts
enum
{
    ADAPTER_EIP202_LOGICAL_INTERRUPTS
};


#endif /* ADAPTER_INTERRUPTS_EXT_H_ */

/* end of file adapter_interrupts_ext.h */
