/* cs_hwpal_ext2.h
 *
 * SafeXcel-IP-97 hardware specific configuration parameters
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

#ifndef CS_HWPAL_EXT2_H_
#define CS_HWPAL_EXT2_H_


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

// Enables DMA resources banks so that different memory regions can be used
// for DMA buffer allocation
#ifdef DRIVER_DMARESOURCE_BANKS_ENABLE
#define HWPAL_DMARESOURCE_BANKS_ENABLE
#endif // DRIVER_DMARESOURCE_BANKS_ENABLE

#ifdef HWPAL_DMARESOURCE_BANKS_ENABLE
// Definition of DMA banks, one dynamic and 1 static
//                                  Bank   Static   Blocks   Block size
#define HWPAL_DMARESOURCE_BANKS                                          \
        HWPAL_DMARESOURCE_BANK_ADD (0,       0,       0,          0),    \
        HWPAL_DMARESOURCE_BANK_ADD (1,       1,                          \
                                    DRIVER_TRANSFORM_RECORD_COUNT,       \
                                    DRIVER_TRANSFORM_RECORD_BYTE_COUNT)
#endif // HWPAL_DMARESOURCE_BANKS_ENABLE


#endif /* CS_HWPAL_EXT2_H_ */


/* end of file cs_hwpal_ext2.h */
