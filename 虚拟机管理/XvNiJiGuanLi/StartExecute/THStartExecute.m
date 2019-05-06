//
//  THStartExecute.m
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/6.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import "THStartExecute.h"
#import "WuMaReqsut.h"
#import "VMConfigurationEditing.h"
#import "PLVMDiskCleanupManager.h"
#import "PLInventoryDeleteHelper.h"
#import "DUIOpenedVM.h"
#import "DUIInventory.h"
#import "THConfigure.h"
#import "PLInventoryWindowController.h"
#import "Aspects.h"
#import "DUIDlgMgr.h"

@interface THStartExecute()
@property (assign,nonatomic) BOOL isZanTing;
@property (strong,nonatomic) NSWindow *window;
@property (strong,nonatomic) NSTimer *snapshotTimer;
@property (strong,nonatomic) PLVMSnapshotNodeView *snapshotNodeView;
@property (strong,nonatomic) PLVMSnapshotViewController *snapshotViewController;
@property (strong,nonatomic) PLVMSnapshotWindowController *snapshotWindowController;
@property (strong,nonatomic) THStartExecuteWindowController *startExecuteWindowController;
@property (strong,nonatomic) PLInventoryWindowController *inventoryWindowController;
@end

@implementation THStartExecute
//PLInventoryManager
+ (instancetype)shared {
    static THStartExecute *_sharedSingleton = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        //不能再使用alloc方法
        
        //因为已经重写了allocWithZone方法，所以这里要调用父类的分配空间的方法
        _sharedSingleton =  [[THStartExecute alloc] init];
        _sharedSingleton.vmItems = [NSMutableArray arrayWithCapacity:50];
        _sharedSingleton.wuMaReqsut = [[WuMaReqsut alloc] init];
        _sharedSingleton.wuMaReqsut.shBaiMaxCount = 1;
        [_sharedSingleton updateFolderNodes];
        
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            
            PLSessionMgr *sessionMgr = [NSClassFromString(@"PLSessionMgr") sharedSessionMgr];
            [sessionMgr showLibrarySessionWithInventory:nil];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                
                _sharedSingleton.startExecuteWindowController = [[THStartExecuteWindowController alloc] initWithWindowNibName:@"THStartExecuteWindowController" tartExecute:_sharedSingleton];
                
                [_sharedSingleton updateFolderNodes];
                _sharedSingleton.startExecuteWindowController.vmItem = _sharedSingleton.vmItems.firstObject;
                
                [sessionMgr showSnapshotsForVMWithID:_sharedSingleton.startExecuteWindowController.vmItem.node.vmID];
                
                _sharedSingleton.snapshotTimer = [NSTimer scheduledTimerWithTimeInterval:1 target:_sharedSingleton selector:@selector(dldsmvnfknvfdkvf) userInfo:nil repeats:YES];
                
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                    [_sharedSingleton.startExecuteWindowController showWindow:_sharedSingleton.startExecuteWindowController.window];
                    [_sharedSingleton searchSanPLInventoryWindowProvider];
                });
                
                [self HookLogx:@"显示 我的win"];
            });
        });
    });
    return _sharedSingleton;
}

-(void)dldsmvnfknvfdkvf {
    
    [self.inventoryWindowController.window.sheets enumerateObjectsUsingBlock:^(__kindof NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSLog(@"弹框=%@",obj.delegate);
        
        if([obj.delegate isKindOfClass:[NSAlert class]]) {
            NSAlert *alert = obj.delegate;
            if (alert.buttons.count == 3) {
                [alert.buttons enumerateObjectsUsingBlock:^(NSButton * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    if(obj.tag == NSAlertThirdButtonReturn) {
                        [alert performSelector:@selector(buttonPressed:) withObject:obj];
                    }
                    NSLog(@"alert-buton-title=%@,tag=%ld",obj.title,obj.tag);
                }];
            } else if (alert.buttons.count == 1) {
                [alert performSelector:@selector(buttonPressed:) withObject:alert.buttons.firstObject];
            }
        }
    }];
    
}

-(void)searchSanPLInventoryWindowProvider {
    
    [[[NSApplication sharedApplication] windows] enumerateObjectsUsingBlock:^(NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if ([obj.delegate isKindOfClass:NSClassFromString(@"PLInventoryWindowProvider")]) {
            // NSLog(@"要找的-obj.delegate=%@",[obj.delegate performSelector:@selector(windowController)]);
            self.inventoryWindowController = [obj.delegate performSelector:@selector(windowController)];
            //NSLog(@"要找的-xx.activeViewController=%@",[xx performSelector:@selector(activeViewController)]);
            //NSLog(@"要找的-xx.activeViewController.selectedNodes=%@",[[xx performSelector:@selector(activeViewController)] performSelector:@selector(selectedNodes)]);
            NSLog(@"找到了");
        }
    }];
    
    if (self.inventoryWindowController == nil) {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [self searchSanPLInventoryWindowProvider];
        });
    }
    
}


-(void)updateFolderNodes {
    
    PLInventoryManager *inventoryManager = [NSClassFromString(@"PLInventoryManager") defaultInventoryManager];
    DUIInventoryFolderNode *folderNode = inventoryManager.contents.firstObject;
    NSMutableArray <THVMItem*>*vmItems = [self.vmItems mutableCopy];
    [folderNode.nodes enumerateObjectsUsingBlock:^(DUIInventoryVMNode * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        __block BOOL isContent = NO;
        
        if([[NSFileManager defaultManager] fileExistsAtPath:obj.vmID.stringValue]) {
            [vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull item , NSUInteger idx, BOOL * _Nonnull stop) {
                if ([item.stringValue isEqualToString:obj.vmID.stringValue]) {
                    item.node = obj;
                    isContent = YES;
                    *stop = YES;
                }
            }];
            if (!isContent) {
                THVMItem *item = [[THVMItem alloc] init];
                item.node = obj;
                item.name = obj.title;
                item.stringValue = obj.vmID.stringValue;
                item.powerState = obj.vm.powerState;
                [vmItems addObject:item];
            }
        } else {
            THVMItem *item = [[THVMItem alloc] init];
            item.node = obj;
            item.name = obj.title;
            item.stringValue = obj.vmID.stringValue;
            item.powerState = obj.vm.powerState;
            [self delete:@[item]];
            //[folderNode removeSingleChild:obj];
        }
    }];
    
    NSString *directory = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
    
    NSArray <NSString *>*array = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:directory error:nil];
    
    [array enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
        NSString *name = obj.stringByDeletingPathExtension;
        NSString *vmxPath = [NSString stringWithFormat:@"%@/%@/%@.vmx",directory,obj,name];
        if(![name hasPrefix:@"."] && [obj hasSuffix:@"vmwarevm"]) {
            __block BOOL isContent = NO;
            [vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull item , NSUInteger idx, BOOL * _Nonnull stop) {
                if ([item.stringValue isEqualToString:vmxPath]) {
                    isContent = YES;
                    *stop = YES;
                }
                
            }];
            if (!isContent) {
                THVMItem *item = [[THVMItem alloc] init];
                item.name = name;
                item.stringValue = vmxPath;
                item.powerState = 2;
                [vmItems addObject:item];
                
            }
        }
        
    }];
    
    self.vmItems = vmItems;
}

