//
//  Alert.m
//  刷码神器
//
//  Created by iobit on 2018/9/30.
//  Copyright © 2018年 iobit. All rights reserved.
//

#import "Alert.h"
#import <AppKit/AppKit.h>

@implementation Alert

+(void)alertMessage:(NSString *)str {
    dispatch_async(dispatch_get_main_queue(), ^{
       [[NSAlert alertWithMessageText:str defaultButton:@"OK" alternateButton:nil otherButton:nil informativeTextWithFormat:@""] runModal];
    });
}

@end
