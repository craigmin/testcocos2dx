package com.lihui.iap.te;

import java.util.UUID;

import com.alipay.android.msp.demo.ExternalPartner;
import com.estore.lsms.tools.ApiParameter;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.umeng.analytics.MobclickAgent;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.util.Log;

//import com.unicom.dcLoader.Utils;
//import com.unicom.dcLoader.Utils.UnipayPayResultListener;


import cn.lihui.iap.i.IPurchaseCallback;
import cn.lihui.iap.i.IPurchaseHandler;
import cn.lihui.iap.mm.LihuiInAppPurchase;
import cn.lihui.iap.mm.PurchaseItem;

public class PurchaseHandler implements IPurchaseHandler {

	public static PurchaseHandler instanse;
	private PurchaseItem mPurchaseItem;
	private static Boolean isInitIAP = false;
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
		mPurchaseItem=purchaseItem;
		if(purchaseItem.type.equals("lives")||purchaseItem.type.equals("coins3")||purchaseItem.type.equals("gold3")){
			LoaderActivity.m_Activity.runOnUiThread(m_PurchaseEx);
			
			return;
		}
		Log.i("","Jerry--CU_order");
		Intent intent = new Intent();
        intent.setClass(LoaderActivity.m_Activity, com.estore.ui.CTEStoreSDKActivity.class);

        Bundle bundle = new Bundle();
   
       //this.code = new String("E59A4C411A9797C0E040640A041E0698");
        bundle.putString(ApiParameter.APPCHARGEID, mPurchaseItem.idContentTE);
        bundle.putString(ApiParameter.CHANNELID, "T009");
        bundle.putBoolean(ApiParameter.SCREENHORIZONTAL, false);//��������XML"
        
        bundle.putString(ApiParameter.CHARGENAME, mPurchaseItem.title);
        bundle.putInt(ApiParameter.PRICETYPE, 0);
        bundle.putString(ApiParameter.PRICE, mPurchaseItem.prize);
    
        bundle.putString(ApiParameter.REQUESTID, UUID.randomUUID().toString().replaceAll("-", ""));
        intent.putExtras(bundle);
        Log.i("Jerry--CTE","startActivityForResult");
        Editor editor=LihuiInAppPurchase.getPreferences().edit();
        editor.putString("itemtype",mPurchaseItem.type);
        editor.commit();
        LoaderActivity.m_Activity.startActivityForResult(intent, 100);
	}

	@Override
	public void initPurchaseSDK() {
		// TODO Auto-generated method stub
		
	}
	private final Runnable m_PurchaseEx = new Runnable() {
		public void run() {
			MobclickAgent.onEvent(LoaderActivity.m_Activity,"onPurchase","ALI:"+mPurchaseItem.type);
			ExternalPartner.getInstance().LihuiPay("com.ximad.bubblebirds3.inapp."+mPurchaseItem.type);
		}
	};
	

}
