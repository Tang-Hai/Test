//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSString;

@interface DUISupportedHardwareVersion : NSObject
{
    struct SupportedHardwareVersion mSupportedHardwareVersion;
}

+ (id)supportedHWVersionWithCUISupportedHWVersion:(const struct SupportedHardwareVersion *)arg1;
@property(readonly, nonatomic) struct SupportedHardwareVersion cuiSupportedHardwareVersion; // @synthesize cuiSupportedHardwareVersion=mSupportedHardwareVersion;
- (id).cxx_construct;
- (void).cxx_destruct;
- (id)description;
@property(readonly, copy, nonatomic) NSArray *featureRestrictions;
@property(readonly, copy, nonatomic) NSArray *productCompatNames;
@property(readonly, copy, nonatomic) NSString *versionProduct;
@property(readonly, nonatomic) int hardwareVersion;
@property(readonly, nonatomic) BOOL canCreate;
@property(readonly, nonatomic) BOOL isDefault;
@property(readonly, copy, nonatomic) NSString *key;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)arg1;
- (id)initWithCUISupportedHWVersion:(const struct SupportedHardwareVersion *)arg1;

@end

