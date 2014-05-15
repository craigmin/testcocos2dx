#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "GameLayer.h"
#include "Lihui2048Api.h"
#include "LihuiLB.h"
#include "LihuiSocial.h"
#include "ThemeManager.h"
#include "TaskManager.h"
#include "LihuiDomob.h"
#include "PlatformManager.h"
#include "LihuiMMInApp.h"

static GameScene * sInstance = NULL;
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
GameScene* GameScene::sharedInstance()
{
	if (sInstance)
		return sInstance;
	/*else {
	sInstance = new GameScene();
	return sInstance;
	}*/

	return NULL;
}

void GameScene::drawMatrix(float dt){

	CCSprite* rect[16];
	bool isGood = false;


	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){


			this->removeChildByTag(i*4+j+100);
			coodinates_last[i][j] = coodinates_now[i][j];
			if(coodinates_now[i][j] == 0){
				continue;
			}

			char buff[256];
			*buff = 0;
			sprintf(buff,"numb_%d.png",coodinates_now[i][j]);
			rect[i*4+j]=ThemeManager::sharedInstance()->spriteWithImageFile(buff);

			if(!isGood && coodinates_now[i][j] > topTileScore) {
				topTileScore = coodinates_now[i][j];
				isGood = true;
			}

			CCSprite* sprite = ThemeManager::sharedInstance()->spriteWithImageFile("gi_background.png");
			rect[i*4+j]->setScale(SCREEN_WIDTH/sprite->getContentSize().width);
			rect[i*4+j]->setPosition(ccp(SCREEN_WIDTH*(0.1375+j*0.2417), SCREEN_HEIGHT*(0.7075-i*0.1359)));
			rect[i*4+j]->setTag(i*4+j+100);
			//Jerry--Acition
			int anim=getAnim(i,j);
			if(anim==1){
				CCActionInterval* largeto = CCScaleBy::create(0.05, 2);
				rect[i*4+j]->setScale(0.5*SCREEN_WIDTH/sprite->getContentSize().width);
				rect[i*4+j]->runAction(largeto);
				if(soundState){
					//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/swipe.mp3", false);
				}
			}else if(anim==2){
				CCActionInterval * large = CCScaleBy::create(0.05, 1.1);
				CCActionInterval * small = large->reverse();
				rect[i*4+j]->runAction(CCSequence::actions(large,small,NULL));
				if(soundState&&!isGood){
					//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/kick.mp3", false);
					//CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/combo.wav", false);
				}
			}
			/*
			switch(anim){
			case 0:
			break;
			case 1:
			rect[i*4+j]->setScale(0.5*SCREEN_WIDTH/sprite->getContentSize().width);
			rect[i*4+j]->runAction(largeto);
			break;
			case 2:  
			//CCFiniteTimeAction * actionbyback = CCSequence::actions(large,small);
			CCActionInterval * large = CCScaleBy::create(0.1, 1.1);
			CCActionInterval * small = large->reverse();
			rect[i*4+j]->runAction(CCSequence::actions(large,small,NULL)); 
			break;
			}*/

			this->addChild(rect[i*4+j],2);

		}

		if(isGood&&soundState) {
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/plaudit.raw");
		}
}
// on "init" you need to initialize your instance
bool GameScene::init()
{
	if (!CCLayer::init())
		return false;

	sInstance = this;
	bombsUsed=5;
	ResUsed=2;
	bGameOver=false;
	soundState=true;
	topTileScore = 16;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sounds/swipe.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sounds/plaudit.raw");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("sounds/CollisionBomb0.raw");
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("sounds/kick.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1);
	SCREEN_WIDTH = CCDirector::sharedDirector()->getWinSize().width;
	SCREEN_HEIGHT = CCDirector::sharedDirector()->getWinSize().height;
	widoffset=0.2417*SCREEN_WIDTH;
	heioffset=0.1359*SCREEN_HEIGHT;

	for(int i=0;i<16;++i)
	{
		coodinates_last[i/4][i%4]=0;
		coodinates_now[i/4][i%4]=getValue(i/4,i%4);
	}

	CCSprite* sprite = ThemeManager::sharedInstance()->spriteWithImageFile("gi_background.png");
	sprite->setScaleX(SCREEN_WIDTH/sprite->getContentSize().width);
	sprite->setScaleY(SCREEN_HEIGHT/sprite->getContentSize().height);
	sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(sprite,1);
	TaskManager::sharedInstance()->initTask(this);
	drawMatrix();

	scoreLabel=CCLabelTTF::labelWithString("0",CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.96,SCREEN_HEIGHT*0.89));//SCREEN_WIDTH*0.96
	scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(scoreLabel, 4);

	char buff[16];
	*buff = 0;
	sprintf(buff,"%d",getBestScore());
	topScoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	topScoreLabel->setPosition(ccp(SCREEN_WIDTH*0.96,SCREEN_HEIGHT*0.95));
	topScoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(topScoreLabel, 4);	

	sprintf(buff,"x%d",getBombs());
	bombLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	bombLabel->setPosition(ccp(SCREEN_WIDTH*0.8,SCREEN_HEIGHT*0.82));
	bombLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(bombLabel, 4);

	sprintf(buff,"x%d",getRearranges());
	rearrangeLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	rearrangeLabel->setPosition(ccp(SCREEN_WIDTH*0.98,SCREEN_HEIGHT*0.82));
	rearrangeLabel->setColor(ThemeManager::sharedInstance()->getColor());
	this->addChild(rearrangeLabel, 4);

	CCSprite* restartNormal = ThemeManager::sharedInstance()->spriteWithImageFile("restart.png");
	CCSprite* restartSelected = ThemeManager::sharedInstance()->spriteWithImageFile("restart.png");
	restartSelected->setScale(1.1);
	CCMenuItemSprite* prestartItemSprite = CCMenuItemSprite::itemWithNormalSprite(restartNormal, restartSelected,this, menu_selector(GameScene::restartClick));
	prestartItemSprite->setScale(LL_BUTTON_SCALE_VALUE);

	CCMenu* prestartMenu = CCMenu::menuWithItems(prestartItemSprite,NULL);
	prestartMenu->setPosition(ccp(SCREEN_WIDTH*0.24, SCREEN_HEIGHT*0.16));
	//Jerry--Test

	this->addChild(prestartMenu, 3);	

	CCSprite* back2menuNormal = ThemeManager::sharedInstance()->spriteWithImageFile("back2menu.png");
	CCSprite* back2menuSelected = ThemeManager::sharedInstance()->spriteWithImageFile("back2menu.png");
	back2menuSelected->setScale(1.1);
	CCMenuItemSprite* pback2menuItemSprite = CCMenuItemSprite::itemWithNormalSprite(back2menuNormal, back2menuSelected,this, menu_selector(GameScene::back2menuClick));
	pback2menuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pback2menuMenu = CCMenu::menuWithItems(pback2menuItemSprite,NULL);
	pback2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.62, SCREEN_HEIGHT*0.16));

	this->addChild(pback2menuMenu, 3);	

	CCSprite* soundButtonOff = ThemeManager::sharedInstance()->spriteWithImageFile("sound_on.png");
	CCSprite* soundButtonOn = ThemeManager::sharedInstance()->spriteWithImageFile("sound_on.png");
	psoundmenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(soundButtonOff, soundButtonOn, this, menu_selector(GameScene::soundButtonClick));
	psoundmenuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* psound2menuMenu = CCMenu::menuWithItems(psoundmenuItemSprite,NULL);
	psound2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.89, SCREEN_HEIGHT*0.16));
	this->addChild(psound2menuMenu, 3);

	CCSprite* bombButtonOff = ThemeManager::sharedInstance()->spriteWithImageFile("bomb.png");
	CCSprite* bombButtonOn = ThemeManager::sharedInstance()->spriteWithImageFile("bomb.png");
	bombButtonOn->setScale(1.1);
	pbombmenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(bombButtonOff, bombButtonOn, this, menu_selector(GameScene::bombButtonClick));
	pbombmenuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	//pbombmenuItemSprite->setTag(3001);
	CCMenu* pbomb2menuMenu = CCMenu::menuWithItems(pbombmenuItemSprite,NULL);
	pbomb2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.55, SCREEN_HEIGHT*0.82));
	this->addChild(pbomb2menuMenu, 3);

	CCSprite* rearrangeButtonOff = ThemeManager::sharedInstance()->spriteWithImageFile("rearrange.png");
	CCSprite* rearrangeButtonOn = ThemeManager::sharedInstance()->spriteWithImageFile("rearrange.png");
	rearrangeButtonOn->setScale(1.1);
	prearrangemenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(rearrangeButtonOff, rearrangeButtonOn, this, menu_selector(GameScene::rearrangeButtonClick));
	prearrangemenuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	//prearrangemenuItemSprite->setTag(3002);
	CCMenu* prearrange2menuMenu = CCMenu::menuWithItems(prearrangemenuItemSprite,NULL);
	prearrange2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.72,SCREEN_HEIGHT*0.82));
	this->addChild(prearrange2menuMenu, 3);

	CCSprite* shopButtonOff = ThemeManager::sharedInstance()->spriteWithImageFile("btn_shop.png");
	CCSprite* shopButtonOn = ThemeManager::sharedInstance()->spriteWithImageFile("btn_shop.png");
	shopButtonOn->setScale(1.1);
	CCMenuItemSprite* pshopmenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(shopButtonOff, shopButtonOn, this, menu_selector(GameScene::shopButtonClick));
	pshopmenuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	//pshopmenuItemSprite->setTag(3002);
	CCMenu* pshop2menuMenu = CCMenu::menuWithItems(pshopmenuItemSprite,NULL);
	pshop2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.9,SCREEN_HEIGHT*0.82));
	this->addChild(pshop2menuMenu, 3);

	bMovable = true;
	bInMoving = false;


	return true;
}


