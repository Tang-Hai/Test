//
//  THStartExecuteWindowController.m
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/7.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import "THStartExecuteWindowController.h"
#import "THStartExecute.h"
#import "THDAsyncSocket.h"
#import "WuMaReqsut.h"
#import "THConfigure.h"

@interface THStartExecuteWindowController ()
@property (assign,nonatomic) BOOL isZanTing;
@property (weak) IBOutlet NSPopUpButton *snapshotButton;
@property (weak) IBOutlet NSTextField *vmMaxNumberTextField;
@property (weak) IBOutlet NSTextField *vmNumberTextField;
@property (weak) IBOutlet NSPopUpButton *deleteVmButon;
@property (weak,nonatomic) THStartExecute *tartExecute;
@property (weak) IBOutlet NSPopUpButton *deleteVMButton;
@property (weak) IBOutlet NSTextField *currendVmNumberTextField;
@property (weak) IBOutlet NSPopUpButton *vmButton;
@property (weak) IBOutlet NSTextField *runMaxTextField;
@property (weak) IBOutlet NSTextField *miaoJianGeTextField;
@property (weak) IBOutlet NSTextField *chongQiCiShuTextField;
@property (weak) IBOutlet NSButton *statrButton;

@property (strong,nonatomic) THDAsyncSocket *socket;

@property (strong,nonatomic) NSString *snapshotName;
@property (strong,nonatomic) NSTimer *timer;
@property (strong,nonatomic) NSTimer *timerRun;

@property (assign,nonatomic) NSInteger snapIndex;
@property (assign,nonatomic) NSInteger vmIndex;
@property (assign,nonatomic) BOOL isOpening;
@property (assign,nonatomic) int vmNumber;
@property (weak) IBOutlet NSTextField *chengGongNumTextField;

@property (strong,nonatomic) NSTimer *wuMaReqsutTimer;
@property (strong,nonatomic) WuMaReqsut *wuMaReqsut;
@property (strong,nonatomic) THConfigure *configure;
@property (assign,nonatomic) BOOL isdierciqidong;

@end

@implementation THStartExecuteWindowController

- (instancetype)initWithWindowNibName:(NSNibName)windowNibName tartExecute:(THStartExecute *)tartExecute {
    self = [super initWithWindowNibName:windowNibName];
    self.tartExecute = tartExecute;
    self.wuMaReqsut = [[WuMaReqsut alloc] init];
    self.configure = [THConfigure shared];
    self.isZanTing = YES;
    //self.vmNumber = 1000;
    return self;
}

- (void)windowDidLoad {
    [super windowDidLoad];
    self.window.alphaValue = 0;
    void(^initAll)(void) = ^{
        

        int vmNumberold = (int)[[NSUserDefaults standardUserDefaults] integerForKey:@"vmNumberold"];
        if (vmNumberold == 0 || vmNumberold >= 9999 || vmNumberold < 1000) {
           self.vmNumber = 1000;
        } else {
            self.vmNumber = vmNumberold;
        }
        self.vmNumberTextField.stringValue = @"0";
        if ([[NSUserDefaults standardUserDefaults] objectForKey:@"isdierciqidong"] != nil) {
            self.isdierciqidong = [[NSUserDefaults standardUserDefaults] boolForKey:@"isdierciqidong"];
        } else {
            self.isdierciqidong = YES;
        }
        if ([[NSUserDefaults standardUserDefaults] objectForKey:@"self.isZanTing"] == nil) {
            self.isZanTing = YES;
        } else {
            if([[NSUserDefaults standardUserDefaults] boolForKey:@"self.isZanTing"] == YES) {
                self.isZanTing = NO;
                [self statrButtonAction:self.statrButton];
            } else {
                self.isZanTing = YES;
                [self statrButtonAction:self.statrButton];
            }
        }
        
        
        //[[NSUserDefaults standardUserDefaults] setBool:self.isZanTing forKey:@"self.isZanTing"];
        
        [self seterciqidongs];
        
        self.timer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(updateData) userInfo:nil repeats:YES];
        
        
        self.timerRun = [NSTimer scheduledTimerWithTimeInterval:3 target:self selector:@selector(updateRun) userInfo:nil repeats:YES];
        
        self.socket = [[THDAsyncSocket alloc] init];
//        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(60 * 30 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//            self.wuMaReqsutTimer = [NSTimer scheduledTimerWithTimeInterval:60 * 30 target:self selector:@selector(wuMaReqsutTimerAction) userInfo:nil repeats:YES];
//        });
        if ([[NSUserDefaults standardUserDefaults] objectForKey:@"vmMaxNumberTextField"]) {
            self.vmMaxNumberTextField.stringValue = [[NSUserDefaults standardUserDefaults] objectForKey:@"vmMaxNumberTextField"];
        }
        

        
        [self updateRun];
    };