-(void)openItemNoOpen:(THVMItem*)selectItem block:(void(^)(void))block {
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSMutableArray <THVMItem*>*vmItems = [self.vmItems mutableCopy];
    
    __block THVMItem *item;
    
    [vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if([fileManager fileExistsAtPath:obj.stringValue]  &&  (obj.node == nil || obj.powerState != 1) && selectItem != obj && obj.isOpenError == NO && obj.notOpen == NO && obj.erciqidong == 0) {
            item = obj;
            *stop = YES;
        }
//        } else {
//
//            NSLog(@"stringValue=%hhd",[fileManager fileExistsAtPath:obj.stringValue]);
//            NSLog(@"stringValue=%d",(obj.node == nil || obj.powerState != 1));
//            NSLog(@"obj.isOpenError=%hhd",obj.isOpenError);
//            NSLog(@"obj.notOpen=%hhd",obj.notOpen);
//            NSLog(@"\r\r");
//        }
    }];
    
    [[self class] HookLogx:[NSString stringWithFormat:@"打开item=%@",item]];
    
    if (item == nil) {
        block();
        return;
    }
    
    static dispatch_queue_t openNOdeleT;
    
    if (openNOdeleT == nil) {
        openNOdeleT = dispatch_queue_create("openNOdeleT", DISPATCH_QUEUE_CONCURRENT);
    }
    
    void(^openNOdel)(void) = ^{
        [[NSWorkspace sharedWorkspace] openFile:item.stringValue];
//        DUIController *duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
//        [duiController runVMsForURLs:@[[NSURL fileURLWithPath:item.stringValue]]];
        item.powerState = 1;
        [[self class] HookLogx:[NSString stringWithFormat:@"item.stringValue=%@",item.stringValue]];
        [[self class] HookLogx:[NSString stringWithFormat:@"执行打开"]];
        
        dispatch_async(openNOdeleT, ^{
            
            int maxNodeCount = 15;
            while (item.node == nil && maxNodeCount >= 0) {
                sleep(1);
                // dispatch_sync(dispatch_get_main_queue(), ^{
                
                PLInventoryManager *inventoryManager = [NSClassFromString(@"PLInventoryManager") defaultInventoryManager];
                DUIInventoryFolderNode *folderNode = inventoryManager.contents.firstObject;
                NSArray <DUIInventoryVMNode*>*nodes = [folderNode.nodes mutableCopy];
                [nodes enumerateObjectsUsingBlock:^(DUIInventoryVMNode * _Nonnull vmNode, NSUInteger idx, BOOL * _Nonnull stop) {
                    if ([vmNode.vmID.stringValue isEqualToString:item.stringValue]) {
                        item.node = vmNode;
                        *stop = YES;
                    }
                }];
                //   });
                
                maxNodeCount -= 1;
                [[self class] HookLogx:[NSString stringWithFormat:@"查找 node"]];
            }
            
            int maxCount = 10;
            while (item.node.vm.powerState != 1 && maxCount >= 0) {
                sleep(1);
                maxCount -= 1;
                [[self class] HookLogx:[NSString stringWithFormat:@"查找 node.vm.powerState"]];
            }
            if(item.node.vm.powerState != 1 || item.node == nil) {
                item.isOpenError = YES;
                item.powerState = 2;
                [self delete:@[item]];
            } else {
                [item saveOpenJiLu];
            }
            
            [[self class] HookLogx:[NSString stringWithFormat:@"打开完成"]];
            block();
        });
    };
    
    if([item resetCount] > 0) {
        openNOdel();
    } else {
        [self.wuMaReqsut reqsut:^(NSMutableArray<BrushCode *> *brushCodes) {
            BrushCode *brushCode = brushCodes.firstObject;
            if (brushCode != nil) {
                NSString *name = [[[item.stringValue stringByDeletingLastPathComponent] lastPathComponent] stringByDeletingPathExtension];
                item.brushCode = brushCode;
                [VMConfigurationEditing configurationEditing:brushCode macAss:name VMConfigurationPath:item.stringValue];
                openNOdel();
                [self.wuMaReqsut updateXuNiJiCode:name ID:[brushCode.ID stringValue] maxErrorCount:10];
//                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//
//                });
            } else {
                block();
            }
        }];
    }
    
}

-(void)selectNode:(DUIInventoryVMNode *)node {
    PLSessionMgr *sessionMgr = [NSClassFromString(@"PLSessionMgr") sharedSessionMgr];
    [sessionMgr showSnapshotsForVMWithID:node.vmID];
}
static NSLock *lock;
static dispatch_queue_t deleT;
static dispatch_semaphore_t lockDeleta;
-(void)delete:(NSArray<THVMItem*> *)items {
    return;
    if (items.count == 0) { return; }
    if (lock == nil) {
        lock = [[NSLock alloc] init];
    }
    if (deleT == nil) {
       deleT = dispatch_queue_create("SDDSSD", DISPATCH_QUEUE_CONCURRENT);
    }
    if(lockDeleta == nil) {
        lockDeleta = dispatch_semaphore_create(1);
    }

    dispatch_async(deleT, ^{
        //[lock lock];
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
           
            NSMutableArray *deletes = [NSMutableArray arrayWithCapacity:items.count];
            
            [items enumerateObjectsUsingBlock:^(THVMItem * _Nonnull item, NSUInteger idx, BOOL * _Nonnull stop) {
                if (item.node && item.isRemove == NO) {
                    item.isRemove = YES;
                    [deletes addObject:item.node];
                } else if (item.node == nil || item.isRemove == NO ){
                    item.isRemove = YES;
                    [item claer];
                    NSString *path = [item.stringValue stringByDeletingLastPathComponent];
                    [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
                }
            }];
            
            NSLog(@"删除失败=%@",deletes);
            if (deletes.count > 0) {
                
                // PLInventoryManager *inventoryManager = [NSClassFromString(@"PLInventoryManager") defaultInventoryManager];
                // DUIInventoryFolderNode *folderNode = inventoryManager.contents.lastObject;
                //[folderNode removeSingleChild:item.node];
                // [[NSFileManager defaultManager] removeItemAtPath:[item.stringValue stringByDeletingLastPathComponent] error:nil];
                NSLog(@"删除失败开始删除");
                NSArray *ind = deletes;
                // [self.inventoryWindowController.inventoryResponder ]
                
                
                PLInventoryDeleteHelper *inventoryDeleteHelper = [[NSClassFromString(@"PLInventoryDeleteHelper") alloc] initWithNodes:ind treeController:self.inventoryWindowController.treeController dlgMgr:self.inventoryWindowController.dlgMgr delegate:self.inventoryWindowController.inventoryResponder abortHandler:^{
                    NSLog(@"删除失败");
                   // [lock unlock];
                    dispatch_semaphore_signal(lockDeleta);
                } doneHandler:^{
                    NSLog(@"成功删除");
                   // [lock unlock];
                    dispatch_semaphore_signal(lockDeleta);
                }];
                
                // DUIDlgMgr *dlgMgr = [(id)[inventoryDeleteHelper dlgMgr] object];
                [inventoryDeleteHelper start];
               // [inventoryDeleteHelper processState:1];
                
                [items enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    [obj claer];
                }];
            } else {
                //[lock unlock];
                dispatch_semaphore_signal(lockDeleta);
            }
        });
        dispatch_semaphore_wait(lockDeleta, 0);
    });
}

