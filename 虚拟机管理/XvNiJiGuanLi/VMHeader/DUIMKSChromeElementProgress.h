//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "DUIMKSChromeElement.h"

@class DUIMKSChrome, DUIProgressViewController, NSString, NSView;

@interface DUIMKSChromeElementProgress : NSObject <DUIMKSChromeElement>
{
    BOOL mIsOpen;
    BOOL mIsInChildWindow;
    DUIMKSChrome *mChrome;
    DUIProgressViewController *mProgressViewController;
    DUIProgressViewController *mSmallProgressViewController;
    DUIProgressViewController *mLargeProgressViewController;
    NSView *mBackgroundView;
}

+ (id)observationKeyPaths;
@property(retain, nonatomic) NSView *backgroundView; // @synthesize backgroundView=mBackgroundView;
@property(retain, nonatomic) DUIProgressViewController *largeProgressViewController; // @synthesize largeProgressViewController=mLargeProgressViewController;
@property(retain, nonatomic) DUIProgressViewController *smallProgressViewController; // @synthesize smallProgressViewController=mSmallProgressViewController;
@property(retain, nonatomic) DUIProgressViewController *progressViewController; // @synthesize progressViewController=mProgressViewController;
@property(nonatomic) BOOL isInChildWindow; // @synthesize isInChildWindow=mIsInChildWindow;
@property(nonatomic) BOOL isOpen; // @synthesize isOpen=mIsOpen;
@property(nonatomic) DUIMKSChrome *chrome; // @synthesize chrome=mChrome;
- (void)invalidateChrome;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)performLayout;
- (void)update;
- (void)onProgressViewFrameDidChange:(id)arg1;
- (id)newestBlockingProgress;
- (void)dealloc;
- (int)identifier;
- (BOOL)needsChildWindow;
- (void)resize;
- (BOOL)shouldOpen;
- (void)close;
- (void)updateProgressViewController;
- (void)open;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

