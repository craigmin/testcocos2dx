#include "SimpleAudioEngine.h"
#include "SplashScreen.h"
#include "GameLayer.h"

SplashScreen::~SplashScreen()
{
}

CCScene* SplashScreen::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    SplashScreen *layer = SplashScreen::create();

    // Add layer as a child to scene
    scene->addChild(layer);

    // Return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScreen::init()
{
    if (!CCLayer::init())
        return false;

	int SCREEN_WIDTH = CCDirector::sharedDirector()->getWinSize().width;
	int SCREEN_HEIGHT = CCDirector::sharedDirector()->getWinSize().height;

	CCSprite* bg = CCSprite::spriteWithFile("images/splashscreen_css.jpg");
	float scale = SCREEN_HEIGHT/bg->getContentSize().height;
	bg->setScaleX(scale);
	bg->setScaleY(scale);
	bg->setPosition(ccp(SCREEN_WIDTH/2,SCREEN_HEIGHT/2));
	this->addChild(bg,1);

	// Create main loop
    this->schedule(schedule_selector(SplashScreen::update), 1, false, 2);


    // BOX2D TIP
    // Create Box2D objects here

    return true;
}

void SplashScreen::update(float dt)
{
	// Update Box2D world
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5f,  GameLayer::scene()));

    // BOX2D TIP
    // Update objects from box2d coordinates here
}