-(int)folderNodeCount {
    
    PLInventoryManager *inventoryManager = [NSClassFromString(@"PLInventoryManager") defaultInventoryManager];
    DUIInventoryFolderNode *folderNode = inventoryManager.contents.firstObject;
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSMutableArray <THVMItem*>*vmItems = [self.vmItems mutableCopy];
    
    [self.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if (![fileManager fileExistsAtPath:obj.stringValue] && obj.isGangOpen == NO) {
            [obj claer];
            [vmItems removeObject:obj];
        }
    }];
    self.vmItems = vmItems;
    
    if (folderNode.nodes.count != self.vmItems.count) {
        [self updateFolderNodes];
    }
    return (int)self.vmItems.count;
}

-(int)folderNodeRunCount {
    PLInventoryManager *inventoryManager = [NSClassFromString(@"PLInventoryManager") defaultInventoryManager];
    DUIInventoryFolderNode *folderNode = inventoryManager.contents.firstObject;
    if (folderNode.nodes.count != self.vmItems.count) {
        [self updateFolderNodes];
    }
    __block int runVMNumber = 0;
    [self.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        obj.powerState = obj.node.vm.powerState;
        if (obj.powerState == 1) {
            runVMNumber += 1;
        }
    }];
    
    return runVMNumber;
}

-(NSArray<NSString *>*)snapshotNames:(DUIInventoryVMNode *)vmNode {
    
    NSArray <DUISnapshot*>*snapshots = vmNode.vm.snapshotTree.snapshots;
    NSMutableArray *snapshotNames = [NSMutableArray arrayWithCapacity:snapshots.count];
    [snapshots enumerateObjectsUsingBlock:^(DUISnapshot * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        [snapshotNames addObject:[obj displayName]];
    }];
    [[self  class] HookLogx:[NSString stringWithFormat:@"snapshotNames=%@",snapshotNames]];
    [snapshotNames insertObject:@"当前状态" atIndex:0];
    return snapshotNames;
}

