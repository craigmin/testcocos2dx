package cn.lihui.game.operation;

import android.util.Log;
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
				return true;
			}
		}
		return false;
	}

	private Point[] moveLineForward(Point[] points) {
		if (points == null || points.length == 0) {
			return points;
		}
		//Log.i("","Jerry int j=0;");
       int j=0;
       Point[] ps = new Point[points.length];
       boolean flag=true;
		//points = closer(points);
		for (int i = 0; i < points.length ; ++i) {
			ps[i] = points[i].clone();
			ps[i].clear();
			if(points[i].isEmpty()){
			continue;
			}
			if(flag){
				ps[j] = points[j].clone(); 
			ps[j].setValue(points[i].getValue());
			Log.i("","Jerry: "+String.valueOf(ps[j].getX())+" "+String.valueOf(ps[j].getY())+" "+String.valueOf(ps[j].getValue()));
			flag=false;
			if(j!=i){
				ps[j].setChanged(true);
			}
			continue;
			}
            if (ps[j].equals(points[i])){
            	//points[i].clear();
            	ps[j].bigger(); 
            	Log.i("","Jerry: "+String.valueOf(ps[j].getX())+" "+String.valueOf(ps[j].getY())+" "+String.valueOf(ps[j].getValue()));
            	j++;
            	//ps[j].setValue(points[i].getValue()); 
            	flag=true;
            }else {
            	j++;
            	ps[j] = points[j].clone(); 
    			ps[j].setValue(points[i].getValue());
    			if(j!=i){
    				ps[j].setChanged(true);
    			}
               	//flag=true;
            }
		}
		
          
         
				//			if (points[i].equals(points[i + 1])) {
//				points[i].bigger();
//				points[i + 1].clear();
//				++i;
//			}
		
		//Log.i("","Jerry: "+String.valueOf(j));
//    for(j=0;j<points.length;j++){
//    	Log.i("","Jerry: "+String.valueOf(ps[j].getX())+" "+String.valueOf(ps[j].getY())+" "+String.valueOf(ps[j].getValue()));
//    }
		return ps;
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
