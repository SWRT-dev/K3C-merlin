/* api_global_eip97.h
 *
 * SafeXcel-IP-97 Global Control API
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

#ifndef API_GLOBAL_EIP97_H_
#define API_GLOBAL_EIP97_H_

// The status part of the API
#include "api_global_status_eip97.h"


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Basic Definitions API
#include "basic_defs.h"         // uint8_t, uint32_t, bool

// EIP-97 Driver Library Global API
#include "eip97_global_init.h"  // Initialization
#include "eip97_global_prng.h"  // PRNG


/*----------------------------------------------------------------------------
 * Definitions and macros
 */

#define GLOBAL_CONTROL_MAXLEN_TEXT      128

// Ring PE assignment map
typedef EIP97_Global_Ring_PE_Map_t      GlobalControl97_Ring_PE_Map_t;

// Zero-terminated descriptive text of the available services.
typedef struct
{
    char szTextDescription[GLOBAL_CONTROL_MAXLEN_TEXT];
} GlobalControl97_Capabilities_t;


/*----------------------------------------------------------------------------
 * GlobalControl97_Capabilities_Get
 *
 * This routine returns a structure that describes the capabilities of the
 * implementation. See description of GlobalControl97_Capabilities_t
 * for details.
 *
 * Capabilities_p
 *     Pointer to the capabilities structure to fill in.
 *
 * This function is re-entrant.
 */
GlobalControl97_Error_t
GlobalControl97_Capabilities_Get(
        GlobalControl97_Capabilities_t * const Capabilities_p);


/*----------------------------------------------------------------------------
 * GlobalControl97_Init
 *
 * This function performs the initialization of the EIP-97 Global Control
 * functionality.
 *
 * fHWResetDone (input)
 *     Flag indicates whether the HW Reset operation was performed
 *     for the SafeXcel-IP-97 hardware before calling this function
 *
 * This function is not re-entrant.
 *
 * Return value
 *     GLOBAL_CONTROL_NO_ERROR : initialization performed successfully
 *     GLOBAL_CONTROL_ERROR_INTERNAL : initialization failed
 *     GLOBAL_CONTROL_ERROR_BAD_USE_ORDER : initialization is already done
 */
GlobalControl97_Error_t
GlobalControl97_Init(
        const bool fHWResetDone);


/*----------------------------------------------------------------------------
 * GlobalControl97_UnInit
 *
 * This function performs the initialization of the EIP-97 Global Control
 * functionality.
 *
 * This function is not re-entrant.
 *
 * Return value
 *     GLOBAL_CONTROL_NO_ERROR : un-initialization performed successfully
 *     GLOBAL_CONTROL_ERROR_INTERNAL : un-initialization failed
 *     GLOBAL_CONTROL_ERROR_BAD_USE_ORDER : un-initialization is already done
 */
GlobalControl97_Error_t
GlobalControl97_UnInit(void);


/*----------------------------------------------------------------------------
 * GlobalControl97_Configure
 *
 * This function performs the Ring to PE assignment and configures
 * the Ring priority. The EIP-97 device supports multiple Ring interfaces
 * as well as multiple PE's. One ring can be assigned to the same or different
 * PE's. Multiple rings can be assigned to the same PE.
 *
 * PE_Number (input)
 *     Number of the EIP-97 Processing Engine for which the status information
 *     must be retrieved
 *
 * RingPEMap_p (input)
 *     Pointer to the data structure that contains the Ring PE assignment map.
 *
 * This function is not re-entrant.
 *
 * Return value
 *     GLOBAL_CONTROL_NO_ERROR : PE configured successfully
 *     GLOBAL_CONTROL_ERROR_INTERNAL : operation failed
 *     GLOBAL_CONTROL_ERROR_BAD_PARAMETER : invalid parameter
 */
GlobalControl97_Error_t
GlobalControl97_Configure(
        const unsigned int PE_Number,
        const GlobalControl97_Ring_PE_Map_t * const RingPEMap_p);



#endif /* API_GLOBAL_EIP97_H_ */


/* end of file api_global_eip97.h */