-(void)createCloneLinked:(DUIInventoryVMNode *)vmNode
            snapshotName:(NSString*)snapshotName
                linkName:(NSString *)linkName
                   block:(void(^)(void))block {
    
    PLVMController *lvmController = [[NSClassFromString(@"PLVMController") alloc] initWithVMID:vmNode.vmID];
    PLSnapshotController *snapshotController = lvmController.vm.snapshotController;
    __block DUISnapshot *snapshot;
    [vmNode.vm.snapshotTree.snapshots enumerateObjectsUsingBlock:^(DUISnapshot *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if ([obj.displayName isEqualToString:snapshotName]) {
            snapshot = obj;
            *stop = YES;
            [[self  class] HookLogx:[NSString stringWithFormat:@"找到了哈哈snapshot.uid=%@",snapshot.uid]];
        }
        [[self  class] HookLogx:[NSString stringWithFormat:@"找到了哈哈obj.displayName=%@,snapshotName=%@",obj.displayName,snapshotName]];
    }];
    
    [[self  class] HookLogx:[NSString stringWithFormat:@"找到了哈哈vmNode.vm.snapshotTree.snapshots=%@",vmNode.vm.snapshotTree.snapshots]];
    
    DUISnapshotUID *uid = snapshot.uid;
    
    if(snapshot == nil && [snapshotName isEqualToString:@"当前状态"] == false) {
        [[self  class] HookLogx:[NSString stringWithFormat:@"错误创建"]];
        return;
    } else {
        uid = [[NSClassFromString(@"DUISnapshotUID") alloc] initWithUID:0];
    }
    
    [snapshotController setCloneType:0x0];
    [snapshotController setCloneUID:uid];
    
    [[self  class] HookLogx:[NSString stringWithFormat:@"snapshot.uid=%@",uid]];
    
    NSString *directory = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
    
    NSSavePanel*  panel = [NSSavePanel savePanel];
    [panel setNameFieldStringValue:linkName];
    // [panel setMessage:@"Choose the path to save the document"];
    [panel setAllowsOtherFileTypes:YES];
    //[panel setAllowedFileTypes:@[@"onecodego"]];
    [panel setExtensionHidden:YES];
    [panel setCanCreateDirectories:YES];
    [panel setDirectoryURL:[NSURL fileURLWithPath:directory]];
    
    [[snapshotController savePanelAccessory] savePanelDidEnd:panel];
    [[snapshotController vm] decrementCuiBusyCount];
    
    NSString *path = [directory stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.vmwarevm",linkName]];
    ///Users/apple/Desktop/macOS1012_parent_05.vmwarevm
    [[self class] HookLogx:[NSString stringWithFormat:@"path=%@",path]];
    
    [snapshotController setBundlePath:path];
    NSString *pathName = [path lastPathComponent];
    NSString *name = [pathName stringByDeletingPathExtension];
    NSString *pathExtension = [name stringByAppendingPathExtension:@"vmx"];
    NSString *baoPath = [path stringByAppendingPathComponent:pathExtension];
    
    [snapshotController setCloneType:0x0];
    [snapshotController setCloneUID:snapshot.uid];//
    
    [snapshotController savePanelAccessory];
    [snapshotController duiWeakRef];
    
    //    [snapshotController savePanelDidEnd:panel returnCode:1];
    //    DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
    //    PLVMController *plvmController = [NSClassFromString(@"PLVMController") controllerForVMWithID:snapshotTree.vm.uid];
    //    [plvmController openVMWithDlgMgr:snapshotTree.vm.dlgMgr abortHandler:^{
    //        [[self class] HookLogx:@"创建失败"];
    //    } doneHandler:^{
    //        [[self class] HookLogx:@"创建成功"];
    //    }];
    
    //    void(^blockx)(void) = ^{
    //
    //        dispatch_async(dispatch_get_global_queue(0, 0), ^{
    //            __block BOOL isWeChuXian = YES;
    //            while (isWeChuXian) {
    //
    //                PLInventoryManager *inventoryManager = [NSClassFromString(@"PLInventoryManager") defaultInventoryManager];
    //                DUIInventoryFolderNode *folderNode = inventoryManager.contents.firstObject;
    //
    //                [folderNode.nodes enumerateObjectsUsingBlock:^(DUIInventoryVMNode * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //                    [[self class] HookLogx:[NSString stringWithFormat:@"新的 %@---%@",obj.title,linkName]];
    //                    if ([obj.title isEqualToString:linkName]) {
    //                        isWeChuXian = NO;
    //
    //                        [self.wuMaReqsut reqsut:^(NSMutableArray<BrushCode *> *brushCodes) {
    //                            BrushCode *brushCode = brushCodes.firstObject;
    //                            if (brushCode != nil) {
    //
    //                                dispatch_async(dispatch_get_main_queue(), ^{
    //
    //                                    DUIController * duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
    //
    //                                    DUIVMActionController * rax = [duiController performSelector:@selector(actionControllerForVMWithNode:) withObject:obj];
    //
    //                                    //BrushCode *brushCode = [[BrushCode alloc] initWithRom:@"AC293AE25E35" mlb:@"C07537502F1F1YLEF" serialNumber:@"W80JH1F9DHJX" boardID:@"Mac-942B5BF581941519" model:@"iMac12,1" ID:@1];
    //
    //                                    [VMConfigurationEditing configurationEditing:brushCode VMConfigurationPath:obj.vmID.stringValue];
    //
    //
    //                                    [rax vmTogglePowerOnOffSuspend:obj];
    //                                    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    //                                        // [rax vmPowerOff:obj];
    //                                        // item.powerState = 2;
    //                                        [self.startExecuteWindowController update];
    //                                    });
    //                                    [self.startExecuteWindowController update];
    //
    //                                });
    //
    //                            }
    //                        }];
    //
    //                        //[self.wuMaReqsut sta]
    //                       // [self.wuMaReqsut xx];
    //
    ////                        [rax vmTogglePowerOnOffSuspend:obj];
    ////                        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    ////                            [rax vmPowerOff:obj];
    ////                            // item.powerState = 2;
    ////                            [self.startExecuteWindowController update];
    ////                        });
    ////                        [self.startExecuteWindowController update];
    //
    //                        [[self class] HookLogx:[NSString stringWithFormat:@"vmNode.vm.vmPath=%@,stringv=%@",obj.vm.vmPath,obj.vmID.stringValue]];
    //
    //                        *stop = YES;
    //                    }
    //                }];
    //                sleep(1);
    //            }
    //            if (block != nil) {
    //
    ////
    ////                DUIController * duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
    ////                [duiController runVMsForURLs:@[[NSURL fileURLWithPath:vmNode.vm.vmPath]]];
    ////
    ////
    //                block();
    //            }
    //
    //        });
    //    };
    //    blockx();
    
    DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
    [snapshotTree cloneSnapshotWithUID:snapshot.uid cloneType:0x0 displayName:name cfgFile:baoPath abortHandler:^{
        [[self class] HookLogx:@"创建错误"];
        dispatch_async(dispatch_get_main_queue(), ^{
            block();
        });
    } doneHandler:^{
        [[self class] HookLogx:@"全部完成"];
        [[self class] HookLogx:[NSString stringWithFormat:@"创建完成 %@",baoPath]];
        
        THVMItem *vmItem = [[THVMItem alloc] init];
        vmItem.powerState = 2;
        vmItem.stringValue = baoPath;
        vmItem.name = name;
        vmItem.notOpen = NO;
        [self.vmItems addObject:vmItem];
        dispatch_async(dispatch_get_main_queue(), ^{
            block();
        });
    } snapshotDoneHandler:^{
        [[self class] HookLogx:@"快照处理成功"];
    } progressHandler:nil];
    
    
    //  [snapshotController savePanelDidEnd:panel returnCode:1];
    
    
    
    return;
    
    //  DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
    //    [snapshotTree cloneSnapshotWithUID:snapshot.uid cloneType:0x0 displayName:name cfgFile:baoPath abortHandler:^{
    //        [[self class] HookLogx:@"创建错误"];
    //    } doneHandler:^{
    //        [[self class] HookLogx:@"全部完成"];
    //
    //        PLVMController *plvmController = [NSClassFromString(@"PLVMController") controllerForVMWithID:snapshotController.vm.uid];
    //
    //        [plvmController openVMWithDlgMgr:vmNode.vm.dlgMgr abortHandler:^{
    //            [[self class] HookLogx:@"创建失败"];
    //        } doneHandler:^{
    //            [[self class] HookLogx:@"创建成功"];
    //
    //            id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
    //            id inventoryVMNode = [[duiController performSelector:@selector(allLocalVMNodes)] lastObject];
    //
    //
    //
    //            DUIVMActionController * rax = [duiController performSelector:@selector(actionControllerForVMWithNode:) withObject:inventoryVMNode];
    //
    //            //DUIInventoryVMNode
    //            if ([[inventoryVMNode valueForKey:@"isClone"] boolValue]) {
    //                [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d是克隆机",rax.powerState]];
    //            } else {
    //                [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d不是克隆机",rax.powerState]];
    //            }
    //
    //            [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d",rax.powerState]];
    //
    //            [rax vmTogglePowerOnOffSuspend:inventoryVMNode];
    //
    //            [[self class] HookLogx:[NSString stringWithFormat:@"我尝试了打开=%@",rax.vm.name]];
    //
    //
    //            //                THVMItem *item = [[THVMItem alloc] init];
    //            //                item.actionController = rax;
    //            //                item.node = inventoryVMNode;
    //            //                item.powerState = 1;
    //            //                [self.vmItems addObject:item];
    //
    //            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    //
    //                [rax vmPowerOff:inventoryVMNode];
    //                // item.powerState = 2;
    //                [self.startExecuteWindowController update];
    //            });
    //
    //            if (block != nil) {
    //                block();
    //            }
    //
    //        }];
    //
    //    } snapshotDoneHandler:^{
    //        [[self class] HookLogx:@"快照处理成功"];
    //    } progressHandler:nil];
    //
}

-(void)createCloneLinked:(NSString *)linkName block:(void(^)(void))block {
    
    if (self.snapshotNodeView == nil) {
        return;
    }
    
    [self.snapshotViewController endEditing];
    id node = [[self.snapshotViewController selectedSnapshots] lastObject];
    [[self class] HookLogx:[NSString stringWithFormat:@"克隆Node=%@",node]];
    PLSnapshotController * snapshotController = self.snapshotViewController.vmController.vm.snapshotController;
    
    
    
    id uid = [node performSelector:@selector(uid)];
    [snapshotController setCloneType:0x0];
    [snapshotController setCloneUID:uid];
    
    NSString *directory = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
    
    NSSavePanel*    panel = [NSSavePanel savePanel];
    [panel setNameFieldStringValue:linkName];
    // [panel setMessage:@"Choose the path to save the document"];
    [panel setAllowsOtherFileTypes:YES];
    //[panel setAllowedFileTypes:@[@"onecodego"]];
    [panel setExtensionHidden:YES];
    [panel setCanCreateDirectories:YES];
    [panel setDirectoryURL:[NSURL fileURLWithPath:directory]];
    
    [[snapshotController savePanelAccessory] savePanelDidEnd:panel];
    [[snapshotController vm] decrementCuiBusyCount];
    
    NSString *path = [directory stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.vmwarevm",linkName]];
    ///Users/apple/Desktop/macOS1012_parent_05.vmwarevm
    [[self class] HookLogx:[NSString stringWithFormat:@"path=%@",path]];
    
    [snapshotController setBundlePath:path];
    NSString *pathName = [path lastPathComponent];
    NSString *name = [pathName stringByDeletingPathExtension];
    NSString *pathExtension = [name stringByAppendingPathExtension:@"vmx"];
    NSString *baoPath = [path stringByAppendingPathComponent:pathExtension];
    
    [snapshotController setCloneType:0x0];
    [snapshotController setCloneUID:uid];
    // [[snapshotController savePanelAccessory] ]
    
    [snapshotController savePanelAccessory];
    [snapshotController duiWeakRef];
    
    DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
    [snapshotTree cloneSnapshotWithUID:uid cloneType:0x0 displayName:name cfgFile:baoPath abortHandler:^{
        [[self class] HookLogx:@"创建错误"];
    } doneHandler:^{
        [[self class] HookLogx:@"全部完成"];
    } snapshotDoneHandler:^{
        [[self class] HookLogx:@"快照处理成功"];
    } progressHandler:nil];
    
    return;
    
    id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
    id inventoryVMNode = [[duiController performSelector:@selector(allLocalVMNodes)] lastObject];
    
    [snapshotController savePanelDidEnd:panel returnCode:1];
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(10 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        
        DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
        PLVMController *plvmController = [NSClassFromString(@"PLVMController") controllerForVMWithID:snapshotTree.vm.uid];
        
        [plvmController openVMWithDlgMgr:snapshotTree.vm.dlgMgr abortHandler:^{
            [[self class] HookLogx:@"创建失败"];
        } doneHandler:^{
            [[self class] HookLogx:@"创建成功"];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                
                id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
                id inventoryVMNode = [[duiController performSelector:@selector(allLocalVMNodes)] lastObject];
                
                DUIVMActionController * rax = [duiController performSelector:@selector(actionControllerForVMWithNode:) withObject:inventoryVMNode];
                
                //DUIInventoryVMNode
                if ([[inventoryVMNode valueForKey:@"isClone"] boolValue]) {
                    [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d是克隆机",rax.powerState]];
                } else {
                    [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d不是克隆机",rax.powerState]];
                }
                
                [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d",rax.powerState]];
                
                [rax vmTogglePowerOnOffSuspend:inventoryVMNode];
                
                [[self class] HookLogx:[NSString stringWithFormat:@"我尝试了打开=%@",rax.vm.name]];
                
                
                //                THVMItem *item = [[THVMItem alloc] init];
                //                item.actionController = rax;
                //                item.node = inventoryVMNode;
                //                item.powerState = 1;
                //                [self.vmItems addObject:item];
                
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                    
                    [rax vmPowerOff:inventoryVMNode];
                    // item.powerState = 2;
                    [self.startExecuteWindowController update];
                });
                
                if (block != nil) {
                    block();
                }
                
            });
        }];
        
    });
    
    
    
}

