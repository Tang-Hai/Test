//
//  THVMItem.m
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/9.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import "THVMItem.h"
#import "DUIInventoryVMNode.h"
#import "DUIVMID.h"
@implementation THVMItem

-(void)setGangOpen:(BOOL)isGangOpen {
    self.isGangOpen = isGangOpen;
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        self.isGangOpen = NO;
    });
}

-(NSString *)resetKey {
    return [NSString stringWithFormat:@"%@-重启次数",self.stringValue];
}

-(NSString *)guJiDateKey {
    return [NSString stringWithFormat:@"%@-THVMItem_guJiDate",self.stringValue];
}

-(NSString *)notOpenKey {
    return [NSString stringWithFormat:@"%@-notOpen",self.stringValue];
}

-(NSString *)chengGongNumKey {
    return [NSString stringWithFormat:@"%@-chengGongNumKey",self.stringValue];
}

-(NSString *)JianCeCGKey {
    return [NSString stringWithFormat:@"%@-JianCeCGKey",self.stringValue];
}

-(void)claer {
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:[self resetKey]];
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:[self guJiDateKey]];
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:[self notOpenKey]];
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:[self chengGongNumKey]];
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:[self JianCeCGKey]];
}

- (void)setIsChengGongNum:(BOOL)isChengGongNum {
    [[NSUserDefaults standardUserDefaults] setBool:isChengGongNum forKey:[self chengGongNumKey]];
    _isChengGongNum = isChengGongNum;
}

-(void)setStringValue:(NSString *)stringValue {
    _stringValue = stringValue;
    _notOpen = [[NSUserDefaults standardUserDefaults] boolForKey:[self notOpenKey]];
    _guJiDate = [[NSUserDefaults standardUserDefaults] objectForKey:[self guJiDateKey]];
    _isChengGongNum = [[NSUserDefaults standardUserDefaults] boolForKey:[self chengGongNumKey]];
    _JianCeCG = [[NSUserDefaults standardUserDefaults] boolForKey:[self JianCeCGKey]];
}

-(void)setJianCeCG:(BOOL)JianCeCG {
    _JianCeCG = JianCeCG;
    [[NSUserDefaults standardUserDefaults] setBool:JianCeCG forKey:[self JianCeCGKey]];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

-(void)setNotOpen:(BOOL)notOpen {
    _notOpen = notOpen;
    [[NSUserDefaults standardUserDefaults] setBool:notOpen forKey:[self notOpenKey]];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

-(void)saveOpenJiLu {
    
    self.notOpen = YES;
    [[NSUserDefaults standardUserDefaults] setBool:YES forKey:[self notOpenKey]];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

-(NSInteger)resetCount {
    return [[NSUserDefaults standardUserDefaults] integerForKey:[self resetKey]];
}

-(void)reset {
    self.notOpen = NO;
    [[NSUserDefaults standardUserDefaults] setBool:self.notOpen forKey:[self notOpenKey]];
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:self.stringValue];
    self.guJiDate = nil;
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:[self guJiDateKey]];
    
    NSInteger cishu = [[NSUserDefaults standardUserDefaults] integerForKey:[self resetKey]];
    [[NSUserDefaults standardUserDefaults] setInteger:cishu + 1 forKey:[self resetKey]];
    
    [[NSUserDefaults standardUserDefaults] synchronize];
}

-(void)saveGuanJi {
    self.guJiDate = [NSDate date];
    [[NSUserDefaults standardUserDefaults] setObject:self.guJiDate forKey:[self guJiDateKey]];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

-(BOOL)canOpen {
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if ([fileManager fileExistsAtPath:self.stringValue]  &&  (self.node == nil || self.powerState != 1) && self.isOpenError == NO && self.notOpen == NO) {
        return YES;
    }
    return NO;
}

@end
