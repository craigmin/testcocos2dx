
#include "LeaderBoard.h"
#include "GameLayer.h"
#include "Lihui2048Api.h"
#include "LihuiLB.h"
#include "ThemeManager.h"

LeaderBoard::~LeaderBoard()
{
}

CCScene* LeaderBoard::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	LeaderBoard *layer = LeaderBoard::create();

	// Add layer as a child to scene
	scene->addChild(layer);

	// Return the scene
	return scene;
}
bool LeaderBoard::init()
{

	if (!CCLayer::init())
		return false;
	
	//float iMenuWidthOffset = 0.55;
	SCREEN_WIDTH = CCDirector::sharedDirector()->getWinSize().width;
	SCREEN_HEIGHT = CCDirector::sharedDirector()->getWinSize().height;


	CCSprite* bgsprite =ThemeManager::sharedInstance()->spriteWithImageFile("leaderboard.png");
	bgsprite->setScaleX(SCREEN_WIDTH/bgsprite->getContentSize().width);
	bgsprite->setScaleY(SCREEN_HEIGHT/bgsprite->getContentSize().height);
	bgsprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(bgsprite,1);

	CCSprite* updateNicknamelb =ThemeManager::sharedInstance()->spriteWithImageFile("btn_update_nickname.png");
	CCSprite* updateNicknameSelectedlb =ThemeManager::sharedInstance()->spriteWithImageFile("btn_update_nickname.png");
	updateNicknameSelectedlb->setScale(1.1);
	CCMenuItemSprite* pupdateNicknameItemSpritelb = CCMenuItemSprite::itemWithNormalSprite(updateNicknamelb, updateNicknameSelectedlb, this, menu_selector(LeaderBoard::updateNicknameClick));
	pupdateNicknameItemSpritelb->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pupdateNicknameMenu = CCMenu::menuWithItems(pupdateNicknameItemSpritelb,NULL);
	pupdateNicknameMenu->setPosition(ccp(SCREEN_WIDTH*0.3, SCREEN_HEIGHT*0.15));

	this->addChild(pupdateNicknameMenu, 3);	


	CCSprite* back2menuNormallb =ThemeManager::sharedInstance()->spriteWithImageFile("back2menu.png");
	CCSprite* back2menuSelectedlb =ThemeManager::sharedInstance()->spriteWithImageFile("back2menu.png");
	back2menuSelectedlb->setScale(1.1);

	CCMenuItemSprite* pback2menuItemSpritelb = CCMenuItemSprite::itemWithNormalSprite(back2menuNormallb, back2menuSelectedlb, this, menu_selector(LeaderBoard::back2menuClick));
	pback2menuItemSpritelb->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pback2menuMenu = CCMenu::menuWithItems(pback2menuItemSpritelb,NULL);
	pback2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.7, SCREEN_HEIGHT*0.15));

	this->addChild(pback2menuMenu, 3);

	CCLayer *bg = CCLayer::create();  
    bg->setContentSize(CCSizeMake(SCREEN_WIDTH,SCREEN_HEIGHT*0.58));  
    bg->setAnchorPoint(ccp(0,0));  
    bg->setPosition(ccp(0,0));  

	char buff[16];
	*buff = 0;

	for(int i=0;i<10;i++){
		int offsetHeight = SCREEN_HEIGHT*(0.63125-0.0583*i-0.08);

		sprintf(buff,"%d ",i+1);
		scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(300*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
		scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.43,offsetHeight));
		scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
		bg->addChild(scoreLabel, 4);

		scoreLabel=CCLabelTTF::labelWithString(getNicknameByRank(i+1),CCSizeMake(300*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
		scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.50,offsetHeight));
		scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
		bg->addChild(scoreLabel, 4);

		sprintf(buff,"%d ",getScore(i+1));
		scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(150*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentRight,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
		scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.78,offsetHeight));
		scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
		bg->addChild(scoreLabel, 4);
	}

    CCScrollView * view = CCScrollView::create(CCSizeMake(SCREEN_WIDTH,SCREEN_HEIGHT*0.35), bg);
    view->setDirection(kCCScrollViewDirectionVertical);  
	view->setContentSize( CCSizeMake(SCREEN_WIDTH,SCREEN_HEIGHT*0.58) );
	view->setContentOffset(ccp(0,-SCREEN_HEIGHT*0.226));
    view->setAnchorPoint(ccp(0,0));  
    view->setPosition(0,SCREEN_HEIGHT*0.305);  
    this->addChild(view,4);  


	sprintf(buff,"%d ",getBestScore());
	scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(150*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentRight,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.78,SCREEN_HEIGHT*(0.62725-0.0583*6)));
	scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(scoreLabel, 4);

	scoreLabel=CCLabelTTF::labelWithString(getNickname(),CCSizeMake(300*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.51,SCREEN_HEIGHT*(0.62725-0.0583*6)));
	scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(scoreLabel, 4);

	/*char buff2[256];
	*buff2 = 0;
	sprintf(buff2,"%d %s",getUserRank(), getNickname());
	scoreLabel=CCLabelTTF::labelWithString(buff2,CCSizeMake(330*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.43,SCREEN_HEIGHT*(0.63125-0.0583*7)));
	scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(scoreLabel, 4);*/

	return true;
}

bool bScheduled = false;
void LeaderBoard::back2menuClick(CCObject *sender){
	this->unscheduleAllSelectors();
	bScheduled = false;
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::transitionWithDuration(0.5f,  GameLayer::scene()));
}

void LeaderBoard::updateNicknameClick(CCObject *sender){
	updateNickname(NULL);
	if(!bScheduled) {
		this->schedule(schedule_selector(LeaderBoard::update), 2, kCCRepeatForever, 0);
		bScheduled = true;
	}
}

void LeaderBoard::update(float dt)
{
	if(scoreLabel){
		/*char buff2[256];
		*buff2 = 0;
		sprintf(buff2,"%d %s",getUserRank(), getNickname());*/
		scoreLabel->setString(getNickname());
	}
}