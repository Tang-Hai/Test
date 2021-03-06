//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString;

@interface VMIPCObserverEntry : NSObject
{
    NSString *name;
    NSString *object;
    SEL selector;
}

+ (id)observerEntryTableFromNotification:(id)arg1;
- (void)dealloc;
- (id)matchesInObserverArray:(id)arg1;
- (id)propertyList;
- (SEL)selector;
- (id)object;
- (id)name;
- (id)initWithName:(id)arg1 object:(id)arg2 selector:(SEL)arg3;

@end

