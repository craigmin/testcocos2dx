package com.lihui.lihui2048;

import cn.lihui.game.object.Matrix;

public class Lihui2048 {
	private static Lihui2048 instanse;
	private Matrix matrix;

	Lihui2048() {
		matrix = new Matrix();
	}

	public static Lihui2048 getInstance() {
		if (instanse == null) {
			instanse = new Lihui2048();
		}

		return instanse;
	}

	public boolean isMovable() {
		return matrix.isMovable();
	}

	public void move(int type) {
		matrix.move(type);
	}

	public int getCurrentScore() {
		return matrix.getScore().getCurrent();
	}

	public int getBestScore() {
		return matrix.getScore().getBest();
	}

	public boolean isWin() {
		return matrix.isPointReachMax();
	}

	public int getValue(int x, int y) {
		return matrix.getPointValue(x, y);
	}

	public void reset() {
		matrix.reset();
	}

	public int getAnim(int x, int y) {
		return matrix.getPointAnim(x, y);
	}

	public void cleanRect(int x, int y) {
		matrix.cleanPointValue(x, y);
	}

	public void reArrange() {
		matrix.rearrangeMatrix();
	}
}
