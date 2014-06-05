package cn.lihui.daily2048_lenovo;

import com.estore.lsms.tools.ApiParameter;
import com.ideaworks3d.marmalade.LoaderActivity;
import com.umeng.analytics.MobclickAgent;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;
import cn.lihui.LihuiActivity;
import cn.lihui.iap.mm.LihuiInAppPurchase;

public class LihuiMain extends LihuiActivity {
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		if (requestCode == 100) {
			Log.i("Jerry", "onActivityResult");
			Bundle bdl = data.getExtras();
			int payResultCode = bdl.getInt(ApiParameter.RESULTCODE);

			String itemtype = LihuiInAppPurchase.getPreferences().getString(
					"itemtype", "");
			Log.i("", "Jerry" + itemtype);
			// Log.i("Jerry","Jerry Succeed");
			if (ApiParameter.CTESTORE_SENDSUCCESS == payResultCode
					|| ApiParameter.CTESTORE_SENDTIMEOUT == payResultCode) {
				Toast.makeText(LoaderActivity.m_Activity, "购买成功",
						Toast.LENGTH_SHORT).show();
				LihuiInAppPurchase.getInstance().LihuiInAppPurchaseSuccessful(
						itemtype);
				MobclickAgent.onEvent(LoaderActivity.m_Activity,
						"onPurchaseSucceed", "TE: "
								+ itemtype);
				// LihuiInAppPurchase.instanse.LihuiInAppPurchaseSuccessful("com.ximad.bubblebirds3.inapp."+LihuiInAppPurchase.instanse.mPurchaseItem.type);

				Log.i("pay-success", bdl.getString(ApiParameter.REQUESTID));
			} else {
				// LihuiInAppPurchase.LihuiInAppFailedCallBack();
				Toast.makeText(LoaderActivity.m_Activity, "购买失败",
						Toast.LENGTH_SHORT).show();
				MobclickAgent.onEvent(LoaderActivity.m_Activity,
						"onPurchaseFail", itemtype);
			}

		} else {
			super.onActivityResult(requestCode, resultCode, data);
		}
	}
}
