//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSView.h"

@class NSGradient, NSMapTable, NSMutableArray;

@interface VMActionBarView : NSView
{
    NSGradient *backgroundGradient;
    NSGradient *inactiveBackgroundGradient;
    double defaultMargin;
    double minimumTitleWidth;
    double leftMargin;
    double rightMargin;
    NSView *titleItem;
    NSMutableArray *leftItems;
    NSMutableArray *rightItems;
    NSMapTable *itemSettings;
    BOOL needsLayout;
}

@property(retain) NSView *titleItem; // @synthesize titleItem;
@property double minimumTitleWidth; // @synthesize minimumTitleWidth;
@property double rightMargin; // @synthesize rightMargin;
@property double leftMargin; // @synthesize leftMargin;
@property double defaultMargin; // @synthesize defaultMargin;
@property(retain) NSGradient *inactiveBackgroundGradient; // @synthesize inactiveBackgroundGradient;
@property(retain) NSGradient *backgroundGradient; // @synthesize backgroundGradient;
- (void)onWindowDidChangeMain:(id)arg1;
- (void)viewDidMoveToWindow;
- (void)viewWillMoveToWindow:(id)arg1;
- (void)viewWillDraw;
- (void)resizeSubviewsWithOldSize:(struct CGSize)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;
- (id)keysAffectingLayout:(id)arg1;
- (BOOL)shouldSizeToFitForItem:(id)arg1;
- (double)verticalOffsetForItem:(id)arg1;
- (double)marginForItem:(id)arg1;
- (id)performLayoutForItems:(id)arg1 placeAfterItem:(id)arg2;
- (void)performLayout;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)setNeedsLayout;
- (void)removeAllItems;
- (void)removeItem:(id)arg1;
- (void)addItem:(id)arg1 atLocation:(int)arg2 verticalOffset:(double)arg3 sizeToFit:(BOOL)arg4 customMargin:(double)arg5;
- (void)addItem:(id)arg1 atLocation:(int)arg2 verticalOffset:(double)arg3 sizeToFit:(BOOL)arg4;

@end

