#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MIAPInterface.h"
#import "MIAPManager.h"
#import "MIAPService.h"
#import "MPayOrder.h"
#import "MPayOrderManager.h"

FOUNDATION_EXPORT double IAPCommVersionNumber;
FOUNDATION_EXPORT const unsigned char IAPCommVersionString[];

