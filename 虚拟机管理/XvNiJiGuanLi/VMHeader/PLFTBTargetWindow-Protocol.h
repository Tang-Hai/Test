//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLFTBBaseWindow.h"

@class PLFTBAccessoryView, PLFTBMinibarView;

@protocol PLFTBTargetWindow <PLFTBBaseWindow>
- (void)updateMinibar:(PLFTBMinibarView *)arg1;
- (PLFTBAccessoryView *)accessoryView;

@optional
- (BOOL)moveToScreenWithPoint:(struct CGPoint)arg1;
@end

