//
//  BrushCode.h
//  刷码神器
//
//  Created by iobit on 2018/9/30.
//  Copyright © 2018年 iobit. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BrushCode : NSObject
@property (copy,nonatomic) NSString *rom;
@property (copy,nonatomic) NSString *mlb;
@property (copy,nonatomic) NSString *serialNumber;
@property (copy,nonatomic) NSString *boardID;
@property (copy,nonatomic) NSString *model;
@property (copy,nonatomic) NSNumber *ID;

@property (copy,nonatomic) NSString *machineNumber;
@property (assign,nonatomic) int getResult;

-(instancetype)initWithRom:(NSString *)rom
                       mlb:(NSString *)mlb
              serialNumber:(NSString *)serialNumber
                   boardID:(NSString *)boardID
                     model:(NSString *)model
                        ID:(NSNumber *)ID;
-(NSString *)vmxRom;
@end
