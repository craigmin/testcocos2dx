/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "LihuiDomob_autodefs.h"
#include "s3eEdk.h"
#include "LihuiDomob.h"
//Declarations of Init and Term functions
extern s3eResult LihuiDomobInit();
extern void LihuiDomobTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static void initDoAd_wrap()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob func on main thread: initDoAd"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)initDoAd, 0);
}

static void showDoBanner_wrap()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob func on main thread: showDoBanner"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)showDoBanner, 0);
}

static void showDoInter_wrap()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob func on main thread: showDoInter"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)showDoInter, 0);
}

static void showDoSplash_wrap()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob func on main thread: showDoSplash"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)showDoSplash, 0);
}

static void checkPoints_wrap()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob func on main thread: checkPoints"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)checkPoints, 0);
}

static void usePoints_wrap(int point)
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob func on main thread: usePoints"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)usePoints, 1, point);
}

static void getPoints_wrap()
{
    IwTrace(LIHUIDOMOB_VERBOSE, ("calling LihuiDomob func on main thread: getPoints"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)getPoints, 0);
}

#define initDoAd initDoAd_wrap
#define showDoBanner showDoBanner_wrap
#define showDoInter showDoInter_wrap
#define showDoSplash showDoSplash_wrap
#define checkPoints checkPoints_wrap
#define usePoints usePoints_wrap
#define getPoints getPoints_wrap

#endif

s3eResult LihuiDomobRegister(LihuiDomobCallback cbid, s3eCallback fn, void* pData)
{
    return s3eEdkCallbacksRegister(S3E_EXT_LIHUIDOMOB_HASH, LIHUIDOMOB_CALLBACK_MAX, cbid, fn, pData, 0);
};

s3eResult LihuiDomobUnRegister(LihuiDomobCallback cbid, s3eCallback fn)
{
    return s3eEdkCallbacksUnRegister(S3E_EXT_LIHUIDOMOB_HASH, LIHUIDOMOB_CALLBACK_MAX, cbid, fn);
}

void LihuiDomobRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[9];
    funcPtrs[0] = (void*)LihuiDomobRegister;
    funcPtrs[1] = (void*)LihuiDomobUnRegister;
    funcPtrs[2] = (void*)initDoAd;
    funcPtrs[3] = (void*)showDoBanner;
    funcPtrs[4] = (void*)showDoInter;
    funcPtrs[5] = (void*)showDoSplash;
    funcPtrs[6] = (void*)checkPoints;
    funcPtrs[7] = (void*)usePoints;
    funcPtrs[8] = (void*)getPoints;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[9] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("LihuiDomob", funcPtrs, sizeof(funcPtrs), flags, LihuiDomobInit, LihuiDomobTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int LihuiDomobStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&LihuiDomobRegisterExt;
    return 0;
}

int g_LihuiDomobVal = LihuiDomobStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    LihuiDomobRegisterExt();
}
#endif

#endif
