////
////  THStartExecuteNew.m
////  XvNiJiGuanLi
////
////  Created by apple on 2019/4/10.
////  Copyright © 2019年 Aiwei. All rights reserved.
////
//
//#import "THStartExecuteNew.h"
//
//#import "NSObject+aspect.h"
//#import "NSObject+ClasssFunc.h"
//#import "PLVMSnapshotViewController.h"
//#import "PLVMController.h"
//#import "DUISnapshotTree.h"
//#import "PLSnapshotController.h"
//#import "PLVM.h"
//#import "PLSessionMgr.h"
//#import "PLVMActionController.h"
//#import "DUIVMID.h"
//#import "PLVMSnapshotWindowController.h"
//#import "PLVMSnapshotTreeView.h"
//#import "PLVMSnapshotNodeView.h"
//#import "THStartExecuteWindowController.h"
//#import "DUIInventoryVMNode.h"
//#import "PLController.h"
//#import "THVMItem.h"
//#import "DUISnapshot.h"
//#import "PLInventoryManager.h"
//#import "PLImportSavePanelAccessory.h"
//#import "NSObject-DUIWeakRefAdditions.h"
//#import "DUIInventoryFolderNode.h"
//
//@interface THStartExecuteNew()
//@property (strong,nonatomic) THStartExecuteWindowController *startExecuteWindowController;
//@end
//
//@implementation THStartExecuteNew
//
//+ (instancetype)shared {
//    static THStartExecuteNew *_sharedSingleton = nil;
//    static dispatch_once_t onceToken;
//    dispatch_once(&onceToken, ^{
//        _sharedSingleton =  [[THStartExecuteNew alloc] init];
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            PLSessionMgr *sessionMgr = [NSClassFromString(@"PLSessionMgr") sharedSessionMgr];
//            [sessionMgr showLibrarySessionWithInventory:nil];
//            
//            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//                
//                _sharedSingleton.startExecuteWindowController = [[THStartExecuteWindowController alloc] initWithWindowNibName:@"THStartExecuteWindowController" tartExecute:_sharedSingleton];
//                [_sharedSingleton.startExecuteWindowController showWindow:_sharedSingleton.startExecuteWindowController.window];
//                [_sharedSingleton.startExecuteWindowController update];
//                [self HookLogx:@"显示 我的win"];
//                
//            });
//        });
//    });
//    return _sharedSingleton;
//}
//
//+(void)HookLogx:(NSString *)log {
//    
//    NSLog(@"[Plugin]%@",log);
//}
//
//
//////
//////  THStartExecute.m
//////  XvNiJiGuanLi
//////
//////  Created by apple on 2019/4/6.
//////  Copyright © 2019年 Aiwei. All rights reserved.
//////
////
////#import "THStartExecute.h"
////#import "NSObject+aspect.h"
////#import "NSObject+ClasssFunc.h"
////#import "PLVMSnapshotViewController.h"
////#import "PLVMController.h"
////#import "DUISnapshotTree.h"
////#import "PLSnapshotController.h"
////#import "PLVM.h"
////#import "PLSessionMgr.h"
////#import "PLVMActionController.h"
////#import "DUIVMID.h"
////#import "PLVMSnapshotWindowController.h"
////#import "PLVMSnapshotTreeView.h"
////#import "PLVMSnapshotNodeView.h"
////#import "THStartExecuteWindowController.h"
////#import "DUIInventoryVMNode.h"
////#import "PLController.h"
////#import "THVMItem.h"
////#import "DUISnapshot.h"
////#import "PLInventoryManager.h"
////#import "PLImportSavePanelAccessory.h"
////#import "NSObject-DUIWeakRefAdditions.h"
////#import "DUIInventoryFolderNode.h"
////
////@interface THStartExecute()
////@property (strong,nonatomic) NSWindow *window;
////@property (strong,nonatomic) NSTimer *snapshotTimer;
////@property (strong,nonatomic) NSMutableArray <THVMItem *> *vmItems;
////@property (strong,nonatomic) PLVMSnapshotNodeView *snapshotNodeView;
////@property (strong,nonatomic) PLVMSnapshotViewController *snapshotViewController;
////@property (strong,nonatomic) PLVMSnapshotWindowController *snapshotWindowController;
////@property (strong,nonatomic) THStartExecuteWindowController *startExecuteWindowController;
////@end
////
////@implementation THStartExecute
//////PLInventoryManager
////+ (instancetype)shared {
////    static THStartExecute *_sharedSingleton = nil;
////    static dispatch_once_t onceToken;
////    dispatch_once(&onceToken, ^{
////        //不能再使用alloc方法
////        //因为已经重写了allocWithZone方法，所以这里要调用父类的分配空间的方法
////        _sharedSingleton =  [[THStartExecute alloc] init];
////        _sharedSingleton.vmItems = [NSMutableArray arrayWithCapacity:50];
////        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////            
////            PLSessionMgr *sessionMgr = [NSClassFromString(@"PLSessionMgr") sharedSessionMgr];
////            [sessionMgr showLibrarySessionWithInventory:nil];
////            
////            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////                
////                _sharedSingleton.startExecuteWindowController = [[THStartExecuteWindowController alloc] initWithWindowNibName:@"THStartExecuteWindowController" tartExecute:_sharedSingleton];
////                [_sharedSingleton.startExecuteWindowController showWindow:_sharedSingleton.startExecuteWindowController.window];
////                [_sharedSingleton.startExecuteWindowController update];
////                [self HookLogx:@"显示 我的win"];
////                
////                
////                
////                
////            });
////            
////            //[sessionMgr loadInitialSessions];
////            //id vmid = [NSClassFromString(@"DUIVMID") vmidForLocalVMWithConfigPath:@"/Users/apple/Desktop/macOS1012_parent_05.vmwarevm/macOS1012_parent_05.vmx"];
////            //[sessionMgr showSnapshotsForVMWithID:vmid];
////            
////            //            PLInventoryManager *manager = [NSClassFromString(@"PLInventoryManager") defaultInventoryManager];
////            //            DUIInventoryVMNode *node = [manager.allLocalVMNodes lastObject];
////            //            [self HookLogx:[NSString stringWithFormat:@"manager=%@,allLocalVMNodes=%@",manager,manager.allLocalVMNodes]];
////            //            [self HookLogx:[NSString stringWithFormat:@"DUIInventoryVMNode-vm=%@",node.vm]];
////            //
////            //            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(4 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////            //                _sharedSingleton.startExecuteWindowController = [[THStartExecuteWindowController alloc] initWithWindowNibName:@"THStartExecuteWindowController" tartExecute:_sharedSingleton];
////            //                [_sharedSingleton.startExecuteWindowController showWindow:_sharedSingleton.startExecuteWindowController.window];
////            //
////            //                id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
////            //                NSArray <DUIInventoryVMNode *>*nodes = [duiController performSelector:@selector(allLocalVMNodes)];
////            //
////            //                [nodes enumerateObjectsUsingBlock:^(DUIInventoryVMNode * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////            //                    DUIVMActionController *vc = [NSClassFromString(@"DUIVMActionController") actionControllerForVMWithNode:obj];
////            //                    THVMItem *vmItem = [[THVMItem alloc] init];
////            //                    vmItem.actionController = vc;
////            //                    vmItem.node = obj;
////            //                    vmItem.powerState = vc.powerState;
////            //                    [_sharedSingleton.vmItems addObject:vmItem];
////            //                }];
////            //
////            //                [_sharedSingleton.startExecuteWindowController update];
////            //                [self HookLogx:@"显示 我的win"];
////            //            });
////            
////            
////            //            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////            //
////            //                _sharedSingleton.startExecuteWindowController = [[THStartExecuteWindowController alloc] initWithWindowNibName:@"THStartExecuteWindowController" tartExecute:_sharedSingleton];
////            //                [_sharedSingleton.startExecuteWindowController showWindow:_sharedSingleton.startExecuteWindowController.window];
////            //                [_sharedSingleton.startExecuteWindowController update];
////            //                [self HookLogx:@"显示 我的win"];
////            //
////            //
////            //                PLController * duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
////            //
////            //                [self HookLogx:[NSString stringWithFormat:@"duiController=%@",duiController]];
////            //
////            //                DUIInventoryVMNode *inventoryVMNode = [[duiController performSelector:@selector(allLocalVMNodes)] lastObject];
////            //
////            //                [self HookLogx:[NSString stringWithFormat:@"inventoryVMNode=%@",inventoryVMNode]];
////            //
////            //                DUIVMActionController * rax = [duiController performSelector:@selector(actionControllerForVMWithNode:) withObject:inventoryVMNode];
////            //                [rax.vm performSnapshotsCompatibilityChecks];
////            //                [rax.vm.snapshotTree refresh];
////            //
////            //            //    DUIVMActionController.
////            //
////            //
////            //
////            //                [self HookLogx:[NSString stringWithFormat:@"vm=%@",rax.vm]];
////            //                [self HookLogx:[NSString stringWithFormat:@"vm.snapshotTree=%@",rax.vm.snapshotTree]];
////            //                [self HookLogx:[NSString stringWithFormat:@"inventoryVMNode.vm.snapshotTree=%@",inventoryVMNode.vm.snapshotTree]];
////            //
////            //             //   [[DUISnapshotTree alloc] initWithAdaptedSnapshotTree:(struct SnapshotTree *)]
////            //
////            //               // [[DUIVM alloc] initWithAdaptedVM:(const struct DUIAdaptedVMWrapper *)];
////            //                //rax.
////            //                //inventoryVMNode.v
////            //
////            //                [self HookLogx:[NSString stringWithFormat:@"vm.snapshotTree.snapshots=%@",rax.vm.snapshotTree.snapshots]];
////            //                [self HookLogx:[NSString stringWithFormat:@"vm.snapshotTree.snapshots=%@",rax.vm.snapshotTree.visibleSnapshots]];
////            //
////            //
////            //                PLSnapshotController * snapshotController = [[NSClassFromString(@"PLSnapshotController") alloc] initWithVM:rax.vm];
////            //                id node = rax.vm.snapshotTree.visibleSnapshots.lastObject;
////            //                id uid = [node performSelector:@selector(uid)];
////            //                [snapshotController setCloneType:0x0];
////            //                [snapshotController setCloneUID:uid];
////            //
////            //                NSString *directory = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
////            //
////            //                NSSavePanel*    panel = [NSSavePanel savePanel];
////            //                [panel setNameFieldStringValue:@"太好了"];
////            //                // [panel setMessage:@"Choose the path to save the document"];
////            //                [panel setAllowsOtherFileTypes:YES];
////            //                //[panel setAllowedFileTypes:@[@"onecodego"]];
////            //                [panel setExtensionHidden:YES];
////            //                [panel setCanCreateDirectories:YES];
////            //                [panel setDirectoryURL:[NSURL fileURLWithPath:directory]];
////            //
////            //                [snapshotController savePanelDidEnd:panel returnCode:1];
////            //
////            //
////            //           //     id scanController = [NSClassFromString(@"PLVMScanController") performSelector:@selector(sharedScanController)];
////            //       //         dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////            //
////            ////                    [self HookLogx:[NSString stringWithFormat:@"MScanController=%@",scanController]];
////            ////                    [self HookLogx:[NSString stringWithFormat:@"MScanController-scanPaths=%@",[scanController valueForKey:@"scanPaths"]]];
////            ////                    [self HookLogx:[NSString stringWithFormat:@"MScanController-scannedVMs=%@",[scanController valueForKey:@"scannedVMs"]]];
////            ////
////            ////
////            ////                    id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
////            ////                    id inventoryVMNode = [[duiController performSelector:@selector(allLocalVMNodes)] lastObject];
////            //                   // [[self class] HookLogx:[NSString stringWithFormat:@"duiController=%@,allLocalVMNodes=%@",duiController,[duiController performSelector:@selector(allLocalVMNodes)]]];
////            //
////            //                  //  id rax = [duiController performSelector:@selector(actionControllerForVMWithNode:) withObject:inventoryVMNode];
////            //
////            //                  //  id vmID = [inventoryVMNode valueForKey:@"vmID"];
////            //
////            //                  //  DUIVMActionController *vmActionController = [[NSClassFromString(@"DUIVMActionController") alloc] initWithVMID:vmID node:inventoryVMNode];
////            //
////            //                   // [[self class] HookLogx:[NSString stringWithFormat:@"擦擦擦vmActionController=%@",vmActionController]];
////            //
////            ////                    [rax vmTogglePowerOnOffSuspend:nil];
////            ////                    [[self class] HookLogx:@"我尝试了打开"];
////            //                //});
////            //
////            //            });
////        });
////    });
////    return _sharedSingleton;
////}
////
////-(void)scanningsnapshotWindowController {
////    
////    [[[NSApplication sharedApplication] windows] enumerateObjectsUsingBlock:^(NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////        
////        if ([obj.delegate isKindOfClass:NSClassFromString(@"PLVMSnapshotWindowController")]) {
////            if ([self.snapshotWindowController isEqual:obj.delegate] == NO) {
////                
////                self.snapshotWindowController = (PLVMSnapshotWindowController *)obj.delegate;
////                self.snapshotViewController = self.snapshotWindowController.snapshotViewController;
////                PLVMSnapshotTreeView *snapshotTreeView = [self.snapshotViewController valueForKey:@"snapshotTreeView"];
////                [snapshotTreeView.nodes enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PLVMSnapshotNodeView *  _Nonnull obj, BOOL * _Nonnull stop) {
////                    if (obj.isSelected) {
////                        self.snapshotNodeView = obj;
////                    }
////                }];
////                [self.startExecuteWindowController update];
////            }
////        }
////    }];
////}
////
////-(NSInteger)snapshotCount {
////    PLInventoryManager *inventoryManager = [NSClassFromString(@"PLInventoryManager") defaultInventoryManager];
////    DUIInventoryFolderNode *folderNode = inventoryManager.contents.firstObject;
////    return folderNode.nodes.count;
////    
////    //    PLVMSnapshotTreeView *snapshotTreeView = [self.snapshotViewController valueForKey:@"snapshotTreeView"];
////    //    return snapshotTreeView.nodes.count;
////}
////
////-(NSArray<NSString *>*)snapshotNames:(DUIInventoryVMNode *)vmNode {
////    
////    NSArray <DUISnapshot*>*snapshots = vmNode.vm.snapshotTree.snapshots;
////    NSMutableArray *snapshotNames = [NSMutableArray arrayWithCapacity:snapshots.count];
////    [snapshots enumerateObjectsUsingBlock:^(DUISnapshot * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////        [snapshotNames addObject:[obj displayName]];
////    }];
////    return snapshotNames;
////}
////
//////-(NSArray<NSString *>*)snapshotNames {
//////
//////    PLVMSnapshotTreeView *snapshotTreeView = [self.snapshotViewController valueForKey:@"snapshotTreeView"];
//////    NSMutableArray *snapshotNames = [NSMutableArray arrayWithCapacity:snapshotTreeView.nodes.count];
//////    [snapshotTreeView.nodes enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PLVMSnapshotNodeView *  _Nonnull obj, BOOL * _Nonnull stop) {
//////        [snapshotNames addObject:obj.name];
//////    }];
//////    return snapshotNames;
//////}
////
////-(void)setSelectedNode:(DUIInventoryVMNode *)vmNode  snapshotName:(NSString *)nodeName {
////    
////    //  NSArray <DUISnapshot*>*snapshots = vmNode.vm.snapshotTree.snapshots;
////    
////    
////}
////
//////-(void)setSelectedNodeName:(NSString *)nodeName {
//////    PLVMSnapshotTreeView *snapshotTreeView = [self.snapshotViewController valueForKey:@"snapshotTreeView"];
//////    [snapshotTreeView.nodes enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PLVMSnapshotNodeView *  _Nonnull obj, BOOL * _Nonnull stop) {
//////        if([obj.name isEqualToString:nodeName]) {
//////            self.snapshotNodeView = obj;
//////            obj.isSelected = YES;
//////        } else {
//////            obj.isSelected = NO;
//////        }
//////    }];
//////}
////
////-(NSInteger)vmNumbers {
////    
////    id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
////    NSArray <DUIInventoryVMNode *>*nodes = [duiController performSelector:@selector(allLocalVMNodes)];
////    
////    if (nodes.count != self.vmItems.count) {
////        [self.vmItems removeAllObjects];
////        [nodes enumerateObjectsUsingBlock:^(DUIInventoryVMNode * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////            DUIVMActionController *vc = [NSClassFromString(@"DUIVMActionController") actionControllerForVMWithNode:obj];
////            THVMItem *vmItem = [[THVMItem alloc] init];
////            vmItem.actionController = vc;
////            vmItem.node = obj;
////            vmItem.powerState = vc.powerState;
////            [self.vmItems addObject:vmItem];
////        }];
////    }
////    
////    return self.vmItems.count;
////}
////
////-(NSInteger)runVMNumber {
////    
////    id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
////    NSArray <DUIInventoryVMNode *>*nodes = [duiController performSelector:@selector(allLocalVMNodes)];
////    
////    if (nodes.count != self.vmItems.count) {
////        
////        [self.vmItems removeAllObjects];
////        [nodes enumerateObjectsUsingBlock:^(DUIInventoryVMNode * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////            DUIVMActionController *vc = [NSClassFromString(@"DUIVMActionController") actionControllerForVMWithNode:obj];
////            THVMItem *vmItem = [[THVMItem alloc] init];
////            vmItem.actionController = vc;
////            vmItem.node = obj;
////            vmItem.powerState = vc.powerState;
////            [self.vmItems addObject:vmItem];
////        }];
////    }
////    
////    __block int runVMNumber = 0;
////    [self.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////        if(obj.actionController.powerState == 1) {
////            runVMNumber += 1;
////        }
////    }];
////    return runVMNumber;
////}
////
////-(void)createCloneLinked:(NSString *)linkName block:(void(^)(void))block {
////    
////    if (self.snapshotNodeView == nil) {
////        return;
////    }
////    
////    [self.snapshotViewController endEditing];
////    id node = [[self.snapshotViewController selectedSnapshots] lastObject];
////    [[self class] HookLogx:[NSString stringWithFormat:@"克隆Node=%@",node]];
////    PLSnapshotController * snapshotController = self.snapshotViewController.vmController.vm.snapshotController;
////    
////    id uid = [node performSelector:@selector(uid)];
////    [snapshotController setCloneType:0x0];
////    [snapshotController setCloneUID:uid];
////    
////    NSString *directory = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
////    
////    NSSavePanel*    panel = [NSSavePanel savePanel];
////    [panel setNameFieldStringValue:linkName];
////    // [panel setMessage:@"Choose the path to save the document"];
////    [panel setAllowsOtherFileTypes:YES];
////    //[panel setAllowedFileTypes:@[@"onecodego"]];
////    [panel setExtensionHidden:YES];
////    [panel setCanCreateDirectories:YES];
////    [panel setDirectoryURL:[NSURL fileURLWithPath:directory]];
////    
////    [[snapshotController savePanelAccessory] savePanelDidEnd:panel];
////    [[snapshotController vm] decrementCuiBusyCount];
////    
////    NSString *path = [directory stringByAppendingPathComponent:[NSString stringWithFormat:@"%@.vmwarevm",linkName]];
////    ///Users/apple/Desktop/macOS1012_parent_05.vmwarevm
////    [[self class] HookLogx:[NSString stringWithFormat:@"path=%@",path]];
////    
////    [snapshotController setBundlePath:path];
////    NSString *pathName = [path lastPathComponent];
////    NSString *name = [pathName stringByDeletingPathExtension];
////    NSString *pathExtension = [name stringByAppendingPathExtension:@"vmx"];
////    NSString *baoPath = [path stringByAppendingPathComponent:pathExtension];
////    
////    [snapshotController setCloneType:0x0];
////    [snapshotController setCloneUID:uid];
////    // [[snapshotController savePanelAccessory] ]
////    
////    [snapshotController savePanelAccessory];
////    [snapshotController duiWeakRef];
////    
////    DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
////    [snapshotTree cloneSnapshotWithUID:uid cloneType:0x0 displayName:name cfgFile:baoPath abortHandler:^{
////        [[self class] HookLogx:@"创建错误"];
////    } doneHandler:^{
////        [[self class] HookLogx:@"全部完成"];
////    } snapshotDoneHandler:^{
////        [[self class] HookLogx:@"快照处理成功"];
////    } progressHandler:nil];
////    
////    return;
////    
////    id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
////    id inventoryVMNode = [[duiController performSelector:@selector(allLocalVMNodes)] lastObject];
////    
////    [snapshotController savePanelDidEnd:panel returnCode:1];
////    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(10 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////        
////        DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
////        PLVMController *plvmController = [NSClassFromString(@"PLVMController") controllerForVMWithID:snapshotTree.vm.uid];
////        
////        [plvmController openVMWithDlgMgr:snapshotTree.vm.dlgMgr abortHandler:^{
////            [[self class] HookLogx:@"创建失败"];
////        } doneHandler:^{
////            [[self class] HookLogx:@"创建成功"];
////            
////            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////                
////                id duiController = [NSClassFromString(@"DUIController") performSelector:@selector(sharedController)];
////                id inventoryVMNode = [[duiController performSelector:@selector(allLocalVMNodes)] lastObject];
////                
////                DUIVMActionController * rax = [duiController performSelector:@selector(actionControllerForVMWithNode:) withObject:inventoryVMNode];
////                
////                //DUIInventoryVMNode
////                if ([[inventoryVMNode valueForKey:@"isClone"] boolValue]) {
////                    [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d是克隆机",rax.powerState]];
////                } else {
////                    [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d不是克隆机",rax.powerState]];
////                }
////                
////                [[self class] HookLogx:[NSString stringWithFormat:@"当前虚拟机状态=%d",rax.powerState]];
////                
////                [rax vmTogglePowerOnOffSuspend:inventoryVMNode];
////                
////                [[self class] HookLogx:[NSString stringWithFormat:@"我尝试了打开=%@",rax.vm.name]];
////                
////                
////                //                THVMItem *item = [[THVMItem alloc] init];
////                //                item.actionController = rax;
////                //                item.node = inventoryVMNode;
////                //                item.powerState = 1;
////                //                [self.vmItems addObject:item];
////                
////                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////                    
////                    [rax vmPowerOff:inventoryVMNode];
////                    // item.powerState = 2;
////                    [self.startExecuteWindowController update];
////                });
////                
////                if (block != nil) {
////                    block();
////                }
////                
////            });
////        }];
////        
////    });
////    
////    
////    
////}
////
////+(void)VMs {
////    NSString *path = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
////    
////    NSFileManager *fileManager = [NSFileManager defaultManager];
////    
////    [fileManager contentsOfDirectoryAtPath:path error:nil];
////    
////    
////    
////}
////
////+(void)load {
////    
////    HookLog(@"加载成功了");
////    //highlighted NSMenuItem
////    [NSClassFromString(@"NSButton") HookMouseDown];
////    THStartExecute *shared = [self shared];
////    shared.snapshotTimer = [NSTimer scheduledTimerWithTimeInterval:1 target:shared selector:@selector(scanningsnapshotWindowController) userInfo:nil repeats:YES];
////    
////    //    [NSClassFromString(@"DUISnapshotTree") aspect_hookSelector:@selector(cloneSnapshotWithUID:cloneType:displayName:cfgFile:abortHandler:doneHandler:snapshotDoneHandler:progressHandler:) usingBlock:^(id info, id sender) {
////    //
////    //            [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //                HookLog(@"快照相关 参数=%@,index=%ld",obj,idx);
////    //            }];
////    //            HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //        }];
////    //
////    return;
////    
////    //    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(9 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////    //
////    //        [self statr];
////    //
////    //    });
////    //
////    
////    
////    //    [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:@selector(selectedSnapshots) usingBlock:^(id info, id sender) {
////    //
////    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinked",idx,[obj class],obj,[obj superclass]);
////    //        }];
////    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //    }];
////    //
////    //
////    //    [NSClassFromString(@"PLController") aspect_hookSelector:@selector(actionControllerForVMWithID:) usingBlock:^(id info, id sender) {
////    //
////    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinked",idx,[obj class],obj,[obj superclass]);
////    //        }];
////    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //    }];
////    //
////    //    [NSClassFromString(@"DUISnapshotUID") aspect_hookSelector:@selector(plistRepresentation) usingBlock:^(id info, id sender) {
////    //
////    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinked",idx,[obj class],obj,[obj superclass]);
////    //        }];
////    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //    }];
////    //
////    //
////    //    [NSClassFromString(@"PLVMActionController") aspect_hookSelector:@selector(createCloneLinked:) usingBlock:^(id info, id sender) {
////    //
////    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinked",idx,[obj class],obj,[obj superclass]);
////    //        }];
////    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //    }];
////    //
////    //    [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:@selector(onCreateCloneLinked:) usingBlock:^(id info, id sender) {
////    //
////    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"onCreateCloneLinked",idx,[obj class],obj,[obj superclass]);
////    //        }];
////    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //    }];
////    //
////    //    [NSClassFromString(@"PLSnapshotController") aspect_hookSelector:@selector(createCloneLinkedForSnapshot:dlgMgr:) usingBlock:^(id info, id sender) {
////    //
////    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"createCloneLinkedForSnapshot",idx,[obj class],obj,[obj superclass]);
////    //        }];
////    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //    }];
////    //
////    //    [NSClassFromString(@"PLInventoryResponder") aspect_hookSelector:@selector(onCreateCloneLinked:) usingBlock:^(id info, id sender) {
////    //
////    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"onCreateCloneLinked",idx,[obj class],obj,[obj superclass]);
////    //        }];
////    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //    }];
////    
////    //- (id)initWithVMID:(id)arg1 node:(id)arg2;
////    
////    //struct VMID
////    
////    
////    
////    
////    id cccc = [NSClassFromString(@"DUIVMID") performSelector:@selector(vmidForLocalVMWithConfigPath:) withObject:@"/Users/apple/Desktop/macOS1012_parent_05.vmwarevm/macOS1012_parent_05.vmx"];
////    
////    [self HookLogx:[NSString stringWithFormat:@"vmidForLocalVMWithConfigPath=%@",cccc]];
////    
////    //  id adaptorBase = [[NSClassFromString(@"DUIAdaptorBase") alloc] init];
////    
////    id actionController = [[NSClassFromString(@"PLVMActionController") alloc] initWithVMID:cccc node:nil];
////    
////    
////    [actionController performSelector:@selector(showSnapshots:) withObject:nil];
////    
////    [NSClassFromString(@"PLVMActionController") aspect_hookSelector:@selector(showSnapshots:) usingBlock:^(id info, id sender) {
////        
////        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////            
////            if ([obj isKindOfClass:[NSMenuItem class]]) {
////                NSMenuItem *b = obj;
////                [self HookLogx:[NSString stringWithFormat:@"PLVMActionController-target=%@,action=%@",b.target,NSStringFromSelector(b.action)]];
////            }
////            
////            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"showSnapshots",idx,[obj class],obj,[obj superclass]);
////        }];
////        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////        
////    }];
////    
////    [self HookLogx:[NSString stringWithFormat:@"actionController=%@",actionController]];
////    
////    NSArray<NSString *> *vv =  [NSClassFromString(@"PLVMSnapshotViewController") propertyList];
////    [self HookLogx:[NSString stringWithFormat:@"%@",vv]];
////    //    [[NSClassFromString(@"PLVMSnapshotViewController") funcList] enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //
////    //        [self HookLogx:obj];
////    //
////    //        if (![vv containsObject:obj]) {
////    //
////    //            if ([NSClassFromString(@"PLVMSnapshotViewController") respondsToSelector:NSSelectorFromString(obj)]) {
////    //
////    //                [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:NSSelectorFromString(obj) usingBlock:^(id info, id sender) {
////    //
////    //                    [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //                        HookLog(@"快照 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"actionControllerForVMWithID",idx,[obj class],obj,[obj superclass]);
////    //                    }];
////    //                    HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //                }];
////    //
////    //            } else if ([[[NSClassFromString(@"PLVMSnapshotViewController") alloc] init] respondsToSelector:NSSelectorFromString(obj)]) {
////    //
////    //                [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:NSSelectorFromString(obj) usingBlock:^(id info, id sender) {
////    //
////    //                    [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //                        HookLog(@"快照 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"actionControllerForVMWithID",idx,[obj class],obj,[obj superclass]);
////    //                    }];
////    //                    HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //
////    //                }];
////    //
////    //            }
////    //        }
////    //
////    //    }];
////    //PLWindowProvider
////    
////    
////    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(8 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////        
////        [[[NSApplication sharedApplication] windows] enumerateObjectsUsingBlock:^(NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////            
////            [self HookLogx:[NSString stringWithFormat:@"文斗%@",obj.windowController]];
////            
////        }];
////        
////    });
////    
////}
////
////
////+(void)statr {
////    
////    [[[[NSApplication sharedApplication] mainMenu] itemArray] enumerateObjectsUsingBlock:^(NSMenuItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////        
////        [self HookLogx:obj.title];
////        
////        if ([obj.title isEqualToString:@"虚拟机"]) {
////            
////            [[[obj submenu] itemArray] enumerateObjectsUsingBlock:^(NSMenuItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////                
////                [self HookLogx:obj.title];
////                if([obj.title hasPrefix:@"快照"]) {
////                    
////                    [[[obj submenu] itemArray] enumerateObjectsUsingBlock:^(NSMenuItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////                        
////                        [self HookLogx:obj.title];
////                        if([obj.title hasPrefix:@"快照"]) {
////                            
////                            [obj.target performSelector:obj.action withObject:obj];
////                            
////                            NSString *ff = [NSString stringWithFormat:@"target=%@,action=%@",obj.target,NSStringFromSelector(obj.action)];
////                            
////                            [self HookLogx:ff];
////                        }
////                        
////                    }];
////                    
////                }
////                
////            }];
////            
////        }
////        
////        
////    }];
////    
////    
////    PLSessionMgr *sessionMgr = [NSClassFromString(@"PLSessionMgr") sharedSessionMgr];
////    
////    id vmid = [NSClassFromString(@"DUIVMID") vmidForLocalVMWithConfigPath:@"/Users/apple/Desktop/macOS1012_parent_05.vmwarevm/macOS1012_parent_05.vmx"];
////    
////    
////    
////    //[sessionMgr showSnapshotsForVMWithID:vmid];
////    
////    
////    
////    
////    
////    //    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////    //        [self HookLogx:[NSString stringWithFormat:@"a哈哈llSessions=%@",sessionMgr.allSessions]];
////    //
////    //        [[[NSApplication sharedApplication] windows] enumerateObjectsUsingBlock:^(NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //
////    //            [self HookLogx:[NSString stringWithFormat:@"NSWindow=%@",obj.delegate]];
////    //            if ([obj.delegate isKindOfClass:NSClassFromString(@"PLVMSnapshotWindowController")]) {
////    //                PLVMSnapshotWindowController *snapshotWindowController = obj.delegate;
////    //                [self HookLogx:[NSString stringWithFormat:@"windowNibName=%@",snapshotWindowController.windowNibName]];
////    //            }
////    //                //snapshotWindowController.windowNibName
////    //        }];
////    //
////    //    });
////    
////    
////    
////    //   PLVMActionController *plvmActionController = [[NSClassFromString(@"PLVMActionController") alloc] initWithVMID:vmid node:nil];
////    [sessionMgr.allSessions enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////        //PLVMStartMenuManager PLLibrarySession
////        if([obj isKindOfClass:NSClassFromString(@"PLVMSession")]) {
////            
////            //initWithWindowNibName
////            PLVMSnapshotWindowController *snapshotWindowController = [[NSClassFromString(@"PLVMSnapshotWindowController") alloc] initWithSession:obj];
////            
////            [snapshotWindowController snapshotWindowWantsProgress];
////            [snapshotWindowController showSnapshotWindow];
////            [snapshotWindowController.window makeKeyWindow];
////            
////            [[NSClassFromString(@"PLVMSnapshotWindowController") propertyList] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////                
////                [self HookLogx:[NSString stringWithFormat:@"%@=%@",obj,[snapshotWindowController valueForKey:obj]]];
////                
////            }];
////            
////            PLVMSnapshotTreeView *snapshotTreeView = [snapshotWindowController.snapshotViewController valueForKey:@"snapshotTreeView"];
////            
////            [snapshotTreeView.nodes enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, PLVMSnapshotNodeView *  _Nonnull obj, BOOL * _Nonnull stop) {
////                if([obj.name isEqualToString:@"快照 2"]) {
////                    [obj setIsSelected:YES];
////                } else {
////                    [obj setIsSelected:NO];
////                }
////            }];
////            
////            [self HookLogx:[NSString stringWithFormat:@"PLLibrarySession-snapshotTreeView.nodes%@",snapshotTreeView.nodes]];
////        }
////    }];
////    
////    return;
////    
////    // [snapshotWindowController showSnapshotWindow];
////    /* [rbx cancelAutomaticDiskCleanup];
////     [rbx duiWeakRef];
////     [rbx openVMWithAbortHandler:0x0 DoneHandler:__NSConcreteStackBlock];*/
////    
////    //    [plvmActionController cancelAutomaticDiskCleanup];
////    //    [plvmActionController duiWeakRef];
////    //    [plvmActionController openVMWithAbortHandler:0x0 DoneHandler:^{
////    //        [self HookLogx:@"打开了"];
////    //    }];
////    //    [sessionMgr openVMSessionForVMWithID:plvmActionController.vmID abortHandler:^{
////    //        [self HookLogx:@"错误"];
////    //    } doneHandler:^{
////    //        [self HookLogx:@"打开了"];
////    //    }];
////    
////    return;
////    
////    
////    PLVMSnapshotViewController *vc = [[NSClassFromString(@"PLVMSnapshotViewController") alloc] init];
////    
////    [self HookLogx:[NSString stringWithFormat:@"selectedSnapshots=%@",[vc selectedSnapshots]]];
////    
////    
////    
////    [[NSClassFromString(@"PLVMSnapshotViewController") propertyList] enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////        
////        [self HookLogx:[NSString stringWithFormat:@"属性%@",[vc valueForKey:obj]]];
////        
////    }];
////    
////    id actionController = [[NSClassFromString(@"PLVMActionController") alloc] init];
////    
////    // [actionController performSelector:@selector(showSnapshots:) withObject:nil];
////    [self HookLogx:[NSString stringWithFormat:@"显示%@",actionController]];
////    
////    id cccc = [NSClassFromString(@"DUIVMID") performSelector:@selector(vmidForLocalVMWithConfigPath:) withObject:@"/Users/apple/Desktop/macOS1012_parent_05.vmwarevm/macOS1012_parent_05.vmx"];
////    id plvmController = NSClassFromString(@"PLVMController");
////    
////    PLVMController * vmController = [[plvmController alloc] initWithVMID:cccc];
////    
////    id rdi = [[vmController valueForKey:@"vm"] performSelector:@selector(snapshotController)];
////    id rdx = [[rdi valueForKey:@"cloneUID"] valueForKey:@"uid"];
////    [rdi performSelector:@selector(createCloneLinkedForSnapshot:dlgMgr:) withObject:rdx withObject:nil];
////    [self HookLogx:[NSString stringWithFormat:@"链接😯%@,%@",rdi,vmController]];
////    
////    
////    [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:@selector(onCreateCloneLinked:) usingBlock:^(id info, id sender) {
////        
////        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////            if ([obj isKindOfClass:[NSMenuItem class]]) {
////                NSMenuItem *b = obj;
////                [self HookLogx:[NSString stringWithFormat:@"PLVMSnapshotViewController-target=%@,action=%@",b.target,NSStringFromSelector(b.action)]];
////            }
////            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"onCreateCloneLinked",idx,[obj class],obj,[obj superclass]);
////        }];
////        
////        id x = [[info valueForKey:@"instance"] valueForKey:@"dlgMgr"];
////        id y = [[info valueForKey:@"instance"] valueForKey:@"selectedSnapshots"];
////        
////        NSDictionary * nodes = [[[info valueForKey:@"instance"] valueForKey:@"snapshotTreeView"] valueForKey:@"nodes"];
////        [nodes enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
////            if([[obj valueForKey:@"name"] isEqualToString:@"快照 2"]) {
////                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
////                    
////                    [obj setValue:@(YES) forKey:@"isSelected"];
////                    
////                    id vmController = [obj valueForKey:@"vmController"];
////                    
////                    [self HookLogx:[NSString stringWithFormat:@"调用了vmController=%@",vmController]];
////                    
////                    id rdi = [[vmController valueForKey:@"vm"]
////                              performSelector:@selector(snapshotController)];
////                    
////                    [self HookLogx:[NSString stringWithFormat:@"调用了snapshotController=%@",rdi]];
////                    
////                    id rdx = [[rdi valueForKey:@"cloneUID"] valueForKey:@"uid"];
////                    
////                    [self HookLogx:[NSString stringWithFormat:@"调用了cloneUID=%@",rdx]];
////                    
////                    [rdi performSelector:@selector(createCloneLinkedForSnapshot:dlgMgr:) withObject:rdx withObject:nil];
////                    
////                    
////                    
////                    
////                    [self HookLogx:@"调用了"];
////                    
////                    //  [[info valueForKey:@"instance"] performSelector:@selector(onCreateCloneLinked:) withObject:nil];
////                    
////                    
////                    id mage = [info valueForKey:@"instance"];
////                    [mage performSelector:@selector(endEditing)];
////                    id node = [[mage performSelector:@selector(selectedSnapshots)] lastObject];
////                    PLSnapshotController * snapshotController = [[[mage performSelector:@selector(vmController)] performSelector:@selector(vm)] performSelector:@selector(snapshotController)];
////                    //createCloneLinkedForSnapshot
////                    
////                    id rdxx = [node performSelector:@selector(uid)];
////                    
////                    [snapshotController setCloneType:0x0];
////                    [snapshotController setCloneUID:rdxx];
////                    
////                    [NSClassFromString(@"PLSnapshotController") aspect_hookSelector:@selector(savePanelDidEnd:returnCode:) usingBlock:^(id info, id sender) {
////                        
////                        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////                            HookLog(@"快照 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"savePanelDidEnd",idx,[obj class],obj,[obj superclass]);
////                        }];
////                        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////                        
////                    }];
////                    
////                    NSSavePanel*    panel = [NSSavePanel savePanel];
////                    [panel setNameFieldStringValue:@"唐海uuu"];
////                    // [panel setMessage:@"Choose the path to save the document"];
////                    [panel setAllowsOtherFileTypes:YES];
////                    //[panel setAllowedFileTypes:@[@"onecodego"]];
////                    [panel setExtensionHidden:YES];
////                    [panel setCanCreateDirectories:YES];
////                    [panel setDirectoryURL:[NSURL fileURLWithPath:@"/Users/apple/VM"]];
////                    
////                    [snapshotController savePanelDidEnd:panel returnCode:1];
////                    
////                    // [snapshotController createCloneForSnapshot:rdxx dlgMgr:[mage performSelector:@selector(dlgMgr)]];
////                    
////                    // return;
////                    
////                    //[snapshotController setCloneType:0];
////                    
////                    //[snapshotController setCloneUID:rdxx];
////                    DUISnapshotTree *snapshotTree = snapshotController.vm.snapshotTree;
////                    //  [snapshotTree canCloneSnapshotWithUID:rdxx cloneType:0 error:nil];
////                    
////                    
////                    PLVMController *plvmController = [NSClassFromString(@"PLVMController") controllerForVMWithID:snapshotTree.vm.uid];
////                    
////                    [plvmController openVMWithDlgMgr:snapshotTree.vm.dlgMgr abortHandler:^{
////                        [self HookLogx:@"创建失败"];
////                    } doneHandler:^{
////                        [self HookLogx:@"创建成功"];
////                    }];
////                    
////                    //[snapshotController performSelector:@selector(checkIfCanCloneWithDlgMgr:) withObject:[mage performSelector:@selector(dlgMgr)]];
////                    
////                    
////                    
////                    
////                    /* [PLSnapshotController checkIfCanCloneWithDlgMgr:](void * self, void * _cmd, void * arg2) {
////                     r14 = arg2;
////                     rbx = self;
////                     r12 = [[self vm] snapshotTree];
////                     r8 = var_30;
////                     rdx = [rbx cloneUID];
////                     rcx = [rbx cloneType];
////                     r12 = [r12 canCloneSnapshotWithUID:rdx cloneType:rcx error:r8];
////                     if (r14 == 0x0) {
////                     r14 = [[rbx vm] dlgMgr];
////                     }
////                     if (r12 != 0x0) {
////                     rax = [rbx vm];
////                     rax = [rax uid];
////                     rax = [PLVMController controllerForVMWithID:rax];
////                     [rax openVMWithDlgMgr:r14 abortHandler:__NSConcreteStackBlock doneHandler:__NSConcreteStackBlock];
////                     }
////                     else {
////                     [rbx setCloneType:0x2];
////                     [rbx setCloneUID:0x0];
////                     rax = [NSAlert alertWithError:var_30];
////                     [r14 beginAlert:rax repliedHandler:0x0];
////                     }
////                     return;
////                     }*/
////                    
////                });
////                
////            } else {
////                [obj setValue:@(NO) forKey:@"isSelected"];
////            }
////            
////            
////            [self HookLogx:[NSString stringWithFormat:@"nodesName=%@",[obj valueForKey:@"name"]]];
////        }];
////        
////        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////        [self HookLogx:[NSString stringWithFormat:@"dlgMgr=%@,selectedSnapshots=%@,nodes=%@",x,y,nodes]];
////        
////        [[NSClassFromString(@"PLVMSnapshotViewController") propertyList] enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////            
////            [self HookLogx:[NSString stringWithFormat:@"属性%@=%@",obj,[[info valueForKey:@"instance"] valueForKey:obj]]];
////            
////        }];
////    }];
////    
////    
////    
////    
////    
////    //    [NSClassFromString(@"PLVMSnapshotViewController") aspect_hookSelector:@selector(snapshotForItem:) usingBlock:^(id info, id sender) {
////    //
////    //        [[info valueForKey:@"arguments"] enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //            HookLog(@"发送相关 类名:%@ 方法名:%@ -by:餐数:%ld\r --class:%@\r---obj:%@\r---%@\r",[self class],@"snapshotForItem",idx,[obj class],obj,[obj superclass]);
////    //        }];
////    //
////    //        id x = [[info valueForKey:@"instance"] valueForKey:@"dlgMgr"];
////    //        id y = [[info valueForKey:@"instance"] valueForKey:@"selectedSnapshots"];
////    //        HookLog(@"类名 %@",[info valueForKey:@"instance"]);
////    //        [self HookLogx:[NSString stringWithFormat:@"dlgMgr=%@,selectedSnapshots=%@",x,y]];
////    //    }];
////    
////    
////    //    id Session = [[NSClassFromString(@"PLWindowedSession") alloc] performSelector:@selector(initWithWindowProvider:) withObject:@1];
////    //
////    //    id shotWindowController = [[NSClassFromString(@"PLVMSnapshotWindowController") alloc] performSelector:@selector(initWithSession:) withObject:Session];
////    //
////    //    [[NSClassFromString(@"PLVMSnapshotWindowController") propertyList] enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //
////    //        [self HookLogx:[NSString stringWithFormat:@"window属性%@",[shotWindowController valueForKey:obj]]];
////    //
////    //    }];
////    //
////    //    [shotWindowController performSelector:@selector(showSnapshotWindow)];
////    //
////    //    id shotViewControllerNew = [shotWindowController valueForKey:@"snapshotViewController"];
////    //
////    //    [[NSClassFromString(@"PLVMSnapshotViewController") propertyList] enumerateObjectsUsingBlock:^(NSString *  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
////    //
////    //        [self HookLogx:[NSString stringWithFormat:@"属性%@",[shotViewControllerNew valueForKey:obj]]];
////    //
////    //    }];
////    //
////    
////}
////
////+(void)HookLogx:(NSString *)log {
////    
////    NSLog(@"[Plugin]%@",log);
////}
////
////@end
/////*void -[PLVMSnapshotViewController onCreateCloneLinked:](void * self, void * _cmd, void * arg2) {
//// [self endEditing];
//// r14 = [[self selectedSnapshots] lastObject];
//// rdi = [[[self vmController] vm] snapshotController];
//// rdx = [r14 uid];
//// [rdi createCloneLinkedForSnapshot:rdx dlgMgr:[self dlgMgr]];
//// return;
//// }
//// */
//////[Plugin][Hook] button taegrt=<PLImportSavePanelViewController: 0x60400015dfe0>--action=onSharingCheckboxPressed:
//
//
//@end
