//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSControl.h"

@class NSMutableArray;

@interface VMCodeExchangeView : NSControl
{
    unsigned long long codeLength;
    NSMutableArray *codeCells;
    NSMutableArray *cellRects;
    long long insertIndex;
    double minimumPadding;
}

@property(nonatomic) unsigned long long codeLength; // @synthesize codeLength;
@property(nonatomic) double minimumPadding; // @synthesize minimumPadding;
- (void)setupCells;
- (id)prototypeDigitCell;
- (void)drawRect:(struct CGRect)arg1;
- (void)keyDown:(id)arg1;
- (void)mouseDown:(id)arg1;
- (BOOL)isOpaque;
- (int)intValue;
- (void)setIntValue:(int)arg1;
@property(nonatomic) struct _NSRange selectedTextRange;
- (id)selectedText;
- (void)setStringValue:(id)arg1;
- (id)stringValue;
- (BOOL)canBecomeKey;
- (BOOL)acceptsFirstResponder;
- (void)setEnabled:(BOOL)arg1;
- (void)setFrame:(struct CGRect)arg1;
- (id)cell;
- (void)setCell:(id)arg1;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (id)accessibilityFocusedUIElement;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (void)accessibilitySetValue:(id)arg1 forAttribute:(id)arg2;
- (BOOL)accessibilityIsAttributeSettable:(id)arg1;
- (id)accessibilityAttributeValue:(id)arg1;
- (BOOL)accessibilityIsIgnored;

@end

