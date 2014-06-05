package cn.lihui.ssjjAd;

import android.util.Log;
import android.view.ViewGroup;
import android.widget.RelativeLayout;

import com.ideaworks3d.marmalade.LoaderActivity;
import com.unionsy.sdk.OnSsjjAdsListener;
import com.unionsy.sdk.SsjjAdsManager;
import com.unionsy.sdk.SsjjAdsView;
import com.unionsy.sdk.SsjjPauseScreenManager;

public class lihui2048 {
	SsjjAdsView adView;
	RelativeLayout mAdContainer;
	public native void LihuiSplashSuccessful(String key);

	public native void LihuiSplashFailedCallback(String key);

	public native void LihuiPointSuccessfulCallback(String key);

	public native void LihuiPointFailedCallback(String key);
	
	public native void LihuiConsumeSuccessfulCallback(String key);

	public native void LihuiConsumeFailedCallback(String key);
	void initDoAd(){
		Log.i("Jerry","initDoAd--ssjj");
		SsjjAdsManager.init(LoaderActivity.m_Activity);
		// 预加载插屏广告
		SsjjPauseScreenManager.preLoad(LoaderActivity.m_Activity);
		
	}
	void showDoBanner(){
		Log.i("Jerry","showDoBanner--ssjj");
		if(mAdContainer == null) {
			adView=new SsjjAdsView(LoaderActivity.m_Activity);
			mAdContainer = new RelativeLayout(LoaderActivity.m_Activity);
			RelativeLayout.LayoutParams lp1 = new RelativeLayout.LayoutParams(
					ViewGroup.LayoutParams.FILL_PARENT,
					ViewGroup.LayoutParams.WRAP_CONTENT);
			lp1.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
			mAdContainer.addView(adView, lp1);
			LoaderActivity.m_Activity.addContentView(mAdContainer, new ViewGroup.LayoutParams(-1, -1));
			adView.show();
		}
		
	}
	void showDoInter(){
		Log.i("Jerry","showDoInter--ssjj");
		// 显示插屏广告
		SsjjPauseScreenManager.show(LoaderActivity.m_Activity, 
		                             mOnSsjjAdsListener);
	}
	void showDoSplash(){
		
	}
	void getPoints(){
		
	}
	 void usePoints(int cp){
		 
	 }
	 void checkPoints(){
		 
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

