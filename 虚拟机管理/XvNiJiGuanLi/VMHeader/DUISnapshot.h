//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class DUISnapshotUID, NSArray, NSDate, NSString;

@interface DUISnapshot : DUIAdaptorBase
{
}

+ (id)snapshotForAdaptedSnapshot:(const struct Snapshot *)arg1;
@property(readonly, nonatomic) const struct Snapshot *adaptedSnapshot;
- (id)initWithAdaptedSnapshot:(const struct Snapshot *)arg1;
@property(readonly, retain, nonatomic) NSArray *clones;
@property(readonly, nonatomic) BOOL hasClones;
@property(readonly, retain, nonatomic) NSArray *filePaths;
@property(readonly, retain, nonatomic) NSArray *tiers;
@property(readonly, retain, nonatomic) NSArray *descendants;
@property(readonly, retain, nonatomic) NSArray *visibleChildren;
- (id)uidForChildAtIndex:(int)arg1;
@property(readonly, nonatomic) int numberOfChildren;
@property(readonly, retain, nonatomic) NSArray *children;
@property(readonly, retain, nonatomic) DUISnapshot *visibleParent;
@property(readonly, retain, nonatomic) DUISnapshot *parent;
@property(readonly, nonatomic) unsigned int clientFlags;
@property(readonly, nonatomic) int type;
@property(readonly, nonatomic) int powerState;
@property(readonly, retain, nonatomic) NSDate *timestamp;
@property(readonly, copy, nonatomic) NSString *desc;
@property(readonly, copy, nonatomic) NSString *displayName;
@property(readonly, retain, nonatomic) DUISnapshotUID *uid;
@property(readonly, nonatomic) BOOL isAutosave;
@property(readonly, nonatomic) BOOL isReplay;
@property(readonly, nonatomic) BOOL isVisible;
@property(readonly, nonatomic) BOOL isYah;
@property(readonly, nonatomic) BOOL isRoot;
@property(readonly, nonatomic) BOOL isValid;

@end

