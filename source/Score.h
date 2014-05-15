#ifndef __SCORES_H_
#define __SCORES_H_
#include "Point.h"
class Score
{
private:
	int best;
	int current;
public:
	Score();
	~Score();
	int getBest();
	int getCurrent();
	void resetCurrent();
	void calculate(Point *p);
};
#endif // __AnimationObject_H_