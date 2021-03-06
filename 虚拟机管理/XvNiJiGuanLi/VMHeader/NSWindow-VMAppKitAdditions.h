//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSWindow.h"

@interface NSWindow (VMAppKitAdditions)
+ (id)allOrderedWindows;
+ (BOOL)areAllAppWindowsInFront;
+ (BOOL)windowNumber:(long long)arg1 isAboveWindowNumber:(long long)arg2;
- (void)shakeWindow;
- (struct CGPoint)convertPointFromScreen:(struct CGPoint)arg1;
- (struct CGPoint)convertPointToScreen:(struct CGPoint)arg1;
- (BOOL)isSheetAncestor:(id)arg1;
- (id)sheetAncestor;
- (BOOL)validateAndEndEditing;
- (BOOL)isAboveWindowNumber:(long long)arg1;
- (void)setWindowResizable:(BOOL)arg1;
- (void)setCloseButtonEnabled:(BOOL)arg1;
- (void)setFrameOrCenterUsingName:(id)arg1;
@end

