//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSWindowController.h"

#import "DUISettingsControllerDelegate.h"

@class DUICnx, DUIDlgMgr, DUISettingsController, DUIVM, NSImageView, NSObject<DUISettingsItem>, NSObject<DUIVMContainer>, NSSegmentedControl, NSStackView, NSString, NSTextField, NSToolbarItem, NSView, VMTitleBarTemplateImageButton;

@interface DUISettingsWindowController : NSWindowController <DUISettingsControllerDelegate>
{
    NSView *warningView;
    NSTextField *warningTextField;
    NSImageView *warningImageView;
    NSStackView *stackView;
    NSToolbarItem *addDeviceTBItem;
    NSToolbarItem *showAllTBItem;
    NSToolbarItem *titleItem;
    NSSegmentedControl *addDeviceButton;
    NSSegmentedControl *showAllButton;
    VMTitleBarTemplateImageButton *lockButton;
    DUISettingsController *mSettingsController;
    NSObject<DUISettingsItem> *mCurrentItem;
    DUIDlgMgr *mDlgMgr;
    NSObject<DUIVMContainer> *mVMContainer;
    DUICnx *mCnx;
    NSString *mRestorationID;
}

+ (id)observationKeyPaths;
+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
@property(copy, nonatomic) NSString *restorationID; // @synthesize restorationID=mRestorationID;
@property(retain, nonatomic) DUICnx *cnx; // @synthesize cnx=mCnx;
@property(retain, nonatomic) NSObject<DUIVMContainer> *vmContainer; // @synthesize vmContainer=mVMContainer;
@property(retain, nonatomic) DUIDlgMgr *dlgMgr; // @synthesize dlgMgr=mDlgMgr;
@property(retain, nonatomic) NSObject<DUISettingsItem> *currentItem; // @synthesize currentItem=mCurrentItem;
@property(retain, nonatomic) DUISettingsController *settingsController; // @synthesize settingsController=mSettingsController;
- (void)onRestrictLockDialogDidEnd:(id)arg1;
- (void)onToggleLock:(id)arg1;
- (void)showDescribeLockAlert;
- (id)lockImage;
- (BOOL)isPolicyControlledVM;
- (void)windowDidChangeOcclusionState:(id)arg1;
- (void)restoreStateWithCoder:(id)arg1;
- (void)encodeRestorableStateWithCoder:(id)arg1;
- (void)updateWarnings;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)onItemDidInvalidate:(id)arg1;
- (void)onAddDevice:(id)arg1;
- (void)onShowAll:(id)arg1;
@property(readonly, copy, nonatomic) NSString *windowTitle;
- (void)animateSwitchToItem:(id)arg1;
- (void)showItemWithKey:(id)arg1 shouldForce:(BOOL)arg2;
- (void)onWindowDidEndSheet:(id)arg1;
- (void)onWindowWillBeginSheet:(id)arg1;
- (void)windowWillClose:(id)arg1;
- (BOOL)windowShouldClose:(id)arg1;
- (void)closeContents;
- (BOOL)canCloseContents;
- (id)supplementalTargetForAction:(SEL)arg1 sender:(id)arg2;
- (id)windowWillReturnFieldEditor:(id)arg1 toObject:(id)arg2;
- (void)showSettingsWindowWithItemKey:(id)arg1;
- (BOOL)canAddDevices;
- (BOOL)canShowAll;
- (BOOL)hideAddDeviceButton;
@property(readonly, retain, nonatomic) DUIVM *vm;
- (void)windowDidLoad;
- (void)dealloc;
- (id)initWithWindowNibName:(id)arg1 vmContainer:(id)arg2;

@end

