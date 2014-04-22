package cn.lihui.cocos2dx;

import java.util.Date;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.regex.PatternSyntaxException;

import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.graphics.Color;
import android.text.Editable;
import android.text.InputFilter;
import android.text.InputType;
import android.text.TextWatcher;
import android.util.Log;
import android.view.KeyEvent;
import android.view.ViewGroup.LayoutParams;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;
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
//			Log.e(TAG, "Execute getScore" + rank);
			return listener.getRanks().getRanks().get(rank - 1).getScore();
		} else if (rank == 1) {
			LoaderActivity.m_Activity.runOnUiThread(m_Purchase);
		}
//		Log.e(TAG, "Execute getScore" + rank);
		return 0;
	}

	public String getNicknameByRank(int rank) {
		if (rank == -1) {
			return getNickname();
		} else if (listener.getRanks() != null
				&& listener.getRanks().getRanks() != null
				&& listener.getRanks().getRanks().size() >= rank) {
//			Log.e(TAG, "Execute getNickname" + rank);
			return listener.getRanks().getRanks().get(rank - 1).getNickname();
		} else if (rank == 1) {
			LoaderActivity.m_Activity.runOnUiThread(m_Purchase);
		}
//		Log.e(TAG, "Execute getNickname" + rank);
		return "";
	}

	private final Runnable m_Purchase = new Runnable() {
		public void run() {
			Toast.makeText(LoaderActivity.m_Activity, "获取数据失败，请检查网络",
					Toast.LENGTH_SHORT).show();
		}

	};

	public int getUserRank() {
		Log.e(TAG, "Execute getUserRank");
		if (listener.getRanks() != null
				&& listener.getRanks().getOwnRank() != null) {
			return listener.getRanks().getOwnRank().getRank();
		}
		return 0;
	}

	public boolean notUnlimetedLives() {
		Date now = new Date();
		int nowtime = preferences.getInt("nowtime",
				(int) ((now.getTime()) / 1000));
		int purchasetime = preferences.getInt("purchasetime",
				(int) ((now.getTime()) / 1000));
		int timetemp = nowtime - purchasetime;
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
		int sharenowtime = preferences.getInt("sharenowtime",
				(int) ((now.getTime()) / 1000));
		int sharetime = preferences.getInt("sharetime",
				(int) ((now.getTime()) / 1000));
		int timetemp = sharenowtime - sharetime;
//		Log.e(TAG, "sharenow:" + sharenowtime);
//		Log.e(TAG, "sharetime:" + sharetime);
		if ((timetemp <= 60 && timetemp > 0)) {
			Log.e(TAG, "notShared:false");
			return false;
		} else if (timetemp > 60) {
			editor.putBoolean("shareb", true);
			editor.commit();
//			Log.e(TAG, "notShared:true");
			return true;
		}
//		Log.e(TAG, "notShared:true");
		return true;
	}

	public void setShareTime() {
		Log.e(TAG, "setShareTime execute");
		new Thread(new Runnable() {

			@Override
			public void run() {
				boolean b = preferences.getBoolean("shareb", true);
				Log.e(TAG, "shareb:" + b);
				int bjTime = lb.getBeijingTimeSeconds();
				if (bjTime == 0) {
					Log.e(TAG, "系统时间");
					Date now = new Date();
					if (b == true) {
						editor.putInt("sharetime",
								(int) ((now.getTime()) / 1000));
						editor.putInt("sharenowtime",
								(int) ((now.getTime()) / 1000) + 1);
						editor.putBoolean("shareb", false);
					} else {
						if (preferences.getInt("sharenowtime",
								(int) ((now.getTime()) / 1000)) <= (int) ((now
								.getTime()) / 1000)) {
							editor.putInt("sharenowtime",
									(int) ((now.getTime()) / 1000));
						}
					}
				} else {
					Log.e(TAG, "网络时间" + bjTime);
					if (b == true) {
						Log.e(TAG, "put pref");
						editor.putInt("sharetime", bjTime);
						editor.putInt("sharenowtime", bjTime + 1);
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
		Log.e(TAG, "setBeijingTime execute");
		new Thread(new Runnable() {

			@Override
			public void run() {
				boolean b = preferences.getBoolean("b", true);
				Log.e(TAG, "b:" + b);
				int bjTime = lb.getBeijingTimeSeconds();
				if (bjTime == 0) {
					Log.e(TAG, "系统时间");
					Date now = new Date();
					if (b == true) {
						editor.putInt("purchasetime",
								(int) ((now.getTime()) / 1000));
						editor.putInt("nowtime",
								(int) ((now.getTime()) / 1000) + 1);
						editor.putBoolean("b", false);
					} else {
						if (preferences.getInt("nowtime",
								(int) ((now.getTime()) / 1000)) <= (int) ((now
								.getTime()) / 1000)) {
							editor.putInt("nowtime",
									(int) ((now.getTime()) / 1000));
						}
					}
				} else {
					Log.e(TAG, "网络时间" + bjTime);
					if (b == true) {
						Log.e(TAG, "put pref");
						editor.putInt("purchasetime", bjTime);
						editor.putInt("nowtime", bjTime + 1);
						editor.putBoolean("b", false);
					} else {

						editor.putInt("nowtime", bjTime);
					}
				}
				editor.commit();

			}

		}).start();

	}

	public int getNextWeekLeftSeconds() {
		return lb.getNewWeekLeftSeconds();
	}

	@SuppressLint("NewApi")
	public void updateNickname(String nickname) {
		AlertDialog.Builder builder = new AlertDialog.Builder(
				LoaderActivity.m_Activity).setTitle("请输入游戏昵称").setIcon(
				android.R.drawable.ic_dialog_info);
		final EditText mEditText = new EditText(LoaderActivity.m_Activity);
		mEditText.setHint("匿名玩家");
		String nn = getNickname();
		if(!"匿名玩家".equals(nn)) {
			mEditText.setText(nn);
		}
		mEditText.addTextChangedListener(new TextWatcher() {
			private int cou = 0;
			int mMaxLenth = 7;
			private String lastStr = "";

			@Override
			public void afterTextChanged(Editable s) {
				String str = s.toString();
				if (cou > mMaxLenth && !lastStr.equals(str)) {
					
					StringBuffer strBf = new StringBuffer("");
					
					int length = 0;
					for(int i =0; i<str.length();i++){
						String c = str.substring(i, i+1);
						
						if(1 == c.getBytes().length) {
							length++;
						} else if (1 < c.getBytes().length){
							length +=2;
						}

						if(length > mMaxLenth*2) {
							break;
						}

						strBf.append(c);
					}
					lastStr = strBf.toString();
					mEditText.setText(lastStr);
				}
			}

			@Override
			public void beforeTextChanged(CharSequence s, int start, int count,
					int after) {

			}

			@Override
			public void onTextChanged(CharSequence s, int start, int before,
					int count) {
				cou = before + count;
				String editable = mEditText.getText().toString();
				String str = stringFilter(editable);
				if (!editable.equals(str)) {
					mEditText.setText(str);
				}

				mEditText.setSelection(mEditText.length());
				cou = mEditText.length();
			}

			public String stringFilter(String str)
					throws PatternSyntaxException {
				String regEx = "[/\\:?\"\', \n\t]";
				Pattern p = Pattern.compile(regEx);
				Matcher m = p.matcher(str);
				return m.replaceAll("");
			}
		});

		builder.setView(mEditText);
		builder.setPositiveButton("确定", new OnClickListener() {
			@Override
			public void onClick(DialogInterface dialog, int which) {
				 lb.updateNickName(mEditText.getText().toString());
			}

		});
		builder.setNegativeButton("取消", null);

		Dialog dialog = builder.create();
		dialog.show();
	}

	public String getNickname() {
		return lb.getNickName();
	}
}