void GameScene::drawScore(){
	char buff[16];
	*buff = 0;
	sprintf(buff,"%d",getCurrentScore());
	scoreLabel->setString(buff);
	sprintf(buff,"%d",getBestScore());
	topScoreLabel->setString(buff);
}
void GameScene::drawProperty(){
	char buff[16];
	*buff = 0;
	sprintf(buff,"x%d",getBombs());
	bombLabel->setString(buff);
	//bombLabel->setString(checkPoints());
	sprintf(buff,"x%d",getRearranges()); 
	rearrangeLabel->setString(buff);
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
void GameScene::inMovable(){
	//bInMovable=true;
	pauseGame(INMOVABLE);
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
			if(bombsUsed==0&&ResUsed==0) gameOver();
			else{
				inMovable();
				bInMovable=true;
			}
		} else {
			if(TaskManager::sharedInstance()->processTask((int*)coodinates_now,getCurrentScore()))
				Taskfinish();
		}
	}
	//bInMovable=false;
	bInMoving = false;
}

void GameScene::updateCoodinates(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			coodinates_now[i][j] = getValue(i,j);
		}
	}
}

void GameScene::animateMatrix(int moveDir){
	updateCoodinates();

	float ANIM_TIME = 0.05;

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
					//target->setTag(i*4+j+100);
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
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("sounds/swipe.mp3", false);
	}
}
void GameScene::cleanPointConfirm(int x,int y){
	if (bValueZero[x][y]==true)
		return;
	cleanX=x;
	cleanY=y;
	//pauseGame(USEBOMB);
	cleanRect(cleanX,cleanY);
	coodinates_last[cleanX][cleanY]=0;
	bInMovable=false;
	bMovable=true;
	//empty++;
	useBombs();
	bombsUsed--;
	//drawScore();
	//addBombs();
	drawProperty();
	bValueZero[cleanX][cleanY]=true;
	bCConfrim=true;
	this->removeChildByTag(1000);
	bPaused = false;
	//bClean=false;
	CCSprite* target=(CCSprite*)this->getChildByTag(cleanX*4+cleanY+100);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/CollisionBomb0.raw");
	CCActionInterval * fadeOutTRTiles = CCFadeOutTRTiles::create(ccg(5, 5), 0.5);
	CCFiniteTimeAction* fadeOutDone = CCCallFuncN::create( this, callfuncN_selector(GameScene::fadeOutCallback)); 
	target->runAction( CCSequence::create(fadeOutTRTiles,fadeOutDone, NULL) );
}
void GameScene::cleanPoint(float x,float y)
{

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			CCSprite* target=(CCSprite*)this->getChildByTag(i*4+j+100);
			if(target!=NULL){

				/*
				char buff[16];
				*buff = 0;
				*/
				float rangXL = target->getPositionX()-0.1042*SCREEN_WIDTH;
				float rangXR = target->getPositionX()+0.1042*SCREEN_WIDTH;
				float rangYU = target->getPositionY()-0.0586*SCREEN_HEIGHT;
				float rangYB = target->getPositionY()+0.0586*SCREEN_HEIGHT;

				/*sprintf(buff,"%4.0f:%4.0f",rangXL, rangXR);

				scoreLabel->setString(buff);

				sprintf(buff,"%4.0f:%4.0f",x, y);

				topScoreLabel->setString(buff);*/

				if(rangXL<x && x<rangXR && rangYU<y && y<rangYB){
					cleanPointConfirm(i,j);
					//cleanRect(i,j);
					//drawMatrix();
					//target->setOpacity(0);
					/*
					if(bCConfrim){
					CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/CollisionBomb0.raw");
					CCActionInterval * fadeOutTRTiles = CCFadeOutTRTiles::create(ccg(5, 5), 0.5);
					target->runAction(fadeOutTRTiles);
					*/
					i=4;

					break;
				}
			}
		}
	}
}
void GameScene::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

	if(bClean){
		if(empty>14){

			return;
		}
		/*
		if((getBombs()<0)||(getBombs()==0)) {
		pauseGame(BUYBOMB);
		return;
		}
		*/
		CCPoint	touch = pTouch->getLocationInView();
		touch = CCDirector::sharedDirector()->convertToGL(touch);
		cleanPoint(touch.x,touch.y);
		return;

	}
	ccp_now = pTouch->getLocationInView();
	ccp_now = CCDirector::sharedDirector()->convertToGL(ccp_now);
	if (bPaused || bInMoving) {
		return;
	}

	bInMoving = true;

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
	bGameOver=true;
	updateScore(getBestScore());
	CCSprite* gameover= ThemeManager::sharedInstance()->spriteWithImageFile("gameover.png");
	gameover->setScaleX(SCREEN_WIDTH/gameover->getContentSize().width);
	gameover->setScaleY(SCREEN_WIDTH/gameover->getContentSize().width);
	gameover->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	gameover->setTag(10);

	//ShareButton
	CCSprite* shareButtonOff = ThemeManager::sharedInstance()->spriteWithImageFile("share.png");
	CCSprite* shareButtonOn = ThemeManager::sharedInstance()->spriteWithImageFile("share.png");
	CCMenuItemSprite* psharemenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(shareButtonOff, shareButtonOn, this, menu_selector(GameScene::shareButtonClick));

	CCMenu* pshare2menuMenu = CCMenu::menuWithItems(psharemenuItemSprite,NULL);
	pshare2menuMenu->setPosition(ccp(gameover->getContentSize().width*0.5, gameover->getContentSize().width*0.3));
	psharemenuItemSprite->setScale(0.7*LL_BUTTON_SCALE_VALUE);
	//Jerry--Action
	CCScaleTo* large=CCScaleTo::actionWithDuration(0.1,0.8*LL_BUTTON_SCALE_VALUE);
	CCScaleTo* small=CCScaleTo::actionWithDuration(0.1,0.7*LL_BUTTON_SCALE_VALUE);
	CCDelayTime *waiting=CCDelayTime::actionWithDuration(0.5f);
	CCFiniteTimeAction* action= CCSequence::actions(waiting,large,small,waiting,NULL);
	CCActionInterval* actionShake=CCRepeatForever::actionWithAction((CCActionInterval*)action);
	psharemenuItemSprite->stopAllActions();
	psharemenuItemSprite->runAction(actionShake);

	gameover->addChild(pshare2menuMenu, 1);

	char buff[16];
	*buff = 0;
	sprintf(buff,"%d !!",getCurrentScore());
	CCLabelTTF* scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(400*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),80*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(gameover->getContentSize().width*0.5,gameover->getContentSize().width*0.5));
	scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());
	gameover->addChild(scoreLabel, 1);

	this->addChild(gameover,5);




}

