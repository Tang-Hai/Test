//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSViewController.h"

@class NSImageView, NSString, PLSettingsItemGeneral, PLVMDiskSpaceDataSource;

@interface PLVMDiskSpace : NSViewController
{
    PLSettingsItemGeneral *viewController;
    NSImageView *hardDiskDot;
    NSImageView *snapshotsDot;
    NSImageView *reclaimableDot;
    NSString *mHardDiskDescription;
    NSString *mSnapshotsDescription;
    NSString *mReclaimableDescription;
}

+ (id)keyPathsForDiskSpace;
+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
@property(retain, nonatomic) NSString *reclaimableDescription; // @synthesize reclaimableDescription=mReclaimableDescription;
@property(retain, nonatomic) NSString *snapshotsDescription; // @synthesize snapshotsDescription=mSnapshotsDescription;
@property(retain, nonatomic) NSString *hardDiskDescription; // @synthesize hardDiskDescription=mHardDiskDescription;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)updateReclaimableSize:(unsigned long long)arg1;
- (void)updateSnapshotsSize:(unsigned long long)arg1;
- (void)updateHardDiskSize:(unsigned long long)arg1;
- (void)setReclaimableSize:(unsigned long long)arg1;
- (void)setHardDiskTotalSize:(unsigned long long)arg1;
- (void)setSnapshotsSize:(unsigned long long)arg1;
- (void)setSegment:(long long)arg1 forImageView:(id)arg2;
- (void)dealloc;
- (void)awakeFromNib;
@property(readonly, retain, nonatomic) PLVMDiskSpaceDataSource *dataSource;

@end

