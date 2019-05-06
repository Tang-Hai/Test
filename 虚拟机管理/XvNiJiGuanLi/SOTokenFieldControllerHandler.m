//
//  SOTokenFieldControllerHandler.m
//  MessagesHook
//
//  Created by Aiwei on 2018/8/6.
//  Copyright © 2018年 Aiwei. All rights reserved.
//

#import "SOTokenFieldControllerHandler.h"
#import "SOTokenFieldController.h"


@implementation NSObject(SOTokenFieldController_Hook)

+(void)hookTokenFieldControllerMethod
{
    NSError *error;
    
    [self jr_swizzleMethod:@selector(idStatusUpdatedForDestinations:) withMethod:@selector(hook_idStatusUpdatedForDestinations:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
//    [self jr_swizzleMethod:@selector(iconTypeForResult:selected:) withMethod:@selector(hook_iconTypeForResult:selected:) error:&error];
//    if (error) {
//        HookLog(@"hookerror:%@",error);
//        error = nil;
//    }
    [self jr_swizzleMethod:@selector(showContactCard:) withMethod:@selector(hook_showContactCard:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
    [self jr_swizzleMethod:@selector(tokenAttachmentCell:doubleClickedInRect:ofView:) withMethod:@selector(hook_tokenAttachmentCell:doubleClickedInRect:ofView:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
    [self jr_swizzleMethod:@selector(_updateHandleTokenFromNotification:) withMethod:@selector(hook__updateHandleTokenFromNotification:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
    [self jr_swizzleMethod:@selector(selectedResult:) withMethod:@selector(hook_selectedResult:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
//    [self jr_swizzleMethod:@selector(tokenField:setUpTokenAttachmentCell:forRepresentedObject:) withMethod:@selector(hook_tokenField:setUpTokenAttachmentCell:forRepresentedObject:) error:&error];
//    if (error) {
//        HookLog(@"hookerror:%@",error);
//        error = nil;
//    }
    [self jr_swizzleMethod:@selector(tokenField:shouldAddObjects:atIndex:) withMethod:@selector(hook_tokenField:shouldAddObjects:atIndex:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
    [self jr_swizzleMethod:@selector(tokenAttachmentCellHasErrorState:) withMethod:@selector(hook_tokenAttachmentCellHasErrorState:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
    [self jr_swizzleMethod:@selector(appendIMHandles:) withMethod:@selector(hook_appendIMHandles:) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
    
}
- (void)hook_idStatusUpdatedForDestinations:(id)arg1
{
    HookLog(@"[+sot]%s-->args:%@",__PRETTY_FUNCTION__,@[arg1]);
    [self hook_idStatusUpdatedForDestinations:arg1];
}
//返回联系人icon
//- (id)hook_iconTypeForResult:(id)arg1 selected:(BOOL)arg2
//{
//    id obj = [self hook_iconTypeForResult:arg1 selected:arg2];
//    HookLog(@"[+sot]%s-->args:%@,return:%@",__PRETTY_FUNCTION__,arg1,obj);
//    return obj;
//}

- (void)hook_showContactCard:(id)arg1
{
    HookLog(@"[+sot]%s-->args:%@",__PRETTY_FUNCTION__,@[arg1]);
    [self hook_showContactCard:arg1];
}
- (BOOL)hook_tokenAttachmentCell:(id)arg1 doubleClickedInRect:(struct CGRect)arg2 ofView:(id)arg3
{
    HookLog(@"[+sot]%s-->args:%@",__PRETTY_FUNCTION__,@[arg1,NSStringFromRect(arg2),arg3]);
    return [self hook_tokenAttachmentCell:arg1 doubleClickedInRect:arg2 ofView:arg3];
}
- (void)hook__updateHandleTokenFromNotification:(id)arg1
{
    HookLog(@"[+sot]%s-->args:%@",__PRETTY_FUNCTION__,@[arg1]);
    [self hook__updateHandleTokenFromNotification:arg1];
}
- (void)hook_selectedResult:(id)arg1
{
    HookLog(@"[+sot]%s-->args:%@",__PRETTY_FUNCTION__,arg1);
    [self hook_selectedResult:arg1];
}
//- (id)hook_tokenField:(id)arg1 setUpTokenAttachmentCell:(id)arg2 forRepresentedObject:(id)arg3
//{
//    id obj = [self hook_tokenField:arg1 setUpTokenAttachmentCell:arg2 forRepresentedObject:arg3];
//    HookLog(@"[+sot]cell:%@,re:%@",arg3,obj);
//    id result = [self performSelector:NSSelectorFromString(@"tokenAttachmentCellHasErrorState:") withObject:arg2];
//    NSTokenField *t1 = [self valueForKey:@"layoutTestTokenField"];
//    NSTokenField *t2 = [self performSelector:NSSelectorFromString(@"tokenField")];
//    HookLog(@"t1->text:%@,t2->text:%@",t1.stringValue,t2.stringValue);
//    if ([result boolValue])
//    {
//        HookLog(@"YES");
//        return nil;
//    }
//    else  HookLog(@"NO");
//    return obj;
//}
- (id)hook_tokenField:(id)arg1 shouldAddObjects:(id)arg2 atIndex:(unsigned long long)arg3
{
    NSArray *objArray = (NSArray *)[self hook_tokenField:arg1 shouldAddObjects:arg2 atIndex:arg3];
    HookLog(@"addobj->array:%@,obj:%@",objArray,arg2);
   
    return objArray;
}
- (BOOL)hook_tokenAttachmentCellHasErrorState:(id)arg1
{
    BOOL errState = [self hook_tokenAttachmentCellHasErrorState:arg1];
//    HookLog(@"[+sot]errState:%d,arg:%@",errState,arg1);
    return errState;
}
- (void)hook_appendIMHandles:(id)arg1
{
    HookLog(@"%s->arg1:%@",__PRETTY_FUNCTION__,arg1);
}
@end

@implementation NSObject(SOTokenAttachmentCell_Hook)

+(void)hookSOTokenAttachmentCellMethod
{
    NSError *error;
    
//    [self jr_swizzleMethod:@selector(updateIconWithColor:) withMethod:@selector(hook_updateIconWithColor:) error:&error];
//    if (error) {
//        HookLog(@"hookerror:%@",error);
//        error = nil;
//    }
//    [self jr_swizzleMethod:@selector(setRepresentedObject:) withMethod:@selector(hook_setRepresentedObject:) error:&error];
//    if (error) {
//        HookLog(@"hookerror:%@",error);
//        error = nil;
//    }
    [self jr_swizzleMethod:@selector(tokenTintColor) withMethod:@selector(hook_tokenTintColor) error:&error];
    if (error) {
        HookLog(@"hookerror:%@",error);
        error = nil;
    }
}
//- (void)hook_updateIconWithColor:(id)arg1
//{
//    HookLog(@"[+sot]%s-->args:%@",__PRETTY_FUNCTION__,arg1);
//    [self hook_updateIconWithColor:arg1];
//}
//- (void)hook_setRepresentedObject:(id)arg1
//{
//    HookLog(@"[+sot]%s-->args:%@",__PRETTY_FUNCTION__,arg1);
//    [self hook_setRepresentedObject:arg1];
//}
- (id)hook_tokenTintColor
{
    id color = [self hook_tokenTintColor];
    HookLog(@"[+sot]tinColor:%@",color);
    return color;
}
@end

@interface SOTokenFieldControllerHandler()

@property(nonatomic,readwrite)NSViewController *controller;


@end

@implementation SOTokenFieldControllerHandler

+(SOTokenFieldControllerHandler *)handler
{
    static SOTokenFieldControllerHandler *handler;
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
+(SOTokenFieldControllerHandler *)handlerWithController:(NSViewController *)controller
{
    SOTokenFieldControllerHandler *handler = [self handler];
    handler.controller = controller;
    return handler;
}
-(void)handleViewDidLoad
{
    [[self.controller class] hookTokenFieldControllerMethod];
    [NSClassFromString(@"SOTokenAttachmentCell") hookSOTokenAttachmentCellMethod];
//    HookLog(@"[+sot]tokenfiled:%@,layoutfield:%@",[self.controller hook_tokenField],[self valueForKey:@"layoutTestTokenField"]);
}
@end
