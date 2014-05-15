package cn.lihui.iap.utility;

import android.content.Context;
import android.telephony.TelephonyManager;
import android.util.Log;

public class NetUtility {
	private static String TAG = "Lihui";
	public static int CHINAMOBILE = 1;
	public static int CHINAUNICOM = 2;
	public static int CHINATELECOM = 3;
	public static int UNKNOWN = 0;

	public static int getOperatorType(Context mContext) {

        TelephonyManager telManager = (TelephonyManager) mContext.getSystemService(Context.TELEPHONY_SERVICE); 
        /** 获取SIM卡的IMSI码
         * SIM卡唯一标识：IMSI 国际移动用户识别码（IMSI：International Mobile Subscriber Identification Number）是区别移动用户的标志，
         * 储存在SIM卡中，可用于区别移动用户的有效信息。IMSI由MCC、MNC、MSIN组成，其中MCC为移动国家号码，由3位数字组成，
         * 唯一地识别移动客户所属的国家，我国为460；MNC为网络id，由2位数字组成，
         * 用于识别移动客户所归属的移动网络，中国移动为00，中国联通为01,中国电信为03；MSIN为移动客户识别码，采用等长11位数字构成。
         * 唯一地识别国内GSM移动通信网中移动客户。所以要区分是移动还是联通，只需取得SIM卡中的MNC字段即可
        */ 
        String imsi = telManager.getSubscriberId(); 
//　　　　　　　　　　"getNetworkOperatorName=" + telManager.getNetworkOperatorName()+"\n" +//直接获取移动运营商名称
	
        if(imsi!=null){ 
            if(imsi.startsWith("46000") || imsi.startsWith("46002") || imsi.startsWith("46007")){//因为移动网络编号46000下的IMSI已经用完，所以虚拟了一个46002编号，134/159号段使用了此编号 
                //中国移动 
            	Log.e(TAG, "中国移动");
            	return CHINAMOBILE;
            }else if(imsi.startsWith("46001")){ 
                //中国联通 
            	Log.e(TAG, "中国联通");
            	return CHINAUNICOM;
            }else if(imsi.startsWith("46003")){ 
                //中国电信 
            	Log.e(TAG, "中国电信");
            	return CHINATELECOM;
            } 
        }  
        return UNKNOWN;
	}
}
