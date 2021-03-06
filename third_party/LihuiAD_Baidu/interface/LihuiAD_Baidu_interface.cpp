/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "LihuiAD_Baidu.h"


// For MIPs (and WP8) platform we do not have asm code for stack switching 
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*InitBdAd_t)();
typedef       void(*SetBdAdPosition_t)(int opt);
typedef        int(*GetBdAdHeight_t)();
typedef       void(*showBdInter_t)();

/**
 * struct that gets filled in by LihuiAD_BaiduRegister
 */
typedef struct LihuiAD_BaiduFuncs
{
    InitBdAd_t m_InitBdAd;
    SetBdAdPosition_t m_SetBdAdPosition;
    GetBdAdHeight_t m_GetBdAdHeight;
    showBdInter_t m_showBdInter;
} LihuiAD_BaiduFuncs;

static LihuiAD_BaiduFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x45dccac9, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: LihuiAD_Baidu");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x45dccac9, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool LihuiAD_BaiduAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void InitBdAd()
{
    IwTrace(LIHUIAD_BAIDU_VERBOSE, ("calling LihuiAD_Baidu[0] func: InitBdAd"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_InitBdAd();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void SetBdAdPosition(int opt)
{
    IwTrace(LIHUIAD_BAIDU_VERBOSE, ("calling LihuiAD_Baidu[1] func: SetBdAdPosition"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_SetBdAdPosition(opt);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

int GetBdAdHeight()
{
    IwTrace(LIHUIAD_BAIDU_VERBOSE, ("calling LihuiAD_Baidu[2] func: GetBdAdHeight"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_GetBdAdHeight();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void showBdInter()
{
    IwTrace(LIHUIAD_BAIDU_VERBOSE, ("calling LihuiAD_Baidu[3] func: showBdInter"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_showBdInter();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
