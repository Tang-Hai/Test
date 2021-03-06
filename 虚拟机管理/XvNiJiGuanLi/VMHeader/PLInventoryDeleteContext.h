//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class DUIOpenedVM, NSURL;

@interface PLInventoryDeleteContext : NSObject
{
    BOOL mIsBootCamp;
    BOOL mIsDeletable;
    BOOL mIsRemovable;
    BOOL mIsTrashable;
    int mAction;
    DUIOpenedVM *mOpenedVM;
    NSURL *mTrashURL;
}

@property(retain, nonatomic) NSURL *trashURL; // @synthesize trashURL=mTrashURL;
@property(retain, nonatomic) DUIOpenedVM *openedVM; // @synthesize openedVM=mOpenedVM;
@property(nonatomic) BOOL isTrashable; // @synthesize isTrashable=mIsTrashable;
@property(nonatomic) BOOL isRemovable; // @synthesize isRemovable=mIsRemovable;
@property(nonatomic) BOOL isDeletable; // @synthesize isDeletable=mIsDeletable;
@property(nonatomic) BOOL isBootCamp; // @synthesize isBootCamp=mIsBootCamp;
@property(nonatomic) int action; // @synthesize action=mAction;
- (void)dealloc;

@end

