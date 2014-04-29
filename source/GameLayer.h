#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#define LL_SCREEN_SCALE_VALUE (CCDirector::sharedDirector()->getWinSize().height/1024)
#define LL_BUTTON_SCALE_VALUE (0.6*LL_SCREEN_SCALE_VALUE)

#include "cocos2d.h"
using namespace cocos2d;
class GameLayer : public cocos2d::CCLayer
{
protected:
    bool bPaused;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

public:
    ~GameLayer();
    
    // Init method
    virtual bool init();

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
    

	void instructionButtonClick(CCObject *sender);
	void startButtonClick(CCObject *sender);
	void finishButtonClick(CCObject *sender);
	void cancelButtonClick(CCObject *sender);
	void leaderboardButtonClick(CCObject *sender);
	void themeButtonClick(CCObject *sender);
	void theme1useButtonClick(CCObject *sender);
	void theme2useButtonClick(CCObject *sender);
};

#endif // __GAMELAYER_H__

