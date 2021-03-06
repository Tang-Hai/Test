//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLFTBBackgroundView.h"

#import "NSWindowDelegate.h"

@class NSString, NSToolbar, NSWindow, NSWindow<PLFTBTargetWindow>, PLFTBMinibarViewController;

@interface PLFTBAccessoryView : PLFTBBackgroundView <NSWindowDelegate>
{
    NSWindow<PLFTBTargetWindow> *targetWindow;
    NSToolbar *toolbar;
    NSWindow *mToolbarWindow;
    PLFTBMinibarViewController *mMinibarViewController;
    BOOL mShowFTBView;
}

@property(nonatomic) BOOL showFTBView; // @synthesize showFTBView=mShowFTBView;
@property(retain, nonatomic) PLFTBMinibarViewController *minibarViewController; // @synthesize minibarViewController=mMinibarViewController;
@property(retain, nonatomic) NSWindow *toolbarWindow; // @synthesize toolbarWindow=mToolbarWindow;
- (void)viewDidMoveToWindow;
- (void)drawRect:(struct CGRect)arg1;
- (void)setTemporarilyDisabled:(BOOL)arg1;
- (void)validateUserInterface;
- (void)configureSubview;
- (void)createMinibarViewWithSession:(id)arg1;
- (void)onMiniaturize:(id)arg1;
- (void)onExitFullScreen:(id)arg1;
- (void)parentWindowWillClose;
- (id)minibarView;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

