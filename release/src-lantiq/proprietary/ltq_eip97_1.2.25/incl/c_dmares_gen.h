/* c_dmares_gen.h
 *
 * Default configuration for generic Driver Framework DMAResource API
 * implementation.
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
* In case you do not have an account for this system, please send an e-mail
* to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/

#ifndef C_DMARES_GEN_H_
#define C_DMARES_GEN_H_


/*----------------------------------------------------------------
 * get configuration settings from product config file
 */
#include "cs_hwpal.h"

// choose from LOG_SEVERITY_INFO, LOG_SEVERITY_WARN, LOG_SEVERITY_CRIT
#ifndef HWPAL_LOG_SEVERITY
#define HWPAL_LOG_SEVERITY  LOG_SEVERITY_CRIT
#endif

#ifdef HWPAL_DMARESOURCE_BANKS_ENABLE
#ifndef HWPAL_DMARESOURCE_BANKS
#error "Expected HWPAL_DMARESOURCE_BANKS defined by cs_hwpal.h"
#endif
#endif // HWPAL_DMARESOURCE_BANKS_ENABLE

// Enable use of UMDevXS and SHDevXS API's
#ifdef HWPAL_USE_UMDEVXS_PCI_DEVICE
#define HWPAL_DMARESOURCE_USE_UMDEVXS_PCI_DEVICE
#endif // HWPAL_USE_UMDEVXS_PCI_DEVICE

/*----------------------------------------------------------------
 * Other configuration parameters that can be set in a top level
 * configuration
 */

// Enables DMA resources banks so that different memory regions can be used
// for DMA buffer allocation
//#define HWPAL_DMARESOURCE_BANKS_ENABLE


#endif // C_DMARES_GEN_H_


/* end of file c_dmares_gen.h */
