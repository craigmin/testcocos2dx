/*
Generic implementation of the LihuiDomob extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "LihuiDomob_internal.h"
s3eResult LihuiDomobInit()
{
    //Add any generic initialisation code here
    return LihuiDomobInit_platform();
}

void LihuiDomobTerminate()
{
    //Add any generic termination code here
    LihuiDomobTerminate_platform();
}

void initDoAd()
{
	initDoAd_platform();
}

void showDoBanner()
{
	showDoBanner_platform();
}

void showDoInter()
{
	showDoInter_platform();
}

void showDoSplash()
{
	showDoSplash_platform();
}

void checkPoints()
{
	checkPoints_platform();
}

void usePoints(int point)
{
	usePoints_platform(point);
}

void getPoints()
{
	getPoints_platform();
}
