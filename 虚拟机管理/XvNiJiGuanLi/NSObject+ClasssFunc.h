//
//  SOInputLineViewController+ClasssFunc.h
//  MessagesHook
//
//  Created by iobit on 2018/9/18.
//  Copyright © 2018年 Aiwei. All rights reserved.
//



@interface NSObject (ClasssFunc)

+(NSArray *)propertyList;

//2. 获取类的属性类型

+ (NSArray *)propertyType;

//3.获取类的方法

+ (NSArray *)funcList;
@end
