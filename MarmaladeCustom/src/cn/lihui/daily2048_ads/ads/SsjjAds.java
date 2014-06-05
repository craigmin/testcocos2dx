package cn.lihui.daily2048_ads.ads;

import com.ideaworks3d.marmalade.LoaderActivity;
import com.unionsy.sdk.OnSsjjAdsListener;
import com.unionsy.sdk.SsjjPauseScreenManager;

import android.content.Context;
import android.util.Log;

public class SsjjAds implements IAds{

	@Override
	public void init() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void showDoInter() {
		// TODO Auto-generated method stub
		// 显示插屏广告
				SsjjPauseScreenManager.show(LoaderActivity.m_Activity, 
				                             mOnSsjjAdsListener);
	}

	@Override
	public void destroy(Context c) {
		// TODO Auto-generated method stub
		
	}
	 private OnSsjjAdsListener mOnSsjjAdsListener = new OnSsjjAdsListener() {
			@Override
			public void onShow() {
				//广告正常显示时调用 
				Log.i("Jerry", "展示成功");
			}

			@Override
			public void onShowFailed() {
				// 显示广告失败的时候调用。
				Log.i("Jerry", "展示失败");
			}

			@Override
			public void onDismiss() {
				// 广告消失时调用
				Log.i("Jerry", "关闭展示");
			}
		};

}
