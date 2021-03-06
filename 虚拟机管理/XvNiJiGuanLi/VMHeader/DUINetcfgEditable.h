//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class DUINetcfgNetwork, NSDictionary, NSString;

@interface DUINetcfgEditable : DUIAdaptorBase
{
}

- (void)invalidateAdaptation;
@property(readonly, nonatomic) struct Editable *adaptedNetcfgEditable;
@property(nonatomic) DUINetcfgNetwork *autoBridgeNetwork;
@property(readonly, nonatomic) NSString *unusedNetworkAdapter;
@property(readonly, nonatomic) NSDictionary *hostAdapters;
- (id)displayNameForAdapter:(id)arg1;
- (id)networkForAdaptor:(id)arg1;
- (void)moveHostAdapter:(id)arg1 network:(id)arg2;
- (void)addHostAdapter:(id)arg1 displayName:(id)arg2;
@property(readonly, nonatomic) NSDictionary *networks;
@property(readonly, nonatomic) unsigned int unusedNetwork;
- (id)network:(unsigned int)arg1;
- (void)removeNetwork:(unsigned int)arg1;
- (id)addNetwork:(unsigned int)arg1 type:(int)arg2 initialize:(BOOL)arg3 abortHandler:(CDUnknownBlockType)arg4;
@property(readonly, nonatomic) unsigned int maxNetworks;
- (id)init;

@end

