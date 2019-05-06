//
//  THStartExecuteWindowController.h
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/7.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import <Cocoa/Cocoa.h>
@class THStartExecute,THVMItem;
NS_ASSUME_NONNULL_BEGIN

@interface THStartExecuteWindowController : NSWindowController
-(void)update;
-(void)updateMenu;
@property (strong,nonatomic) THVMItem *vmItem;
- (instancetype)initWithWindowNibName:(NSNibName)windowNibName tartExecute:(THStartExecute *)tartExecute;
@end

NS_ASSUME_NONNULL_END
