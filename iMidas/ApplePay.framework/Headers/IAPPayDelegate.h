//
//  IAPPayDelegate.h
//  NetWorkDemoTest
//
//  Created by 杨开鹏 on 13-4-19.
//
//

#import <Foundation/Foundation.h>
#import "RequestInfo.h"
#import "MpInfo.h"

@protocol IAPPayDelegate <NSObject>

@optional


//参数不合法
-(void)parameterWrong:(NSString*)parameterLog;

//log的回调
-(void)log:(NSString*)message;

//登陆态失效
-(void)onLoginExpiry:(RequestInfo*)info;

//下单成功回调
-(void)onOrderFinish:(NSString*)billno withRequestInfo:(RequestInfo*)info;

//下单失败回调(业务错误)

-(void)onOrderFailue:(RequestInfo*)info withErrorMessage:(NSString*)errorMessage withEorrorCode:(int)code;

//苹果支付成功回调

-(void)onIAPPayFinish:(RequestInfo*)info;

//拉取货物产品信息失败
//针对拉取产品的时候产品数量为0的时候
-(void)onGetProductInfoFailue:(RequestInfo*)info;

//苹果支付失败回调

-(void)onIAPPayFailue:(RequestInfo*)info  withError:(NSError*)error;

//发货成功回调

-(void)onDistributeGoodsFinish:(RequestInfo*)info;

//发货失败回调(业务错误)
//如果code=10001 则需要补发,其他错误则不需要
-(void)onDistributeGoodsFailue:(RequestInfo*)info withErrorMessage:(NSString*)errorMessage withEorrorCode:(int)code;

//补发货的数目回调
-(void)distributeGoodsWithCount:(int)count;

/*******************补发回调用********************/
//读取补发商品信息失败
-(void)getrestoreInfoFailue:(NSError*)error;

//补发货成功回调(针对非消耗性商品)
-(void)onRestorNon_ConsumableFinish:(RequestInfo*)info;

//补发货失败回调(针对非消耗性商品)
-(void)onRestorNon_ConsumableFailue:(RequestInfo*)info withErrorMessage:(NSString*)errorMessage withEorrorCode:(int)code;

/*******************补发回调用********************/





/******************拉取营销信息回调*****************/

-(void)onLaunMpFinish:(RequestInfo*)info withMpinfo:(MpInfo*)mpinfo;

-(void)onLaunMpFailue:(RequestInfo*)info withErrorMessage:(NSString*)errorMessage withEorrorCode:(int)code;

/******************拉取营销信息回调*****************/





//网络错误，参数：具体在进行哪一步的时候发生网络错误
//1.下单 2 苹果支付 3 发货 4.恢复非消耗性物品失败 5,拉去营销信息网络错误
-(void)onNetWorkEorror:(int)state withRequestInfo:(RequestInfo*)info;

@end
