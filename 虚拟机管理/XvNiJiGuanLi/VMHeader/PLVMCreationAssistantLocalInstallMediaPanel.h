//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLAssistantPanelController.h"

#import "DUISettingsCDROMOpenPanelDelegate.h"

@class NSArrayController, NSString, PLVMCreationAssistant, VMTableViewWithPlaceholder;

@interface PLVMCreationAssistantLocalInstallMediaPanel : PLAssistantPanelController <DUISettingsCDROMOpenPanelDelegate>
{
    NSArrayController *mediaArrayController;
    VMTableViewWithPlaceholder *mediaTableView;
    id mDiscDisappearedObserver;
    id mDiscAppearedObserver;
    id mDevicesChangedObserver;
}

@property(retain, nonatomic) id devicesChangedObserver; // @synthesize devicesChangedObserver=mDevicesChangedObserver;
@property(retain, nonatomic) id discAppearedObserver; // @synthesize discAppearedObserver=mDiscAppearedObserver;
@property(retain, nonatomic) id discDisappearedObserver; // @synthesize discDisappearedObserver=mDiscDisappearedObserver;
- (void)writePrefs;
- (void)loadFromPrefs;
- (void)addMediaPref:(id)arg1;
- (void)clearRecentItems:(id)arg1;
- (id)gosKeyFromInfo:(const CDStruct_14321004 *)arg1;
- (id)gosDescriptionFromInfo:(const CDStruct_14321004 *)arg1;
- (void)guessGuest:(id)arg1 type:(int)arg2 entry:(id)arg3;
- (void)guessGuest:(id)arg1 type:(int)arg2;
- (void)guessGuest:(id)arg1 type:(int)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (id)cdromAccessoryPanelLastDirectoryKey;
- (BOOL)cdromAccessoryPanelShowRecentItems;
- (BOOL)cdromAccessoryPanelHideToolsFolder;
- (void)browseForFileDidEnd:(id)arg1 returnCode:(int)arg2 deviceKey:(id)arg3;
- (void)setFileBased:(id)arg1 deviceKey:(id)arg2 installAppPath:(id)arg3;
- (void)setFileBased:(id)arg1 deviceKey:(id)arg2 remoteDiscPath:(id)arg3;
- (void)installDiscNotifications;
- (void)chooseCDROMBackend:(id)arg1;
- (BOOL)chooseURL:(id)arg1;
- (void)devicesChangedNotification:(id)arg1;
- (void)discDisappearedNotification:(id)arg1;
- (void)discAppearedNotification:(id)arg1;
- (void)setPhysicalDisc:(id)arg1 deviceKey:(id)arg2;
- (void)checkCDROMDevice:(id)arg1;
- (id)nonDeviceMediaEntries;
- (id)entryForFileBackendPath:(id)arg1;
- (id)iconForDevice:(id)arg1;
- (id)entryForDevice:(id)arg1;
- (id)selectedEntry;
- (void)showFileInFinder:(id)arg1;
- (id)tableView:(id)arg1 rowViewForRow:(long long)arg2;
- (void)tableViewSelectionDidChange:(id)arg1;
- (void)resetButtons;
- (void)syncInstallationMediaState;
- (void)configureView;
- (void)assistantWillUnload;
- (void)assistantWillStart;
- (void)awakeFromNib;
- (id)initWithAssistant:(id)arg1;

// Remaining properties
@property(readonly, nonatomic) PLVMCreationAssistant *assistant; // @dynamic assistant;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

