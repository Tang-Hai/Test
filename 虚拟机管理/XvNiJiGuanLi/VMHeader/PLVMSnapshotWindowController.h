//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLSessionAuxWindowController.h"

//#import "PLSnapshotProgressViewDelegate.h"

@class NSButton, PLSnapshotProgressView, PLVMSnapshotViewController;

@interface PLVMSnapshotWindowController : PLSessionAuxWindowController //<PLSnapshotProgressViewDelegate>
{
    NSButton *takeButton;
    NSButton *deleteButton;
    NSButton *saveAndRevertButton;
    NSButton *autoProtectSettingsButton;
    NSButton *revertButton;
    PLVMSnapshotViewController *snapshotViewController;
    PLSnapshotProgressView *progressView;
}

+ (id)toolbarValidationKeyPaths;
@property(retain, nonatomic) PLSnapshotProgressView *progressView; // @synthesize progressView;
@property(retain, nonatomic) PLVMSnapshotViewController *snapshotViewController; // @synthesize snapshotViewController;
- (void)windowDidChangeOcclusionState:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)onSnapshotWindowAutoProtect:(id)arg1;
- (void)onSnapshotWindowRevert:(id)arg1;
- (void)onSnapshotWindowDelete:(id)arg1;
- (void)onSnapshotWindowTake:(id)arg1;
- (void)prepareToCloseContentWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (void)shouldCloseContentWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (BOOL)canSessionCloseForTermination:(BOOL)arg1;
- (void)onProgressDone;
- (void)addProgress:(id)arg1 withViewController:(id)arg2;
- (BOOL)snapshotWindowWantsProgress;
- (void)showSnapshotWindow;
- (id)windowTitle;
- (void)close;
- (void)onWindowDidEndSheet:(id)arg1;
- (void)onWindowWillBeginSheet:(id)arg1;
- (void)dealloc;
- (void)windowDidLoad;
- (id)initWithSession:(id)arg1;

@end

