//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLAssistantPanelController.h"

@class NSPopUpButton, NSSlider, NSString, NSTextField, NSView, PLRemoteVMCreationAssistant;

@interface PLVMCreationAssistantChooseRemoteVMDKPanel : PLAssistantPanelController
{
    NSView *optionView;
    NSView *existingDiskView;
    NSView *customDiskView;
    NSSlider *diskSizeSlider;
    NSTextField *diskSizeTextField;
    NSPopUpButton *busTypeButton;
    BOOL mCheckingDiskInfo;
    BOOL mPreAllocated;
    BOOL mSplit;
    BOOL _canEditBusType;
    int mBusType;
    NSString *mExistingVMDKDisplayName;
    double mSizeGB;
    double mMinimumSizeGB;
    double mMaximumSizeGB;
    NSString *mPreferredDiskSize;
    NSString *mMinLabel;
    NSString *mMaxLabel;
}

+ (id)observationKeyPaths;
+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
@property(readonly, nonatomic) BOOL canEditBusType; // @synthesize canEditBusType=_canEditBusType;
@property(copy, nonatomic) NSString *maxLabel; // @synthesize maxLabel=mMaxLabel;
@property(copy, nonatomic) NSString *minLabel; // @synthesize minLabel=mMinLabel;
@property(copy, nonatomic) NSString *preferredDiskSize; // @synthesize preferredDiskSize=mPreferredDiskSize;
@property(nonatomic) BOOL split; // @synthesize split=mSplit;
@property(nonatomic) BOOL preAllocated; // @synthesize preAllocated=mPreAllocated;
@property(nonatomic) int busType; // @synthesize busType=mBusType;
@property(nonatomic) double maximumSizeGB; // @synthesize maximumSizeGB=mMaximumSizeGB;
@property(nonatomic) double minimumSizeGB; // @synthesize minimumSizeGB=mMinimumSizeGB;
@property(nonatomic) double sizeGB; // @synthesize sizeGB=mSizeGB;
@property(nonatomic) BOOL checkingDiskInfo; // @synthesize checkingDiskInfo=mCheckingDiskInfo;
@property(copy, nonatomic) NSString *existingVMDKDisplayName; // @synthesize existingVMDKDisplayName=mExistingVMDKDisplayName;
- (void)controlTextDidEndEditing:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)selectVirtualDisk:(id)arg1;
- (void)selectVirtualDiskWithPath:(id)arg1;
- (void)updateVirtualDisk:(id)arg1 name:(id)arg2;
@property(readonly, nonatomic) BOOL canEditPreAllocated;
@property(readonly, nonatomic) BOOL canEditSplit;
- (id)diskDescription;
- (id)hardDiskDisplaySize;
@property(readonly, nonatomic) unsigned long long sizeInBytes;
- (BOOL)makeCustomVMDK;
- (id)hardDiskProxy;
- (id)vmCreationHelper;
- (void)diskSizeSliderMoved:(id)arg1;
- (void)updateMinMaxSizes;
- (BOOL)enableNVMe;
- (BOOL)enableSATA;
- (BOOL)enableSCSI;
- (BOOL)enableIDE;
@property(nonatomic) long long busTypeIndex;
- (void)assistantWillUnload;
- (void)assistantWillStart;
- (void)awakeFromNib;
- (void)resetView;
- (void)configureView;
- (void)dealloc;
- (id)initWithAssistant:(id)arg1;

// Remaining properties
@property(readonly, nonatomic) PLRemoteVMCreationAssistant *assistant; // @dynamic assistant;

@end

