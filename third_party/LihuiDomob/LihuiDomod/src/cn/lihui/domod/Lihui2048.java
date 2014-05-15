package cn.lihui.domod;


import com.adcocoa.sdk.AdcocoaPopupAd;
import com.adcocoa.sdk.AdcocoaPopupAdListener;
import com.bodong.dianjinweb.DianJinPlatform;
import com.bodong.dianjinweb.banner.DianJinBanner;
import com.bodong.dianjinweb.banner.DianJinBanner.AnimationType;
import com.bodong.dianjinweb.listener.AppActiveListener;
import com.bodong.dianjinweb.listener.ChannelListener;
import com.bodong.dianjinweb.listener.ConsumeListener;


import com.example.lihuidomod.R;
import com.ideaworks3d.marmalade.LoaderActivity;


import android.app.Activity;
import android.content.Context;
import android.os.Handler;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.RelativeLayout;
import android.widget.Toast;



import cn.domob.android.ads.DomobAdEventListener;
import cn.domob.android.ads.DomobAdView;
import cn.domob.android.ads.DomobInterstitialAd;
import cn.domob.android.ads.DomobInterstitialAdListener;
import cn.domob.android.ads.DomobRTSplashAd;
import cn.domob.android.ads.DomobRTSplashAdListener;

import cn.domob.android.ads.DomobAdManager.ErrorCode;
import cn.domob.android.ads.DomobSplashAd.DomobSplashMode;
import cn.domob.data.OErrorInfo;
import cn.domob.data.OManager;
import cn.domob.data.OManager.ConsumeStatus;

public class Lihui2048 {
	public static final String PUBLISHER_ID = "56OJwtjouNGvRN/O2Q";
	public static final String InlinePPID = "16TLwebvAchksY6iO_8oSb-i";
	public static final String FlexibleInlinePPID = "16TLuh6vAphIcNUk9mQ1oTQi";
	public static final String InterstitialPPID = "16TLuh6vAphIcNUk9ww_079s";
	public static final String SplashPPID = "16TLuh6vAphIcNUk9ozver3z";
	public static final String FeedsPPID = "16TLwebvAchksNUGSZjJXz_k";
	
	public native void LihuiSplashSuccessful(String key);

	public native void LihuiSplashFailedCallback(String key);

	public native void LihuiPointSuccessfulCallback(String key);

	public native void LihuiPointFailedCallback(String key);
	
	public native void LihuiConsumeSuccessfulCallback(String key);

	public native void LihuiConsumeFailedCallback(String key);
	
	
	private OManager mDomobOfferWallManager;
	private  String PublisherID_P = "96ZJ1hlgzeKzzwTBkB";
	 String p="0";
	  int consumeP=0;
	RelativeLayout mAdContainer;
	DomobAdView mAdviewFlexibleAdView;
	DomobRTSplashAd rtSplashAd;
	DomobInterstitialAd mInterstitialAd;
	 DianJinBanner banner;
	
