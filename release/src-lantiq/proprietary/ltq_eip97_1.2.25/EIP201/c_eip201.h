/* c_eip201.h
 *
 * Configuration options for the EIP201 Driver Library module.
 * The project-specific cs_eip201.h file is included,
 * whereafter defaults are provided for missing parameters.
 */

/*****************************************************************************
* Copyright (c) 2007-2013 INSIDE Secure B.V. All Rights Reserved.
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

/*----------------------------------------------------------------
 * Defines that can be used in the cs_xxx.h file
 */

/* EIP201_STRICT_ARGS
 *
 * Set this option to enable checking of all arguments to all EIP201 DL
 * functions. Disable it to reduce code size and reduce overhead.
 */

/* EIP201_STRICT_ARGS_MAX_NUM_OF_INTERRUPTS <NOI>
 *
 * This configures the maximum Number Of Interrupt (NOI) sources
 * actually available in the EIP201 AIC.
 * This can be used for strict argument checking.
 */

/*----------------------------------------------------------------
 * inclusion of cs_eip201.h
 */
#include "cs_eip201.h"


/*----------------------------------------------------------------
 * provide backup values for all missing configuration parameters
 */
#if !defined(EIP201_STRICT_ARGS_MAX_NUM_OF_INTERRUPTS) \
             || (EIP201_STRICT_ARGS_MAX_NUM_OF_INTERRUPTS > 32)
#undef  EIP201_STRICT_ARGS_MAX_NUM_OF_INTERRUPTS
#define EIP201_STRICT_ARGS_MAX_NUM_OF_INTERRUPTS 32
#endif


/*----------------------------------------------------------------
 * other configuration parameters that cannot be set in cs_xxx.h
 * but are considered product-configurable anyway
 */


/*----------------------------------------------------------------
 * correct implementation-specific collisions
 */

#ifndef EIP201_REMOVE_INITIALIZE
// EIP201_Initialize internally depends on EIP201_Config_Change
#ifdef EIP201_REMOVE_CONFIG_CHANGE
#undef EIP201_REMOVE_CONFIG_CHANGE
#endif
#endif

/* end of file c_eip201.h */
