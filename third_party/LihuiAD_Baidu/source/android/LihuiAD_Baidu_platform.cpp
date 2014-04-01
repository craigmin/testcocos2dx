/*
 * android-specific implementation of the LihuiAD_Baidu extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "LihuiAD_Baidu_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_InitBdAd;
static jmethodID g_SetBdAdPosition;
static jmethodID g_GetBdAdHeight;
static jmethodID g_showBdInter;

s3eResult LihuiAD_BaiduInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = env->FindClass("cn/lihui/baiduad/LihuiADInterface");
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
    g_InitBdAd = env->GetMethodID(cls, "InitBdAd", "()V");
    if (!g_InitBdAd)
        goto fail;

    g_SetBdAdPosition = env->GetMethodID(cls, "SetBdAdPosition", "(I)V");
    if (!g_SetBdAdPosition)
        goto fail;

    g_GetBdAdHeight = env->GetMethodID(cls, "GetBdAdHeight", "()I");
    if (!g_GetBdAdHeight)
        goto fail;

    g_showBdInter = env->GetMethodID(cls, "showBdInter", "()V");
    if (!g_showBdInter)
        goto fail;



    IwTrace(LIHUIAD_BAIDU, ("LIHUIAD_BAIDU init success"));
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
        IwTrace(LihuiAD_Baidu, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void LihuiAD_BaiduTerminate_platform()
{
    // Add any platform-specific termination code here
}

void InitBdAd_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_InitBdAd);
}

void SetBdAdPosition_platform(int opt)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_SetBdAdPosition, opt);
}

int GetBdAdHeight_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_GetBdAdHeight);
}

void showBdInter_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_showBdInter);
}
