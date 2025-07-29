//
//  MNWSDK.h
//  MNWSDK
//
//  Created by 谭志武 on 2022/5/16.
//

#import <Foundation/Foundation.h>
#import "MNWUser.h"
#import "MNWToken.h"
#import "MNWLoginParam.h"
#import "MNWSDKRegister.h"
#import "MNWVerCodeParam.h"
#import "MNWSDKTypeDefine.h"
#import "MNWBindAccoutParam.h"
#import "MNWBindingVerCodeParam.h"


NS_ASSUME_NONNULL_BEGIN

@interface MNWSDK : NSObject
#pragma mark 版本号
+ (NSString*)version;


#pragma mark --- 注册/初始化接口

/// 注册聚合平台分发的appid和appkey
/// @param tenementId 聚合平台的appid
/// @param tenementKey 聚合平台的appkey
/// @param deviceId 唯一机器编码
+ (void)registerMNWSDKWithTenementId:(NSString *)tenementId tenementKey:(NSString *)tenementKey deviceId:(NSString *)deviceId;

/// 注册登录SDK，需要传入配置的各平台的AppId和AppKey,SecretKey 和universalLink等
/// @param platforms ...
+ (void)registerLoginPlatforms:(void(^_Nonnull)(MNWSDKRegister * _Nonnull platformsRegister))platforms;


/// 是否开启调试模式，会打印请求url，请求参数，还有返回数据
/// @param enableDebug 是否能调试（会切换测试环境）
/// @param isDomestic 是否是国内（会切换国内环境）
/// @param apiId 渠道id,可以不传,默认45,苹果渠道
+ (void)setEnableDebug:(BOOL)enableDebug isDomestic:(BOOL)isDomestic apiId:(NSString * _Nullable)apiId;

/// 透传客户端额外的参数，作为请求的补充参数
/// @param extensionParams 额外参数的json 字符串
+ (void)setExtensionParams:(NSString *)extensionParams;

/// 检查是否支持手机号一键登录
+ (BOOL)checkEnableOneKeyLogin:(void(^ _Nullable)(NSString *code, NSString *msg))resultBlock;

/// 处理SDK的回调设置
/// - Parameter url: 回调url
+ (BOOL)handleUrl:(NSURL * _Nullable)url;

/// 处理SDK的ULink
/// - Parameter userActivity: ...
+ (BOOL)handleOpenUniversalLink:(NSUserActivity *)userActivity;

#pragma mark --- 聚合UI
+ (void)initUIWithParam:(NSDictionary*)param;
/// 聚合登录
+ (void)login:(loginHandler _Nonnull)loginHandler;

#pragma mark --- 聚合登录相关接口

/// 聚合登录接口
/// @param loginParam 登录参数对象，查看具体类型和实例化方法
/// @param onResult 请求结果回调
/// @param onLoginResult 如果第三方授权登录，则返回授权的信息
/// @param onAuthResult 聚合平台返回的token信息，具体内容可以查看token.extension
+ (void)loginWithMNWLoginParam:(MNWLoginParam *)loginParam onResult:(onResult _Nullable)onResult onLoginResult:(onLoginResult _Nullable)onLoginResult onAuthResult:(onAuthResult _Nonnull)onAuthResult;


/// 获取验证码
/// @param codeParam 验证码参数
/// @param onResult 是否获取成功回调
+ (void)getVerifyCode:(MNWVerCodeParam *)codeParam onResult:(onResult _Nullable)onResult;

/// 注册聚合平台通行证
/// 注册限制：同一个ip永久限制只能注册十个账号，同一设备号每天只能注册三个账号
/// @param account 通行证账号
/// @param password 通行证密码
/// @param onResult 注册是否成功回调
/// @param onAuthResult 用户信息回调
+ (void)registerAccountWithAccount:(NSString *)account password:(NSString *)password onResult:(onResult _Nullable)onResult onAuthResult:(onAuthResult _Nonnull)onAuthResult;

/// 快速通过手机号注册
/// @param phone 手机号
/// @param phoneAreaCode 区号
/// @param verifyCode 手机验证码
/// @param onResult 注册是否成功回调
/// @param onAuthResult 用户信息回调
+ (void)registerAccountWithPhone:(NSString *)phone phoneAreaCode:(NSString *)phoneAreaCode verifyCode:(NSString *)verifyCode onResult:(onResult _Nullable)onResult onAuthResult:(onAuthResult _Nonnull)onAuthResult;


/// 通行证密码获取验证码接口
/// @param account 通行证账号
/// @param token 聚合token
/// @param resetWay 重置方式 MNWResetWayePhone 手机 MNWResetWayeEmail 邮箱
/// @param onResult 发送是否成功回调
+ (void)sendResetVerifyCodeWithAccount:(NSString * _Nullable)account token:(NSString * _Nullable)token resetWay:(MNWResetWay)resetWay onResult:(onResult _Nullable)onResult;

