//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class NSString;

@interface DUIRemoteMessager : DUIAdaptorBase
{
}

+ (id)remoteMessagerWithIpAddress:(id)arg1 port:(unsigned short)arg2;
- (void)invalidateAdaptation;
- (id)initWithIpAddress:(id)arg1 port:(unsigned short)arg2;
@property(readonly, nonatomic) struct RemoteMessager *adaptedRemoteMessager;
@property(readonly, copy, nonatomic) NSString *remoteIpAddress;
@property(readonly, copy, nonatomic) NSString *localIpAddress;
- (void)send:(id)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;

@end

