//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

@class DUIConfigTransaction, NSString;

@protocol DUIDevicePhysicalBackend
- (void)setUsesPhysicalBackendForTransaction:(DUIConfigTransaction *)arg1;
- (BOOL)usesPhysicalBackendForTransaction:(DUIConfigTransaction *)arg1;
- (BOOL)usesPhysicalBackend;
- (void)setPhysicalBackendPath:(NSString *)arg1 forTransaction:(DUIConfigTransaction *)arg2;
- (NSString *)physicalBackendPathForTransaction:(DUIConfigTransaction *)arg1;
- (NSString *)physicalBackendPath;
@end

