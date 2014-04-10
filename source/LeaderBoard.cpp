
#include "LeaderBoard.h"
#include "GameLayer.h"
#include "Lihui2048Api.h"
#include "LihuiLB.h"

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
	

	CCSprite* bgsprite = CCSprite::spriteWithFile("images/leaderboard.png");
	bgsprite->setScaleX(SCREEN_WIDTH/bgsprite->getContentSize().width);
	bgsprite->setScaleY(SCREEN_HEIGHT/bgsprite->getContentSize().height);
	bgsprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(bgsprite,1);


	CCSprite* back2menuNormallb = CCSprite::spriteWithFile("images/back2menu.png");
    CCSprite* back2menuSelectedlb = CCSprite::spriteWithFile("images/back2menu.png");
    CCSprite* back2menuDisabledlb = CCSprite::spriteWithFile("images/back2menu.png");

    CCMenuItemSprite* pback2menuItemSpritelb = CCMenuItemSprite::itemWithNormalSprite(back2menuNormallb, back2menuSelectedlb, back2menuDisabledlb, this, menu_selector(LeaderBoard::back2menuClick));
    pback2menuItemSpritelb->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pback2menuMenu = CCMenu::menuWithItems(pback2menuItemSpritelb,NULL);
    pback2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.15));
	 
    this->addChild(pback2menuMenu, 3);	

	char buff[16];
	*buff = 0;
	
	for(int i=0;i<6;i++){
		sprintf(buff,"%d ",getScore(i+1));
	scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(150*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentRight,kCCVerticalTextAlignmentCenter,"arial",36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.62,SCREEN_HEIGHT*(0.63125-0.0583*i)));
	scoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(scoreLabel, 4);
	}
	sprintf(buff,"%d ",getBestScore());
	scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(150*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentRight,kCCVerticalTextAlignmentCenter,"arial",36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.62,SCREEN_HEIGHT*(0.63125-0.0583*6)));
	scoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(scoreLabel, 4);
	/*
	scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(150*LL_SCREEN_SCALE_VALUE,32), kCCTextAlignmentRight,kCCVerticalTextAlignmentCenter,"arial",36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.62,SCREEN_HEIGHT*(0.63125-0.0583)));
	scoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(scoreLabel, 4);


	scoreLabel=CCLabelTTF::labelWithString("100000", "arial",36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.78,SCREEN_HEIGHT*0.63125));
	scoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	scoreLabel->setHorizontalAlignment(kCCTextAlignmentRight);
	this->addChild(scoreLabel, 4);

	scoreLabel=CCLabelTTF::labelWithString("10000", "arial",36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.78,SCREEN_HEIGHT*(0.63125-0.0583)));
	scoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	scoreLabel->setHorizontalAlignment(kCCTextAlignmentRight);
	this->addChild(scoreLabel, 4);
	*/
	return true;
}
void LeaderBoard::back2menuClick(CCObject *sender){
	
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::transitionWithDuration(0.5f,  GameLayer::scene()));
}
