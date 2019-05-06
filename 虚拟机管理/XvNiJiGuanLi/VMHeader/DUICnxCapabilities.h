//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class NSArray;

@interface DUICnxCapabilities : DUIAdaptorBase
{
}

+ (id)cnxCapabilitiesForAdaptedCnxCapabilities:(struct CnxCapabilities *)arg1;
@property(readonly, retain, nonatomic) NSArray *supportsVMCreationFailureReasons;
@property(readonly, nonatomic) BOOL supportsVMCreation;
@property(readonly, retain, nonatomic) NSArray *canSupportSoftPowerOperationsFailureReasons;
@property(readonly, nonatomic) BOOL canSupportSoftPowerOperations;
@property(readonly, retain, nonatomic) NSArray *canProvideHostUsageStatsFailureReasons;
@property(readonly, nonatomic) BOOL canProvideHostUsageStats;
@property(readonly, retain, nonatomic) NSArray *canManageMultipleHostsFailureReasons;
@property(readonly, nonatomic) BOOL canManageMultipleHosts;
@property(readonly, nonatomic) struct CnxCapabilities *adaptedCnxCapabilities;
- (id)initWithAdaptedCnxCapabilities:(struct CnxCapabilities *)arg1;

@end

