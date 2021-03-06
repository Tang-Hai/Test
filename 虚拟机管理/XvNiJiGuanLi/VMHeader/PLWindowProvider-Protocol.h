//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSNotification, NSObject<PLContent>, NSWindow, PLSession, PLVMSnapshotWindowController;

@protocol PLWindowProvider <NSObject>
- (void)closeContent:(NSObject<PLContent> *)arg1;
- (NSObject<PLContent> *)activeContent;
- (NSArray *)allContents;
- (void)windowWillClose:(NSNotification *)arg1;
- (BOOL)windowShouldClose:(id)arg1;
- (void)orderFrontAllWindows:(BOOL)arg1;
- (void)close;
- (void)showWindows;
- (void)openWindows;
- (void)openWithSession:(PLSession *)arg1;
- (NSWindow *)primaryWindow;
- (NSArray *)allWindows;

@optional
- (PLVMSnapshotWindowController *)snapshotWindowController;
@end

