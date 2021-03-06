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
	CCLabelTTF* bombLabel;
	CCLabelTTF* rearrangeLabel;
	CCLabelTTF* pointLabel;
	CCMenuItemSprite *psoundmenuItemSprite;
	CCMenuItemSprite*  pbombmenuItemSprite; 
	CCMenuItemSprite*  prearrangemenuItemSprite;
	//CCSprite* rect[16];
	bool bGameOver;
	bool bMovable;
    CCPoint ccp_last,ccp_now;       //记录起始、当前坐标
	int coodinates_last[4][4], coodinates_now[4][4];
	bool bValueZero[4][4];
	bool bPaused;
	bool bInMoving;
	bool soundState;
	bool bClean;
	bool bCConfrim;
	bool bInMovable;
	int topTileScore;
	float widoffset;
	float heioffset;
	int cleanX;
	int cleanY;
	int empty;
	int bombsUsed;
	int ResUsed;
typedef enum
{
    RESTART,
    BACK2MENU,
    USEBOMB,
	USEREARRANGE,
	BUYBOMB,
	BUYREARRANGE,
	INMOVABLE,
	SHOP
} pausetype;

public:
    ~GameScene();
    
	static GameScene* sharedInstance();
    // Init method
    virtual bool init();

    // Create instance of scene
    static CCScene* scene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameScene);
    
	void drawMatrix(float dt = 0.0);
	void restartClick(CCObject *sender);	
	void back2menuClick(CCObject *sender);
	void animCallback(CCNode *sender);
	void fadeOutCallback(CCNode *sender);		
	void drawScore();
	void inMovable();
	void drawProperty();
	void drawWallPoints(const char* p);
	void moveMatrix(int moveDir);
	void gameOver();
	void animateMatrix(int moveDir);
	int* trackMovementPath(const int before[],const int after[], bool b);
	void pauseGame(pausetype Type);
	void shareButtonClick(CCObject *sender);
	void cancelButtonClick(CCObject *sender);
	void restartConfirmButtonClick(CCObject *sender);
	void backConfirmButtonClick(CCObject *sender);
	void soundButtonClick(CCObject *sender);
	void cleancancleClick(CCObject *sender);
	void bombButtonClick(CCObject *sender);
	void rearrangeButtonClick(CCObject *sender);
	void cleanConfirmButtonClick(CCObject *sender);
	void rearrangeConfirmButtonClick(CCObject *sender);
	void buyBombButtonClick(CCObject *sender);
	void buyRearrangeButtonClick(CCObject *sender);
	void gameoverButtonClick(CCObject *sender);
	void shopButtonClick(CCObject *sender);
	void buygiftButtonClick(CCObject *sender);
	void buy3bombsButtonClick(CCObject *sender);
	void buy5bombsButtonClick(CCObject *sender);
	void buy10bombsButtonClick(CCObject *sender);
	void buy1ReButtonClick(CCObject *sender);
	void buy2ResButtonClick(CCObject *sender);
	void buy5ResButtonClick(CCObject *sender);
	void getPointClick(CCObject *sender);
	void bombConsumeClick(CCObject *sender);
	void rearrangeConsumeClick(CCObject *sender);
	
	void processPurchase(const char* p);
	void cleanPoint(float x,float y);
	void updateCoodinates();
	void cleanPointConfirm(int x,int y);
	
	void Taskfinish(); 
	void ShowRunOut(int type); 
	void update(CCNode *sender);

	virtual void onEnter();
    virtual void onExit();

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
};

#endif // __GameScene_H__

