/*
Generic implementation of the LihuiMMInApp extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "LihuiMMInApp_internal.h"
s3eResult LihuiMMInAppInit()
{
    //Add any generic initialisation code here
    return LihuiMMInAppInit_platform();
}

void LihuiMMInAppTerminate()
{
    //Add any generic termination code here
    LihuiMMInAppTerminate_platform();
}

void LihuiInAppStart()
{
	LihuiInAppStart_platform();
}

void LihuiInAppRestorePurchases()
{
	LihuiInAppRestorePurchases_platform();
}

void LihuiInAppBuyItem(const char* itemId)
{
	LihuiInAppBuyItem_platform(itemId);
}
