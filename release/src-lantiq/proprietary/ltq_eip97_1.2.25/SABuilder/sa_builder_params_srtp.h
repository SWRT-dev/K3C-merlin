/* sa_builder_params_srtp.h
 *
 * SRTP specific extension to the SABuilder_Params_t type.
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


#ifndef SA_BUILDER_PARAMS_SRTP_H_
#define SA_BUILDER_PARAMS_SRTP_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

#include "sa_builder_params.h"

// Driver Framework Basic Definitions API
#include "basic_defs.h"



/*----------------------------------------------------------------------------
 * Definitions and macros
 */

/* Flag values for te SRTPFlags field */
#define SAB_SRTP_FLAG_SRTCP          BIT_0
#define SAB_SRTP_FLAG_INCLUDE_MKI    BIT_1


/* Extension record for SAParams_t. Protocol_Extension_p must point
   to this structure when the SRTP protocol is used.

   SABuilder_Iinit_SRTP() will fill all fields in this structure  with
   sensible defaults.
 */
typedef struct
{
    uint32_t SRTPFlags;
    uint32_t MKI;
    uint32_t ICVByteCount; /* Length of ICV in bytes. */
} SABuilder_Params_SRTP_t;


#endif /* SA_BUILDER_PARAMS_SRTP_H_ */


/* end of file sa_builder_params_srtp.h */
