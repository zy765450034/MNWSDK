//
//  JVerificationCommunication.h
//  JVerificationComm
//
//  Created by 谭志武 on 2022/11/21.
//

#import <Foundation/Foundation.h>
#import <MNWSDK/MNWSDK.h>
#import "JVerCommUIConfig.h"
NS_ASSUME_NONNULL_BEGIN

@interface JVerificationComm : NSObject

+ (void)registerAuthConfig:(NSDictionary *)config;

+ (void)registerCustomUIConfig:(NSDictionary *)config;

+ (void)login:(MNWSDKGetUserStateChangedHandler)handler;

+ (BOOL)checkVerifyEnable:(void(^)(NSString *code, NSString *msg))resultBlock;

+ (void)dismissLoginController;

@end

NS_ASSUME_NONNULL_END
