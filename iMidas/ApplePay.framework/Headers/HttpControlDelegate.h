//
//  HttpControlDelegate.h
//  NetWorkDemoTest
//
//  Created by 杨开鹏 on 13-4-15.
//
//

#import <Foundation/Foundation.h>
@class BaseHttpResovle;

@protocol HttpControlDelegate <NSObject>

@optional

//完成状态
-(void)onFinish:(BaseHttpResovle*)resovle;

//网络请求前的初始化
-(void)onReady:(BaseHttpResovle*)resovle;
//解析完包头
-(void)onStart:(BaseHttpResovle*)resovle;
//暂停状态
-(void)onPause:(BaseHttpResovle*)resovle;
//错误状态
-(void)onError:(BaseHttpResovle*)resovle;

@end
