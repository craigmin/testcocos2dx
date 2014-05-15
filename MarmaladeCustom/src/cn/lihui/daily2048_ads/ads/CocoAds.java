package cn.lihui.daily2048_ads.ads;

import android.content.Context;
import android.util.Log;

import com.adcocoa.sdk.AdcocoaPopupAd;
import com.adcocoa.sdk.AdcocoaPopupAdListener;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.lihui.lihui2048.Lihui2048;

public class CocoAds implements IAds {
	int flag = 0;
	boolean init = true;

	@Override
	public void init() {
		// 代码设置平台ID
		AdcocoaPopupAd.setPlatformId("b0a8f1d76797f66c7c07c2a38b0b7f9e");
		// 这里需要先调用平台的init方法！推荐写在onCreate的第一句。
		AdcocoaPopupAd.init(LoaderActivity.m_Activity);
	}

	@Override
	public void showDoInter() {
		flag = Lihui2048.getInstance().getFlags("cocoads_flag");
		Log.i("", "MobclickAgent.onResume(this);");

		if (!init && flag == 0) {
			AdcocoaPopupAd.open(LoaderActivity.m_Activity,
					new AdcocoaPopupAdListener() {
						@Override
						public void onSucceed() {
							// Toast.makeText(LoaderActivity.m_Activity,
							// "插屏广告展示成功。",
							// Toast.LENGTH_LONG).show();
						}

						@Override
						public void onError(int errorCode, String errorMsg) {
							// // Toast.makeText(LoaderActivity.m_Activity,
							// // "插屏广告打开失败:" + errorCode + "; " + errorMsg,
							// // Toast.LENGTH_LONG).show();
						}
					});
		}
		Lihui2048.getInstance().setFlags("cocoads_flag", flag == 0 ? 1 : 0);
		init = false;
	}

	@Override
	public void destroy(Context c) {
		AdcocoaPopupAd.destroy(c);
	}

}
