//
//  PaymentInfo.h
//  MiniWorld
//
//  Created by admin on 2019/7/4.
//  Copyright © 2019 Miniwan Tech. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TransactionState) {
    TransactionStateStart = 0,         //订单开始交易
    TransactionStatePurchasing,        //订单支付中 
    TransactionStatePurchased,         //订单支付完成
    TransactionStateVerifyFinish,      //订单验证完成，根据内购回调凭证给服务器去苹果服务认证
    TransactionStateFinish,            //订单交易完成(在SKPaymentQueue中移除)
    TransactionStateFailed             //订单交易失败(在SKPaymentQueue中移除)
};

@interface MPayOrder : NSObject

@property (nonatomic, strong) NSDictionary *orderDetail;

@property (nonatomic, assign) BOOL isFromNewMiniPay;

@property (nonatomic, assign) int verifyNum; //内购回调凭证给服务器校验次数

@property (nonatomic, strong) NSString *transactionIdentifier;

- (instancetype)initWithProductId:(NSString *)productId orderId:(NSString *)orderId cpOrderId:(NSString *)cpOrderId;


- (instancetype)initWithDictionary:(NSDictionary *)dic;
- (void)validateReceiptWithSandbox;
/**
 *  cp订单号
 */
- (NSString *)getCpOrderId;

/**
 *  订单号
 */
- (NSString *)getOrderId;

/**
 *  产品Id
 */
- (NSString *)getProductId;


/**
 * 创建订单时间戳*1000
 */
- (long long)getTimeStamp;

/**
 * 订单交易状态
 */
- (long long)getTransactionState;

/**
 *  env
 */
- (NSString *)getEnv;
/**
 *  env
 */
- (void)setEnv:(NSString *)env;
/**
 *  receipt
 */

- (NSString *)getReceipt;

/**
 *  receipt
 */
- (void)setReceipt:(NSString *)receipt;


- (void)refreshReceipt;



/**
 *  修改订单交易状态
 */
- (void)changeTransactionState:(TransactionState)transactionState;

/**
 *  订单数据转json字符
 */
- (NSString *)payOrderToString;

/**
 *  订单数据转字典
 */
- (NSDictionary *)payOrderToDictionary;

@end

