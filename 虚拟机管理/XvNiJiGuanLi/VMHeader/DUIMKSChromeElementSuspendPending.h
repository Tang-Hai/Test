//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "DUIMKSChromeElement.h"

@class DUIMKSChrome, NSString, NSView;

@interface DUIMKSChromeElementSuspendPending : NSObject <DUIMKSChromeElement>
{
    BOOL mIsOpen;
    DUIMKSChrome *mChrome;
    NSView *mBackgroundView;
}

+ (id)observationKeyPaths;
@property(retain, nonatomic) NSView *backgroundView; // @synthesize backgroundView=mBackgroundView;
@property(nonatomic) BOOL isOpen; // @synthesize isOpen=mIsOpen;
@property(nonatomic) DUIMKSChrome *chrome; // @synthesize chrome=mChrome;
- (void)invalidateChrome;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)dealloc;
- (void)updateScreens;
- (BOOL)isInChildWindow;
- (int)identifier;
- (BOOL)needsChildWindow;
- (void)resize;
- (BOOL)shouldOpen;
- (void)close;
- (void)open;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

