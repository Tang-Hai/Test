//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLMultiStateAssistant.h"

#import "DUIApplicationTerminationDelegate.h"
#import "NSTableViewDataSource.h"
#import "NSTableViewDelegate.h"

@class DUIDlgMgr, NSString, NSTableView, PLVMScanAssistantInteractionPanel;

@interface PLVMScanAssistant : PLMultiStateAssistant <DUIApplicationTerminationDelegate, NSTableViewDataSource, NSTableViewDelegate>
{
    PLVMScanAssistantInteractionPanel *interactionPanel;
    BOOL mDidAwakeFromNib;
    DUIDlgMgr *mDlgMgr;
    NSTableView *_scanPathsTableView;
}

@property(nonatomic) NSTableView *scanPathsTableView; // @synthesize scanPathsTableView=_scanPathsTableView;
@property(nonatomic) BOOL didAwakeFromNib; // @synthesize didAwakeFromNib=mDidAwakeFromNib;
@property(retain, nonatomic) DUIDlgMgr *dlgMgr; // @synthesize dlgMgr=mDlgMgr;
- (void)onRemoveScanPaths:(id)arg1;
- (void)onAddScanPath:(id)arg1;
- (void)tableViewSelectionDidChange:(id)arg1;
- (void)tableView:(id)arg1 willDisplayCell:(id)arg2 forTableColumn:(id)arg3 row:(long long)arg4;
- (id)tableView:(id)arg1 objectValueForTableColumn:(id)arg2 row:(long long)arg3;
- (long long)numberOfRowsInTableView:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)assistantWillUnload;
- (void)prepareForApplicationTerminationWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
@property(readonly, nonatomic) BOOL canApplicationTerminate;
- (void)cancel;
- (id)window;
- (BOOL)start;
- (BOOL)goForward;
@property(readonly, nonatomic) BOOL canScanForVMs;
@property(readonly, nonatomic) BOOL canRemoveScanPaths;
- (void)configButtonState;
@property(readonly, nonatomic) BOOL canAddScanPath;
- (id)viewForState:(int)arg1;
- (long long)helpTag;
- (id)title;
- (id)subtitleForState:(int)arg1;
- (id)titleForState:(int)arg1;
- (void)awakeFromNib;
- (void)dealloc;
- (id)vmScanController;
- (id)initWithAssistantManager:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

