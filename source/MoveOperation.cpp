#include "MoveOperation.h";

static MoveOperation * sInstance = 0;

MoveOperation::MoveOperation()
{
	
	//itemRequestInProgress = false;
}

MoveOperation::~MoveOperation()
{

}
MoveOperation* MoveOperation::sharedInstance()
{
	if (sInstance)
		return sInstance;
	else {
		sInstance = new MoveOperation();
		return sInstance;
	}
}
Point* MoveOperation::moveLine(Point *p,bool isForward)
{
	if(isForward){
		return moveLineForward(p);
	}
	return reverse(moveLineForward(reverse(p)));
}
Point* MoveOperation::moveLineForward(Point *p)
{
	return p; 
}.

	+
	.
