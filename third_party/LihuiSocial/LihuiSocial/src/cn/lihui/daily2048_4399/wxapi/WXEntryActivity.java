/**
 * Craig: 根据游戏的包名（package name）修改这个包名 
 * 
 */
package cn.lihui.daily2048_4399.wxapi;



import java.util.Date;

import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.util.Log;
//import android.util.log;
import android.widget.Toast;

import cn.lihui.sdk.Leaderboards;

import com.ideaworks3d.marmalade.LoaderActivity;
import com.lihui.social4wx.Constants;
import com.lihui.social4wx.LihuiSocial;
//import com.lihui.social4wx.SendToWXActivity;
import com.tencent.mm.sdk.openapi.BaseReq;
import com.tencent.mm.sdk.openapi.BaseResp;
import com.tencent.mm.sdk.openapi.IWXAPI;
import com.tencent.mm.sdk.openapi.IWXAPIEventHandler;
import com.tencent.mm.sdk.openapi.WXAPIFactory;
import com.umeng.analytics.MobclickAgent;

public class WXEntryActivity extends Activity implements IWXAPIEventHandler{
	private IWXAPI wxApi;
	public static LihuiSocial lihuiSocial;
    public static SharedPreferences preferences;
    private static Editor editor;
    private static Leaderboards lb;
    private final static String TAG = "LihuiLB";
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		wxApi = WXAPIFactory.createWXAPI(this, Constants.APP_ID, false);
		Log.i("WXEntryActivity","Jerry--start");

		//startActivity(new Intent(WXEntryActivity.this, SendToWXActivity.class));
//		 preferences=getSharedPreferences("countkit",MODE_WORLD_READABLE);
//		 editor=preferences.edit();
		 //log.e("WXEntryActivity","execute startactivty");
		 finish();
		wxApi.handleIntent(getIntent(), this);
		
		//log.e("handleIntent","execute");
    }

	@Override
	protected void onNewIntent(Intent intent) {
		super.onNewIntent(intent);
		
		setIntent(intent);
		wxApi.handleIntent(intent, this);
	}
	

	@Override
	public void onReq(BaseReq arg0) {
		//log.e("Callback","Req Start");
		
	}
	
	private static SharedPreferences getPreferences(){
		if(preferences == null){
			preferences=LoaderActivity.m_Activity.getSharedPreferences("countkit",LoaderActivity.m_Activity.MODE_WORLD_READABLE);
		}
		
		return preferences;
	}

	private static Editor getEditor(){
		if(editor == null){
			editor= getPreferences().edit();
		}
		
		return editor;
	}

	public static int getCount(){
		lb = Leaderboards.getInstance().init(LoaderActivity.m_Activity);
		Date now = new Date();
		int sharenowtime = getPreferences().getInt("sharenowtime", (int) ((now.getTime())/1000));
		int sharetime = getPreferences().getInt("sharetime", (int) ((now.getTime())/1000));
		int timetemp = sharenowtime - sharetime;
		////log.e(TAG, "sharenow:" + sharenowtime);
		////log.e(TAG, "sharetime:" + sharetime);
//		//log.e(TAG, "shareb:" + getPreferences().getBoolean("shareb", false));
		if ((timetemp <= 86400&& timetemp > 0)) {
			////log.e(TAG+"0-60", "count"+getPreferences().getInt("count",0));
			return getPreferences().getInt("count",0);
		} else if (timetemp > 86400) {
			
			getEditor().putBoolean("shareb", true);
			getEditor().putInt("count", 0);
			getEditor().commit();
			////log.e(TAG+">60", "count"+getPreferences().getInt("count",0));
			return getPreferences().getInt("count",0);
		}
		////log.e(TAG+"=0", "count"+getPreferences().getInt("count",0));
		return getPreferences().getInt("count",0);
		
}
	public static void setShareTime() {
		////log.e(TAG,"setShareTime execute" );
		//final getEditor(getEditor()or= getPreferences().edit();
		new Thread(new Runnable() {

			@Override
			public void run() {
				boolean b = getPreferences().getBoolean("shareb", true);
				//log.e(TAG, "shareb:" + b);
				int bjTime = lb.getBeijingTimeSeconds();
				// TODO Auto-generated method stub
				//log.e(TAG, "set bjTime");
				if (bjTime == 0) {
					//log.e(TAG, "系统时间");
					Date now = new Date();
					if (b == true) {
						getEditor().putInt("sharetime", (int) ((now.getTime())/1000));
						getEditor().putInt("sharenowtime", (int) ((now.getTime())/1000)+1);
						getEditor().putBoolean("shareb", false);
					} else {
						if(getPreferences().getInt("sharenowtime", (int) ((now.getTime())/1000))<=(int) ((now.getTime())/1000)){
						getEditor().putInt("sharenowtime", (int) ((now.getTime())/1000));
						}
					}
				} else {
					//log.e(TAG, "网络时间"+bjTime);
					if (b == true) {
						//log.e(TAG, "put pref");
						getEditor().putInt("sharetime",
								bjTime);
						getEditor().putInt("sharenowtime",
								bjTime+1);
						getEditor().putBoolean("shareb", false);
					} else {
						
						getEditor().putInt("sharenowtime", bjTime);
					}
				}
				getEditor().commit();
			
			}

		}).start();

	}
	@Override
	public void onResp(BaseResp resp) {
		//int count=getCount();
		////log.e("Callback","Resp Start");
		switch (resp.errCode) {
		case BaseResp.ErrCode.ERR_OK:
			Toast.makeText(LoaderActivity.m_Activity, "成功分享", Toast.LENGTH_LONG).show();
			//if(count==0){
				////log.e(TAG,"分享成功count:");
				MobclickAgent.onEvent(LoaderActivity.m_Activity,"onShareSuccess");
//			lihuiSocial.LihuiSocialShareSuccessful("");
//			count++;
//			
//			getEditor().putInt("count",count++);
//			getEditor().commit();   
//			}
			////log.e(TAG,"死循环count:");
		break;
		case BaseResp.ErrCode.ERR_USER_CANCEL:
			Toast.makeText(LoaderActivity.m_Activity, "取消分享", Toast.LENGTH_LONG).show();
			MobclickAgent.onEvent(LoaderActivity.m_Activity,"onShareFailed");
			//lihuiSocial.LihuiSocialShareFailed("");
			break;
		case BaseResp.ErrCode.ERR_AUTH_DENIED:
			Toast.makeText(LoaderActivity.m_Activity, "认证错误", Toast.LENGTH_LONG).show();
			MobclickAgent.onEvent(LoaderActivity.m_Activity,"onShareFailed");
			//lihuiSocial.LihuiSocialShareFailed("");
			break;
		default:
			Toast.makeText(LoaderActivity.m_Activity, "未知错误", Toast.LENGTH_LONG).show();
			MobclickAgent.onEvent(LoaderActivity.m_Activity,"onShareFailed");
			//lihuiSocial.LihuiSocialShareFailed("");
			break;
		}
		//Toast.makeText(WXEntryActivity.this, "成功分享", Toast.LENGTH_LONG).show();
		////log.e(TAG,"finish count:");
		finish();
	}
}
