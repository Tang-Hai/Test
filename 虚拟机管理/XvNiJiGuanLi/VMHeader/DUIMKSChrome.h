//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSView.h"

@class DUIMKSScreen, DUIVM, DUIVMID, NSArray, NSColor, NSImage, NSMutableArray, NSString, NSTimer, NSWindow;

@interface DUIMKSChrome : NSView
{
    id <DUIMKSChromeDelegate> delegate;
    id mVMAddedObserver;
    BOOL isOpen;
    BOOL screenUpdatesDisabledFlag;
    BOOL hasInitialized;
    BOOL mWantsInput;
    BOOL mWantsDnD;
    BOOL mCanShowInlineProgress;
    BOOL mCanShowPlayButton;
    BOOL mHasShadow;
    BOOL mUseStackedLayout;
    BOOL mAllowInteractionsWithScreenshots;
    BOOL mAllowRendering;
    BOOL mSelected;
    BOOL mMKSIsInLiveResize;
    BOOL mWindowCanResize;
    BOOL mSuspendScreenshotPending;
    BOOL mScreenSizeChanged;
    int mWindowGroupID;
    int mDisplayMode;
    DUIVM *mVM;
    DUIVMID *mVMID;
    DUIMKSScreen *mMKSScreen;
    NSArray *mImages;
    double mShineFraction;
    NSColor *mBackgroundColor;
    NSImage *mBadgeImage;
    NSString *mBadgeText;
    NSWindow *mChildWindow;
    NSMutableArray *mChromeElements;
    NSMutableArray *mMKSOverlays;
    NSTimer *mDelayedLiveResizeTimer;
    NSImage *mTitleOverlayImage;
    struct CGSize mPreferredSize;
    struct CGRect mFrontRect;
}

@property(nonatomic) BOOL screenSizeChanged; // @synthesize screenSizeChanged=mScreenSizeChanged;
@property(nonatomic) int displayMode; // @synthesize displayMode=mDisplayMode;
@property(retain, nonatomic) NSImage *titleOverlayImage; // @synthesize titleOverlayImage=mTitleOverlayImage;
@property(retain, nonatomic) NSTimer *delayedLiveResizeTimer; // @synthesize delayedLiveResizeTimer=mDelayedLiveResizeTimer;
@property(retain, nonatomic) NSMutableArray *mksOverlays; // @synthesize mksOverlays=mMKSOverlays;
@property(retain, nonatomic) NSMutableArray *chromeElements; // @synthesize chromeElements=mChromeElements;
@property(nonatomic) BOOL suspendScreenshotPending; // @synthesize suspendScreenshotPending=mSuspendScreenshotPending;
@property(retain, nonatomic) NSWindow *childWindow; // @synthesize childWindow=mChildWindow;
@property(nonatomic) id <DUIMKSChromeDelegate> delegate; // @synthesize delegate;
@property(nonatomic) BOOL windowCanResize; // @synthesize windowCanResize=mWindowCanResize;
@property(nonatomic) BOOL mksIsInLiveResize; // @synthesize mksIsInLiveResize=mMKSIsInLiveResize;
@property(nonatomic) int windowGroupID; // @synthesize windowGroupID=mWindowGroupID;
@property(nonatomic) struct CGRect frontRect; // @synthesize frontRect=mFrontRect;
@property(nonatomic) struct CGSize preferredSize; // @synthesize preferredSize=mPreferredSize;
@property(nonatomic) BOOL selected; // @synthesize selected=mSelected;
@property(retain, nonatomic) NSString *badgeText; // @synthesize badgeText=mBadgeText;
@property(retain, nonatomic) NSImage *badgeImage; // @synthesize badgeImage=mBadgeImage;
@property(retain, nonatomic) NSColor *backgroundColor; // @synthesize backgroundColor=mBackgroundColor;
@property(nonatomic) double shineFraction; // @synthesize shineFraction=mShineFraction;
@property(retain, nonatomic) NSArray *images; // @synthesize images=mImages;
@property(nonatomic) BOOL allowRendering; // @synthesize allowRendering=mAllowRendering;
@property(nonatomic) BOOL allowInteractionWithScreenshots; // @synthesize allowInteractionWithScreenshots=mAllowInteractionsWithScreenshots;
@property(nonatomic) BOOL useStackedLayout; // @synthesize useStackedLayout=mUseStackedLayout;
@property(nonatomic) BOOL hasShadow; // @synthesize hasShadow=mHasShadow;
@property(nonatomic) BOOL canShowPlayButton; // @synthesize canShowPlayButton=mCanShowPlayButton;
@property(nonatomic) BOOL canShowInlineProgress; // @synthesize canShowInlineProgress=mCanShowInlineProgress;
@property(nonatomic) BOOL wantsDnD; // @synthesize wantsDnD=mWantsDnD;
@property(nonatomic) BOOL wantsInput; // @synthesize wantsInput=mWantsInput;
@property(retain, nonatomic) DUIMKSScreen *mksScreen; // @synthesize mksScreen=mMKSScreen;
@property(retain, nonatomic) DUIVMID *vmID; // @synthesize vmID=mVMID;
@property(nonatomic) DUIVM *vm; // @synthesize vm=mVM;
- (id)description;
- (void)onDelayedLiveResizeTimer:(id)arg1;
- (void)startDelayedLiveResizeTimer;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (struct CGRect)rectForTitleImage:(id)arg1 inBounds:(struct CGRect)arg2;
- (id)imageForAnimationInRect:(struct CGRect)arg1;
- (void)setUngrabRect:(struct CGRect)arg1;
- (id)liveVMScreenshot;
- (void)removeOverlay:(id)arg1;
- (void)addOverlay:(id)arg1;
- (id)overlays;
- (id)namesOfPromisedFilesDroppedAtDestination:(id)arg1;
- (id)typesOfPromisedFilesToDrop;
- (id)chromeElementForIdentifier:(int)arg1;
- (void)addChromeElement:(id)arg1;
- (void)updateForChromeElement:(id)arg1;
- (void)setScreenUpdatesDisabled:(BOOL)arg1;
- (void)updateAllElements;
- (void)internalUpdateForChromeElement:(id)arg1;
- (BOOL)performUpdateForChromeElement:(id)arg1;
- (void)updateChildWindowFrame;
- (void)closeChildWindow;
- (void)openChildWindow;
- (void)viewDidEndLiveResize;
- (void)viewWillStartLiveResize;
- (void)resizeSubviewsWithOldSize:(struct CGSize)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (void)viewWillDraw;
- (void)onWindowMove:(id)arg1;
- (void)viewWillMoveToWindow:(id)arg1;
- (void)dealloc;
- (void)initialize;
- (void)commonInitializer;
- (void)awakeFromNib;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)initWithCoder:(id)arg1;

@end

