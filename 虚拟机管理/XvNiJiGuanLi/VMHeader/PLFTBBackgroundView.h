//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSView.h"

@interface PLFTBBackgroundView : NSView
{
    BOOL mIsPlaceholder;
    BOOL mIsHighlighted;
    int mEdge;
    BOOL mNeedsLayout;
    BOOL mIsEmbedded;
}

@property(nonatomic) BOOL isEmbedded; // @synthesize isEmbedded=mIsEmbedded;
@property(nonatomic) BOOL needsLayout; // @synthesize needsLayout=mNeedsLayout;
@property(nonatomic) int edge; // @synthesize edge=mEdge;
@property(nonatomic) BOOL isHighlighted; // @synthesize isHighlighted=mIsHighlighted;
@property(nonatomic) BOOL isPlaceholder; // @synthesize isPlaceholder=mIsPlaceholder;
- (void)drawRect:(struct CGRect)arg1;
- (void)drawEdgeMarkers:(struct CGRect)arg1 isVertical:(BOOL)arg2;
- (struct CGRect)titleBarEdgeRect;
- (id)semiDarkBorderColor;
- (id)darkBorderColor;
- (BOOL)shouldDrawSecondaryHighlight;
- (BOOL)isOpaque;
- (void)resizeSubviewsWithOldSize:(struct CGSize)arg1;
- (void)dealloc;
- (void)viewWillDraw;
- (BOOL)edgeIsVertical;
- (void)performLayout;
- (id)initWithFrame:(struct CGRect)arg1 isPlaceholder:(BOOL)arg2;

@end

