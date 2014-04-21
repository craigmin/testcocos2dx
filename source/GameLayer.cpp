#include "SimpleAudioEngine.h"
#include "GameLayer.h"
#include "GameScene.h"
#include "LeaderBoard.h"LL_BUTTON_SCALE_VALUE
#include "Lihui2048Api.h"
#include "LihuiAD_Baidu.h"
#include "LihuiLB.h"

#define LL_SCREEN_SCALE_VALUE (CCDirector::sharedDirector()->getWinSize().height/1024)
#define LL_BUTTON_SCALE_VALUE (0.6*LL_SCREEN_SCALE_VALUE)

GameLayer::~GameLayer()
{
}

CCScene* GameLayer::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameLayer *layer = GameLayer::create();

	// Add layer as a child to scene
	scene->addChild(layer);

	// Return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameLayer::init()
{
	if (!CCLayer::init())
		return false;

	SCREEN_WIDTH = CCDirector::sharedDirector()->getWinSize().width;
	SCREEN_HEIGHT = CCDirector::sharedDirector()->getWinSize().height;
	bPaused = false;
	//Jerry--LB
	receiveRank();

	CCSprite* sprite = CCSprite::spriteWithFile("images/background.png");
	sprite->setScaleX(SCREEN_WIDTH/sprite->getContentSize().width);
	sprite->setScaleY(SCREEN_HEIGHT/sprite->getContentSize().height);
	sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(sprite,1);

	float iMenuWidthOffset = 0.55;
	CCSprite* startNormal = CCSprite::spriteWithFile("images/menu_start.png");
	CCSprite* startSelected = CCSprite::spriteWithFile("images/menu_start.png");
	CCSprite* startDisabled = CCSprite::spriteWithFile("images/menu_start.png");
	CCMenuItemSprite* pStartItemSprite = CCMenuItemSprite::itemWithNormalSprite(startNormal, startSelected, startDisabled, this, menu_selector(GameLayer::startButtonClick));

	CCMenu* pStartMenu = CCMenu::menuWithItems(pStartItemSprite,NULL);
	pStartMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.5));
	pStartItemSprite->setScale(LL_BUTTON_SCALE_VALUE);

	//Jerry--Action
	CCScaleTo* large=CCScaleTo::actionWithDuration(0.5,0.7*LL_SCREEN_SCALE_VALUE);
	CCScaleTo* small=CCScaleTo::actionWithDuration(0.5,LL_BUTTON_SCALE_VALUE);
	CCDelayTime *waiting=CCDelayTime::actionWithDuration(1.0f);
	CCFiniteTimeAction* action= CCSequence::actions(waiting,large,small,waiting,NULL);
	CCActionInterval* actionShake=CCRepeatForever::actionWithAction((CCActionInterval*)action);
	pStartItemSprite->stopAllActions();  
	pStartItemSprite->runAction(actionShake); 

	this->addChild(pStartMenu, 3);

	/*CCSprite* leaderboardNormal = CCSprite::spriteWithFile("images/menu_leaderboard.png");
	CCSprite* leaderboardSelected = CCSprite::spriteWithFile("images/menu_leaderboard.png");
	CCSprite* leaderboardDisabled = CCSprite::spriteWithFile("images/menu_leaderboard.png");
	CCMenuItemSprite* pleaderboardItemSprite = CCMenuItemSprite::itemWithNormalSprite(leaderboardNormal, leaderboardSelected, leaderboardDisabled, this, menu_selector(GameLayer::levelButtonClick));
	pleaderboardItemSprite->setScale(0.8);
	CCMenu* pleaderboardMenu = CCMenu::menuWithItems(pleaderboardItemSprite,NULL);
	pleaderboardMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.4));

	this->addChild(pleaderboardMenu, 3);*/

	CCSprite* instructionNormal = CCSprite::spriteWithFile("images/menu_instruction.png");
	CCSprite* instructionSelected = CCSprite::spriteWithFile("images/menu_instruction.png");
	CCSprite* instructionDisabled = CCSprite::spriteWithFile("images/menu_instruction.png");
	CCMenuItemSprite* pinstructionItemSprite = CCMenuItemSprite::itemWithNormalSprite(instructionNormal, instructionSelected, instructionDisabled, this, menu_selector(GameLayer::instructionButtonClick));
	pinstructionItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pinstructionMenu = CCMenu::menuWithItems(pinstructionItemSprite,NULL);
	pinstructionMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.4));

	this->addChild(pinstructionMenu, 3);

	CCSprite* quitNormal = CCSprite::spriteWithFile("images/menu_quit.png");
	CCSprite* quitSelected = CCSprite::spriteWithFile("images/menu_quit.png");
	CCSprite* quitDisabled = CCSprite::spriteWithFile("images/menu_quit.png");
	CCMenuItemSprite* pquitItemSprite = CCMenuItemSprite::itemWithNormalSprite(quitNormal, quitSelected, quitDisabled, this, menu_selector(GameLayer::finishButtonClick));
	pquitItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pquitMenu = CCMenu::menuWithItems(pquitItemSprite,NULL);
	pquitMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.2));

	this->addChild(pquitMenu, 3);
	//Jerry--Code
	CCSprite* lbNormal = CCSprite::spriteWithFile("images/menu_leaderboard.png");
	CCSprite* lbSelected = CCSprite::spriteWithFile("images/menu_leaderboard.png");
	CCSprite* lbDisabled = CCSprite::spriteWithFile("images/menu_leaderboard.png");
	CCMenuItemSprite* plbItemSprite = CCMenuItemSprite::itemWithNormalSprite(lbNormal, lbSelected, lbDisabled, this, menu_selector(GameLayer::leaderboardButtonClick));
	plbItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* plbMenu = CCMenu::menuWithItems(plbItemSprite,NULL);
	plbMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.3));

	this->addChild(plbMenu, 3);


	/*CCSprite* zero = CCSprite::spriteWithFile("images/name_0.png");
	zero->setPosition(ccp(SCREEN_WIDTH*0.397, SCREEN_HEIGHT*0.84));
	zero->setScale(SCREEN_WIDTH/sprite->getContentSize().width);
	this->addChild(zero,1);

	CCSprite* two = CCSprite::spriteWithFile("images/name_2.png");
	two->setPosition(ccp(SCREEN_WIDTH*0.25, SCREEN_HEIGHT*0.788));
	two->setScale(SCREEN_WIDTH/sprite->getContentSize().width);
	this->addChild(two, 2);

	CCSprite* four = CCSprite::spriteWithFile("images/name_4.png");
	four->setPosition(ccp(SCREEN_WIDTH*0.57, SCREEN_HEIGHT*0.75));
	four->setScale(SCREEN_WIDTH/sprite->getContentSize().width);
	this->addChild(four, 2);

	CCSprite* eight = CCSprite::spriteWithFile("images/name_8.png");
	eight->setPosition(ccp(SCREEN_WIDTH*0.756, SCREEN_HEIGHT*0.804));
	eight->setScale(SCREEN_WIDTH/sprite->getContentSize().width);
	this->addChild(eight, 1);*/

	// Create main loop
	//this->schedule(schedule_selector(GameLayer::update));

	// COCOS2D TIP
	// Create Cocos2D objects here

	// Create Box2D world
	//world = new b2World(b2Vec2(0, 100));

	// BOX2D TIP
	// Create Box2D objects here
	InitBdAd();
	return true;
}

