//
//  HookUITool.h
//  MessagesHook
//
//  Created by Aiwei on 2018/8/27.
//  Copyright © 2018 Aiwei. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ClassName(obj) NSStringFromClass([obj class])

@interface HookUITool : NSObject
+(void)showAllSubView:(NSView *)view;
@end


