//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIOVFProductInfo, NSArray;

@interface DUIOVFProbeResult : NSObject
{
    BOOL mIsVApp;
    DUIOVFProductInfo *mProductInfo;
    NSArray *mEulas;
    NSArray *mCategories;
    NSArray *mDeploymentOptions;
    NSArray *mVms;
}

+ (id)ovfProbeResultWithCUIOVFProbeResult:(struct ProbeResult)arg1;
@property(retain, nonatomic) NSArray *vms; // @synthesize vms=mVms;
@property(retain, nonatomic) NSArray *deploymentOptions; // @synthesize deploymentOptions=mDeploymentOptions;
@property(retain, nonatomic) NSArray *categories; // @synthesize categories=mCategories;
@property(retain, nonatomic) NSArray *eulas; // @synthesize eulas=mEulas;
@property(nonatomic) BOOL isVApp; // @synthesize isVApp=mIsVApp;
@property(retain, nonatomic) DUIOVFProductInfo *productInfo; // @synthesize productInfo=mProductInfo;
- (void)dealloc;
- (BOOL)hasAdditionalSettings;
- (BOOL)hasDeploymentOptions;
- (BOOL)hasEULAs;
- (id)initWithCUIOVFProbeResult:(struct ProbeResult)arg1;

@end

