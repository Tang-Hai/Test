//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLInventoryFolderInfoViewController.h"

#import "PLInventoryInfoViewController.h"

@class DUICnx, DUIInventoryNode, NSArrayController, NSLayoutConstraint, NSPopUpButton, NSStackView, NSString, NSTableView, NSTextField, NSView;

@interface PLInventoryRemoteStatsInfoViewController : PLInventoryFolderInfoViewController <PLInventoryInfoViewController>
{
    NSStackView *hostsStackView;
    NSView *loadingView;
    NSView *hostView;
    NSView *hostListView;
    NSView *singleHostView;
    NSView *singleHostNoUsageView;
    NSLayoutConstraint *infoLabelsWidthConstraint;
    NSTextField *cpuInfoLabel;
    NSTextField *memoryInfoLabel;
    NSArrayController *hostsArrayController;
    NSTableView *datastoreTableView;
    NSTableView *datastoreTableView2;
    NSPopUpButton *hostOperations;
    BOOL mIsLoading;
    BOOL mHasObservers;
    BOOL mHasAwakeFromNib;
    BOOL mcanSupportVMCreation;
    BOOL _subscribedToCanSupportVMCreationNotification;
    DUICnx *mCnx;
    long long mStatsTabIndex;
    NSString *mUsername;
}

+ (id)observationKeyPaths;
@property(nonatomic) BOOL subscribedToCanSupportVMCreationNotification; // @synthesize subscribedToCanSupportVMCreationNotification=_subscribedToCanSupportVMCreationNotification;
@property(nonatomic) BOOL canSupportVMCreation; // @synthesize canSupportVMCreation=mcanSupportVMCreation;
@property(copy, nonatomic) NSString *username; // @synthesize username=mUsername;
@property(nonatomic) long long statsTabIndex; // @synthesize statsTabIndex=mStatsTabIndex;
@property(nonatomic) BOOL hasAwakeFromNib; // @synthesize hasAwakeFromNib=mHasAwakeFromNib;
@property(nonatomic) BOOL hasObservers; // @synthesize hasObservers=mHasObservers;
@property(nonatomic) BOOL isLoading; // @synthesize isLoading=mIsLoading;
@property(retain, nonatomic) DUICnx *cnx; // @synthesize cnx=mCnx;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)onNewVM:(id)arg1;
- (void)configureViews;
- (void)addHostIDs:(id)arg1;
- (void)unsubscribeToCanSupportVMCreationNotification;
- (void)subscribeToCanSupportVMCreationNotification;
- (double)widthForTextField:(id)arg1 value1:(id)arg2 value2:(id)arg3;
- (id)dlgMgr;
- (void)closeView;
- (void)awakeFromNib;
- (void)dealloc;
- (BOOL)GetCanSupportVMCreation;
- (id)initWithInventoryNode:(id)arg1;

// Remaining properties
@property(retain, nonatomic) DUIInventoryNode *node;

@end

