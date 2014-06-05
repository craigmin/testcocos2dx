package com.lihui.social4wx;



import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.concurrent.CountDownLatch;




import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.Bitmap.CompressFormat;
import android.os.Looper;
import android.util.Log;
import android.widget.Toast;












import cn.lihui.daily2048_4399.wxapi.WXEntryActivity;

import com.ideaworks3d.marmalade.LoaderActivity;

import com.tencent.mm.sdk.openapi.IWXAPI;
import com.tencent.mm.sdk.openapi.SendMessageToWX;
import com.tencent.mm.sdk.openapi.WXAPIFactory;
import com.tencent.mm.sdk.openapi.WXAppExtendObject;
import com.tencent.mm.sdk.openapi.WXImageObject;
import com.tencent.mm.sdk.openapi.WXMediaMessage;
import com.tencent.mm.sdk.openapi.WXTextObject;
import com.tencent.mm.sdk.platformtools.BackwardSupportUtil.BitmapFactory;
import com.umeng.analytics.MobclickAgent;

public class LihuiSocial {
	private IWXAPI wxApi;
	SharedPreferences.Editor editor;
	private static final int THUMB_SIZE = 50;
	private static final int TIMELINE_SUPPORTED_VERSION = 0x21020001;
	public native void LihuiSocialShareSuccessful(String key);

	public native void LihuiSocialShareFailed(String key);

	private void connectToWX(){
		Log.e("Wx", "Connect Start");
		WXEntryActivity.lihuiSocial = this;
		MobclickAgent.onEvent(LoaderActivity.m_Activity,"ShareToWx");
		LoaderActivity.m_Activity.startActivity(new Intent(LoaderActivity.m_Activity, SendToWXActivity.class));
			}

	public void sendMessageOnWX() {
		Log.e("Jerry", "setShareTime execute");
		WXEntryActivity.setShareTime();	
		}
	
	public int isWXLoggedIn(){
	//	Log.e("注意Count",String.valueOf(WXEntryActivity.getCount()));
		Log.e("Jerry isWXLoggedIn()", "count:"+WXEntryActivity.getCount());
		return WXEntryActivity.getCount();
	}

	private void InitWX(){
		Log.e("微信","调用Send方法");
		//int wxSdkVersion = wxApi.getWXAppSupportAPI();
		//if (wxSdkVersion >= TIMELINE_SUPPORTED_VERSION) {
			Log.e("微信","当前版本支持朋友圈");
			wxApi = WXAPIFactory.createWXAPI(LoaderActivity.m_Activity, Constants.APP_ID, true);
			wxApi.registerApp(Constants.APP_ID);
			String text = "测试";
			// 初始化一个WXTextObject对象
			WXTextObject textObj = new WXTextObject();
			textObj.text = text; 
			// 用WXTextObject对象初始化一个WXMediaMessage对象
			WXMediaMessage msg = new WXMediaMessage(textObj);
			
			Bitmap bmp = null;
			try {
				bmp = BitmapFactory.decodeStream(LoaderActivity.m_Activity.getAssets().open("BB3Share.jpg"));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}	
			final WXAppExtendObject appdata = new WXAppExtendObject();
			appdata.fileData = bmpToByteArray(bmp, true);
			appdata.extInfo = "this is ext info";                          
			//msg.mediaObject = appdata;	
			WXImageObject image=new WXImageObject(bmp);
//			Bitmap thumbBmp = Bitmap.createScaledBitmap(bmp, THUMB_SIZE, THUMB_SIZE, true);
			bmp.recycle();
			msg.mediaObject=image;
//			msg.thumbData = bmpToByteArray(thumbBmp, true);  // 设置缩略图
			msg.title = "肥鸟大漂流";
			msg.description = "一起来玩吧!";
		SendMessageToWX.Req req = new SendMessageToWX.Req();
			req.scene=SendMessageToWX.Req.WXSceneSession;
			req.transaction = buildTransaction("img");
			req.message = msg;
			Log.e("微信","rep构造完成");
			// 调用api接口响应数据到微信
			wxApi.sendReq(req);
			//
//			final WXAppExtendObject appdata = new WXAppExtendObject();
//				appdata.fileData = bmpToByteArray(bmp, true);
//				appdata.extInfo = "this is ext info";                          
//				msg.mediaObject = appdata;			
//			req.scene = isTimelineCb() ? SendMessageToWX.Req.WXSceneTimeline : SendMessageToWX.Req.WXSceneSession;
//			// 构造一个Resp
//			SendMessageToWX.Req req = new SendMessageToWX.Req();
//			// 将req的transaction设置到resp对象中，其中bundle为微信传递过来的intent所带的内容，通过getExtras方法获取
//			req.transaction = String.valueOf(System.currentTimeMillis());
//			req.message = msg;		
//		} else {
//			Log.e("微信","当前版本不支持朋友圈");
//			Toast.makeText(LoaderActivity.m_Activity, "当前微信版本不支持朋友圈分享功能", Toast.LENGTH_LONG).show();
//		}
//		
	}
	public static byte[] bmpToByteArray(final Bitmap bmp, final boolean needRecycle) {
		ByteArrayOutputStream output = new ByteArrayOutputStream();
		bmp.compress(CompressFormat.PNG, 100, output);
		if (needRecycle) {
			bmp.recycle();
		}
		
		byte[] result = output.toByteArray();
		try {
			output.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return result;
	}
	class InitWxRunnable implements Runnable {
		private final CountDownLatch doneSignal;

		public InitWxRunnable(CountDownLatch doneSignal) {
			this.doneSignal = doneSignal;
		}

		@Override
		public void run() {
			   
			InitWX();
			doneSignal.countDown();
					}
	}

	private boolean isTimelineCb(){
		if(wxApi.getWXAppSupportAPI() > TIMELINE_SUPPORTED_VERSION) {
			return true;
		}
		return false;
	}
	private String buildTransaction(final String type) {
		return (type == null) ? String.valueOf(System.currentTimeMillis()) : type + System.currentTimeMillis();
	}
}
