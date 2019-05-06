//
//  NSObject+NSObject.m
//  MessagesHook
//
//  Created by iobit on 2018/9/21.
//  Copyright © 2018年 Aiwei. All rights reserved.
//

#import "NSView+finder.h"

@implementation NSView (finder)

+(NSView *)windowsFinderTargetWithWindows:(NSArray<NSWindow *>*)windows block:(BOOL(^)(NSView *))block {
    __block NSView *target = nil;
    [windows enumerateObjectsUsingBlock:^(NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSView *tempTarget = [obj.contentView finderTarget:block];
        if (tempTarget != nil) {
            target = tempTarget;
            *stop = YES;
        } else if (obj.sheets.count > 0) {
            NSView *tempTarget = [self windowsFinderTargetWithWindows:obj.sheets block:block];
            if (tempTarget != nil) {
                target = tempTarget;
                *stop = YES;
            }
        }
       // HookLog(@"我来过 windowsFinderTargetWithWindows");
    }];
    return target;
}

-(NSView *)finderTarget:(BOOL(^)(NSView *))block {
    __block NSView *target = nil;
    [self.subviews enumerateObjectsUsingBlock:^(__kindof NSView * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if (block(obj)) {
            target = obj;
            *stop = YES;
        } else if (obj.subviews.count > 0) {
            target = [obj finderTarget:block];
            if (block(target)) {
                *stop = YES;
            }
        }
        //HookLog(@"我来过 finderTarget");
    }];
    return target;
}

@end
