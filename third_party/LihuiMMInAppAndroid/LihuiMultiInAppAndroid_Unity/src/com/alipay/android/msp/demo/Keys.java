/*
 * Copyright (C) 2010 The MobileSecurePay Project
 * All right reserved.
 * author: shiqun.shi@alipay.com
 * 
 *  提示：如何获取安全校验码和合作身份者id
 *  1.用您的签约支付宝账号登录支付宝网站(www.alipay.com)
 *  2.点击“商家服务”(https://b.alipay.com/order/myorder.htm)
 *  3.点击“查询合作者身份(pid)”、“查询安全校验码(key)”
 */

package com.alipay.android.msp.demo;

//
// 请参考 Android平台安全支付服务(msp)应用开发接口(4.2 RSA算法签名)部分，并使用压缩包中的openssl RSA密钥生成工具，生成一套RSA公私钥。
// 这里签名时，只需要使用生成的RSA私钥。
// Note: 为安全起见，使用RSA私钥进行签名的操作过程，应该尽量放到商家服务器端去进行。
public final class Keys {

	//合作身份者id，以2088开头的16位纯数字
	public static final String DEFAULT_PARTNER = "2088111403788333";

	//收款支付宝账号
	public static final String DEFAULT_SELLER = "chenmt@ibirdgame.com";

	//商户私钥，自助生成
	
	public static final String PRIVATE = "MIICdgIBADANBgkqhkiG9w0BAQEFAASCAmAwggJcAgEAAoGBANs5mBgHGWsZOXBZrGhSJB3jdDoULDR7PDsmkr1OaLJegi4ym3IGguFX9ZaEf8afVUw0xbGM005ah1UN8NO4U+StBPlliTa0KFbKGRfdmpsV7dDOY0QmGxvkkKqjcO2pMulUWkElKr42TGZEGZl8I0eyjVYacR4ZWaoCm9Eoz07zAgMBAAECgYEApDqZPibTW/Ahn5EOH3ippdpnj7rdAtPvY0CaXUcIF9fFHma7HMjT84y5ZnEMZ/elJtnB4Cjng6M+DvHKoFFORnZ+bi7nIy7dF/hq85AlYTm/KUMzoLbHD46oHObay4pfAwetq7g+sDq7FgachNy3BjrMYpie0CosjZ/i6EbaPEECQQDv3lu4zZaLa2A/fhrK1Z7rCyCyER/AJCFvVIQkoG1MosPo+E4d+2XeYCusd6ODSQSA22rtAhK/622uNpEtJxc9AkEA6ffUdZnI10TVDtL9br6Ny9vKFhR32xlxZaK0/xZRiAQVXce22GkoksOjE9ghI8xF2rUPkV+lz9UlR8Dae7Th7wJAJ0eWZZDlEjenLz6LTKPmvj64P/Cl7mT8RKrmaMkMnPwacNAYmrhMWjoNbNS6pgkS/7bur5kjUOJQt7Kf23EHUQJADZZk8kdyEH5g2TGLokjSt0oWXF3n8AN0QHDIjh/fsER8cSvOBJdm0c8mw1pD4m5UiDUHqGujl4RLW/VpOtHwZQJAaSQggxSg1jV1WA7iiEr5MoDHLlkkqVDuuJ/Avih3vQdLbsl+2jOFpVtyBB7isnqgha/nt5PQRa2r+EddgALMKQ==";

	public static final String PUBLIC = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCnxj/9qwVfgoUh/y2W89L6BkRAFljhNhgPdyPuBV64bfQNN1PjbCzkIM6qRdKBoLPXmKKMiFYnkd6rAoprih3/PrQEB/VsW8OoM8fxn67UDYuyBTqA23MML9q1+ilIZwBC2AQ2UBVOrFXfFl75p6/B5KsiNG9zpgmLCUYuLkxpLQIDAQAB";

}
