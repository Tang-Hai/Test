//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSWindowController.h"

#import "CAAnimationDelegate.h"

@class NSString;

@interface PLFullScreenMessageWindowController : NSWindowController <CAAnimationDelegate>
{
}

- (void)updateMessageWindowFrame;
- (void)animationDidStop:(id)arg1 finished:(BOOL)arg2;
- (void)mouseUp:(id)arg1;
- (void)close;
- (id)initWithMessage:(id)arg1 parentWindow:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

