
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
	CCSprite* updateNicknameDisabledlb =ThemeManager::sharedInstance()->spriteWithImageFile("btn_update_nickname.png");

	CCMenuItemSprite* pupdateNicknameItemSpritelb = CCMenuItemSprite::itemWithNormalSprite(updateNicknamelb, updateNicknameSelectedlb, updateNicknameDisabledlb, this, menu_selector(LeaderBoard::updateNicknameClick));
	pupdateNicknameItemSpritelb->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pupdateNicknameMenu = CCMenu::menuWithItems(pupdateNicknameItemSpritelb,NULL);
	pupdateNicknameMenu->setPosition(ccp(SCREEN_WIDTH*0.3, SCREEN_HEIGHT*0.15));

	this->addChild(pupdateNicknameMenu, 3);	


	CCSprite* back2menuNormallb =ThemeManager::sharedInstance()->spriteWithImageFile("back2menu.png");
	CCSprite* back2menuSelectedlb =ThemeManager::sharedInstance()->spriteWithImageFile("back2menu.png");
	CCSprite* back2menuDisabledlb =ThemeManager::sharedInstance()->spriteWithImageFile("back2menu.png");

	CCMenuItemSprite* pback2menuItemSpritelb = CCMenuItemSprite::itemWithNormalSprite(back2menuNormallb, back2menuSelectedlb, back2menuDisabledlb, this, menu_selector(LeaderBoard::back2menuClick));
	pback2menuItemSpritelb->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pback2menuMenu = CCMenu::menuWithItems(pback2menuItemSpritelb,NULL);
	pback2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.7, SCREEN_HEIGHT*0.15));

	this->addChild(pback2menuMenu, 3);	

	char buff[16];
	*buff = 0;

	for(int i=0;i<10;i++){
		sprintf(buff,"%d ",i+1);
		scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(300*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
		scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.20,SCREEN_HEIGHT*(0.63125-0.0583*i)));
		scoreLabel->setColor(ccc3(0xFF,0xFF,0xFF));
		this->addChild(scoreLabel, 4);

		scoreLabel=CCLabelTTF::labelWithString(getNicknameByRank(i+1),CCSizeMake(300*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
		scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.50,SCREEN_HEIGHT*(0.63125-0.0583*i)));
		scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
		this->addChild(scoreLabel, 4);

		sprintf(buff,"%d ",getScore(i+1));
		scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(150*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentRight,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
		scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.78,SCREEN_HEIGHT*(0.63125-0.0583*i)));
		scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
		this->addChild(scoreLabel, 4);
	}

	sprintf(buff,"%d ",getScore(-1));
	scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(300*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.20,SCREEN_HEIGHT*(0.63125-0.0583*i)));
	scoreLabel->setColor(ccc3(0xFF,0xFF,0xFF));
	this->addChild(scoreLabel, 4);

	sprintf(buff,"%d ",getBestScore());
	scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(150*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentRight,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.78,SCREEN_HEIGHT*(0.62700-0.0583*6)));
	scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(scoreLabel, 4);

	scoreLabel=CCLabelTTF::labelWithString(getNickname(),CCSizeMake(300*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.52,SCREEN_HEIGHT*(0.62700-0.0583*6)));
	scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(scoreLabel, 4);

	this->schedule(schedule_selector(LeaderBoard::update), 2, kCCRepeatForever, 0);

	return true;
}

void LeaderBoard::back2menuClick(CCObject *sender){
	this->unscheduleAllSelectors();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::transitionWithDuration(0.5f,  GameLayer::scene()));
}

void LeaderBoard::updateNicknameClick(CCObject *sender){
	updateNickname(NULL);
}

void LeaderBoard::update(float dt)
{
	if(scoreLabel){
		scoreLabel->setString(getNickname());
	}
}