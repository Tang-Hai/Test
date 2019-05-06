//
//  THConfigure.m
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/20.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import "THConfigure.h"

@interface THConfigure ()
@property (strong,nonatomic) NSTimer *timer;
@end

@implementation THConfigure

+ (instancetype)shared {
    static THConfigure *_sharedSingleton = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedSingleton = [[THConfigure alloc] init];
        [_sharedSingleton update];
        _sharedSingleton.timer = [NSTimer scheduledTimerWithTimeInterval:3 target:_sharedSingleton selector:@selector(update) userInfo:nil repeats:YES];
    });
    return _sharedSingleton;
}

-(void)update {
    
    NSString *nameBegnPath = [NSString stringWithFormat:@"%@/%@",NSHomeDirectory(),@"Documents/configure.txt"];
    
    NSString *configureContent = [[[[NSString stringWithContentsOfFile:nameBegnPath encoding:NSUTF8StringEncoding error:nil] stringByReplacingOccurrencesOfString:@"\n" withString:@""] stringByReplacingOccurrencesOfString:@"\r" withString:@""] stringByReplacingOccurrencesOfString:@" " withString:@""];
    
    NSArray *configures = [configureContent componentsSeparatedByString:@","];
    THConfigure *configure = self;
    [configures enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if([obj hasPrefix:@"前缀"]) {
            configure.prefix = [obj stringByReplacingOccurrencesOfString:@"前缀=" withString:@""];
        } else if([obj hasPrefix:@"虚拟机名字"]) {
            configure.vmName = [obj stringByReplacingOccurrencesOfString:@"虚拟机名字=" withString:@""];
        } else if([obj hasPrefix:@"快照名字"]) {
            configure.vmSnapshotName = [obj stringByReplacingOccurrencesOfString:@"快照名字=" withString:@""];
        } else if([obj hasPrefix:@"虚拟机最大创建数量"]) {
            configure.vmMaxNumber = [[obj stringByReplacingOccurrencesOfString:@"虚拟机最大创建数量=" withString:@""] intValue];
        } else if([obj hasPrefix:@"虚拟机最大运行数量"]) {
            configure.vmMaxRunNumber = [[obj stringByReplacingOccurrencesOfString:@"虚拟机最大运行数量=" withString:@""] intValue];
           // NSLog(@"最大obj=%@,vmMaxRunNumber=%d",obj,configure.vmMaxRunNumber);
            
            
        } else if([obj hasPrefix:@"二次启动间隔时间"]) {
            configure.vmIntervalTime = [[[obj stringByReplacingOccurrencesOfString:@"二次启动间隔时间=" withString:@""] stringByReplacingOccurrencesOfString:@" " withString:@""] intValue];
        } else if([obj hasPrefix:@"重启数量"]) {
            configure.restartTimes = [[obj stringByReplacingOccurrencesOfString:@"重启数量=" withString:@""] intValue];
        } else if([obj hasPrefix:@"推信"]) {
            configure.tuiXinName = [obj stringByReplacingOccurrencesOfString:@"推信=" withString:@""];
        }
    }];
    
}

@end
