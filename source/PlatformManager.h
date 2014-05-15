#ifndef __PLATFORMMANAGER_H__
#define __PLATFORMMANAGER_H__

#include "cocos2d.h"
using namespace cocos2d;

class PlatformManager
{
	bool AdEnable;
public:
	PlatformManager();
	~PlatformManager();
	bool isInterShow;
	//const char* WallPoints;
	//Returns shared instance of this class
	static PlatformManager* sharedInstance();

	//Releases shared instance of this calss
	void releaseInstance();

	//Inits Domob system
	void initDomobSystem();
	void initInAppSystem();
	void releaseDomobSystem();
	void releaseInAppSystem();
	void showBanner();
	void showSpalsh();
	void showInter();
	void getIntoWall();
	void checkWallPoints();
	void consumeWallPoints(int p);

};
#endif // __PLATFORMMANAGER_H__