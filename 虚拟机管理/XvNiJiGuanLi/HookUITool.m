//
//  HookUITool.m
//  MessagesHook
//
//  Created by Aiwei on 2018/8/27.
//  Copyright © 2018 Aiwei. All rights reserved.
//

#import "HookUITool.h"

@implementation HookUITool

+(void)showAllSubView:(NSView *)view
{
    [self showSubView:view withBoundary:@"[+]"];
}
+(void)showSubView:(NSView *)view withBoundary:(NSString *)boundary
{
    HookLog(@"%@:%@",boundary,ClassName(view));
    if(!view.subviews.count) return;
    for (NSView *subView in view.subviews) {
        [self showSubView:subView withBoundary:[NSString stringWithFormat:@"*%@",boundary]];
    }
}
@end
