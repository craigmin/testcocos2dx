#ifndef __MOVEOPERATION__H__
#define __MOVEOPERATION__H__


#include "Point.h"
#include "Score.h"
#include "ChessBoard.h"


class MoveOperation
{
private:
	Point* moveLineForward(Point* p);
	Point* closer(Point* p);
	Point* reverse(Point* p);
public:
	MoveOperation();
	~MoveOperation();
	Point* moveLine(Point* p,bool isForward);
	bool isLineMovable(Point* p);
	bool isBoardMovable(ChessBoard c);
	static MoveOperation* sharedInstance();
	
};
#endif // __MOVEOPERATION__H__