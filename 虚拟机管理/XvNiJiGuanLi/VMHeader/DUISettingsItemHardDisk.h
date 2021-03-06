//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUISettingsItemBaseDevice.h"

#import "NSOpenSavePanelDelegate.h"
#import "NSTextFieldDelegate.h"

@class DUIVMEditor, NSNumberFormatter, NSPopUpButton, NSSlider, NSString, NSTextField, NSURL;

@interface DUISettingsItemHardDisk : DUISettingsItemBaseDevice <NSOpenSavePanelDelegate, NSTextFieldDelegate>
{
    NSPopUpButton *diskPopup;
    NSSlider *diskSizeSlider;
    NSTextField *diskSizeTextField;
    long long firstDynamicDiskItemIndex;
    NSURL *fileURLForNewDisk;
    double sizeGB;
    double minimumSizeGB;
    double maximumSizeGB;
    BOOL hasParent;
    BOOL isThirdPartyDisk;
    DUIVMEditor *editor;
    BOOL userOverridesSplitRecommendation;
    BOOL userSplitValue;
    BOOL mSizeGBTextHasChanged;
    BOOL mAbsolutePathExists;
    BOOL mViewHasLoaded;
    NSString *mFilePathForNewDisk;
    NSNumberFormatter *mSizeGBFormatter;
}

+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
+ (id)observationKeyPaths;
@property(nonatomic) BOOL viewHasLoaded; // @synthesize viewHasLoaded=mViewHasLoaded;
@property(nonatomic) BOOL absolutePathExists; // @synthesize absolutePathExists=mAbsolutePathExists;
@property(retain, nonatomic) NSNumberFormatter *sizeGBFormatter; // @synthesize sizeGBFormatter=mSizeGBFormatter;
@property(retain, nonatomic) NSString *filePathForNewDisk; // @synthesize filePathForNewDisk=mFilePathForNewDisk;
@property(nonatomic) double maximumSizeGB; // @synthesize maximumSizeGB;
@property(nonatomic) double minimumSizeGB; // @synthesize minimumSizeGB;
@property(nonatomic) BOOL hasParent; // @synthesize hasParent;
@property(nonatomic) BOOL sizeGBTextHasChanged; // @synthesize sizeGBTextHasChanged=mSizeGBTextHasChanged;
@property(nonatomic) double sizeGB; // @synthesize sizeGB;
@property(retain, nonatomic) DUIVMEditor *editor; // @synthesize editor;
- (id)removeDeviceMessageText;
- (id)warnings;
- (void)trashExtents:(id)arg1;
- (void)moveToTrashAlertDidEndWithReturnCode:(long long)arg1;
- (void)removeDevice:(id)arg1;
- (id)removeDeviceInformativeText;
- (BOOL)canRemoveDevice;
- (void)onSaveAs:(id)arg1;
- (void)splitDiskChanged:(id)arg1;
- (void)diskSizeSliderMoved:(id)arg1;
- (BOOL)validateSizeGB:(id *)arg1 error:(id *)arg2;
- (void)resetInitialSizeGB;
- (CDUnknownBlockType)saveBlockWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (void)onApplySuccess:(BOOL)arg1 saveHandler:(CDUnknownBlockType)arg2 needsResize:(BOOL)arg3;
- (void)onDevicesChanged:(id)arg1;
- (void)applyAndClose:(BOOL)arg1 saveHandler:(CDUnknownBlockType)arg2;
- (void)apply:(id)arg1;
- (void)shouldCloseViewWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (BOOL)canCloseView;
- (BOOL)validateSizeGBWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (void)abortDiskSizeEditing;
- (void)controlTextDidEndEditing:(id)arg1;
- (void)controlTextDidChange:(id)arg1;
- (void)revert:(id)arg1;
- (BOOL)canApply;
- (BOOL)canRevert;
@property(nonatomic) BOOL split;
@property(nonatomic) BOOL preAllocated;
- (BOOL)enableBusType:(int)arg1;
- (BOOL)enableNVMe;
- (BOOL)enableSATA;
- (BOOL)enableSCSI;
- (BOOL)enableIDE;
- (BOOL)isBusTypeAvailable;
@property(nonatomic) long long busTypeIndex;
- (id)absolutePath;
- (BOOL)validateDiskItemIndex:(id *)arg1 error:(id *)arg2;
@property(nonatomic) long long diskItemIndex;
@property(readonly, nonatomic) BOOL hideSaveAs;
- (BOOL)shouldInvalidateOnKeyChange;
- (void)updateMinMaxSizes;
- (void)updatePopupMenu;
- (id)fileSystem;
- (id)deviceHardDisk;
- (void)closeView;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)onDiskExistenceCheckDone:(int)arg1;
- (void)openView;
- (void)awakeFromNib;
- (void)dealloc;
- (BOOL)canEditProperty:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

