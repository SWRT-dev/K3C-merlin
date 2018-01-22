/* adapter_pec_lkm_ext.h
 *
 * PEC API implementation,
 * Linux kernel specific extensions
 *
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

#ifndef ADAPTER_PEC_LKM_EXT_H_
#define ADAPTER_PEC_LKM_EXT_H_


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

#include "api_pec.h"        // PEC API

#ifdef ADAPTER_PEC_ENABLE_SCATTERGATHER
#include "api_pec_sg.h"     // PEC SG API
#endif /* ADAPTER_PEC_ENABLE_SCATTERGATHER */


EXPORT_SYMBOL(PEC_Capabilities_Get);
EXPORT_SYMBOL(PEC_Init);
EXPORT_SYMBOL(PEC_UnInit);
EXPORT_SYMBOL(PEC_SA_Register);
EXPORT_SYMBOL(PEC_SA_UnRegister);
EXPORT_SYMBOL(PEC_Packet_Put);
EXPORT_SYMBOL(PEC_Packet_Get);
EXPORT_SYMBOL(PEC_CommandNotify_Request);
EXPORT_SYMBOL(PEC_ResultNotify_Request);
EXPORT_SYMBOL(PEC_CD_Control_Write);
EXPORT_SYMBOL(PEC_RD_Status_Read);

#ifdef ADAPTER_PEC_ENABLE_SCATTERGATHER
EXPORT_SYMBOL(PEC_SGList_Create);
EXPORT_SYMBOL(PEC_SGList_Destroy);
EXPORT_SYMBOL(PEC_SGList_Write);
EXPORT_SYMBOL(PEC_SGList_Read);
EXPORT_SYMBOL(PEC_SGList_GetCapacity);
EXPORT_SYMBOL(PEC_Scatter_Preload);
EXPORT_SYMBOL(PEC_Scatter_PreloadNotify_Request);
#endif /* ADAPTER_PEC_ENABLE_SCATTERGATHER */


#endif // ADAPTER_PEC_LKM_EXT_H_


/* end of file adapter_pec_lkm_ext.h */