void GameScene::pauseGame(pausetype Type){ 
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
	if(Type == BACK2MENU){
		dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("dialog_bk.png");
	}if(Type == RESTART) {
		dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("restart_dialog_bk.png");
	}if(Type == USEBOMB) {
		dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("dialog_bomb.png");
	}if(Type == USEREARRANGE) {
		dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("dialog_rearrange.png");
	}if(Type == BUYBOMB){
		dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("dialog_buy_bomb.png");
	}if(Type == BUYREARRANGE){
		dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("dialog_buy_rearrange.png");
	}if(Type == INMOVABLE){
		dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("dialog_item.png");
	}if(Type == SHOP){
		//WallPointVersion
		dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("exchange_dialog.png");
		//InAppVersion
		//dialog_bk= ThemeManager::sharedInstance()->spriteWithImageFile("shop.png");
	}

	dialog_bk->setScaleX(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setScaleY(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	layer2->addChild(dialog_bk,5);


	CCSprite* confirmNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_confirm.png");
	CCSprite* confirmSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_confirm.png");
	confirmSelected->setScale(1.1);
	CCMenuItemSprite* pconfirmNormalItemSprite;
	if(Type == BACK2MENU){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, this, menu_selector(GameScene::backConfirmButtonClick));
	} if(Type == RESTART) {
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, this, menu_selector(GameScene::restartConfirmButtonClick));
	}if(Type == USEBOMB){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, this, menu_selector(GameScene::cleanConfirmButtonClick));
	}if(Type == USEREARRANGE){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, this, menu_selector(GameScene::rearrangeConfirmButtonClick));
	}if(Type == BUYBOMB){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, this, menu_selector(GameScene::buyBombButtonClick));
	}if(Type == BUYREARRANGE){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, this, menu_selector(GameScene::buyRearrangeButtonClick));
	}if(Type == INMOVABLE){
		//pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, this, menu_selector(GameScene::buyRearrangeButtonClick));
		CCSprite* cancelNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_gameover.png");
		CCSprite* cancelSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_gameover.png");
		CCMenuItemSprite* pcancelItemSprite = CCMenuItemSprite::itemWithNormalSprite(cancelNormal, cancelSelected, this, menu_selector(GameScene::gameoverButtonClick));
		pcancelItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pcancelMenu = CCMenu::menuWithItems(pcancelItemSprite,NULL);
		pcancelMenu->setPosition(ccp(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.3));

		CCSprite* buseNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_use.png");
		CCSprite* buseSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_use.png");
		CCMenuItemSprite* pbuseItemSprite = CCMenuItemSprite::itemWithNormalSprite(buseNormal, buseSelected, this, menu_selector(GameScene::bombButtonClick));
		pbuseItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pbuseMenu = CCMenu::menuWithItems(pbuseItemSprite,NULL);
		pbuseMenu->setPosition(ccp(SCREEN_WIDTH*0.81, SCREEN_HEIGHT*0.52));

		CCSprite* ruseNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_use.png");
		CCSprite* ruseSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_use.png");
		CCMenuItemSprite* pruseItemSprite = CCMenuItemSprite::itemWithNormalSprite(ruseNormal, ruseSelected, this, menu_selector(GameScene::rearrangeButtonClick));
		pruseItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pruseMenu = CCMenu::menuWithItems(pruseItemSprite,NULL);
		pruseMenu->setPosition(ccp(SCREEN_WIDTH*0.81, SCREEN_HEIGHT*0.4));

		char buff[16];
		*buff = 0;
		sprintf(buff,"%d",bombsUsed);
		CCSprite* bomb2use=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
		bomb2use->setPosition(ccp(SCREEN_WIDTH*0.753,SCREEN_HEIGHT*0.513));
		bomb2use->setColor(ThemeManager::sharedInstance()->getColor());


		sprintf(buff,"%d",ResUsed);
		CCSprite* Re2use=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
		Re2use->setPosition(ccp(SCREEN_WIDTH*0.753,SCREEN_HEIGHT*0.408));
		Re2use->setColor(ThemeManager::sharedInstance()->getColor());

		/*	
		CCScaleTo* large=CCScaleTo::actionWithDuration(0.3,1.5*LL_BUTTON_SCALE_VALUE);
		CCScaleTo* small=CCScaleTo::actionWithDuration(0.3,1*LL_BUTTON_SCALE_VALUE);
		CCDelayTime *waiting=CCDelayTime::actionWithDuration(0.5f);
		CCFiniteTimeAction* action= CCSequence::actions(waiting,large,small,waiting,NULL);
		CCActionInterval* actionShake=CCRepeatForever::actionWithAction((CCActionInterval*)action);
		CCActionInterval* actionShake1=CCRepeatForever::actionWithAction((CCActionInterval*)action);
		pbombmenuItemSprite->runAction(actionShake1);
		prearrangemenuItemSprite->runAction(actionShake);
		*/
		layer2->addChild(pcancelMenu, 10);
		layer2->addChild(pbuseMenu, 10);
		layer2->addChild(pruseMenu, 10);
		layer2->addChild(bomb2use, 10);	
		layer2->addChild(Re2use, 10);
		layer2->setTag(1005);

		this->addChild(layer2, 10);
		return;
	}if(Type == SHOP){
		///*
		//WallPointVersion
		CCSprite* getpointNormal = ThemeManager::sharedInstance()->spriteWithImageFile("get.png");
		CCSprite* getpointSelected = ThemeManager::sharedInstance()->spriteWithImageFile("get.png");
		CCMenuItemSprite* pgetpointItemSprite = CCMenuItemSprite::itemWithNormalSprite(getpointNormal, getpointSelected, this, menu_selector(GameScene::getPointClick));
		pgetpointItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pgetpointMenu = CCMenu::menuWithItems(pgetpointItemSprite,NULL);
		pgetpointMenu->setPosition(ccp(SCREEN_WIDTH*0.81, SCREEN_HEIGHT*0.685));

		CCSprite* buseNormal = ThemeManager::sharedInstance()->spriteWithImageFile("exchange.png");
		CCSprite* buseSelected = ThemeManager::sharedInstance()->spriteWithImageFile("exchange.png");
		buseSelected->setScale(1.1);
		CCMenuItemSprite* pbuseItemSprite = CCMenuItemSprite::itemWithNormalSprite(buseNormal, buseSelected, this, menu_selector(GameScene::bombConsumeClick));
		pbuseItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pbuseMenu = CCMenu::menuWithItems(pbuseItemSprite,NULL);
		pbuseMenu->setPosition(ccp(SCREEN_WIDTH*0.81, SCREEN_HEIGHT*0.55));

		CCSprite* ruseNormal = ThemeManager::sharedInstance()->spriteWithImageFile("exchange.png");
		CCSprite* ruseSelected = ThemeManager::sharedInstance()->spriteWithImageFile("exchange.png");
		ruseSelected->setScale(1.1);
		CCMenuItemSprite* pruseItemSprite = CCMenuItemSprite::itemWithNormalSprite(ruseNormal, ruseSelected, this, menu_selector(GameScene::rearrangeConsumeClick));
		pruseItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pruseMenu = CCMenu::menuWithItems(pruseItemSprite,NULL);
		pruseMenu->setPosition(ccp(SCREEN_WIDTH*0.81, SCREEN_HEIGHT*0.41));

		pointLabel=CCLabelTTF::labelWithString("Loading...",CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentLeft,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),50*LL_SCREEN_SCALE_VALUE);
		pointLabel->setPosition(ccp(SCREEN_WIDTH*0.6,SCREEN_HEIGHT*0.685));
		pointLabel->setColor(ThemeManager::sharedInstance()->getColor());

		CCSprite* cancelNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_cancel.png");
		CCSprite* cancelSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_cancel.png");
		cancelSelected->setScale(1.1);
		CCMenuItemSprite* pcancelItemSprite = CCMenuItemSprite::itemWithNormalSprite(cancelNormal, cancelSelected, this, menu_selector(GameScene::cancelButtonClick));
		pcancelItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pcancelMenu = CCMenu::menuWithItems(pcancelItemSprite,NULL);
		pcancelMenu->setPosition(ccp(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.28));

		layer2->addChild(pgetpointMenu, 10);
		layer2->addChild(pbuseMenu, 10);
		layer2->addChild(pruseMenu,10);
		layer2->addChild(pointLabel,10);
		layer2->addChild(pcancelMenu,10);
		layer2->setTag(1000);
		this->addChild(layer2, 10);
		//Jerry--Tag
		PlatformManager::sharedInstance()->checkWallPoints();
		return;
		//*/
		/*
		//InAppVersion
		//buygift
		CCSprite* buygiftNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buygift.png");
		CCSprite* buygiftSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buygift.png");
		CCMenuItemSprite* buygiftSprite = CCMenuItemSprite::itemWithNormalSprite(buygiftNormal, buygiftSelected, this, menu_selector(GameScene::buygiftButtonClick));
		buygiftSprite->setScale(0.8*LL_BUTTON_SCALE_VALUE);
		CCMenu* buygiftMenu = CCMenu::menuWithItems(buygiftSprite,NULL);
		buygiftMenu->setPosition(ccp(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.7));
		//buy3bombs
		CCSprite* buy3bombsNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy3bombs.png");
		CCSprite* buy3bombsSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy3bombs.png");
		CCMenuItemSprite* buy3bombsSprite = CCMenuItemSprite::itemWithNormalSprite(buy3bombsNormal, buy3bombsSelected, this, menu_selector(GameScene::buy3bombsButtonClick));
		buy3bombsSprite->setScale(0.8*LL_BUTTON_SCALE_VALUE);
		CCMenu* buy3bombsMenu = CCMenu::menuWithItems(buy3bombsSprite,NULL);
		buy3bombsMenu->setPosition(ccp(SCREEN_WIDTH*0.2, SCREEN_HEIGHT*0.56));
		//buy5bombs
		CCSprite* buy5bombsNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy5bombs.png");
		CCSprite* buy5bombsSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy5bombs.png");
		CCMenuItemSprite* buy5bombsSprite = CCMenuItemSprite::itemWithNormalSprite(buy5bombsNormal, buy5bombsSelected, this, menu_selector(GameScene::buy5bombsButtonClick));
		buy5bombsSprite->setScale(0.8*LL_BUTTON_SCALE_VALUE);
		CCMenu* buy5bombsMenu = CCMenu::menuWithItems(buy5bombsSprite,NULL);
		buy5bombsMenu->setPosition(ccp(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.56));
		//buy10bombs
		CCSprite* buy10bombsNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy10bombs.png");
		CCSprite* buy10bombsSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy10bombs.png");
		CCMenuItemSprite* buy10bombsSprite = CCMenuItemSprite::itemWithNormalSprite(buy10bombsNormal, buy10bombsSelected, this, menu_selector(GameScene::buy10bombsButtonClick));
		buy10bombsSprite->setScale(0.8*LL_BUTTON_SCALE_VALUE);
		CCMenu* buy10bombsMenu = CCMenu::menuWithItems(buy10bombsSprite,NULL);
		buy10bombsMenu->setPosition(ccp(SCREEN_WIDTH*0.8, SCREEN_HEIGHT*0.56));
		//buy1Re
		CCSprite* buy1ReNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy1Re.png");
		CCSprite* buy1ReSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy1Re.png");
		CCMenuItemSprite* buy1ReSprite = CCMenuItemSprite::itemWithNormalSprite(buy1ReNormal, buy1ReSelected, this, menu_selector(GameScene::buy1ReButtonClick));
		buy1ReSprite->setScale(0.8*LL_BUTTON_SCALE_VALUE);
		CCMenu* buy1ReMenu = CCMenu::menuWithItems(buy1ReSprite,NULL);
		buy1ReMenu->setPosition(ccp(SCREEN_WIDTH*0.2, SCREEN_HEIGHT*0.41));
		//buy2Res
		CCSprite* buy2ResNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy2Res.png");
		CCSprite* buy2ResSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy2Res.png");
		CCMenuItemSprite* buy2ResSprite = CCMenuItemSprite::itemWithNormalSprite(buy2ResNormal, buy2ResSelected, this, menu_selector(GameScene::buy2ResButtonClick));
		buy2ResSprite->setScale(0.8*LL_BUTTON_SCALE_VALUE);
		CCMenu* buy2ResMenu = CCMenu::menuWithItems(buy2ResSprite,NULL);
		buy2ResMenu->setPosition(ccp(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.41));
		//buy5Res
		CCSprite* buy5ResNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy5Res.png");
		CCSprite* buy5ResSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_buy5Res.png");
		CCMenuItemSprite* buy5ResSprite = CCMenuItemSprite::itemWithNormalSprite(buy5ResNormal, buy5ResSelected, this, menu_selector(GameScene::buy5ResButtonClick));
		buy5ResSprite->setScale(0.8*LL_BUTTON_SCALE_VALUE);
		CCMenu* buy5ResMenu = CCMenu::menuWithItems(buy5ResSprite,NULL);
		buy5ResMenu->setPosition(ccp(SCREEN_WIDTH*0.8, SCREEN_HEIGHT*0.41));
		//cancel
		CCSprite* cancelNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_cancel.png");
		CCSprite* cancelSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_cancel.png");
		cancelSelected->setScale(1.1);
		CCMenuItemSprite* pcancelItemSprite = CCMenuItemSprite::itemWithNormalSprite(cancelNormal, cancelSelected, this, menu_selector(GameScene::cancelButtonClick));
		pcancelItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pcancelMenu = CCMenu::menuWithItems(pcancelItemSprite,NULL);
		pcancelMenu->setPosition(ccp(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.28));

		layer2->addChild(buygiftMenu, 10);
		layer2->addChild(buy3bombsMenu, 10);
		layer2->addChild(buy5bombsMenu, 10);
		layer2->addChild(buy10bombsMenu, 10);
		layer2->addChild(buy1ReMenu, 10);
		layer2->addChild(buy2ResMenu, 10);
		layer2->addChild(buy5ResMenu, 10);
		layer2->addChild(pcancelMenu,10);
		layer2->setTag(1000);
		this->addChild(layer2, 10);
		return;
		*/
	}
	pconfirmNormalItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pconfirmMenu = CCMenu::menuWithItems(pconfirmNormalItemSprite,NULL);
	pconfirmMenu->setPosition(ccp(SCREEN_WIDTH*0.2778, SCREEN_HEIGHT*(1-0.55)));

	layer2->addChild(pconfirmMenu, 1001);

	CCSprite* cancelNormal = ThemeManager::sharedInstance()->spriteWithImageFile("btn_cancel.png");
	CCSprite* cancelSelected = ThemeManager::sharedInstance()->spriteWithImageFile("btn_cancel.png");
	cancelSelected->setScale(1.1);
	CCMenuItemSprite* pcancelItemSprite = CCMenuItemSprite::itemWithNormalSprite(cancelNormal, cancelSelected, this, menu_selector(GameScene::cancelButtonClick));
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
	if(bInMovable&&!bGameOver) inMovable();
}

