/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "LihuiDomob.h"


// For MIPs (and WP8) platform we do not have asm code for stack switching 
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*LihuiDomobRegister_t)(LihuiDomobCallback cbid, s3eCallback fn, void* userData);
typedef  s3eResult(*LihuiDomobUnRegister_t)(LihuiDomobCallback cbid, s3eCallback fn);
typedef       void(*initDoAd_t)();
typedef       void(*showDoBanner_t)();
typedef       void(*showDoInter_t)();
typedef       void(*showDoSplash_t)();
typedef       void(*checkPoints_t)();
typedef       void(*usePoints_t)(int point);
typedef       void(*getPoints_t)();

/**
 * struct that gets filled in by LihuiDomobRegister
 */
typedef struct LihuiDomobFuncs
{
    LihuiDomobRegister_t m_LihuiDomobRegister;
    LihuiDomobUnRegister_t m_LihuiDomobUnRegister;
    initDoAd_t m_initDoAd;
    showDoBanner_t m_showDoBanner;
    showDoInter_t m_showDoInter;
    showDoSplash_t m_showDoSplash;
    checkPoints_t m_checkPoints;
    usePoints_t m_usePoints;
    getPoints_t m_getPoints;
} LihuiDomobFuncs;

static LihuiDomobFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xd687ab11, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: LihuiDomob");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xd687ab11, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool LihuiDomobAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult LihuiDomobRegister(LihuiDomobCallback cbid, s3eCallback fn, void* userData)
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[0] func: LihuiDomobRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_LihuiDomobRegister(cbid, fn, userData);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult LihuiDomobUnRegister(LihuiDomobCallback cbid, s3eCallback fn)
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[1] func: LihuiDomobUnRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_LihuiDomobUnRegister(cbid, fn);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void initDoAd()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[2] func: initDoAd"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_initDoAd();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void showDoBanner()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[3] func: showDoBanner"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_showDoBanner();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void showDoInter()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[4] func: showDoInter"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_showDoInter();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void showDoSplash()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[5] func: showDoSplash"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_showDoSplash();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void checkPoints()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[6] func: checkPoints"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_checkPoints();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void usePoints(int point)
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[7] func: usePoints"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_usePoints(point);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void getPoints()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob[8] func: getPoints"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_getPoints();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}