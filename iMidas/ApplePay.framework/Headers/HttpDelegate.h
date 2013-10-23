//
//  HttpDelegate.h
//  NetWorkDemoTest
//
//  Created by 杨开鹏 on 13-4-15.
//
//

#import <Foundation/Foundation.h>

@class BaseHttp;

@protocol HttpDelegate <NSObject>

@optional

//网络请求前的初始化
-(void)onReady:(BaseHttp*)basehttp;
//解析完包头
-(void)onStart:(BaseHttp*)basehttp;
//暂停状态
-(void)onPause:(BaseHttp*)basehttp;
//错误状态
-(void)onError:(BaseHttp*)basehttp;
//完成状态
-(void)onFinish:(BaseHttp*)basehttp;
@end
