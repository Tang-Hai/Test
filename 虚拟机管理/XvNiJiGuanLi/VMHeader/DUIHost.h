//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class DUICnx, DUIHostInfo;

@interface DUIHost : DUIAdaptorBase
{
    DUIHostInfo *mInfo;
}

+ (id)hostForAdaptedHost:(struct Host *)arg1;
@property(retain, nonatomic) DUIHostInfo *info; // @synthesize info=mInfo;
- (void)dealloc;
@property(readonly, nonatomic) struct Host *adaptedHost;
- (id)initWithAdaptedHost:(struct Host *)arg1;
- (id)powerOps;
- (id)moid;
- (id)stats;
- (id)filePath;
- (id)progressMgr;
- (void)memoryLimitsMin:(int *)arg1 max:(int *)arg2 default:(int *)arg3 hostLimit:(int *)arg4 perVMLimit:(int *)arg5;
- (int)memory;
- (void)getDefaultVMConfigVersion:(int *)arg1 hardwareVersion:(int *)arg2;
- (void)getDefaultVMConfigVersion:(int *)arg1 hardwareVersion:(int *)arg2 legacy:(BOOL)arg3;
- (void)loadGuestOSTableWithHardwareVersion:(int)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (void)repopulateLicenseWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (BOOL)cap64BitGuest;
- (BOOL)capSMPGuest;
- (int)cpuThreads;
- (int)licenceExpirationDaysLeft;
- (id)updateURL;
- (id)defaultVMPath;
- (void)setDefaultVMPath:(id)arg1;
@property(readonly, nonatomic) DUICnx *connection;

@end

