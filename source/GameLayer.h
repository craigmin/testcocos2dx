#ifndef __GAMELAYER_H__
#define __GAMELAYER_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"

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

	// Draw method
	virtual void draw();

	// Main update loop
	void update(float dt);

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameLayer);
    

	void instructionButtonClick(CCObject *sender);
	void startButtonClick(CCObject *sender);
	void finishButtonClick(CCObject *sender);
	void cancelButtonClick(CCObject *sender);
	void leaderboardButtonClick(CCObject *sender);
};

#endif // __GAMELAYER_H__

