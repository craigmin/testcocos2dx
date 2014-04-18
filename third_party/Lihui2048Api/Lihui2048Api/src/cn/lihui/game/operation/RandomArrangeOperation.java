package cn.lihui.game.operation;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;

import cn.lihui.game.consts.MatrixSize;
import cn.lihui.game.object.Matrix;
import cn.lihui.game.object.Point;
import cn.lihui.game.operation.i.IArrangeOperation;

public class RandomArrangeOperation implements IArrangeOperation {

	@Override
	public void rearrange(Matrix matrix) {
		new RandomArrangement().arrange(matrix, sortPoints(matrix));
	}

	class RandomArrangement {
		// true:horizontal ; false:vertical
		boolean layout;
		// true: forward ; false:backward
		boolean direction;

		RandomArrangement() {
			Random rnd = new Random();
			layout = rnd.nextBoolean();
			direction = rnd.nextBoolean();
		}

		public void arrange(Matrix matrix, Point[] sortedPoints) {
			int firstSize = layout ? MatrixSize.X_SIZE : MatrixSize.Y_SIZE;
			int secondSize = layout ? MatrixSize.Y_SIZE : MatrixSize.X_SIZE;

			for (int x = 0; x < firstSize; x++) {
				Point[] ps = getLine(matrix, x);
				for (int y = 0; y < secondSize; y++) {
					ps[y].copyValue(sortedPoints[x * secondSize + y]);
				}
				reverseLine(ps);
			}
		}

		private Point[] getLine(Matrix matrix, Integer index) {
			return layout ? matrix.getYLine(index) : matrix.getXLine(index);
		}
		
		private void reverseLine(Point[] ps){
			if(!direction) {
				for (int i = 0 ; i < ps.length/2 ; i++) {
					Point temp = ps[ps.length - 1 - i].clone();
					ps[ps.length - 1 - i].copyValue(ps[i]);
					ps[i].copyValue(temp);
				}
			}
			direction=!direction;
		}
	}

	private Point[] sortPoints(Matrix matrix) {
		Point[] sortedValues = new Point[MatrixSize.X_SIZE * MatrixSize.Y_SIZE];
		for (int x = 0; x < MatrixSize.X_SIZE; x++) {
			for (int y = 0; y < MatrixSize.Y_SIZE; y++) {
				sortedValues[x * MatrixSize.Y_SIZE + y] = new Point(
						matrix.getPointValue(x, y));
			}
		}

		Arrays.sort(sortedValues, new PointComparator());
		return sortedValues;
	}

	class PointComparator implements Comparator<Point> {

		@Override
		public int compare(Point p1, Point p2) {
			if (p1.equals(p2)) {
				return 0;
			} else if (p1.getValue() > p2.getValue()) {
				return -1;
			}
			return 1;
		}
	}

}
