//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@interface DUIDeviceMgr : DUIAdaptorBase
{
    RefPtr_3bbf08f0 mAdaptedDeviceMgrRefPtr;
}

+ (id)deviceMgrForAdaptedDeviceMgr:(RefPtr_3bbf08f0)arg1;
+ (id)deviceForAdaptedDevice:(struct Device *)arg1;
- (id).cxx_construct;
- (void).cxx_destruct;
- (BOOL)hasVTPM;
- (id)listVTPM;
- (id)listXHCICtlr;
- (id)listVUsbCamera;
- (id)listUSBCtlr;
- (id)listSerial;
- (id)listNVMeCtlr;
- (id)listSCSICtlr;
- (id)listSATACtlr;
- (id)listParallel;
- (id)listNIC;
- (id)listIDECtlr;
- (id)listFloppy;
- (id)listAudio;
- (id)listForCUIType:(int)arg1;
- (id)svga;
- (id)memoryForCUITransaction:(struct ConfigTransaction *)arg1;
- (id)memoryForTransaction:(id)arg1;
- (id)memory;
- (id)cpuForCUITransaction:(struct ConfigTransaction *)arg1;
- (id)cpuForTransaction:(id)arg1;
- (id)cpu;
- (id)controlledDevicesWithFilter:(int)arg1 forCUITransaction:(struct ConfigTransaction *)arg2;
- (id)controlledDevicesWithFilter:(int)arg1 forTransaction:(id)arg2;
- (id)controlledDevicesWithFilter:(int)arg1;
- (id)deviceForKey:(id)arg1 forCUITransaction:(struct ConfigTransaction *)arg2;
- (id)deviceForKey:(id)arg1 forTransaction:(id)arg2;
- (id)deviceForKey:(id)arg1;
- (id)deviceSummaryForTransaction:(id)arg1;
- (id)dlgMgr;
- (id)vm;
- (id)host;
- (unsigned int)hiddenUSBDeviceFamilies;
- (void)invalidateAdaptation;
- (struct VMDeviceMgr *)adaptedDeviceMgr;
- (id)initWithAdaptedDeviceMgr:(RefPtr_3bbf08f0)arg1;
- (void)setHardwareVersion:(int)arg1 forTransaction:(id)arg2;
- (int)hardwareVersionForTransaction:(id)arg1;
- (int)hardwareVersion;
- (void)setVmxFilename:(id)arg1 forTransaction:(id)arg2;
- (id)vmxFilenameForTransaction:(id)arg1;
- (id)vmxFilename;
- (void)setGuestOSInfo:(id)arg1 forTransaction:(id)arg2;
- (id)guestOSInfoForTransaction:(id)arg1;
- (id)guestOSInfo;

@end

