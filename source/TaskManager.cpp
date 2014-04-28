#include "TaskManager.h"

static TaskManager * sInstance = NULL;

TaskManager::~TaskManager()
{
}

TaskManager::TaskManager(){
	taskId = task_fixed_block_256;
}

TaskManager* TaskManager::sharedInstance()
{
	if (sInstance)
		return sInstance;
	else {
		sInstance = new TaskManager();
		return sInstance;
	}
}

void TaskManager::initTask() {
	taskId = task_fixed_block_256;
	bTaskFinished = false;
}

bool TaskManager::isTaskFinished(){
	return bTaskFinished;
}

void TaskManager::processTask(int* coodinates, int score){
	if(bTaskFinished) {
		return;
	}

	switch (taskId) {
	case task_fixed_block_256:
		break;
	default:
		break;
	}
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