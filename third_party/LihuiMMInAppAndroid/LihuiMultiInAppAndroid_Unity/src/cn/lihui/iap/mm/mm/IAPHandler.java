package cn.lihui.iap.mm.mm;


import mm.purchasesdk.PurchaseCode;
import android.app.Activity;
import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.Toast;

public class IAPHandler extends Handler {
	private final String TAG = "CBMMIAPHandler";

	public static final int INIT_FINISH = 10000;
	public static final int BILL_FINISH = 10001;
	public static final int QUERY_FINISH = 10002;
	public static final int UNSUB_FINISH = 10003;

	private Context context;
	private PurchaseHandler lhIAP;

	public IAPHandler(Activity context, PurchaseHandler lhIAP, OnIAPFinishedHandler handler) {
		this.context = context;
		this.handler = handler;
		this.lhIAP = lhIAP;
	}

	public void setContext(Activity context) {
		this.context = context;
	}

	private OnIAPFinishedHandler handler;

	public interface OnIAPFinishedHandler {
		public void onPurchaseSucceed();

		public void onPurchaseFinished();

		public void onInitFinished();
		
		public void onPurchaseFailed();
	}

	@Override
	public void handleMessage(Message msg) {
		super.handleMessage(msg);
		int what = msg.what;
		switch (what) {
		case INIT_FINISH:
			initFinish(msg);
			return;
		case BILL_FINISH:
			if (msg.arg1 == PurchaseCode.BILL_CANCEL_FAIL) {
				break;
			}

			String strToast = "";
			if (msg.arg1 == PurchaseCode.AUTH_OK) {
				strToast = "您已购买过此商品，请继续使用。";
				handler.onPurchaseSucceed();
			} else if (msg.arg1 == PurchaseCode.ORDER_OK) {
				strToast = "购买成功，感谢您的购买。";
				handler.onPurchaseSucceed();
			} else if (msg.arg1 == PurchaseCode.NOMOREREQUEST_ERR) {
				strToast = "正在购买中，请稍候...";
			} else {
				strToast = "购买未成功，请检查手机卡或者数据网络稍后再试。";
				handler.onPurchaseFailed();
			}

			Toast.makeText(context, strToast, Toast.LENGTH_SHORT).show();
			break;
		case QUERY_FINISH:
		case UNSUB_FINISH:
		default:
			// Not support these actions
			break;
		}

		handler.onPurchaseFinished();
		if (msg.obj != null && msg.obj instanceof String) {
			Log.i(TAG, (String) msg.obj);
		}
	}

	private void initFinish(Message msg) {

		// Set flag if init failed
		if (msg.arg1 != PurchaseCode.INIT_OK) {
			lhIAP.setInitFlag(false);
		} else {
			lhIAP.setInitFlag(true);
		}

		handler.onInitFinished();
	}
}