void GameLayer::draw()
{
}

void GameLayer::update(float dt)
{
	// Update Box2D world
	//world->Step(dt, 6, 3);

	// BOX2D TIP
	// Update objects from box2d coordinates here
}
void GameLayer::startButtonClick(CCObject *sender){
	if (bPaused) {
		return;
	}
	reset();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5f,  GameScene::scene()));
}
//Jerry--Code
void GameLayer::leaderboardButtonClick(CCObject *sender){
	/*
	if (bPaused) {
		return;
	}

	bPaused = true;
	CCLayer *layerInput = new CCLayer();

	CCSprite* dialog_bk = CCSprite::spriteWithFile("images/dialog_input.png");
	dialog_bk->setScaleX(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setScaleY(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	layerInput->addChild(dialog_bk,11);

	CCSprite* cancelNormal = CCSprite::spriteWithFile("images/btn_know.png");
	CCSprite* cancelSelected = CCSprite::spriteWithFile("images/btn_know.png");
	CCSprite* cancelDisabled = CCSprite::spriteWithFile("images/btn_know.png");
	CCMenuItemSprite* pcancelItemSprite = CCMenuItemSprite::itemWithNormalSprite(cancelNormal, cancelSelected, cancelDisabled, this, menu_selector(GameLayer::inputButtonClick));
	pcancelItemSprite->setScale(0.6*LL_SCREEN_SCALE_VALUE);
	CCMenu* pcancelMenu = CCMenu::menuWithItems(pcancelItemSprite,NULL);
	pcancelMenu->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.45));

	layerInput->addChild(pcancelMenu, 12);
	layerInput->setTag(1000);
	CCActionInterval* largeto = CCScaleBy::create(0.2, 2);
	layerInput->setScale(0.5);
	layerInput->runAction(largeto);

	CCTextFieldTTF* text = CCTextFieldTTF::textFieldWithPlaceHolder(  "", "Arial", 30);  
	text->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.8));  
	layerInput->addChild(text);  
	text->attachWithIME();
	char buff[16];
	*buff = 0;
	sprintf(buff,"%s",text->getString());
	CCLabelTTF* scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,"arial",36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.96,SCREEN_HEIGHT*0.95));//SCREEN_WIDTH*0.96
	scoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(scoreLabel, 4);

	this->addChild(layerInput, 10);
	*/
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5f, LeaderBoard::scene()));
}

