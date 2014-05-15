package cn.lihui.iap.mm.mm;

import mm.purchasesdk.Purchase;
import android.app.Activity;
import android.content.Context;
import android.util.Log;
import android.widget.Toast;

import cn.lihui.iap.i.IPurchaseCallback;
import cn.lihui.iap.i.IPurchaseHandler;
import cn.lihui.iap.mm.LihuiInAppPurchase;
import cn.lihui.iap.mm.PurchaseItem;

public class PurchaseHandler implements IPurchaseHandler  {
	private PurchaseItem mPurchaseItem;
	private Context context;
	private static Boolean isInitIAP = false;
	private static Boolean isOnCreate = false;
	private IPurchaseCallback callback;
    public static int count=0;
	private static String TAG = "Lihui";
	private static final String APPID = "300008265411";
	private static final String APPKEY = "EBE1CB1A33FA4B85";
	private static IAPListener mListener;
	private static IAPHandler mIapHandler;
	private static Purchase mPurchase;
	

	
	public PurchaseHandler(PurchaseItem mPurchaseItem, Context context, IPurchaseCallback callback){
		this.mPurchaseItem = mPurchaseItem;
		this.context = context;
		this.callback = callback;
		isInitIAP = false;
		count=0;
	}

	@Override
	public void order(PurchaseItem purchaseItem) {
		this.mPurchaseItem = purchaseItem;
		
		if (count==0) {
	
			//isOnCreate = false;
			initPurchaseSDK();
		} else {
			try {
				
				mPurchase.order(context, mPurchaseItem.idContentMM,
						1, mListener);
				Toast.makeText(context, "正在购买中，请稍候...", Toast.LENGTH_SHORT)
						.show();
			} catch (Exception e) {
				Log.e("MM purchase order failed",
						mPurchaseItem.title + " " + e.getMessage());
			}
		}
		count++;
	}

	@Override
	public void initPurchaseSDK() {
		if(isInitIAP) {
			return;
		}
		Log.i(TAG, "Jerry--order initPurchaseSDK");
		Log.d(TAG, "Init LihuiInAppPurchase1");
		mIapHandler = new IAPHandler((Activity)context, this,
				new IAPHandler.OnIAPFinishedHandler() {

					public void onInitFinished() {
						// Not execute when the game is onCreate
						if (isInitIAP && !isOnCreate) {
							Log.d(TAG, "Init LihuiInAppPurchase2");
							order(mPurchaseItem);
						} else if (!isInitIAP && !isOnCreate) {
							Toast.makeText(context,
									"初始化失败，请检查手机卡或者数据网络稍后再试。",
									Toast.LENGTH_SHORT).show();
						}
					}
					@Override
					public void onPurchaseSucceed() {
						callback.onPurchaseSucceed();
					}

					public void onPurchaseFinished() {
						callback.onPurchaseFinish();
					}
					@Override
					public void onPurchaseFailed() {
						callback.onPurchaseFailed();
					}

				});

		mListener = new IAPListener(mIapHandler);

		mPurchase = Purchase.getInstance();
		try {
			mPurchase.setAppInfo(APPID, APPKEY);
			mPurchase.init(context, mListener);
			//isInitIAP=true;
		} catch (Throwable e) {
			Log.e("LihuiIAP", "MM purchase init failed: "
					+ e.getCause().getMessage());
			isInitIAP = false;
		}
	}

	public void setInitFlag(boolean flag) {
		isInitIAP = flag;
	}
}
