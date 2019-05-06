//
//  SOInputLineViewController+ClasssFunc.m
//  MessagesHook
//
//  Created by iobit on 2018/9/18.
//  Copyright © 2018年 Aiwei. All rights reserved.
//

#import "NSObject+ClasssFunc.h"
#import  <objc/runtime.h>

@implementation NSObject (ClasssFunc)


+(NSArray *)propertyList {
    
    unsigned int count = 0;
    
    objc_property_t *propertyList = class_copyPropertyList([self class] , &count);
    
    NSMutableArray *array = [NSMutableArray array];
    
    for(int i = 0 ; i < count ; i ++) {
        
        objc_property_t property = propertyList[i];
        
        const char *propertyChar = property_getName(property);
        
        NSString *propertyName = [NSString stringWithUTF8String:propertyChar];
        
        [array addObject:propertyName];
        
    }
    
    free(propertyList);
    
    return array.copy;
    
}



//2. 获取类的属性类型

+ (NSArray *)propertyType {
    
    unsigned int count = 0;
    
    objc_property_t *propertyList = class_copyPropertyList([self class] , &count);
    
    NSMutableArray *array = [NSMutableArray array];
    
    for(int i = 0 ; i < count ; i ++) {
        
        objc_property_t property = propertyList[i];
        
        const char *propertyChar = property_getAttributes(property);
        
        NSString *propertyName = [NSString stringWithUTF8String:propertyChar];
        
        [array addObject:propertyName];
        
    }
    
    free(propertyList);
    
    return array.copy;
}



//3.获取类的方法

+ (NSArray *)funcList {
    
    unsigned  int count = 0;
    
    Method *methodList = class_copyMethodList([self class] , &count);
    
    NSMutableArray *array = [NSMutableArray array];
    
    for(int i = 0 ; i < count ; i++) {
        
        Method method = methodList[i];
        
        SEL selector = method_getName(method);
        
        NSString *funcName  = NSStringFromSelector(selector);
        
        [array addObject:funcName];
    }
    
    free(methodList);
    
    return array.copy;
    
}

@end
