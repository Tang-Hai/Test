//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSViewController.h"

#import "PLPrefsPaneController.h"

@class DUIPrefs, NSPopUpButton, NSString;

@interface PLDisplayPrefsPaneController : NSViewController <PLPrefsPaneController>
{
    NSPopUpButton *singleWindowResolutionPopUp;
}

+ (id)identifier;
- (void)rebuildSingleWindowPopUpMenu;
- (void)selectSingleWindowAutofitMode:(id)arg1;
@property(nonatomic) int singleWindowAutofitMode;
- (void)setSelectedObject:(id)arg1;
@property(readonly, nonatomic) DUIPrefs *prefs;
- (id)icon;
- (id)label;
- (id)identifier;
- (void)awakeFromNib;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

