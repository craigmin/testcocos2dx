package com.lihui.social4wx;



import java.io.IOException;

import com.ideaworks3d.marmalade.LoaderActivity;
import com.lihui.lihui2048.Lihui2048;

import com.tencent.mm.sdk.openapi.BaseReq;
import com.tencent.mm.sdk.openapi.BaseResp;
import com.tencent.mm.sdk.openapi.IWXAPI;
import com.tencent.mm.sdk.openapi.IWXAPIEventHandler;
import com.tencent.mm.sdk.openapi.SendMessageToWX;
import com.tencent.mm.sdk.openapi.WXAPIFactory;
import com.tencent.mm.sdk.openapi.WXAppExtendObject;
import com.tencent.mm.sdk.openapi.WXImageObject;
import com.tencent.mm.sdk.openapi.WXMediaMessage;
import com.tencent.mm.sdk.openapi.WXTextObject;
import com.tencent.mm.sdk.platformtools.BackwardSupportUtil.BitmapFactory;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Paint.Align;
import android.graphics.Typeface;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

public class SendToWXActivity extends Activity {
	private IWXAPI wxApi;
	private static final int TIMELINE_SUPPORTED_VERSION = 0x21020001;
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		Log.e("SendToWXActivity","start");
		wxApi = WXAPIFactory.createWXAPI(SendToWXActivity.this, Constants.APP_ID,true);
		LoaderActivity.m_Activity.runOnUiThread(m_Share);
		Log.e("结束", "m_Share Thread");
	}

	private final Runnable m_Share = new Runnable() {
		public void run() {
			Log.e("线程", "UI");
			int wxSdkVersion = wxApi.getWXAppSupportAPI();
			if (wxSdkVersion >= TIMELINE_SUPPORTED_VERSION) {
				//Toast.makeText(SendToWXActivity.this, "当前微信版本支持朋友圈分享功能", Toast.LENGTH_LONG).show();
				Log.e("微信","当前版本支持朋友圈");
				//wxApi = WXAPIFactory.createWXAPI(LoaderActivity.m_Activity, Constants.APP_ID, true);
				wxApi.registerApp(Constants.APP_ID);
				String text = "play Chalkball";
				// 初始化一个WXTextObject对象
				WXTextObject textObj = new WXTextObject();
				textObj.text = text;
				WXMediaMessage msg = new WXMediaMessage(textObj);
				
				//添加图片
				
				// Craig： 2048 分享图片用 - Start
				Bitmap bmp = null;
				try {
					bmp = BitmapFactory.decodeStream(LoaderActivity.m_Activity.getAssets().open("sunbeams.png"));
					
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}	
				int x=bmp.getWidth();
				int y=bmp.getHeight();
				Bitmap newbit=Bitmap.createBitmap(x, y, Bitmap.Config.ARGB_8888);
				Canvas c = new Canvas(newbit);
				Paint p = new Paint();
				c.drawBitmap(bmp, 0, 0,p);
				Typeface font = Typeface.create("宋体", Typeface.NORMAL);
				p.setTypeface(font);
				p.setColor(Color.WHITE);
				p.setTextSize((int) (0.1*x));
				p.setTextAlign(Align.CENTER);
				int tempX=(int) (0.5*x);
				c.drawText(String.valueOf(Lihui2048.getInstance().getBestScore())+"分", (int) (0.5*x), (int) (0.7*y), p);
				//c.drawText("10000"+"分", 165, 240, p);
				c.save(Canvas.ALL_SAVE_FLAG);
				c.restore();
				WXImageObject image=new WXImageObject(newbit);
				// 2048 - End
				// Craig: Bubble Birds 3 用分享图片 - Start
				/*
				Bitmap bmp = null;
				try {
					bmp = BitmapFactory.decodeStream(LoaderActivity.m_Activity.getAssets().open("BB3Share.jpg"));
					
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}	
				
				WXImageObject image=new WXImageObject(bmp);
				*/
				// BB3 - End
				msg.mediaObject = image;
			//bmp.recycle();
				// 用WXTextObject对象初始化一个WXMediaMessage对象
				msg.description = text;
				msg.title ="ChalkBall";
				SendMessageToWX.Req req = new SendMessageToWX.Req();
				req.scene=SendMessageToWX.Req.WXSceneTimeline;
				req.transaction = Util.buildTransaction("img");
				req.message = msg;
				wxApi.sendReq(req);
				Log.e("调用api接口响应数据到微信","Done");
//				String text = "测试";
//				// 初始化一个WXTextObject对象
//				WXTextObject textObj = new WXTextObject();
//				textObj.text = text; 
//				// 用WXTextObject对象初始化一个WXMediaMessage对象
//				WXMediaMessage msg = new WXMediaMessage(textObj);
//				Bitmap bmp = null;
//				try {
//					bmp = BitmapFactory.decodeStream(LoaderActivity.m_Activity.getAssets().open("icon1.png"));
//				} catch (IOException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}	
////				final WXAppExtendObject appdata = new WXAppExtendObject();
////				appdata.fileData = Util.bmpToByteArray(bmp, true);
////				appdata.extInfo = "this is ext info";                          
//				//msg.mediaObject = appdata;	
//				WXImageObject image=new WXImageObject(bmp);
////				Bitmap thumbBmp = Bitmap.createScaledBitmap(bmp, THUMB_SIZE, THUMB_SIZE, true);
//				bmp.recycle();
//				msg.mediaObject=image;
////				msg.thumbData = bmpToByteArray(thumbBmp, true);  // 设置缩略图
//				msg.title = "肥鸟大漂流";
//				msg.description = "一起来玩吧!";
//			SendMessageToWX.Req req = new SendMessageToWX.Req();
//				req.scene=SendMessageToWX.Req.WXSceneSession;
//				req.transaction = Util.buildTransaction("img");
//				req.message = msg;
//				Log.e("微信","rep构造完成");
//				// 调用api接口响应数据到微信
//				wxApi.sendReq(req);
			} else {
				Log.e("微信","当前版本不支持朋友圈");
				Toast.makeText(LoaderActivity.m_Activity, "当前微信版本不支持朋友圈分享功能", Toast.LENGTH_LONG).show();
			}
			finish();
		}

	};
	
}
	


	
