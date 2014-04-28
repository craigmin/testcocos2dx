/*
Generic implementation of the Lihui2048Api extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "Lihui2048Api_internal.h"
s3eResult Lihui2048ApiInit()
{
    //Add any generic initialisation code here
    return Lihui2048ApiInit_platform();
}

void Lihui2048ApiTerminate()
{
    //Add any generic termination code here
    Lihui2048ApiTerminate_platform();
}

bool isMovable()
{
	return isMovable_platform();
}

void move(int type)
{
	move_platform(type);
}

int getCurrentScore()
{
	return getCurrentScore_platform();
}

int getBestScore()
{
	return getBestScore_platform();
}

void reset()
{
	reset_platform();
}

bool isWin()
{
	return isWin_platform();
}

int getValue(int x, int y)
{
	return getValue_platform(x, y);
}

int getAnim(int x, int y)
{
	return getAnim_platform(x, y);
}

void cleanRect(int x, int y)
{
	cleanRect_platform(x, y);
}

void reArrange()
{
	reArrange_platform();
}

int getBombs()
{
	return getBombs_platform();
}

int getRearranges()
{
	return getRearranges_platform();
}

void addBombs(int i)
{
	addBombs_platform(i);
}

void addRearranges(int i)
{
	addRearranges_platform(i);
}

void useBombs()
{
	useBombs_platform();
}

void useRearranges()
{
	useRearranges_platform();
}

int getEmptyPoints()
{
	getEmptyPoints_platform();
}

void setFlags(const char* key, int flag)
{
	setFlags_platform(key, flag);
}

int getFlags(const char* key)
{
	getFlags_platform(key);
}
