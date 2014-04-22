/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "LihuiLB.h"


// For MIPs (and WP8) platform we do not have asm code for stack switching 
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*LihuiLBRegister_t)(LihuiLBCallback cbid, s3eCallback fn, void* userData);
typedef  s3eResult(*LihuiLBUnRegister_t)(LihuiLBCallback cbid, s3eCallback fn);
typedef       void(*initLB_t)();
typedef       void(*updateScore_t)(int score);
typedef       void(*receiveRank_t)();
typedef        int(*getScore_t)(int rank);
typedef        int(*getUserRank_t)();
typedef        int(*getNextWeekLeftSeconds_t)();
typedef       bool(*notUnlimetedLives_t)();
typedef       void(*setBeijingTime_t)();
typedef       bool(*notShared_t)();
typedef       void(*setShareTime_t)();
typedef const char*(*getNickname_t)();
typedef const char*(*getNicknameByRank_t)(int rank);
typedef       void(*updateNickname_t)(const char* nickname);

/**
 * struct that gets filled in by LihuiLBRegister
 */
typedef struct LihuiLBFuncs
{
    LihuiLBRegister_t m_LihuiLBRegister;
    LihuiLBUnRegister_t m_LihuiLBUnRegister;
    initLB_t m_initLB;
    updateScore_t m_updateScore;
    receiveRank_t m_receiveRank;
    getScore_t m_getScore;
    getUserRank_t m_getUserRank;
    getNextWeekLeftSeconds_t m_getNextWeekLeftSeconds;
    notUnlimetedLives_t m_notUnlimetedLives;
    setBeijingTime_t m_setBeijingTime;
    notShared_t m_notShared;
    setShareTime_t m_setShareTime;
    getNickname_t m_getNickname;
    getNicknameByRank_t m_getNicknameByRank;
    updateNickname_t m_updateNickname;
} LihuiLBFuncs;

static LihuiLBFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x79dad28e, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: LihuiLB");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x79dad28e, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool LihuiLBAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult LihuiLBRegister(LihuiLBCallback cbid, s3eCallback fn, void* userData)
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[0] func: LihuiLBRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_LihuiLBRegister(cbid, fn, userData);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult LihuiLBUnRegister(LihuiLBCallback cbid, s3eCallback fn)
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[1] func: LihuiLBUnRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_LihuiLBUnRegister(cbid, fn);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void initLB()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[2] func: initLB"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_initLB();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void updateScore(int score)
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[3] func: updateScore"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_updateScore(score);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void receiveRank()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[4] func: receiveRank"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_receiveRank();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

int getScore(int rank)
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[5] func: getScore"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_getScore(rank);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int getUserRank()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[6] func: getUserRank"));

    if (!_extLoad())
        return 1;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_getUserRank();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

int getNextWeekLeftSeconds()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[7] func: getNextWeekLeftSeconds"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    int ret = g_Ext.m_getNextWeekLeftSeconds();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool notUnlimetedLives()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[8] func: notUnlimetedLives"));

    if (!_extLoad())
        return true;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_notUnlimetedLives();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void setBeijingTime()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[9] func: setBeijingTime"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_setBeijingTime();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

bool notShared()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[10] func: notShared"));

    if (!_extLoad())
        return true;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_notShared();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void setShareTime()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[11] func: setShareTime"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_setShareTime();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

const char* getNickname()
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[12] func: getNickname"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    const char* ret = g_Ext.m_getNickname();

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

const char* getNicknameByRank(int rank)
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[13] func: getNicknameByRank"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    const char* ret = g_Ext.m_getNicknameByRank(rank);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void updateNickname(const char* nickname)
{
    IwTrace(LIHUILB_VERBOSE, ("calling LihuiLB[14] func: updateNickname"));

    if (!_extLoad())
        return;

#ifdef LOADER_CALL
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_updateNickname(nickname);

#ifdef LOADER_CALL
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
