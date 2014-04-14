package cn.lihui.game.operation;

import cn.lihui.game.consts.MatrixSize;
import cn.lihui.game.object.Matrix;
import cn.lihui.game.object.Point;
import cn.lihui.game.operation.i.IMoveOperation;

public class MoveUpOperation extends MoveOperationBase implements
		IMoveOperation {

	@Override
	public void move(Matrix matrix) {
		for (int y = 0; y < MatrixSize.Y_SIZE; ++y) {
			Point[] points = matrix.getXLine(y);
			points = moveLine(points, true);
			matrix.updateXLine(y, points);
		}
	}

}
