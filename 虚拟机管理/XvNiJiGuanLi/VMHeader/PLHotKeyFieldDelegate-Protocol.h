//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIHotKey, PLHotKeyField;

@protocol PLHotKeyFieldDelegate <NSObject>
- (void)hotKeyFieldDidClear:(PLHotKeyField *)arg1;
- (void)hotKeyField:(PLHotKeyField *)arg1 didReceiveHotKey:(DUIHotKey *)arg2;
@end

