//
//  ViewController.m
//  IAPPayDemo
//
//  Created by 杨开鹏 on 13-5-1.
//  Copyright (c) 2013年 tencent. All rights reserved.
//

//单笔
//节奏大师
#define ProductID_IAP0p99 @"com.tencent.game.rhythmmaster.goldx600"//$0.99
//7 天的自动续费
//#define ProductID_IAP0p99 @"test.days"//$0.99
//包月非自动续费free.pruduct
//#define ProductID_IAP0p99   @"Non_ConsumableTest"
//#define ProductID_IAP0p99   @"com.tencent.game.rhythmmaster.songpack001"
//#define ProductID_IAP0p99     @"blue.diamond"
//#define ProductID_IAP0p99 @"com.qq.xl.ios_pid_1"

#import "ViewController.h"


@interface ViewController ()

@end

@implementation ViewController

@synthesize Button=button;
@synthesize RestoreButton=restoreButton;


-(id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil{
    
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    
    if(self){
        
        help=[[IAPPayHelper alloc] init];
        
        help.Delegate=self;

        
    }
    
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

-(void)viewDidAppear:(BOOL)animated{
    
      [help registerHandle];
      [super viewDidAppear:animated];
}

-(void)viewDidDisappear:(BOOL)animated{
    
    [help unregisterHandle];
    [super viewDidDisappear:animated];
}

//生成换key的info
-(RequestInfo *)creatChangeKey{
    
    RequestInfo *info=[[[RequestInfo alloc] init] autorelease];
    
    info.Openid=@"3865529";
    
    info.OpenKey=@"@oaBQb5tvi";
    //如果是qq登录态则
    info.Session_id=@"uin";
    
    //如果是微信登陆态
    //info.Session_id=@"wechatid";
    
    info.Session_type=@"skey";
    
    info.Payitem=@"1";
    
    info.Productid=ProductID_IAP0p99;
    
    info.Pf=@"huyu_m-2001-iap";
    //是否是托管游戏币
    info.IsDepositGameCoin=false;
    
    info.ProductType=1;
    
    info.Quantity=1;
    
    //应用注册信息
    info.Zoneid=@"1";
    
    //应用的扩展字段，透传
    info.VarItem=@"1;";
    
    //  APGlobalInfoManager *globalInfo = [APGlobalInfoManager singleton];
    
    //  NSString *p = [NSString stringWithFormat:@"%@_%@_%@_%@_2a53ba1b619645d78d15d5c10a3b1074",info.Openid,info.OpenKey,globalInfo.OfferID,info.Pf];
    //NSString   *pfKey = [PayTool md5:p];
    
    info.Pfkey=@"DSSSAEDSDSDSD";
    
    return info;
    
}

-(IBAction)restorePay:(id)sender{
    
    RequestInfo *info=[self creatChangeKey];
    
    [help restoreCompletedTransactions:info];
    
}

-(IBAction)pay:(id)sender{
    
    NSLog(@"pay come in");
    
    RequestInfo *info=[self creatChangeKey];
    
//    help.ChangeKeyUrl=@"http://10.136.4.89/v1/r/1450000081/mobile_get_key";
//    
//    help.OrdanddisUrl=@"http://10.136.4.89/v1/r/1450000081/iap_proc";
    
    [help setOfferId:@"1450000132"];
    [help pay:info];
    
    //补发货
    [help restoreFailueDistributeGoods:info.OpenKey withOpenid:info.Openid];
}


-(IBAction)LaunMp:(id)sender{
    
    RequestInfo *info=[self creatChangeKey];
    
    [help setOfferId:@"1450000132"];
    
//help.RequestMp=@"http://api.unipay.qq.com/v1/012/1450000132/mobile_mp_info";

    [help launchMpInfo:info];
}

//下单成功回调
-(void)onOrderFinish:(NSString*)billno withRequestInfo:(RequestInfo*)info{
    
    NSLog(@"下单成功=%@",info.VarItem);
}

//补发货的数目回调
-(void)distributeGoodsWithCount:(int)count{
    
    NSLog(@"distributeGoodsWithCount=%d",count);
}

-(void)log:(NSString *)message{
    
    NSLog(@"回调%@",message);
}

//下单失败回调

-(void)onOrderFailue:(RequestInfo*)info withErrorMessage:(NSString*)errorMessage
      withEorrorCode:(int)code
{
    
    NSLog(@"下单失败 ==%@  code=%d %@",errorMessage,code,errorMessage);
}

//苹果支付成功回调

-(void)onIAPPayFinish:(RequestInfo*)info{
    
    NSLog(@"苹果支付成功");
}

//苹果支付失败回调

-(void)onIAPPayFailue:(RequestInfo*)info  withError:(NSError*)error{
    
    NSLog(@"苹果支付失败 %d %@",error.code,error.description);
}

//发货成功回调

-(void)onDistributeGoodsFinish:(RequestInfo*)info{
    
    if(info.ChangeKeyType==1){
        
       NSLog(@"补发货成功"); 
    }else{
        
        NSLog(@"新发货成功");
    }
    
}

//发货失败回调

-(void)onDistributeGoodsFailue:(RequestInfo*)info withErrorMessage:(NSString*)errorMessage withEorrorCode:(int)code{
    
    NSLog(@"发货失败");
}

//网络错误，参数：具体在进行哪一步的时候发生网络错误
//1.下单 2 苹果支付 3 发货
-(void)onNetWorkEorror:(int)state withRequestInfo:(RequestInfo*)info{
    
    NSLog(@"网络错误 %d",state);
    
}


-(void)onLoginExpiry:(RequestInfo *)info{
    
    NSLog(@"登陆态失效");
}

//读取补发商品信息失败
-(void)getrestoreInfoFailue:(NSError*)error{
    
    NSLog(@"读取补发商品信息失败");
}

//补发货成功回调(针对非消耗性商品)
-(void)onRestorNon_ConsumableFinish:(RequestInfo*)info{
    
    NSLog(@"成功非消耗性商品=%@",info.Productid);
}

//补发货失败回调(针对非消耗性商品)
-(void)onRestorNon_ConsumableFailue:(RequestInfo*)info withErrorMessage:(NSString*)errorMessage withEorrorCode:(int)code{
    
     NSLog(@"消耗性回复==%@",info.Productid);
}

-(void)onLaunMpFinish:(RequestInfo*)info withMpinfo:(MpInfo*)mpinfo{
    
    
    NSLog(@"mpinfo=%@",mpinfo.Frist_present_count);
    
    for(int i=0;i<[mpinfo.MpValueList count];i++){
        
        NSLog(@"DDD=%@",[mpinfo.MpValueList objectAtIndex:i]);
    }
    for(int i=0;i<[mpinfo.MpPresentList count];i++){
        
        NSLog(@"ssss=%@",[mpinfo.MpPresentList objectAtIndex:i]);
    }

}

-(void)onLaunMpFailue:(RequestInfo*)info withErrorMessage:(NSString*)errorMessage withEorrorCode:(int)code{
    
    
    NSLog(@"erormessage=%@",errorMessage);
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)dealloc{

    [help release],help=nil;
    [super dealloc];
}

@end
