package cn.lihui.iap.mm.sms;

import cn.lihui.iap.i.IPurchaseCallback;
import cn.lihui.iap.i.IPurchaseHandler;
import cn.lihui.iap.mm.PurchaseItem;
import mm.sms.purchasesdk.OnSMSPurchaseListener;
import mm.sms.purchasesdk.PurchaseSkin;
import mm.sms.purchasesdk.SMSPurchase;
import android.app.Activity;
import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;

public class PurchaseHandler  implements IPurchaseHandler {
	/** Called when the activity is first created. */
	public static final int ITEM0 = Menu.FIRST;// 系统值
	public static final int ITEM1 = 2;
	public static final int ITEM2 = 3;
	public static final int ITEM3 = 4;
	private final String TAG = "Demo";

	public SMSPurchase purchase;
	private Context context;
	private IAPListener mListener;
	private PurchaseItem mPurchaseItem;
	// 计费信息
	// 计费信息 (现网环境)
	private static final String APPID = "300008265411";
	private static final String APPKEY = "EBE1CB1A33FA4B85";
	// 计费点信息
	//private static final String LEASE_PAYCODE = "000000000000000";

    public static int count=0;
	private IPurchaseCallback callback;
	private static Boolean isInitIAP = false;
	private static Boolean isInitSMS = false;
	
	public PurchaseHandler(PurchaseItem mPurchaseItem, Context context, IPurchaseCallback callback){
		this.mPurchaseItem = mPurchaseItem;
		this.context = context;
		this.callback = callback;
		isInitIAP = false;
		//count=0;
	}
	

	@Override
	public void order(PurchaseItem purchaseItem) {
		this.mPurchaseItem = purchaseItem;
		
		if (!isInitIAP) {
	
			//isOnCreate = false;
			initPurchaseSDK();
		} else try {
			Log.i("","Jerry--smsOrder");
			
			/**
			 * step4. IAP组件初始化开始， 参数PurchaseListener，初始化函数需传入step1时实例化的
			 * PurchaseListener。
			 */
			if(!isInitSMS) {
				purchase.smsInit(context, mListener);
			} else {
				// purchase.smsOrder(context, mPaycode, listener);
				purchase.smsOrder(context, mPurchaseItem.idContentMM, mListener);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		//count++;
	}

	@Override
	public void initPurchaseSDK() {
		// TODO Auto-generated method stub
		Log.i("","Jerry--initPurchaseSDK");
		if(isInitIAP) {
			return;
		}
		Log.i(TAG, "Jerry--order initPurchaseSDK");
		Log.d(TAG, "Init LihuiInAppPurchase1");

		/**
		 * IAP组件初始化.包括下面3步。
		 */
		/**
		 * step1.实例化PurchaseListener。实例化传入的参数与您实现PurchaseListener接口的对象有关。
		 * 例如，此Demo代码中使用IAPListener继承PurchaseListener，其构造函数需要Context实例。
		 */
		mListener = new IAPListener(context, this, callback);
		/**
		 * step2.获取Purchase实例。
		 */
		purchase = SMSPurchase.getInstance();
		/**
		 * step3.向Purhase传入应用信息。APPID，APPKEY。 需要传入参数APPID，APPKEY。 APPID，见开发者文档
		 * APPKEY，见开发者文档
		 */
		try {
			purchase.setAppInfo(APPID, APPKEY);
			
		} catch (Exception e1) {
			e1.printStackTrace();
			isInitIAP = false;
		}
		isInitIAP = true;
	}
	
	public void setInitFlag(boolean flag) {
		isInitSMS = flag;
		if(isInitSMS) {
			purchase.smsOrder(context, mPurchaseItem.idContentMM, mListener);
		}
	}

	private final static String PAYCODE = "Paycode";
	private final static String PRODUCTNUM = "ProductNUM";

}