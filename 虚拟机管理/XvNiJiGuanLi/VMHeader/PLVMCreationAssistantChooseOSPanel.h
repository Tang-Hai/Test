//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLAssistantPanelController.h"

#import "NSBrowserDelegate.h"

@class NSArray, NSBrowser, NSMutableDictionary, NSString, PLBaseVMCreationAssistant<PLChooseOSDelegate>;

@interface PLVMCreationAssistantChooseOSPanel : PLAssistantPanelController <NSBrowserDelegate>
{
    NSBrowser *guestOSBrowser;
    NSArray *mGuestFamilies;
    NSMutableDictionary *mGuestOSesByFamily;
}

+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
+ (id)observationKeyPaths;
@property(retain, nonatomic) NSMutableDictionary *guestOSesByFamily; // @synthesize guestOSesByFamily=mGuestOSesByFamily;
@property(retain, nonatomic) NSArray *guestFamilies; // @synthesize guestFamilies=mGuestFamilies;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)browser:(id)arg1 objectValueForItem:(id)arg2;
- (BOOL)browser:(id)arg1 isLeafItem:(id)arg2;
- (id)browser:(id)arg1 child:(long long)arg2 ofItem:(id)arg3;
- (long long)browser:(id)arg1 numberOfChildrenOfItem:(id)arg2;
- (void)adjustBrowserColumnSize;
- (id)supportedGuestOSesByFamily:(id)arg1;
- (void)resetOperatingSystemButtons:(BOOL)arg1;
- (void)setOSVersion:(id)arg1;
- (void)onGuestOSInfoChanged;
- (void)configureView;
- (id)vmCreationHelper;
- (void)assistantWillUnload;
- (void)assistantWillStart;
- (void)dealloc;
- (id)initWithAssistant:(id)arg1;

// Remaining properties
@property(readonly, nonatomic) PLBaseVMCreationAssistant<PLChooseOSDelegate> *assistant; // @dynamic assistant;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

