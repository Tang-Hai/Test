//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "VMAssistant.h"

#import "NSCollectionViewDataSource.h"
#import "NSCollectionViewDelegateFlowLayout.h"
#import "PLCreationHomeEntryDelegate.h"

@class NSArray, NSCollectionView, NSIndexPath, NSString, PLCreationHomePageEntry, VMDragTargetBox;

@interface PLCreationHomeAssistant : VMAssistant <NSCollectionViewDataSource, NSCollectionViewDelegateFlowLayout, PLCreationHomeEntryDelegate>
{
    VMDragTargetBox *dragTargetView;
    int _matrixTag;
    PLCreationHomePageEntry *mMainEntry;
    NSArray *mInstallEntries;
    NSCollectionView *_collectionView;
    NSIndexPath *_selection;
}

@property(retain, nonatomic) NSIndexPath *selection; // @synthesize selection=_selection;
@property(nonatomic) NSCollectionView *collectionView; // @synthesize collectionView=_collectionView;
@property(nonatomic) int matrixTag; // @synthesize matrixTag=_matrixTag;
@property(retain, nonatomic) NSArray *installEntries; // @synthesize installEntries=mInstallEntries;
@property(retain, nonatomic) PLCreationHomePageEntry *mainEntry; // @synthesize mainEntry=mMainEntry;
- (void)draggingExited:(id)arg1;
- (BOOL)performDragOperation:(id)arg1;
- (unsigned long long)draggingEntered:(id)arg1;
- (double)collectionView:(id)arg1 layout:(id)arg2 minimumInteritemSpacingForSectionAtIndex:(long long)arg3;
- (double)collectionView:(id)arg1 layout:(id)arg2 minimumLineSpacingForSectionAtIndex:(long long)arg3;
- (struct NSEdgeInsets)collectionView:(id)arg1 layout:(id)arg2 insetForSectionAtIndex:(long long)arg3;
- (struct CGSize)collectionView:(id)arg1 layout:(id)arg2 sizeForItemAtIndexPath:(id)arg3;
- (void)collectionView:(id)arg1 didSelectItemsAtIndexPaths:(id)arg2;
- (id)collectionView:(id)arg1 itemForRepresentedObjectAtIndexPath:(id)arg2;
- (long long)collectionView:(id)arg1 numberOfItemsInSection:(long long)arg2;
- (long long)numberOfSectionsInCollectionView:(id)arg1;
- (void)doubleClickEntryViewItem:(id)arg1;
- (BOOL)goForward;
- (void)showAssistantForType:(int)arg1;
- (id)creationEntryForType:(int)arg1;
- (long long)helpTag;
- (id)title;
- (void)cancel;
- (void)assistantWillUnload;
- (BOOL)start;
- (void)awakeFromNib;
- (id)initWithAssistantManager:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

