/*
Generic implementation of the LihuiAD_Baidu extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "LihuiAD_Baidu_internal.h"
s3eResult LihuiAD_BaiduInit()
{
    //Add any generic initialisation code here
    return LihuiAD_BaiduInit_platform();
}

void LihuiAD_BaiduTerminate()
{
    //Add any generic termination code here
    LihuiAD_BaiduTerminate_platform();
}

void InitBdAd()
{
	InitBdAd_platform();
}

void SetBdAdPosition(int opt)
{
	SetBdAdPosition_platform(opt);
}

int GetBdAdHeight()
{
	return GetBdAdHeight_platform();
}

void showBdInter()
{
	showBdInter_platform();
}