+(void)VMs {
    NSString *path = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
    
    NSFileManager *fileManager = [NSFileManager defaultManager];
    
    [fileManager contentsOfDirectoryAtPath:path error:nil];
    
    
    
}

+(void)load {
    
    HookLog(@"加载成功了");
    //highlighted NSMenuItem
    [NSClassFromString(@"NSButton") HookMouseDown];
    THStartExecute *shared = [self shared];
    
    [NSClassFromString(@"PLInventoryDeleteHelper")  initWithNodesTreeController];
    
    
    //    initWithNodesxxx Nodes=(
    //                            "<DUIInventoryVMNode: 0x7ff39301e5f0> {Inventory = <DUILocalInventory: 0x7ff38eedfa60> {ID = user}, IsClone = YES, State = Normal, VMID = <DUIVMID: 0x7ff391d8a940> {StringValue = \"/Users/apple/VM/cvb.vmwarevm/cvb.vmx\", AdaptedVMID = 0x0x7ff391d8a948 (0x7ff391112dd0)}}"
    //                            )--treeController=<VMTreeArrayController: 0x7ff39124aef0>[object class: DUIInventoryNode],dlgMgr=<DUIDlgMgr: 0x7ff3918bdff0> {hasDialog = NO, hasProgress = NO, isSuspended = NO},delegate=<PLInventoryResponder: 0x7ff391261630>
    
    // shared.snapshotTimer = [NSTimer scheduledTimerWithTimeInterval:1 target:shared selector:@selector(scanningsnapshotWindowController) userInfo:nil repeats:YES];
    
    //    [NSClassFromString(@"DUISnapshotTree") aspect_hookSelector:@selector(cloneSnapshotWithUID:cloneType:displayName:cfgFile:abortHandler:doneHandler:snapshotDoneHandler:progressHandler:) usingBlock:^(id info, id sender) {
    //
    //            [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //                HookLog(@"快照相关 参数=%@,index=%ld",obj,idx);
    //            }];
    //            HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //        }];
    //
    //    PLInventoryDeleteHelper
    //        [NSClassFromString(@"PLInventoryDeleteHelper") aspect_hookSelector:@selector(deleteNodes:fromTreeController:dlgMgr:delegate:abortHandler:doneHandler:) usingBlock:^(id info, id sender) {
    //
    //                [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //                    HookLog(@"快照相关 参数=%@,index=%ld",obj,idx);
    //                }];
    //                HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //            }];
    //
    
    return;
    
    //    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(9 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    //
    //        [self statr];
    //
    //    });
    //
    
    
    //    [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:@selector(selectedSnapshots) usingBlock:^(id info, id sender) {
    //
    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinked",idx,[obj class],obj,[obj superclass]);
    //        }];
    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //    }];
    //
    //
    //    [NSClassFromString(@"PLController") aspect_hookSelector:@selector(actionControllerForVMWithID:) usingBlock:^(id info, id sender) {
    //
    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinked",idx,[obj class],obj,[obj superclass]);
    //        }];
    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //    }];
    //
    //    [NSClassFromString(@"DUISnapshotUID") aspect_hookSelector:@selector(plistRepresentation) usingBlock:^(id info, id sender) {
    //
    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinked",idx,[obj class],obj,[obj superclass]);
    //        }];
    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //    }];
    //
    //
    //    [NSClassFromString(@"PLVMActionController") aspect_hookSelector:@selector(createCloneLinked:) usingBlock:^(id info, id sender) {
    //
    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinked",idx,[obj class],obj,[obj superclass]);
    //        }];
    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //    }];
    //
    //    [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:@selector(onCreateCloneLinked:) usingBlock:^(id info, id sender) {
    //
    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"onCreateCloneLinked",idx,[obj class],obj,[obj superclass]);
    //        }];
    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //    }];
    //
    //    [NSClassFromString(@"PLSnapshotController") aspect_hookSelector:@selector(createCloneLinkedForSnapshot:dlgMgr:) usingBlock:^(id info, id sender) {
    //
    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinkedForSnapshot",idx,[obj class],obj,[obj superclass]);
    //        }];
    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //    }];
    //
    //    [NSClassFromString(@"PLInventoryResponder") aspect_hookSelector:@selector(onCreateCloneLinked:) usingBlock:^(id info, id sender) {
    //
    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"onCreateCloneLinked",idx,[obj class],obj,[obj superclass]);
    //        }];
    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //    }];
    
    //- (id)initWithVMID:(id)arg1 node:(id)arg2;
    
    //struct VMID
    
    
    
    
    id cccc = [NSClassFromString(@"DUIVMID") performSelector:@selector(vmidForLocalVMWithConfigPath:) withObject:@"/Users/apple/Desktop/macOS1012_parent_05.vmwarevm/macOS1012_parent_05.vmx"];
    
    [self HookLogx:[NSString stringWithFormat:@"vmidForLocalVMWithConfigPath=%@",cccc]];
    
    //  id adaptorBase = [[NSClassFromString(@"DUIAdaptorBase") alloc] init];
    
    id actionController = [[NSClassFromString(@"PLVMActionController") alloc] initWithVMID:cccc node:nil];
    
    
    [actionController performSelector:@selector(showSnapshots:) withObject:nil];
    
    [NSClassFromString(@"PLVMActionController") aspect_hookSelector:@selector(showSnapshots:) usingBlock:^(id info, id sender) {
        
        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            
            if ([obj isKindOfClass:[NSMenuItem class]]) {
                NSMenuItem *b = obj;
                [self HookLogx:[NSString stringWithFormat:@"PLVMActionController-target=%@,action=%@",b.target,NSStringFromSelector(b.action)]];
            }
            
            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"showSnapshots",idx,[obj class],obj,[obj superclass]);
        }];
        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
        
    }];
    
    [self HookLogx:[NSString stringWithFormat:@"actionController=%@",actionController]];
    
    NSArray<NSString *> *vv =  [NSClassFromString(@"PLVMSnapshotViewController") propertyList];
    [self HookLogx:[NSString stringWithFormat:@"%@",vv]];
    //    [[NSClassFromString(@"PLVMSnapshotViewController") funcList] enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //
    //        [self HookLogx:obj];
    //
    //        if (![vv containsObject:obj]) {
    //
    //            if ([NSClassFromString(@"PLVMSnapshotViewController") respondsToSelector:NSSelectorFromString(obj)]) {
    //
    //                [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:NSSelectorFromString(obj) usingBlock:^(id info, id sender) {
    //
    //                    [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //                        HookLog(@"快照 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"actionControllerForVMWithID",idx,[obj class],obj,[obj superclass]);
    //                    }];
    //                    HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //                }];
    //
    //            } else if ([[[NSClassFromString(@"PLVMSnapshotViewController") alloc] init] respondsToSelector:NSSelectorFromString(obj)]) {
    //
    //                [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:NSSelectorFromString(obj) usingBlock:^(id info, id sender) {
    //
    //                    [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //                        HookLog(@"快照 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"actionControllerForVMWithID",idx,[obj class],obj,[obj superclass]);
    //                    }];
    //                    HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //
    //                }];
    //
    //            }
    //        }
    //
    //    }];
    //PLWindowProvider
    
    
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        
        [[[NSApplication sharedApplication] windows] enumerateObjectsUsingBlock:^(NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            
            [self HookLogx:[NSString stringWithFormat:@"文斗%@",obj.windowController]];
            
        }];
        
    });
    
}


