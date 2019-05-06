//
//  UnifiedChatWindowController+Hook.m
//  MessagesHook
//
//  Created by Aiwei on 2018/7/30.
//  Copyright © 2018年 Aiwei. All rights reserved.
//

#import "UnifiedChatWindowControllerHandler.h"
#import "UnifiedChatWindowController.h"

@interface UnifiedChatWindowControllerHandler()

@property(nonatomic,readwrite)NSWindowController * windowController;


@end;


@implementation UnifiedChatWindowControllerHandler

+(UnifiedChatWindowControllerHandler *)handler
{
    static UnifiedChatWindowControllerHandler *handler;
    static dispatch_once_t onceT;
    dispatch_once(&onceT, ^{
        handler = [[super allocWithZone:NULL]init];
        
    });
    return handler;
}
+(instancetype)allocWithZone:(struct _NSZone *)zone
{
    return [self handler];
}
+(UnifiedChatWindowControllerHandler *)handlerWithWindowController:(NSWindowController *)windowController
{
    UnifiedChatWindowControllerHandler *handler = [self handler];
    handler.windowController = windowController;
    return handler;
}

-(void)handleViewDidLoad
{
    
    
}

@end
