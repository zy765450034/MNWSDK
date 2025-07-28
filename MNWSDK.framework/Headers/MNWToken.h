//
//  MNWToken.h
//  MNWSDK
//
//  Created by 谭志武 on 2022/5/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MNWToken : NSObject

/// 登陆认证是否成功
@property (nonatomic, assign) BOOL success;

/// 聚合SDK唯一的用户id
@property (nonatomic, strong) NSString *userId;

/// 聚合登录的Token
@property (nonatomic, strong) NSString *unifiedToken;

/// 后端返回的所有数据（例如后台返回的数据）
@property (nonatomic, strong) NSDictionary *extension;

/// 登录透传参数（如果有账号信息等，也都返回在此json中），后端原路返回
@property (nonatomic, strong) NSString *busiExt;

/// 第三方返回的用户信息
@property (nonatomic, strong) NSDictionary *userInfo;

/// 一键登录等返回的手机号
@property (nonatomic, strong) NSString *phone;

/// 返回的用户名，例如迷你号等
@property (nonatomic, strong) NSString *userName;

@property (nonatomic, assign) NSInteger age;
//实名状态 -1：渠道未提供实名认证 1：未实名 2：成年人 3：未成年人
@property (nonatomic, assign) NSInteger identityStatus;
//1:关闭实名认证 2：开启实名认证 3:强制开启实名认证不认证无法进入游戏
@property (nonatomic, assign) NSInteger realAuthenticationType;

- (instancetype)initWithDictionary:(NSDictionary *)dic;
- (NSDictionary *)toDictionary;
@end

NS_ASSUME_NONNULL_END
