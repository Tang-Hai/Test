//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSWindowController.h"

@class NSTimer;

@interface DUITransientMessageWindowController : NSWindowController
{
    NSTimer *messageFadeTimer;
}

- (void)updateWindowFade:(id)arg1;
- (void)setMessageFadeTimer:(id)arg1;
- (void)scheduleMessageFade;
- (void)updateMessageWindowFrame;
- (void)close;
- (void)dealloc;
- (id)initWithMessage:(id)arg1 parentWindow:(id)arg2;

@end

