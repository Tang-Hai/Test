//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface DUIDiskInfo : NSObject
{
    struct DiskInfo mDiskInfo;
}

+ (id)diskInfoWithCUIDiskInfo:(const struct DiskInfo *)arg1;
@property(readonly, nonatomic) struct DiskInfo cuiDiskInfo; // @synthesize cuiDiskInfo=mDiskInfo;
@property(readonly, nonatomic) int hwVersion;
@property(readonly, nonatomic) long long capacityB;
@property(readonly, nonatomic) int busType;
@property(readonly, nonatomic) int diskType;
- (id)initWithCUIDiskInfo:(const struct DiskInfo *)arg1;

@end

