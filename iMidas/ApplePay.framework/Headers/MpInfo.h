//
//  MpInfo.h
//  NetWorkDemoTest
//
//  Created by 杨开鹏 on 13-6-6.
//
//

#import <Foundation/Foundation.h>

@interface MpInfo : NSObject{
    
    NSString *rate;
    NSMutableArray *mplist;
    NSMutableArray *mpValueList;
    NSMutableArray *mpPresentList;
    NSString *first_present_count;
    NSString *beginTime;
    NSString *endTime;

}

@property(nonatomic,copy) NSString* Rate;
@property(nonatomic,copy) NSString* Frist_present_count;
@property(nonatomic,copy) NSString* BeginTime;
@property(nonatomic,copy) NSString* EndTime;
@property(nonatomic,retain) NSMutableArray *Mplist;
@property(nonatomic,retain) NSMutableArray *MpValueList;
@property(nonatomic,retain) NSMutableArray *MpPresentList;

@end
