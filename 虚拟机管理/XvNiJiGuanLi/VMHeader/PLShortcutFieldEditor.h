//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSTextView.h"

@class DUIKeyboardAndMouseMappingInfo;

@interface PLShortcutFieldEditor : NSTextView
{
    DUIKeyboardAndMouseMappingInfo *mShortcut;
}

@property(retain, nonatomic) DUIKeyboardAndMouseMappingInfo *shortcut; // @synthesize shortcut=mShortcut;
- (BOOL)validateMenuItem:(id)arg1;
- (void)addKeyEvent:(id)arg1 modifier:(int)arg2;
- (void)keyDown:(id)arg1;
- (void)updateStringValue;
- (void)setDelegate:(id)arg1;
- (void)dealloc;

@end

