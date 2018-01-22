/* cs_adapter_ext.h
 *
 * Configuration Settings for the SLAD Adapter Combined module,
 * extensions.
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

#ifndef CS_ADAPTER_EXT_H_
#define CS_ADAPTER_EXT_H_


/****************************************************************************
 * Adapter Global configuration parameters
 */


/****************************************************************************
 * Adapter PEC configuration parameters
 */


/****************************************************************************
 * Adapter EIP-202 configuration parameters
 */

// Enables the EIP-207 Record Cache interface for the record invalidation
//#define ADAPTER_EIP202_RC_SUPPORT

#ifdef DRIVER_DMARESOURCE_BANKS_ENABLE
#define ADAPTER_EIP202_DMARESOURCE_BANKS_ENABLE

#define ADAPTER_EIP202_TRANSFORM_RECORD_COUNT      \
                                        DRIVER_TRANSFORM_RECORD_COUNT
#define ADAPTER_EIP202_TRANSFORM_RECORD_BYTE_COUNT \
                                        DRIVER_TRANSFORM_RECORD_BYTE_COUNT
#endif // DRIVER_DMARESOURCE_BANKS_ENABLE


#endif // CS_ADAPTER_EXT_H_


/* end of file cs_adapter_ext.h */
