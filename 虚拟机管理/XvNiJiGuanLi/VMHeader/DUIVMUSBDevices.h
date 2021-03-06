//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIVM, NSArray, NSDictionary;

@interface DUIVMUSBDevices : NSObject
{
    NSDictionary *mUSBDevices;
    NSArray *mSortedKeys;
    DUIVM *mVM;
}

@property(retain, nonatomic) DUIVM *vm; // @synthesize vm=mVM;
@property(retain, nonatomic) NSArray *sortedKeys; // @synthesize sortedKeys=mSortedKeys;
@property(retain, nonatomic) NSDictionary *usbDevices; // @synthesize usbDevices=mUSBDevices;
- (void)dealloc;
- (void)reloadCache;
- (void)reloadCacheNotification:(id)arg1;
- (void)deviceStateChangedNotification:(id)arg1;
- (void)finishInitialization;
- (id)initWithVM:(id)arg1;
- (id)reverseObjectEnumerator;
- (id)objectEnumerator;
- (unsigned long long)indexOfObject:(id)arg1;
- (BOOL)containsObject:(id)arg1;
- (id)objectAtIndex:(unsigned long long)arg1;
- (id)keyEnumerator;
- (id)allValues;
- (id)allKeys;
- (id)objectForKey:(id)arg1;
- (id)valueForKey:(id)arg1;
- (id)usbDeviceAtIndex:(unsigned long long)arg1;
- (id)usbDeviceForKey:(id)arg1;
- (unsigned long long)count;

@end