/// 通信证账号重置密码接口
/// @param account 通行证账号
/// @param token 聚合token
/// @param newUserName 新聚合账户名
/// @param newPassword 新密码
/// @param verifyCode 验证码（手机或邮箱）
/// @param onResult 重置是否成功回调
+ (void)resetAccountWithAccount:(NSString * _Nullable)account token:(NSString * _Nullable)token newUserName:(NSString * _Nullable)newUserName  newPassword:(NSString *)newPassword verifyCode:(NSString *)verifyCode onResult:(onResult _Nullable)onResult;

/// 通行证设置新密码接口
/// @param account 通行证账号
/// @param password 密码
/// @param onResult 是否设置成功回调
+ (void)setPasswordForQuickRegisterWithAccount:(NSString *)account password:(NSString *)password onResult:(onResult _Nullable)onResult;

/// 查询第三方账号绑定列表
/// @param completionHandler 绑定信息回调
/// 返回这样的数据
/// {
///"thirdInfos": [
///  {
///    "thirdChannelId": -1,   ----- 10:Facebook ；12:Google ；15: Apple;  -1 ：email ; -2 : phone
///    "tenementId": 10870003,
///    "accountNum": "317006399371657219",
///    "thirdUserName": "1124634508@qq.com"
///  }]
///}queryThirdUserListWithToken
+ (void)queryThirdBindListWithToken:(NSString *)token completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;
/// 查询第三方账号，邮箱，手机绑定列表
/// @param account 通行证账号
/// @param completionHandler 绑定信息回调
/// 返回这样的数据
/// {
///"thirdInfos": [
///  {
///    "thirdChannelId": -1,   ----- 10:Facebook ；12:Google ；15: Apple;  -1 ：email ; -2 : phone
///    "tenementId": 10870003,
///    "accountNum": "317006399371657219",
///    "thirdUserName": "1124634508@qq.com"
///  }]
///}
+ (void)queryBindAccountInfoWithAccount:(NSString *)account completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;


/// 安全手机找回账号获取验证码
/// @param securePhone 安全手机
/// @param secrePhoneAreaCode 安全手机所属区号
/// @param onResult ...
+ (void)sendFindAccountVCodeWithSecurePhone:(NSString *)securePhone securePhoneAreaCode:(NSString *)secrePhoneAreaCode onResult:(onResult _Nullable)onResult;


/// 安全手机找回账号
/// @param securePhone 安全手机号
/// @param secrePhoneAreaCode 安全手机所属区号
/// @param verifyCode 手机验证码
/// @param completionHandler ...
+ (void)findAccountWithSecurePhone:(NSString *)securePhone securePhoneAreaCode:(NSString *)secrePhoneAreaCode verifyCode:(NSString *)verifyCode completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;


/// 安全邮箱找回账号获取验证码
/// @param secureEmail 安全邮箱
/// @param onResult ...
+ (void)sendFindAccountVCodeWithSecureEmail:(NSString *)secureEmail onResult:(onResult _Nullable)onResult;

/// 安全邮箱找回账号
/// @param secureEmail 安全邮箱
/// @param verifyCode 邮箱验证码
/// @param completionHandler ...
+ (void)findAccountWithSecureEmail:(NSString *)secureEmail verifyCode:(NSString *)verifyCode completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;


/// 根据token查询账号信息
/// @param token 聚合unifiedToken
/// @param completionHandler 回调
+ (void)queryAccountWithToken:(NSString *)token completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler ;

/// 验证验证码
/// @param account 聚合账号
/// @param token 聚合token
/// @param verifyCode 验证码
/// @param checkType 验证方式
/// @param onResult ...
+ (void)checkVCodeWithAccout:(NSString *)account token:(NSString *)token verifyCode:(NSString *)verifyCode checkType:(NSString *)checkType onResult:(onResult _Nullable)onResult;


/// 是否打开账号服登录安全验证功能
/// @param token 聚合token
/// @param isOpen 是否打开
/// @param reason 打开原因
+ (void)switchLoginSafeVerifyWithToken:(NSString *)token isOpen:(BOOL)isOpen reason:(NSString *)reason onResult:(onResult _Nullable)onResult;

/// 退出登录
/// @param onResult ...
+ (void)logout:(onResult _Nullable)onResult;

#pragma mark -- 绑定/解绑相关接口

/// 获取绑定账号验证码
/// @param codeParam bindingParam
/// @param onResult ...
+ (void)getBindAccountVerifyCode:(MNWBindingVerCodeParam *)codeParam onResult:(onResult _Nullable)onResult;

