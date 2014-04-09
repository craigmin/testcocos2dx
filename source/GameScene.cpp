#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "GameLayer.h"
#include "Lihui2048Api.h"
#include "LihuiLB.h"

#define LL_SCREEN_SCALE_VALUE (CCDirector::sharedDirector()->getWinSize().height/1024)
#define LL_BUTTON_SCALE_VALUE (0.6*LL_SCREEN_SCALE_VALUE)

int timeStamp = 0;

int* GameScene::trackMovementPath(const int before[],const int after[], bool b = false) {

		int path[4] = {0,0,0,0};
		int afterC[4] = {0,0,0,0};
		for(int i=0;i<4;i++){
			afterC[i] = after[i];
		}

		for (int i = 0, j = 0; i < 4; i++) {
			if (afterC[j] == 0) {
				break;
			}

			if (before[i] == 0) {
				continue;
			} else if (before[i] == afterC[j]) {
				if(i != j){
					path[i] = j + 1;
				}
				j++;
			} else {
				path[i] = j + 1;
				afterC[j] = afterC[j] - before[i];
			}
		}

		return path;
}

GameScene::~GameScene()
{
}

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();

    // Add layer as a child to scene
    scene->addChild(layer);

    // Return the scene
    return scene;
}

void GameScene::drawMatrix(float dt){

	CCSprite* rect[16];
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++){

		this->removeChildByTag(i*4+j+100);
		coodinates_last[i][j] = coodinates_now[i][j];
		if(coodinates_now[i][j] == 0){
			continue;
		}
		switch(coodinates_now[i][j]){
	
		case 2:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_2.png");
			break;
		case 4:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_4.png");
		break;
		case 8:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_8.png");
		break;
		case 16:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_16.png");
		break;
		case 32:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_32.png");
		break;
		case 64:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_64.png");
		break;
		case 128:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_128.png");
		break;
		case 256:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_256.png");
		break;
		case 512:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_512.png");
		break;
		case 1024:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_1024.png");
		break;
		case 2048:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_2048.png");
		break;
		case 4096:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_4096.png");
		break;
		case 8192:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_8192.png");
		break;
		case 16384:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_16384.png");
		break;
		case 32768:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_32768.png");
		break;
		//default:rect[i*4+j]=CCSprite::spriteWithFile("images/numb_blank.png");
		}
		CCSprite* sprite = CCSprite::spriteWithFile("images/gi_background.png");
		//rect[i*4+j]=CCSprite::spriteWithFile("images/numb_blank.png");
		rect[i*4+j]->setScale(SCREEN_WIDTH/sprite->getContentSize().width);
		rect[i*4+j]->setPosition(ccp(SCREEN_WIDTH*(0.1375+j*0.2417), SCREEN_HEIGHT*(0.7075-i*0.1359)));
		rect[i*4+j]->setTag(i*4+j+100);
		this->addChild(rect[i*4+j],2);
	}
}
// on "init" you need to initialize your instance
bool GameScene::init()
{
    if (!CCLayer::init())
        return false;

	soundState=true;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sounds/909.mp3");
	SCREEN_WIDTH = CCDirector::sharedDirector()->getWinSize().width;
	SCREEN_HEIGHT = CCDirector::sharedDirector()->getWinSize().height;
	
	for(int i=0;i<16;++i)
	{
		coodinates_last[i/4][i%4]=0;
		coodinates_now[i/4][i%4]=getValue(i/4,i%4);
	}

	CCSprite* sprite = CCSprite::spriteWithFile("images/gi_background.png");
	sprite->setScaleX(SCREEN_WIDTH/sprite->getContentSize().width);
	sprite->setScaleY(SCREEN_HEIGHT/sprite->getContentSize().height);
	sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(sprite,1);

	drawMatrix();
	
	scoreLabel=CCLabelTTF::labelWithString("0",CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,"arial",40*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.96,SCREEN_HEIGHT*0.843));
	scoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(scoreLabel, 4);

	char buff[16];
	*buff = 0;
	sprintf(buff,"%d",getBestScore());
	topScoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,"arial",40*LL_SCREEN_SCALE_VALUE);
	topScoreLabel->setPosition(ccp(SCREEN_WIDTH*0.96,SCREEN_HEIGHT*0.92));
	topScoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(topScoreLabel, 4);	

	CCSprite* restartNormal = CCSprite::spriteWithFile("images/restart.png");
    CCSprite* restartSelected = CCSprite::spriteWithFile("images/restart.png");
    CCSprite* restartDisabled = CCSprite::spriteWithFile("images/restart.png");
    CCMenuItemSprite* prestartItemSprite = CCMenuItemSprite::itemWithNormalSprite(restartNormal, restartSelected, restartDisabled, this, menu_selector(GameScene::restartClick));
	prestartItemSprite->setScale(LL_BUTTON_SCALE_VALUE);

	CCMenu* prestartMenu = CCMenu::menuWithItems(prestartItemSprite,NULL);
    prestartMenu->setPosition(ccp(SCREEN_WIDTH*0.24, SCREEN_HEIGHT*0.16));
	
    this->addChild(prestartMenu, 3);	

	CCSprite* back2menuNormal = CCSprite::spriteWithFile("images/back2menu.png");
    CCSprite* back2menuSelected = CCSprite::spriteWithFile("images/back2menu.png");
    CCSprite* back2menuDisabled = CCSprite::spriteWithFile("images/back2menu.png");
    CCMenuItemSprite* pback2menuItemSprite = CCMenuItemSprite::itemWithNormalSprite(back2menuNormal, back2menuSelected, back2menuDisabled, this, menu_selector(GameScene::back2menuClick));
    pback2menuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pback2menuMenu = CCMenu::menuWithItems(pback2menuItemSprite,NULL);
    pback2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.62, SCREEN_HEIGHT*0.16));
	
    this->addChild(pback2menuMenu, 3);	

	CCSprite* soundButtonOff = CCSprite::spriteWithFile("images/sound_on.png");
    CCSprite* soundButtonOn = CCSprite::spriteWithFile("images/sound_on.png");
	  psoundmenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(soundButtonOff, soundButtonOn, this, menu_selector(GameScene::soundButtonClick));
    psoundmenuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* psound2menuMenu = CCMenu::menuWithItems(psoundmenuItemSprite,NULL);
    psound2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.89, SCREEN_HEIGHT*0.16));
	
    this->addChild(psound2menuMenu, 3);
	bMovable = true;
	bInMoving = false;

    return true;
}

