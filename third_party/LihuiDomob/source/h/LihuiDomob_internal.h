/*
 * Internal header for the LihuiDomob extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef LIHUIDOMOB_INTERNAL_H
#define LIHUIDOMOB_INTERNAL_H

#include "s3eTypes.h"
#include "LihuiDomob.h"
#include "LihuiDomob_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult LihuiDomobInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult LihuiDomobInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void LihuiDomobTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void LihuiDomobTerminate_platform();
void initDoAd_platform();

void showDoBanner_platform();

void showDoInter_platform();

void showDoSplash_platform();

void checkPoints_platform();

void usePoints_platform(int point);

void getPoints_platform();


#endif /* !LIHUIDOMOB_INTERNAL_H */