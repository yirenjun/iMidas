//
//  ILogDelegate.h
//  ApplePay
//
//  Created by 杨开鹏 on 13-6-27.
//  Copyright (c) 2013年 Tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ILogDelegate <NSObject>

-(void)logwithMessage:(NSString*)Message;

@end
