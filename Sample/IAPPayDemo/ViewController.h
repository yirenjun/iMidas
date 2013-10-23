//
//  ViewController.h
//  IAPPayDemo
//
//  Created by 杨开鹏 on 13-5-1.
//  Copyright (c) 2013年 tencent. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <ApplePay/IAPPayHelper.h>
#import <ApplePay/RequestInfo.h>
#import <ApplePay/IAPPayDelegate.h>

@interface ViewController : UIViewController<IAPPayDelegate>{
    
    IAPPayHelper* help;
    
    UIButton *button;
    
    UIButton *restoreButton;
    
    UIButton *mpButton;
}

@property(nonatomic,retain)IBOutlet UIButton *Button;
@property(nonatomic,retain)IBOutlet UIButton *RestoreButton;
@property(nonatomic,retain)IBOutlet UIButton *MpButton;
@end
