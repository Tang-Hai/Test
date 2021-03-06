//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUISettingsItemBase.h"

@class NSMatrix, NSScrollView, NSString, VMAlternateKeyButton;

@interface PLSettingsItemStartupDevice : DUISettingsItemBase
{
    NSScrollView *deviceScrollView;
    NSMatrix *deviceMatrix;
    VMAlternateKeyButton *restartButton;
    NSString *selectedItemName;
}

+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
@property(retain, nonatomic) NSString *selectedItemName; // @synthesize selectedItemName;
- (id)warnings;
- (id)deviceList;
- (void)updateDeviceList:(id)arg1;
- (void)updateCell:(id)arg1 forDevice:(id)arg2;
- (id)nameForDevice:(id)arg1;
- (id)descriptionForDevice:(id)arg1;
- (id)descriptionForDeviceNIC:(id)arg1;
- (id)iconForDevice:(id)arg1;
- (void)selectCellWithDeviceKey:(id)arg1;
- (void)onRestoreDefaultsButtonClicked:(id)arg1;
- (void)onRestartButtonClicked:(id)arg1;
- (BOOL)canRestartToFirmware;
@property(readonly, nonatomic) BOOL canRestart;
- (void)onDeviceButtonClicked:(id)arg1;
- (void)setStartupDeviceKey:(id)arg1;
- (id)addBootOrderDeviceItemOfType:(int)arg1 withName:(id)arg2 toBootOrderArray:(id)arg3;
- (id)startupDeviceKey;
- (void)closeView;
- (void)openView;
- (void)awakeFromNib;

@end

