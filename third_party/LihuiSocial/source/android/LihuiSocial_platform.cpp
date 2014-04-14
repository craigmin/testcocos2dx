/*
 * android-specific implementation of the LihuiSocial extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "LihuiSocial_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_connectToWX;
static jmethodID g_sendMessageOnWX;
static jmethodID g_isWXLoggedIn;
void JNICALL LihuiSocial_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiSocial_FailedCallback(JNIEnv* env, jobject obj, jstring id);

s3eResult LihuiSocialInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("com/lihui/social4wx/LihuiSocial");
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
    g_connectToWX = env->GetMethodID(cls, "connectToWX", "()V");
    if (!g_connectToWX)
        goto fail;

    g_sendMessageOnWX = env->GetMethodID(cls, "sendMessageOnWX", "()V");
    if (!g_sendMessageOnWX)
        goto fail;

    g_isWXLoggedIn = env->GetMethodID(cls, "isWXLoggedIn", "()I");
    if (!g_isWXLoggedIn)
        goto fail;
	{
        static const JNINativeMethod methods[]=
        {
            {"LihuiSocialShareSuccessful","(Ljava/lang/String;)V",(void*)&LihuiSocial_SuccessfulCallback},
            {"LihuiSocialShareFailed","(Ljava/lang/String;)V",(void*)&LihuiSocial_FailedCallback},
        };
        // Register the native hooks
        if(env->RegisterNatives(cls,methods,sizeof(methods)/sizeof(methods[0])))
            goto fail;
    }

    IwTrace(LIHUISOCIAL, ("LIHUISOCIAL init success"));
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
        IwTrace(LihuiSocial, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void LihuiSocialTerminate_platform()
{
    // Add any platform-specific termination code here
}

void connectToWX_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_connectToWX);
}

void sendMessageOnWX_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_sendMessageOnWX);
}

int isWXLoggedIn_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_isWXLoggedIn);
}
void JNICALL LihuiSocial_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUISOCIAL_HASH, LIHUISOCIAL_CALLBACK_SHARE_SUCCESSFUL, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiSocial_FailedCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUISOCIAL_HASH, LIHUISOCIAL_CALLBACK_SHARE_FAILED, key,
                           (len+1)*sizeof(char));
}
