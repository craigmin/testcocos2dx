package cn.lihui.game;

import cn.lihui.game.consts.MoveTypes;

public class GameExecutor {

	public static void main(String[] args) {
		MatrixOperator matrix = new MatrixOperator();
		matrix.print();

		while (matrix.isMovable() && !matrix.isWin()) {
			int type = (int) Math.round(Math.random() * (MoveTypes.values().length - 1) + 1);
			System.out.println("Move " + MoveTypes.getMoveNameByType(type));
			matrix.move(type);
//			matrix.print();
			System.out.println();
		}
	}

}
