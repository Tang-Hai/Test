//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray;

@interface PLBootCampDiskMgr : NSObject
{
    NSMutableArray *mBootCampDisks;
    struct __DASession *mDaSession;
}

+ (id)sharedBootCampDiskMgr;
@property(nonatomic) struct __DASession *daSession; // @synthesize daSession=mDaSession;
@property(retain, nonatomic) NSMutableArray *bootCampDisks; // @synthesize bootCampDisks=mBootCampDisks;
- (void)updateDisk:(id)arg1 withVolumeURL:(id)arg2;
- (void)removeNotifications;
- (void)installNotifications;
- (id)allBootCampDisks;
- (void)dealloc;

@end

