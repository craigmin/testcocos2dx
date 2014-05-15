/*
 * android-specific implementation of the LihuiMMInApp extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "LihuiMMInApp_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_LihuiInAppStart;
static jmethodID g_LihuiInAppRestorePurchases;
static jmethodID g_LihuiInAppBuyItem;
static jmethodID g_LihuiInAppBuyItemEx;

void JNICALL LihuiInApp_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiInApp_FailedCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiInApp_RevokedCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiInApp_RestoredCallback(JNIEnv* env, jobject obj, jstring id);


s3eResult LihuiMMInAppInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = env->FindClass("cn/lihui/iap/mm/LihuiInAppPurchase");
    if (!cls)
        goto fail;

    // Get its constructor
    cons = env->GetMethodID(cls, "<init>", "()V");
    if (!cons)
        goto fail;

    // Construct the java class
    obj = env->NewObject(cls, cons);
    if (!obj)
        goto fail;

    // Get all the extension methods
    g_LihuiInAppStart = env->GetMethodID(cls, "LihuiInAppStart", "()V");
    if (!g_LihuiInAppStart)
        goto fail;

    g_LihuiInAppRestorePurchases = env->GetMethodID(cls, "LihuiInAppRestorePurchases", "()V");
    if (!g_LihuiInAppRestorePurchases)
        goto fail;

    g_LihuiInAppBuyItem = env->GetMethodID(cls, "LihuiInAppBuyItem", "(Ljava/lang/String;)V");
    if (!g_LihuiInAppBuyItem)
        goto fail;
		
	 g_LihuiInAppBuyItemEx = env->GetMethodID(cls, "LihuiInAppBuyItemEx", "(Ljava/lang/String;)V");
    if (!g_LihuiInAppBuyItemEx)
        goto fail;

	{
        static const JNINativeMethod methods[]=
        {
            {"LihuiInAppPurchaseSuccessful","(Ljava/lang/String;)V",(void*)&LihuiInApp_SuccessfulCallback},
            {"LihuiInAppPurchaseFailed","(Ljava/lang/String;)V",(void*)&LihuiInApp_FailedCallback},
            {"LihuiInAppPurchaseRestored","(Ljava/lang/String;)V",(void*)&LihuiInApp_RestoredCallback},
            {"LihuiInAppPurchaseRevoked","(Ljava/lang/String;)V",(void*)&LihuiInApp_RevokedCallback},
        };
        // Register the native hooks
        if(env->RegisterNatives(cls,methods,sizeof(methods)/sizeof(methods[0])))
            goto fail;
    }

    IwTrace(LIHUIMMINAPP, ("LIHUIMMINAPP init success"));
    g_Obj = env->NewGlobalRef(obj);
    env->DeleteLocalRef(obj);
    env->DeleteGlobalRef(cls);

    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;

fail:
    jthrowable exc = env->ExceptionOccurred();
    if (exc)
    {
        env->ExceptionDescribe();
        env->ExceptionClear();
        IwTrace(LihuiMMInApp, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void LihuiMMInAppTerminate_platform()
{
    // Add any platform-specific termination code here
}

void LihuiInAppStart_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_LihuiInAppStart);
}

void LihuiInAppRestorePurchases_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_LihuiInAppRestorePurchases);
}

void LihuiInAppBuyItem_platform(const char* itemId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring itemId_jstr = env->NewStringUTF(itemId);
    env->CallVoidMethod(g_Obj, g_LihuiInAppBuyItem, itemId_jstr);
}
void LihuiInAppBuyItemEx_platform(const char* itemId)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring itemId_jstr = env->NewStringUTF(itemId);
    env->CallVoidMethod(g_Obj, g_LihuiInAppBuyItemEx, itemId_jstr);
}

void JNICALL LihuiInApp_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIMMINAPP_HASH, LIHUIMMINAPP_CALLBACK_PURCHASE_SUCCESSFUL, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiInApp_FailedCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIMMINAPP_HASH, LIHUIMMINAPP_CALLBACK_PURCHASE_FAILED, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiInApp_RevokedCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIMMINAPP_HASH, LIHUIMMINAPP_CALLBACK_PURCHASE_REVOKED, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiInApp_RestoredCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIMMINAPP_HASH, LIHUIMMINAPP_CALLBACK_PURCHASE_RESTORED, key,
                           (len+1)*sizeof(char));
}
