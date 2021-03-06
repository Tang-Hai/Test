//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLPreprocessedVMAssistant.h"

@class PLAssistantPanelController, PLBootCampAssistantChooseDiskPanel, PLBootCampAssistantImportPanel, PLBootCampVMCreator, PLImportCreationDelegate, PLImportSavePanelAccessory;

@interface PLBootCampAssistant : PLPreprocessedVMAssistant
{
    PLBootCampAssistantChooseDiskPanel *chooseDiskPanel;
    PLAssistantPanelController *processDiskPanel;
    PLBootCampAssistantImportPanel *importDiskPanel;
    BOOL mIsImporting;
    BOOL mIsPreprocessing;
    int mBootCampVMType;
    PLBootCampVMCreator *mBootCampVMCreator;
    PLImportCreationDelegate *mImportDelegate;
    PLImportSavePanelAccessory *mSavePanelAccessory;
}

@property(nonatomic) BOOL isPreprocessing; // @synthesize isPreprocessing=mIsPreprocessing;
@property(nonatomic) BOOL isImporting; // @synthesize isImporting=mIsImporting;
@property(nonatomic) int bootCampVMType; // @synthesize bootCampVMType=mBootCampVMType;
@property(retain, nonatomic) PLImportSavePanelAccessory *savePanelAccessory; // @synthesize savePanelAccessory=mSavePanelAccessory;
@property(retain, nonatomic) PLImportCreationDelegate *importDelegate; // @synthesize importDelegate=mImportDelegate;
@property(retain, nonatomic) PLBootCampVMCreator *bootCampVMCreator; // @synthesize bootCampVMCreator=mBootCampVMCreator;
- (void)onSaveVMDone;
- (void)configureSavePanel:(id)arg1 displayName:(id)arg2;
- (void)createBootCampVMBundle;
- (void)createBootCampVMBundleAsync;
- (void)doCleanupOnFailure;
- (void)savePanelDidEnd:(id)arg1;
- (void)findAvailableDidEndWithName:(id)arg1;
- (void)showSavePanel;
- (void)resetImportButtons;
- (id)toolsGuestKey;
- (BOOL)isImport;
- (void)configureChooseDisksView;
- (void)finishCreation;
- (id)resultBundleURL;
- (void)assistantWillUnload;
- (void)cancel;
- (BOOL)start;
- (void)goBackward;
- (BOOL)goForward;
- (id)localizedNameForStep:(long long)arg1;
- (long long)stepIndexForState:(int)arg1;
- (void)stateDidChangeFromState:(int)arg1;
- (id)viewForState:(int)arg1;
- (long long)helpTag;
- (id)title;
- (id)subtitleForState:(int)arg1;
- (id)titleForState:(int)arg1;
- (void)dealloc;
- (id)initWithAssistantManager:(id)arg1;

@end

