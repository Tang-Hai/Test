//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSWindowController.h"

#import "NSWindowDelegate.h"

@class DUIDlgMgr, DUIRestrictedInventory, NSArray, NSArrayController, NSMutableDictionary, NSString, NSTableView, NSTextField, PLImportSavePanelAccessory;

@interface PLRestrictedVMWindowController : NSWindowController <NSWindowDelegate>
{
    NSTableView *selTableView;
    NSArrayController *rvmArrayCtl;
    NSTextField *serverHostName;
    DUIRestrictedInventory *mInventory;
    DUIDlgMgr *mDlgMgr;
    PLImportSavePanelAccessory *mSavePanelAccessory;
    NSMutableDictionary *mInventoryChangeObservers;
    NSArray *mSortDescriptors;
}

@property(retain, nonatomic) NSArray *sortDescriptors; // @synthesize sortDescriptors=mSortDescriptors;
@property(retain, nonatomic) NSMutableDictionary *inventoryChangeObservers; // @synthesize inventoryChangeObservers=mInventoryChangeObservers;
@property(retain, nonatomic) PLImportSavePanelAccessory *savePanelAccessory; // @synthesize savePanelAccessory=mSavePanelAccessory;
@property(retain, nonatomic) DUIDlgMgr *dlgMgr; // @synthesize dlgMgr=mDlgMgr;
@property(retain, nonatomic) DUIRestrictedInventory *inventory; // @synthesize inventory=mInventory;
- (void)updateAttributesForDownloadBundle:(id)arg1 withID:(id)arg2;
- (void)cleanupDownloadPath:(id)arg1;
- (void)resumeVMWithID:(id)arg1;
- (void)resumeDownloadForFileURL:(id)arg1;
- (void)resumeDownload:(id)arg1;
- (void)cancelDownload:(id)arg1;
- (void)downloadRVM:(id)arg1 toVMDestination:(id)arg2 downloadPath:(id)arg3;
- (void)download:(id)arg1 toFile:(id)arg2;
- (id)savePanelForVM:(id)arg1;
- (void)handleCancelButton:(id)arg1;
- (void)handleActionButton:(id)arg1;
- (void)showSavePanel:(id)arg1 forVM:(id)arg2 abortHandler:(CDUnknownBlockType)arg3 completionHandler:(CDUnknownBlockType)arg4;
- (void)showSavePanelForVMDownload:(id)arg1;
- (void)refresh:(id)arg1;
- (void)windowWillClose:(id)arg1;
- (id)restrictedVMForRowView:(id)arg1;
- (BOOL)windowShouldClose:(id)arg1;
- (void)windowDidLoad;
- (void)dealloc;
- (id)initWithCnx:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

