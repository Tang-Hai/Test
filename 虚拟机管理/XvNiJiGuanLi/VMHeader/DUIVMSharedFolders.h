//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "DUITrackable.h"
#import "DUITransacting.h"
#import "NSOpenSavePanelDelegate.h"

@class DUIVM, NSMutableArray, NSMutableDictionary, NSString;

@interface DUIVMSharedFolders : NSObject <DUITransacting, DUITrackable, NSOpenSavePanelDelegate>
{
    BOOL dirty;
    id <DUITrackableProxy> trackableProxyImpl;
    BOOL mSharedFoldersEnabled;
    BOOL mSharedFoldersEnableAtPowerOn;
    BOOL mSharedFoldersDiscoverable;
    DUIVM *mVM;
    NSMutableDictionary *mFolders;
    NSMutableArray *mSortedKeys;
}

+ (id)observationKeyPaths;
+ (unsigned long long)duiKeyForUserFolderMappingByUsabilityTag:(id)arg1;
@property(nonatomic) BOOL sharedFoldersDiscoverable; // @synthesize sharedFoldersDiscoverable=mSharedFoldersDiscoverable;
@property(nonatomic) BOOL sharedFoldersEnableAtPowerOn; // @synthesize sharedFoldersEnableAtPowerOn=mSharedFoldersEnableAtPowerOn;
@property(nonatomic) BOOL sharedFoldersEnabled; // @synthesize sharedFoldersEnabled=mSharedFoldersEnabled;
@property(retain, nonatomic) NSMutableArray *sortedKeys; // @synthesize sortedKeys=mSortedKeys;
@property(retain, nonatomic) NSMutableDictionary *folders; // @synthesize folders=mFolders;
@property(retain, nonatomic) DUIVM *vm; // @synthesize vm=mVM;
- (id)uniqueNameForFolder:(id)arg1;
- (void)saveEditor:(struct VMEditor *)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (id)quietlyAddSharedFolder:(id)arg1;
- (id)nameForUserFolderMappingByKey:(unsigned long long)arg1;
- (void)manageSharedFolderProxy:(id)arg1;
- (void)setDirty:(BOOL)arg1;
- (void)reloadCachedData;
- (void)dealloc;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)customSharedFolderForPath:(id)arg1;
- (void)invalidateTrackableProxy;
- (id)trackableProxy;
- (void)setUserFolderMirroringForTag:(id)arg1 enable:(BOOL)arg2 abortHandler:(CDUnknownBlockType)arg3 doneHandler:(CDUnknownBlockType)arg4;
- (void)setUserFolderMirroring:(unsigned long long)arg1 enable:(BOOL)arg2 abortHandler:(CDUnknownBlockType)arg3 doneHandler:(CDUnknownBlockType)arg4;
- (BOOL)isExistingUserFolderMapping:(unsigned long long)arg1;
- (BOOL)isExistingUserFolderMappingForTag:(id)arg1;
- (void)setUserFolderSharingForTag:(id)arg1 enable:(BOOL)arg2 abortHandler:(CDUnknownBlockType)arg3 doneHandler:(CDUnknownBlockType)arg4;
- (void)setUserFolderSharing:(unsigned long long)arg1 enable:(BOOL)arg2 abortHandler:(CDUnknownBlockType)arg3 doneHandler:(CDUnknownBlockType)arg4;
- (void)sharedFolderKeyWillChange:(id)arg1;
- (void)reloadCache;
- (void)reloadCacheNotification:(id)arg1;
- (void)finishInitialization;
- (id)initWithVM:(id)arg1;
- (id)objectEnumerator;
- (unsigned long long)indexOfObject:(id)arg1;
- (BOOL)containsObject:(id)arg1;
- (id)objectAtIndex:(unsigned long long)arg1;
- (id)keyEnumerator;
- (id)allValues;
- (id)allKeys;
- (id)objectForKey:(id)arg1;
- (id)valueForKey:(id)arg1;
- (void)setDisableAutocommit:(BOOL)arg1;
- (BOOL)validate:(id *)arg1;
- (void)discard;
- (BOOL)commitWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (BOOL)isNew;
@property(readonly, nonatomic, getter=isDirty) BOOL dirty;
@property(nonatomic) BOOL alwaysConnected;
- (id)automaticSharedFolderAtIndex:(unsigned long long)arg1;
- (id)automaticSharedFolders;
- (id)customSharedFolderAtIndex:(unsigned long long)arg1;
- (id)customSharedFolders;
- (id)sharedFolderAtIndex:(unsigned long long)arg1;
- (id)sharedFolderForKey:(id)arg1;
- (id)sharedFolderContainingPath:(id)arg1;
- (id)urlFromPath:(id)arg1 mappedToSharedFolder:(id)arg2;
- (unsigned long long)automaticCount;
- (unsigned long long)customCount;
- (id)pathFromShareURL:(id)arg1;
- (unsigned long long)count;
- (id)nextNameWithPrefix:(id)arg1;
- (void)removeSharedFolder:(id)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (void)promptUserToAddSharedFolderWithDlgMgr:(id)arg1 addHandler:(CDUnknownBlockType)arg2;
- (void)addSharedFolders:(id)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (id)addSharedFolder:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

