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
    CCPoint ccp_last,ccp_now;       //��¼��ʼ����ǰ����

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

	virtual void onEnter();
    virtual void onExit();

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
};

#endif // __GameScene_H__

