//
//  Untitled.swift
//  Pods
//
//  Created by admin on 2025/4/22.
//
#import <UIKit/UIKit.h>
#import <MNWSDK/MNWSDK.h>
@interface VKIDComm : NSObject
+(void)initWihtAppId:(NSString*)appId;
+ (void)login:(MNWSDKGetUserStateChangedHandler)handler;
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;
@end
