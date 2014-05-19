package cn.lihui.iap.mm.sms;

import java.util.HashMap;

import cn.lihui.iap.i.IPurchaseCallback;
import cn.lihui.iap.mm.sms.PurchaseHandler;

import com.ideaworks3d.marmalade.LoaderActivity;

import mm.purchasesdk.Purchase;
import mm.sms.purchasesdk.OnSMSPurchaseListener;
import mm.sms.purchasesdk.PurchaseCode;
import mm.sms.purchasesdk.SMSPurchase;
import android.content.Context;
import android.os.Message;
import android.util.Log;
import android.widget.Toast;

public class IAPListener implements OnSMSPurchaseListener {
	private final String TAG = "IAPListener";
	private Context context;
	private IPurchaseCallback callback;
	private PurchaseHandler ph;

	public IAPListener(Context context, PurchaseHandler lhIAP, IPurchaseCallback callback) {
		this.context = context;
		this.callback=callback;
		this.ph = lhIAP;
		}

	@Override
	public void onInitFinish(int code) {
		Log.d(TAG, "Init finish, status code = " + code);
		Log.i("","Jerry--onInitFinish" + "初始化结果：" + SMSPurchase.getReason(code) + " " + code);
		if (code != PurchaseCode.INIT_OK) {
			ph.setInitFlag(false);
		} else {
			ph.setInitFlag(true);
		}
	}

	@Override
	public void onBillingFinish(int code, HashMap arg1) {
		Log.d(TAG, "billing finish, status code = " + code);

		////////////////////////////////////////////////////////////////
		if (code != PurchaseCode.BILL_CANCEL_FAIL) {
			String strToast = "";
			 if (code == PurchaseCode.ORDER_OK) {
				strToast = "购买成功，感谢您的购买。";
				callback.onPurchaseSucceed();
			} else {
				strToast = "购买未成功，请检查手机卡或者数据网络稍后再试。";
				callback.onPurchaseFailed();
			}
			Toast.makeText(context, strToast, Toast.LENGTH_SHORT).show();
		}

		callback.onPurchaseFinish();
	}

}
