//
//  THStartExecute.h
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/6.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "THVMItem.h"
#import "NSObject+aspect.h"
#import "NSObject+ClasssFunc.h"
#import "PLVMSnapshotViewController.h"
#import "PLVMController.h"
#import "DUISnapshotTree.h"
#import "PLSnapshotController.h"
#import "PLVM.h"
#import "PLSessionMgr.h"
#import "PLVMActionController.h"
#import "DUIVMID.h"
#import "PLVMSnapshotWindowController.h"
#import "PLVMSnapshotTreeView.h"
#import "PLVMSnapshotNodeView.h"
#import "THStartExecuteWindowController.h"
#import "DUIInventoryVMNode.h"
#import "PLController.h"
#import "DUISnapshot.h"
#import "PLInventoryManager.h"
#import "PLImportSavePanelAccessory.h"
#import "NSObject-DUIWeakRefAdditions.h"
#import "DUIInventoryFolderNode.h"
#import "THSnapshot.h"
#import "DUISnapshotUID.h"

NS_ASSUME_NONNULL_BEGIN
@class DUIInventoryVMNode,WuMaReqsut;
@interface THStartExecute : NSObject
@property (strong,nonatomic) WuMaReqsut *wuMaReqsut;
@property (strong,nonatomic) NSMutableArray <THVMItem *> *vmItems;
-(int)folderNodeCount;
-(int)folderNodeRunCount;
-(void)openItemNoOpen:(THVMItem*)selectItem block:(void(^)(void))block;
-(void)selectNode:(DUIInventoryVMNode *)node;
-(void)delete:(NSArray<THVMItem*> *)items;
-(NSArray<NSString *>*)snapshotNames:(DUIInventoryVMNode *)vmNode;
-(void)createCloneLinked:(DUIInventoryVMNode *)vmNode
            snapshotName:(NSString*)snapshotName
                linkName:(NSString *)linkName
                   block:(void(^)(void))block;
-(void)createCloneLinked:(NSString *)linkName block:(void(^)(void))block;
@end

NS_ASSUME_NONNULL_END
