#include "TaskManager.h"
#include "Lihui2048Api.h"
#include "GameLayer.h"
#include "ThemeManager.h"
#include "GameScene.h"

static TaskManager * sInstance = NULL;
static int task_all_finished = -1;
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
	CCString* cstr = CCString::createWithFormat("TaskID: %d ", taskId);
	showInfo(cstr);
	for (int i = task_fixed_block_256; i <= task_fixed_block_2048_rearrange ; ++i){
		CCString* taskName = formatTaskNameById(i);
		if(getFlags(taskName->getCString()) == 0) {
			taskId = i;
			bTaskFinished = false;

			CCString* cstr = CCString::createWithFormat("TaskID: %d ", taskId);
			showInfo(cstr);
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
		CCString* cstr = CCString::createWithFormat("TaskID: %d ", taskId);
		showInfo(cstr);
	}
}

int TaskManager::generateRandomTask() {
	int id = int(rand()%10)+4;
	for (int i=id;i<task_fixed_list_max;i++) {
		if(!isTaskFinished(id)) {
			return id;
		}
	}
	for (int i=task_fixed_block_1024_2;i<id;i++) {
		if(!isTaskFinished(id)) {
			return id;
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
		if(hasNumber(coodinates, task_mission[taskId])) {
			for(int i = 0, j=0; i < 16; i++) {
				if(coodinates[i] > task_mission[taskId]) {
					bRes = true;
					break;
				} else if (coodinates[i] == task_mission[taskId]) {
					j++;
					if (j>1) {
						bRes = true;
						break;
					}
				}
			}
		}
	} else	if(taskId <= task_fixed_block_4096) {
		bRes = hasNumber(coodinates, task_mission[taskId]);
	} else if(score > task_mission[taskId]){
		bRes = true;
	}

	if(bRes) {
		setFlags(formatTaskNameById(taskId)->getCString(), 1);
		bTaskFinished = true;
	}

	CCString* cstr = CCString::createWithFormat("TaskID: %d , Res: %s", taskId, bRes ? "true" : "false");
	showInfo(cstr);

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

CCString* TaskManager::formatTaskNameById(int taskId) {
	return CCString::createWithFormat("TASK_2048_ID_", taskId);
}

void TaskManager::showInfo(CCString* cstr){
	clayer->removeChildByTag(3000);

	CCLabelTTF* scoreLabel=CCLabelTTF::labelWithString(cstr->getCString(),CCSizeMake(256*LL_SCREEN_SCALE_VALUE,32),kCCTextAlignmentCenter,kCCVerticalTextAlignmentCenter,ThemeManager::sharedInstance()->getFontName(),36*LL_SCREEN_SCALE_VALUE);
	scoreLabel->setPosition(ccp(SCREEN_WIDTH*0.5,SCREEN_HEIGHT*0.5));//SCREEN_WIDTH*0.96
	scoreLabel->setColor(ThemeManager::sharedInstance()->getColor());

	clayer->addChild(scoreLabel, 2000, 3000);
}