void GameScene::restartClick(CCObject *sender){
	if (bPaused) {
		return;
	}

	pauseGame(2);
}

void GameScene::back2menuClick(CCObject *sender){
	if (bPaused) {
		return;
	}

	pauseGame(1);
}

void GameScene::drawScore(){
	char buff[16];
	*buff = 0;
	sprintf(buff,"%d",getCurrentScore());

	scoreLabel->setString(buff);

	sprintf(buff,"%d",getBestScore());

	topScoreLabel->setString(buff);
}

int bAnimFinished = true;
int iAnimCount = 0;
void GameScene::animCallback(CCNode *sender){
	if(iAnimCount>0){
		iAnimCount--;
	}

	if(!bAnimFinished && iAnimCount == 0){
		bAnimFinished = true; 
		this->schedule(schedule_selector(GameScene::drawMatrix), 0.0, false, 0.0);
	}
}

void GameScene::onEnter()
{
    CCLayer::onEnter();
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void GameScene::onExit()
{
    CCLayer::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool GameScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    CCPoint localPoint = pTouch->getLocationInView();
    ccp_last = localPoint;
    ccp_last = CCDirector::sharedDirector()->convertToGL(ccp_last);
    
	return true;
}

void GameScene::moveMatrix(int moveDir){
	int64 nowStamp = s3eTimerGetUTC();
	if(nowStamp - timeStamp < 5000){
		return;
	}
	timeStamp = nowStamp;

	if(bMovable){
		move(moveDir);
		animateMatrix(moveDir);

		drawScore();
		bMovable = isMovable();
		if (!bMovable){
			gameOver();
		}
	}

	bInMoving = false;
}

void GameScene::animateMatrix(int moveDir){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			coodinates_now[i][j] = getValue(i,j);
		}
	}

	float ANIM_TIME = 0.1;

	bAnimFinished = false;
	bool isChanged = false;
	iAnimCount=0;
	if(moveDir == 3) {
		for(int i=0;i<4;i++){
			int* anm;
			anm = trackMovementPath(coodinates_last[i], coodinates_now[i], true);
			
			for (int j =0;j<4;j++) {
				if(anm[j] == 0){
					continue;
				} else {
					iAnimCount++;
					isChanged = true;
					CCSprite *target = (CCSprite*)this->getChildByTag(i*4+j+100);

					CCFiniteTimeAction* actionMove = CCMoveTo::create(ANIM_TIME,ccp(SCREEN_WIDTH*(0.1375+(anm[j]-1)*0.2417), SCREEN_HEIGHT*(0.7075-i*0.1359)) );  

					CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this, callfuncN_selector(GameScene::animCallback));  
					target->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );  

				}
			}
		}

	} else if(moveDir == 4) {
		for(int i=0;i<4;i++){
			int* anm;
			int last[4] = {coodinates_last[i][3],coodinates_last[i][2],coodinates_last[i][1],coodinates_last[i][0]}; 
			int now[4] = {coodinates_now[i][3],coodinates_now[i][2],coodinates_now[i][1],coodinates_now[i][0]}; 
			anm = trackMovementPath(last, now, true);
			
			for (int j =0;j<4;j++) {
				if(anm[3-j] == 0){
					continue;
				} else {
					iAnimCount++;
					isChanged = true;
					CCSprite *target = (CCSprite*)this->getChildByTag(i*4+j+100);

					CCFiniteTimeAction* actionMove = CCMoveTo::create(ANIM_TIME,ccp(SCREEN_WIDTH*(0.1375+(4-anm[3-j])*0.2417), SCREEN_HEIGHT*(0.7075-i*0.1359)) );  

					CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this, callfuncN_selector(GameScene::animCallback));  
					target->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );  

					
				}
			}
		}

	} else if(moveDir == 1){
		for(int i=0;i<4;i++){
			int* anm;
			int last[4] = {coodinates_last[0][i],coodinates_last[1][i],coodinates_last[2][i],coodinates_last[3][i]}; 
			int now[4] = {coodinates_now[0][i],coodinates_now[1][i],coodinates_now[2][i],coodinates_now[3][i]}; 
			anm = trackMovementPath(last, now, true);

			for (int j =0;j<4;j++) {
				if(anm[j] == 0){
					continue;
				} else {
					iAnimCount++;
					isChanged = true;
					CCSprite *target = (CCSprite*)this->getChildByTag(j*4+i+100);

					CCFiniteTimeAction* actionMove = CCMoveTo::create(ANIM_TIME,ccp(SCREEN_WIDTH*(0.1375+i*0.2417), SCREEN_HEIGHT*(0.7075-(anm[j]-1)*0.1359)) );  

					CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this, callfuncN_selector(GameScene::animCallback));  
					target->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );  
				}
			}
		}
	} else if(moveDir == 2){
		for(int i=0;i<4;i++){
			int* anm;
			int last[4] = {coodinates_last[3][i],coodinates_last[2][i],coodinates_last[1][i],coodinates_last[0][i]}; 
			int now[4] = {coodinates_now[3][i],coodinates_now[2][i],coodinates_now[1][i],coodinates_now[0][i]}; 
			anm = trackMovementPath(last, now, true);

			for (int j=0;j<4;j++) {
				if(anm[3-j] == 0){
					continue;
				} else {
					iAnimCount++;
					isChanged = true;
					CCSprite *target = (CCSprite*)this->getChildByTag(j*4+i+100);

					CCFiniteTimeAction* actionMove = CCMoveTo::create(ANIM_TIME,ccp(SCREEN_WIDTH*(0.1375+i*0.2417), SCREEN_HEIGHT*(0.7075-(4-anm[3-j])*0.1359)) );  

					CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create( this, callfuncN_selector(GameScene::animCallback));  
					target->runAction( CCSequence::create(actionMove,actionMoveDone, NULL) );  
				}
			}
		}
	}

	if(!isChanged){
		bAnimFinished = true;
		drawMatrix();
	} else if(soundState){
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/909.mp3", false);
	}
}

