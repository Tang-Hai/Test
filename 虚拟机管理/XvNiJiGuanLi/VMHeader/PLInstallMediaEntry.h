//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIDeviceCDROMProxy, DUILocalCDROMDevice, NSImage, NSString, NSURL;

@interface PLInstallMediaEntry : NSObject
{
    DUIDeviceCDROMProxy *cdromProxy;
    DUILocalCDROMDevice *device;
    CDStruct_14321004 guess;
    NSString *guestOSName;
    NSImage *icon;
    NSURL *volumeURL;
    BOOL hasValidGuess;
    BOOL isCheckingGuess;
    BOOL hasInstallMedia;
    NSString *displayName;
}

@property(nonatomic) BOOL hasInstallMedia; // @synthesize hasInstallMedia;
@property(nonatomic) BOOL isCheckingGuess; // @synthesize isCheckingGuess;
@property(nonatomic) BOOL hasValidGuess; // @synthesize hasValidGuess;
@property(nonatomic) CDStruct_14321004 guess; // @synthesize guess;
@property(retain, nonatomic) NSURL *volumeURL; // @synthesize volumeURL;
@property(retain, nonatomic) NSImage *icon; // @synthesize icon;
@property(copy, nonatomic) NSString *guestOSName; // @synthesize guestOSName;
@property(copy, nonatomic) NSString *displayName; // @synthesize displayName;
@property(retain, nonatomic) DUILocalCDROMDevice *device; // @synthesize device;
@property(retain, nonatomic) DUIDeviceCDROMProxy *cdromProxy; // @synthesize cdromProxy;
- (void)dealloc;

@end

