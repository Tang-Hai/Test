//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIHost.h"

@class DUILocalCDROMDeviceMgr, NSTimer;

@interface DUILocalHost : DUIHost
{
    DUILocalCDROMDeviceMgr *localCDROMDeviceMgr;
    NSTimer *repopulateDevicesTimer;
    struct trackable *repopulateDevicesTrackable;
}

+ (id)localHost;
@property(readonly, nonatomic) struct trackable *repopulateDevicesTrackable; // @synthesize repopulateDevicesTrackable;
@property(retain, nonatomic) NSTimer *repopulateDevicesTimer; // @synthesize repopulateDevicesTimer;
@property(readonly, retain, nonatomic) DUILocalCDROMDeviceMgr *localCDROMDeviceMgr; // @synthesize localCDROMDeviceMgr;
- (int)dx10SupportLevel;
- (BOOL)supportsGPUAutoSwitching;
- (void)onRepopulateDevicesSucceeded:(BOOL)arg1;
- (BOOL)isRepopulatingDevices;
- (void)onRepopulateDevicesTimerFired:(id)arg1;
- (void)repopulateDevices;
- (void)onDefaultSoundDeviceChanged:(id)arg1;
- (void)findCDROMHostPathForDevicePath:(id)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (vector_a7077208)cuiCDROMDevices;
- (BOOL)isRemoteDiscURL:(id)arg1;
- (id)remoteDiscs;
- (id)guestOSInfoForKey:(id)arg1;
- (id)guestOSTable;
- (id)localCDROMDeviceFromURL:(id)arg1;
- (id)localCDROMDevices;
- (id)localUSBDeviceMgr;
@property(readonly, nonatomic) struct LocalHost *adaptedLocalHost;
- (void)dealloc;
- (id)initWithAdaptedLocalHost:(struct LocalHost *)arg1;

@end