+(void)statr {
    
    [[[[NSApplication sharedApplication] mainMenu] itemArray] enumerateObjectsUsingBlock:^(NSMenuItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
        [self HookLogx:obj.title];
        
        if ([obj.title isEqualToString:@"虚拟机"]) {
            
            [[[obj submenu] itemArray] enumerateObjectsUsingBlock:^(NSMenuItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                
                [self HookLogx:obj.title];
                if([obj.title hasPrefix:@"快照"]) {
                    
                    [[[obj submenu] itemArray] enumerateObjectsUsingBlock:^(NSMenuItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                        
                        [self HookLogx:obj.title];
                        if([obj.title hasPrefix:@"快照"]) {
                            
                            [obj.target performSelector:obj.action withObject:obj];
                            
                            NSString *ff = [NSString stringWithFormat:@"target=%@,action=%@",obj.target,NSStringFromSelector(obj.action)];
                            
                            [self HookLogx:ff];
                        }
                        
                    }];
                    
                }
                
            }];
            
        }
        
        
    }];
    
    
    PLSessionMgr *sessionMgr = [NSClassFromString(@"PLSessionMgr") sharedSessionMgr];
    
    id vmid = [NSClassFromString(@"DUIVMID") vmidForLocalVMWithConfigPath:@"/Users/apple/Desktop/macOS1012_parent_05.vmwarevm/macOS1012_parent_05.vmx"];
    
    
    
    //[sessionMgr showSnapshotsForVMWithID:vmid];
    
    
    
    
    
    //    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
    //        [self HookLogx:[NSString stringWithFormat:@"a哈哈llSessions=%@",sessionMgr.allSessions]];
    //
    //        [[[NSApplication sharedApplication] windows] enumerateObjectsUsingBlock:^(NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //
    //            [self HookLogx:[NSString stringWithFormat:@"NSWindow=%@",obj.delegate]];
    //            if ([obj.delegate isKindOfClass:NSClassFromString(@"PLVMSnapshotWindowController")]) {
    //                PLVMSnapshotWindowController *snapshotWindowController = obj.delegate;
    //                [self HookLogx:[NSString stringWithFormat:@"windowNibName=%@",snapshotWindowController.windowNibName]];
    //            }
    //                //snapshotWindowController.windowNibName
    //        }];
    //
    //    });
    
    
    
    //   PLVMActionController *plvmActionController = [[NSClassFromString(@"PLVMActionController") alloc] initWithVMID:vmid node:nil];
    [sessionMgr.allSessions enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        //PLVMStartMenuManager PLLibrarySession
        if([obj isKindOfClass:NSClassFromString(@"PLVMSession")]) {
            
            //initWithWindowNibName
            PLVMSnapshotWindowController *snapshotWindowController = [[NSClassFromString(@"PLVMSnapshotWindowController") alloc] initWithSession:obj];
            
            [snapshotWindowController snapshotWindowWantsProgress];
            [snapshotWindowController showSnapshotWindow];
            [snapshotWindowController.window makeKeyWindow];
            
            [[NSClassFromString(@"PLVMSnapshotWindowController") propertyList] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                
                [self HookLogx:[NSString stringWithFormat:@"%@=%@",obj,[snapshotWindowController valueForKey:obj]]];
                
            }];
            
            PLVMSnapshotTreeView *snapshotTreeView = [snapshotWindowController.snapshotViewController valueForKey:@"snapshotTreeView"];
            
            [snapshotTreeView.nodes enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PLVMSnapshotNodeView *  _Nonnull obj, BOOL * _Nonnull stop) {
                if([obj.name isEqualToString:@"快照 2"]) {
                    [obj setIsSelected:YES];
                } else {
                    [obj setIsSelected:NO];
                }
            }];
            
            [self HookLogx:[NSString stringWithFormat:@"PLLibrarySession-snapshotTreeView.nodes%@",snapshotTreeView.nodes]];
        }
    }];
    
    return;
    
    // [snapshotWindowController showSnapshotWindow];
    /* [rbx cancelAutomaticDiskCleanup];
     [rbx duiWeakRef];
     [rbx openVMWithAbortHandler:0x0 DoneHandler:__NSConcreteStackBlock];*/
    
    //    [plvmActionController cancelAutomaticDiskCleanup];
    //    [plvmActionController duiWeakRef];
    //    [plvmActionController openVMWithAbortHandler:0x0 DoneHandler:^{
    //        [self HookLogx:@"打开了"];
    //    }];
    //    [sessionMgr openVMSessionForVMWithID:plvmActionController.vmID abortHandler:^{
    //        [self HookLogx:@"错误"];
    //    } doneHandler:^{
    //        [self HookLogx:@"打开了"];
    //    }];
    
    return;
    
    
    PLVMSnapshotViewController *vc = [[NSClassFromString(@"PLVMSnapshotViewController") alloc] init];
    
    [self HookLogx:[NSString stringWithFormat:@"selectedSnapshots=%@",[vc selectedSnapshots]]];
    
    
    
    [[NSClassFromString(@"PLVMSnapshotViewController") propertyList] enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
        [self HookLogx:[NSString stringWithFormat:@"属性%@",[vc valueForKey:obj]]];
        
    }];
    
    id actionController = [[NSClassFromString(@"PLVMActionController") alloc] init];
    
    // [actionController performSelector:@selector(showSnapshots:) withObject:nil];
    [self HookLogx:[NSString stringWithFormat:@"显示%@",actionController]];
    
    id cccc = [NSClassFromString(@"DUIVMID") performSelector:@selector(vmidForLocalVMWithConfigPath:) withObject:@"/Users/apple/Desktop/macOS1012_parent_05.vmwarevm/macOS1012_parent_05.vmx"];
    id plvmController = NSClassFromString(@"PLVMController");
    
    PLVMController * vmController = [[plvmController alloc] initWithVMID:cccc];
    
    id rdi = [[vmController valueForKey:@"vm"] performSelector:@selector(snapshotController)];
    id rdx = [[rdi valueForKey:@"cloneUID"] valueForKey:@"uid"];
    [rdi performSelector:@selector(createCloneLinkedForSnapshot:dlgMgr:) withObject:rdx withObject:nil];
    [self HookLogx:[NSString stringWithFormat:@"链接😯%@,%@",rdi,vmController]];
    
    
    [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:@selector(onCreateCloneLinked:) usingBlock:^(id info, id sender) {
        
        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if ([obj isKindOfClass:[NSMenuItem class]]) {
                NSMenuItem *b = obj;
                [self HookLogx:[NSString stringWithFormat:@"PLVMSnapshotViewController-target=%@,action=%@",b.target,NSStringFromSelector(b.action)]];
            }
            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"onCreateCloneLinked",idx,[obj class],obj,[obj superclass]);
        }];
        
        id x = [[info valueForKey:@"instance"] valueForKey:@"dlgMgr"];
        id y = [[info valueForKey:@"instance"] valueForKey:@"selectedSnapshots"];
        
        NSDictionary * nodes = [[[info valueForKey:@"instance"] valueForKey:@"snapshotTreeView"] valueForKey:@"nodes"];
        [nodes enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
            if([[obj valueForKey:@"name"] isEqualToString:@"快照 2"]) {
                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                    
                    [obj setValue:@(YES) forKey:@"isSelected"];
                    
                    id vmController = [obj valueForKey:@"vmController"];
                    
                    [self HookLogx:[NSString stringWithFormat:@"调用了vmController=%@",vmController]];
                    
                    id rdi = [[vmController valueForKey:@"vm"]
                              performSelector:@selector(snapshotController)];
                    
                    [self HookLogx:[NSString stringWithFormat:@"调用了snapshotController=%@",rdi]];
                    
                    id rdx = [[rdi valueForKey:@"cloneUID"] valueForKey:@"uid"];
                    
                    [self HookLogx:[NSString stringWithFormat:@"调用了cloneUID=%@",rdx]];
                    
                    [rdi performSelector:@selector(createCloneLinkedForSnapshot:dlgMgr:) withObject:rdx withObject:nil];
                    
                    
                    
                    
                    [self HookLogx:@"调用了"];
                    
                    //  [[info valueForKey:@"instance"] performSelector:@selector(onCreateCloneLinked:) withObject:nil];
                    
                    
                    id mage = [info valueForKey:@"instance"];
                    [mage performSelector:@selector(endEditing)];
                    id node = [[mage performSelector:@selector(selectedSnapshots)] lastObject];
                    PLSnapshotController * snapshotController = [[[mage performSelector:@selector(vmController)] performSelector:@selector(vm)] performSelector:@selector(snapshotController)];
                    //createCloneLinkedForSnapshot
                    
                    id rdxx = [node performSelector:@selector(uid)];
                    
                    [snapshotController setCloneType:0x0];
                    [snapshotController setCloneUID:rdxx];
                    
                    [NSClassFromString(@"PLSnapshotController") aspect_hookSelector:@selector(savePanelDidEnd:returnCode:) usingBlock:^(id info, id sender) {
                        
                        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                            HookLog(@"快照 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"savePanelDidEnd",idx,[obj class],obj,[obj superclass]);
                        }];
                        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
                        
                    }];
                    
                    NSSavePanel*    panel = [NSSavePanel savePanel];
                    [panel setNameFieldStringValue:@"唐海uuu"];
                    // [panel setMessage:@"Choose the path to save the document"];
                    [panel setAllowsOtherFileTypes:YES];
                    //[panel setAllowedFileTypes:@[@"onecodego"]];
                    [panel setExtensionHidden:YES];
                    [panel setCanCreateDirectories:YES];
                    [panel setDirectoryURL:[NSURL fileURLWithPath:@"/Users/apple/VM"]];
                    
                    [snapshotController savePanelDidEnd:panel returnCode:1];
                    
                    // [snapshotController createCloneForSnapshot:rdxx dlgMgr:[mage performSelector:@selector(dlgMgr)]];
                    
                    // return;
                    
                    //[snapshotController setCloneType:0];
                    
                    //[snapshotController setCloneUID:rdxx];
                    DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
                    //  [snapshotTree canCloneSnapshotWithUID:rdxx cloneType:0 error:nil];
                    
                    
                    PLVMController *plvmController = [NSClassFromString(@"PLVMController") controllerForVMWithID:snapshotTree.vm.uid];
                    
                    [plvmController openVMWithDlgMgr:snapshotTree.vm.dlgMgr abortHandler:^{
                        [self HookLogx:@"创建失败"];
                    } doneHandler:^{
                        [self HookLogx:@"创建成功"];
                    }];
                    
                    //[snapshotController performSelector:@selector(checkIfCanCloneWithDlgMgr:) withObject:[mage performSelector:@selector(dlgMgr)]];
                    
                    
                    
                    
                    /* [PLSnapshotController checkIfCanCloneWithDlgMgr:](void * self, void * _cmd, void * arg2) {
                     r14 = arg2;
                     rbx = self;
                     r12 = [[self vm] snapshotTree];
                     r8 = var_30;
                     rdx = [rbx cloneUID];
                     rcx = [rbx cloneType];
                     r12 = [r12 canCloneSnapshotWithUID:rdx cloneType:rcx error:r8];
                     if (r14 == 0x0) {
                     r14 = [[rbx vm] dlgMgr];
                     }
                     if (r12 != 0x0) {
                     rax = [rbx vm];
                     rax = [rax uid];
                     rax = [PLVMController controllerForVMWithID:rax];
                     [rax openVMWithDlgMgr:r14 abortHandler:__NSConcreteStackBlock doneHandler:__NSConcreteStackBlock];
                     }
                     else {
                     [rbx setCloneType:0x2];
                     [rbx setCloneUID:0x0];
                     rax = [NSAlert alertWithError:var_30];
                     [r14 beginAlert:rax repliedHandler:0x0];
                     }
                     return;
                     }*/
                    
                });
                
            } else {
                [obj setValue:@(NO) forKey:@"isSelected"];
            }
            
            
            [self HookLogx:[NSString stringWithFormat:@"nodesName=%@",[obj valueForKey:@"name"]]];
        }];
        
        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
        [self HookLogx:[NSString stringWithFormat:@"dlgMgr=%@,selectedSnapshots=%@,nodes=%@",x,y,nodes]];
        
        [[NSClassFromString(@"PLVMSnapshotViewController") propertyList] enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            
            [self HookLogx:[NSString stringWithFormat:@"属性%@=%@",obj,[[info valueForKey:@"instance"] valueForKey:obj]]];
            
        }];
    }];
    
    
    
    
    
    //    [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:@selector(snapshotForItem:) usingBlock:^(id info, id sender) {
    //
    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"snapshotForItem",idx,[obj class],obj,[obj superclass]);
    //        }];
    //
    //        id x = [[info valueForKey:@"instance"] valueForKey:@"dlgMgr"];
    //        id y = [[info valueForKey:@"instance"] valueForKey:@"selectedSnapshots"];
    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
    //        [self HookLogx:[NSString stringWithFormat:@"dlgMgr=%@,selectedSnapshots=%@",x,y]];
    //    }];
    
    
    //    id Session = [[NSClassFromString(@"PLWindowedSession") alloc] performSelector:@selector(initWithWindowProvider:) withObject:@1];
    //
    //    id shotWindowController = [[NSClassFromString(@"PLVMSnapshotWindowController") alloc] performSelector:@selector(initWithSession:) withObject:Session];
    //
    //    [[NSClassFromString(@"PLVMSnapshotWindowController") propertyList] enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //
    //        [self HookLogx:[NSString stringWithFormat:@"window属性%@",[shotWindowController valueForKey:obj]]];
    //
    //    }];
    //
    //    [shotWindowController performSelector:@selector(showSnapshotWindow)];
    //
    //    id shotViewControllerNew = [shotWindowController valueForKey:@"snapshotViewController"];
    //
    //    [[NSClassFromString(@"PLVMSnapshotViewController") propertyList] enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
    //
    //        [self HookLogx:[NSString stringWithFormat:@"属性%@",[shotViewControllerNew valueForKey:obj]]];
    //
    //    }];
    //
    
}

+(void)HookLogx:(NSString *)log {
    
    NSLog(@"[Plugin]%@",log);
}

@end

