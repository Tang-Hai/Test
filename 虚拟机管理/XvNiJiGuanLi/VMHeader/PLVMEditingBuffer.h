//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableDictionary, NSString, PLVM;

@interface PLVMEditingBuffer : NSObject
{
    PLVM *mVM;
    NSString *mName;
    NSString *mNotes;
    NSMutableDictionary *mBufferStates;
}

+ (id)observationKeyPaths;
@property(retain, nonatomic) NSMutableDictionary *bufferStates; // @synthesize bufferStates=mBufferStates;
@property(retain, nonatomic) NSString *notes; // @synthesize notes=mNotes;
@property(retain, nonatomic) NSString *name; // @synthesize name=mName;
@property(nonatomic) PLVM *vm; // @synthesize vm=mVM;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (void)endEditingForKey:(id)arg1;
- (void)didChangeForKey:(id)arg1;
- (void)beginEditingForKey:(id)arg1;
- (void)syncValueForKey:(id)arg1;
- (void)saveValueForKey:(id)arg1;
- (BOOL)canEditKey:(id)arg1;
- (void)updateNotes;
- (void)updateName;
- (CDUnknownBlockType)abortBlockForKey:(id)arg1;
- (CDUnknownBlockType)doneBlockForKey:(id)arg1;
- (id)keyForKeyPath:(id)arg1;
- (SEL)selectorForKey:(id)arg1;
- (void)setEditing:(BOOL)arg1 forKey:(id)arg2;
- (void)setInCallback:(BOOL)arg1 forKey:(id)arg2;
- (void)setDirty:(BOOL)arg1 forKey:(id)arg2;
- (BOOL)isKeyEditing:(id)arg1;
- (BOOL)isKeyInCallback:(id)arg1;
- (BOOL)isKeyDirty:(id)arg1;
- (void)dealloc;
- (id)initWithVM:(id)arg1;

@end

