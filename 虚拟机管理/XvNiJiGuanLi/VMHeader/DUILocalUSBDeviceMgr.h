//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@interface DUILocalUSBDeviceMgr : DUIAdaptorBase
{
    struct USBDeviceMgr *mAdaptedUSBDeviceMgrRefPtr;
}

+ (id)usbDeviceMgrFromLocalHost:(struct LocalHost *)arg1;
+ (id)localUSBDeviceMgrForAdaptedLocalUSBDeviceMgr:(struct USBDeviceMgr *)arg1;
- (void)postRuleChangedNotificationName:(id)arg1 withRuleList:(vector_17e0b622)arg2;
- (void)postDeviceChangedNotificationName:(id)arg1 withDeviceList:(vector_2f466f73)arg2;
- (id)usbDeviceBySerial:(id)arg1;
- (id)usbDeviceByKey:(id)arg1;
- (BOOL)updateUSBDeviceRule:(id)arg1;
- (BOOL)removeAllUSBDeviceRules;
- (BOOL)addUSBDeviceRuleForDeviceId:(long long)arg1 targetType:(int)arg2 vm:(id)arg3;
- (BOOL)addUSBDeviceRuleForDeviceId:(long long)arg1 targetId:(id)arg2 displayName:(id)arg3;
- (id)usbDeviceRules;
- (id)usbDevicesExcludingDeviceFamilies:(unsigned int)arg1;
- (struct USBDeviceMgr *)adaptedLocalUSBDeviceMgr;
- (id)initWithAdaptedUSBDeviceMgr:(struct USBDeviceMgr *)arg1;

@end

