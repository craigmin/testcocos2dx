package com.lihui.lihui2048;

import com.ideaworks3d.marmalade.LoaderActivity;

import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import cn.lihui.game.object.Matrix;

public class Lihui2048 {
	private static Lihui2048 instanse;
	private Matrix matrix;
	private SharedPreferences mSharedPreferences;
	

	Lihui2048() {
		matrix = new Matrix();
		mSharedPreferences = LoaderActivity.m_Activity.getSharedPreferences(
				"cn.lihui.2048.flags", LoaderActivity.m_Activity.MODE_PRIVATE);
	}

	public static Lihui2048 getInstance() {
		if (instanse == null) {
			instanse = new Lihui2048();
		}

		return instanse;
	}

	public boolean isMovable() {
		return matrix.isMovable();
	}

	public void move(int type) {
		matrix.move(type);
	}

	public int getCurrentScore() {
		return matrix.getScore().getCurrent();
	}

	public int getBestScore() {
		return matrix.getScore().getBest();
	}

	public boolean isWin() {
		return matrix.isPointReachMax();
	}

	public int getValue(int x, int y) {
		return matrix.getPointValue(x, y);
	}

	public void reset() {
		matrix.reset();
	}

	public int getAnim(int x, int y) {
		return matrix.getPointAnim(x, y);
	}

	public void cleanRect(int x, int y) {
		matrix.cleanPointValue(x, y);
	}

	public void reArrange() {
		matrix.rearrangeMatrix();
	}
	public int getBombs(){
		return matrix.getBombs();
	}
	public int getRearranges(){
		return matrix.getRearranges();
	}
	public void addBombs(int i){
		matrix.addBombs(i);
	}
	public void addRearranges(int i){
		matrix.addRearranges(i);
	}
	public void useBombs(){
		matrix.useBombs();
	}
	public void useRearranges(){
		matrix.useRearranges();
	}
	public int getEmptyPoints(){
		return matrix.recountEmptyPoints();
	}
	public void setFlags(String key,int flag){
		Editor editor = mSharedPreferences.edit();
		editor.putInt(key, flag);
		editor.commit();
	}
	public int getFlags(String key){
	return mSharedPreferences.getInt(key,0);
	}
}
