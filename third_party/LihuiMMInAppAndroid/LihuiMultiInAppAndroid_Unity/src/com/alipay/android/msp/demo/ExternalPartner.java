package com.alipay.android.msp.demo;

import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.text.SimpleDateFormat;
import java.util.Date;

import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


import cn.lihui.iap.mm.LihuiInAppPurchase;
import cn.lihui.iap.mm.PurchaseItem;

import com.alipay.android.app.sdk.AliPay;
//import com.estore.lsms.tools.ApiParameter;
import com.ideaworks3d.marmalade.LoaderActivity;
//import cn.lihui.iap.R;
//import com.umeng.analytics.MobclickAgent;
import com.umeng.analytics.MobclickAgent;

public class ExternalPartner{ 
	public  final static String TAG = "alipay-sdk";

	private  final static int RQF_PAY = 1;

	private  final static int RQF_LOGIN = 2;
	private PurchaseItem item;
	private  EditText mUserId;
	private Button mLogon;
	private static ExternalPartner ep;

	
   public  void LihuiPay(String itemId){
	   Log.e("Jerry","LihuiPay() execute");
       Log.e("Jerry","LihuiInAppPurchase.External=this;");
	   //doLogin();
	   try {
		   Log.e("Jerry", "try in");
			String info = getOrderInfo(itemId);
			String sign = Rsa.sign(info, Keys.PRIVATE);
			sign = URLEncoder.encode(sign);
			info += "&sign=\"" + sign + "\"&" + getSignType();
			//Log.i("ExternalPartner", "start pay");
			// start the pay.
			Log.i("Jerry" , "info = " + info);

			final String orderInfo = info;
			
			new Thread() {
				public void run() {	
					AliPay alipay = new AliPay(LoaderActivity.m_Activity, mHandler);
					
					//设置为沙箱模式，不设置默认为线上环境
					//alipay.setSandBox(true);

					String result = alipay.pay(orderInfo);

					Log.i(TAG, "result = " + result);
					Message msg = new Message();
					msg.what = RQF_PAY;
					msg.obj = result;
					mHandler.sendMessage(msg);
				}
			}.start();
			
		} catch (Exception ex) {
			ex.printStackTrace();
			Toast.makeText(LoaderActivity.m_Activity, "remote_call_failed",
					Toast.LENGTH_SHORT).show();
		}
	}
	private   String getOrderInfo(String itemId){
		this.item = PurchaseItem.getPurchaseItemByType(itemId);
		StringBuilder sb = new StringBuilder();
		sb.append("partner=\"");
		sb.append(Keys.DEFAULT_PARTNER);
		sb.append("\"&out_trade_no=\"");
		sb.append(getOutTradeNo());
		sb.append("\"&subject=\"");
		sb.append(item.title);
		sb.append("\"&body=\"");
		sb.append(item.idContentTE);
		sb.append("\"&total_fee=\"");
		sb.append(item.prize);
		sb.append("\"&notify_url=\"");

		// 网址需要做URL编码
		sb.append(URLEncoder.encode("http://notify.java.jpxx.org/index.jsp"));
		sb.append("\"&service=\"mobile.securitypay.pay");
		sb.append("\"&_input_charset=\"UTF-8");
		sb.append("\"&return_url=\"");
		sb.append(URLEncoder.encode("http://m.alipay.com"));
		sb.append("\"&payment_type=\"1");
		sb.append("\"&seller_id=\"");
		sb.append(Keys.DEFAULT_SELLER);

		// 如果show_url值为空，可不传
		// sb.append("\"&show_url=\"");
		sb.append("\"&it_b_pay=\"1m");
		sb.append("\"");

		return new String(sb);
	}


	private   String getOutTradeNo() {
		SimpleDateFormat format = new SimpleDateFormat("MMddHHmmss");
		Date date = new Date();
		String key = format.format(date);

		java.util.Random r = new java.util.Random();
		key += r.nextInt();
		key = key.substring(0, 15);
		Log.d(TAG, "outTradeNo: " + key);
		return key;
	}

	private   String getSignType() {
		return "sign_type=\"RSA\"";
	}





	private  String getUserInfo() {
		String userId = mUserId.getText().toString();
		return trustLogin(Keys.DEFAULT_PARTNER, userId);

	}

	private  String trustLogin(String partnerId, String appUserId) {
		StringBuilder sb = new StringBuilder();
		sb.append("app_name=\"mc\"&biz_type=\"trust_login\"&partner=\"");
		sb.append(partnerId);
		Log.d("TAG", "UserID = " + appUserId);
		if (!TextUtils.isEmpty(appUserId)) {
			appUserId = appUserId.replace("\"", "");
			sb.append("\"&app_id=\"");
			sb.append(appUserId);
		}
		sb.append("\"");

		String info = sb.toString();

		// 请求信息签名
		String sign = Rsa.sign(info, Keys.PRIVATE);
		try {
			sign = URLEncoder.encode(sign, "UTF-8");
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
		info += "&sign=\"" + sign + "\"&" + getSignType();

		return info;
	}



	 Handler mHandler = new Handler() {
		public void handleMessage(final android.os.Message msg) {
			final Result result = new Result((String) msg.obj);
			LoaderActivity.m_Activity.runOnUiThread(new Runnable() {
				public void run() {
			switch (msg.what) {
			case RQF_PAY:
			case RQF_LOGIN: {
				if(result.getResultCode().equals("9000")){
						Toast.makeText(LoaderActivity.m_Activity, "购买成功",//.getResult(),
						Toast.LENGTH_SHORT).show();
						MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchaseSucceed","ALI:"+item.type);
				LihuiInAppPurchase.getInstance().LihuiInAppPurchaseSuccessful("com.ximad.bubblebirds3.inapp."+
						item.type);
				
				}else {
					MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchaseFail","ALI:"+item.type);
							Toast.makeText(LoaderActivity.m_Activity, "购买失败",//.getResult(),
							Toast.LENGTH_SHORT).show();
				//LihuiInAppPurchase.getInstance().LihuiInAppPurchaseSuccessful("com.ximad.bubblebirds3.inapp."+item.type);
				}

			}
				break;
			default:
				break;
			}
				}
			});
		};
	};

	

	public static ExternalPartner getInstance() {
		// TODO Auto-generated method stub
		if(ep == null){
			ep = new ExternalPartner();
		}
		return ep;
	}
		}
	