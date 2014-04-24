#include "ThemeManager.h"

static ThemeManager * sInstance = NULL;

ThemeManager::~ThemeManager()
{
}

ThemeManager::ThemeManager(){
	type=themeCandy;
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
	std::string fName = "images/" ;
	fName.append(getPath());
	fName.append(imageName);
	CCSprite* sprite = CCSprite::spriteWithFile(fName.c_str());

	return sprite;
}

const char* ThemeManager::getFontName() {
	switch (type)
	{
	case themePlain:
		return "arial";
	case themeCandy:
		return "candy";
	default:
		//sprintf(buff,"themePlain/");
		break;
	}
	return "arial";
}
const char* ThemeManager::getPath(){
	char buff[16];
	*buff = 0;

	switch (type)
	{
	case themePlain:
		sprintf(buff,"themePlain/");
		break;
	case themeCandy:
		sprintf(buff,"themeCandy/");
		break;
	default:
		sprintf(buff,"themePlain/");
		break;
	}
	return buff;
}
ccColor3B ThemeManager::getColor(){
	switch (type)
	{
	case themePlain:
		return ccc3(0xFF,0xFF,0xFF);
	case themeCandy:
		return ccc3(0x0F,0x49,0xCC);
	default:
		//sprintf(buff,"themePlain/");
		break;
	}
	return ccc3(0xFF,0xFF,0xFF);
}
int ThemeManager::getTheme(){
	return type;
}
