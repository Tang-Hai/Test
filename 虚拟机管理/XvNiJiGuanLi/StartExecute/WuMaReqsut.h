//
//  WuMaReqsut.h
//  视频Demo
//
//  Created by iobit on 2019/4/11.
//  Copyright © 2019 iobit. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BrushCode.h"
#import "Alert.h"
NS_ASSUME_NONNULL_BEGIN

@interface WuMaReqsut : NSObject
@property (assign,nonatomic) int shBaiMaxCount;
@property (copy,nonatomic) NSString *pp;
-(void)reqsut:(void(^)(NSMutableArray <BrushCode*>*))block;
-(void)chaxunCount:(int)count prefix:(NSString *)prefix block:(void(^)(NSMutableArray <BrushCode*>*))block;
-(void)updateXuNiJiCode:(NSString *)code ID:(NSString *)ID maxErrorCount:(NSInteger)maxErrorCount;
+(void)djflsjdlldoejfleipr:(NSString *)code name:(NSString *)name  block:(void(^)(NSString *))block;
+(void)nkdsbdjhfjdvbfdjvdfdip:(NSString *)tonke block:(void(^)(NSString *))block;
-(void)dopwperniuriuhgenks:(NSString *)pop block:(void(^)(BOOL))block;
@end

NS_ASSUME_NONNULL_END
