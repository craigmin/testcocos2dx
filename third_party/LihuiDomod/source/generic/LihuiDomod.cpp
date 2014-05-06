/*
Generic implementation of the LihuiDomod extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "LihuiDomod_internal.h"
s3eResult LihuiDomodInit()
{
    //Add any generic initialisation code here
    return LihuiDomodInit_platform();
}

void LihuiDomodTerminate()
{
    //Add any generic termination code here
    LihuiDomodTerminate_platform();
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
