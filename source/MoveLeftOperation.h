#ifndef __MOVELEFTOPERATION__H__
#define __MOVELEFTOPERATION__H__

#include "MoveOperation.h";
#include "IMoveOperation.h";
#include "ChessBoard.h"
#include "Consts.h"
#include "Point.h"

class MoveLeftOperation:public MoveOperation,public IMoveOperation
{
public:
	virtual void move(ChessBoard* c){
		for(int x=0;x<X_SIZE; ++x){
			Point* p=c->getYLine(x);
			p=moveLine(p,true);
			c->updateXLine(x,p);
		}
	}
};
#endif;//__MOVEDOWNOPERATION__H__