	void initDoAd(){
		//dianjin Init
		DianJinPlatform.initialize(LoaderActivity.m_Activity, 50084,
				"e09656089ccb91efd0e82a4a32cc1152", 1001);
		DianJinPlatform.requestChannelEnable(LoaderActivity.m_Activity,
				new ChannelListener() {

					@Override
					public void onSuccess(boolean enable) {
//						mChannelTextView.setVisibility(View.VISIBLE);
//						mChannelTextView.setText("在线参数，是否在该渠道显示广告=" + enable);
					}

					@Override
					public void onError(int errorCode, String errorMessage) {
//						mChannelTextView.setVisibility(View.GONE);
//						Toast.makeText(getApplicationContext(),
//								"在线参数获取失败，请检查网络！", Toast.LENGTH_SHORT).show();
					}
				});

		DianJinPlatform.setAppActivedListener(new AppActiveListener() {

			@Override
			public void onSuccess(long reward) {
				Toast.makeText(LoaderActivity.m_Activity, "激活成功，奖励金额为：" + reward,
						Toast.LENGTH_SHORT).show();
			}

			@Override
			public void onError(int errorCode, String errorMessage) {
				switch (errorCode) {
				case DianJinPlatform.DIANJIN_NET_ERROR:// 网络不稳定
					Toast.makeText(LoaderActivity.m_Activity, errorMessage,
							Toast.LENGTH_SHORT).show();
					break;
				case DianJinPlatform.DIANJIN_DUPLICATE_ACTIVATION:// 重复激活
					Toast.makeText(LoaderActivity.m_Activity, errorMessage,
							Toast.LENGTH_SHORT).show();
					break;

				case DianJinPlatform.DIANJIN_ADVERTSING_EXPIRED:// 应用已下架
					Toast.makeText(LoaderActivity.m_Activity, errorMessage,
							Toast.LENGTH_SHORT).show();
					break;

				case DianJinPlatform.DIANJIN_ACTIVATION_FAILURE:// 激活失败
					Toast.makeText(LoaderActivity.m_Activity, errorMessage,
							Toast.LENGTH_SHORT).show();
					break;

				default:
					break;
				}
			}
		});
		//keke init
	
		


		
//		mDomobOfferWallManager = new OManager(LoaderActivity.m_Activity,PublisherID_P);
//		mDomobOfferWallManager.setConsumeListener(new OManager.ConsumeListener() {
//			
//			@Override
//			public void onConsumeFailed(
//					final OErrorInfo mDomobOfferWallErrorInfo) {
//				showToast("网络异常，请重试");
//
//			}
//
//			@Override
//			public void onConsumeSucess(final int point, final int consumed, final ConsumeStatus cs) {
//				
//				switch (cs) {
//				case SUCCEED:
////					showToast("消费成功:" + "总积分：" + point + "总消费积分："
////							+ consumed);
//					if(consumeP==1000)showToast("道具炸弹 兑换成功");
//					if(consumeP==2000)showToast("道具重排列 兑换成功");
//					LihuiConsumeSuccessfulCallback(String.valueOf(consumeP));
//					
//					break;
//				case OUT_OF_POINT:
//					showToast("总积分不足，消费失败：" + "总积分：" + point
//							+ "总消费积分：" + consumed);
//					break;
//				case ORDER_REPEAT:
//					showToast("订单号重复，消费失败：" + "总积分：" + point
//							+ "总消费积分：" + consumed);
//					break;
//
//				default:
//					showToast("消费失败");
//					break;
//				}
//			}
//		});
	}
	void showDoBanner(){
		//dianjin
		if(mAdContainer == null) {
		banner = new DianJinBanner(LoaderActivity.m_Activity);
		banner. setAnimationType(AnimationType.ANIMATION_PUSHUP);
		mAdContainer = new RelativeLayout(LoaderActivity.m_Activity);
		RelativeLayout.LayoutParams lp1 = new RelativeLayout.LayoutParams(
				ViewGroup.LayoutParams.FILL_PARENT,
				ViewGroup.LayoutParams.WRAP_CONTENT);
		lp1.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
		mAdContainer.addView(banner, lp1);
		LoaderActivity.m_Activity.addContentView(mAdContainer, new ViewGroup.LayoutParams(-1, -1));
		}
        //mAdContainer.addView(banner);
		
	//final DianJinBanner banner = (DianJinBanner) findViewById(R.id.dianJinBaaner1);
		
		banner.startBanner();
		Log.i("","Jerry--showDoBanner");
//		
//		
//		//LoaderActivity.m_Activity.runOnUiThread(showDoBanner);
//		if(mAdviewFlexibleAdView==null){
//			
//			RelativeLayout.LayoutParams lp1 = new RelativeLayout.LayoutParams(
//					ViewGroup.LayoutParams.FILL_PARENT,
//					ViewGroup.LayoutParams.WRAP_CONTENT);
//			lp1.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
//
//		mAdContainer = new RelativeLayout(LoaderActivity.m_Activity);
//		mAdviewFlexibleAdView = new DomobAdView(LoaderActivity.m_Activity, PUBLISHER_ID, FlexibleInlinePPID, DomobAdView.INLINE_SIZE_FLEXIBLE);
//		mAdviewFlexibleAdView.setKeyword("game");
//		mAdviewFlexibleAdView.setUserGender("male");
//		mAdviewFlexibleAdView.setUserBirthdayStr("2000-08-08");
//		mAdviewFlexibleAdView.setUserPostcode("123456");
//
//		mAdviewFlexibleAdView.setAdEventListener(new DomobAdEventListener() {
//						
//			@Override
//			public void onDomobAdReturned(DomobAdView adView) {
//				Log.i("DomobSDKDemo", "onDomobAdReturned");				
//			}
//
//			@Override
//			public void onDomobAdOverlayPresented(DomobAdView adView) {
//				Log.i("DomobSDKDemo", "overlayPresented");
//			}
//
//			@Override
//			public void onDomobAdOverlayDismissed(DomobAdView adView) {
//				Log.i("DomobSDKDemo", "Overrided be dismissed");				
//			}
//
//			@Override
//			public void onDomobAdClicked(DomobAdView arg0) {
//				Log.i("DomobSDKDemo", "onDomobAdClicked");				
//			}
//
//			@Override
//			public void onDomobAdFailed(DomobAdView arg0, ErrorCode arg1) {
//				Log.i("DomobSDKDemo", "onDomobAdFailed");				
//			}
//
//			@Override
//			public void onDomobLeaveApplication(DomobAdView arg0) {
//				Log.i("DomobSDKDemo", "onDomobLeaveApplication");				
//			}
//
//			@Override
//			public Context onDomobAdRequiresCurrentContext() {
//				return LoaderActivity.m_Activity;
//			}
//		});
//		Log.i("","Jerry--setLayoutParams");
//		//mAdviewFlexibleAdView.setLayoutParams(layoutParams);
//		mAdContainer.addView(mAdviewFlexibleAdView, lp1);
//		LoaderActivity.m_Activity.addContentView(mAdContainer, new ViewGroup.LayoutParams(-1, -1));
//		//mAdContainer.addView(mAdviewFlexibleAdView);
//	}
		}	

