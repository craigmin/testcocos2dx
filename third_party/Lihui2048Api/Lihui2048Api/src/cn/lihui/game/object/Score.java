package cn.lihui.game.object;

import com.ideaworks3d.marmalade.LoaderActivity;

import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import cn.lihui.game.consts.MatrixSize;

public class Score {
	private int best;
	private int current;
	private SharedPreferences mSharedPreferences;

	public Score() {
		mSharedPreferences = LoaderActivity.m_Activity.getSharedPreferences(
				"cn.lihui.2048", LoaderActivity.m_Activity.MODE_PRIVATE);
		best = mSharedPreferences.getInt("TOPSCORE", 0);
	}

	public int getBest() {
		return best;
	}

	public int getCurrent() {
		return current;
	}

	public void resetCurrent() {
		this.current = 0;
	}

	public void print() {
		System.out.println("--- Score ---");
		System.out.println("Current:[" + current + "] Best:[" + best + "]");
	}

	public void calculate(Point[][] points) {
		this.current = 0;
		for (int x = 0; x < MatrixSize.X_SIZE; x++)
			for (int y = 0; y < MatrixSize.Y_SIZE; y++)
				this.current += points[x][y].getScore();

		if (this.best < this.current) {
			this.best = this.current;

			Editor editor = mSharedPreferences.edit();
			editor.putInt("TOPSCORE", this.best);
			editor.commit();
		}
	}
}
