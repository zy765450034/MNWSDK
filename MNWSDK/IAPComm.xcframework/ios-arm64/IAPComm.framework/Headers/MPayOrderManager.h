//
//  ApplePayOrderManager.h
//  MiniWorld
//
//  Created by 谭志武 on 2023/3/22.
//  Copyright © 2023 Miniwan Tech. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "UICKeyChainStore.h"
#import "MPayOrder.h"

NS_ASSUME_NONNULL_BEGIN

@interface MPayOrderManager : NSObject


//保存订单数据
+ (void)saveOrUpdateOrder:(MPayOrder *)payOrder;

//获取订单数据
+ (MPayOrder *)getOrderWithOrderid:(NSString *)orderId productId:(NSString *)productId transactionIdentifier:(NSString *)transactionIdentifier;

//获取已付完款没发货订单数据
+ (NSArray *)getPurchasedOrders;

//删除订单数据
+ (void)delOrderWithOrderid:(NSString *)orderId productId:(NSString *)productId;

@end

NS_ASSUME_NONNULL_END
