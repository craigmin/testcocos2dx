#ifndef __MOVERIGHTOPERATION__H__
#define __MOVERIGHTOPERATION__H__
#include "MoveOperation.h";
#include "IMoveOperation.h";
#include "ChessBoard.h"
#include "Consts.h"
#include "Point.h"


class MoveRightOperation:public MoveOperation,public IMoveOperation
{
public:
	virtual void move(ChessBoard* c){
		for(int x=0;x<X_SIZE; ++x){
			Point* p=c->getYLine(x);
			p=moveLine(p,false);
			c->updateXLine(x,p);
		}
	}
};
#endif;//__MOVERIGHTOPERATION__H__