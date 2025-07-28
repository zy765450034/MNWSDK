//
//  ViewController.m
//  YandexTest
//
//  Created by admin on 2025/6/17.
//

#import "ViewController.h"
//#import "YandexTest-Swift.h"
//#import "AppDelegate.h"
//#import <AppsFlyerLib/AppsFlyerLib.h>
//#import <AdSupport/AdSupport.h>
//#import <AppTrackingTransparency/AppTrackingTransparency.h>
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
//    [[YandexAuthManager shared] addObserver];
    // Do any additional setup after loading the view.
}
- (IBAction)login:(id)sender {
    // 自定义事件上报
//    NSDictionary *eventValues = @{
//        @"af_content_id": @"12345",
//        @"af_content_type": @"shoes"
//    };
//    [[AppsFlyerLib shared] logEvent:AFEventAdView
//           withValues: @{AFEventParamSuccess  : @200,
//                         AFEventParamDestinationB : @"USD",
//                         AFEventParamLong : @2,
//                         AFEventParamEventStart: @"092",
//                         AFEventParamReviewText: @"9277"}];
//    [[AppsFlyerLib shared] logEventWithEventName:@"purchase" eventValues:eventValues completionHandler:^(NSDictionary<NSString *,id> * _Nullable dictionary, NSError * _Nullable error) {
//            NSLog(@"%@,%@",dictionary,error);
//    }];
   
//    [self requestTrackingAuthorizationIfNeeded];
//    [[AppsFlyerLib shared] validateAndLogInAppPurchase:@"product_id"
//                                               price:@"9.99"
//                                            currency:@"USD"
//                                        transactionId:@"trans123"
//                                 additionalParameters:@{@"test_param":@"value"}
//                                            success:^(NSDictionary *response) {
//                                                NSLog(@"验证成功: %@", response);
//                                            } failure:^(NSError *error, id reponse) {
//                                                NSLog(@"验证失败: %@", error);
//                                            }];
//    [AppDelegate AFTTrackEvent:@"af_revenue"
//                   withValues:@"testAppsFlyerName",@"testAppsFlyerV",nil];
//    [AppDelegate AFTTrackEvent:@"af_achievement_id"
//                   withValues:@"testAppsFlyerName",@"testAppsFlyerV",nil];
//    [[YandexAuthManager shared] loginWith:self];
 
}

//- (void)requestTrackingAuthorizationIfNeeded {
//    NSString *idfa = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
//    NSLog(@"当前 IDFA: %@", idfa);
//    if (@available(iOS 14, *)) {
//        [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
//            switch (status) {
//                case ATTrackingManagerAuthorizationStatusAuthorized:
//                    NSLog(@"✅ 用户已授权广告追踪");
//                    break;
//                case ATTrackingManagerAuthorizationStatusDenied:
//                    NSLog(@"❌ 用户拒绝广告追踪");
//                    break;
//                case ATTrackingManagerAuthorizationStatusRestricted:
//                    NSLog(@"⚠️ 广告追踪受限");
//                    break;
//                case ATTrackingManagerAuthorizationStatusNotDetermined:
//                    NSLog(@"⏳ 用户尚未做出选择");
//                    break;
//            }
//
////             可选：打印 IDFA
//            NSString *idfa = [[[ASIdentifierManager sharedManager] advertisingIdentifier] UUIDString];
//            NSLog(@"当前 IDFA: %@", idfa);
//        }];
//    } else {
//        NSLog(@"系统版本 < iOS 14，无需请求 ATT 权限");
//    }
//}
@end
