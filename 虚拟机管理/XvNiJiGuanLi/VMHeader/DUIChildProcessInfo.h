//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableData, NSTask;

@interface DUIChildProcessInfo : NSObject
{
    NSMutableData *mErrData;
    NSMutableData *mOutData;
    NSTask *mTask;
}

@property(retain, nonatomic) NSTask *task; // @synthesize task=mTask;
@property(retain, nonatomic) NSMutableData *outData; // @synthesize outData=mOutData;
@property(retain, nonatomic) NSMutableData *errData; // @synthesize errData=mErrData;
- (void)dealloc;

@end

