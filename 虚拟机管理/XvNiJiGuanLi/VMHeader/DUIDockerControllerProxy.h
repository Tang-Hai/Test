//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface DUIDockerControllerProxy : NSObject
{
}

- (void)broadcastSystemQuitReply:(BOOL)arg1;
- (void)onSystemQuit:(id)arg1;
- (void)onDockerRunGuestProgram:(id)arg1;
- (void)listenForDockerMessages:(BOOL)arg1;
- (void)dealloc;
- (void)disconnect;
- (void)connect;

@end

