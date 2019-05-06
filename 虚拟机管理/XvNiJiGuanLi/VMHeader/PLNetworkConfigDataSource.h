//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSControlTextEditingDelegate.h"
#import "NSTableViewDataSource.h"
#import "NSTableViewDelegate.h"

@class NSMutableArray, NSObject<PLNetworkConfigDelegate>, NSString, NSTableView, NSTextFieldCell, PLNetcfgMgr, PLNetworkTableItem, VMNetworkInterfaceController;

@interface PLNetworkConfigDataSource : NSObject <NSTableViewDelegate, NSTableViewDataSource, NSControlTextEditingDelegate>
{
    NSTableView *interfacesTable;
    NSObject<PLNetworkConfigDelegate> *configDelegate;
    NSTextFieldCell *titleCell;
    BOOL mSuspendReload;
    BOOL mIsEditNicListAllowed;
    BOOL _isCommitInProgress;
    BOOL _isDataSourceEditing;
    VMNetworkInterfaceController *mInterfaceController;
    NSMutableArray *mTableContents;
    PLNetworkTableItem *mSelectedItem;
    PLNetworkTableItem *mActiveItem;
    PLNetcfgMgr *mNetcfgMgr;
    id mLastActiveItem;
}

@property(nonatomic) BOOL isDataSourceEditing; // @synthesize isDataSourceEditing=_isDataSourceEditing;
@property(nonatomic) BOOL isCommitInProgress; // @synthesize isCommitInProgress=_isCommitInProgress;
@property(retain, nonatomic) id lastActiveItem; // @synthesize lastActiveItem=mLastActiveItem;
@property(nonatomic) BOOL isEditNicListAllowed; // @synthesize isEditNicListAllowed=mIsEditNicListAllowed;
@property(nonatomic) BOOL suspendReload; // @synthesize suspendReload=mSuspendReload;
@property(retain, nonatomic) PLNetcfgMgr *netcfgMgr; // @synthesize netcfgMgr=mNetcfgMgr;
@property(retain, nonatomic) PLNetworkTableItem *activeItem; // @synthesize activeItem=mActiveItem;
@property(retain, nonatomic) PLNetworkTableItem *selectedItem; // @synthesize selectedItem=mSelectedItem;
@property(retain, nonatomic) NSMutableArray *tableContents; // @synthesize tableContents=mTableContents;
@property(retain, nonatomic) VMNetworkInterfaceController *interfaceController; // @synthesize interfaceController=mInterfaceController;
- (BOOL)isOccupiedPort:(int)arg1;
- (BOOL)isHostPortOccupied:(long long)arg1;
- (long long)numberOfRowsInTableView:(id)arg1;
- (BOOL)tableView:(id)arg1 shouldEditTableColumn:(id)arg2 row:(long long)arg3;
- (void)tableViewSelectionDidChange:(id)arg1;
- (BOOL)control:(id)arg1 isValidObject:(id)arg2;
- (void)tableView:(id)arg1 setObjectValue:(id)arg2 forTableColumn:(id)arg3 row:(long long)arg4;
- (id)tableView:(id)arg1 objectValueForTableColumn:(id)arg2 row:(long long)arg3;
- (id)tableView:(id)arg1 toolTipForCell:(id)arg2 rect:(struct CGRect *)arg3 tableColumn:(id)arg4 row:(long long)arg5 mouseLocation:(struct CGPoint)arg6;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forTableColumn:(id)arg3 row:(long long)arg4;
- (id)tableView:(id)arg1 dataCellForTableColumn:(id)arg2 row:(long long)arg3;
- (BOOL)tableView:(id)arg1 shouldSelectRow:(long long)arg2;
- (BOOL)tableView:(id)arg1 isGroupRow:(long long)arg2;
- (id)tableViewItemAtIndex:(long long)arg1;
- (void)populateInterfaces;
- (char *)netcfgSaveBuffer;
- (void)populateAfterReload;
- (void)reloadNetworkConfig;
- (void)deleteSelection;
- (void)addNewCustomNetwork;
- (id)networkForVMNetKey:(id)arg1;
- (id)networkForAdaptor:(id)arg1;
- (id)customNetworks;
- (id)selectedNetworkInterface;
- (void)onRepopulate:(id)arg1;
- (void)updateInterfacesTableIsEnabled;
- (void)onEditingChange:(id)arg1;
- (void)onInterfaceChanged:(id)arg1;
- (void)addBridgedItemWithInterface:(id)arg1;
- (void)addItemWithRepresentedObject:(id)arg1 withTitle:(id)arg2 image:(id)arg3;
- (void)addItemWithHostIF:(int)arg1 image:(id)arg2;
- (id)infoTextForNetcfgNetwork:(id)arg1;
- (id)infoTextForHostIF:(int)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)reloadData;
- (void)closeView;
- (void)openView;
- (void)dealloc;
- (void)awakeFromNib;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

