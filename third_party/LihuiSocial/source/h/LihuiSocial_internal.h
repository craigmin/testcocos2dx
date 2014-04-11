/*
 * Internal header for the LihuiSocial extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef LIHUISOCIAL_INTERNAL_H
#define LIHUISOCIAL_INTERNAL_H

#include "s3eTypes.h"
#include "LihuiSocial.h"
#include "LihuiSocial_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult LihuiSocialInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult LihuiSocialInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void LihuiSocialTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void LihuiSocialTerminate_platform();
void connectToWX_platform();

void sendMessageOnWX_platform();

int isWXLoggedIn_platform();


#endif /* !LIHUISOCIAL_INTERNAL_H */