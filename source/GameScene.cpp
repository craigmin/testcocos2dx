#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "GameLayer.h"
#include "Lihui2048Api.h"
#include "LihuiLB.h"
#include "LihuiSocial.h"


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
			sprintf(buff,"images/numb_%d.png",coodinates_now[i][j]);
			rect[i*4+j]=CCSprite::spriteWithFile(buff);

			if(!isGood && coodinates_now[i][j] > topTileScore) {
				topTileScore = coodinates_now[i][j];
				isGood = true;
			}

			CCSprite* sprite = CCSprite::spriteWithFile("images/gi_background.png");
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

	CCSprite* sprite = CCSprite::spriteWithFile("images/gi_background.png");
	sprite->setScaleX(SCREEN_WIDTH/sprite->getContentSize().width);
	sprite->setScaleY(SCREEN_HEIGHT/sprite->getContentSize().height);
	sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	this->addChild(sprite,1);

	drawMatrix();

	scoreLabel=CCLabelTTF::labelWithString("0",CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,"arial",36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.96,SCREEN_HEIGHT*0.89));//SCREEN_WIDTH*0.96
	scoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(scoreLabel, 4);

	char buff[16];
	*buff = 0;
	sprintf(buff,"%d",getBestScore());
	topScoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,"arial",36*LL_SCREEN_SCALE_VALUE);
	topScoreLabel->setPosition(ccp(SCREEN_WIDTH*0.96,SCREEN_HEIGHT*0.95));
	topScoreLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(topScoreLabel, 4);	

	sprintf(buff,"x%d",getBombs());
	bombLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,"arial",36*LL_SCREEN_SCALE_VALUE);
	bombLabel->setPosition(ccp(SCREEN_WIDTH*0.87,SCREEN_HEIGHT*0.82));
	bombLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(bombLabel, 4);

	sprintf(buff,"x%d",getRearranges());
	rearrangeLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentRight,"arial",36*LL_SCREEN_SCALE_VALUE);
	rearrangeLabel->setPosition(ccp(SCREEN_WIDTH*1.07,SCREEN_HEIGHT*0.82));
	rearrangeLabel->setColor(ccc3(0xEE,0xEE,0xEE));
	this->addChild(rearrangeLabel, 4);

	CCSprite* restartNormal = CCSprite::spriteWithFile("images/restart.png");
	CCSprite* restartSelected = CCSprite::spriteWithFile("images/restart.png");
	CCSprite* restartDisabled = CCSprite::spriteWithFile("images/restart.png");
	CCMenuItemSprite* prestartItemSprite = CCMenuItemSprite::itemWithNormalSprite(restartNormal, restartSelected, restartDisabled, this, menu_selector(GameScene::restartClick));
	prestartItemSprite->setScale(LL_BUTTON_SCALE_VALUE);

	CCMenu* prestartMenu = CCMenu::menuWithItems(prestartItemSprite,NULL);
	prestartMenu->setPosition(ccp(SCREEN_WIDTH*0.24, SCREEN_HEIGHT*0.16));
	//Jerry--Test

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

	CCSprite* bombButtonOff = CCSprite::spriteWithFile("images/bomb.png");
	CCSprite* bombButtonOn = CCSprite::spriteWithFile("images/bomb.png");
	CCMenuItemSprite*  pbombmenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(bombButtonOff, bombButtonOn, this, menu_selector(GameScene::bombButtonClick));
	pbombmenuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* pbomb2menuMenu = CCMenu::menuWithItems(pbombmenuItemSprite,NULL);
	pbomb2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.82));
	this->addChild(pbomb2menuMenu, 3);

	CCSprite* rearrangeButtonOff = CCSprite::spriteWithFile("images/rearrange.png");
	CCSprite* rearrangeButtonOn = CCSprite::spriteWithFile("images/rearrange.png");
	CCMenuItemSprite*  prearrangemenuItemSprite = CCMenuItemSprite::itemWithNormalSprite(rearrangeButtonOff, rearrangeButtonOn, this, menu_selector(GameScene::rearrangeButtonClick));
	prearrangemenuItemSprite->setScale(LL_BUTTON_SCALE_VALUE);
	CCMenu* prearrange2menuMenu = CCMenu::menuWithItems(prearrangemenuItemSprite,NULL);
	prearrange2menuMenu->setPosition(ccp(SCREEN_WIDTH*0.8 ,SCREEN_HEIGHT*0.82));
	this->addChild(prearrange2menuMenu, 3);

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
	pauseGame(USEBOMB);
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
		if((getBombs()<0)||(getBombs()==0)) {
			pauseGame(BUYBOMB);
			return;
		}
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
	updateScore(getBestScore());
	CCSprite* gameover= CCSprite::spriteWithFile("images/gameover.png");
	gameover->setScaleX(SCREEN_WIDTH/gameover->getContentSize().width);
	gameover->setScaleY(SCREEN_WIDTH/gameover->getContentSize().width);
	gameover->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	gameover->setTag(10);

	//ShareButton
	CCSprite* shareButtonOff = CCSprite::spriteWithFile("images/share.png");
	CCSprite* shareButtonOn = CCSprite::spriteWithFile("images/share.png");
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
	CCLabelTTF* scoreLabel=CCLabelTTF::labelWithString(buff,CCSizeMake(400*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter,"arial",80*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(gameover->getContentSize().width*0.5,gameover->getContentSize().width*0.5));
	scoreLabel->setColor(ccc3(0xFF,0xFF,0xFF));
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
		dialog_bk= CCSprite::spriteWithFile("images/dialog_bk.png");
	}if(Type == RESTART) {
		dialog_bk= CCSprite::spriteWithFile("images/restart_dialog_bk.png");
	}if(Type == USEBOMB) {
		dialog_bk= CCSprite::spriteWithFile("images/dialog_bomb.png");
	}if(Type == USEREARRANGE) {
		dialog_bk= CCSprite::spriteWithFile("images/dialog_rearrange.png");
	}if(Type == BUYBOMB){
		dialog_bk= CCSprite::spriteWithFile("images/dialog_buy_bomb.png");
	}if(Type == BUYREARRANGE){
		dialog_bk= CCSprite::spriteWithFile("images/dialog_buy_rearrange.png");
	}

	dialog_bk->setScaleX(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setScaleY(SCREEN_WIDTH/dialog_bk->getContentSize().width);
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
	layer2->addChild(dialog_bk,5);


	CCSprite* confirmNormal = CCSprite::spriteWithFile("images/btn_confirm.png");
	CCSprite* confirmSelected = CCSprite::spriteWithFile("images/btn_confirm.png");
	CCSprite* confirmDisabled = CCSprite::spriteWithFile("images/btn_confirm.png");
	CCMenuItemSprite* pconfirmNormalItemSprite;
	if(Type == BACK2MENU){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, confirmDisabled, this, menu_selector(GameScene::backConfirmButtonClick));
	} if(Type == RESTART) {
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, confirmDisabled, this, menu_selector(GameScene::restartConfirmButtonClick));
	}if(Type == USEBOMB){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, confirmDisabled, this, menu_selector(GameScene::cleanConfirmButtonClick));
	}if(Type == USEREARRANGE){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, confirmDisabled, this, menu_selector(GameScene::rearrangeConfirmButtonClick));
	}if(Type == BUYBOMB){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, confirmDisabled, this, menu_selector(GameScene::buyBombButtonClick));
	}if(Type == BUYREARRANGE){
		pconfirmNormalItemSprite = CCMenuItemSprite::itemWithNormalSprite(confirmNormal, confirmSelected, confirmDisabled, this, menu_selector(GameScene::buyRearrangeButtonClick));
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
	/*
	if (bPaused) {
	return;
	}
	*/
	soundState=!soundState;

	if(soundState){
		psoundmenuItemSprite->setNormalImage(CCSprite::spriteWithFile("images/sound_on.png"));
		psoundmenuItemSprite->setSelectedImage(CCSprite::spriteWithFile("images/sound_on.png"));
	}else{
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

	topTileScore = 16;

	for(int i=0;i<16;++i)
	{
		coodinates_last[i/4][i%4]=0;
		coodinates_now[i/4][i%4]=getValue(i/4,i%4);
	}
	drawMatrix();
	drawScore();
}
// ShareButtonClick
void GameScene::shareButtonClick(CCObject *sender){
	connectToWX();
}

void GameScene::restartClick(CCObject *sender){
	if (bPaused||bClean) {
		return;
	}
	//connectToWX();
	pauseGame(RESTART);
}

void GameScene::back2menuClick(CCObject *sender){
	bPaused=false;

	if (bPaused||bClean) {
		return;
	}

	pauseGame(BACK2MENU);

}

void GameScene::cleancancleClick(CCObject *sender){
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
		}
}
void GameScene::bombButtonClick(CCObject *sender){
	//bPaused = true;
	if(bClean)
		return;
	if((getBombs()==0)||(getBombs()<0)){
		pauseGame(BUYBOMB);
		return;
	}
	empty=getEmptyPoints();
	bClean=true;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			bValueZero[i][j]=false;
		}
		CCSprite* sprite = CCSprite::spriteWithFile("images/gi_background_2.png");
		sprite->setScaleX(SCREEN_WIDTH/sprite->getContentSize().width);
		sprite->setScaleY(SCREEN_HEIGHT/sprite->getContentSize().height);
		sprite->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT/2));
		sprite->setTag(2000);
		this->addChild(sprite,10);
		CCSprite* back2menuNormal = CCSprite::spriteWithFile("images/back2game.png");
		CCSprite* back2menuSelected = CCSprite::spriteWithFile("images/back2game.png");
		CCSprite* back2menuDisabled = CCSprite::spriteWithFile("images/back2game.png");
		CCMenuItemSprite* pback2menuItemSprite = CCMenuItemSprite::itemWithNormalSprite(back2menuNormal, back2menuSelected, back2menuDisabled, this, menu_selector(GameScene::cleancancleClick));
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
				CCSprite* sprite = CCSprite::spriteWithFile("images/gi_background.png");
				CCScaleTo* large=CCScaleTo::actionWithDuration(0.2,1.05*SCREEN_WIDTH/sprite->getContentSize().width);
				CCScaleTo* small=CCScaleTo::actionWithDuration(0.2,SCREEN_WIDTH/sprite->getContentSize().width);
				CCDelayTime *waiting=CCDelayTime::actionWithDuration(0.2f);
				CCFiniteTimeAction* action= CCSequence::actions(waiting,large,small,waiting,NULL);
				CCActionInterval* actionShake=CCRepeatForever::actionWithAction((CCActionInterval*)action);
				CCSprite *target = (CCSprite*)this->getChildByTag(i*4+j+100);
				//target->setOpacity(100);
				target->stopAllActions();
				target->runAction(actionShake);
			}
}
void GameScene::rearrangeButtonClick(CCObject *sender){
	if (bPaused||bClean) {
		return;
	}
	if(getRearranges()>0)
		pauseGame(USEREARRANGE);
	else pauseGame(BUYREARRANGE);
	/*
	reArrange();
	updateCoodinates();
	drawMatrix();
	*/
}
void GameScene::cleanConfirmButtonClick(CCObject *sender){
	cleanRect(cleanX,cleanY);
	coodinates_last[cleanX][cleanY]=0;
	empty++;
	useBombs();
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

	drawProperty();
	bPaused = false;
	reArrange();
	updateCoodinates();
	drawMatrix();


}
void GameScene::fadeOutCallback(CCNode *sender){
	this->removeChildByTag(cleanX*4+cleanY+100);
	if(empty==15){
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
				}
	}
}
void GameScene::buyBombButtonClick(CCObject *sender){ 
	addBombs();
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
}
void GameScene::buyRearrangeButtonClick(CCObject *sender){ 
	addRearranges();
	drawProperty();
	this->removeChildByTag(1000);
	bPaused = false;
}
