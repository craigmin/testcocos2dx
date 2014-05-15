package cn.lihui.iap.i;

import cn.lihui.iap.mm.PurchaseItem;

public interface IPurchaseHandler {
	void order(PurchaseItem p);
	void initPurchaseSDK();
}
