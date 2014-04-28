#include "AdModule.h"

static AdModule * g_pInstance = NULL;

AdModule* AdModule::sharedInstance()
{
	if (g_pInstance)
		return g_pInstance;
	else {
		g_pInstance = new AdModule();
		g_pInstance->init();
		return g_pInstance;
	}
}

void AdModule::releaseInstance()
{
	if (g_pInstance!=NULL)
		delete g_pInstance;
}


bool AdModule::init()
{
	return true;
}

float AdModule::getAdHeight()
{
	return CCDirector::sharedDirector()->getWinSize().height/10;
}

void AdModule::showAdPopup()
{
}


bool AdModule::showCrossRef( CrossReferencePlace ePlace )
{
	return false;
}

float AdModule::getBannerHeight()
{
	return 0;
}

float AdModule::getBannerWidth()
{
	return 0;
}

void AdModule::setBannerPosition( CCPoint tPoint )
{

}

void AdModule::setBannerSize( CCPoint tPoint )
{

}

bool AdModule::popupSupported()
{
	return false;
}
