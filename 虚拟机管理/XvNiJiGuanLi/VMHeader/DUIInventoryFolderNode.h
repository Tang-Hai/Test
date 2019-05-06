//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIInventoryNode.h"

@class DUIHost, NSArray,DUIInventoryVMNode;

@interface DUIInventoryFolderNode : DUIInventoryNode
{
    BOOL mIsLoaded;
}

+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
+ (id)keyPathsForValuesAffectingToolTip;
+ (id)keyPathsForValuesAffectingIsUploadFolderLeaf;
+ (id)keyPathsForValuesAffectingIsFolderLeaf;
@property(nonatomic) BOOL isLoaded; // @synthesize isLoaded=mIsLoaded;
- (void)removeSingleChild:(id)arg1;
- (void)unloadObject;
- (void)loadObject;
- (BOOL)canShutdownHost;
- (BOOL)canRebootHost;
- (BOOL)canExitMaintenanceMode;
- (BOOL)canEnterMaintenanceMode;
- (BOOL)canPerformHostOperation;
@property(readonly, nonatomic) DUIHost *host;
//- (void)didRemoveChild:(id)arg1 fromBefore:(__list_iterator_24c82087)arg2;
//- (void)willRemoveChild:(__list_iterator_24c82087)arg1;
//- (void)didAddChild:(__list_iterator_24c82087)arg1;
//- (void)willAddChild:(id)arg1 toBefore:(__list_iterator_24c82087)arg2;
- (id)targetOnlyNodesWithFilter:(unsigned long long)arg1;
@property(readonly, nonatomic) NSArray *onlyFolderNodes;
@property(readonly, nonatomic) NSArray <DUIInventoryVMNode*>*nodes;
@property(readonly, nonatomic) struct FolderNode *adaptedFolderNode;
- (id)initWithAdaptedFolderNode:(struct FolderNode *)arg1;
- (id)stateString;
- (id)toolTip;
- (id)filteredChildrenUsingPredicate:(id)arg1;
- (BOOL)isUploadFolderLeaf;
- (unsigned long long)uploadFolderNodeCount;
- (id)uploadFolderNodes;
//- (slot_87f7680d)filterSlot;
- (BOOL)isFolderLeaf;
- (unsigned long long)onlyFolderNodeCount;
- (BOOL)isLeaf;
- (unsigned long long)nodeCount;

@end

