//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSImage, NSString, NSURL;

@interface PLImportFileEntry : NSObject
{
    NSURL *url;
    NSString *displayName;
    NSString *guestOSName;
    NSString *guestOSType;
    NSString *spaceNeeded;
    NSString *failureReason;
    NSImage *icon;
    unsigned long long requiredDiskSpaceMB;
    BOOL success;
    BOOL isImportable;
}

@property(nonatomic) BOOL isImportable; // @synthesize isImportable;
@property(nonatomic) BOOL success; // @synthesize success;
@property(nonatomic) unsigned long long requiredDiskSpaceMB; // @synthesize requiredDiskSpaceMB;
@property(retain, nonatomic) NSImage *icon; // @synthesize icon;
@property(retain, nonatomic) NSString *failureReason; // @synthesize failureReason;
@property(retain, nonatomic) NSString *spaceNeeded; // @synthesize spaceNeeded;
@property(retain, nonatomic) NSString *guestOSType; // @synthesize guestOSType;
@property(retain, nonatomic) NSString *guestOSName; // @synthesize guestOSName;
@property(retain, nonatomic) NSString *displayName; // @synthesize displayName;
@property(retain, nonatomic) NSURL *url; // @synthesize url;
- (void)dealloc;

@end

