//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSSegmentedCell.h"

@class NSArray;

@interface VMToolbarSegmentedCell : NSSegmentedCell
{
    unsigned long long segmentDividerStyle;
    NSArray *accessibleSegments;
}

@property(nonatomic) unsigned long long segmentDividerStyle; // @synthesize segmentDividerStyle;
- (long long)lastSegmentIndex;
- (void)setControlSize:(unsigned long long)arg1;
- (unsigned long long)focusRingType;
- (void)drawWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (struct CGRect)drawingRectForBounds:(struct CGRect)arg1;
- (void)drawStandardSegment:(long long)arg1 withFrame:(struct CGRect)arg2 inView:(id)arg3;
- (double)_menuDelayTimeForSegment:(long long)arg1;
- (double)displayWidthForSegment:(long long)arg1;
- (void)setKeySegment:(long long)arg1;
- (long long)keySegment;
- (void)dealloc;
- (id)accessibilityFocusedUIElement;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (BOOL)accessibilityIsIgnored;
- (id)accessibleSegments;

@end

