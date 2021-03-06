//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLVMCommonWindowProvider.h"

#import "NSAnimationDelegate.h"
#import "NSMenuDelegate.h"
#import "PLVMPrimaryWindowDelegate.h"
#import "PLWindowProvider.h"

@class NSString, PLVMSession;

@interface PLVMSessionWindowProvider : PLVMCommonWindowProvider <PLWindowProvider, NSAnimationDelegate, NSMenuDelegate, PLVMPrimaryWindowDelegate>
{
    BOOL mUpdateInProgress;
    BOOL mUseDefaultMode;
    BOOL mIsAnimating;
    long long mRetryToggleFullScreenCount;
}

+ (id)observationKeyPaths;
@property(nonatomic) BOOL isAnimating; // @synthesize isAnimating=mIsAnimating;
@property(nonatomic) long long retryToggleFullScreenCount; // @synthesize retryToggleFullScreenCount=mRetryToggleFullScreenCount;
@property(nonatomic) BOOL useDefaultMode; // @synthesize useDefaultMode=mUseDefaultMode;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)window:(id)arg1 startCustomAnimationToExitFullScreenWithDuration:(double)arg2;
- (void)window:(id)arg1 startCustomAnimationToEnterFullScreenWithDuration:(double)arg2;
- (id)customWindowsToExitFullScreenForWindow:(id)arg1;
- (id)customWindowsToEnterFullScreenForWindow:(id)arg1;
- (void)windowDidFailToExitFullScreen:(id)arg1;
- (void)windowDidFailToEnterFullScreen:(id)arg1;
- (BOOL)retryFullScreenTransition:(id)arg1;
- (void)windowDidEnterFullScreen:(id)arg1;
- (void)startAnimation:(id)arg1 duration:(double)arg2;
- (void)animationDidStop:(id)arg1;
- (void)animationDidEnd:(id)arg1;
- (void)addSecondaryFadeOutAnimations:(id)arg1 forWindows:(id)arg2;
- (void)addSecondaryFadeInAnimations:(id)arg1 forWindows:(id)arg2;
- (id)fullScreenExitAnimationsForWindow:(id)arg1;
- (id)fullScreenEnterAnimationsForWindow:(id)arg1 targetScreen:(id)arg2;
- (id)hostScreensForAnimation;
- (void)syncWindows;
- (void)window:(id)arg1 didChangeViewModeFrom:(int)arg2 to:(int)arg3;
- (void)window:(id)arg1 willChangeViewModeFrom:(int)arg2 to:(int)arg3;
- (struct CGRect)window:(id)arg1 willPositionSheet:(id)arg2 usingRect:(struct CGRect)arg3;
- (void)windowDidEndSheet:(id)arg1;
- (void)windowWillBeginSheet:(id)arg1;
- (void)windowDidMove:(id)arg1;
- (void)windowDidEndLiveResize:(id)arg1;
- (BOOL)windowIsVMLayerWindow:(id)arg1;
- (void)minibarSettingsDidChange;
- (void)updateMinibarOptions;
- (void)updateMinibarForViewMode:(int)arg1;
- (void)configureMinibarShowPref;
- (void)configureHideMenuBar;
- (BOOL)canSwitchVMLayers;
- (BOOL)isInFullScreen;
- (void)switchToFullScreen;
- (void)updateActiveLayer;
- (void)updateWindowProviderForLayer:(id)arg1;
- (void)toggleFullScreenForLayer:(id)arg1;
- (BOOL)restoreWindow:(id)arg1 withCoder:(id)arg2;
- (void)restoreSessionWindowWithIdentifier:(id)arg1 state:(id)arg2 completionHandler:(CDUnknownBlockType)arg3;
- (void)configureRestorableWindows;
- (id)createAuxWindowControllerWithKindOfClass:(Class)arg1;
- (void)closeForBackgroundProcessing;
- (void)closeAllMKSWindows;
- (void)prepareToClose;
- (void)orderFrontAllWindows:(BOOL)arg1;
- (void)showWindows;
- (void)showMKSWindows;
- (void)openWindows;
- (id)allMKSWindows;
- (id)primaryVMWindow;
- (BOOL)updateWindowCount:(unsigned long long)arg1;
- (BOOL)updateWindowCount:(unsigned long long)arg1 forLayer:(id)arg2;
- (void)primaryWindowDidClose;
- (id)createPrimaryWindow;
- (void)updateWindowsForLayer:(id)arg1 shouldShow:(BOOL)arg2;
- (void)updateWindowLayoutWithScreens:(id)arg1;
- (void)onDisplayReconfigured:(id)arg1;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(retain, nonatomic) PLVMSession *session; // @dynamic session;
@property(readonly) Class superclass;

@end

