/* adapter_dmabuf.h
 *
 * Adapter DMABuf internal interface
 */

/*****************************************************************************
* Copyright (c) 2010-2013 INSIDE Secure B.V. All Rights Reserved.
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

#ifndef ADAPTER_DMABUF_H_
#define ADAPTER_DMABUF_H_


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Driver Framework Basic Definitions API
#include "basic_defs.h"            // bool

// Driver Framework DMAResource API
#include "dmares_types.h"          // DMAResource_Handle_t

// DMABuf API
#include "api_dmabuf.h"            // DMABuf_Handle_t

/*----------------------------------------------------------------------------
 * Function name
 *
 */
DMAResource_Handle_t
Adapter_DMABuf_Handle2DMAResourceHandle(
        DMABuf_Handle_t Handle);

DMABuf_Handle_t
Adapter_DMAResource_Handle2DMABufHandle(
        DMAResource_Handle_t Handle);

void *
Adapter_DMAResource_HostAddr(
        DMAResource_Handle_t Handle);

bool
Adapter_DMAResource_IsSubRangeOf(
        const DMAResource_Handle_t Handle1,
        const DMAResource_Handle_t Handle2);

bool
Adapter_DMAResource_IsForeignAllocated(
        DMAResource_Handle_t Handle);


#endif /* ADAPTER_DMABUF_H_ */

/* end of file adapter_dmabuf.h */
