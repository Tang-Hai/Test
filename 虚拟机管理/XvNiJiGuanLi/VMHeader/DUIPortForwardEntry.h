//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSNumber, NSString;

@interface DUIPortForwardEntry : NSObject
{
    BOOL mTcp;
    NSString *mIp;
    NSString *mDesc;
    NSNumber *_hostPort;
    NSNumber *_vmPort;
}

@property(retain, nonatomic) NSNumber *vmPort; // @synthesize vmPort=_vmPort;
@property(retain, nonatomic) NSNumber *hostPort; // @synthesize hostPort=_hostPort;
@property(copy, nonatomic) NSString *desc; // @synthesize desc=mDesc;
@property(copy, nonatomic) NSString *ip; // @synthesize ip=mIp;
@property(nonatomic) BOOL tcp; // @synthesize tcp=mTcp;
- (id)ip_Port;
- (void)dealloc;
- (void)clear;
- (BOOL)isEqual:(id)arg1;
- (id)init;

@end

