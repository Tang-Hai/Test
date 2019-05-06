//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class NSArray;

@interface DUIAutoProtectConfigMgr : DUIAdaptorBase
{
}

+ (id)autoProtectConfigMgrWithConfig:(id)arg1 andTransaction:(id)arg2;
@property(readonly, nonatomic) NSArray *autoProtectText;
@property(readonly, nonatomic) unsigned long long autoProtectMinimumMB;
- (void)invalidateAdaptation;
@property(readonly, nonatomic) struct AutoProtectConfigMgr *adaptedAutoProtectConfigMgr;
- (id)initWithConfig:(id)arg1 andTransaction:(id)arg2;
- (void)setMaximum:(int)arg1;
- (int)maximum;
- (void)setFrequency:(int)arg1;
- (int)frequency;
- (void)setEnabled:(BOOL)arg1;
- (BOOL)enabled;

@end

