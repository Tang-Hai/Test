//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSCustomTouchBarItem.h"

@class NSButton;

@interface PLVMZoomOpsBarItem : NSCustomTouchBarItem
{
    NSButton *mZoomBtn;
}

@property(retain, nonatomic) NSButton *zoomBtn; // @synthesize zoomBtn=mZoomBtn;
- (int)currentViewMode;
- (void)onZoomStateChanged:(id)arg1;
- (void)updateTouchBarItem;
- (void)zoomOpAction:(id)arg1;
- (void)dealloc;
- (id)initWithIdentifier:(id)arg1;

@end