	void showDoInter(){

		int flag = com.lihui.lihui2048.Lihui2048.getInstance().getFlags("cocoads_flag");
		com.lihui.lihui2048.Lihui2048.getInstance().setFlags("cocoads_flag", flag == 0 ? 1: 0);
			AdcocoaPopupAd.open(LoaderActivity.m_Activity, new AdcocoaPopupAdListener() {
			@Override
			public void onSucceed() {
//				Toast.makeText(LoaderActivity.m_Activity, "插屏广告展示成功。",
//						Toast.LENGTH_LONG).show();
			}

			@Override
			public void onError(int errorCode, String errorMsg) {
//				Toast.makeText(LoaderActivity.m_Activity,
//						"插屏广告打开失败:" + errorCode + "; " + errorMsg,
//						Toast.LENGTH_LONG).show();
			}
		});
		
//		if(mInterstitialAd==null){
//		mInterstitialAd = new DomobInterstitialAd(LoaderActivity.m_Activity, PUBLISHER_ID,
//				InterstitialPPID, DomobInterstitialAd.INTERSITIAL_SIZE_300X250);
//		
//		mInterstitialAd.setInterstitialAdListener(new DomobInterstitialAdListener() {
//			@Override
//			public void onInterstitialAdReady() {
//				Log.i("DomobSDKDemo", "onAdReady");
//			}
//
//			@Override
//			public void onLandingPageOpen() {
//				Log.i("DomobSDKDemo", "onLandingPageOpen");
//			}
//
//			@Override
//			public void onLandingPageClose() {
//				Log.i("DomobSDKDemo", "onLandingPageClose");
//			}
//
//			@Override
//			public void onInterstitialAdPresent() {
//				Log.i("DomobSDKDemo", "onInterstitialAdPresent");
//			}
//
//			@Override
//			public void onInterstitialAdDismiss() {
//				// Request new ad when the previous interstitial ad was closed.
//				mInterstitialAd.loadInterstitialAd();
//				Log.i("DomobSDKDemo", "onInterstitialAdDismiss");
//			}
//
//			@Override
//			public void onInterstitialAdFailed(ErrorCode arg0) {
//				Log.i("DomobSDKDemo", "onInterstitialAdFailed");				
//			}
//
//			@Override
//			public void onInterstitialAdLeaveApplication() {
//				Log.i("DomobSDKDemo", "onInterstitialAdLeaveApplication");
//				
//			}
//
//			@Override
//			public void onInterstitialAdClicked(DomobInterstitialAd arg0) {
//				Log.i("DomobSDKDemo", "onInterstitialAdClicked");
//			}
//		});
//		
//		mInterstitialAd.loadInterstitialAd();
//		}
//		if (mInterstitialAd.isInterstitialAdReady()){
//			mInterstitialAd.showInterstitialAd(LoaderActivity.m_Activity);
//		} else {
//			Log.i("DomobSDKDemo", "Interstitial Ad is not ready");
//			mInterstitialAd.loadInterstitialAd();
//		}
	}
	void showDoSplash(){
		
	
////			Real-time splash ad
//			rtSplashAd = new DomobRTSplashAd(LoaderActivity.m_Activity, PUBLISHER_ID, SplashPPID,
//					DomobSplashMode.DomobSplashModeFullScreen);
////		    setRTSplashTopMargin is available when you choose non-full-screen splash mode.
////			rtSplashAd.setRTSplashTopMargin(200);
//			rtSplashAd.setRTSplashAdListener(new DomobRTSplashAdListener() {
//				@Override
//				public void onRTSplashDismiss() {
//					Log.i("DomobSDKDemo", "onRTSplashClosed");
////					 开屏回调被关闭时，立即进行界面跳转，从开屏界面到主界面。
////					When rtSplash ad is closed, jump to the next(main) Activity immediately.
//					//jump();
//					LihuiSplashSuccessful("");
////					如果应用没有单独的闪屏Activity，需要调用closeRTSplash方法去关闭开屏广告
////					If you do not carry a separate advertising activity, you need to call closeRTSplash way to close the splash ad
//					
//					rtSplashAd.closeRTSplash();
//				}
//
//				@Override
//				public void onRTSplashLoadFailed() {
//					Log.i("DomobSDKDemo", "onRTSplashLoadFailed");
//					LihuiSplashFailedCallback("");
//				}
//
//				@Override
//				public void onRTSplashPresent() {
//					Log.i("DomobSDKDemo", "onRTSplashStart");
//				}
//				
//			});
//			
//			new Handler().postDelayed(new Runnable() {
//				@Override
//				public void run() {
//					RelativeLayout mAdContainer1 = new RelativeLayout(LoaderActivity.m_Activity);
//					RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
//							ViewGroup.LayoutParams.FILL_PARENT,
//							ViewGroup.LayoutParams.FILL_PARENT);
//					mAdContainer1.setLayoutParams(params);
//					LoaderActivity.m_Activity.addContentView(mAdContainer1,
//							new ViewGroup.LayoutParams(-1, -1));
//					rtSplashAd.splash(LoaderActivity.m_Activity,mAdContainer1);
//				}
//			}, 1);
//		
	}
//	private final Runnable showDoBanner = new Runnable() {
//		public void run() {
//			if(mAdviewFlexibleAdView==null){
//				
//				RelativeLayout.LayoutParams lp1 = new RelativeLayout.LayoutParams(
//						ViewGroup.LayoutParams.FILL_PARENT,
//						ViewGroup.LayoutParams.WRAP_CONTENT);
//				lp1.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
//
//			mAdContainer = new RelativeLayout(LoaderActivity.m_Activity);
//			mAdviewFlexibleAdView = new DomobAdView(LoaderActivity.m_Activity, PUBLISHER_ID, FlexibleInlinePPID, DomobAdView.INLINE_SIZE_FLEXIBLE);
//			mAdviewFlexibleAdView.setKeyword("game");
//			mAdviewFlexibleAdView.setUserGender("male");
//			mAdviewFlexibleAdView.setUserBirthdayStr("2000-08-08");
//			mAdviewFlexibleAdView.setUserPostcode("123456");
//
//			mAdviewFlexibleAdView.setAdEventListener(new DomobAdEventListener() {
//							
//				@Override
//				public void onDomobAdReturned(DomobAdView adView) {
//					Log.i("DomobSDKDemo", "onDomobAdReturned");				
//				}
//
//				@Override
//				public void onDomobAdOverlayPresented(DomobAdView adView) {
//					Log.i("DomobSDKDemo", "overlayPresented");
//				}
//
//				@Override
//				public void onDomobAdOverlayDismissed(DomobAdView adView) {
//					Log.i("DomobSDKDemo", "Overrided be dismissed");				
//				}
//
//				@Override
//				public void onDomobAdClicked(DomobAdView arg0) {
//					Log.i("DomobSDKDemo", "onDomobAdClicked");				
//				}
//
//				@Override
//				public void onDomobAdFailed(DomobAdView arg0, ErrorCode arg1) {
//					Log.i("DomobSDKDemo", "onDomobAdFailed");				
//				}
//
//				@Override
//				public void onDomobLeaveApplication(DomobAdView arg0) {
//					Log.i("DomobSDKDemo", "onDomobLeaveApplication");				
//				}
//
//				@Override
//				public Context onDomobAdRequiresCurrentContext() {
//					return LoaderActivity.m_Activity;
//				}
//			});
//			Log.i("","Jerry--setLayoutParams");
//			//mAdviewFlexibleAdView.setLayoutParams(layoutParams);
//			mAdContainer.addView(mAdviewFlexibleAdView, lp1);
//			LoaderActivity.m_Activity.addContentView(mAdContainer, new ViewGroup.LayoutParams(-1, -1));
//			//mAdContainer.addView(mAdviewFlexibleAdView);
//		}}
//	};
	
