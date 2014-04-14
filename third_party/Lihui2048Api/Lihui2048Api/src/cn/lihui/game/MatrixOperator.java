package cn.lihui.game;

import cn.lihui.game.consts.MatrixSize;
import cn.lihui.game.object.Matrix;

public class MatrixOperator {
	private Matrix matrix;
	public static MatrixOperator instanse;

	MatrixOperator() {
		matrix = new Matrix();
	}

	public static MatrixOperator getInstance(){
		if(instanse == null){
			instanse = new MatrixOperator();
		}
		
		return instanse;
	}

	public boolean isMovable() {
		return matrix.isMovable();
	}

	public void move(int type) {
		matrix.move(type);
	}

	public void print() {
		matrix.print();
	}

	public int getCurrentScore() {
		return matrix.getScore().getCurrent();
	}

	public int getBestScore() {
		return matrix.getScore().getBest();
	}

	public void reset() {
		matrix.reset();
	}

	public Integer[][] getMatrix() {
		Integer[][] matrixValues = new Integer[MatrixSize.X_SIZE][MatrixSize.Y_SIZE];
		for (int x = 0; x < MatrixSize.X_SIZE; x++)
			for (int y = 0; y < MatrixSize.Y_SIZE; y++) {
				matrixValues[x][y] = matrix.getPointValue(x, y);
			}
		return matrixValues;
	}
	
	public int getValue(int x, int y){
		return matrix.getPointValue(x, y);
	}

	public boolean isWin() {
		return matrix.isPointReachMax();
	}
}
