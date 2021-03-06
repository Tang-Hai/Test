//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUISettingsItemBaseRemovableDevice.h"

#import "DUISettingsCDROMOpenPanelDelegate.h"
#import "DUISettingsCDROMPopUpDelegate.h"

@class DUISettingsCDROMPopUpController, NSString;

@interface DUISettingsItemCDROM : DUISettingsItemBaseRemovableDevice <DUISettingsCDROMOpenPanelDelegate, DUISettingsCDROMPopUpDelegate>
{
    DUISettingsCDROMPopUpController *popUpController;
}

+ (id)keyPathsAffectingSettingsValueForKey:(id)arg1;
@property(readonly, nonatomic) DUISettingsCDROMPopUpController *popUpController; // @synthesize popUpController;
- (id)removeDeviceMessageText;
- (id)warnings;
- (void)chooseRemoteFileBackend:(id)arg1;
- (void)chooseCDROMBackend:(id)arg1;
- (id)defaultOpenPanelPath;
- (void)browseForFileDidEnd:(id)arg1 returnCode:(int)arg2 deviceKey:(id)arg3;
- (void)chooseRemoteCDROMDevice:(id)arg1;
- (void)chooseLocalCDROMDevice:(id)arg1;
- (void)chooseAutoDetect:(id)arg1;
- (void)setRemotePhysicalDisc:(id)arg1;
- (void)setPhysicalDisc:(id)arg1 deviceKey:(id)arg2;
- (void)setPhysicalDisc:(id)arg1;
- (void)setRemoteFileBased:(id)arg1;
- (void)setFileBased:(id)arg1 deviceKey:(id)arg2 remoteDiscPath:(id)arg3;
- (void)setFileBased:(id)arg1;
- (void)saveCDROMEditor:(id)arg1;
- (id)fileBackendNormalizedPath;
- (id)physicalBackendLocalDevice;
- (BOOL)hideSeparator;
@property(readonly, nonatomic) BOOL hideAutoDetect;
@property(readonly, nonatomic) BOOL enableAutoDetect;
- (BOOL)enableBusType:(int)arg1;
- (BOOL)enableSATA;
- (BOOL)enableSCSI;
- (BOOL)enableIDE;
@property(nonatomic) long long busTypeIndex;
- (BOOL)shouldInvalidateOnKeyChange;
- (BOOL)canEditProperty:(id)arg1;
@property(readonly, nonatomic) BOOL enableBackendSelection;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)closeView;
- (void)openView;
- (void)updateDevices:(id)arg1;
- (void)onDevicesChanged:(id)arg1;
- (id)deviceCDROM;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

