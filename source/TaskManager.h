#ifndef __TaskManager_H__
#define __TaskManager_H__

#include "cocos2d.h"
#include "Box2D\Box2D.h"

using namespace cocos2d;

typedef enum {
	task_fixed_block_256,
	task_fixed_block_512,
	task_fixed_block_1024,
	task_fixed_block_2048_rearrange,
	task_fixed_block_1024_2,
	task_fixed_block_2048_bomb,
	task_fixed_block_4096,
	task_fixed_score_20000,
	task_fixed_score_25000,
	task_fixed_score_35000,
	task_fixed_score_45000,
	task_fixed_score_65000,
	task_fixed_score_80000,
	task_fixed_score_100000
} TASK_LIST;

struct TaskAward {
	int bombNum;
	int rearrangeNum;
};

class TaskManager
{
protected:
	int taskId;
	bool bTaskFinished;
	
	TaskAward* getCurrentTaskAwardById();

public:
    ~TaskManager();
    TaskManager();
	static TaskManager* sharedInstance();

	void initTask();
	bool isTaskFinished();
	void processTask(int* coodinates = NULL, int score = 0);
	TaskAward* getCurrentTaskAward();
	
};

#endif // __TaskManager_H__