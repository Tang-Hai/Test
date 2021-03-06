//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSToolbarDelegate.h"

@class DUIActionController, DUIWeakRef, NSObject<DUIVMContainer>, NSString, NSToolbar;

@interface DUIVMWindowToolbarDelegate : NSObject <NSToolbarDelegate>
{
    NSToolbar *toolbar;
    NSObject<DUIVMContainer> *mVMContainer;
    DUIActionController *mActionController;
    DUIWeakRef *mWeakToolbar;
}

+ (id)observationKeyPaths;
@property(retain, nonatomic) DUIWeakRef *weakToolbar; // @synthesize weakToolbar=mWeakToolbar;
@property(retain, nonatomic) DUIActionController *actionController; // @synthesize actionController=mActionController;
@property(retain, nonatomic) NSObject<DUIVMContainer> *vmContainer; // @synthesize vmContainer=mVMContainer;
- (id)itemTarget;
- (id)toolbar:(id)arg1 itemForItemIdentifier:(id)arg2 willBeInsertedIntoToolbar:(BOOL)arg3;
- (id)toolbarDefaultItemIdentifiers:(id)arg1;
- (id)toolbarAllowedItemIdentifiers:(id)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)updateTargetForItem:(id)arg1;
- (void)validateAllItems;
- (id)liveToolbar;
- (void)awakeFromNib;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

