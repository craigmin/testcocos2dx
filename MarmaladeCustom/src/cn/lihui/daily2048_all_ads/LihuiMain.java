/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
package cn.lihui.daily2048_all_ads;

import android.os.Bundle;
import cn.lihui.LihuiActivity;
import cn.lihui.daily2048_ads.ads.CocoAds;
import cn.lihui.daily2048_ads.ads.DomobAds;
import cn.lihui.daily2048_ads.ads.IAds;
import cn.lihui.daily2048_ads.ads.SsjjAds;

public class LihuiMain extends LihuiActivity {
	// Jerry Test
	IAds ads;

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		ads = new SsjjAds();
		ads.init();
	}

	protected void onResume() {
		super.onResume();
		ads.showDoInter();
	}

	@Override
	protected void onDestroy() {
		ads.destroy(this);
		super.onDestroy();
	}
}
