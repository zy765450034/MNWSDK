//
//  IAPManager.h
//  MiniWorld
//
//  Created by admin on 2019/7/3.
//  Copyright © 2019 Miniwan Tech. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MIAPService.h"
#import <MNWSDK/MNWSDK.h>
@interface MIAPManager : NSObject

@property (nonatomic, strong) MIAPService * _Nullable IAPService;

+ (instancetype _Nullable )instance;

- (void)createOrder:(NSString*_Nullable)cpOrderId
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

- (void)showTextHUD:(NSString *_Nullable)message;
@end

