//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUISettingsItemBaseDevice.h"

@class DUIMemoryConfigMgr, NSArray, NSPopUpButton, NSStackView, NSString, NSView;

@interface PLSettingsItemDisplay : DUISettingsItemBaseDevice
{
    NSPopUpButton *memorySettingPopUp;
    NSStackView *accel3DStackLayoutView;
    NSView *batteryLifeView;
    NSView *graphicsMemoryView;
    NSStackView *retinaSupportStackLayoutView;
    NSView *applyNativeDPIView;
    NSView *scaledHighResolutionView;
    NSPopUpButton *supportedViewModePopUp;
    NSStackView *resolutionBehaviorStackLayoutView;
    NSView *resolutionBehaviorView;
    BOOL mSupportsGPUAutoSwitching;
    int mDX10SupportLevel;
    DUIMemoryConfigMgr *mMemoryConfigMgr;
    NSArray *mStackableSubviews;
}

+ (id)keyPathsAffectingSettingsValueForKey:(id)arg1;
@property(nonatomic) int dx10SupportLevel; // @synthesize dx10SupportLevel=mDX10SupportLevel;
@property(nonatomic) BOOL supportsGPUAutoSwtiching; // @synthesize supportsGPUAutoSwtiching=mSupportsGPUAutoSwitching;
@property(retain, nonatomic) NSArray *stackableSubviews; // @synthesize stackableSubviews=mStackableSubviews;
@property(retain, nonatomic) DUIMemoryConfigMgr *memoryConfigMgr; // @synthesize memoryConfigMgr=mMemoryConfigMgr;
- (BOOL)hasSupportedHardwareAccelerated3D;
- (id)warnings;
- (BOOL)canEditProperty:(id)arg1;
@property(nonatomic) BOOL applyNativeDPI;
@property(nonatomic) long long scaledHighResolution;
- (void)selectGraphicsMemorySize:(id)arg1;
@property(nonatomic) unsigned int graphicsMemorySize;
- (void)selectFullscreenAutofitMode:(id)arg1;
@property(nonatomic) int fullscreenAutofitMode;
- (void)selectSingleWindowAutofitMode:(id)arg1;
@property(nonatomic) int singleWindowAutofitMode;
- (void)selectAutoSwitchState:(id)arg1;
@property(nonatomic) int autoSwitchState;
@property(nonatomic) BOOL nativeResolution;
@property(readonly, copy, nonatomic) NSString *accel3DDescription;
@property(nonatomic) BOOL accel3D;
- (id)uiConfig;
- (id)deviceSVGA;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)updateContainedViews;
- (void)updatePopUpMenu;
- (void)closeView;
- (void)openView;
- (void)awakeFromNib;
- (void)dealloc;

@end

