//
//  UnifiedChatWindowController+Hook.h
//  MessagesHook
//
//  Created by Aiwei on 2018/7/30.
//  Copyright © 2018年 Aiwei. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface UnifiedChatWindowControllerHandler : NSObject

@property(nonatomic,readonly)NSWindowController * windowController;

+(UnifiedChatWindowControllerHandler *)handlerWithWindowController:(NSWindowController *)windowController;

-(void)handleViewDidLoad;

@end
