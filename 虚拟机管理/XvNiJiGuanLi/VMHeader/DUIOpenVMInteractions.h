//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIDlgMgr;

@interface DUIOpenVMInteractions : NSObject
{
    CDUnknownBlockType mUnlockVM;
    CDUnknownBlockType mUnlockRestrictedVM;
    struct OpenVMInteractions mInteractions;
}

@property(readonly, nonatomic) struct OpenVMInteractions cuiInteractions; // @synthesize cuiInteractions=mInteractions;
@property(copy, nonatomic) CDUnknownBlockType unlockRestrictedVM; // @synthesize unlockRestrictedVM=mUnlockRestrictedVM;
@property(copy, nonatomic) CDUnknownBlockType unlockVM; // @synthesize unlockVM=mUnlockVM;
- (id).cxx_construct;
- (void).cxx_destruct;
@property(nonatomic) DUIDlgMgr *dlgMgr;
- (void)dealloc;

@end

