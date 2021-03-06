//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIDnD, NSString;

@interface DUIDockerWindowProxy : NSObject
{
    NSString *uuid;
    NSString *vmUUID;
    struct UnityWindow *unityWindow;
    DUIDnD *duiDnD;
    int dndDraggingState;
    struct _Region *lastGuestRegion;
    struct CGRect frame;
}

- (void)onDockerRequestCaretPosition:(id)arg1;
- (void)onDockerRequestSetFrame:(id)arg1;
- (void)onDockerDidResignKey:(id)arg1;
- (void)onDockerDidBecomeKey:(id)arg1;
- (void)onDockerRebindWindow:(id)arg1;
- (void)onDockerDisconnectWindow:(id)arg1;
- (void)onDockerConnectWindow:(id)arg1;
- (void)onDockerHostMaximize:(id)arg1;
- (void)onDockerHostMinimize:(id)arg1;
- (void)onDockerHostUnminimized:(id)arg1;
- (void)onDockerHostOrderFront:(id)arg1;
- (void)onDockerMouseExited:(id)arg1;
- (void)onDockerMouseEntered:(id)arg1;
- (void)onDockerMouseEvent:(id)arg1;
- (void)dragSourceMouseDragged:(struct CGPoint)arg1;
- (void)dragSourceMouseUp;
- (void)dragSourceMouseDown;
- (void)updateGuestDnDWindow:(BOOL)arg1;
- (void)listenForDockerMessages:(BOOL)arg1;
- (void)disconnect;
- (void)setUUID:(id)arg1;
- (void)dealloc;
- (void)setCaretPosition:(struct CGRect)arg1;
- (void)setAttentionWanted:(id)arg1;
- (void)setPresentationOptions:(unsigned long long)arg1;
- (void)setTransparency:(BOOL)arg1;
- (BOOL)setScreenUpdatesDisabled:(BOOL)arg1;
- (void)setTopmost:(BOOL)arg1;
- (void)close;
- (void)orderOut;
- (void)refreshRegion:(struct _Region *)arg1;
- (void)setCollectionBehavior:(unsigned long long)arg1;
- (void)deminiaturize;
- (void)miniaturize;
- (void)makeKeyAndOrderFront;
- (void)orderWindowAboveWindow:(const struct UnityWindow *)arg1;
- (struct UnityWindow *)unityWindow;
- (id)uuid;
- (struct CGRect)frame;
- (void)setFrame:(struct CGRect)arg1;
- (void)setTitle:(id)arg1;
- (void)synchronizeWindowAttributes;
- (void)setGuestApp:(id)arg1;
- (BOOL)isConnected;
- (id)initWithUnityWindow:(struct UnityWindow *)arg1 duiDnD:(id)arg2 vmUUID:(id)arg3;

@end

