//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLAssistantPanelController.h"

#import "NSOutlineViewDataSource.h"
#import "NSOutlineViewDelegate.h"
#import "NSTextFieldDelegate.h"

@class NSArray, NSOutlineView, NSPopover, NSString;

@interface PLCreationAssistantImportAdditionalSettingsPanel : PLAssistantPanelController <NSTextFieldDelegate, NSOutlineViewDataSource, NSOutlineViewDelegate>
{
    BOOL mCanContinue;
    NSArray *mCategories;
    NSOutlineView *_outlineView;
    NSPopover *_descPopover;
}

@property(nonatomic) NSPopover *descPopover; // @synthesize descPopover=_descPopover;
@property(nonatomic) NSOutlineView *outlineView; // @synthesize outlineView=_outlineView;
@property(nonatomic) BOOL canContinue; // @synthesize canContinue=mCanContinue;
@property(retain, nonatomic) NSArray *categories; // @synthesize categories=mCategories;
- (void)focusOnTextField:(id)arg1;
- (void)movementOnItem:(id)arg1 forward:(BOOL)arg2;
- (void)tabToMoveWithTextField:(id)arg1 forward:(BOOL)arg2;
- (void)controlTextDidChange:(id)arg1;
- (void)controlTextDidEndEditing:(id)arg1;
- (void)showPopoverWithDescription:(id)arg1 sender:(id)arg2;
- (id)descriptionWithSender:(id)arg1;
- (void)onDescriptionButtonClicked:(id)arg1;
- (double)outlineView:(id)arg1 heightOfRowByItem:(id)arg2;
- (id)outlineView:(id)arg1 viewForTableColumn:(id)arg2 item:(id)arg3;
- (id)outlineView:(id)arg1 objectValueForTableColumn:(id)arg2 byItem:(id)arg3;
- (BOOL)outlineView:(id)arg1 shouldExpandItem:(id)arg2;
- (BOOL)outlineView:(id)arg1 isGroupItem:(id)arg2;
- (BOOL)outlineView:(id)arg1 isItemExpandable:(id)arg2;
- (id)outlineView:(id)arg1 child:(long long)arg2 ofItem:(id)arg3;
- (long long)outlineView:(id)arg1 numberOfChildrenOfItem:(id)arg2;
- (void)updateCanContinue;
- (id)getOutput;
- (void)setInputWithCategories:(id)arg1;
- (void)dealloc;
- (void)viewDidDisappear;
- (void)viewWillAppear;
- (void)viewDidLoad;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

