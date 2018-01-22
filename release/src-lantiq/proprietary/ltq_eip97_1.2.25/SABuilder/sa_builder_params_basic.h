/* sa_builder_params_basic.h
 *
 * Basic crypto and hash specific extension to the SABuilder_Params_t type.
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
* In case you do not have an account for this system, please send an e-mail
* to ESSEmbeddedHW-Support@insidesecure.com.
*****************************************************************************/


#ifndef SA_BUILDER_PARAMS_BASIC_H_
#define SA_BUILDER_PARAMS_BASIC_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

#include "sa_builder_params.h"

// Driver Framework Basic Definitions API
#include "basic_defs.h"


/*----------------------------------------------------------------------------
 * Definitions and macros
 */


/* Flag bits for the BasicFlags field. Combine any values using a
   bitwise or.
 */
#define SAB_BASIC_FLAG_EXTRACT_ICV   BIT_0 /* Extract and verify ICV from packet*/


/* Extension record for SAParams_t. Protocol_Extension_p must point
   to this structure when the Basic crypto/hash protocol is used.

   SABuilder_Iinit_Basic() will fill all fields in this structure  with
   sensible defaults.
 */
typedef struct
{
    uint32_t BasicFlags;
    uint32_t DigestBlockCount;
    uint32_t ICVByteCount; /* Length of ICV in bytes. */
} SABuilder_Params_Basic_t;


#endif /* SA_BUILDER_PARAMS_BASIC_H_ */


/* end of file sa_builder_params_basic.h */
