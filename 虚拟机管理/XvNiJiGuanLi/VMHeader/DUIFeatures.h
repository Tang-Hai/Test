//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class NSArray;

@interface DUIFeatures : DUIAdaptorBase
{
}

+ (id)featuresForAdaptedFeatures:(struct Features *)arg1;
+ (id)features;
@property(readonly, retain, nonatomic) NSArray *canSupportUIDrawnMKSFailureReasons;
@property(readonly, nonatomic) BOOL canSupportUIDrawnMKS;
@property(readonly, retain, nonatomic) NSArray *canSupportVigorDevMgmtFailureReasons;
@property(readonly, nonatomic) BOOL canSupportVigorDevMgmt;
@property(readonly, retain, nonatomic) NSArray *canSupportVBSFailureReasons;
@property(readonly, nonatomic) BOOL canSupportVBS;
@property(readonly, retain, nonatomic) NSArray *canSupportUEFISecureBootFailureReasons;
@property(readonly, nonatomic) BOOL canSupportUEFISecureBoot;
@property(readonly, retain, nonatomic) NSArray *canShowGuestInfoFailureReasons;
@property(readonly, nonatomic) BOOL canShowGuestInfo;
@property(readonly, retain, nonatomic) NSArray *canSupportVNCFailureReasons;
@property(readonly, nonatomic) BOOL canSupportVNC;
@property(readonly, retain, nonatomic) NSArray *canSupportVMEncryptionFailureReasons;
@property(readonly, nonatomic) BOOL canSupportVMEncryption;
@property(readonly, retain, nonatomic) NSArray *canSupportUnityFailureReasons;
@property(readonly, nonatomic) BOOL canSupportUnity;
@property(readonly, retain, nonatomic) NSArray *canSupportTouchbarFailureReasons;
@property(readonly, nonatomic) BOOL canSupportTouchbar;
@property(readonly, retain, nonatomic) NSArray *canSupportShrinkDiskTreeFailureReasons;
@property(readonly, nonatomic) BOOL canSupportShrinkDiskTree;
@property(readonly, retain, nonatomic) NSArray *canSupportShowNotificationAreaInUnityFailureReasons;
@property(readonly, nonatomic) BOOL canSupportShowNotificationAreaInUnity;
@property(readonly, retain, nonatomic) NSArray *canSupportShowTaskbarInUnityFailureReasons;
@property(readonly, nonatomic) BOOL canSupportShowTaskbarInUnity;
@property(readonly, retain, nonatomic) NSArray *canSupportRecordReplayFailureReasons;
@property(readonly, nonatomic) BOOL canSupportRecordReplay;
@property(readonly, retain, nonatomic) NSArray *canSupportPolicyEnforcementFailureReasons;
@property(readonly, nonatomic) BOOL canSupportPolicyEnforcement;
@property(readonly, retain, nonatomic) NSArray *canSupportPerVMHotKeysFailureReasons;
@property(readonly, nonatomic) BOOL canSupportPerVMHotKeys;
@property(readonly, retain, nonatomic) NSArray *canSupportOVFExportFailureReasons;
@property(readonly, nonatomic) BOOL canSupportOVFExport;
@property(readonly, retain, nonatomic) NSArray *canSupportLocalUSBFailureReasons;
@property(readonly, nonatomic) BOOL canSupportLocalUSB;
@property(readonly, retain, nonatomic) NSArray *canSupportDeviceSettingsFailureReasons;
@property(readonly, nonatomic) BOOL canSupportDeviceSettings;
@property(readonly, retain, nonatomic) NSArray *canSupportCloningFailureReasons;
@property(readonly, nonatomic) BOOL canSupportCloning;
@property(readonly, retain, nonatomic) NSArray *canSupportAdvancedSettingsFailureReasons;
@property(readonly, nonatomic) BOOL canSupportAdvancedSettings;
@property(readonly, retain, nonatomic) NSArray *canShowNetworkEditorFailureReasons;
@property(readonly, nonatomic) BOOL canShowNetworkEditor;
@property(readonly, retain, nonatomic) NSArray *canConnectToVIMFailureReasons;
@property(readonly, nonatomic) BOOL canConnectToVIM;
@property(readonly, retain, nonatomic) NSArray *canConnectToVCloudFailureReasons;
@property(readonly, nonatomic) BOOL canConnectToVCloud;
@property(readonly, retain, nonatomic) NSArray *canConnectToHorizonFlexFailureReasons;
@property(readonly, nonatomic) BOOL canConnectToHorizonFlex;
@property(readonly, retain, nonatomic) NSArray *canCollectDataFailureReasons;
@property(readonly, nonatomic) BOOL canCollectData;
@property(readonly, retain, nonatomic) NSArray *canChangeNetworkPromptForPromiscFailureReasons;
@property(readonly, nonatomic) BOOL canChangeNetworkPromptForPromisc;
@property(readonly, retain, nonatomic) NSArray *canCacheEncryptionKeysFailureReasons;
@property(readonly, nonatomic) BOOL canCacheEncryptionKeys;
@property(readonly, retain, nonatomic) NSArray *canBrowseFilesOnVIMFailureReasons;
@property(readonly, nonatomic) BOOL canBrowseFilesOnVIM;
@property(readonly, retain, nonatomic) NSArray *canAuthorRestrictedVMsFailureReasons;
@property(readonly, nonatomic) BOOL canAuthorRestrictedVMs;
@property(readonly, nonatomic) struct Features *adaptedFeatures;
- (id)initWithAdaptedFeatures:(struct Features *)arg1;

@end

