/*
 * android-specific implementation of the Lihui2048Api extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "Lihui2048Api_internal.h"

#include "s3eEdk.h"
#include "s3eEdk_android.h"
#include <jni.h>
#include "IwDebug.h"

static jobject g_Obj;
static jmethodID g_isMovable;
static jmethodID g_move;
static jmethodID g_getCurrentScore;
static jmethodID g_getBestScore;
static jmethodID g_reset;
static jmethodID g_isWin;
static jmethodID g_getValue;
static jmethodID g_getAnim;

s3eResult Lihui2048ApiInit_platform()
{
    // Get the environment from the pointer
    JNIEnv* env = s3eEdkJNIGetEnv();
    jobject obj = NULL;
    jmethodID cons = NULL;

    // Get the extension class
    jclass cls = s3eEdkAndroidFindClass("com.lihui.lihui2048.Lihui2048");
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
    g_isMovable = env->GetMethodID(cls, "isMovable", "()Z");
    if (!g_isMovable)
        goto fail;

    g_move = env->GetMethodID(cls, "move", "(I)V");
    if (!g_move)
        goto fail;

    g_getCurrentScore = env->GetMethodID(cls, "getCurrentScore", "()I");
    if (!g_getCurrentScore)
        goto fail;

    g_getBestScore = env->GetMethodID(cls, "getBestScore", "()I");
    if (!g_getBestScore)
        goto fail;

    g_reset = env->GetMethodID(cls, "reset", "()V");
    if (!g_reset)
        goto fail;

    g_isWin = env->GetMethodID(cls, "isWin", "()Z");
    if (!g_isWin)
        goto fail;

    g_getValue = env->GetMethodID(cls, "getValue", "(II)I");
    if (!g_getValue)
        goto fail;

    g_getAnim = env->GetMethodID(cls, "getAnim", "(II)I");
    if (!g_getAnim)
        goto fail;



    IwTrace(LIHUI2048API, ("LIHUI2048API init success"));
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
        IwTrace(Lihui2048Api, ("One or more java methods could not be found"));
    }
    return S3E_RESULT_ERROR;

}

void Lihui2048ApiTerminate_platform()
{
    // Add any platform-specific termination code here
}

bool isMovable_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_isMovable);
}

void move_platform(int type)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_move, type);
}

int getCurrentScore_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_getCurrentScore);
}

int getBestScore_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_getBestScore);
}

void reset_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    env->CallVoidMethod(g_Obj, g_reset);
}

bool isWin_platform()
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (bool)env->CallBooleanMethod(g_Obj, g_isWin);
}

int getValue_platform(int x, int y)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_getValue, x, y);
}

int getAnim_platform(int x, int y)
{
    JNIEnv* env = s3eEdkJNIGetEnv();
    return (int)env->CallIntMethod(g_Obj, g_getAnim, x, y);
}
