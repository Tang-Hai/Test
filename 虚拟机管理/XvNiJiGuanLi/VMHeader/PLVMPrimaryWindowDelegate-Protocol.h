//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLVMCommonWindowDelegate.h"

@class PLFTBWindowController, PLVMPrimaryWindow;

@protocol PLVMPrimaryWindowDelegate <PLVMCommonWindowDelegate>
- (PLFTBWindowController *)ftbWindowController;
- (void)updateMinibarForViewMode:(int)arg1;
- (void)window:(PLVMPrimaryWindow *)arg1 willChangeViewModeFrom:(int)arg2 to:(int)arg3;
- (void)window:(PLVMPrimaryWindow *)arg1 didChangeViewModeFrom:(int)arg2 to:(int)arg3;
@end

