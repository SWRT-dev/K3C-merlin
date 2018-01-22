/* adapter_sleep.h
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

#ifndef INCLUDE_GUARD_ADAPTER_SLEEP_H
#define INCLUDE_GUARD_ADAPTER_SLEEP_H

#include "basic_defs.h"

/*----------------------------------------------------------------------------
 *                           Adapter time management
 *----------------------------------------------------------------------------
 */

/*----------------------------------------------------------------------------
 * Adapter_SleepMS
 *
 * This function will sleep the calling context for at most the requested
 * amount of time (milliseconds) and then returns.
 *
 */
void
Adapter_SleepMS(
        const unsigned int Duration_ms);

#endif /* Include Guard */

/* end of file adapter_sleep.h */
