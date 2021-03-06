#include "TaskManager.h"
#include "Lihui2048Api.h"
#include "GameLayer.h"
#include "ThemeManager.h"
#include "GameScene.h"

static TaskManager * sInstance = NULL;
static int task_all_finished = -1;

//static int task_mission[task_fixed_list_max] = {8,16,32,64,32,64,32,200,250,300,350,400,450,500};
static int task_mission[task_fixed_list_max] = {256,512,1024,2048,1024,2048,4096,20000,25000,35000,45000,65000,80000,100000};

TaskManager::~TaskManager()
{
}

TaskManager::TaskManager(){
	taskId = task_fixed_block_256;
	SCREEN_WIDTH = CCDirector::sharedDirector()->getWinSize().width;
	SCREEN_HEIGHT = CCDirector::sharedDirector()->getWinSize().height;
}

TaskManager* TaskManager::sharedInstance()
{
	if (sInstance)
		return sInstance;
	else {
		srand( (unsigned)time( NULL ) );
		sInstance = new TaskManager();
		return sInstance;
	}
}

void TaskManager::initTask(CCLayer* cl) {
	clayer = cl;
	if(taskId == task_all_finished) {
		bTaskFinished = true;
		return;
	}

	taskId = task_fixed_block_256;
	bTaskFinished = true;
	for (int i = task_fixed_block_256; i <= task_fixed_block_2048_rearrange ; ++i){
		if(!isTaskFinished(i)) {
			taskId = i;
			bTaskFinished = false;
			break;
		}
	}

	if(bTaskFinished) {
		taskId = generateRandomTask();
		if (taskId != task_all_finished) {
			bTaskFinished = false;
		} else {
			bTaskFinished = true;
		}
	}

	if (!bTaskFinished) {
		showInfo();
	}
}

int TaskManager::generateRandomTask() {
	int id = int(rand()%10)+4;
	for (int i=id;i<task_fixed_list_max;i++) {
		if(!isTaskFinished(i)) {
			return i;
		}
	}
	for (int i=task_fixed_block_1024_2;i<id;i++) {
		if(!isTaskFinished(i)) {
			return i;
		}
	}

	return task_all_finished;
}

bool TaskManager::isTaskFinished(int id){
	return getFlags(formatTaskNameById(id)->getCString()) != 0;
}

bool TaskManager::processTask(int* coodinates, int score){
	if(taskId == task_all_finished || bTaskFinished) {
		return false;
	}

	bool bRes = false;
	if (taskId == task_fixed_block_1024_2) {
		for(int i = 0, j=0; i < 16; i++) {
			if (coodinates[i] == task_mission[taskId]) {
				j++;
				if (j>1) {
					bRes = true;
					break;
				}
			}
		}
	} else	if(taskId <= task_fixed_block_4096) {
		bRes = hasNumber(coodinates, task_mission[taskId]);
	} else if(score >= task_mission[taskId]){
		bRes = true;
	}

	if(bRes) {
		setFlags(formatTaskNameById(taskId)->getCString(), 1);
		bTaskFinished = true;
		showDone();
	}

	return bRes;
}

bool TaskManager::hasNumber(int* coodinates, int number){
	for(int i = 0; i < 16; i++) {
		if(coodinates[i] == number) {
			return true;
		}
	}

	return false;
}

TaskAward* TaskManager::getCurrentTaskAward(){
	return getCurrentTaskAwardById();
}

TaskAward* TaskManager::getCurrentTaskAwardById(){
	TaskAward* award = new TaskAward();
	award->bombNum = 0;
	award->rearrangeNum = 0;

	switch (taskId) {
	case task_fixed_block_256:
	case task_fixed_block_1024:
	case task_fixed_block_1024_2:
	case task_fixed_block_2048_bomb:
	case task_fixed_score_20000:
	case task_fixed_score_25000:
	case task_fixed_score_35000:
		award->bombNum = 1;
		break;
	case task_fixed_block_512:
	case task_fixed_block_2048_rearrange:
	case task_fixed_block_4096:
	case task_fixed_score_45000:
		award->rearrangeNum = 1;
		break;
	case task_fixed_score_65000:
		award->rearrangeNum = 1;
		award->bombNum = 1;
		break;
	case task_fixed_score_80000:
	case task_fixed_score_100000:
		award->rearrangeNum = 1;
		award->bombNum = 2;
		break;
	default:
		break;
	}

	return award;
}

CCString* TaskManager::formatTaskNameById(int id) {
	return CCString::createWithFormat("TASK_2048_ID_%d", id);
}

void TaskManager::showInfo() {
	TaskManager::sharedInstance()->clayer->removeChildByTag(4000);
	CCString* taskBack;
	switch (taskId) {
	case task_fixed_block_1024_2:
	case task_fixed_block_2048_bomb:
		taskBack = CCString::createWithFormat("task_dialog_%d_2.png ", task_mission[taskId]);
		break;
	default:
		taskBack = CCString::createWithFormat("task_dialog_%d.png ", task_mission[taskId]);
		break;
	}

	CCSprite* dialog_bk = ThemeManager::sharedInstance()->spriteWithImageFile(taskBack->getCString());
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.5));
	dialog_bk->setTag(4000);

	CCActionInterval* largeto = CCScaleBy::create(0.5, 2);
	dialog_bk->setScale(SCREEN_WIDTH*0.5/dialog_bk->getContentSize().width);
	dialog_bk->runAction(largeto);

	clayer->addChild(dialog_bk,2000);
	clayer->schedule(schedule_selector(TaskManager::update), 1, 0, 3);
}

void TaskManager::showDone() {
	TaskManager::sharedInstance()->clayer->removeChildByTag(4000);

	CCSprite* dialog_bk = ThemeManager::sharedInstance()->spriteWithImageFile("task_dialog_done.png");
	dialog_bk->setPosition(ccp(SCREEN_WIDTH/2, SCREEN_HEIGHT*0.5));
	dialog_bk->setTag(4000);

	CCActionInterval* largeto = CCScaleBy::create(0.5, 2);
	dialog_bk->setScale(SCREEN_WIDTH*0.5/dialog_bk->getContentSize().width);
	dialog_bk->runAction(largeto);

	clayer->addChild(dialog_bk,2000);
	clayer->schedule(schedule_selector(TaskManager::update), 1, 0, 3);
}

void TaskManager::update(CCNode *sender) {
	TaskManager::sharedInstance()->clayer->removeChildByTag(4000);
}