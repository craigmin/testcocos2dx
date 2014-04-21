/*
 * Internal header for the LihuiLB extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef LIHUILB_INTERNAL_H
#define LIHUILB_INTERNAL_H

#include "s3eTypes.h"
#include "LihuiLB.h"
#include "LihuiLB_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult LihuiLBInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult LihuiLBInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void LihuiLBTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void LihuiLBTerminate_platform();
void initLB_platform();

void updateScore_platform(int score);

void receiveRank_platform();

int getScore_platform(int rank);

int getUserRank_platform();

int getNextWeekLeftSeconds_platform();

bool notUnlimetedLives_platform();

void setBeijingTime_platform();

bool notShared_platform();

void setShareTime_platform();

const char* getNickname_platform();

void updateNickname_platform(const char* nickname);


#endif /* !LIHUILB_INTERNAL_H */