//     self.window.alphaValue = 1;
//    initAll();
//    return;
   //[[NSUserDefaults standardUserDefaults] removeObjectForKey:@"weixibianba"];
    NSString *weixibianba = [[NSUserDefaults standardUserDefaults] objectForKey:@"weixibianba"];
    if(weixibianba == nil || weixibianba.length == 0 ) {
        NSString *uuid = [[[NSUUID alloc] init] UUIDString];
        int timeIntervalSince1970 = (int)[[NSDate date] timeIntervalSince1970];
        weixibianba = [NSString stringWithFormat:@"%@%d",uuid,timeIntervalSince1970];
        [[NSUserDefaults standardUserDefaults] setObject:weixibianba forKey:@"weixibianba"];
    }
    
    [WuMaReqsut djflsjdlldoejfleipr:weixibianba name:self.configure.tuiXinName block:^(NSString * _Nonnull tonkon) {
        if(tonkon) {
            [WuMaReqsut nkdsbdjhfjdvbfdjvdfdip:tonkon block:^(NSString * _Nonnull ip) {
                if(ip) {
                    self.wuMaReqsut.pp = ip;
                    self.tartExecute.wuMaReqsut.pp = ip;
                    dispatch_async(dispatch_get_main_queue(), ^{
                        self.window.alphaValue = 1;
                        [self showWindow:self.window];
                        initAll();
                    });
                } else {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        [Alert alertMessage:@"网络失败或暂无权限"];
                        //exit(0);
                    });
                }
                
            }];
        } else {
            dispatch_async(dispatch_get_main_queue(), ^{
                [Alert alertMessage:@"网络失败或暂无权限"];
                //exit(0);
            });
        }
    }];
}

-(void)wuMaReqsutTimerAction {
    
//    [self.wuMaReqsut chaxunCount:10000 prefix:self.configure.prefix block:^(NSMutableArray<BrushCode *>* brushCodes) {
//        NSMutableArray <THVMItem*>*guanjivms = [NSMutableArray arrayWithCapacity:10];
//        [self.tartExecute.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//            if(obj.node && obj.notOpen && obj.node.vm.powerState != 1 && obj.isOpenError == NO) {
//                [guanjivms addObject:obj];
//            }
//        }];
//        
//        NSMutableArray <THVMItem*>*deletes = [NSMutableArray arrayWithCapacity:10];
//        
//        [guanjivms enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//            
//            __block BOOL iccontent = NO;
//            [brushCodes enumerateObjectsUsingBlock:^(BrushCode * _Nonnull brushCode, NSUInteger idx, BOOL * _Nonnull stop) {
//                if ([obj.name hasSuffix:brushCode.machineNumber]) {
//                    iccontent = YES;
//                    *stop = YES;
//                }
//            }];
//            if (iccontent == NO) {
//                [deletes addObject:obj];
//            }
//        }];
//        
//        dispatch_async(dispatch_get_main_queue(), ^{
//           
//            [deletes enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
//                dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(idx * 2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//                    [self.tartExecute delete:obj];
//                });
//            }];
//        });
//        
//    }];
    
}

-(void)seterciqidongs {
    
    [self.tartExecute.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
        if ([obj resetCount] >= 1) {
            if (self.isdierciqidong) {
                obj.erciqidong = 0;
            } else {
                obj.erciqidong = 1;
            }
        }
    }];
}

-(void)updateRun {
    
    if (self.vmItem == nil) {
        self.vmItem = self.tartExecute.vmItems.firstObject;
    }
    
    self.vmMaxNumberTextField.stringValue = [NSString stringWithFormat:@"%d",self.configure.vmMaxNumber];
    self.runMaxTextField.stringValue = [NSString stringWithFormat:@"%d",self.configure.vmMaxRunNumber];
    
    self.miaoJianGeTextField.stringValue = [NSString stringWithFormat:@"%d",self.configure.vmIntervalTime * 60];
    self.chongQiCiShuTextField.stringValue = [NSString stringWithFormat:@"%d",self.configure.restartTimes];
    
    int runMax = [self.runMaxTextField.stringValue intValue];
    int sp = runMax == 0 ? 0 : 5;
    if (runMax > [self.tartExecute folderNodeRunCount] && self.isOpening == NO && self.isZanTing == NO) {
        self.isOpening = YES;
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(sp * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            if (self.isZanTing == NO) {
                [self.tartExecute openItemNoOpen:self.vmItem block:^{
                    self.isOpening = NO;
                }];
            } else {
                self.isOpening = NO;
            }
            
        });
    }
}

