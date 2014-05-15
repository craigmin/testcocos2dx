/*
 * android-specific implementation of the LihuiDomob extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "LihuiDomob_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_initDoAd;
static jmethodID g_showDoBanner;
static jmethodID g_showDoInter;
static jmethodID g_showDoSplash;
static jmethodID g_checkPoints;
static jmethodID g_usePoints;
static jmethodID g_getPoints;

void JNICALL LihuiDO_Splash_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiDO_Splash_FailedCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiDO_Point_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiDO_Point_FailedCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiDO_Consume_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiDO_Consume_FailedCallback(JNIEnv* env, jobject obj, jstring id);

s3eResult LihuiDomobInit_platform()
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
    g_initDoAd = env->GetMethodID(cls, "initDoAd", "()V");
    if (!g_initDoAd)
        goto fail;

    g_showDoBanner = env->GetMethodID(cls, "showDoBanner", "()V");
    if (!g_showDoBanner)
        goto fail;

    g_showDoInter = env->GetMethodID(cls, "showDoInter", "()V");
    if (!g_showDoInter)
        goto fail;

    g_showDoSplash = env->GetMethodID(cls, "showDoSplash", "()V");
    if (!g_showDoSplash)
        goto fail;

    g_checkPoints = env->GetMethodID(cls, "checkPoints", "()V");
    if (!g_checkPoints)
        goto fail;

    g_usePoints = env->GetMethodID(cls, "usePoints", "(I)V");
    if (!g_usePoints)
        goto fail;

    g_getPoints = env->GetMethodID(cls, "getPoints", "()V");
    if (!g_getPoints)
        goto fail;

	{
        static const JNINativeMethod methods[]=
        {
            {"LihuiSplashSuccessful","(Ljava/lang/String;)V",(void*)&LihuiDO_Splash_SuccessfulCallback},
            {"LihuiSplashFailedCallback","(Ljava/lang/String;)V",(void*)&LihuiDO_Splash_FailedCallback},
            {"LihuiPointSuccessfulCallback","(Ljava/lang/String;)V",(void*)&LihuiDO_Point_SuccessfulCallback},
            {"LihuiPointFailedCallback","(Ljava/lang/String;)V",(void*)&LihuiDO_Point_FailedCallback},
			 {"LihuiConsumeSuccessfulCallback","(Ljava/lang/String;)V",(void*)&LihuiDO_Consume_SuccessfulCallback},
            {"LihuiConsumeFailedCallback","(Ljava/lang/String;)V",(void*)&LihuiDO_Consume_FailedCallback},
        };
        // Register the native hooks
        if(env->RegisterNatives(cls,methods,sizeof(methods)/sizeof(methods[0])))
            goto fail;
    }

    IwTrace(LIHUIDOMOB, ("LIHUIDOMOB init success"));
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
        IwTrace(LihuiDomob, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void LihuiDomobTerminate_platform()
{
    // Add any platform-specific termination code here
}

void initDoAd_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_initDoAd);
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

void checkPoints_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_checkPoints);
}

void usePoints_platform(int point)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_usePoints, point);
}

void getPoints_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_getPoints);
}
void JNICALL LihuiDO_Splash_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIDOMOB_HASH, LIHUIDO_CALLBACK_SPLASH_SUCCESSFUL, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiDO_Splash_FailedCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIDOMOB_HASH, LIHUIDO_CALLBACK_SPLASH_FAILED, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiDO_Point_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIDOMOB_HASH, LIHUIDO_CALLBACK_POINT_SUCCESSFUL, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiDO_Point_FailedCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIDOMOB_HASH, LIHUIDO_CALLBACK_POINT_FAILED, key,
                           (len+1)*sizeof(char));
}
void JNICALL LihuiDO_Consume_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIDOMOB_HASH, LIHUIDO_CALLBACK_CONSUME_SUCCESSFUL, key,
                           (len+1)*sizeof(char));
}
void JNICALL LihuiDO_Consume_FailedCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUIDOMOB_HASH, LIHUIDO_CALLBACK_CONSUME_FAILED, key,
                           (len+1)*sizeof(char));
}