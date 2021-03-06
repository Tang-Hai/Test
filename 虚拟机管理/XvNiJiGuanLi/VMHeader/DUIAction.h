//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSValidatedUserInterfaceItem.h"

@interface DUIAction : NSObject <NSValidatedUserInterfaceItem>
{
    SEL mSelector;
    id mRepresentedObject;
    long long mTag;
}

+ (id)actionFromButton:(id)arg1;
+ (id)actionFromUIItem:(id)arg1;
+ (id)actionWithSelector:(SEL)arg1 representedObject:(id)arg2 tag:(long long)arg3;
+ (id)actionWithSelector:(SEL)arg1;
+ (id)actionForPowerState:(int)arg1 isAltAction:(BOOL)arg2;
@property(readonly, nonatomic) long long tag; // @synthesize tag=mTag;
@property(readonly, retain, nonatomic) id representedObject; // @synthesize representedObject=mRepresentedObject;
@property(readonly, nonatomic) SEL selector; // @synthesize selector=mSelector;
@property(readonly) SEL action;
- (id)description;
- (void)dealloc;
- (id)initWithSelector:(SEL)arg1 representedObject:(id)arg2 tag:(long long)arg3;

@end

