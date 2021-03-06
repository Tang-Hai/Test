//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class DUIMKSScreen, NSArray, NSDictionary;

@interface DUIMKSScreenMgr : DUIAdaptorBase
{
}

+ (id)screenMgrForAdaptedScreenMgr:(struct MKSScreenMgr *)arg1;
@property(readonly, nonatomic) struct MKSScreenMgr *adaptedMKSScreenMgr;
- (id)initWithAdaptedScreenMgr:(struct MKSScreenMgr *)arg1;
- (void)setExpectedMainScreenRect:(struct CGRect)arg1;
@property(readonly, copy, nonatomic) NSArray *topologyForRootedScreens;
@property(readonly, copy, nonatomic) NSArray *sortedRootedScreens;
@property(readonly, copy, nonatomic) NSDictionary *rootedScreens;
@property(readonly, copy, nonatomic) NSDictionary *screens;
- (id)screenWithID:(id)arg1;
@property(readonly, retain, nonatomic) DUIMKSScreen *virtualBoundingScreen;
@property(readonly, nonatomic) struct CGRect virtualBoundingBox;

@end

