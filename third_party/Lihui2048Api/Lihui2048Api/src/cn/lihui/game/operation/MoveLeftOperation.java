package cn.lihui.game.operation;

import cn.lihui.game.consts.MatrixSize;
import cn.lihui.game.object.Matrix;
import cn.lihui.game.object.Point;
import cn.lihui.game.operation.i.IMoveOperation;

public class MoveLeftOperation extends MoveOperationBase implements
		IMoveOperation {

	@Override
	public void move(Matrix matrix) {
		for (int x = 0; x < MatrixSize.X_SIZE; ++x) {
			Point[] points = matrix.getYLine(x);
			points = moveLine(points, true);
			matrix.updateYLine(x, points);
		}
	}

}
