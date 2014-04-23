#include "ThemeManager.h"

static ThemeManager * sInstance = NULL;

ThemeManager::~ThemeManager()
{
}

ThemeManager::ThemeManager(){
}

ThemeManager* ThemeManager::sharedInstance()
{
	if (sInstance)
		return sInstance;
	else {
		sInstance = new ThemeManager();
		return sInstance;
	}
}

void ThemeManager::setTheme(int type){
	ThemeManager::type=type;
}

CCSprite* ThemeManager::spriteWithImageFile(const char* imageName){
	std::string fName = imageName;
	fName = "images/" + fName;
	CCSprite* sprite = CCSprite::spriteWithFile(fName.c_str());

	return sprite;
}

const char* ThemeManager::getFontName() {
	return "arial";
}
