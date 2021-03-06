//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUISettingsItemBase.h"

@class DUIDevice, NSObject<DUIDeviceList>, NSString;

@interface DUISettingsItemBaseDevice : DUISettingsItemBase
{
    DUIDevice *device;
    DUIDevice *unblockedDevice;
    int mPendingIndex;
    NSObject<DUIDeviceList> *mPendingDeviceList;
    DUIDevice *mPendingDevice;
    id mDeviceAddedObserver;
    id mDevicesChangedObserver;
    NSString *_backendName;
}

+ (id)keyPathsAffectingSettingsValueForKey:(id)arg1;
@property(readonly, copy, nonatomic) NSString *backendName; // @synthesize backendName=_backendName;
@property(retain, nonatomic) id devicesChangedObserver; // @synthesize devicesChangedObserver=mDevicesChangedObserver;
@property(retain, nonatomic) id deviceAddedObserver; // @synthesize deviceAddedObserver=mDeviceAddedObserver;
@property(nonatomic) int pendingIndex; // @synthesize pendingIndex=mPendingIndex;
@property(retain, nonatomic) DUIDevice *pendingDevice; // @synthesize pendingDevice=mPendingDevice;
@property(retain, nonatomic) NSObject<DUIDeviceList> *pendingDeviceList; // @synthesize pendingDeviceList=mPendingDeviceList;
@property(retain, nonatomic) DUIDevice *device; // @synthesize device;
- (void)removeDeviceForTransaction:(id)arg1;
- (void)removeDevice:(id)arg1;
- (id)removeDeviceInformativeText;
- (id)removeDeviceMessageText;
- (void)onDevicesChanged:(id)arg1;
- (void)onDeviceListDeviceAdded:(id)arg1;
- (void)observeChangesToControllerInTransaction:(id)arg1;
- (void)doRemoveDevice;
@property(readonly, nonatomic) BOOL canRemoveDevice;
- (BOOL)hideRemoveDeviceButton;
- (id)name;
- (id)key;
- (BOOL)shouldInvalidateOnKeyChange;
- (void)invalidateItem;
- (void)onDeviceDidInvalidate:(id)arg1;
- (void)closeView;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)dealloc;
- (id)initWithController:(id)arg1 device:(id)arg2 nibName:(id)arg3;

@end

