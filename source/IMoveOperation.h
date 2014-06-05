#ifndef __IMOVEOPERATIONS__H__
#define __IMOVEOPERATIONS__H__
#include "ChessBoard.h";

class IMoveOperation{
public:
	virtual ~IMoveOperation();
	virtual void move(ChessBoard* c)=0; 
};
#endif //__IMOVEOPERATION__H__