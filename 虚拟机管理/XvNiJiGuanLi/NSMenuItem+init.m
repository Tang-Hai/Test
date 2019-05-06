//
//  NSMenuItem+init.m
//  MessagesHook
//
//  Created by iobit on 2019/4/8.
//  Copyright © 2019 Aiwei. All rights reserved.
//

#import "NSMenuItem+init.h"

@implementation NSMenuItem (init)


+(void)load {
    [self hookWindowControllerMethod];
}

+(void)hookWindowControllerMethod
{
    NSError *error;
    [self jr_swizzleMethod:@selector(initWithTitle:action:keyEquivalent:) withMethod:@selector(hookinitWithTitle:action:keyEquivalent:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
}

- (instancetype)hookinitWithTitle:(NSString *)string action:(nullable SEL)selector keyEquivalent:(NSString *)charCode {
   id ccc = [self hookinitWithTitle:string action:selector keyEquivalent:charCode];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if ([string isEqualToString:@"启动"] || [string isEqualToString:@"虚拟机资源库"] || [string isEqualToString:@"删除"]) {
            HookLog(@"%@", [NSString stringWithFormat:@"NSMenuItem%@-target=%@,action=%@",string,self.target,NSStringFromSelector(selector)]);
        }
    });
    
    return ccc;
}


//-(void)setTarget:(id)target {
//    HookLog(@"%@", [NSString stringWithFormat:@"NSMenuItem%@-target=%@,action=%@",self.title,target,NSStringFromSelector(self.action)]);
//    HookLog(@"set调用了");
//    [self setValue:target forKey:@"target"];
//}
//
//-(id)target {
//    HookLog(@"%@", [NSString stringWithFormat:@"NSMenuItem%@-target=%@,action=%@",self.title,[self valueForKey:@"target"],NSStringFromSelector(self.action)]);
//    HookLog(@"调用了");
//    return [self valueForKey:@"target"];
//}

@end
