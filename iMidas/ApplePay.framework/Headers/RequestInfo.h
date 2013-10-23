//
//  RequestInfo.h
//  NetWorkDemoTest
//
//  Created by 杨开鹏 on 13-4-15.
//
//

#import <Foundation/Foundation.h>

//苹果商品的几种类型
enum{
    Consumable=0,//消费类产品(单笔,游戏币)
    Non_Consumable,//非消费类产品
    Auto_Renewable_Subscriptions,//包月＋自动续费
    Free_Subscription,//免费
    Non_Renewing_Subscription,//包月+非自动续费
}AppproductType;


//key类型
enum{
    Base_key=0,
    Secret_key,
}Key_Type;

//换key业务类型
enum{
    nomalChangekey=0,
    resortDoods,//补发货
    resortNonConsumale,//补非消耗性商品
}ChangeKeyType;

@interface RequestInfo : NSObject
{
    NSString *url;//请求的链接地址
    NSString *requestKey;//请求的唯一标示(cmd)
    NSString *openid;//用户帐号id（account），例如openid、uin
    NSString *openKey;//用户session（skey具体值）
    NSString *session_id;//用户账户类型(uin还是openid)
    NSString *session_type;//session类型(skey)
    NSString *pf;//平台来源
    NSString *pfkey;//跳转到应用首页后，URL后会带该参数。由平台直接传给应用，应用原样传给平台
    NSString *ts;//时间戳
    NSString *appid;//数平为每个业务分配
    NSString *productid;//物品id
    int      productType;//物品类型(0 单笔 ,游戏币 2 包月＋自动续费 3 包月＋非自动续费)
    NSString *payitem;//(1.如果是 单笔 直接由业务自己订 2.如果是包月 字符串 是 开月的天数 3如果是游戏币,则是充值个数)
    NSData   *receipt;//票据
    NSString *billno;//内部订单号
    NSString *amt;//用户支付金额
    int      keyType;//所属三key类型
    int      changeKeyType;//换key的业务
    NSString* currencyType;//当前币种
    int      quantity;//购买产品的数量
    NSString* from;//预留字段给微信
    NSString* zoneid;//游戏币字段
    BOOL      isChangeKey;//控制换key的次数
    BOOL      isDepositGameCoin;//是否是托管游戏币
    NSString* varItem;//业务的扩展字段
}
-(id)initwithOpenId:(NSString*)openId withOpenKey:(NSString*)openkey whitSessionId:(NSString*)sessionId
    withSessionType:(NSString*)sessionType withPf:(NSString*)pform whithPfkey:(NSString*)pfKey  withProductid:(NSString*)productId withProductType:(int)producttype withPayItem:(NSString*)payItem
       withQuantity:(int)quantitys;
@property(nonatomic,copy) NSString *Url;
@property(nonatomic,copy) NSString *RequestKey;
@property(nonatomic,copy) NSString *Openid;
@property(nonatomic,copy) NSString *OpenKey;
@property(nonatomic,copy) NSString *Session_id;
@property(nonatomic,copy) NSString *Session_type;
@property(nonatomic,copy) NSString *Pf;
@property(nonatomic,copy) NSString *Pfkey;
@property(nonatomic,copy) NSString *Ts;
@property(nonatomic,copy) NSString *Appid;
@property(nonatomic,copy) NSString *Productid;
@property(nonatomic,assign) int    ProductType;
@property(nonatomic,copy) NSString *Payitem;
@property(nonatomic,retain)NSData  *Receipt;
@property(nonatomic,copy) NSString *Billno;
@property(nonatomic,copy) NSString    *Amt;
@property(nonatomic,assign) int    KeyType;
@property(nonatomic,assign) int   ChangeKeyType;
@property(nonatomic,copy) NSString *CurrencyType;
@property(nonatomic,assign)int     Quantity;
@property(nonatomic,copy)NSString  *From;
@property(nonatomic,copy)NSString  *Zoneid;
@property(nonatomic,assign)BOOL    IsChangeKey;
@property(nonatomic,assign)BOOL    IsDepositGameCoin;
@property(nonatomic,copy)NSString  *VarItem;
@end
