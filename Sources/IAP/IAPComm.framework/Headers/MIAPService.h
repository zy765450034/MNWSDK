//
//  MIAPService.h
//  MNWSDK
//
//  Created by admin on 2025/5/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MIAPService : NSObject

//接口说明 https://apifox.com/apidoc/shared/79e521ce-01e7-4c58-8ab2-e740a3d9f4ae/269374441e0

- (void)createOrder:(NSString*)cpOrderId
          payMethod:(NSString*)payMethod
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
            success:(void (^ _Nullable)(id _Nullable responseObject))success
            failure:(void (^ _Nullable)(NSError *error))failure;

//接口说明 https://apifox.com/apidoc/shared/79e521ce-01e7-4c58-8ab2-e740a3d9f4ae/269374439e0
//kMNWOverseaOrderConfirmUrl
-(void)confirmOrder:(NSString*)tenementId
          payMethod:(NSString*)payMethod
          productId:(NSString*)productId
        productType:(NSString*)productType
            receipt:(NSString*)receipt
      transactionId:(NSString*)transactionId
       mergeOrderId:(NSString*)mergeOrderId
                env:(NSString*)env
            success:(void (^ _Nullable)(id _Nullable responseObject))success
            failure:(void (^ _Nullable)(NSError *error))failure;
@end

NS_ASSUME_NONNULL_END
