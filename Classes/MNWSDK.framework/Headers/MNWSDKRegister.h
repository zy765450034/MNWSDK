//
//  MNWSDKRegister.h
//  MNWSDK
//
//  Created by 谭志武 on 2022/5/27.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MNWSDKRegister : NSObject


/// 设置Google的注册信息
/// @param clientId clientId
/// @param clientSecret clientSecret 填@“”
/// @param redirectUrl 默认填 @“http://localhost"
- (void)setupGoogleLoginByClientID:(NSString *)clientId
                     clientSecret:(NSString * _Nullable)clientSecret
                      redirectUrl:(NSString * _Nullable)redirectUrl;

/// 设置Facebook的注册信息
/// @param appkey appkey
/// @param appSecret appSecret
/// @param displayName @“your app DisplayName”
- (void)setupFacebookLoginWithAppkey:(NSString *)appkey
                      appSecret:(NSString *)appSecret
                    displayName:(NSString *)displayName;


/// 设置极光秒验的注册信息
/// @param appKey appkey
/// @param advertisinggId 广告最终id
/// @param isProduction 是否正式环境
/// @param authBlock 初始化回调
- (void)setupJIGUANGLoginWithAppkey:(NSString *)appKey
                        advertisinggId:(NSString * _Nullable)advertisinggId
                       isProduction:(BOOL)isProduction
                          authBlock:(void(^)(NSDictionary *result))authBlock;

/// 设置极光秒验登录界面的自定义配置信息,不然会按照默认的样式拉起
/// @param logoImage logo图片
/// @param logBtnText 登录按钮文案
/// @param appPrivacys 隐私协议集合
/// @param otherActionBlock 其他方式回调
/**
 appPrivacys 按照此方式填入
 @[
 @"头部文字",//头部文字
 @[@"、",@"应用自定义服务条款1",@"https://www.xxxxx.com/",@"应用自定义服务条款1",],
 @[@"、",@"应用自定义服务条款2",@"https://www.xxxxx.cn/",@"应用自定义服务条款2",],
 @[@"、",@"应用自定义服务条款3",@"https://www.xxxxx.com/", @"应用自定义服务条款3",],
 @[@"、",@"应用自定义服务条款4",@"https://www.xxxxx.com/",@"应用自定义服务条款4",],
 @[@"、",@"应用自定义服务条款5",@"https://www.xxxxx.com/",@"应用自定义服务条款5",],
 @"尾部文字。"
 ];
 */
- (void)setupJIGUANGLoginCustomConfigWithLogoImage:(UIImage * _Nullable)logoImage logBtnText:(NSString * _Nullable)logBtnText  appPrivacys:(NSDictionary * _Nullable)appPrivacys otherActionBlock:(void (^ _Nullable)(void))otherActionBlock resultActionBlock:(void(^)(NSString * msg))resultActionBlock;


/// 设置wechat的注册信息
/// @param appId appid
/// @param appSecret appSecret
/// @param universalLink universalLink
- (void)setupWechatLoginWithAppId:(NSString *)appId
                        appSecret:(NSString * _Nullable)appSecret
                    universalLink:(NSString * _Nullable)universalLink;


/// 设置QQ的注册信息，采用service code的方式，只需要appId
/// @param appId appId
- (void)setupQQLoginWithAppId:(NSString *)appId;
/// VKID 登陆
/// @param appId appId
- (void)setupVKIDLoginWithAppId:(NSString *)appId;
/// Yandex 登陆
/// @param clientId clientId
- (void)setupYandexLoginWithClientId:(NSString *)clientId;

@end

NS_ASSUME_NONNULL_END
