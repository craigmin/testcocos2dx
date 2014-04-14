package cn.lihui.game.operation;

import cn.lihui.game.object.Point;

public abstract class MoveOperationBase {

	protected Point[] moveLine(Point[] points, Boolean isForward) {
		if (isForward) {
			return moveLineForward(points);
		}

		return reverse(moveLineForward(reverse(points)));
	}

	protected boolean isMovable(final Point[] points) {
		Point[] ps = closer(points);
		for (int i = 0; i < points.length - 1; ++i) {
			if (ps[i].equals(ps[i + 1])) {
				return true;
			} else if (ps[i].isEmpty()){
				return false;
			}
		}
		return false;
	}

	private Point[] moveLineForward(Point[] points) {
		if (points == null || points.length == 0) {
			return points;
		}

		points = closer(points);
		for (int i = 0; i < points.length - 1; ++i) {
			if (points[i].equals(points[i + 1])) {
				points[i].bigger();
				points[i + 1].clear();
				++i;
			}
		}

		return closer(points);
	}

	private Point[] closer(final Point[] points) {
		if (points == null || points.length == 0) {
			return points;
		}

		Point[] ps = new Point[points.length];
		for (int i = 0, j = 0; i < points.length; ++i) {
			ps[i] = points[i].clone();
			ps[i].clear();

			if (!points[i].isEmpty()) {
				ps[j].copyValue(points[i]);
				if(i != j){
					ps[j].setChanged(true);
				}
				++j;
			}
		}

		return ps;
	}

	private Point[] reverse(Point[] points) {
		if (points == null || points.length == 0) {
			return points;
		}

		Point[] ps = new Point[points.length];
		for (int i = 0; i < points.length; ++i) {
			ps[i] = points[points.length - i - 1].clone();
		}
		return ps;
	}
}
