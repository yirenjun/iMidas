//
//  IAppIAPPayDelegate.h
//  NetWorkDemoTest
//
//  Created by 杨开鹏 on 13-4-23.
//
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@protocol IAppIAPPayDelegate <NSObject>

//请求产品信息(数组里面存放的是产品id,可以请求多个)
-(void)receiveProducts:(NSArray*)products;

//请求产品信息失败
-(void)receiveProductsFail:(NSError *)error;

//请求产品信息完成
-(void)receiveProductFinish;

//交易完成
-(void)completeTransaction:(SKPaymentTransaction*)Transaction;

//交易失败
-(void)failedTransaction:(SKPaymentTransaction*)Transaction;

//重复购买非消耗性商品
-(void)restoreTransaction:(SKPaymentTransaction*)Transaction;

//重复购买读取失败
-(void)restoreTransactionFail:(NSError *)error;

@end
