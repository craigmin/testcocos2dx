#include "PlatformManager.h"
#include "LihuiDomob.h"
#include "GameScene.h"
#include "GameLayer.h"
#include "LihuiMMInApp.h"
//#include "Lihui2048Api.h"
static PlatformManager * sInstance = NULL;
PlatformManager::PlatformManager()
{
	AdEnable=false;
	//itemRequestInProgress = false;
}

PlatformManager::~PlatformManager()
{

}
PlatformManager* PlatformManager::sharedInstance()
{
	if (sInstance)
		return sInstance;
	else {
		sInstance = new PlatformManager();
		return sInstance;
	}
}

void PlatformManager::releaseInstance()
{
	if (sInstance!=NULL)
		delete sInstance;
}
int32 LihuiSplashSuccessCallback(void* system, void* user)
{

	CCDirector *pDirector = CCDirector::sharedDirector();
	pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
	pDirector->setProjection(kCCDirectorProjection2D);
	CCScene *pScene = GameLayer::scene();
	pDirector->runWithScene(pScene);

	return 0;
}
int32 LihuiSplashFailedCallback(void* system, void* user)
{
	//LeaderBoard UpdateFailed
	return 0;
}
int32 LihuiGetPointSuccessCallback(void* system, void* user)
{
	if(GameScene::sharedInstance()){
		GameScene::sharedInstance()->drawWallPoints((const char*) system);
	}
	return 0;
}
int32 LihuiGetPointFailedCallback(void* system, void* user)
{
		return 0;
}
int32 LihuiConsumeSuccessCallback(void* system, void* user)
{
		if(GameScene::sharedInstance()){
		GameScene::sharedInstance()->processPurchase((const char*) system);
	}
	return 0;
}
int32 LihuiConsumeFailedCallback(void* system, void* user)
{
		return 0;

}
int32 LihuiSuccessCallback(void* system, void* user)
{
	if(GameScene::sharedInstance()){
		GameScene::sharedInstance()->processPurchase((const char*) system);
	}
	return 0;
}

int32 LihuiFailedCallback(void* system, void* user)
{
	//PlatformTools::sharedInstance()->finishRequest();
	return 0;
}

int32 LihuiRestoredCallback(void* system, void* user)
{
	//DataManager::sharedInstance()->processPurchase((const char*) system);
	return 0;
}

int32 LihuiRevokedCallback(void* system, void* user)
{
	//DataManager::sharedInstance()->processCancelledPurchase((const char*) system);
	return 0;
}
void PlatformManager::initInAppSystem()
{
	LihuiMMInAppRegister(LIHUIMMINAPP_CALLBACK_PURCHASE_SUCCESSFUL,&LihuiSuccessCallback,NULL);
	LihuiMMInAppRegister(LIHUIMMINAPP_CALLBACK_PURCHASE_FAILED,&LihuiFailedCallback,NULL);
	LihuiMMInAppRegister(LIHUIMMINAPP_CALLBACK_PURCHASE_RESTORED,&LihuiRestoredCallback,NULL);
	LihuiMMInAppRegister(LIHUIMMINAPP_CALLBACK_PURCHASE_REVOKED,&LihuiRevokedCallback,NULL);
	//Jerry--Clean
		LihuiInAppStart();
}
void PlatformManager::releaseInAppSystem()
{
	LihuiMMInAppUnRegister(LIHUIMMINAPP_CALLBACK_PURCHASE_SUCCESSFUL,&LihuiSuccessCallback);
	LihuiMMInAppUnRegister(LIHUIMMINAPP_CALLBACK_PURCHASE_FAILED,&LihuiFailedCallback);
	LihuiMMInAppUnRegister(LIHUIMMINAPP_CALLBACK_PURCHASE_RESTORED,&LihuiRestoredCallback);
	LihuiMMInAppUnRegister(LIHUIMMINAPP_CALLBACK_PURCHASE_REVOKED,&LihuiRevokedCallback);
}
void PlatformManager::initDomobSystem()
{
	if(AdEnable){
		isInterShow=true;
		initDoAd();
		LihuiDomobRegister(LIHUIDO_CALLBACK_SPLASH_SUCCESSFUL,&LihuiSplashSuccessCallback,NULL);
		LihuiDomobRegister(LIHUIDO_CALLBACK_SPLASH_FAILED,&LihuiSplashFailedCallback,NULL);
		LihuiDomobRegister(LIHUIDO_CALLBACK_POINT_SUCCESSFUL,&LihuiGetPointSuccessCallback,NULL);
		LihuiDomobRegister(LIHUIDO_CALLBACK_POINT_FAILED,&LihuiGetPointFailedCallback,NULL);
		LihuiDomobRegister(LIHUIDO_CALLBACK_CONSUME_SUCCESSFUL,&LihuiConsumeSuccessCallback,NULL);
		LihuiDomobRegister(LIHUIDO_CALLBACK_CONSUME_FAILED,&LihuiConsumeFailedCallback,NULL);
	}
}
void PlatformManager::releaseDomobSystem()
{
	if(AdEnable){
		LihuiDomobUnRegister(LIHUIDO_CALLBACK_SPLASH_SUCCESSFUL,&LihuiSplashSuccessCallback);
		LihuiDomobUnRegister(LIHUIDO_CALLBACK_SPLASH_FAILED,&LihuiSplashFailedCallback);
		LihuiDomobUnRegister(LIHUIDO_CALLBACK_POINT_SUCCESSFUL,&LihuiGetPointSuccessCallback);
		LihuiDomobUnRegister(LIHUIDO_CALLBACK_POINT_FAILED,&LihuiGetPointFailedCallback);
		LihuiDomobUnRegister(LIHUIDO_CALLBACK_CONSUME_SUCCESSFUL,&LihuiConsumeSuccessCallback);
		LihuiDomobUnRegister(LIHUIDO_CALLBACK_CONSUME_FAILED,&LihuiConsumeFailedCallback);
	}
}

void PlatformManager::showBanner()
{
	if(AdEnable){
		showDoBanner();
	}
}
void PlatformManager::showSpalsh()
{
	if(AdEnable){
		showDoSplash();
	}
}
void PlatformManager::showInter()
{
	isInterShow=!isInterShow;
	if(AdEnable&&isInterShow){
		showDoInter();
	}

}
void PlatformManager::getIntoWall()
{
	if(AdEnable){
		getPoints();
	}

}
void PlatformManager::checkWallPoints()
{
	if(AdEnable){
		checkPoints();
	}

}
void PlatformManager::consumeWallPoints(int p)
{
	if(AdEnable){
		usePoints(p);
	}

}


