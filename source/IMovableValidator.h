#ifndef __IMOVABLEVALIDATOR__H__
#define __IMOVABLEVALIDATOR__H__
#include "ChessBoard.h"

class IMovableValidator{
public:
	virtual ~IMovableValidator();
	virtual bool isMovable(ChessBoard* c)=0;
};
#endif//__IMOVABLEVALIDATOR__H__