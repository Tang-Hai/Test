//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIVM;

@interface DUIVMAutosaveSnapshots : NSObject
{
    struct connection *enabledConnection;
    struct connection *frequencyConnection;
    struct connection *maximumConnection;
    DUIVM *mVM;
}

+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
+ (BOOL)automaticallyNotifiesObserversForKey:(id)arg1;
@property(retain, nonatomic) DUIVM *vm; // @synthesize vm=mVM;
- (void)onSaveAndDiscardDone;
- (void)emitValueChangedEvents;
- (void)disconnectAutoProtectSnapshotListeners;
- (void)connectAutoProtectSnapshotListeners;
- (void)commitEditor:(struct VMEditor *)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (id)tiersDescription;
- (long long)next;
- (unsigned long long)minimumMB;
- (void)setMaximum:(int)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (int)maximum;
- (void)setFrequency:(int)arg1;
- (int)frequency;
@property(nonatomic, getter=isEnabled) BOOL enabled;
- (void)dealloc;
- (id)initWithVM:(id)arg1;

@end