-(void)updateData {
    
    [self update];
    //[self guanJiJiLu];
//    if ([self.vmButton.menu.itemArray.firstObject.title isEqualToString:@"暂无"] && self.vmButton.menu.itemArray.count == 1) {
//        [self updateMenu];
//    }
    
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
       
        __block int num = 0;
        [self.tartExecute.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if(obj.isChengGongNum) {
                num += 1;
            }
        }];
        dispatch_async(dispatch_get_main_queue(), ^{
            self.chengGongNumTextField.stringValue = [NSString stringWithFormat:@"%d",num];
        });
    });
}

-(void)updateMenu {
    
   // dispatch_async(dispatch_get_main_queue(), ^{
       
        [self.vmButton.menu removeAllItems];
        [[self.tartExecute vmItems] enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if (obj.node != nil) {
                NSMenuItem *item = [[NSMenuItem alloc] initWithTitle:obj.name action:@selector(selectedVM:) keyEquivalent:@""];
                item.target = self;
                item.tag = idx;
                [self.vmButton.menu addItem:item];
            }
        }];
        
        if(self.vmIndex < self.vmButton.menu.itemArray.count) {
            [self.vmButton selectItemAtIndex:self.vmIndex];
        }
        
        if(self.vmItem == nil) {
            self.vmItem = self.tartExecute.vmItems.firstObject;
        }
        
        [self.snapshotButton.menu removeAllItems];
        
        
        [[self.tartExecute snapshotNames:self.vmItem.node] enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            NSMenuItem *item = [[NSMenuItem alloc] initWithTitle:obj action:@selector(selectedSnapshot:) keyEquivalent:@""];
            item.tag = idx;
            item.target = self;
            [self.snapshotButton.menu addItem:item];
        }];
        if(self.snapIndex < self.snapshotButton.menu.itemArray.count) {
            [self.snapshotButton selectItemAtIndex:self.snapIndex];
        }
        
       // NSLog(@"[Plugin]updateMenu-tartExecute vmItems-%@",[self.tartExecute vmItems]);
        
   // });
}


-(void)update {
    
    NSString *string = [NSString stringWithFormat:@"%d",[self.tartExecute folderNodeCount]];
    
    NSString *runString = [NSString stringWithFormat:@"%d",[self.tartExecute folderNodeRunCount]];
    
//    if ([string integerValue] != [self.vmNumberTextField.stringValue = string integerValue]) {
//        [self updateMenu];
//    }
    
    self.currendVmNumberTextField.stringValue = runString;
    self.vmNumberTextField.stringValue = string;
}

-(void)selectedVM:(NSMenuItem *)item {
    self.vmIndex = item.tag;
    self.snapIndex = 0;
    self.vmItem = [self.tartExecute.vmItems objectAtIndex:item.tag];
    [self.tartExecute selectNode:self.vmItem.node];
    [self update];
    [self updateMenu];
}

-(void)selectedSnapshot:(NSMenuItem *)item {
    self.snapIndex = item.tag;
    self.snapshotName = item.title;
}

-(void)statrcreateCloneLinked {
    
    int maxVMNumber = [self.vmMaxNumberTextField intValue];
    int current = (int)[self.tartExecute folderNodeCount];
    
    [self.tartExecute.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if([obj.name isEqualToString:self.configure.vmName]) {
            self.vmItem = obj;
            *stop = YES;
        }
    }];
    
    self.snapshotName = self.configure.vmSnapshotName;
    
    if(self.snapshotName == nil) {
        self.snapshotName = [self.tartExecute snapshotNames:self.vmItem.node].firstObject;
    }
    
    if(current <= maxVMNumber) {
        
        NSString *directory = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
        NSArray <NSString *>*contents = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:directory error:nil];
        __block NSString *name = [NSString stringWithFormat:@"%@%d",self.configure.prefix,self.vmNumber];
      //  self.vmNumber ++;
        
        __block BOOL isR = NO;
        [contents enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if ([obj hasPrefix:name]) {
                isR = YES;
                self.vmNumber ++;
                name = [NSString stringWithFormat:@"%@%d",self.configure.prefix,self.vmNumber];
            }
        }];
        //NSLog(@"vmNumber=%d",self.vmNumber);
        [[NSUserDefaults standardUserDefaults] setInteger:self.vmNumber forKey:@"vmNumberold"];
        [[NSUserDefaults standardUserDefaults] synchronize];
        [self.tartExecute createCloneLinked:self.vmItem.node snapshotName:self.snapshotName linkName:name block:^{
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                if (self.isZanTing == NO) {
                    [self statrcreateCloneLinked];
                }
            });
        }];
    } else {
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            if (self.isZanTing == NO) {
                [self statrcreateCloneLinked];
            }
        });
    }
}

