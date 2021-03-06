/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "LihuiMMInApp.h"


// For MIPs (and WP8) platform we do not have asm code for stack switching 
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*LihuiMMInAppRegister_t)(LihuiMMInAppCallback cbid, s3eCallback fn, void* userData);
typedef  s3eResult(*LihuiMMInAppUnRegister_t)(LihuiMMInAppCallback cbid, s3eCallback fn);
typedef       void(*LihuiInAppStart_t)();
typedef       void(*LihuiInAppRestorePurchases_t)();
typedef       void(*LihuiInAppBuyItem_t)(const char* itemId);

/**
 * struct that gets filled in by LihuiMMInAppRegister
 */
typedef struct LihuiMMInAppFuncs
{
    LihuiMMInAppRegister_t m_LihuiMMInAppRegister;
    LihuiMMInAppUnRegister_t m_LihuiMMInAppUnRegister;
    LihuiInAppStart_t m_LihuiInAppStart;
    LihuiInAppRestorePurchases_t m_LihuiInAppRestorePurchases;
    LihuiInAppBuyItem_t m_LihuiInAppBuyItem;
} LihuiMMInAppFuncs;

static LihuiMMInAppFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x46f7a112, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: LihuiMMInApp");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x46f7a112, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool LihuiMMInAppAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult LihuiMMInAppRegister(LihuiMMInAppCallback cbid, s3eCallback fn, void* userData)
{
    IwTrace(LIHUIMMINAPP_VERBOSE, ("calling LihuiMMInApp[0] func: LihuiMMInAppRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_LihuiMMInAppRegister(cbid, fn, userData);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult LihuiMMInAppUnRegister(LihuiMMInAppCallback cbid, s3eCallback fn)
{
    IwTrace(LIHUIMMINAPP_VERBOSE, ("calling LihuiMMInApp[1] func: LihuiMMInAppUnRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_LihuiMMInAppUnRegister(cbid, fn);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void LihuiInAppStart()
{
    IwTrace(LIHUIMMINAPP_VERBOSE, ("calling LihuiMMInApp[2] func: LihuiInAppStart"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_LihuiInAppStart();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void LihuiInAppRestorePurchases()
{
    IwTrace(LIHUIMMINAPP_VERBOSE, ("calling LihuiMMInApp[3] func: LihuiInAppRestorePurchases"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_LihuiInAppRestorePurchases();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void LihuiInAppBuyItem(const char* itemId)
{
    IwTrace(LIHUIMMINAPP_VERBOSE, ("calling LihuiMMInApp[4] func: LihuiInAppBuyItem"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_LihuiInAppBuyItem(itemId);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
