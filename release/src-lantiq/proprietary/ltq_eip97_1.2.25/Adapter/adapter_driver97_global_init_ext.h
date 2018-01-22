/* adapter_driver97_global_init_ext.h
 *
 * Linux kernel specific Adapter Global Control extensions
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
* In case you do not have an account for
* this system, please send an e-mail to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Default Adapter configuration
#include "c_adapter_global.h"   // ADAPTER_GLOBAL_LICENSE

// Linux Kernel API
#include <linux/init.h>     // module_init, module_exit
#include <linux/module.h>   // EXPORT_SYMBOL


/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
 */

// Global Packet I/O Control Init API
#include "api_global_eip97.h"

// Global Packet I/O Control Status API
#include "api_global_status_eip97.h"


MODULE_LICENSE(ADAPTER_GLOBAL_LICENSE);

// Global Packet I/O Control Status API
EXPORT_SYMBOL(GlobalControl97_Capabilities_Get);
EXPORT_SYMBOL(GlobalControl97_Init);
EXPORT_SYMBOL(GlobalControl97_UnInit);
EXPORT_SYMBOL(GlobalControl97_Configure);

// Global Packet I/O Control Status API
EXPORT_SYMBOL(GlobalControl97_DFE_Status_Get);
EXPORT_SYMBOL(GlobalControl97_DSE_Status_Get);
EXPORT_SYMBOL(GlobalControl97_Token_Status_Get);
EXPORT_SYMBOL(GlobalControl97_Context_Status_Get);
EXPORT_SYMBOL(GlobalControl97_Interrupt_Status_Get);
EXPORT_SYMBOL(GlobalControl97_OutXfer_Status_Get);
EXPORT_SYMBOL(GlobalControl97_PRNG_Status_Get);
EXPORT_SYMBOL(GlobalControl97_PRNG_Reseed);

module_init(Driver97_Global_Init);
module_exit(Driver97_Global_Exit);

/* end of file adapter_driver97_init_ext.h */