void GameLayer::instructionButtonClick(CCObject *sender){
	if (bPaused) {
		return;
	}

	bPaused = true;
	CCLayer *layer2 = new CCLayer();

	CCSprite* dialog_bk = CCSprite::spriteWithFile("images/dialog_intro.png");
	dialog_bk->setScaleX(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setScaleY(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	layer2->addChild(dialog_bk,11);

	CCSprite* cancelNormal = CCSprite::spriteWithFile("images/btn_know.png");
	CCSprite* cancelSelected = CCSprite::spriteWithFile("images/btn_know.png");
	CCSprite* cancelDisabled = CCSprite::spriteWithFile("images/btn_know.png");
	CCMenuItemSprite* pcancelItemSprite = CCMenuItemSprite::itemWithNormalSprite(cancelNormal, cancelSelected, cancelDisabled, this, menu_selector(GameLayer::cancelButtonClick));
	pcancelItemSprite->setScale(0.6*LL_SCREEN_SCALE_VALUE);
	CCMenu* pcancelMenu = CCMenu::menuWithItems(pcancelItemSprite,NULL);
	pcancelMenu->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.28));

	layer2->addChild(pcancelMenu, 12);
	layer2->setTag(1000);
	CCActionInterval* largeto = CCScaleBy::create(0.2, 2);
	layer2->setScale(0.5);
	layer2->runAction(largeto);
	this->addChild(layer2, 10);
}

void GameLayer::finishButtonClick(CCObject *sender){
	if (bPaused) {
		return;
	}
	this->removeAllChildrenWithCleanup(true);
	CCDirector::sharedDirector()->end();
}

void GameLayer::cancelButtonClick(CCObject *sender){
	this->removeChildByTag(1000);
	bPaused = false;
	//CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5f,  GameScene::scene()));
}

void GameLayer::inputButtonClick(CCObject *sender){
	this->removeChildByTag(1000);
	bPaused = false;
	//CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5f,  GameScene::scene()));
}

bool GameLayer:: onTextFieldAttachWithIME(CCTextFieldTTF * sender)
{
	CCLOG("启动输入");
	return false;
	//    return true;(不启动)
}
//    当用户关闭虚拟键盘的时候回调函数
bool GameLayer::  onTextFieldDetachWithIME(CCTextFieldTTF * sender)
{
	CCLOG("关闭输入");
	return false;
	//    return true;(不关闭)
}
//    当用户进行输入 虚拟键盘的时候回调函数
bool  GameLayer:: onTextFieldInsertText(CCTextFieldTTF * sender, const char * text, int nLen)
{
	CCLOG("输入字符");
	return false;
	//    return true;(不输入)
}
//    当用户进行删除文字 虚拟键盘的时候回调函数
bool GameLayer:: onTextFieldDeleteBackward(CCTextFieldTTF * sender, const char * delText, int nLen)
{
	CCLOG("删除字符");
	return false;
	//    return true;(不删除)
}