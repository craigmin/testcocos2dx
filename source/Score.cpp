#include "Score.h"
#include "consts.h"
Score::Score(){
	best=0;
}
int Score::getBest(){
	//TODO
	return best;
}
int Score::getCurrent(){
	return current;
}
void Score::resetCurrent(){
	current=0;
}
void Score::calculate(Point *p)
{
	current=0;
	for(int x=0;x<X_SIZE;x++)
		for(int y=0;y<Y_SIZE;y++)
			current+=p[4*x+y].getScore();
	if(best<current){
		best=current;
	}
	//TODO
}