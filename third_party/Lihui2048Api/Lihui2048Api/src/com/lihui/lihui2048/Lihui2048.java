package com.lihui.lihui2048;

import android.util.Log;
import cn.lihui.game.MatrixOperator;

public class Lihui2048 {
	private static Lihui2048 instanse;

	public static Lihui2048 getInstance() {
		if (instanse == null) {
			instanse = new Lihui2048();
		}

		return instanse;
	}

	public boolean isMovable() {
		return MatrixOperator.getInstance().isMovable();
	}

	public void move(int type) {
		MatrixOperator.getInstance().move(type);
	}

	public int getCurrentScore() {
		return MatrixOperator.getInstance().getCurrentScore();
	}

	public int getBestScore() {
		return MatrixOperator.getInstance().getBestScore();
	}

	public boolean isWin() {
		return MatrixOperator.getInstance().isWin();
	}

	public int getValue(int x, int y) {
		return MatrixOperator.getInstance().getValue(x, y);
	}

	public void reset() {
		MatrixOperator.getInstance().reset();
	}

	public int getAnim(int x, int y) {
		return MatrixOperator.getInstance().getAnim(x, y);
	}

	public void cleanRect(int x, int y) {
		Log.i("", "cleanRect: " + x + " " + y);
		MatrixOperator.getInstance().cleanPoint(x, y);
	}

	public void reArrange() {
		MatrixOperator.getInstance().rearrangeMatrix();
	}

}
