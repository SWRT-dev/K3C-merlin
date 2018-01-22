/* adapter_driver97_init_ext.h
 *
 * Linux kernel specific Adapter extensions
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


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Top-level Adapter configuration
#include "cs_adapter.h"

// Linux Kernel API
#include <linux/init.h>     // module_init, module_exit
#include <linux/module.h>   // EXPORT_SYMBOL


/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
 */

#include "api_dmabuf.h"     // DMABuf API


//MODULE_LICENSE(ADAPTER_LICENSE);

//module_init(Driver97_Init);
//module_exit(Driver97_Exit);

EXPORT_SYMBOL(DMABuf_NULLHandle);
EXPORT_SYMBOL(DMABuf_Handle_IsSame);
EXPORT_SYMBOL(DMABuf_Alloc);
EXPORT_SYMBOL(DMABuf_Register);
EXPORT_SYMBOL(DMABuf_Release);


// PEC API LKM implementation extensions
#include "adapter_pec_lkm_ext.h"


/* end of file adapter_driver97_init_ext.h */
