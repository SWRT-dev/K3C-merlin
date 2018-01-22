/* adapter_sleep.c
 *
 * Linux kernel specific Adapter module
 * responsible for adapter-wide time management.
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

#include "adapter_sleep.h"

#include "basic_defs.h"

// Linux Kernel API
#include <linux/delay.h>        // msleep, no-busy-waiting implementation


/*----------------------------------------------------------------------------
 * Adapter_SleepMS
 */
void
Adapter_SleepMS(
        const unsigned int Duration_ms)
{
    msleep(Duration_ms);
}


/* end of file adapter_sleep.c */
