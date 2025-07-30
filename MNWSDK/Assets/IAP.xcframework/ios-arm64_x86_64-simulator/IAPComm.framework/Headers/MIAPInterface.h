//
//  MIAPInterface.h
//  IAPComm
//
//  Created by admin on 2025/7/3.
//

#import <Foundation/Foundation.h>
#import <MNWSDK/MNWSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface MIAPInterface : NSObject
+ (void)observer;
+ (void)createOrder:(NSString*_Nullable)cpOrderId
          payMethod:(NSString*_Nullable)payMethod
             amount:(float)amount
           currency:(NSString*_Nullable)currency
        productCode:(NSString*_Nullable)productCode
        productName:(NSString*_Nullable)productName
       productCount:(int)productCount
             payExp:(NSString*_Nullable)payExp
             attach:(NSString*_Nullable)attach
          orderDesc:(NSString*_Nullable)orderDesc
          extension:(NSString*_Nullable)extension
         accountNum:(NSString*_Nullable)accountNum
           cpUserId:(NSString*_Nullable)cpUserId
           onResult:(onResult _Nullable)onResult;
@end

NS_ASSUME_NONNULL_END