-(void)guanJiJiLu {
    
    NSMutableArray *deles = [NSMutableArray arrayWithCapacity:10];
    NSInteger maxChongQi = [self.chongQiCiShuTextField.stringValue integerValue];
    NSMutableArray <THVMItem*>*VMItemGuanJis = [NSMutableArray arrayWithCapacity:10];
    [self.tartExecute.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if(obj.node && obj.notOpen && obj.node.vm.powerState != 1 && obj.isOpenError == NO) {
            //NSLog(@"guanJiJiLu-obj.stringValue=%@,isdierciqidong=%d",obj.stringValue,self.isdierciqidong);
            obj.powerState = obj.node.vm.powerState;
            [VMItemGuanJis addObject:obj];
            if (obj.guJiDate == nil) {
                if (maxChongQi > 0) {
                   [obj saveGuanJi];
                } else {
                    //删除
                    [deles addObject:obj];
                }
            } else if (self.configure.vmIntervalTime > 0 && self.isdierciqidong) {
                
                if(maxChongQi > [obj resetCount]) {
                    NSTimeInterval oldTimeIntervalSince1970 = obj.guJiDate.timeIntervalSince1970;
                    NSTimeInterval currentTimeIntervalSince1970 = [[NSDate date] timeIntervalSince1970];
                    NSTimeInterval ins = self.configure.vmIntervalTime * 60.0;
                    //NSLog(@"ins=%f,currentTimeIntervalSince1970=%f,oldTimeIntervalSince1970=%f",ins,currentTimeIntervalSince1970,oldTimeIntervalSince1970);
                    if (currentTimeIntervalSince1970 - oldTimeIntervalSince1970 >= ins) {
                        NSLog(@"达到重启间隔");
                        NSLog(@"j关机时间=%f,当前时间=%f,ins=%f",oldTimeIntervalSince1970,currentTimeIntervalSince1970,ins);
                        [obj reset];
                    }
                } else {
                    //删除
                    [deles addObject:obj];
                }
            }
        }
    }];
    [self.tartExecute delete:deles];
    
    NSMutableArray *delsss = [NSMutableArray arrayWithCapacity:10];
    dispatch_group_t group = dispatch_group_create();
    [[[NSApplication sharedApplication] windows] enumerateObjectsUsingBlock:^(NSWindow * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
       
        [VMItemGuanJis enumerateObjectsUsingBlock:^(THVMItem * _Nonnull item, NSUInteger idx, BOOL * _Nonnull stop) {
           
            if ([item.name isEqualToString:obj.title]) {
                [obj close];
            }
            
            if (item.isJianCeCG == NO && item.isChengGongNum == NO) {
                item.isJianCeCG = YES;
                dispatch_group_enter(group);
                [self.wuMaReqsut dopwperniuriuhgenks:item.name block:^(BOOL isC) {
                    if (isC == NO) {
                        //删除
                        item.JianCeCG = YES;
                        item.isChengGongNum = NO;
                        [delsss addObject:item];
                    } else {
                        item.isChengGongNum = YES;
                        item.JianCeCG = YES;
                    }
                    dispatch_group_leave(group);
                }];
                
            }
            
        }];
        
    }];
    
    dispatch_group_notify(group, dispatch_get_main_queue(), ^{
        [self.tartExecute delete:delsss];
    });
    
}

- (IBAction)statrButtonAction:(NSButton *)sender {
    
    if(self.isZanTing == YES) {
        self.isZanTing = NO;
        sender.title = @"暂停";
        
        [self statrcreateCloneLinked];
    } else {
        sender.title = @"开始";
        self.isZanTing = YES;
        return;
    }
    [[NSUserDefaults standardUserDefaults] setBool:self.isZanTing forKey:@"self.isZanTing"];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (IBAction)deleteButtonAction:(NSButton *)sender {
   // [self.tartExecute delete:@[self.tartExecute.vmItems[1]]];
    
}

- (IBAction)dierci:(NSButton *)sender {
    
    if(self.isdierciqidong) {
        sender.title = @"第二次开启";
        self.isdierciqidong = NO;
    } else {
        self.isdierciqidong = YES;
        sender.title = @"第二次暂停";
    }
    
    [[NSUserDefaults standardUserDefaults] setBool:self.isdierciqidong forKey:@"isdierciqidong"];
    
    [self seterciqidongs];
    
}

- (IBAction)allDeleteAction:(NSButton *)sender {
    
    [self.tartExecute.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if([obj.name isEqualToString:self.configure.vmName]) {
            self.vmItem = obj;
            *stop = YES;
        }
    }];
    NSMutableArray *deletas = [NSMutableArray arrayWithCapacity:10];
    NSString *directory = [NSString stringWithFormat:@"%@/VM",NSHomeDirectory()];
    [self.tartExecute.vmItems enumerateObjectsUsingBlock:^(THVMItem * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        
        if ([obj isEqual:self.vmItem] == NO && [obj.stringValue hasPrefix:directory] && obj.powerState != 1 ) {
            [deletas addObject:obj];
        }
        
    }];
    
    [self.tartExecute delete:deletas];
}

@end
