//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIDevice.h"

@interface DUIDeviceUSBController : DUIDevice
{
}

- (struct USBCtlr *)adaptedDeviceUSBController;
- (id)initWithAdaptedDevice:(struct Device *)arg1;
- (void)setSticky:(BOOL)arg1 forTransaction:(id)arg2;
- (BOOL)stickyForTransaction:(id)arg1;
- (BOOL)sticky;
- (void)setPluginAction:(int)arg1 forTransaction:(id)arg2;
- (int)pluginActionForTransaction:(id)arg1;
- (int)pluginAction;
- (void)setKeyUsb:(id)arg1 forTransaction:(id)arg2;
- (id)keyUsbForTransaction:(id)arg1;
- (id)keyUsb;
- (void)setEnableEHCI:(BOOL)arg1 forTransaction:(id)arg2;
- (BOOL)enableEHCIForTransaction:(id)arg1;
- (BOOL)enableEHCI;

@end

