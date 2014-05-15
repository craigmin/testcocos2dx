package cn.lihui.iap.wo;

import android.content.Context;
import android.util.Log;

import com.alipay.android.msp.demo.ExternalPartner;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.umeng.analytics.MobclickAgent;
import com.unicom.dcLoader.Utils;
import com.unicom.dcLoader.Utils.UnipayPayResultListener;


import cn.lihui.iap.i.IPurchaseCallback;
import cn.lihui.iap.i.IPurchaseHandler;
import cn.lihui.iap.mm.PurchaseItem;

public class PurchaseHandler implements IPurchaseHandler {

	private static PayResultListener payResultListener;
	private PurchaseItem mPurchaseItem;
	private static Boolean isInitIAP = false;
	private static final String AppId="909248362220140505141737409500";
	private static final String cpCode="9092483622";
	private static final String cpId="86008029";
	private static final String companyName="上海游米网络科技有限公司";
	private static final String telphone="4008210849";
	private static final String appName="天天2048";
	private Context context;
	private IPurchaseCallback callback;

	public PurchaseHandler(PurchaseItem mPurchaseItem, Context context, IPurchaseCallback callback){
		this.mPurchaseItem = mPurchaseItem;
		this.context = context;
		this.callback = callback;
		PurchaseHandler.isInitIAP = false;
	}

	@Override
	public void order(PurchaseItem purchaseItem) {
		if(purchaseItem.type.equals("lives")||purchaseItem.type.equals("coins3")||purchaseItem.type.equals("gold3")){
			this.mPurchaseItem = purchaseItem;
			LoaderActivity.m_Activity.runOnUiThread(m_PurchaseEx);
			
			return;
		}
		Log.i("","Jerry--CU_order");
		this.mPurchaseItem = purchaseItem;
		initPurchaseSDK();
//		Utils.getInstances().setBaseInfo(context, false, true, "");
//		Utils.getInstances().pay(context, mPurchaseItem.idContentWO,
//				"", mPurchaseItem.title, mPurchaseItem.prize,
//				"123456789012345678901234", payResultListener);
	//	Utils.getInstances().initSDK(context, 0);
		Utils.getInstances().pay(context,mPurchaseItem.idContentWO,new PayResultListener());
		Log.i("","Jerry--CU_order--"+mPurchaseItem.idContentWO);
	}

	@Override
	public void initPurchaseSDK() {
		if (!isInitIAP) {
//			payResultListener = new PayResultListener();
//			Utils.getInstances().init(context,
//					AppId, cpCode, cpId,
//					companyName,telphone,appName, "uid",
//					payResultListener);
		Utils.getInstances().initSDK(context, 0);
			isInitIAP = true;
		}	}

	public class PayResultListener implements UnipayPayResultListener {

		@Override
		public void PayResult(String paycode, int flag, String desc) {

			if (flag == Utils.SUCCESS_SMS) {
				// 如果是短信发送成功或者延时超过指定时间，SDK都返回成功，开发者可以在在desc中可以看到成功结果的描述
				callback.onPurchaseSucceed();
			} else if (flag == Utils.SUCCESS_3RDPAY) {
				// SDK使用第三方支付返回成功
				callback.onPurchaseSucceed();
			} else if (flag == Utils.FAILED) {
				// desc中放支付失败的原因
				callback.onPurchaseFailed();
			} else if (flag == Utils.CANCEL) {
			} else if (flag == Utils.OTHERPAY) {
			}

			callback.onPurchaseFinish();
		}
	}
	private final Runnable m_PurchaseEx = new Runnable() {
		public void run() {
			MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchase","ALI:"+mPurchaseItem.type);
			ExternalPartner.getInstance().LihuiPay("com.ximad.bubblebirds3.inapp."+mPurchaseItem.type);
		}
	};
}
