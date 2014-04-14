package cn.lihui.game.operation;

import cn.lihui.game.consts.MatrixSize;
import cn.lihui.game.object.Matrix;
import cn.lihui.game.object.Point;
import cn.lihui.game.operation.i.IMovableValidator;

public class MovableValidator extends MoveOperationBase implements IMovableValidator {

	@Override
	public boolean isMovable(Matrix matrix) {
		for (int x = 0; x < MatrixSize.X_SIZE; ++x) {
			Point[] points = matrix.getYLine(x);
			if(isMovable(points)){
				return true;
			}
		}

		for (int y = 0; y < MatrixSize.Y_SIZE; ++y) {
			Point[] points = matrix.getXLine(y);
			if(isMovable(points)){
				return true;
			}
		}

		return false;
	}
}