void GameScene::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	if (bPaused || bInMoving) {
		return;
	}

	bInMoving = true;
	ccp_now = pTouch->getLocationInView();
    ccp_now = CCDirector::sharedDirector()->convertToGL(ccp_now);
    float adsx = ccp_now.x - ccp_last.x;
    float adsy = ccp_now.y - ccp_last.y;
    if(fabsf(adsx) > fabsf(adsy) && fabsf(adsx) > 80)   //X方向增量大
    {
        if(adsx < 0)
        {
            //左移;
            moveMatrix(3);
        }
        else
        {
            moveMatrix(4);
        }
    }
	else if (fabsf(adsy) > fabsf(adsx) && fabsf(adsy) > 80)
    {
        if(adsy < 0)
        {
            moveMatrix(2);
        }
        else
        {
            moveMatrix(1);
        }
	} else {
		bInMoving = false;
	}
}

void GameScene::gameOver(){
//Jerry--LB
	updateScore(getBestScore());
	CCSprite* gameover= CCSprite::spriteWithFile("images/gameover.png");
	gameover->setScaleX(SCREEN_WIDTH/gameover->getContentSize().width);
	gameover->setScaleY(SCREEN_WIDTH/gameover->getContentSize().width);
	gameover->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	gameover->setTag(10);
	this->addChild(gameover,5);
}

