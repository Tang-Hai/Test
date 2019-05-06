//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSString;

@interface VMPathResolver : NSObject
{
    NSString *path;
    NSString *testPath;
    NSMutableArray *displayPathComponents;
}

- (id)description;
- (long long)compareByLastPathComponent:(id)arg1;
- (void)deleteLastPathComponent;
- (void)setFilenameToLastPathComponent;
- (void)appendLastPathComponent;
- (id)lastPathComponent;
- (void)appendPathComponent:(id)arg1;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (void)setTestPath:(id)arg1;
- (id)path;
- (id)displayPathComponents;
- (id)displayPathString;
- (void)dealloc;
- (id)initWithPath:(id)arg1;

@end

