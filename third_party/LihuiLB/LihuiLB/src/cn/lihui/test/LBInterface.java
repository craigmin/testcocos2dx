package cn.lihui.test;

import java.util.Date;

import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.util.Log;
import android.widget.Toast;
import cn.lihui.sdk.Leaderboards;
import com.ideaworks3d.marmalade.LoaderActivity;

public class LBInterface {
	public static SharedPreferences preferences;
	private Editor editor;// = preferences.edit();;
	private final String TAG = "LihuiLB";
	private Leaderboards lb;
	private ResultListener listener;

	public native void LihuiLBReceiveSuccessful(String key);

	public native void LihuiLBReceiveFailedCallback(String key);

	public native void LihuiLBUpdateSuccessfulCallback(String key);

	public native void LihuiLBUpdateFailedCallback(String key);

	public void initLB() {
		preferences = LoaderActivity.m_Activity.getSharedPreferences(
				"purchasetimekit0", LoaderActivity.m_Activity.MODE_PRIVATE);
		editor = preferences.edit();
		ResultListener.lbinterface = this;
		lb = Leaderboards.getInstance().init(LoaderActivity.m_Activity);
		listener = new ResultListener();
	}

	public void updateScore(int score) {
		Log.e(TAG, "Execute updateScore");
		lb.updateScore(score, listener);
	}

	public void receiveRank() {
		Log.e(TAG, "Execute receiveRank");
		lb.getRanks(listener);
	}

	public int getScore(int rank) {

		if (rank == -1) {
			if (listener.getRanks() != null
					&& listener.getRanks().getOwnRank() != null) {
				return listener.getRanks().getOwnRank().getScore();
			}
		} else if (listener.getRanks() != null 
				&& listener.getRanks().getRanks() != null 
				&& listener.getRanks().getRanks().size() >= rank) {
			Log.e(TAG, "Execute getScore" + rank);
			return listener.getRanks().getRanks().get(rank - 1).getScore();
		} else if (rank == 1) {
			LoaderActivity.m_Activity.runOnUiThread(m_Purchase);		
		}
		Log.e(TAG, "Execute getScore" + rank);
		return 0;
	}

	


private final Runnable m_Purchase = new Runnable() {
	public void run() {
		Toast.makeText(LoaderActivity.m_Activity, "获取数据失败，请检查网络", Toast.LENGTH_SHORT).show();
	}

};
	public int getUserRank() {
		Log.e(TAG, "Execute getUserRank");
		if(listener.getRanks() != null
				&& listener.getRanks().getOwnRank() != null){
		return listener.getRanks().getOwnRank().getRank();
		}
		return 0;
	}

	public boolean notUnlimetedLives() {
		Date now = new Date();
		int nowtime = preferences.getInt("nowtime", (int) ((now.getTime())/1000));
		int purchasetime = preferences.getInt("purchasetime", (int) ((now.getTime())/1000));
		int timetemp = nowtime - purchasetime;
//		Log.e(TAG, "now:" + nowtime);
//		Log.e(TAG, "purchase:" + purchasetime);
//		Log.e(TAG, "b:" + preferences.getBoolean("b", false));
		if (timetemp <= 604800 && timetemp > 0) {

			return false;
		} else if (timetemp > 604800) {
			editor.putBoolean("b", true);
			editor.commit();
			return true;
		}
		return true;
	}
	public boolean notShared() {
		Date now = new Date();
		int sharenowtime = preferences.getInt("sharenowtime", (int) ((now.getTime())/1000));
		int sharetime = preferences.getInt("sharetime", (int) ((now.getTime())/1000));
		int timetemp = sharenowtime - sharetime;
		Log.e(TAG, "sharenow:" + sharenowtime);
		Log.e(TAG, "sharetime:" + sharetime);
//		Log.e(TAG, "shareb:" + preferences.getBoolean("shareb", false));
		if ((timetemp <= 60 && timetemp > 0)) {
			Log.e(TAG, "notShared:false");
			return false;
		} else if (timetemp > 60) {
			editor.putBoolean("shareb", true);
			editor.commit();
			Log.e(TAG, "notShared:true");
			return true;
		}
		Log.e(TAG, "notShared:true");
		return true;
	}
	
	public void setShareTime() {
		Log.e(TAG,"setShareTime execute" );
		new Thread(new Runnable() {

			@Override
			public void run() {
				boolean b = preferences.getBoolean("shareb", true);
				Log.e(TAG, "shareb:" + b);
				int bjTime = lb.getBeijingTimeSeconds();
				// TODO Auto-generated method stub
				if (bjTime == 0) {
					Log.e(TAG, "系统时间");
					Date now = new Date();
					if (b == true) {
						editor.putInt("sharetime", (int) ((now.getTime())/1000));
						editor.putInt("sharenowtime", (int) ((now.getTime())/1000)+1);
						editor.putBoolean("shareb", false);
					} else {
						if(preferences.getInt("sharenowtime", (int) ((now.getTime())/1000))<=(int) ((now.getTime())/1000)){
						editor.putInt("sharenowtime", (int) ((now.getTime())/1000));
						}
					}
				} else {
					Log.e(TAG, "网络时间"+bjTime);
					if (b == true) {
						Log.e(TAG, "put pref");
						editor.putInt("sharetime",
								bjTime);
						editor.putInt("sharenowtime",
								bjTime+1);
						editor.putBoolean("shareb", false);
					} else {
						
						editor.putInt("sharenowtime", bjTime);
					}
				}
				editor.commit();
			
			}

		}).start();

	}

	public void setBeijingTime() {
		Log.e(TAG,"setBeijingTime execute" );
		new Thread(new Runnable() {

			@Override
			public void run() {
				boolean b = preferences.getBoolean("b", true);
				Log.e(TAG, "b:" + b);
				int bjTime = lb.getBeijingTimeSeconds();
				// TODO Auto-generated method stub
				if (bjTime == 0) {
					Log.e(TAG, "系统时间");
					Date now = new Date();
					if (b == true) {
						editor.putInt("purchasetime", (int) ((now.getTime())/1000));
						editor.putInt("nowtime", (int) ((now.getTime())/1000)+1);
						editor.putBoolean("b", false);
					} else {
						if(preferences.getInt("nowtime", (int) ((now.getTime())/1000))<=(int) ((now.getTime())/1000)){
						editor.putInt("nowtime", (int) ((now.getTime())/1000));
						}
					}
				} else {
					Log.e(TAG, "网络时间"+bjTime);
					if (b == true) {
						Log.e(TAG, "put pref");
						editor.putInt("purchasetime",
								bjTime);
						editor.putInt("nowtime",
								bjTime+1);
						editor.putBoolean("b", false);
					} else {
						
						editor.putInt("nowtime", bjTime);
					}
				}
				editor.commit();
			
			}

		}).start();

	}


/*	private final Runnable m_SetTime = new Runnable() {
		public void run() {
			Log.e(TAG,"m_SetTime" );
				}

	};*/

	public int getNextWeekLeftSeconds() {

		return lb.getNewWeekLeftSeconds();
	}
}
