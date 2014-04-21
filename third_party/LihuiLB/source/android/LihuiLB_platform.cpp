/*
 * android-specific implementation of the LihuiLB extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "LihuiLB_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_initLB;
static jmethodID g_updateScore;
static jmethodID g_receiveRank;
static jmethodID g_getScore;
static jmethodID g_getUserRank;
static jmethodID g_getNextWeekLeftSeconds;
static jmethodID g_notUnlimetedLives;
static jmethodID g_setBeijingTime;
static jmethodID g_notShared;
static jmethodID g_setShareTime;
static jmethodID g_getNickname;
static jmethodID g_updateNickname;

void JNICALL LihuiLB_Receive_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiLB_Receive_FailedCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiLB_Update_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id);
void JNICALL LihuiLB_Update_FailedCallback(JNIEnv* env, jobject obj, jstring id);

s3eResult LihuiLBInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = env->FindClass("cn/lihui/test/LBInterface");
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
    g_initLB = env->GetMethodID(cls, "initLB", "()V");
    if (!g_initLB)
        goto fail;

    g_updateScore = env->GetMethodID(cls, "updateScore", "(I)V");
    if (!g_updateScore)
        goto fail;

    g_receiveRank = env->GetMethodID(cls, "receiveRank", "()V");
    if (!g_receiveRank)
        goto fail;

    g_getScore = env->GetMethodID(cls, "getScore", "(I)I");
    if (!g_getScore)
        goto fail;

    g_getUserRank = env->GetMethodID(cls, "getUserRank", "()I");
    if (!g_getUserRank)
        goto fail;

    g_getNextWeekLeftSeconds = env->GetMethodID(cls, "getNextWeekLeftSeconds", "()I");
    if (!g_getNextWeekLeftSeconds)
        goto fail;

    g_notUnlimetedLives = env->GetMethodID(cls, "notUnlimetedLives", "()Z");
    if (!g_notUnlimetedLives)
        goto fail;

    g_setBeijingTime = env->GetMethodID(cls, "setBeijingTime", "()V");
    if (!g_setBeijingTime)
        goto fail;

    g_notShared = env->GetMethodID(cls, "notShared", "()Z");
    if (!g_notShared)
        goto fail;

    g_setShareTime = env->GetMethodID(cls, "setShareTime", "()V");
    if (!g_setShareTime)
        goto fail;

    g_getNickname = env->GetMethodID(cls, "getNickname", "()Ljava/lang/String;");
    if (!g_getNickname)
        goto fail;

    g_updateNickname = env->GetMethodID(cls, "updateNickname", "(Ljava/lang/String;)V");
    if (!g_updateNickname)
        goto fail;

	{
        static const JNINativeMethod methods[]=
        {
            {"LihuiLBReceiveSuccessful","(Ljava/lang/String;)V",(void*)&LihuiLB_Receive_SuccessfulCallback},
            {"LihuiLBReceiveFailedCallback","(Ljava/lang/String;)V",(void*)&LihuiLB_Receive_FailedCallback},
            {"LihuiLBUpdateSuccessfulCallback","(Ljava/lang/String;)V",(void*)&LihuiLB_Update_SuccessfulCallback},
            {"LihuiLBUpdateFailedCallback","(Ljava/lang/String;)V",(void*)&LihuiLB_Update_FailedCallback},
        };
        // Register the native hooks
        if(env->RegisterNatives(cls,methods,sizeof(methods)/sizeof(methods[0])))
            goto fail;
    }


    IwTrace(LIHUILB, ("LIHUILB init success"));
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
        IwTrace(LihuiLB, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void LihuiLBTerminate_platform()
{
    // Add any platform-specific termination code here
}

void initLB_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_initLB);
}

void updateScore_platform(int score)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_updateScore, score);
}

void receiveRank_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_receiveRank);
}

int getScore_platform(int rank)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_getScore, rank);
}

int getUserRank_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_getUserRank);
}

int getNextWeekLeftSeconds_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_getNextWeekLeftSeconds);
}

bool notUnlimetedLives_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_notUnlimetedLives);
}

void setBeijingTime_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_setBeijingTime);
}

bool notShared_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_notShared);
}

void setShareTime_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_setShareTime);
}

static char NickName[256];
const char* getNickname_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();	
	jstring s = (jstring)env->CallObjectMethod(g_Obj, g_getNickname);
    const char *str = env->GetStringUTFChars(s, 0);
    if (str == NULL) { 
    	sprintf(NickName, "");
        return NickName;
    }
    sprintf(NickName, "%s", str);
    env->ReleaseStringUTFChars(s, str);  
    return NickName;
}

void updateNickname_platform(const char* nickname)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    jstring nickname_jstr = env->NewStringUTF(nickname);
    env->CallVoidMethod(g_Obj, g_updateNickname, nickname_jstr);
}

void JNICALL LihuiLB_Receive_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUILB_HASH, LIHUILB_CALLBACK_REICEIVE_SUCCESSFUL, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiLB_Receive_FailedCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUILB_HASH, LIHUILB_CALLBACK_REICEIVE_FAILED, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiLB_Update_SuccessfulCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUILB_HASH, LIHUILB_CALLBACK_UPDATE_SUCCESSFUL, key,
                           (len+1)*sizeof(char));
}

void JNICALL LihuiLB_Update_FailedCallback(JNIEnv* env, jobject obj, jstring id)
{
    const char* utf = env->GetStringUTFChars(id,NULL);
    jsize len = env->GetStringLength(id);

    char* key = new char[len+1];
    memcpy(key, utf, len+1); //faster strcpy, since length is known

    env->ReleaseStringUTFChars(id,utf);

    s3eEdkCallbacksEnqueue(S3E_EXT_LIHUILB_HASH, LIHUILB_CALLBACK_UPDATE_FAILED, key,
                           (len+1)*sizeof(char));
}
