#ifndef __MOVETYPESs__H__
#define __MOVETYPES__H__
#include "IMoveOperation.h"
class MoveTypes{

public:
	MoveTypes* up;
	MoveTypes* down;
	MoveTypes* left;
	MoveTypes* right;
	MoveTypes(int type,IMoveOperation mo);
	static IMoveOperation getMoveOperationByType(int type);
	static const char* getMoveNameByType(int type);
};
#endif//__MOVETYPES__H__