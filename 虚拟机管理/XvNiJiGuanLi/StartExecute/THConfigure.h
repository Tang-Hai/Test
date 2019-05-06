//
//  THConfigure.h
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/20.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface THConfigure : NSObject

+ (instancetype)shared;

@property (copy,nonatomic) NSString *vmName;
@property (copy,nonatomic) NSString *prefix;
@property (copy,nonatomic) NSString *vmSnapshotName;
@property (copy,nonatomic) NSString *tuiXinName;
@property (assign,nonatomic) int vmMaxNumber;
@property (assign,nonatomic) int vmMaxRunNumber;
@property (assign,nonatomic) int vmIntervalTime;
@property (assign,nonatomic) int restartTimes;
@end

NS_ASSUME_NONNULL_END
