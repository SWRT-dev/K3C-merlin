/* c_adapter_global.h
 *
 * Default Adapter Global configuration
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
* In case you do not have an account for
* this system, please send an e-mail to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#ifndef INCLUDE_GUARD_C_ADAPTER_GLOBAL_H
#define INCLUDE_GUARD_C_ADAPTER_GLOBAL_H

/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Top-level Adapter configuration
#include "cs_adapter.h"


#ifndef ADAPTER_GLOBAL_PRNG_SEED
// 8 words to seed the PRNG to provide IVs, input to
#define ADAPTER_GLOBAL_PRNG_SEED {0x48c24cfd, 0x6c07f742, \
                                  0xaee75681, 0x0f27c239, \
                                  0x79947198, 0xe2991275, \
                                  0x21ac3c7c, 0xd008c4b4}
#endif

#ifndef ADAPTER_GLOBAL_DEVICE_NAME
#define ADAPTER_GLOBAL_DEVICE_NAME           "EIP97_GLOBAL"
#endif // ADAPTER_GLOBAL_DEVICE_NAME

#ifndef ADAPTER_GLOBAL_RESET_MAX_RETRIES
#define ADAPTER_GLOBAL_RESET_MAX_RETRIES      1000
#endif // ADAPTER_GLOBAL_RESET_MAX_RETRIES

#ifndef ADAPTER_GLOBAL_EIP97_NOF_PES
#define ADAPTER_GLOBAL_EIP97_NOF_PES          1
#endif

#ifndef ADAPTER_GLOBAL_EIP97_RINGMASK
#define ADAPTER_GLOBAL_EIP97_RINGMASK         0x0003
#endif

#ifndef ADAPTER_GLOBAL_EIP97_PRIOMASK
#define ADAPTER_GLOBAL_EIP97_PRIOMASK         0
#endif

#endif /* Include Guard */


/* end of file c_adapter_global.h */