void GameScene::backConfirmButtonClick(CCObject *sender){
	this->removeChildByTag(1000);
	bPaused = false;
	bInMovable=false;
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	CCDirector::sharedDirector()->replaceScene(CCTransitionSlideInL::transitionWithDuration(0.5f,  GameLayer::scene()));
}

void GameScene::soundButtonClick(CCObject *sender){
	/*
	if (bPaused) {
	return;
	}
	*/
	

	soundState=!soundState;

	if(soundState){
		psoundmenuItemSprite->setNormalImage(ThemeManager::sharedInstance()->spriteWithImageFile("sound_on.png"));
		psoundmenuItemSprite->setSelectedImage(ThemeManager::sharedInstance()->spriteWithImageFile("sound_on.png"));
	}else{
		psoundmenuItemSprite->setNormalImage(ThemeManager::sharedInstance()->spriteWithImageFile("sound_off.png"));
		psoundmenuItemSprite->setSelectedImage(ThemeManager::sharedInstance()->spriteWithImageFile("sound_off.png"));
	}

}

void GameScene::restartConfirmButtonClick(CCObject *sender){
	this->removeChildByTag(1000);
	bPaused = false;
	//Jerry--delete
	//this->removeChildByTag(10);
	if(!bMovable){
		this->removeChildByTag(10);
		bMovable = true;
	}

	bInMoving = false;
	bInMovable=false;
	reset();
	bGameOver=false;
	bombsUsed=5;
	ResUsed=2;
	topTileScore = 16;

	for(int i=0;i<16;++i)
	{
		coodinates_last[i/4][i%4]=0;
		coodinates_now[i/4][i%4]=getValue(i/4,i%4);
	}
	drawMatrix();
	drawScore();

	TaskManager::sharedInstance()->initTask(this);
}

