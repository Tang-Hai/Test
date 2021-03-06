//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIVMID, PLVMController;

@interface PLVMUIConfig : NSObject
{
    PLVMController *mVMController;
    DUIVMID *mVMID;
}

+ (id)vmUIConfigForVMWithID:(id)arg1;
+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
+ (void)initialize;
@property(retain, nonatomic) DUIVMID *vmID; // @synthesize vmID=mVMID;
@property(retain, nonatomic) PLVMController *vmController; // @synthesize vmController=mVMController;
@property(nonatomic) long long scaledHighResolution;
@property(nonatomic) long long minibarTopologyIndex;
@property(nonatomic) int minibarShowPref;
@property(nonatomic) int minibarFrameEdge;
@property(nonatomic) BOOL shouldHideFullScreenMenuBar;
@property(nonatomic) int viewModeAtPowerOn;
@property(nonatomic) BOOL shouldFullscreenOnAllHostDisplays;
- (void)dealloc;
- (id)initWithVMID:(id)arg1;

@end

