#ifndef __CHESSBOARD_H_
#define __CHESSBOARD_H_

#include "Point.h";
#include "Score.h";
//#include "IArrangeOperation.h";
//#include "MoveDownOperation.h";
//#include "MoveUpOperation.h";
//#include "MoveLeftOperation.h";
//#include "MoveRightOperation.h";

class ChessBoard 
{
private:
	Point *points;
	Score* score;
	int emptyPoints;
	//TODO IArrangeOperation arrangeOpt;
	int bombs;
	int rearranges;
	void init();
	//IArrangeOperation arrangeOpt;
	MoveUpOperation* mu;
	MoveDownOperation md;
	MoveLeftOperation* ml;
	MoveRightOperation* mr;
public:
	ChessBoard();
	~ChessBoard();
	Point* getXLine(int y);
	Point* getYLine(int x);
	void updateYLine(int x,Point p[]);
	void updateXLine(int y,Point p[]);
	void reorder();
	void reset();
	bool move(int type);
	int recountEmptyPoints();
	bool addPoint();
	void print();
	bool isFull();
	bool isMoved();
	void resetMoved();
	bool isMovable();
	Score* getScore();
	int getPointValue(int x, int y);
    int getPointAnim(int x, int y);
	bool isPointReachMax();
	void rearrangeMatrix();
	void cleanPointValue(int x, int y);
	int getBombs();
	int getRearranges();
	void addBombs(int i);
	void addRearranges(int i);
	void useBombs();
	void useRearranges();
	int getEmptyPoints();
};
#endif // 