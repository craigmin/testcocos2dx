#include "Point.h"
#include "Consts.h"
#include <stdlib.h>
static Point * sInstance = NULL;

Point::Point()
{
	x=0;
	y=0;
	value=0;
	score=0;
	anim=ANIM_NORMAL;
	bChanged=false;
}
Point* Point::sharedInstance()
{
	if (sInstance)
		return sInstance;
	else {
		sInstance = new Point();
		return sInstance;
	}
}

Point::Point(int v)
{
	x=0;
	y=0;
	value=v;
	score=0;
	anim=ANIM_NORMAL;
	bChanged=false;
}
Point::Point(int x,int y)
{
	Point::x=x;
	Point::y=y;
	value=EMPTY;
	score=0;
	anim=ANIM_NORMAL;
	bChanged=false;
}
Point::Point(int x,int y,int v,int s,int a,bool b)
{
	Point::x=x;
	Point::y=y;
	value=v;
	score=s;
	anim= a;
	bChanged=b;
}
void Point::setChanged(bool isChanged)
{
	bChanged=isChanged;
}
bool Point::isChanged()
{
	return bChanged;
}
void Point::resetChanged()
{
	bChanged=false;
	anim=ANIM_NORMAL;
}
void Point::init()
{
	int random=int(rand()%10+1);
	if(random<9||random==9){
		value=VALUE_2;
	}else{
		value=VALUE_4;
	}
	anim=ANIM_NEW;
}
bool Point::isEmpty(){
	return value==EMPTY;
}
void Point::clear(){
	value=EMPTY;
}
void Point::bigger(){
	anim=ANIM_BIGGER;
	value*=2;
	score+=value;
	bChanged=true;
}
bool Point::equals(Point p)
{
	return value==p.value;
}
Point* Point::clone()
{
	return new Point(x,y,value,score,anim,bChanged);
}
void Point::copyValue(Point p)
{
	value=p.value;
}
int Point::getX(){
	return x;
}
int Point::getValue(){
	return value;
}
int Point::getScore(){
	return score;
}
void Point::setValue(int v){
	value=v;
}
int Point::getAnim(){
	return anim;
}