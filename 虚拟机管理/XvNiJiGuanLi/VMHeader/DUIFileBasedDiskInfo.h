//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIDiskInfo.h"

@class NSArray;

@interface DUIFileBasedDiskInfo : DUIDiskInfo
{
    struct FileBasedDiskInfo mFileBasedDiskInfo;
}

@property(readonly, nonatomic) struct FileBasedDiskInfo cuiFileBasedDiskInfo; // @synthesize cuiFileBasedDiskInfo=mFileBasedDiskInfo;
- (id).cxx_construct;
- (void).cxx_destruct;
@property(readonly, nonatomic) NSArray *filesInChain;
@property(readonly, nonatomic) BOOL isBottomEmpty;
@property(readonly, nonatomic) BOOL isMono;
@property(readonly, nonatomic) BOOL isFlat;
- (id)initWithCUIFileBasedDiskInfo:(const struct FileBasedDiskInfo *)arg1;

@end

