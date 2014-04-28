#ifndef __POINT_H_
#define __POINT_H_



class Point 
{
private:
	 int x;
	 int y;
	 int value;
	 int score;
	 int anim;
	 bool isChanged;
public:
	Point(int value);
	Point(int x, int y);
	Point(int x, int y, int value, int score,int anim, bool isChanged);
	void setChanged(bool isChanged);
	bool isChanged();
	void resetChanged();
	void init();
	bool isEmpty();
	void clear();
	void bigger();
	bool equals(Point p);
	Point clone();
	void copyValue(Point p);
	int getX();
	int getY();
	int getScore();
	int getValue();
	void setValue(int value);
	bool isReachMax();
	int getAnim();
	virtual ~Point();


};

#endif // __AnimationObject_H_