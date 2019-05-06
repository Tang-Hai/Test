//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSScreen, PLSession;

@interface PLVMTopology : NSObject
{
    PLSession *mSession;
}

+ (struct CGRect)defaultWindowContentBounds;
@property(nonatomic) PLSession *session; // @synthesize session=mSession;
- (void)dealloc;
- (BOOL)screensHaveSeparateSpaces;
@property(readonly, nonatomic) BOOL menuBarIsLocatedBetweenScreens;
- (struct CGRect)hostBoundingBoxForTopology:(id)arg1;
- (id)hostTopologyForScreen:(id)arg1;
- (id)hostTopologyForAllScreensShouldExcludeMenuBar:(BOOL)arg1;
@property(readonly, retain, nonatomic) NSArray *hostScreens;
@property(readonly, nonatomic) BOOL isPrimaryWindowFramePrefSet;
@property(readonly, retain, nonatomic) NSArray *hostTopologyForAllScreensExcludingMenuBar;
@property(readonly, retain, nonatomic) NSArray *hostTopologyForAllScreens;
@property(readonly, retain, nonatomic) NSScreen *primaryScreen;
@property(nonatomic) BOOL isZoomed;
@property(nonatomic) struct CGRect primaryWindowContentRect;
- (id)initWithSession:(id)arg1;

@end

