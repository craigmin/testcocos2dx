#ifndef __MOVEDOWNOPERATION__H__
#define __MOVEDOWNOPERATION__H__

#include "MoveOperation.h";
#include "IMoveOperation.h";
#include "ChessBoard.h"
#include "Consts.h"
#include "Point.h"

class MoveDownOperation:public MoveOperation,public IMoveOperation
{
public:
	virtual void move(ChessBoard* c){
		for(int y=0;y<Y_SIZE; ++y){
			Point* p=c->getXLine(y);
			p=moveLine(p,false);
			c->updateXLine(y,p);
		}
	}
};
#endif;//__MOVEDOWNOPERATION__H__