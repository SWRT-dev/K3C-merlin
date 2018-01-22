/* c_adapter_pec.h
 *
 * Default Adapter PEC configuration
 */

/*****************************************************************************
* Copyright (c) 2012-2013 INSIDE Secure B.V. All Rights Reserved.
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

#ifndef INCLUDE_GUARD_C_ADAPTER_PEC_H
#define INCLUDE_GUARD_C_ADAPTER_PEC_H

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Top-level Adapter configuration
#include "cs_adapter.h"


/****************************************************************************
 * Adapter general configuration parameters
 */

#ifndef ADAPTER_PEC_BANK_PACKET
#define ADAPTER_PEC_BANK_PACKET         0
#endif

#ifndef ADAPTER_PEC_BANK_TOKEN
#define ADAPTER_PEC_BANK_TOKEN          0
#endif

#ifndef ADAPTER_PEC_BANK_SA
#define ADAPTER_PEC_BANK_SA             0
#endif

//#define ADAPTER_PEC_STRICT_ARGS

#ifndef ADAPTER_PEC_DEVICE_COUNT
#define ADAPTER_PEC_DEVICE_COUNT           2
#endif

#ifndef ADAPTER_PEC_MAX_PACKETS
#define ADAPTER_PEC_MAX_PACKETS         32
#endif

#ifndef ADAPTER_PEC_MAX_LOGICDESCR
#define ADAPTER_PEC_MAX_LOGICDESCR      32
#endif

//#define ADAPTER_PEC_SEPARATE_RINGS
//#define ADAPTER_PEC_ENABLE_SCATTERGATHER
//#define ADAPTER_PEC_INTERRUPTS_ENABLE
//#define ADAPTER_PEC_ARMRING_ENABLE_SWAP

// Remove bounce buffers support
//#define ADAPTER_PEC_REMOVE_BOUNCEBUFFERS


#endif /* Include Guard */


/* end of file c_adapter_pec.h */
