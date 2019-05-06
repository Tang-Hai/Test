//
//  NSObject+aspect.m
//  MessagesHook
//
//  Created by iobit on 2018/9/19.
//  Copyright © 2018年 Aiwei. All rights reserved.
//
///System/Library/PrivateFrameworks/AccessibilitySupport.framework
#import "NSObject+aspect.h"
#import "Aspects.h"
#import <objc/runtime.h>

@implementation NSObject (aspect)

-(void)aspect_hookSelector:(SEL)sel usingBlock:(id)block {
  
    [self aspect_hookSelector:sel withOptions:0 usingBlock:^(id info, id sender) {
        
        
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            
            [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],NSStringFromSelector(sel),idx,[obj class],obj,[obj superclass]);
            }];
            void(^newBlock)(id,id) = block;
            newBlock(info,sender);
        });
    } error:NULL];
}

//[sot awakeFromNib];

#pragma mark - IDSIDQueryController

+(void)chat {
   [self jr_swizzleMethod:@selector(chat) withMethod:@selector(hoot_chat) error:nil];
}

+(void)initWithNodesTreeController {
    
    //[self jr_swizzleMethod:@selector(initWithNodes:treeController:dlgMgr:delegate:abortHandler: doneHandler:) withMethod:@selector(initWithNodesxxx:treeController:dlgMgr:delegate:abortHandler: doneHandler:) error:nil];
}

- (id)initWithNodesxxx:(id)arg1 treeController:(id)arg2 dlgMgr:(id)arg3 delegate:(id)arg4 abortHandler:(void(^)(void))arg5 doneHandler:(void(^)(void))arg6 {
    HookLog(@"initWithNodesxxx Nodes=%@--treeController=%@,dlgMgr=%@,delegate=%@",arg1,arg2,arg3,arg4);
    return [self initWithNodesxxx:arg1 treeController:arg2 dlgMgr:arg3 delegate:arg4 abortHandler:arg5 doneHandler:arg6];
}

+(void)HookMouseDown
{
    NSError *error;
    [self jr_swizzleMethod:@selector(mouseDown:) withMethod:@selector(hook_mouseDown:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
}

-(void)hook_mouseDown:(NSEvent *)event {
    [self hook_mouseDown:event];
    HookLog(@"我来过 hook_mouseDown");
    HookLog(@"button taegrt=%@--action=%@",[(NSButton *)self target],NSStringFromSelector([(NSButton *)self action]));
}

- (NSArray *)getAllSELs
{
    u_int count;
    NSMutableArray *array = [NSMutableArray array];
    //class_copyMethodList 获取类的所有方法列表
    Method *mothList_f = class_copyMethodList([self class],&count) ;
    for (int i = 0; i < count; i++) {
        Method temp_f = mothList_f[i];
        // method_getImplementation 由Method得到IMP函数指针
       // IMP imp_f = method_getImplementation(temp_f);
        
        // method_getName由Method得到SEL
        SEL name_f = method_getName(temp_f);
        if ([NSStringFromClass([self class]) isEqualToString:@"SOInputLine"]) {
            HookLog(@"SOInputLine = %@",NSStringFromSelector(name_f));
        }
        [array addObject:NSStringFromSelector(name_f)];
    }
    free(mothList_f);
    return array;
}

- (void)logAllMethods
{
    u_int count;
    //class_copyMethodList 获取类的所有方法列表
    Method *mothList_f = class_copyMethodList([self class],&count) ;
    for (int i = 0; i < count; i++) {
        Method temp_f = mothList_f[i];
        // method_getImplementation 由Method得到IMP函数指针
        IMP imp_f = method_getImplementation(temp_f);
        
        // method_getName由Method得到SEL
        SEL name_f = method_getName(temp_f);
        
        const char * name_s = sel_getName(name_f);
        // method_getNumberOfArguments  由Method得到参数个数
        int arguments = method_getNumberOfArguments(temp_f);
        // method_getTypeEncoding  由Method得到Encoding 类型
        const char * encoding = method_getTypeEncoding(temp_f);
        
        NSLog(@"方法名：%@\n,参数个数：%d\n,编码方式：%@\n",[NSString stringWithUTF8String:name_s],
              arguments,[NSString stringWithUTF8String:encoding]);
    }
    free(mothList_f);
}

- (NSArray *)getAllProperties
{
    u_int count;
    
    //使用class_copyPropertyList及property_getName获取类的属性列表及每个属性的名称
    
    objc_property_t *properties  =class_copyPropertyList([self class], &count);
    NSMutableArray *propertiesArray = [NSMutableArray arrayWithCapacity:count];
    for (int i = 0; i<count; i++)
    {
        const char* propertyName =property_getName(properties[i]);
        //NSLog(@"属性%@\n",[NSString stringWithUTF8String: propertyName]);
        [propertiesArray addObject: [NSString stringWithUTF8String: propertyName]];
    }
    free(properties);
    return propertiesArray;
}

@end
