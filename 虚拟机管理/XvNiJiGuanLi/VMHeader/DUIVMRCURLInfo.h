//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSString, NSURL;

@interface DUIVMRCURLInfo : NSObject
{
    struct VMRCURLInfo mURLInfo;
}

+ (id)infoForURL:(id)arg1;
+ (BOOL)isVMRCURL:(id)arg1;
@property(readonly, nonatomic) const struct VMRCURLInfo *cuiVMRCURLInfo; // @synthesize cuiVMRCURLInfo=mURLInfo;
- (id).cxx_construct;
- (void).cxx_destruct;
- (id)initWithCUIVMRCURLInfo:(const struct VMRCURLInfo *)arg1;
@property(readonly, nonatomic) NSURL *url;
@property(readonly, nonatomic) NSString *path;
@property(readonly, nonatomic) NSString *webSocket;
@property(readonly, nonatomic) NSString *thumbprint;
@property(readonly, nonatomic) NSString *moid;
@property(readonly, nonatomic) NSString *hostID;
@property(readonly, nonatomic) NSString *ticket;
@property(readonly, nonatomic) int ticketType;
@property(readonly, nonatomic) NSString *username;

@end

