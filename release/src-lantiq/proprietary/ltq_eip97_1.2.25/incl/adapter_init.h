/* adapter_init.h
 *
 * Data types and Interfaces
 */

/*****************************************************************************
* Copyright (c) 2008-2013 INSIDE Secure B.V. All Rights Reserved.
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

#ifndef INCLUDE_GUARD_ADAPTER_INIT_H
#define INCLUDE_GUARD_ADAPTER_INIT_H

#include "basic_defs.h"

/*----------------------------------------------------------------------------
 *                           Adapter initialization
 *----------------------------------------------------------------------------
 */

bool
Adapter_Init(struct platform_device *pdev);

void
Adapter_UnInit(void);

void
Adapter_Report_Build_Params(void);

#endif /* Include Guard */

/* end of file adapter_init.h */