/// 换绑手机/邮箱
/// @param token 聚合token
/// @param bindVCode 绑定验证码
/// @param unbindVCode 解绑验证码
/// @param operateType 换绑方式
/// @param onResult ...
+ (void)changeBindAccoutWithToken:(NSString *)token bindVCode:(NSString *)bindVCode unbindVCode:(NSString *)unbindVCode operateType:(MNWChangeBindType)operateType onResult:(onResult _Nullable)onResult;

/// 绑定账号
/// @param bindParam bindAccountParam
/// @param onResult ...
+ (void)bindAccount:(MNWBindAccoutParam *)bindParam onResult:(onResult _Nullable)onResult;

/// 第三方授权账号绑定
/// @param bindType 绑定类型
/// @param onResult ...
+ (void)thirdBindWithToken:(NSString *)token bindType:(MNWThirdBindType)bindType onResult:(onResult _Nullable)onResult;

/// 第三方授权账号绑定(废弃)
/// @param account 通行证账号
/// @param bindType 绑定类型
/// @param onResult ...
+ (void)thirdBindAccount:(NSString *)account bindType:(MNWThirdBindType)bindType onResult:(onResult _Nullable)onResult;

/// 第三方授权账号解绑
/// @param account 通行证账号
/// @param unBindType 解绑类型
/// @param onResult ...
+ (void)thirdUnBindAccount:(NSString *)account unBindType:(MNWThirdBindType)unBindType onResult:(onResult _Nullable)onResult;


#pragma mark -- 实名信息

/// 绑定实名信息接口
/// @param account 通信证账号
/// @param idCard 身份证号码
/// @param name 真实姓名
/// @param completionHandler 绑定实名信息回调（如果绑定成功的话）
/// {
///     "userId": xxxxxx,
///     "age":18,
///     "birthday": xxxxxxx,
///     "isRealName": 1, (是否实名 ：0否，1是)
///     "realNameAuthStatus":2 (用户实名认证状态： -1：未提供 1：未实名 2：成年人 3：未成年人)
/// }
+ (void)bindRealNameAuthenticationWithAccount:(NSString *)account idCard:(NSString *)idCard name:(NSString *)name completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;


/// 查询实名信息接口
/// @param account 通行证账号
/// @param completionHandler 返回实名信息回调（如果有实名信息的话）
/// {
///     "userId": xxxxxx,
///     "age":18,
///     "birthday": xxxxxxx,
///     "isRealName": 1, (是否实名 ：0否，1是)
///     "realNameAuthStatus":2 (用户实名认证状态： -1：未提供 1：未实名 2：成年人 3：未成年人)
/// }
+ (void)queryBindRealNameAuthenticationWithAccount:(NSString *)account completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;

#pragma mark -- 防沉迷
/// 防沉迷校验
/// @param token 聚合token
/// @param completionHandler ...
- (void)antiAddiction:(NSString *)token completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;
/// 获取剩余游戏时长
/// @param token 聚合token
/// @param completionHandler ...
- (void)getRemainPlayTime:(NSString *)token completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;
#pragma mark -- 海外专属

/// 迷你号或者邮箱发送验证码
/// @param uin 迷你号
/// @param email 邮箱账号
/// @param onResult ...
+ (void)sendResetVerifyCodeWithUin:(NSString *)uin email:(NSString *)email onResult:(onResult _Nullable)onResult;

/// 迷你号发送手机验证码（暂时弃用，后台逻辑未完善）
/// @param uin 迷你号
/// @param phone 手机号
/// @param phoneAreaCode 手机区号
/// @param onResult ...
+ (void)sendResetVerifyCodeWithUin:(NSString *)uin phone:(NSString *)phone phoneAreaCode:(NSString *)phoneAreaCode onResult:(onResult)onResult DEPRECATED_MSG_ATTRIBUTE("this service is not available ,don't used");

/// 迷你号或者邮箱验证验证码接口
/// @param uin 迷你号
/// @param email 邮箱
/// @param verifyCode 验证码
/// @param onResult ...
+ (void)validationAccountWithUin:(NSString *)uin email:(NSString *)email verifyCode:(NSString *)verifyCode onResult:(onResult _Nullable)onResult;

/// 重置迷你号或者邮箱账号密码
/// @param uin 迷你号
/// @param email 邮箱
/// @param newPassword 新密码
/// @param onResult ...
+ (void)resetAccountWithUin:(NSString *)uin email:(NSString *)email newPassword:(NSString *)newPassword onResult:(onResult _Nullable)onResult;

