//
//  NSObject+aspect.h
//  MessagesHook
//
//  Created by iobit on 2018/9/19.
//  Copyright © 2018年 Aiwei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (aspect)
- (NSArray *)getAllSELsFromClass;
- (void)logAllMethods;
- (NSArray *)getAllSELs;
- (NSArray *)getAllProperties;
+(void)hookAwakeFromNib;
+(void)HookMouseDown;
+(void)HookboolForKey;
+(void)chat;
+(void)initWithNodesTreeController;
-(void)aspect_hookSelector:(SEL)sel usingBlock:(id)block;
@end
