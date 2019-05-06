//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSViewController.h"

#import "NSOutlineViewDataSource.h"
#import "NSOutlineViewDelegate.h"
#import "NSTextFieldDelegate.h"

@class DUIDeviceCPU, DUIDeviceMemory, DUIDeviceMgr, DUIFeatures, DUIInventoryNode, DUIInventoryVMNode, DUIMKSChrome, NSArray, NSImage, NSLayoutConstraint, NSOutlineView, NSPopover, NSString, NSTextField;

@interface PLInventoryVMInfoViewController : NSViewController <NSOutlineViewDataSource, NSOutlineViewDelegate, NSTextFieldDelegate>
{
    DUIMKSChrome *mksView;
    NSTextField *notesField;
    DUIInventoryVMNode *node;
    NSOutlineView *networkConnectionsOutlineView;
    NSPopover *advancedNetworkInfoPopover;
    double defaultNetworkInfoViewWidth;
    NSLayoutConstraint *networkInfoViewWidth;
    double defaultSystemInfoViewHeight;
    NSLayoutConstraint *systemInfoViewHeight;
    double defaultDiskCleanupViewHeight;
    NSLayoutConstraint *diskCleanupViewHeight;
    NSTextField *nameField;
    NSLayoutConstraint *notesFixedWidth;
    NSLayoutConstraint *notesFlexibleWidth;
    BOOL mUpdateInfoString;
    BOOL mDidAwakeFromNib;
    NSString *mErrorString;
    NSArray *mNetworkConnections;
}

+ (id)observationKeyPaths;
+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
@property(nonatomic) BOOL didAwakeFromNib; // @synthesize didAwakeFromNib=mDidAwakeFromNib;
@property(copy, nonatomic) NSArray *networkConnections; // @synthesize networkConnections=mNetworkConnections;
@property(retain, nonatomic) NSString *errorString; // @synthesize errorString=mErrorString;
@property(nonatomic) BOOL updateInfoString; // @synthesize updateInfoString=mUpdateInfoString;
@property(readonly, retain, nonatomic) DUIMKSChrome *mksView; // @synthesize mksView;
@property(retain, nonatomic) DUIInventoryNode *node; // @synthesize node;
- (id)outlineView:(id)arg1 viewForTableColumn:(id)arg2 item:(id)arg3;
- (BOOL)outlineView:(id)arg1 isItemExpandable:(id)arg2;
- (id)outlineView:(id)arg1 child:(long long)arg2 ofItem:(id)arg3;
- (long long)outlineView:(id)arg1 numberOfChildrenOfItem:(id)arg2;
- (void)setSeparatorHidden:(BOOL)arg1 forTableCellView:(id)arg2;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)onCanShowGuestInfoChanged;
- (void)onShowNetworkInfoChanged;
- (void)onVMNetworkConnectionsChanged;
- (void)reloadNetworkConnectionsOutlineView;
- (void)reloadAdvancedNetworkInfoPopoverContentSize;
- (BOOL)canShowGuestInfo;
- (BOOL)showNetworkInfo;
- (id)vmNetworkConnections;
- (id)vmPrimaryMACAddress;
- (id)vmPrimaryIPAddress;
- (void)updateStaticImage;
- (void)loadStaticImageAsync;
@property(readonly, nonatomic) BOOL canEditNotes;
@property(readonly, nonatomic) BOOL canEditName;
- (id)infoIcon;
- (id)infoString;
- (BOOL)control:(id)arg1 textView:(id)arg2 doCommandBySelector:(SEL)arg3;
- (void)controlTextDidEndEditing:(id)arg1;
- (void)controlTextDidChange:(id)arg1;
- (void)controlTextDidBeginEditing:(id)arg1;
- (void)setNotes:(id)arg1;
@property(readonly, copy, nonatomic) NSString *notes;
- (BOOL)validateVmName:(id *)arg1 error:(id *)arg2;
- (void)setVmName:(id)arg1;
@property(readonly, copy, nonatomic) NSString *vmName;
- (long long)numberOfCores;
@property(readonly, retain, nonatomic) DUIDeviceCPU *deviceCPU;
- (long long)memorySizeMB;
@property(readonly, retain, nonatomic) DUIDeviceMemory *deviceMemory;
@property(readonly, retain, nonatomic) DUIDeviceMgr *deviceMgr;
- (id)vm;
@property(readonly, nonatomic) DUIInventoryVMNode *vmNode;
@property(readonly, retain, nonatomic) DUIFeatures *features;
- (void)onShowAdvancedNetworkInfo:(id)arg1;
- (void)onShowVMProcessorsAndRAM:(id)arg1;
- (void)onShowVMSettings:(id)arg1;
- (void)onPowerAction:(id)arg1;
@property(readonly, nonatomic) BOOL canPerformSettingsAction;
@property(readonly, nonatomic) BOOL canPerformPowerAction;
@property(readonly, copy, nonatomic) NSString *powerButtonTooltip;
@property(readonly, retain, nonatomic) NSImage *powerButtonImage;
- (id)powerAction;
- (id)actionController;
- (void)closeView;
- (void)dealloc;
- (void)viewWillAppear;
- (void)awakeFromNib;
- (id)initWithNibName:(id)arg1 inventoryNode:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

