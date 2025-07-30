//
//  YandexComm.h
//  YandexComm
//
//  Created by admin on 2025/6/17.
//

#import <Foundation/Foundation.h>
#import <MNWSDK/MNWSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface YandexComm : NSObject
+(void)initWihtClientId:(NSString*)clientId;
+(void)login:(MNWSDKGetUserStateChangedHandler)handler;
+(void)openURL:(NSURL *)url;
+(void)userActivity:(NSUserActivity *)userActivity;
+(void)loginHandler:(NSString*)token jwt:(NSString*)jwt error:(NSError *) error;
@end

NS_ASSUME_NONNULL_END
