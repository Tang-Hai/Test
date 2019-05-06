//
//  SOTokenFieldControllerHandler.h
//  MessagesHook
//
//  Created by Aiwei on 2018/8/6.
//  Copyright © 2018年 Aiwei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject(SOTokenFieldController_Hook)

+(void)hookTokenFieldControllerMethod;

@end

@interface SOTokenFieldControllerHandler : NSObject

@property(nonatomic,readonly)NSViewController *controller;
+(SOTokenFieldControllerHandler *)handler;

+(SOTokenFieldControllerHandler *)handlerWithController:(NSViewController *)controller;
-(void)handleViewDidLoad;
@end
