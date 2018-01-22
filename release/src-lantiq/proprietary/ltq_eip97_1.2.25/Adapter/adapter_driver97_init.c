/* adapter_driver97_init.c
 *
 * Adapter top level module, SafeXcel-IP-97 driver's entry point.
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

#include <linux/platform_device.h>
/*----------------------------------------------------------------------------
 * This module implements (provides) the following interface(s):
 */

#include "api_driver97_init.h"    // Driver Init API


/*----------------------------------------------------------------------------
 * This module uses (requires) the following interface(s):
 */

// Default Adapter configuration
#include "cs_adapter.h"      // ADAPTER_DRIVER_NAME

// Adapter Initialization API
#include "adapter_init.h"   // Adapter_*
#include "adapter_global_init.h"

// Logging API
#include "log.h"            // LOG_INFO


/*----------------------------------------------------------------------------
 * Driver97_Init
 */
int
Driver97_Init(struct platform_device *pdev)
{
    LOG_INFO("\n\t Driver97_Init \n");

    LOG_INFO("%s driver: initializing\n", ADAPTER_DRIVER_NAME);

    Adapter_Report_Build_Params();

    if (!Adapter_Init(pdev))
    {
        return -1;
    }

    if (!Adapter_Global_Init())
    {
        Adapter_UnInit();
        return -1;
    }

    LOG_INFO("\n\t Driver97_Init done \n");

    return 0; 
}


/*----------------------------------------------------------------------------
 * Driver97_Exit
 */
void
Driver97_Exit(void)
{
    LOG_INFO("\n\t Driver97_Exit \n");

    LOG_INFO("%s driver: exit\n", ADAPTER_DRIVER_NAME);

    Adapter_Global_UnInit();
    Adapter_UnInit();

    LOG_INFO("\n\t Driver97_Exit done \n");
}

#include "adapter_driver97_init_ext.h"

/* end of file adapter_driver97_init.c */
