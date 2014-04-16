package cn.lihui.game.object;

import cn.lihui.game.consts.PointValueType;

public class Point {
	private int x;
	private int y;
	private int value;
	private int score;
	private int anim;
	private boolean isChanged;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
		this.value = PointValueType.EMPTY;
		this.score = 0;
		this.anim=PointValueType.ANIM_NORMAL;
		this.isChanged = false;
	}

	public Point(int x, int y, int value, int score,int anim, boolean isChanged) {
		this.x = x;
		this.y = y;
		this.value = value;
		this.score = score;
		this.anim=anim;
		this.isChanged = isChanged;
	}

	public void print() {
		System.out.print(value + " ");
	}

	public void setChanged(boolean isChanged) {
		this.isChanged = isChanged;
	}

	public boolean isChanged() {
		return this.isChanged;
	}

	public void resetChanged() {
		this.isChanged = false;
		this.anim=0;
	}
    
	public void init() {
		double random = Math.random();
		if (random < 0.9) {
			this.value = PointValueType.VALUE_2;
		} else {
			this.value = PointValueType.VALUE_4;
		}
		anim=PointValueType.ANIM_NEW;
	}

	public boolean isEmpty() {
		return value == PointValueType.EMPTY;
	}

	public void clear() {
		value = PointValueType.EMPTY;
	}

	public void bigger() {
		anim=PointValueType.ANIM_BIGGER;
		value *= 2;
		score += value;
		isChanged = true;
	}

	public boolean equals(Point p) {
		return this.value == p.value;
	}

	public Point clone() {
		return new Point(this.x, this.y, this.value, this.score,this.anim, this.isChanged);
	}

	public void copyValue(Point p) {
		this.value = p.value;
	}
    public int getX(){
    	return this.x;
    }
    public int getY(){
    	return this.y;
    }
	public int getScore() {
		return this.score;
	}

	public int getValue() {
		return this.value;
	}
	public void setValue(int value){
		this.value=value;
	}

	public boolean isReachMax() {
		return this.value >= PointValueType.VALUE_MAX;
	}

	public int getAnim() {
		// TODO Auto-generated method stub
		return this.anim;
	}
}