void GameScene::pauseGame(int pauseType){
	//Jerry--LB
	updateScore(getBestScore());
	if (bPaused) {
		return;
	}

	/*if(!bMovable){
		if(pauseType == 1){
			backConfirmButtonClick(NULL);
		} else {
			restartConfirmButtonClick(NULL);
		}

		return;
	}*/

	bPaused = true;
	CCLayer *layer2 = new CCLayer();

	CCSprite* dialog_bk;
	if(pauseType == 1){
		dialog_bk= CCSprite::spriteWithFile("images/dialog_bk.png");
	} else {
		dialog_bk= CCSprite::spriteWithFile("images/restart_dialog_bk.png");
	}
	dialog_bk->setScaleX(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setScaleY(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	layer2->addChild(dialog_bk,5);


	CCSprite* confirmNormal = CCSprite::spriteWithFile("images/btn_confirm.png");
    CCSprite* confirmSelected = CCSprite::spriteWithFile("images/btn_confirm.png");
    CCSprite* confirmDisabled = CCSprite::spriteWithFile("images/btn_confirm.png");
	CCMenuItemSprite* pconfirmNormalItemSprite;
	if(pauseType == 1){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, confirmDisabled, this, menu_selector(GameScene::backConfirmButtonClick));
	} else {
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, confirmDisabled, this, menu_selector(GameScene::restartConfirmButtonClick));
	}
	
	pconfirmNormalItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pconfirmMenu = CCMenu::menuWithItems(pconfirmNormalItemSprite,NULL);
    pconfirmMenu->setPosition(ccp(SCREEN_WIDTH*0.2778, SCREEN_HEIGHT*(1-0.55)));
	
	layer2->addChild(pconfirmMenu, 1001);
	
	CCSprite* cancelNormal = CCSprite::spriteWithFile("images/btn_cancel.png");
    CCSprite* cancelSelected = CCSprite::spriteWithFile("images/btn_cancel.png");
    CCSprite* cancelDisabled = CCSprite::spriteWithFile("images/btn_cancel.png");
    CCMenuItemSprite* pcancelItemSprite = CCMenuItemSprite::itemWithNormalSprite(cancelNormal, cancelSelected, cancelDisabled, this, menu_selector(GameScene::cancelButtonClick));
    pcancelItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pcancelMenu = CCMenu::menuWithItems(pcancelItemSprite,NULL);
    pcancelMenu->setPosition(ccp(SCREEN_WIDTH*0.7222, SCREEN_HEIGHT*(1-0.55)));

    layer2->addChild(pcancelMenu, 1001);
	layer2->setTag(1000);

	this->addChild(layer2, 1000);
}

void GameScene::cancelButtonClick(CCObject *sender){
	this->removeChildByTag(1000);
	bPaused = false;
}

void GameScene::backConfirmButtonClick(CCObject *sender){
	this->removeChildByTag(1000);
	bPaused = false;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::transitionWithDuration(0.5f,  GameLayer::scene()));
}

void GameScene::soundButtonClick(CCObject *sender){
	soundState = !soundState;
	if (soundState) {
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/swipe.wav", true);
		psoundmenuItemSprite->setNormalImage(CCSprite::spriteWithFile("images/sound_on.png"));
		psoundmenuItemSprite->setSelectedImage(CCSprite::spriteWithFile("images/sound_on.png"));
	} else {
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		psoundmenuItemSprite->setNormalImage(CCSprite::spriteWithFile("images/sound_off.png"));
		psoundmenuItemSprite->setSelectedImage(CCSprite::spriteWithFile("images/sound_off.png"));
	}
}

void GameScene::restartConfirmButtonClick(CCObject *sender){
	this->removeChildByTag(1000);
	bPaused = false;

	if(!bMovable){
		this->removeChildByTag(10);
		bMovable = true;
	}

	bInMoving = false;

	reset();

	for(int i=0;i<16;++i)
	{
		coodinates_last[i/4][i%4]=0;
		coodinates_now[i/4][i%4]=getValue(i/4,i%4);
	}
	drawMatrix();
	drawScore();
}