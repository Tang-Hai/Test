//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSViewController.h"

#import "NSMenuDelegate.h"
#import "NSOutlineViewDelegate.h"
#import "NSTableViewDelegate.h"
#import "NSTextFieldDelegate.h"
#import "PLInventoryViewController.h"

@class NSArray, NSArrayController, NSIndexPath, NSMapTable, NSOutlineView, NSSplitView, NSString, NSTableView, NSTextField, NSView, NSViewController<PLInventoryInfoViewController>, PLInventoryResponder, PLInventoryWindowController;

@interface PLInventoryOutlineViewController : NSViewController <NSMenuDelegate, NSTableViewDelegate, NSTextFieldDelegate, NSOutlineViewDelegate, PLInventoryViewController>
{
    NSArrayController *searchResultsController;
    NSOutlineView *outlineView;
    NSTableView *searchResultsView;
    NSTextField *searchTextField;
    NSSplitView *splitView;
    PLInventoryResponder *inventoryResponder;
    NSView *initialKeyView;
    NSView *infoViewContainer;
    PLInventoryWindowController *windowController;
    NSViewController<PLInventoryInfoViewController> *infoViewController;
    NSIndexPath *navigationIndexPath;
    NSArray *dragNodesArray;
    BOOL mNibDidLoad;
    BOOL mIsObserving;
    BOOL mInRenameEvent;
    NSIndexPath *mSelectedFolderIndexPath;
    NSMapTable *mSwitchMenuToInventoryMapTable;
}

+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
+ (id)observationKeyPaths;
@property(retain, nonatomic) NSMapTable *switchMenuToInventoryMapTable; // @synthesize switchMenuToInventoryMapTable=mSwitchMenuToInventoryMapTable;
@property(nonatomic) BOOL inRenameEvent; // @synthesize inRenameEvent=mInRenameEvent;
@property(nonatomic) BOOL isObserving; // @synthesize isObserving=mIsObserving;
@property(nonatomic) BOOL nibDidLoad; // @synthesize nibDidLoad=mNibDidLoad;
@property(nonatomic) PLInventoryResponder *inventoryResponder; // @synthesize inventoryResponder;
@property(readonly, nonatomic) NSView *initialKeyView; // @synthesize initialKeyView;
@property(retain, nonatomic) NSArray *dragNodesArray; // @synthesize dragNodesArray;
@property(retain, nonatomic) NSIndexPath *selectedFolderIndexPath; // @synthesize selectedFolderIndexPath=mSelectedFolderIndexPath;
@property(retain, nonatomic) NSIndexPath *navigationIndexPath; // @synthesize navigationIndexPath;
@property(readonly, nonatomic) PLInventoryWindowController *windowController; // @synthesize windowController;
@property(retain, nonatomic) NSViewController<PLInventoryInfoViewController> *infoViewController; // @synthesize infoViewController;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (unsigned long long)outlineView:(id)arg1 validateDrop:(id)arg2 proposedItem:(id)arg3 proposedChildIndex:(long long)arg4;
- (BOOL)outlineView:(id)arg1 acceptDrop:(id)arg2 item:(id)arg3 childIndex:(long long)arg4;
- (BOOL)outlineView:(id)arg1 writeItems:(id)arg2 toPasteboard:(id)arg3;
- (id)outlineView:(id)arg1 itemForPersistentObject:(id)arg2;
- (id)outlineView:(id)arg1 persistentObjectForItem:(id)arg2;
- (unsigned long long)draggingSourceOperationMaskForLocal:(BOOL)arg1;
- (void)outlineViewItemDidCollapse:(id)arg1;
- (void)outlineViewItemDidExpand:(id)arg1;
- (id)outlineView:(id)arg1 rowViewForItem:(id)arg2;
- (void)outlineViewSelectionDidChange:(id)arg1;
- (id)outlineView:(id)arg1 viewForTableColumn:(id)arg2 item:(id)arg3;
- (BOOL)outlineView:(id)arg1 shouldShowOutlineCellForItem:(id)arg2;
- (BOOL)outlineView:(id)arg1 shouldCollapseItem:(id)arg2;
- (BOOL)outlineView:(id)arg1 shouldEditTableColumn:(id)arg2 item:(id)arg3;
- (BOOL)outlineView:(id)arg1 isGroupItem:(id)arg2;
- (void)outlineViewDeleteSelection:(id)arg1;
- (BOOL)outlineViewCanDeleteSelection:(id)arg1;
- (void)outlineView:(id)arg1 menuNeedsUpdate:(id)arg2;
- (id)tableView:(id)arg1 viewForTableColumn:(id)arg2 row:(long long)arg3;
- (void)tableViewSelectionDidChange:(id)arg1;
- (void)tableView:(id)arg1 menuNeedsUpdate:(id)arg2;
- (BOOL)tableView:(id)arg1 shouldEditTableColumn:(id)arg2 item:(id)arg3;
- (void)tableViewDeleteSelection:(id)arg1;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)controlTextDidEndEditing:(id)arg1;
- (BOOL)control:(id)arg1 textView:(id)arg2 doCommandBySelector:(SEL)arg3;
- (void)onTextDidChange:(id)arg1;
- (void)updateSelectedNodes;
- (void)menuNeedsUpdate:(id)arg1;
- (id)folderContentsView;
- (void)onWindowWillClose:(id)arg1;
- (void)updateInfoView;
- (BOOL)updateInfoViewForNode:(id)arg1;
- (void)onInventoryDidChange:(id)arg1;
- (id)constraintsForInfoView:(id)arg1;
- (void)updateKnownItems;
- (void)closeView;
- (void)configureView;
- (id)knownItemsPrefKey;
- (void)viewWillShowWithTreeNode:(id)arg1;
- (void)navigateToTreeNode:(id)arg1;
- (void)updateNavigationIndexPath;
- (void)updateSearchIndexPaths;
- (void)updateOutlineIndexPaths;
- (void)makeFirstReponderToOutlineView;
- (void)editItem:(id)arg1 atIndexPath:(id)arg2 target:(id)arg3;
- (void)showContentsAtIndexPath:(id)arg1;
- (void)setSelectionIndexPath:(id)arg1;
- (void)expandTreeNode:(id)arg1;
- (id)selectedNodes;
- (id)objectController;
- (id)activeTableView;
- (id)objectControllerForView:(id)arg1;
- (BOOL)outlineView:(id)arg1 shouldShowSwitchViewForItem:(id)arg2;
- (void)outlineView:(id)arg1 willDisplayOutlineCell:(id)arg2 forTableColumn:(id)arg3 item:(id)arg4;
- (void)onDoubleClick:(id)arg1;
- (id)treeController;
- (id)inventoryMgr;
- (void)dealloc;
- (void)awakeFromNib;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

