/*
 * Internal header for the Lihui2048Api extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef LIHUI2048API_INTERNAL_H
#define LIHUI2048API_INTERNAL_H

#include "s3eTypes.h"
#include "Lihui2048Api.h"
#include "Lihui2048Api_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult Lihui2048ApiInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult Lihui2048ApiInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void Lihui2048ApiTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void Lihui2048ApiTerminate_platform();
bool isMovable_platform();

void move_platform(int type);

int getCurrentScore_platform();

int getBestScore_platform();

void reset_platform();

bool isWin_platform();

int getValue_platform(int x, int y);


#endif /* !LIHUI2048API_INTERNAL_H */