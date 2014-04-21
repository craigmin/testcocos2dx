/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_LIHUILB_H
#define S3E_EXT_LIHUILB_H

#include <s3eTypes.h>

enum LihuiLBCallback
{
    LIHUILB_CALLBACK_REICEIVE_SUCCESSFUL,
    LIHUILB_CALLBACK_REICEIVE_FAILED,
    LIHUILB_CALLBACK_UPDATE_SUCCESSFUL,
    LIHUILB_CALLBACK_UPDATE_FAILED,
    LIHUILB_CALLBACK_MAX
};
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the LihuiLB extension is available.
 */
s3eBool LihuiLBAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref LihuiLBCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userdata Value to pass to the @e userdata parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see LihuiLBUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref LihuiLBCallback enum.
 */
s3eResult LihuiLBRegister(LihuiLBCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback for which to register.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the LihuiLBCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see LihuiLBRegister
 */
s3eResult LihuiLBUnRegister(LihuiLBCallback cbid, s3eCallback fn);

void initLB();

void updateScore(int score);

void receiveRank();

int getScore(int rank);

int getUserRank();

int getNextWeekLeftSeconds();

bool notUnlimetedLives();

void setBeijingTime();

bool notShared();

void setShareTime();

const char* getNickname();

const char* getNicknameByRank(int rank);

void updateNickname(const char* nickname);

S3E_END_C_DECL

#endif /* !S3E_EXT_LIHUILB_H */
