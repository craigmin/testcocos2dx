package cn.lihui.game.object;

import com.ideaworks3d.marmalade.LoaderActivity;

import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.util.Log;
import cn.lihui.game.consts.MatrixSize;
import cn.lihui.game.consts.MoveTypes;
import cn.lihui.game.operation.MovableValidator;
import cn.lihui.game.operation.RandomArrangeOperation;
import cn.lihui.game.operation.i.IArrangeOperation;
import cn.lihui.game.operation.i.IMovableValidator;
import cn.lihui.game.operation.i.IMoveOperation;

public class Matrix {
	private Point[][] points;
	private Score score;
	private int emptyPoints;
	private IArrangeOperation arrangeOpt;
	private SharedPreferences mSharedPreferences;
    private int bombs;
    private int rearranges;
	public Matrix() {
		mSharedPreferences = LoaderActivity.m_Activity.getSharedPreferences(
				"cn.lihui.2048.properties", LoaderActivity.m_Activity.MODE_PRIVATE);
		arrangeOpt = new RandomArrangeOperation();
		score = new Score();
		bombs=mSharedPreferences.getInt("BOMB", 3);
		rearranges=mSharedPreferences.getInt("REARRANGE", 1);
		init();
	}

	public Point[] getXLine(int y) {
		Point[] ps = new Point[MatrixSize.X_SIZE];
		for (int x = 0; x < MatrixSize.X_SIZE; ++x) {
			ps[x] = points[x][y];
		}

		return ps;
	}

	public void updateXLine(int y, Point[] ps) {
		for (int x = 0; x < MatrixSize.X_SIZE; ++x) {
			points[x][y] = ps[x];
		}
	}

	public Point[] getYLine(int x) {
		Point[] ps = new Point[MatrixSize.Y_SIZE];
		for (int y = 0; y < MatrixSize.Y_SIZE; ++y) {
			ps[y] = points[x][y];
		}

		return ps;
	}

	public void updateYLine(int x, Point[] ps) {
		for (int y = 0; y < MatrixSize.Y_SIZE; ++y) {
			points[x][y] = ps[y];
		}
	}

	private void init() {
		points = new Point[MatrixSize.X_SIZE][MatrixSize.Y_SIZE];
		for (int x = 0; x < MatrixSize.X_SIZE; x++)
			for (int y = 0; y < MatrixSize.Y_SIZE; y++) {
				points[x][y] = new Point(x, y);
			}
		emptyPoints = MatrixSize.X_SIZE * MatrixSize.Y_SIZE;

		addPoint();
		addPoint();
	}
  public void reorder(){
	  for (int i=0;i<4;i++)
		  for (int j=0;j<4;j++){
			  Point pt= this.points[i][j];
		  }
  }
	public void reset() {
		init();
		score.resetCurrent();
	}

	public boolean move(int type) {
		IMoveOperation mo = MoveTypes.getMoveOperationByType(type);
		if (mo == null) {
			return false;
		}

		resetMoved();
		mo.move(this);
		if (isMoved()) {
			recountEmptyPoints();
			score.calculate(this.points);
			return addPoint();
		}

		return false;
	}

	private void recountEmptyPoints() {
		emptyPoints = 0;
		for (int x = 0; x < MatrixSize.X_SIZE; x++)
			for (int y = 0; y < MatrixSize.Y_SIZE; y++) {
				if (points[x][y].isEmpty()) {
					emptyPoints++;
				}
			}
	}

	private boolean addPoint() {
		if (isFull()) {
			return false;
		}

		long random = (long) Math.round(Math.random() * (emptyPoints - 1) + 1);
		if (random > emptyPoints) {
			return false;
		}

		int index = 1;
		for (int x = 0; x < MatrixSize.X_SIZE; x++)
			for (int y = 0; y < MatrixSize.Y_SIZE; y++) {
				if (points[x][y].isEmpty()) {
					if (index == random) {
						points[x][y].init();
						x = MatrixSize.X_SIZE;
						break;
					}
					++index;
				}
			}

		emptyPoints--;
		return true;
	}

	public void print() {
		System.out.println("--- Matrix ---");
		for (int x = 0; x < MatrixSize.X_SIZE; x++) {
			for (int y = 0; y < MatrixSize.Y_SIZE; y++)
				points[x][y].print();
			System.out.println();
		}
		score.print();
		System.out.println("--- ------ ---");
	}

	public boolean isFull() {
		return emptyPoints == 0;
	}

	private boolean isMoved() {
		for (int x = 0; x < MatrixSize.X_SIZE; x++) {
			for (int y = 0; y < MatrixSize.Y_SIZE; y++)
				if (points[x][y].isChanged())
					return true;
		}

		return false;
	}

	private void resetMoved() {
		for (int x = 0; x < MatrixSize.X_SIZE; x++) {
			for (int y = 0; y < MatrixSize.Y_SIZE; y++)
				points[x][y].resetChanged();
		}
	}

	public boolean isMovable() {
		if (!isFull()) {
			return true;
		}

		IMovableValidator mv = new MovableValidator();
		return mv.isMovable(this);
	}

	public Score getScore() {
		return this.score;
	}

	public int getPointValue(int x, int y) {
		return points[x][y].getValue();
	}

	public int getPointAnim(int x, int y) {
		return points[x][y].getAnim();
	}

	public boolean isPointReachMax() {
		for (int x = 0; x < MatrixSize.X_SIZE; x++) {
			for (int y = 0; y < MatrixSize.Y_SIZE; y++)
				if (points[x][y].isReachMax()) {
					return true;
				}
		}

		return false;
	}

	public void rearrangeMatrix() {
		arrangeOpt.rearrange(this);
	}

	public void cleanPointValue(int x, int y){
		this.points[x][y].clear();
		Log.i("","Jerry--cleanPointValue");
	}
	public int getBombs(){
	   return this.bombs;
	}
	public int getRearranges(){
	   return this.rearranges;
		}
	public void addBombs(){
		this.bombs=this.bombs+3;
		Editor editor = mSharedPreferences.edit();
		editor.putInt("BOMB", this.bombs);
		editor.commit();
	}
	public void addRearranges(){
		this.rearranges=this.rearranges+1;
		Editor editor = mSharedPreferences.edit();
		editor.putInt("REARRANGE", this.rearranges);
		editor.commit();
	}
	public void useBombs(){
		this.bombs=this.bombs-1;
		Editor editor = mSharedPreferences.edit();
		editor.putInt("BOMB", this.bombs);
		editor.commit();
	}
	public void useRearranges(){
		this.rearranges=this.rearranges-1;
		Editor editor = mSharedPreferences.edit();
		editor.putInt("REARRANGE", this.rearranges);
		editor.commit();
	}
	public int getEmptyPoints(){
		return this.emptyPoints;
	}
}
