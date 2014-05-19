package cn.lihui.iap.mm;

import java.util.HashMap;
import java.util.Map;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.util.Log;
import android.widget.Toast;
import cn.lihui.iap.i.IPurchaseCallback;
import cn.lihui.iap.i.IPurchaseHandler;
import cn.lihui.iap.utility.NetUtility;

import com.alipay.android.msp.demo.ExternalPartner;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.umeng.analytics.MobclickAgent;
public class LihuiInAppPurchase {
    public static LihuiInAppPurchase instanse;
	public PurchaseItem mPurchaseItem;
	private static Boolean isInPurchasing = false;
	private static IPurchaseHandler purchaseHandler;
	private static LihuiInAppPurchase sInstance;
	private static String TAG = "Lihui";
	private static final String myPrefName = "cn.lihui.iap";
	private final boolean isRepeatable=true;
	private static SharedPreferences mSharedPreferences;
	private  int type;
	public native void LihuiInAppPurchaseSuccessful(String key);

	public native void LihuiInAppPurchaseFailed(String key);

	public native void LihuiInAppPurchaseRestored(String key);

	public native void LihuiInAppPurchaseRevoked(String key);
	public Map<String, String> productMap = new HashMap<String, String>();
	public static LihuiInAppPurchase getInstance(){
		if(instanse == null){
			instanse = new LihuiInAppPurchase();
		}
		
		return instanse;
	}
	public static SharedPreferences getPreferences(){
		if(mSharedPreferences == null){
			mSharedPreferences=LoaderActivity.m_Activity.getSharedPreferences("bbitems",LoaderActivity.m_Activity.MODE_WORLD_READABLE);
		}
		
		return mSharedPreferences;
	}
	public boolean LihuiIsItemPurchased(String itemId) {
		mPurchaseItem = PurchaseItem.getPurchaseItemByType(itemId);
		if (this.mPurchaseItem == null) {
			return false;
		}
		return mSharedPreferences.getBoolean(mPurchaseItem.type, false);
	}

	public void LihuiInAppBuyItem(String itemId) {
		Log.i(TAG, "Jerry--LihuiInAppBuyItem :" + itemId);

		this.mPurchaseItem = PurchaseItem.getPurchaseItemByType(itemId);
		if (this.mPurchaseItem == null) {
			callback.onPurchaseFailed();
			return;
		}
	
	if (!productMap.containsKey(this.mPurchaseItem.type)) {
		productMap.put(this.mPurchaseItem.type, itemId);
	}
//	if(this.mPurchaseItem.type.equals("lives")||this.mPurchaseItem.type.equals("coins3")||this.mPurchaseItem.type.equals("gold3")){
//		LoaderActivity.m_Activity.runOnUiThread(m_PurchaseEx);
//		
//		return;
//	}

		LoaderActivity.m_Activity.runOnUiThread(new Runnable() {
			public void run() {

				if (isInPurchasing) {
					Toast.makeText(LoaderActivity.m_Activity, "正在购买中，请稍候...",
							Toast.LENGTH_SHORT).show();
					return;
				}
				
				if (purchaseHandler == null) {
					//int type = NetUtility.getOperatorType(LoaderActivity.m_Activity);		
					type = NetUtility.getOperatorType(LoaderActivity.m_Activity);
					type = NetUtility.CHINAMOBILE;
					if (type == NetUtility.CHINAUNICOM) {
						// 联通
						Log.i("","Jerry--CHINAUNICOM");
						purchaseHandler = new cn.lihui.iap.wo.PurchaseHandler(
								mPurchaseItem, LoaderActivity.m_Activity, callback);
					} else if(type == NetUtility.CHINATELECOM){
						// 电信
						Log.i("","Jerry--CHINATELECOM");
						purchaseHandler = new com.lihui.iap.te.PurchaseHandler(
								mPurchaseItem, LoaderActivity.m_Activity, callback);
					}else{
						// 默认使用中国移动计费
						Log.i("","Jerry--CHINAMOBILE");
						purchaseHandler = new cn.lihui.iap.mm.sms.PurchaseHandler(
								mPurchaseItem, LoaderActivity.m_Activity, callback);
						purchaseHandler.initPurchaseSDK();
						Log.i(TAG,"Jerry--"+mPurchaseItem.title);
						
					}
				}
				type = NetUtility.getOperatorType(LoaderActivity.m_Activity);
				if(type == NetUtility.CHINAMOBILE) {
					//isInPurchasing = true;
				}

				MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchase",type+":"+mPurchaseItem.type);
				purchaseHandler.order(mPurchaseItem);
			}
		});
	}

