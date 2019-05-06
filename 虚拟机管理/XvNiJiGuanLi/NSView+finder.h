//
//  NSObject+NSObject.h
//  MessagesHook
//
//  Created by iobit on 2018/9/21.
//  Copyright © 2018年 Aiwei. All rights reserved.
//

#import <AppKit/AppKit.h>

@interface NSView (finder)
+(NSView *)windowsFinderTargetWithWindows:(NSArray<NSWindow *>*)windows block:(BOOL(^)(NSView *))block;
-(NSView *)finderTarget:(BOOL(^)(NSView *))block;
@end
