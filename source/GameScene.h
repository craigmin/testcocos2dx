#ifndef __GameScene_H__
#define __GameScene_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"

using namespace cocos2d;

class GameScene : public cocos2d::CCLayer
{
protected:
    b2World*		world;		// Instance of physics world
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	CCLabelTTF* scoreLabel;
	CCLabelTTF* topScoreLabel;
	bool bMovable;
    CCPoint ccp_last,ccp_now;       //记录起始、当前坐标
	int coodinates_last[4][4], coodinates_now[4][4];

public:
    ~GameScene();
    
    // Init method
    virtual bool init();

	// Draw method
	virtual void draw();

	// Main update loop
	void update(float dt);

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameScene);
    
	void drawMatrix();
	void restartClick(CCObject *sender);	
	void back2menuClick(CCObject *sender);
	void animCallback(CCNode *sender);
	void drawScore();
	void moveMatrix(int moveDir);
	void gameOver();
	void animateMatrix(int moveDir);
	int* trackMovementPath(const int before[],const int after[], bool b);

	virtual void onEnter();
    virtual void onExit();

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
};

#endif // __GameScene_H__

