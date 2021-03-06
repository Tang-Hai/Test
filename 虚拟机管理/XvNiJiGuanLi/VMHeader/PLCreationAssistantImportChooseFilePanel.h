//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLAssistantPanelController.h"

@class NSArrayController, NSMutableSet, NSTableView, PLImportAssistant;

@interface PLCreationAssistantImportChooseFilePanel : PLAssistantPanelController
{
    NSArrayController *fileArrayController;
    NSTableView *fileTableView;
    NSMutableSet *mActiveImportChecks;
}

@property(retain, nonatomic) NSMutableSet *activeImportChecks; // @synthesize activeImportChecks=mActiveImportChecks;
- (void)getConfigInfoForEntry:(id)arg1;
- (void)onConfigCheckDone:(BOOL)arg1 forEntry:(id)arg2 configData:(struct ParsedConfigData *)arg3 failureReason:(id)arg4 error:(id)arg5 isVMImport:(BOOL)arg6;
- (BOOL)canCorrectError:(id)arg1;
- (void)writePrefs;
- (id)entryForURL:(id)arg1;
- (BOOL)chooseURLs:(id)arg1;
- (id)addImportableURL:(id)arg1;
- (id)selectedObject;
- (void)showFileInFinder:(id)arg1;
- (void)reloadFromPrefs:(id)arg1;
- (void)clearRecentItems:(id)arg1;
- (void)chooseImportFile:(id)arg1;
- (id)tableView:(id)arg1 rowViewForRow:(long long)arg2;
- (void)tableViewSelectionDidChange:(id)arg1;
- (void)resetButtons;
- (void)configureView;
- (void)assistantWillUnload;
- (void)awakeFromNib;
- (void)dealloc;

// Remaining properties
@property(readonly, nonatomic) PLImportAssistant *assistant; // @dynamic assistant;

@end

