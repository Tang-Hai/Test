//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUINotificationAreaController.h"

@class DUIVM;

@interface DUIVMNotificationAreaController : DUINotificationAreaController
{
    DUIVM *mVM;
}

@property(nonatomic) DUIVM *vm; // @synthesize vm=mVM;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (BOOL)shouldShowNotificationArea;
- (void)dealloc;
- (id)initWithVM:(id)arg1;

@end

