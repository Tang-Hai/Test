//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface DUICDSController : NSObject
{
}

- (int)downloadPermissions;
- (int)adminPermission;
- (int)userPermissons;
- (void)dealloc;
- (id)init;
- (struct DownloadMgr *)downloadMgr;
- (struct ComponentMgr *)componetMgr;
- (int)componentCoreProductType;
- (BOOL)isProductOnHost:(int)arg1;
- (void)performUpdateChecks:(id)arg1 downloadMgr:(struct DownloadMgr *)arg2 showSkippedUpdates:(BOOL)arg3;
- (void)checkForUpdates:(BOOL)arg1;

@end

