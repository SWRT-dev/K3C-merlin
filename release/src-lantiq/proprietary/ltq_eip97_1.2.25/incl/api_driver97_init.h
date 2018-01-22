/* api_driver97_init.h
 *
 * SafeXcel-IP-97 Driver Initialization Interface
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

#ifndef DRIVER97_INIT_H_
#define DRIVER97_INIT_H_


/*----------------------------------------------------------------------------
 * Driver97_Init
 *
 * Initialize the driver. This function must be called before any other
 * driver API function can be called.
 *
 * Returns 0 for success and -1 for failure.
 */
int
Driver97_Init(struct platform_device *pdev);

/*----------------------------------------------------------------------------
 * Driver97_Exit
 *
 * Initialize the driver. After this function is called no other driver API
 * function can be called except Driver97_Init().
 */
void
Driver97_Exit(void);


#endif /* DRIVER97_INIT_H_ */


/* end of file api_driver97_init.h */
