//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUISettingsItemBaseRemovableDevice.h"

@class NSButton, NSTextField;

@interface PLSettingsItemPrinters : DUISettingsItemBaseRemovableDevice
{
    NSTextField *shareDescriptionTextField;
    NSTextField *defaultPrinterTextField;
    NSButton *shareButton;
}

+ (id)keyPathsAffectingSettingsValueForKey:(id)arg1;
- (id)removeDeviceInformativeText;
- (id)removeDeviceMessageText;
- (id)warnings;
- (BOOL)canEditProperty:(id)arg1;
@property BOOL matchDefault;
- (void)updateGuestOSLabels;
- (void)openView;

@end

