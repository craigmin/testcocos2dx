package cn.lihui.cocos2dx;



import android.util.Log;
import cn.lihui.sdk.bean.Ranks;
import cn.lihui.sdk.constant.LeaderBoardsResultCode;
import cn.lihui.sdk.utils.LeaderBoardsResultListener;

public class ResultListener implements LeaderBoardsResultListener {
	private Ranks ranks;
	public static LBInterface lbinterface;
	public Ranks getRanks() {
		return ranks;
	}

	@Override
	public void onUpdateLeaderBoardsResult(int resultCode, String desc) {
		// TODO Auto-generated method stub
		switch (resultCode) {
		case LeaderBoardsResultCode.RECEIVE_SUCCESS:
			Log.e("注意UPDATE_SUCCESS","Execute"+resultCode+desc);
			lbinterface.LihuiLBUpdateSuccessfulCallback("");
			break;
		case LeaderBoardsResultCode.RECEIVE_ERROR:
			Log.e("注意UPDATE_ERROR","Execute"+resultCode+desc);			
			break;
		case LeaderBoardsResultCode.RECEIVE_NONE:
			Log.e("注意UPDATE_NONE","Execute"+resultCode+desc);			
			break;
		default:
			Log.e("注意default","Execute"+resultCode+desc);				
			break;
		}
	}

	@Override
	public void onReceivedLeaderBoardsResult(int resultCode, String desc,
			Ranks ranks) {
		// TODO Auto-generated method stub
		this.ranks = ranks;
		switch (resultCode) {
			case LeaderBoardsResultCode.RECEIVE_SUCCESS:
				Log.e("注意RECEIVE_SUCCESS","Execute"+resultCode+desc);
				lbinterface.LihuiLBReceiveSuccessful("");
				break;
			case LeaderBoardsResultCode.RECEIVE_ERROR:
				Log.e("注意RECEIVE_ERROR","Execute"+resultCode+desc);			
				break;
			case LeaderBoardsResultCode.RECEIVE_NONE:
				Log.e("注意RECEIVE_NONE","Execute"+resultCode+desc);			
				break;
			default:
				Log.e("注意default","Execute"+resultCode+desc);				
				break;
			}
	}
	
}