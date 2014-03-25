#include "SimpleAudioEngine.h"
#include "GameLayer.h"

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

	CCSprite* sprite = CCSprite::spriteWithFile("images/background.jpg");
	/*sprite->setOpacity(100);*/
	sprite->setScaleX(2);
	sprite->setScaleY(2);
	sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(sprite,1);


	CCSprite* spriteNormal = CCSprite::spriteWithFile("images/btn1.png");
    CCSprite* spriteSelected = CCSprite::spriteWithFile("images/btn2.png");
    CCSprite* spriteDisabled = CCSprite::spriteWithFile("images/btn2.png");
    CCMenuItemSprite* pMenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(spriteNormal, spriteSelected, spriteDisabled, this, menu_selector(GameLayer::levelButtonClick));
    CCMenu* pSpriteMenu = CCMenu::menuWithItems(pMenuItemSprite,NULL);
    pSpriteMenu->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
    this->addChild(pSpriteMenu, 3);


    // Create main loop
    this->schedule(schedule_selector(GameLayer::update));

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

void GameLayer::levelButtonClick(CCObject *sender){
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/SelectLevel.raw");


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

	this->addChild(target, 5);
}

void GameLayer::animCallback(CCNode *sender){
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/SelectLevel.raw");
}

void GameLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint touchPoint = pTouch->locationInView();

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/SelectLevel.raw");
}