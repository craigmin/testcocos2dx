/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
package cn.lihui.daily2048_ads;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;



import cn.lihui.iap.mm.LihuiInAppPurchase;

import com.adcocoa.sdk.AdcocoaPopupAd;
import com.adcocoa.sdk.AdcocoaPopupAdListener;
import com.estore.lsms.tools.ApiParameter;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.lihui.lihui2048.Lihui2048;
import com.umeng.analytics.MobclickAgent;

public class LihuiMain extends com.ideaworks3d.marmalade.LoaderActivity
{
	//Jerry Test
	public static final String PUBLISHER_ID = "56OJwtjouNGvRN/O2Q";
	public static final String InlinePPID = "16TLwebvAchksY6iO_8oSb-i";
	public static final String FlexibleInlinePPID = "16TLuh6vAphIcNUk9mQ1oTQi";
	public static final String InterstitialPPID = "16TLuh6vAphIcNUk9ww_079s";
	public static final String SplashPPID = "16TLuh6vAphIcNUk9ozver3z";
	public static final String FeedsPPID = "16TLwebvAchksNUGSZjJXz_k";
	//DomobInterstitialAd mInterstitialAd;
	private SharedPreferences mSharedPreferences;
	int flag=0;
	boolean init=true;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// 代码设置平台ID
		AdcocoaPopupAd.setPlatformId("b0a8f1d76797f66c7c07c2a38b0b7f9e");
		// 这里需要先调用平台的init方法！推荐写在onCreate的第一句。
		AdcocoaPopupAd.init(LoaderActivity.m_Activity);
		
	}
		protected void onPause()
		{
			super.onPause();
			MobclickAgent.onPause(this);
			//showDoInter();
			
		}
		protected void onRestart(){
			//showDoInter();
			super.onRestart();
		}
		
		protected void onResume()
		{
			super.onResume();
			flag=Lihui2048.getInstance().getFlags("cocoads_flag");
			//long now=System.currentTimeMillis();
			Log.i("","MobclickAgent.onResume(this);");

		MobclickAgent.onResume(this);
			if(!init && flag == 0)
			showDoInter();
			Lihui2048.getInstance().setFlags("cocoads_flag", flag == 0 ? 1: 0);
			init = false;
		}
		@Override
		protected void onDestroy() {
			// 这里需要调用平台的destroy方法！释放相关资源。
			//AdcocoaPopupAd.destroy(this);
			super.onDestroy();
		}
		void showDoInter(){
			
			AdcocoaPopupAd.open(LoaderActivity.m_Activity, new AdcocoaPopupAdListener() {
				@Override
				public void onSucceed() {
//					Toast.makeText(LoaderActivity.m_Activity, "插屏广告展示成功。",
//							Toast.LENGTH_LONG).show();
				}

				@Override
				public void onError(int errorCode, String errorMsg) {
////					Toast.makeText(LoaderActivity.m_Activity,
////							"插屏广告打开失败:" + errorCode + "; " + errorMsg,
////							Toast.LENGTH_LONG).show();
				}
			});
//			if(mInterstitialAd==null){
//			mInterstitialAd = new DomobInterstitialAd(LoaderActivity.m_Activity, PUBLISHER_ID,
//					InterstitialPPID, DomobInterstitialAd.INTERSITIAL_SIZE_300X250);
//			
//			mInterstitialAd.setInterstitialAdListener(new DomobInterstitialAdListener() {
//				@Override
//				public void onInterstitialAdReady() {
//					Log.i("DomobSDKDemo", "onAdReady");
//				}
//
//				@Override
//				public void onLandingPageOpen() {
//					Log.i("DomobSDKDemo", "onLandingPageOpen");
//				}
//
//				@Override
//				public void onLandingPageClose() {
//					Log.i("DomobSDKDemo", "onLandingPageClose");
//				}
//
//				@Override
//				public void onInterstitialAdPresent() {
//					Log.i("DomobSDKDemo", "onInterstitialAdPresent");
//				}
//
//				@Override
//				public void onInterstitialAdDismiss() {
//					// Request new ad when the previous interstitial ad was closed.
//					mInterstitialAd.loadInterstitialAd();
//					Log.i("DomobSDKDemo", "onInterstitialAdDismiss");
//				}
//
//				@Override
//				public void onInterstitialAdFailed(ErrorCode arg0) {
//					Log.i("DomobSDKDemo", "onInterstitialAdFailed");				
//				}
//
//				@Override
//				public void onInterstitialAdLeaveApplication() {
//					Log.i("DomobSDKDemo", "onInterstitialAdLeaveApplication");
//					
//				}
//
//				@Override
//				public void onInterstitialAdClicked(DomobInterstitialAd arg0) {
//					Log.i("DomobSDKDemo", "onInterstitialAdClicked");
//				}
//			});
//			
//			mInterstitialAd.loadInterstitialAd();
//			}
//			if (mInterstitialAd.isInterstitialAdReady()){
//				mInterstitialAd.showInterstitialAd(LoaderActivity.m_Activity);
//			} else {
//				Log.i("DomobSDKDemo", "Interstitial Ad is not ready");
//				mInterstitialAd.loadInterstitialAd();
//			}
		}
//		@Override
//	    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
//			if(requestCode == 100){
//				Log.i("Jerry","onActivityResult");
//				   Bundle bdl = data.getExtras();
//			        int payResultCode = bdl.getInt(ApiParameter.RESULTCODE);
//        
//	      
//					String itemtype= LihuiInAppPurchase.getPreferences().getString("itemtype","");
//			        Log.i("","Jerry"+itemtype);
//			        //Log.i("Jerry","Jerry Succeed");
//			        if (ApiParameter.CTESTORE_SENDSUCCESS == payResultCode
//			        	||ApiParameter.CTESTORE_SENDTIMEOUT == payResultCode)
//			        		        {
//			        	Toast.makeText(LoaderActivity.m_Activity, "购买成功", Toast.LENGTH_SHORT)
//						.show();
//			        	LihuiInAppPurchase.getInstance().LihuiInAppPurchaseSuccessful("com.ximad.bubblebirds3.inapp."+itemtype);
//			        	MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchaseSucceed","TE:com.ximad.bubblebirds3.inapp."+itemtype);	
//			        	//LihuiInAppPurchase.instanse.LihuiInAppPurchaseSuccessful("com.ximad.bubblebirds3.inapp."+LihuiInAppPurchase.instanse.mPurchaseItem.type);
//			       	 
//		        	 Log.i("pay-success",bdl.getString(ApiParameter.REQUESTID));
//			        }
//			        else
//			        {
//			        	//LihuiInAppPurchase.LihuiInAppFailedCallBack();
//			        	 Toast.makeText(LoaderActivity.m_Activity, "购买失败", Toast.LENGTH_SHORT)
//							.show();
//			        	 MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchaseFail",itemtype);	
//			        }
//			
//		       
//			} else {
//				super.onActivityResult(requestCode, resultCode, data);
//			}
//	    }
}