	void getPoints(){
		DianJinPlatform.showOfferWall(LoaderActivity.m_Activity);
		
//		mDomobOfferWallManager.setAddWallListener(new OManager.AddWallListener() {
//
//			@Override
//			public void onAddWallFailed(
//					OErrorInfo mDomobOfferWallErrorInfo) {
//
//				showToast("网络异常，请重试");
//			}
//
//			@Override
//			public void onAddWallClose() {
//				//此处可以设置为横屏...
//			}
//
//			@Override
//			public void onAddWallSucess() {
//
//			}
//		});
//		mDomobOfferWallManager.loadOfferWall();
	}
	 void usePoints(int cp){
		 
		 consumeP=cp;

		 DianJinPlatform.consume(LoaderActivity.m_Activity, cp,
					new ConsumeListener() {

						@Override
						public void onSuccess() {
							
							
							if(consumeP==1000)showToast("道具炸弹 兑换成功");
							if(consumeP==2000)showToast("道具重排列 兑换成功");
							LihuiConsumeSuccessfulCallback(String.valueOf(consumeP));
						}

						@Override
						public void onError(int errorCode,
								String errorMessage) {
							switch (errorCode) {
							case DianJinPlatform.DIANJIN_ERROR_ILLEGAL_CONSUNE://非法的消费金额
								Toast.makeText(LoaderActivity.m_Activity,
										errorMessage,
										Toast.LENGTH_SHORT).show();
								break;
							case DianJinPlatform.DIANJIN_ERROR_BALANCE_NO_ENOUGH://余额不足
								Toast.makeText(LoaderActivity.m_Activity,
										errorMessage,
										Toast.LENGTH_SHORT).show();
							default:
								break;
							}
						}
					});

		
	}
	void checkPoints(){
		LihuiPointSuccessfulCallback(String.valueOf(DianJinPlatform
				.getBalance(LoaderActivity.m_Activity)));
//		mDomobOfferWallManager.setCheckPointsListener(new OManager.CheckPointsListener() {
//    
//			@Override
//			public void onCheckPointsSucess(final int point,
//					final int consumed) {
//				showToast("当前积分： "+ String.valueOf(point-consumed));
//				//showText("总积分：" + point + "总消费积分：" + consumed);
//				Log.i("","Jerry"+String.valueOf(point-consumed));
//				LihuiPointSuccessfulCallback(String.valueOf(point-consumed));
//			}
//
//			@Override
//			public void onCheckPointsFailed(
//					final OErrorInfo mDomobOfferWallErrorInfo) {
//				showToast("网络异常，请重试");
//			}
//		});
//		mDomobOfferWallManager.checkPoints();	
//		
	   }
	public void showToast(final String content) {
		LoaderActivity.m_Activity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				Toast.makeText(LoaderActivity.m_Activity, content, Toast.LENGTH_SHORT).show();
			}
		});
	}
}
   

