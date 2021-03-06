//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSOutlineViewDataSource.h"
#import "NSOutlineViewDelegate.h"

@class NSButtonCell, NSDictionary, NSObject<VMSettingsOutlineTarget>, NSPopUpButtonCell, NSSecureTextFieldCell, NSString, NSTextFieldCell;

@interface VMSettingsOutlineDictionary : NSObject <NSOutlineViewDataSource, NSOutlineViewDelegate>
{
    NSDictionary *root;
    NSObject<VMSettingsOutlineTarget> *target;
    NSObject *delegate;
    NSButtonCell *checkbox;
    NSPopUpButtonCell *popupButton;
    NSSecureTextFieldCell *secureTextField;
    NSTextFieldCell *numberTextField;
    NSTextFieldCell *standardTextField;
}

@property NSObject *delegate; // @synthesize delegate;
@property(retain) NSTextFieldCell *standardTextField; // @synthesize standardTextField;
@property(retain) NSTextFieldCell *numberTextField; // @synthesize numberTextField;
@property(retain) NSSecureTextFieldCell *secureTextField; // @synthesize secureTextField;
@property(retain) NSPopUpButtonCell *popupButton; // @synthesize popupButton;
@property(retain) NSButtonCell *checkbox; // @synthesize checkbox;
@property(retain) NSObject *target; // @synthesize target;
@property(retain) NSDictionary *root; // @synthesize root;
- (BOOL)control:(id)arg1 textView:(id)arg2 doCommandBySelector:(SEL)arg3;
- (void)controlTextDidBeginEditing:(id)arg1;
- (void)outlineViewSelectionDidChange:(id)arg1;
- (void)outlineView:(id)arg1 setObjectValue:(id)arg2 forTableColumn:(id)arg3 byItem:(id)arg4;
- (BOOL)outlineView:(id)arg1 validateObjectValue:(id *)arg2 forKey:(id)arg3 byItem:(id)arg4;
- (id)outlineView:(id)arg1 objectValueForTableColumn:(id)arg2 byItem:(id)arg3;
- (id)outlineView:(id)arg1 child:(long long)arg2 ofItem:(id)arg3;
- (BOOL)outlineView:(id)arg1 isItemExpandable:(id)arg2;
- (long long)outlineView:(id)arg1 numberOfChildrenOfItem:(id)arg2;
- (void)outlineView:(id)arg1 willDisplayCell:(id)arg2 forTableColumn:(id)arg3 item:(id)arg4;
- (id)outlineView:(id)arg1 dataCellForTableColumn:(id)arg2 item:(id)arg3;
- (void)dealloc;
- (id)initWithTarget:(id)arg1 delegate:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

