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
#include "Lihui2048Api_autodefs.h"
#include "s3eEdk.h"
#include "Lihui2048Api.h"
//Declarations of Init and Term functions
extern s3eResult Lihui2048ApiInit();
extern void Lihui2048ApiTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static bool isMovable_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: isMovable"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)isMovable, 0);
}

static void move_wrap(int type)
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: move"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)move, 1, type);
}

static int getCurrentScore_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: getCurrentScore"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)getCurrentScore, 0);
}

static int getBestScore_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: getBestScore"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)getBestScore, 0);
}

static void reset_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: reset"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)reset, 0);
}

static bool isWin_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: isWin"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)isWin, 0);
}

static int getValue_wrap(int x, int y)
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: getValue"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)getValue, 2, x, y);
}

static int getAnim_wrap(int x, int y)
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: getAnim"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)getAnim, 2, x, y);
}

static void cleanRect_wrap(int x, int y)
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: cleanRect"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)cleanRect, 2, x, y);
}

static void reArrange_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: reArrange"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)reArrange, 0);
}

static int getBombs_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: getBombs"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)getBombs, 0);
}

static int getRearranges_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: getRearranges"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)getRearranges, 0);
}

static void addBombs_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: addBombs"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)addBombs, 0);
}

static void addRearranges_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: addRearranges"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)addRearranges, 0);
}

static void useBombs_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: useBombs"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)useBombs, 0);
}

static void useRearranges_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: useRearranges"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)useRearranges, 0);
}

static int getEmptyPoints_wrap()
{
    IwTrace(LIHUI2048API_VERBOSE, ("calling Lihui2048Api func on main thread: getEmptyPoints"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)getEmptyPoints, 0);
}

#define isMovable isMovable_wrap
#define move move_wrap
#define getCurrentScore getCurrentScore_wrap
#define getBestScore getBestScore_wrap
#define reset reset_wrap
#define isWin isWin_wrap
#define getValue getValue_wrap
#define getAnim getAnim_wrap
#define cleanRect cleanRect_wrap
#define reArrange reArrange_wrap
#define getBombs getBombs_wrap
#define getRearranges getRearranges_wrap
#define addBombs addBombs_wrap
#define addRearranges addRearranges_wrap
#define useBombs useBombs_wrap
#define useRearranges useRearranges_wrap
#define getEmptyPoints getEmptyPoints_wrap

#endif

void Lihui2048ApiRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[17];
    funcPtrs[0] = (void*)isMovable;
    funcPtrs[1] = (void*)move;
    funcPtrs[2] = (void*)getCurrentScore;
    funcPtrs[3] = (void*)getBestScore;
    funcPtrs[4] = (void*)reset;
    funcPtrs[5] = (void*)isWin;
    funcPtrs[6] = (void*)getValue;
    funcPtrs[7] = (void*)getAnim;
    funcPtrs[8] = (void*)cleanRect;
    funcPtrs[9] = (void*)reArrange;
    funcPtrs[10] = (void*)getBombs;
    funcPtrs[11] = (void*)getRearranges;
    funcPtrs[12] = (void*)addBombs;
    funcPtrs[13] = (void*)addRearranges;
    funcPtrs[14] = (void*)useBombs;
    funcPtrs[15] = (void*)useRearranges;
    funcPtrs[16] = (void*)getEmptyPoints;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[17] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("Lihui2048Api", funcPtrs, sizeof(funcPtrs), flags, Lihui2048ApiInit, Lihui2048ApiTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int Lihui2048ApiStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&Lihui2048ApiRegisterExt;
    return 0;
}

int g_Lihui2048ApiVal = Lihui2048ApiStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    Lihui2048ApiRegisterExt();
}
#endif

#endif
