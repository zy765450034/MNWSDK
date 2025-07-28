//
//  AppDelegate.m
//  YandexTest
//
//  Created by admin on 2025/6/17.
//

#import "AppDelegate.h"
#import <YandexTest-Swift.h>
#import <AppsFlyerLib/AppsFlyerLib.h>

@interface AppDelegate ()<AppsFlyerLibDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    NSString* clientId = @"57a8133c69d947388a67164dfdbc46d3";
    [[YandexAuthManager shared] activateWith:clientId];
    
    
    [[AppsFlyerLib shared] setAppsFlyerDevKey:@"UTQQgnyauE8gTkpQcrWJfM"];
    [[AppsFlyerLib shared] setAppleAppID:@"6742124528"];
    [AppsFlyerLib shared].isDebug = true;
    [[AppsFlyerLib shared] waitForATTUserAuthorizationWithTimeoutInterval:60];
    [AppsFlyerLib shared].delegate = self;
    [[AppsFlyerLib shared] start];
    
    return YES;
}


- (void)applicationDidBecomeActive:(UIApplication *)application{
//    [[AppsFlyerLib shared] start];
    [AppDelegate AFTTrackEvent:@"testAppsFlyer"
                   withValues:@"testAppsFlyerName",@"testAppsFlyerV",nil];
}

#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}
- (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler{
    [[YandexAuthManager shared] handleUserActivityWith:userActivity];
    [[AppsFlyerLib shared] continueUserActivity:userActivity restorationHandler:restorationHandler];
    return true;
}
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options{
    [[YandexAuthManager shared] handleOpenURLWith:url];
    [[AppsFlyerLib shared] handleOpenUrl:url options:options];
    return true;
}
#pragma mark - AppsFlyerLibDelegate
- (void)onConversionDataSuccess:(NSDictionary *)conversionInfo
{
    NSLog(@"归因数据: %@", conversionInfo);
}
- (void)onConversionDataFail:(NSError *)error
{
    NSLog(@"归因数据: %@", error);
}

- (void)onAppOpenAttribution:(NSDictionary *)attributionData
{
    NSLog(@"归因数据: %@", attributionData);
}

- (void)onAppOpenAttributionFailure:(NSError *)error
{
    NSLog(@"归因数据: %@", error);
}
+ (void)AFTTrackEvent:(NSString *)eventName withValues:(NSString *)value, ...NS_REQUIRES_NIL_TERMINATION {
    NSMutableArray *keys = [[NSMutableArray alloc] init];
    NSMutableArray *values = [[NSMutableArray alloc] init];
    int num = 0;
    va_list args;
    va_start(args, value);
    BOOL iskey = NO;
    for (NSString *arg = value; arg != nil; arg = va_arg(args,NSString*)) {
        if(num%2==0){
            if(arg.length>0){
                iskey = YES;
                [keys addObject:arg];
            }
        } else {
            if(iskey)
                [values addObject:arg];
            iskey = NO;
        }
        
        num++;
    }
    
    va_end(args);
    if(keys.count == values.count) {
        NSDictionary *dict = [[NSDictionary alloc] initWithObjects:values forKeys:keys];
        [[AppsFlyerLib shared] logEvent:eventName withValues:dict];
    }
}
@end
