/*
 * android-specific implementation of the LihuiDomod extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "LihuiDomod_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_showDoBanner;
static jmethodID g_showDoInter;
static jmethodID g_showDoSplash;

s3eResult LihuiDomodInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("cn.lihui.domod.Lihui2048");
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
    g_showDoBanner = env->GetMethodID(cls, "showDoBanner", "()V");
    if (!g_showDoBanner)
        goto fail;

    g_showDoInter = env->GetMethodID(cls, "showDoInter", "()V");
    if (!g_showDoInter)
        goto fail;

    g_showDoSplash = env->GetMethodID(cls, "showDoSplash", "()V");
    if (!g_showDoSplash)
        goto fail;



    IwTrace(LIHUIDOMOD, ("LIHUIDOMOD init success"));
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
        IwTrace(LihuiDomod, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void LihuiDomodTerminate_platform()
{
    // Add any platform-specific termination code here
}

void showDoBanner_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_showDoBanner);
}

void showDoInter_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_showDoInter);
}

void showDoSplash_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_showDoSplash);
}