/// 根据迷你号查询密码设置信息
/// @param uin 迷你号
/// @param completionHandler ...
+ (void)queryPwdInfoWithUin:(NSString *)uin completionHandler:(void (^)(MNWCode code, NSString * _Nullable msg, id _Nullable responseObject))completionHandler;


#pragma mark -- Helper

/// 文字密码验证问题对照表
/// @param lang 当前语言 "en"为英文, "zh"为中文，其它不支持
+ (NSArray *)securityQuestions:(NSString *)lang;


/// 退出一键登录原生页面
+ (void)dismissLoginController;

#pragma mark --Reporter

/// 上报聚合登录相关到聚合数据服
/// - Parameters:
///   - productId: 产品id
///   - sessionId: 场景id
///   - channelId: 渠道id
///   - customParams: 自定义参数
///   - standbyParams: 额外参数
+ (void)reportMNWLoginWithProductId:(NSString *)productId sessionId:(NSString *)sessionId channelId:(NSString *)channelId customParams:(NSDictionary *)customParams standbyParams:(NSDictionary *)standbyParams;

+ (void)reportRoleDataWithType:(int)type
                        roleId:(NSString*)roleId
                      roleName:(NSString*)roleName
                     roleLevel:(NSString*)roleLevel
                       roleVIP:(NSString*)roleVIP
                       roleSex:(NSString*)roleSex
                roleExperience:(NSString*)roleExperience
                   rolePayment:(NSString*)rolePayment
                      serverId:(NSString*)serverId
                    serverName:(NSString*)serverName
                      moneyNum:(NSString*)moneyNum
                roleCreateTime:(NSString*)roleCreateTime
               roleLevelUpTime:(NSString*)roleLevelUpTime;

#pragma mark --- 聚合支付接口
/// 内购接口
/// - Parameters:
///   - cpOrderId:    业务订单号                       必需
///   - amount:       支付金额(分)                    必需
///   - currency:     币种:CNY-人民币             必需
///   - productCode:  商品编码                          必需
///   - productName:  商品名称                          可选
///   - productCount: 商品数量                          可选
///   - productName:  商品编码                          可选
///   - payExp:       支付失效时间                   可选
///   - attach:       回调时会返回给业务         可选
///   - orderDesc:    订单描述                           可选
///   - extension:    预留扩展字段                    可选
///   - accountNum:   聚合号                               可选
///   - cpUserId:     业务用户ID                         可选
+ (void)pay:(NSString*)cpOrderId
     amount:(float)amount
   currency:(NSString*)currency
productCode:(NSString*)productCode
productName:(NSString*)productName
productCount:(int)productCount
     payExp:(NSString*)payExp
     attach:(NSString*)attach
  orderDesc:(NSString*)orderDesc
  extension:(NSString*)extension
 accountNum:(NSString*)accountNum
   cpUserId:(NSString*)cpUserId
   onResult:(onResult _Nullable)onResult;

#pragma mark --- 聚合注销接口

/// 注销接口
/// - Parameters:
///   - info: 注销信息 包含email,protocol
///   - onResult: 注销结果回调
+ (void)cancelAccountInfo:(NSDictionary *)info OnResult:(onResult _Nullable)onResult;


#pragma mark --- 聚合广告接口
/// 广告初始化接口
/// - Parameters:
///   - appId:             广告平台
///   - placementId:       广告位Id

+ (void)initAdWithAppId:(NSString *)appId placementId:(NSString *)placementId;
/// 展示激励视频接口
+ (void)showRewardedVideo:(onResult _Nullable)onResult;
#pragma mark --- 聚合合规协议
/// 打开内部浏览器
/// - Parameters:
/// - url:             连接
/// - HideWithdrawBtn：      释放隐藏底部撤回按钮
+ (void)openBrowserWithURL:(NSString *)url hideWithdrawBtn:(BOOL)hide;
/// 打开内部浏览器 如果有撤回用这个回调
+ (void)withdrawEvent:(onResult _Nullable)onResult;

#pragma mark --- 聚合推送
+ (void)didFinishLaunchingWithOptions:(NSDictionary *)launchOptions mergePushId:(NSNumber*)mergePushId;

+ (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
/// 打开内部浏览器 如果有撤回用这个回调
+ (void)receiveNotification:(onResult _Nullable)onResult;
+ (void)notificationClick:(onResult _Nullable)onResult;
+ (void)pushNotification:(NSString*)pushId title:(NSString*)title body:(NSString*)body data:(NSDate*)date;
#pragma mark -- AppDelegate
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> * _Nullable)options;
+ (BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void(^)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;

#pragma mark --- AppsFlyer
//具体eventName和key 看 AppsFlyerLib.h
+ (void)AppsFlyerEvent:(NSString *)eventName withValues:(NSDictionary * _Nullable)values;

@end

NS_ASSUME_NONNULL_END
