//
//  MNWBindAccoutParam.h
//  MNWSDK
//
//  Created by 谭志武 on 2022/5/20.
//

#import <Foundation/Foundation.h>
#import "MNWSDKTypeDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface MNWBindAccoutParam : NSObject

/// 聚合token
@property (nonatomic, strong, readonly) NSString *unifiedToken;

/// 聚合账号
@property (nonatomic, strong, readonly) NSString *accountNum;

/// 验证码
@property (nonatomic, strong, readonly) NSString *verifyCode;

/// 绑定类型
@property (nonatomic, assign, readonly) MNWSendVerCodeType bindType;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;


/// 绑定手机，邮箱或者解绑手机，邮箱接口
/// @param bindType 类型
/// @param accountNum 通行证账号
/// @param token 聚合token
/// @param verifyCode 验证码
- (instancetype)initWithBindType:(MNWSendVerCodeType)bindType accountNum:(NSString * _Nullable)accountNum token:(NSString * _Nullable) token verifyCode:(NSString *)verifyCode;

@end

NS_ASSUME_NONNULL_END
