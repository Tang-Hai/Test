//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "VMCollectionViewDelegate.h"

@class NSCollectionView, NSCollectionViewItem, NSIndexSet, NSNotification, NSString, NSTreeNode;

@protocol VMTreeCollectionViewDelegate <VMCollectionViewDelegate>

@optional
- (BOOL)collectionView:(NSCollectionView *)arg1 canShowContentsOfNode:(NSTreeNode *)arg2;
- (id)collectionView:(NSCollectionView *)arg1 itemForPersistentObject:(id)arg2;
- (id)collectionView:(NSCollectionView *)arg1 persistentObjectForItem:(id)arg2;
- (void)collectionView:(NSCollectionView *)arg1 showPreviewAtIndexes:(NSIndexSet *)arg2;
- (void)collectionView:(NSCollectionView *)arg1 selectItemMatching:(NSString *)arg2;
- (BOOL)selectionShouldChangeInCollectionView:(NSCollectionView *)arg1;
- (void)collectionViewSelectionDidChange:(NSNotification *)arg1;
- (void)collectionView:(NSCollectionView *)arg1 configureItem:(NSCollectionViewItem *)arg2 forRepresentedObject:(id)arg3;
- (NSCollectionViewItem *)collectionView:(NSCollectionView *)arg1 newItemForRepresentedObject:(id)arg2;
@end

