#include "SimpleAudioEngine.h"
#include "GameLayer.h"
#include "GameScene.h"
#include "Lihui2048Api.h"

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

	int SCREEN_WIDTH = CCDirector::sharedDirector()->getWinSize().width;
	int SCREEN_HEIGHT = CCDirector::sharedDirector()->getWinSize().height;

	CCSprite* sprite = CCSprite::spriteWithFile("images/background.png");
	/*sprite->setOpacity(100);*/
	sprite->setScaleX(SCREEN_WIDTH/sprite->getContentSize().width);
	sprite->setScaleY(SCREEN_HEIGHT/sprite->getContentSize().height);
	sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(sprite,1);

	CCSprite* startNormal = CCSprite::spriteWithFile("images/menu_start.png");
    CCSprite* startSelected = CCSprite::spriteWithFile("images/menu_start.png");
    CCSprite* startDisabled = CCSprite::spriteWithFile("images/menu_start.png");
    CCMenuItemSprite* pStartItemSprite = CCMenuItemSprite::itemWithNormalSprite(startNormal, startSelected, startDisabled, this, menu_selector(GameLayer::startButtonClick));
	
	CCMenu* pStartMenu = CCMenu::menuWithItems(pStartItemSprite,NULL);
	 pStartMenu->setPosition(ccp(SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.5));
	 pStartItemSprite->setScale(0.8);
	  //Jerry--Action
	CCScaleTo* large=CCScaleTo::actionWithDuration(0.5,0.9);
	CCScaleTo* small=CCScaleTo::actionWithDuration(0.5,0.8);
	CCDelayTime *waiting=CCDelayTime::actionWithDuration(1.0f);
	CCFiniteTimeAction* action= CCSequence::actions(waiting,large,small,waiting,NULL);
	CCActionInterval* actionShake=CCRepeatForever::actionWithAction((CCActionInterval*)action);
	pStartItemSprite->stopAllActions();  
   pStartItemSprite->runAction(actionShake); 
   
    this->addChild(pStartMenu, 3);

	CCSprite* leaderboardNormal = CCSprite::spriteWithFile("images/menu_leaderboard.png");
    CCSprite* leaderboardSelected = CCSprite::spriteWithFile("images/menu_leaderboard.png");
    CCSprite* leaderboardDisabled = CCSprite::spriteWithFile("images/menu_leaderboard.png");
    CCMenuItemSprite* pleaderboardItemSprite = CCMenuItemSprite::itemWithNormalSprite(leaderboardNormal, leaderboardSelected, leaderboardDisabled, this, menu_selector(GameLayer::levelButtonClick));
    pleaderboardItemSprite->setScale(0.8);
	CCMenu* pleaderboardMenu = CCMenu::menuWithItems(pleaderboardItemSprite,NULL);
    pleaderboardMenu->setPosition(ccp(SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.4));
	
    this->addChild(pleaderboardMenu, 3);

	CCSprite* instructionNormal = CCSprite::spriteWithFile("images/menu_instruction.png");
    CCSprite* instructionSelected = CCSprite::spriteWithFile("images/menu_instruction.png");
    CCSprite* instructionDisabled = CCSprite::spriteWithFile("images/menu_instruction.png");
    CCMenuItemSprite* pinstructionItemSprite = CCMenuItemSprite::itemWithNormalSprite(instructionNormal, instructionSelected, instructionDisabled, this, menu_selector(GameLayer::levelButtonClick));
    pinstructionItemSprite->setScale(0.8);
	CCMenu* pinstructionMenu = CCMenu::menuWithItems(pinstructionItemSprite,NULL);
    pinstructionMenu->setPosition(ccp(SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.3));
	
    this->addChild(pinstructionMenu, 3);

	CCSprite* quitNormal = CCSprite::spriteWithFile("images/menu_quit.png");
    CCSprite* quitSelected = CCSprite::spriteWithFile("images/menu_quit.png");
    CCSprite* quitDisabled = CCSprite::spriteWithFile("images/menu_quit.png");
    CCMenuItemSprite* pquitItemSprite = CCMenuItemSprite::itemWithNormalSprite(quitNormal, quitSelected, quitDisabled, this, menu_selector(GameLayer::finishButtonClick));
    pquitItemSprite->setScale(0.8);
	CCMenu* pquitMenu = CCMenu::menuWithItems(pquitItemSprite,NULL);
    pquitMenu->setPosition(ccp(SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.2));
	
    this->addChild(pquitMenu, 3);

	
    CCSprite* zero = CCSprite::spriteWithFile("images/name_0.png");
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
    this->addChild(eight, 1);

    // Create main loop
    //this->schedule(schedule_selector(GameLayer::update));

    // COCOS2D TIP
    // Create Cocos2D objects here

	// Create Box2D world
	//world = new b2World(b2Vec2(0, 100));

    // BOX2D TIP
    // Create Box2D objects here

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
	reset();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5f,  GameScene::scene()));
}

void GameLayer::levelButtonClick(CCObject *sender){
	/*CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/SelectLevel.raw");


	CCSprite *target = CCSprite::spriteWithFile("images/btn1.png");
    target->setPosition(ccp(100, 100));
        
    CCFiniteTimeAction* actionMove =   
    CCMoveTo::create( (float)3,   
                       ccp( 300, 100) );  
    CCFiniteTimeAction* actionMoveDone =   
    CCCallFuncN::create( this,   
                         callfuncN_selector(GameLayer::animCallback));  
    target->runAction( CCSequence::create(actionMove,   
                         actionMoveDone, NULL) );  

	this->addChild(target, 5);*/
}

void GameLayer::finishButtonClick(CCObject *sender){
	this->removeAllChildrenWithCleanup(true);
	CCDirector::sharedDirector()->end();
}

void GameLayer::animCallback(CCNode *sender){
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/SelectLevel.raw");
}