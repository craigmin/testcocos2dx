#include "ChessBoard.h";
#include "consts.h";
#include "MoveDownOperation.h";
#include "MoveUpOperation.h";
#include "MoveLeftOperation.h";
#include "MoveRightOperation.h";
#include "Point.h"

ChessBoard::ChessBoard()
{
	//TODO
	//arrangeOpt=new RandomArrangeOperation();
	score=new Score();
	bombs=3;
	rearranges=1;
	mu=new MoveUpOperation();
	md=new MoveDownOperation();
	ml=new MoveLeftOperation();
	mr=new MoveRightOperation();
}

void ChessBoard::init()
{
	points = new Point[4*4];
	for(int x=0;x<X_SIZE;x++)
		for(int y=0;y<Y_SIZE;y++)
			points[4*x+y]=Point(x,y);
	addPoint();
	addPoint();
}
void ChessBoard::reset()
{
	init();
	score->resetCurrent();
}
bool ChessBoard::move(int type)
{
	resetMoved();
	switch (type)
	{
	case 1:for(int y=0;y<Y_SIZE; ++y){
			Point* p=this->getXLine(y);
			p=MoveOperation::sharedInstance()->moveLine(p,false);
			this->updateXLine(y,p);
		   }
		break;
	case 2:
		for(int y=0;y<Y_SIZE; ++y){
			Point* p=this->getXLine(y);
			p=MoveOperation::sharedInstance()->moveLine(p,false);
			this->updateXLine(y,p);
			   }
		break;
	case 3:for(int y=0;y<Y_SIZE; ++y){
			Point* p=this->getXLine(y);
			MoveOperation::sharedInstance()->moveLine(p,false);
			this->updateXLine(y,p);
			   }
		break;
	case 4:  
		for(int y=0;y<Y_SIZE; ++y){
			Point* p=this->getXLine(y);
			MoveOperation::sharedInstance()->moveLine(p,false);
			this->updateXLine(y,p);
			   }
		break;
	default:
		break;
	}
	if(isMoved()){
		recountEmptyPoints();
		score->calculate(points);
		return addPoint();
	}
	return false;
}
int ChessBoard::recountEmptyPoints()
{
	emptyPoints=0;
	for(int x=0;x<X_SIZE;x++)
		for(int y=0;y<Y_SIZE;y++){
			if(points[4*x+y].isEmpty())
				emptyPoints++;
		}
		return emptyPoints;
}
bool ChessBoard::addPoint()
{
	if(isFull()){
		return false;
	}
	int random=rand()%emptyPoints+1;
	int index=1;
	for(int x=0;x<X_SIZE;x++)
		for(int y=0;y<Y_SIZE;y++){
			if(points[4*x+y].isEmpty()){
				if(index==random){
					points[4*x+y].init();
					break;
				}
				++index;
			}
		}
		emptyPoints--;
		return true;
}
bool ChessBoard::isFull()
{
	return emptyPoints==0;
}
bool ChessBoard::isMoved()
{
	for(int x=0;x<X_SIZE;x++)
		for(int y=0;y<Y_SIZE;y++)
			if(points[4*x+y].isChanged())
				return true;
	return false;
}
bool ChessBoard::isMovable()
{
	if(!isFull())
		return true;
	//TODO
}
Score* ChessBoard::getScore()
{
	return score;
}
Point* ChessBoard::getXLine(int y)
{
	Point* ps=new Point[4];
	for(int x=0;x<4;x++){
		ps[x]=points[x*4+y];
	}
	return ps;
}
Point* ChessBoard::getYLine(int x)
{
	Point* ps=new Point[4];
	for(int y=0;y<4;y++){
		ps[y]=points[x*4+y];
	}
	return ps;
}
void ChessBoard::updateXLine(int y,Point *ps)
{
	for(int x=0;x<4;++x)
		points[4*x+y]=ps[x];
}
void ChessBoard::updateYLine(int x,Point *ps)
{
	for(int y=0;y<4;++y)
		points[4*x+y]=ps[y];
}
void ChessBoard::resetMoved()
{
	for (int x = 0; x < X_SIZE; x++) {
			for (int y = 0; y < Y_SIZE; y++)
				points[4*x+y].resetChanged();
		}
}
int ChessBoard::getPointValue(int x,int y)
{
	return points[4*x+y].getValue();
}
int ChessBoard::getPointAnim(int x,int y)
{
	return points[4*x+y].getAnim();
}
bool ChessBoard::isPointReachMax()
{
		for (int x = 0; x < X_SIZE; x++) {
			for (int y = 0; y < Y_SIZE; y++)
				if (points[4*x+y].isReachMax()) {
					return true;
				}
		}

		return false;
}
void ChessBoard::cleanPointValue(int x,int y)
{
	points[4*x+y].clear();
}