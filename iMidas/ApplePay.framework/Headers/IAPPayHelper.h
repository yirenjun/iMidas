//
//  IAPPayHelper.h
//  NetWorkDemoTest
//
//  Created by 杨开鹏 on 13-4-19.
//
//

#import <Foundation/Foundation.h>
#import "HttpControlDelegate.h"
#import "IAppIAPPayDelegate.h"
#import "IAPPayDelegate.h"
#import "ILogDelegate.h"

@class RequestInfo;

@interface IAPPayHelper : NSObject<HttpControlDelegate,IAppIAPPayDelegate,ILogDelegate>{
    
    id<IAPPayDelegate>  delegate;
    RequestInfo *requestInfo;//支付的请求信息
    NSString *changeKeyUrl;//换key的url地址
    NSString *ordanddisUrl;//下单发货地址
    NSString *checkUrl;//验证补发地址
    NSString *requestMp;//拉取营销信息地址
    
}
@property(nonatomic,assign) id<IAPPayDelegate> Delegate;
@property(nonatomic,retain) RequestInfo *RequestInfo;
@property(nonatomic,copy)   NSString    *ChangeKeyUrl;
@property(nonatomic,copy)   NSString    *OrdanddisUrl;
@property(nonatomic,copy)   NSString    *CheckUrl;
@property(nonatomic,copy)   NSString    *RequestMp;

//判断本地是否支持支付
-(Boolean)judgeIsCanPay;

//设置offerID
//在调用pay接口之前调用
-(void)setOfferId:(NSString*)offerId;

//支付
//具体参数请看RequestInfo的构造方法
-(void)pay:(RequestInfo*)info;

//注册监听(必须注册)
-(void)registerHandle;

//重新请求去发货（针对支付成功但发货没成功）
-(void)restoreFailueDistributeGoods:(NSString*)openKey withOpenid:(NSString*)openid;

//针对苹果的重新支付接口(非消耗性商品的接口)
-(void)restoreCompletedTransactions:(RequestInfo*)info;

//拉取营销接口
-(void)launchMpInfo:(RequestInfo*)info;

//注销监听
-(void)unregisterHandle;


@end