// ShareButtonClick
void GameScene::shareButtonClick(CCObject *sender){
	connectToWX();
	//drawScore();
}

void GameScene::restartClick(CCObject *sender){
	if (bPaused||bClean) {
		return;
	}
	//connectToWX();
	pauseGame(RESTART);
}

void GameScene::back2menuClick(CCObject *sender){
	/*
	inMovable();
	bInMovable=true;
	return;
	*/
	//bPaused=false;

	if (bPaused||bClean) {
		return;
	}

	pauseGame(BACK2MENU);
}

void GameScene::cleancancleClick(CCObject *sender){
	this->removeChildByTag(2000);
	this->removeChildByTag(2001);
	if(bInMovable&&!bGameOver) inMovable();
	bPaused = false;
	bClean=false;
	bCConfrim=false;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			CCSprite* target=(CCSprite*)this->getChildByTag(i*4+j+100);
			if(target!=NULL)

				//target->setOpacity(255);
					target->stopAllActions();
		}
}
void GameScene::bombButtonClick(CCObject *sender){
	//bPaused = true;
	if(bPaused&&!bInMovable)
		return;
	if(bombsUsed==0){
		//TODO
		ShowRunOut(1);
		return;
	}
	if(bClean) return;
	if(bGameOver)return;
	if(bInMovable){
		this->removeChildByTag(1005);
		bPaused=false;
		/*
		pbombmenuItemSprite->stopAllActions();
		prearrangemenuItemSprite->stopAllActions();
		*/
	}
	if((getBombs()==0)||(getBombs()<0)){

		pauseGame(SHOP);
		return;
	}
	if(getEmptyPoints()>14) return;
	//empty=getEmptyPoints();
	ShowRunOut(2);
	bClean=true;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			bValueZero[i][j]=false;
		}
		CCSprite* sprite = ThemeManager::sharedInstance()->spriteWithImageFile("gi_background_2.png");
		sprite->setScaleX(SCREEN_WIDTH/sprite->getContentSize().width);
		sprite->setScaleY(SCREEN_HEIGHT/sprite->getContentSize().height);
		sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
		sprite->setTag(2000);
		this->addChild(sprite,10);
		CCSprite* back2menuNormal = ThemeManager::sharedInstance()->spriteWithImageFile("back2game.png");
		CCSprite* back2menuSelected = ThemeManager::sharedInstance()->spriteWithImageFile("back2game.png");
		back2menuSelected->setScale(1.1);
		CCMenuItemSprite* pback2menuItemSprite = CCMenuItemSprite::itemWithNormalSprite(back2menuNormal, back2menuSelected,this, menu_selector(GameScene::cleancancleClick));
		pback2menuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
		CCMenu* pback2menuMenu = CCMenu::menuWithItems(pback2menuItemSprite,NULL);
		pback2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.5, SCREEN_HEIGHT*0.16));
		pback2menuMenu->setTag(2001);
		this->addChild(pback2menuMenu,11);	

		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){

				if(coodinates_now[i][j] == 0){
					continue;
				}
				CCSprite* sprite = ThemeManager::sharedInstance()->spriteWithImageFile("gi_background.png");
				CCScaleTo* large=CCScaleTo::actionWithDuration(0.2,1.05*SCREEN_WIDTH/sprite->getContentSize().width);
				CCScaleTo* small=CCScaleTo::actionWithDuration(0.2,SCREEN_WIDTH/sprite->getContentSize().width);
				CCDelayTime *waiting=CCDelayTime::actionWithDuration(0.2f);
				CCFiniteTimeAction* action= CCSequence::actions(waiting,large,small,waiting,NULL);
				CCActionInterval* actionShake=CCRepeatForever::actionWithAction((CCActionInterval*)action);
				CCSprite *target = (CCSprite*)this->getChildByTag(i*4+j+100);
				if(target!=NULL){
					//target->setOpacity(100);
					target->stopAllActions();
					target->runAction(actionShake);
				}
			}
}
void GameScene::rearrangeButtonClick(CCObject *sender){
	if (bPaused&&!bInMovable) {
		return;
	}
	if(ResUsed==0){
		//TODO
		ShowRunOut(1);
		return;
	}
	if(bGameOver)return;
	if(bClean) return;
	if(bInMovable){
		this->removeChildByTag(1005);
		bPaused=false;
		//pbombmenuItemSprite->stopAllActions();
		//->stopAllActions();
	}
	if(getRearranges()>0)
		//pauseGame(USEREARRANGE);
	{

		this->removeChildByTag(1000);
		useRearranges();
		ResUsed--;
		ShowRunOut(3);
		bInMovable=false;
		bMovable=true;
		drawProperty();
		bPaused = false;
		reArrange();
		drawProperty();
		updateCoodinates();
		drawMatrix();

	}
	else pauseGame(SHOP);
	/*
	reArrange();
	updateCoodinates();
	drawMatrix();
	*/
}
void GameScene::cleanConfirmButtonClick(CCObject *sender){
	cleanRect(cleanX,cleanY);
	coodinates_last[cleanX][cleanY]=0;
	bInMovable=false;
	bClean=true;
	bMovable=true;
	//empty++;
	useBombs();
	//drawScore();
	//addBombs();
	drawProperty();
	bValueZero[cleanX][cleanY]=true;
	bCConfrim=true;
	this->removeChildByTag(1000);
	bPaused = false;
	//bClean=false;
	CCSprite* target=(CCSprite*)this->getChildByTag(cleanX*4+cleanY+100);
	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("sounds/CollisionBomb0.raw");
	CCActionInterval * fadeOutTRTiles = CCFadeOutTRTiles::create(ccg(5, 5), 0.5);
	CCFiniteTimeAction* fadeOutDone = CCCallFuncN::create( this, callfuncN_selector(GameScene::fadeOutCallback)); 
	target->runAction( CCSequence::create(fadeOutTRTiles,fadeOutDone, NULL) );
}
void GameScene::rearrangeConfirmButtonClick(CCObject *sender){ 
	this->removeChildByTag(1000);
	useRearranges();
	bInMovable=false;
	bMovable=true;
	drawProperty();
	bPaused = false;
	reArrange();
	drawProperty();
	updateCoodinates();
	drawMatrix();
}
void GameScene::fadeOutCallback(CCNode *sender){
	this->removeChildByTag(cleanX*4+cleanY+100);
	//if(getEmptyPoints()==15){
	this->removeChildByTag(2000);
	this->removeChildByTag(2001);
	bPaused = false;
	bClean=false;
	bCConfrim=false;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			CCSprite* target=(CCSprite*)this->getChildByTag(i*4+j+100);
			if(target!=NULL)

				//target->setOpacity(255);
					target->stopAllActions();
			//}
		}
}
void GameScene::buyBombButtonClick(CCObject *sender){ 
	addBombs(3);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
}
void GameScene::buyRearrangeButtonClick(CCObject *sender){ 
	addRearranges(1);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
}
void GameScene::gameoverButtonClick(CCObject *sender){ 
	this->removeChildByTag(1005);
	gameOver();
	//pbombmenuItemSprite->stopAllActions();
	//prearrangemenuItemSprite->stopAllActions();
	bInMovable=true;
	bPaused = false;
}
void GameScene::shopButtonClick(CCObject *sender){ 
	if (bPaused&&!bInMovable) {
		return;
	}
	if(bGameOver)return;
	if(bClean) return;	
	if(bInMovable){
		this->removeChildByTag(1005);
		bPaused=false;
		//pbombmenuItemSprite->stopAllActions();
		//->stopAllActions();
	}
	pauseGame(SHOP);
}
void GameScene::buygiftButtonClick(CCObject *sender){ 
	//TODO
	//getPoints();
	LihuiInAppBuyItem("gift");
	/*
	addBombs(6);
	addRearranges(3);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
	*/
}
void GameScene::buy3bombsButtonClick(CCObject *sender){ 
	//TODO
	LihuiInAppBuyItem("3bombs");
	/*
	addBombs(3);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
	*/
}
void GameScene::buy5bombsButtonClick(CCObject *sender){ 
	//TODO
	LihuiInAppBuyItem("5bombs");
	/*
	addBombs(5);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
	*/
}
void GameScene::buy10bombsButtonClick(CCObject *sender){ 
	//TODO
	LihuiInAppBuyItem("10bombs");
	/*
	addBombs(10);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
	*/
}
void GameScene::buy1ReButtonClick(CCObject *sender){ 
	//TODO
	LihuiInAppBuyItem("1Re");
	/*
	addRearranges(1);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
	*/
}
void GameScene::buy2ResButtonClick(CCObject *sender){ 
	//TODO
	LihuiInAppBuyItem("2Res");
	/*
	addRearranges(2);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
	*/
}
void GameScene::buy5ResButtonClick(CCObject *sender){ 
	//TODO
	LihuiInAppBuyItem("5Res");
	/*
	addRearranges(5);
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
	*/
}
void GameScene::Taskfinish(){
	TaskAward* award=TaskManager::sharedInstance()->getCurrentTaskAward();
	//Jerry--Action
	CCScaleTo* large=CCScaleTo::actionWithDuration(0.1,1.2);
	CCScaleTo* small=CCScaleTo::actionWithDuration(0.1,1);
	CCFiniteTimeAction* action= CCSequence::actions(large,small,NULL);
	if(award->bombNum!=0){
		addBombs(award->bombNum);
		drawProperty();
		bombLabel->runAction(action);
	}
	if(award->rearrangeNum!=0){
		addRearranges(award->rearrangeNum);
		drawProperty();
		rearrangeLabel->runAction(action);
	}
}
void GameScene::ShowRunOut(int type){
	this->removeChildByTag(4001);
	this->removeChildByTag(4002);
	CCSprite* dialog_bk;
	if(type==1){
		dialog_bk = ThemeManager::sharedInstance()->spriteWithImageFile("dialog_runout.png");
	}
	if(type==2){
		dialog_bk = ThemeManager::sharedInstance()->spriteWithImageFile("dialog_left.png");
		char buff[16];
		*buff = 0;
		sprintf(buff,"%d",bombsUsed);
		CCSprite* bomb2use=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,ThemeManager::sharedInstance()->getFontName(),40*LL_SCREEN_SCALE_VALUE);
		bomb2use->setPosition(ccp(SCREEN_WIDTH*0.97,SCREEN_HEIGHT*0.5));
		bomb2use->setTag(4002);
		bomb2use->setColor(ThemeManager::sharedInstance()->getColor());
		this->addChild(bomb2use,2001);
	}
	if(type==3){
		dialog_bk = ThemeManager::sharedInstance()->spriteWithImageFile("dialog_left.png");
		char buff[16];
		*buff = 0;
		sprintf(buff,"%d",ResUsed);
		CCSprite* bomb2use=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,ThemeManager::sharedInstance()->getFontName(),40*LL_SCREEN_SCALE_VALUE);
		bomb2use->setPosition(ccp(SCREEN_WIDTH*0.97,SCREEN_HEIGHT*0.5));
		bomb2use->setTag(4002);
		bomb2use->setColor(ThemeManager::sharedInstance()->getColor());
		this->addChild(bomb2use,2001);
	}
	dialog_bk->setScale(0.6*LL_SCREEN_SCALE_VALUE);
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.5));
	dialog_bk->setTag(4001);
	/*  
	CCActionInterval* largeto = CCScaleBy::create(0.5, 2);      
	dialog_bk->setScale(SCREEN_WIDTH*0.5/dialog_bk->getConten   tSize().width);
	dialog_bk->runAction(largeto);
	*/
	this->addChild(dialog_bk,2000);
	this->schedule(schedule_selector(GameScene::update), 1,0,1.5);
}
void GameScene::update(CCNode *sender) { 
	this->removeChildByTag(4001);
	this->removeChildByTag(4002);
}
void GameScene::drawWallPoints(const char* p)
{
	pointLabel->setString(p);
}
void GameScene::getPointClick(CCObject *sender){ 
	PlatformManager::sharedInstance()->getIntoWall();
	
	//PlatformManager::sharedInstance()->checkWallPoints();
	//getPoints();
	return;
}
void GameScene::bombConsumeClick(CCObject *sender){ 
	PlatformManager::sharedInstance()->consumeWallPoints(1000);
}
void GameScene::rearrangeConsumeClick(CCObject *sender){
	PlatformManager::sharedInstance()->consumeWallPoints(2000);
}
void GameScene::processPurchase(const char* p){
	
	if (!strcmp(p,"1000"))
	{
	addBombs(1);
	
	}
	if (!strcmp(p,"2000")){
	addRearranges(1);
		}
	if (!strcmp(p,"gift")){
	addBombs(6);
	addRearranges(3);
	
	}
	if (!strcmp(p,"3bombs")){
	addBombs(3);
	
	}
	if (!strcmp(p,"5bombs")){
	addBombs(5);
	
	}
	if (!strcmp(p,"10bombs")){
	addBombs(10);
	
	}
	if (!strcmp(p,"1Re")){
	addRearranges(1);
	
	}
	if (!strcmp(p,"2Res")){
	addRearranges(2);
	
	}
	if (!strcmp(p,"5Res")){
	addRearranges(5);
	
	}
	drawProperty();
	PlatformManager::sharedInstance()->checkWallPoints();
}