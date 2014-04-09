/*
Generic implementation of the LihuiLB extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "LihuiLB_internal.h"
s3eResult LihuiLBInit()
{
    //Add any generic initialisation code here
    return LihuiLBInit_platform();
}

void LihuiLBTerminate()
{
    //Add any generic termination code here
    LihuiLBTerminate_platform();
}

void initLB()
{
	initLB_platform();
}

void updateScore(int score)
{
	updateScore_platform(score);
}

void receiveRank()
{
	receiveRank_platform();
}

int getScore(int rank)
{
	return getScore_platform(rank);
}

int getUserRank()
{
	return getUserRank_platform();
}

int getNextWeekLeftSeconds()
{
	return getNextWeekLeftSeconds_platform();
}

bool notUnlimetedLives()
{
	return notUnlimetedLives_platform();
}

void setBeijingTime()
{
	setBeijingTime_platform();
}

bool notShared()
{
	return notShared_platform();
}

void setShareTime()
{
	setShareTime_platform();
}
