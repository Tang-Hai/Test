//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIDeviceMixedBackend.h"

#import "DUIDeviceClientBackend.h"

@interface DUIDeviceCDROM : DUIDeviceMixedBackend <DUIDeviceClientBackend>
{
}

+ (int)bootOrderType;
- (id)description;
- (id)physicalBackendForDeviceHost:(id)arg1 transaction:(id)arg2;
- (id)physicalBackendForDeviceHost:(id)arg1;
- (BOOL)usesPhysicalBackendForDeviceHost:(id)arg1 transaction:(id)arg2;
- (BOOL)usesPhysicalBackendForDeviceHost:(id)arg1;
- (void)configureForDeviceHost:(id)arg1 backingType:(int)arg2 path:(id)arg3 transaction:(id)arg4;
- (void)setUsesClientBackendForTransaction:(id)arg1;
- (BOOL)usesClientBackendForTransaction:(id)arg1;
- (BOOL)usesClientBackend;
- (struct ClientBackend *)adaptedDeviceClientBackend;
- (struct CDROM *)adaptedDeviceCDROM;
- (id)initWithAdaptedDevice:(struct Device *)arg1;
- (void)setFilePath:(id)arg1 forTransaction:(id)arg2;
- (id)filePathForTransaction:(id)arg1;
- (id)filePath;
- (void)setDevicePath:(id)arg1 forTransaction:(id)arg2;
- (id)devicePathForTransaction:(id)arg1;
- (id)devicePath;
- (void)setClientPathBacking:(int)arg1 forTransaction:(id)arg2;
- (int)clientPathBackingForTransaction:(id)arg1;
- (int)clientPathBacking;

@end

