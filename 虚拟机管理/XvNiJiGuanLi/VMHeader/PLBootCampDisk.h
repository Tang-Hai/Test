//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, NSURL;

@interface PLBootCampDisk : NSObject
{
    NSString *diskName;
    NSString *diskVolumeName;
    BOOL isIgnored;
    BOOL hasBootCampPartition;
    BOOL hasRecoveryPartition;
    BOOL bootCampCheckIsPending;
    BOOL bootCampCheckInProgress;
    BOOL recoveryPartitionCheckIsPending;
    BOOL recoveryPartitionCheckInProgress;
    BOOL userInitiated;
    unsigned long long recoveryPartitionByteSize;
    unsigned long long recoveryPartitionByteOffset;
    NSString *recoveryPartitionGosKey;
    NSURL *mDiskVolumeFileURL;
}

+ (id)diskNameFromDiskID:(id)arg1;
+ (id)diskIDFromDiskName:(id)arg1;
+ (id)diskPathFromDiskName:(id)arg1;
+ (id)allBootCampDisks;
+ (id)diskNameFromURLKey:(id)arg1;
+ (id)urlKeyFromDiskName:(id)arg1;
+ (id)bootCampPartitionPath:(id)arg1;
+ (id)windowsPartitionPath:(id)arg1;
+ (id)diskVolumePathFromDiskDev:(id)arg1;
+ (BOOL)isRecoveryPartitionCheckPending;
+ (BOOL)isBootCampCheckPending;
+ (BOOL)isBootCampAvailableNoPending;
+ (id)bootCampDiskForDiskID:(id)arg1;
+ (id)bootCampDiskForDiskName:(id)arg1;
+ (void)checkDisksForRecoveryPartition;
+ (void)checkDisksForBootCamp;
+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
@property(retain, nonatomic) NSURL *diskVolumeFileURL; // @synthesize diskVolumeFileURL=mDiskVolumeFileURL;
@property(nonatomic) BOOL recoveryPartitionCheckIsPending; // @synthesize recoveryPartitionCheckIsPending;
@property(nonatomic) BOOL bootCampCheckIsPending; // @synthesize bootCampCheckIsPending;
@property(retain, nonatomic) NSString *recoveryPartitionGosKey; // @synthesize recoveryPartitionGosKey;
@property(nonatomic) unsigned long long recoveryPartitionByteOffset; // @synthesize recoveryPartitionByteOffset;
@property(nonatomic) unsigned long long recoveryPartitionByteSize; // @synthesize recoveryPartitionByteSize;
@property(nonatomic) BOOL hasRecoveryPartition; // @synthesize hasRecoveryPartition;
@property(nonatomic) BOOL hasBootCampPartition; // @synthesize hasBootCampPartition;
@property(retain, nonatomic) NSString *diskVolumeName; // @synthesize diskVolumeName;
- (id)description;
- (void)onCopyRecoveryPartitionCompleted:(int)arg1 onAbort:(CDUnknownBlockType)arg2 onDone:(CDUnknownBlockType)arg3;
- (void)copyRecoveryPartitionToDisk:(id)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (id)searchRecoveryDiskList:(id)arg1 forDiskName:(id)arg2 startByte:(unsigned long long)arg3 size:(unsigned long long)arg4;
- (void)processRecoveryPartitionInfoFromText:(char *)arg1;
- (void)onCheckForRecoveryPartitionCompleted:(int)arg1 withOutputFile:(char *)arg2;
- (void)onCheckForBootCampCompleted:(int)arg1;
- (void)onCheckDoneWithNotificationName:(id)arg1;
- (void)checkForRecoveryPartition;
- (void)checkForBootCamp;
- (void)dealloc;
- (id)initWithBSDName:(id)arg1;
- (id)diskID;
- (id)recoveryDisplayName;
- (id)displayName;
- (void)updateDiskVolumeName:(id)arg1;
- (id)volumeFileURL;
- (id)diskPath;
- (id)diskName;

@end

