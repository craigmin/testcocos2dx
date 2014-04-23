#ifndef __LeaderBoard_H__
#define __LeaderBoard_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"

using namespace cocos2d;

class LeaderBoard : public cocos2d::CCLayer
{
protected:
    int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	CCLabelTTF* scoreLabel;
public:
    ~LeaderBoard();
    
    // Init method
    virtual bool init();

	// Main update loop
	//void update(float dt);

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(LeaderBoard);

    void back2menuClick(CCObject *sender);
	void updateNicknameClick(CCObject *sender);
	void update(float dt);
};

#endif // __LeaderBoard_H__