	IPurchaseCallback callback = new IPurchaseCallback() {

		@Override
		public void onPurchaseSucceed() {
			
			MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchaseSucceed",type+":"+mPurchaseItem.type);
		//BB3
			LihuiInAppPurchaseSuccessful(mPurchaseItem.type);

		}

		@Override
		public void onPurchaseFailed() {
			
			MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchaseFail",type+":"+mPurchaseItem.type);
			Log.i(TAG,"Jerry--onPurchaseFailed");
		}

		@Override
		public void onPurchaseFinish() {
			Log.i(TAG,"Jerry--onPurchaseFinish");
			isInPurchasing = false;
		}
	};
	public void LihuiInAppStart(){
		Log.i(TAG,"Jerry--LihuiInAppStart@@@@");
		if (purchaseHandler == null) {
			//int type = NetUtility.getOperatorType(LoaderActivity.m_Activity);		
			type = NetUtility.getOperatorType(LoaderActivity.m_Activity);
			type = NetUtility.CHINAMOBILE;
			if (type == NetUtility.CHINAUNICOM) {
				// 联通
				Log.i("","Jerry--CHINAUNICOM");
				purchaseHandler = new cn.lihui.iap.wo.PurchaseHandler(
						mPurchaseItem, LoaderActivity.m_Activity, callback);
			} else if(type == NetUtility.CHINATELECOM){
				// 电信
				Log.i("","Jerry--CHINATELECOM");
				purchaseHandler = new com.lihui.iap.te.PurchaseHandler(
						mPurchaseItem, LoaderActivity.m_Activity, callback);
			}else{
				// 默认使用中国移动计费
				Log.i("","Jerry--CHINAMOBILE");
				purchaseHandler = new cn.lihui.iap.mm.sms.PurchaseHandler(
						mPurchaseItem, LoaderActivity.m_Activity, callback);
				purchaseHandler.initPurchaseSDK();
			}
			
		}
	}
	public void LihuiInAppRestorePurchases(){
		//TODO
	}
	public void LihuiInAppBuyItemEx(){
		//TODO
	}
//	private final Runnable m_PurchaseEx = new Runnable() {
//		public void run() {
//			MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchase","ALI:"+mPurchaseItem.type);
//			ExternalPartner.getInstance().LihuiPay("com.ximad.bubblebirds3.inapp."+mPurchaseItem.type);
//		}
//	};
public static void LihuiInAppSuccessCallBack() {
	isInPurchasing = false;
	if(LihuiInAppPurchase.instanse == null) {
		// TODO:
		LihuiInAppPurchase.instanse=new LihuiInAppPurchase();
		return;
	}
		Log.i("","Jerry--"+LihuiInAppPurchase.instanse.type+":"+LihuiInAppPurchase.instanse.mPurchaseItem.type);
		LihuiInAppPurchase.instanse.LihuiInAppPurchaseSuccessful("com.ximad.bubblebirds3.inapp."+LihuiInAppPurchase.getInstance().mPurchaseItem.type);
		MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchaseSucceed",LihuiInAppPurchase.getInstance().type+":"+LihuiInAppPurchase.getInstance().mPurchaseItem.type);
	}
public   static void LihuiInAppFailedCallBack() {
	isInPurchasing = false;
	
	}
}