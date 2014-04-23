#ifndef __ThemeManager_H__
#define __ThemeManager_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"

using namespace cocos2d;

typedef enum {
	themePlain,
	themeCandy
} THEME_2048;

class ThemeManager
{
protected:
	int type;

public:
    ~ThemeManager();
    ThemeManager();
	static ThemeManager* sharedInstance();

	void setTheme(int type);
	CCSprite* spriteWithImageFile(const char* imageName);
	const char* getFontName();
};

#endif // __ThemeManager_H__
