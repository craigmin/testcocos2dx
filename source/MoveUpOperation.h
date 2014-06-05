#ifndef __MOVEUPOPERATION__H__
#define __MOVEUPOPERATION__H__
#include "MoveOperation.h";
#include "IMoveOperation.h";
#include "ChessBoard.h"
#include "Consts.h"
#include "Point.h"

class MoveUpOperation:public MoveOperation,public IMoveOperation
{
public:
	virtual void move(ChessBoard* c){
		for(int y=0;y<Y_SIZE; ++y){
			Point* p=c->getXLine(y);
			p=moveLine(p,true);
			c->updateXLine(y,p);
		}
	}
};
#endif;//__MOVEUPOPERATION__H__