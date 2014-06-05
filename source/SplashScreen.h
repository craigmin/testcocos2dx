#ifndef __SplashScreen_H__
#define __SplashScreen_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"

using namespace cocos2d;

class SplashScreen : public cocos2d::CCLayer
{
protected:
   
public:
    ~SplashScreen();
    
    // Init method
    virtual bool init();

	// Main update loop
	void update(float dt);

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(SplashScreen);
    
	const char* getSplashImage();
	CCScene* nextLayer();
};

#endif // __SplashScreen_H__

