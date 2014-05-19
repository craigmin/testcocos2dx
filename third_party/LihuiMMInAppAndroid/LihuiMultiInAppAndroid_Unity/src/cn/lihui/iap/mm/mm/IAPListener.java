package cn.lihui.iap.mm.mm;

import java.util.HashMap;

import mm.purchasesdk.OnPurchaseListener;
import mm.purchasesdk.Purchase;
import mm.purchasesdk.PurchaseCode;
import android.os.Message;
import android.util.Log;

public class IAPListener implements OnPurchaseListener {
	private final String TAG = "CBMMIAPHandler";
	private IAPHandler iapHandler;

	public IAPListener(IAPHandler iapHandler) {
		this.iapHandler = iapHandler;
	}

	@Override
	public void onAfterApply() {

	}

	@Override
	public void onAfterDownload() {

	}

	@Override
	public void onBeforeApply() {

	}

	@Override
	public void onBeforeDownload() {

	}

	@Override
	public void onInitFinish(int code) {
		Log.d(TAG, "Init finish, status code = " + code);

		// Send message to handler
		Message message = iapHandler.obtainMessage(IAPHandler.INIT_FINISH);
		String result = "初始化结果：" + Purchase.getReason(code);
		message.obj = result;
		message.arg1 = code;
		message.sendToTarget();
	}

	@Override
	public void onBillingFinish(int code, HashMap arg1) {
		Log.d(TAG, "billing finish, status code = " + code);

		StringBuffer result = new StringBuffer("订购结果：");
		// Format the result info
		if (code == PurchaseCode.ORDER_OK || (code == PurchaseCode.AUTH_OK)) {
			/**
			 * 商品购买成功或者已经购买。 此时会返回商品的paycode，orderID,以及剩余时间(租赁类型商品)
			 */
			result.append("购买成功");
				if (arg1 != null) {
				// 商品的有效期(仅租赁类型商品有效)
				String leftday = (String) arg1.get(OnPurchaseListener.LEFTDAY);
				if (leftday != null && leftday.trim().length() != 0) {
					result.append(",剩余时间 ： ");
					result.append(leftday);
				}
				// 此次订购的orderID
				String orderID = (String) arg1.get(OnPurchaseListener.ORDERID);
				if (orderID != null && orderID.trim().length() != 0) {
					result.append(",OrderID ： ");
					result.append(orderID);
				}
				// 商品的paycode
				String paycode = (String) arg1.get(OnPurchaseListener.PAYCODE);
				if (paycode != null && paycode.trim().length() != 0) {
					result.append(",Paycode:");
					result.append(paycode);
				}
				// 商品的交易 ID，用户可以根据这个交易ID，查询商品是否已经交易
				String tradeID = (String) arg1.get(OnPurchaseListener.TRADEID);
				if (tradeID != null && tradeID.trim().length() != 0) {
					result.append(",tradeID:");
					result.append(tradeID);
				}
				String ordertype = (String) arg1.get(OnPurchaseListener.ORDERTYPE);
				if (tradeID != null && tradeID.trim().length() != 0) {
					result.append(",ORDERTYPE:");
					result.append(ordertype);
				}
			}
		} else {
			/**
			 * 表示订购失败。
			 */
			result.append(Purchase.getReason(code));
		}

		// Send message to handler
		Message message = iapHandler.obtainMessage(IAPHandler.BILL_FINISH);
		message.obj = result.toString();
		message.arg1 = code;
		message.sendToTarget();

	}

	@Override
	public void onQueryFinish(int code, HashMap arg1) {
		Log.d(TAG, "license finish, status code = " + code);
		StringBuffer result = new StringBuffer("查询结果：");
		if (code != PurchaseCode.QUERY_OK) {
			/**
			 * 查询不到商品购买的相关信息
			 */
			result.append(Purchase.getReason(code));
		} else {
			/**
			 * 查询到商品的相关信息。
			 * 此时你可以获得商品的paycode，orderid，以及商品的有效期leftday（仅租赁类型商品可以返回）
			 */
			// 商品的有效期(仅租赁类型商品有效)
			String leftday = (String) arg1.get(OnPurchaseListener.LEFTDAY);
			if (leftday != null && leftday.trim().length() != 0) {
				result.append(",剩余时间 ： ");
				result.append(leftday);
			}
			// 此次订购的orderID
			String orderID = (String) arg1.get(OnPurchaseListener.ORDERID);
			if (orderID != null && orderID.trim().length() != 0) {
				result.append(",OrderID ： ");
				result.append(orderID);
			}
			// 商品的paycode
			String paycode = (String) arg1.get(OnPurchaseListener.PAYCODE);
			if (paycode != null && paycode.trim().length() != 0) {
				result.append(",Paycode:");
				result.append(paycode);
			}
		}

		// Send message to handler
		Message message = iapHandler.obtainMessage(IAPHandler.QUERY_FINISH);
		message.obj = result.toString();
		message.sendToTarget();
		
	}

	@Override
	public void onUnsubscribeFinish(int code) {
		// XXX: Not support this action
	}
}
