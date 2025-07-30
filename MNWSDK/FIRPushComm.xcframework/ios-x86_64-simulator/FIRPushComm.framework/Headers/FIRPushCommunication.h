//
//  FIRPushCommunication.h
//  FIRPushComm
//
//  Created by admin on 2025/6/10.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FIRPushCommunication : NSObject
+ (void)AppDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (void)SetAPNSToken:(NSData *)APNSToken;
+ (NSString*)GetFCMToken;
+ (void)AppDidReceiveMessage:(NSDictionary *)message;
@end

NS_ASSUME_NONNULL_END
