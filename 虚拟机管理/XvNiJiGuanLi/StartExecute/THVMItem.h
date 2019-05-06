//
//  THVMItem.h
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/9.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import <Foundation/Foundation.h>
@class DUIInventoryVMNode,DUIVMActionController,BrushCode;
//NS_ASSUME_NONNULL_BEGIN

@interface THVMItem : NSObject
@property (strong,nonatomic) NSDate *nextInsDate;
@property (assign,nonatomic) BOOL isOpenError;
@property (assign,nonatomic) BOOL isGangOpen;
@property (assign,nonatomic) BOOL isChengGongNum;
@property (assign,nonatomic) BOOL first;
@property (copy,nonatomic) NSString *name;
@property (copy,nonatomic) NSString *stringValue;
@property (assign,nonatomic) int powerState;
@property (assign,nonatomic) BOOL notOpen;
@property (assign,nonatomic) BOOL isJianCeCG;
@property (assign,nonatomic) BOOL JianCeCG;
@property (assign,nonatomic) BOOL isRemove;
@property (strong,nonatomic) NSDate *guJiDate;
@property (assign,nonatomic) int erciqidong;
@property (strong,nonatomic) DUIInventoryVMNode *node;
@property (strong,nonatomic) DUIVMActionController *actionController;
@property (strong,nonatomic) BrushCode *brushCode;


-(void)saveGuanJi;
-(void)setGangOpen:(BOOL)isGangOpen;
-(void)saveOpenJiLu;
-(void)reset;
-(void)claer;
-(NSInteger)resetCount;
@end

//NS_ASSUME_NONNULL_END
