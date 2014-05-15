package cn.lihui;

import com.umeng.analytics.MobclickAgent;

public class LihuiActivity extends com.ideaworks3d.marmalade.LoaderActivity {

	protected void onPause() {
		super.onPause();
		MobclickAgent.onPause(this);
	}

	protected void onResume() {
		super.onResume();
		MobclickAgent.onResume(this);
	}
}
