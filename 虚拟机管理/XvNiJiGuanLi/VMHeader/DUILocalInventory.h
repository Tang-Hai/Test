//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIInventory.h"

@interface DUILocalInventory : DUIInventory
{
}

+ (id)localInventoryWithPath:(id)arg1 withTitle:(id)arg2 withID:(id)arg3;
- (void)flushSave;
- (id)addVMPlaceholderWithTitle:(id)arg1 inFolder:(id)arg2 insertBefore:(id)arg3;
- (id)addNodeForVMCfgPath:(id)arg1 withName:(id)arg2 inFolder:(id)arg3;
- (id)addNodeForVMCfgPath:(id)arg1 withName:(id)arg2 inFolder:(id)arg3 insertBefore:(id)arg4;
- (id)addNodeForVMCfgPath:(id)arg1 withName:(id)arg2 replacing:(id)arg3 inFolder:(id)arg4 insertBefore:(id)arg5;
- (id)addNodeForVMDictionary:(id)arg1 inFolder:(id)arg2;
- (id)addNodeForVM:(id)arg1 inFolder:(id)arg2;
- (id)nodeForPath:(id)arg1;
@property(readonly, nonatomic) struct LocalInventory *adaptedLocalInventory;
- (id)initWithPath:(id)arg1 withTitle:(id)arg2 withID:(id)arg3;

@end

