/*
Generic implementation of the LihuiSocial extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "LihuiSocial_internal.h"
s3eResult LihuiSocialInit()
{
    //Add any generic initialisation code here
    return LihuiSocialInit_platform();
}

void LihuiSocialTerminate()
{
    //Add any generic termination code here
    LihuiSocialTerminate_platform();
}

void connectToWX()
{
	connectToWX_platform();
}

void sendMessageOnWX()
{
	sendMessageOnWX_platform();
}

int isWXLoggedIn()
{
	return isWXLoggedIn_platform();
}
