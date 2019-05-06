//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUISnapshotUID, NSMutableArray, NSMutableDictionary, PLVMController;

@interface PLVMDiskSpaceDataSource : NSObject
{
    BOOL mIsCurrent;
    BOOL mIsGeneratingContent;
    BOOL mShowReclaimableLabel;
    BOOL mShouldUpdateAllDiskInfo;
    BOOL mNeedsInitialCalculation;
    PLVMController *mVMController;
    NSMutableArray *mDiskSpaceObservers;
    unsigned long long mHardDiskTotalSize;
    unsigned long long mReclaimableSize;
    unsigned long long mSnapshotsSize;
    NSMutableDictionary *mSnapshotSizes;
    unsigned long long mSnapshotsVMDKSize;
    NSMutableDictionary *mSnapshotVMDKSizes;
    unsigned long long mTotalSize;
    DUISnapshotUID *mCurrentSnapshotUID;
}

+ (id)diskSpaceDataSourceForVMWithID:(id)arg1;
+ (id)keyPathsAffectingDiskSpace;
+ (void)initialize;
@property(nonatomic) BOOL needsInitialCalculation; // @synthesize needsInitialCalculation=mNeedsInitialCalculation;
@property(retain, nonatomic) DUISnapshotUID *currentSnapshotUID; // @synthesize currentSnapshotUID=mCurrentSnapshotUID;
@property(nonatomic) BOOL shouldUpdateAllDiskInfo; // @synthesize shouldUpdateAllDiskInfo=mShouldUpdateAllDiskInfo;
@property(nonatomic) unsigned long long totalSize; // @synthesize totalSize=mTotalSize;
@property(retain, nonatomic) NSMutableDictionary *snapshotVMDKSizes; // @synthesize snapshotVMDKSizes=mSnapshotVMDKSizes;
@property(nonatomic) unsigned long long snapshotsVMDKSize; // @synthesize snapshotsVMDKSize=mSnapshotsVMDKSize;
@property(retain, nonatomic) NSMutableDictionary *snapshotSizes; // @synthesize snapshotSizes=mSnapshotSizes;
@property(nonatomic) unsigned long long snapshotsSize; // @synthesize snapshotsSize=mSnapshotsSize;
@property(nonatomic) BOOL showReclaimableLabel; // @synthesize showReclaimableLabel=mShowReclaimableLabel;
@property(nonatomic) unsigned long long reclaimableSize; // @synthesize reclaimableSize=mReclaimableSize;
@property(nonatomic) BOOL isGeneratingContent; // @synthesize isGeneratingContent=mIsGeneratingContent;
@property(nonatomic) BOOL isCurrent; // @synthesize isCurrent=mIsCurrent;
@property(nonatomic) unsigned long long hardDiskTotalSize; // @synthesize hardDiskTotalSize=mHardDiskTotalSize;
@property(retain, nonatomic) NSMutableArray *diskSpaceObservers; // @synthesize diskSpaceObservers=mDiskSpaceObservers;
@property(readonly, retain, nonatomic) PLVMController *vmController; // @synthesize vmController=mVMController;
- (void)onSnapshotTreeDidRefresh:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)updateShrinkInfo;
- (void)updateVMDKInfo;
- (unsigned long long)snapshotVMDKSizeForUID:(id)arg1;
- (unsigned long long)snapshotSizeForUID:(id)arg1;
- (void)updateTotalSnapshotSizes;
- (void)updateSnapshotsInSet:(id)arg1;
- (void)updateIndividualSnapshotInfo:(BOOL)arg1;
- (void)updateSnapshotInfo:(BOOL)arg1;
- (void)updateDiskSpaceInfo:(BOOL)arg1;
- (void)removeObserver:(id)arg1 forKeyPath:(id)arg2;
- (void)addObserver:(id)arg1 forKeyPath:(id)arg2 options:(unsigned long long)arg3 context:(void *)arg4;
- (void)saveSizes;
- (void)loadSizes;
- (void)dealloc;
- (id)initWithVMID:(id)arg1;

@end

