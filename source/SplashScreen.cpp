#include "SimpleAudioEngine.h"
#include "SplashScreen.h"
#include "GameLayer.h"
#include "LihuiLB.h"
#include "ThemeManager.h"

int splashIndex = 0;

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
	//Jerry--Init LB
	initLB();
	receiveRank();
	splashIndex++;

	CCSprite* bg = ThemeManager::sharedInstance()->spriteWithImageFile(getSplashImage());
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
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInR::transitionWithDuration(0.5f,  nextLayer()));

    // BOX2D TIP
    // Update objects from box2d coordinates here
}

const char* SplashScreen::getSplashImage() {
	switch (splashIndex)
	{
	case 1:
		return "splashscreen_css.jpg" ;
	case 2:
		return "splashscreen_css2.jpg" ;
	default:
		break;
	}

	return "splashscreen_css.jpg";
}

CCScene* SplashScreen::nextLayer(){
	switch (splashIndex)
	{
	case 1:
		return SplashScreen::scene();
	case 2:
		return GameLayer::scene();
	default:
		break;
	}

	return GameLayer::scene();
}