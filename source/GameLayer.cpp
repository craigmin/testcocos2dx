#include "SimpleAudioEngine.h"

#include "GameLayer.h"
#include "GameScene.h"
#include "LeaderBoard.h"
#include "Lihui2048Api.h"
#include "LihuiAD_Baidu.h"
#include "LihuiLB.h"
#include "ThemeManager.h"

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

	CCSprite* sprite = ThemeManager::sharedInstance()->spriteWithImageFile("background.png");//ThemeManager::sharedInstance()->spriteWithImageFile("background.png");
	sprite->setScaleX(SCREEN_WIDTH/sprite->getContentSize().width);
	sprite->setScaleY(SCREEN_HEIGHT/sprite->getContentSize().height);
	sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(sprite,1);

	float iMenuWidthOffset = 0.55;
	CCSprite* startNormal = ThemeManager::sharedInstance()->spriteWithImageFile("menu_start.png");
	CCSprite* startSelected = ThemeManager::sharedInstance()->spriteWithImageFile("menu_start.png");
	CCMenuItemSprite* pStartItemSprite = CCMenuItemSprite::itemWithNormalSprite(startNormal, startSelected, this, menu_selector(GameLayer::startButtonClick));

	CCMenu* pStartMenu = CCMenu::menuWithItems(pStartItemSprite,NULL);
	pStartMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.6));
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

	/*CCSprite* leaderboardNormal = ThemeManager::sharedInstance()->spriteWithImageFile("menu_leaderboard.png");
	CCSprite* leaderboardSelected = ThemeManager::sharedInstance()->spriteWithImageFile("menu_leaderboard.png");
	CCSprite* leaderboardDisabled = ThemeManager::sharedInstance()->spriteWithImageFile("menu_leaderboard.png");
	CCMenuItemSprite* pleaderboardItemSprite = CCMenuItemSprite::itemWithNormalSprite(leaderboardNormal, leaderboardSelected, leaderboardDisabled, this, menu_selector(GameLayer::levelButtonClick));
	pleaderboardItemSprite->setScale(0.8);
	CCMenu* pleaderboardMenu = CCMenu::menuWithItems(pleaderboardItemSprite,NULL);
	pleaderboardMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.4));

	this->addChild(pleaderboardMenu, 3);*/

	CCSprite* instructionNormal = ThemeManager::sharedInstance()->spriteWithImageFile("menu_instruction.png");
	CCSprite* instructionSelected = ThemeManager::sharedInstance()->spriteWithImageFile("menu_instruction.png");
	CCMenuItemSprite* pinstructionItemSprite = CCMenuItemSprite::itemWithNormalSprite(instructionNormal, instructionSelected,this, menu_selector(GameLayer::instructionButtonClick));
	pinstructionItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pinstructionMenu = CCMenu::menuWithItems(pinstructionItemSprite,NULL);
	pinstructionMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.5));

	this->addChild(pinstructionMenu, 3);

	CCSprite* quitNormal = ThemeManager::sharedInstance()->spriteWithImageFile("menu_quit.png");
	CCSprite* quitSelected = ThemeManager::sharedInstance()->spriteWithImageFile("menu_quit.png");
	quitSelected->setScale(1.1);
	CCMenuItemSprite* pquitItemSprite = CCMenuItemSprite::itemWithNormalSprite(quitNormal, quitSelected, this, menu_selector(GameLayer::finishButtonClick));
	pquitItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pquitMenu = CCMenu::menuWithItems(pquitItemSprite,NULL);
	pquitMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.2));

	this->addChild(pquitMenu, 3);
	//Jerry--Code
	CCSprite* lbNormal = ThemeManager::sharedInstance()->spriteWithImageFile("menu_leaderboard.png");
	CCSprite* lbSelected = ThemeManager::sharedInstance()->spriteWithImageFile("menu_leaderboard.png");
	lbSelected->setScale(1.1);
	CCMenuItemSprite* plbItemSprite = CCMenuItemSprite::itemWithNormalSprite(lbNormal, lbSelected,  this, menu_selector(GameLayer::leaderboardButtonClick));
	plbItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* plbMenu = CCMenu::menuWithItems(plbItemSprite,NULL);
	plbMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.4));

	this->addChild(plbMenu, 3);

	//Jerry--Code
	CCSprite* thNormal = ThemeManager::sharedInstance()->spriteWithImageFile("menu_theme.png");
	CCSprite* thSelected = ThemeManager::sharedInstance()->spriteWithImageFile("menu_theme.png");
	thSelected->setScale(1.1);
	CCMenuItemSprite* pthItemSprite = CCMenuItemSprite::itemWithNormalSprite(thNormal, thSelected, this, menu_selector(GameLayer::themeButtonClick));
	pthItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pthMenu = CCMenu::menuWithItems(pthItemSprite,NULL);
	pthMenu->setPosition(ccp(SCREEN_WIDTH*iMenuWidthOffset, SCREEN_HEIGHT*0.3));

	this->addChild(pthMenu, 3);

	//updateNickname(NULL);

	//InitBdAd();
	return true;
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

	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5f, LeaderBoard::scene()));
}



void GameLayer::instructionButtonClick(CCObject *sender){
	if (bPaused) {
		return;
	}

	bPaused = true;
	CCLayer *layer2 = new CCLayer();

	CCSprite* dialog_bk = ThemeManager::sharedInstance()->spriteWithImageFile("dialog_intro.png");
	dialog_bk->setScaleX(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setScaleY(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	layer2->addChild(dialog_bk,11);

	CCSprite* cancelNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_know.png");
	CCSprite* cancelSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_know.png");
	CCMenuItemSprite* pcancelItemSprite = CCMenuItemSprite::itemWithNormalSprite(cancelNormal, cancelSelected, this, menu_selector(GameLayer::cancelButtonClick));
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
void GameLayer::themeButtonClick(CCObject *sender){
	if(ThemeManager::sharedInstance()->getTheme()==themeCandy){
		ThemeManager::sharedInstance()->setTheme(themePlain);
		CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::transitionWithDuration(0.5,GameLayer::scene()));
	}else{ ThemeManager::sharedInstance()->setTheme(themeCandy);

	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5,GameLayer::scene()));
	}
}