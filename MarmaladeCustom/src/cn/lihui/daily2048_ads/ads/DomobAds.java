package cn.lihui.daily2048_ads.ads;

import com.ideaworks3d.marmalade.LoaderActivity;

import cn.domob.android.ads.DomobAdManager.ErrorCode;
import cn.domob.android.ads.DomobInterstitialAd;
import cn.domob.android.ads.DomobInterstitialAdListener;
import android.content.Context;
import android.util.Log;

public class DomobAds implements IAds {
	public static final String PUBLISHER_ID = "56OJwtjouNGvRN/O2Q";
	public static final String InlinePPID = "16TLwebvAchksY6iO_8oSb-i";
	public static final String FlexibleInlinePPID = "16TLuh6vAphIcNUk9mQ1oTQi";
	public static final String InterstitialPPID = "16TLuh6vAphIcNUk9ww_079s";
	public static final String SplashPPID = "16TLuh6vAphIcNUk9ozver3z";
	public static final String FeedsPPID = "16TLwebvAchksNUGSZjJXz_k";
	DomobInterstitialAd mInterstitialAd;

	@Override
	public void init() {
		mInterstitialAd = new DomobInterstitialAd(
				LoaderActivity.m_Activity, PUBLISHER_ID, InterstitialPPID,
				DomobInterstitialAd.INTERSITIAL_SIZE_300X250);

		mInterstitialAd
				.setInterstitialAdListener(new DomobInterstitialAdListener() {
					@Override
					public void onInterstitialAdReady() {
						Log.i("DomobSDKDemo", "onAdReady");
					}

					@Override
					public void onLandingPageOpen() {
						Log.i("DomobSDKDemo", "onLandingPageOpen");
					}

					@Override
					public void onLandingPageClose() {
						Log.i("DomobSDKDemo", "onLandingPageClose");
					}

					@Override
					public void onInterstitialAdPresent() {
						Log.i("DomobSDKDemo", "onInterstitialAdPresent");
					}

					@Override
					public void onInterstitialAdDismiss() {
						// Request new ad when the previous interstitial ad
						// was closed.
						mInterstitialAd.loadInterstitialAd();
						Log.i("DomobSDKDemo", "onInterstitialAdDismiss");
					}

					@Override
					public void onInterstitialAdFailed(ErrorCode arg0) {
						Log.i("DomobSDKDemo", "onInterstitialAdFailed");
					}

					@Override
					public void onInterstitialAdLeaveApplication() {
						Log.i("DomobSDKDemo",
								"onInterstitialAdLeaveApplication");

					}

					@Override
					public void onInterstitialAdClicked(
							DomobInterstitialAd arg0) {
						Log.i("DomobSDKDemo", "onInterstitialAdClicked");
					}
				});

		mInterstitialAd.loadInterstitialAd();
	}

	@Override
	public void showDoInter() {
		if (mInterstitialAd == null) {
			init();
		}

		if (mInterstitialAd.isInterstitialAdReady()) {
			mInterstitialAd.showInterstitialAd(LoaderActivity.m_Activity);
		} else {
			Log.i("DomobSDKDemo", "Interstitial Ad is not ready");
			mInterstitialAd.loadInterstitialAd();
		}
	}

	@Override
	public void destroy(Context c) {
	}

}
