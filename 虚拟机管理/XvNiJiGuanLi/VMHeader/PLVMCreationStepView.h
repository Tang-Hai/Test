//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSView.h"

@class NSColor;

@interface PLVMCreationStepView : NSView
{
    long long mTag;
    NSView *_statusView;
    double _offsetXOfDrawLine;
    double _offsetYOfDrawLine;
    NSColor *_fillColor;
}

@property(retain, nonatomic) NSColor *fillColor; // @synthesize fillColor=_fillColor;
@property(nonatomic) double offsetYOfDrawLine; // @synthesize offsetYOfDrawLine=_offsetYOfDrawLine;
@property(nonatomic) double offsetXOfDrawLine; // @synthesize offsetXOfDrawLine=_offsetXOfDrawLine;
@property(nonatomic) NSView *statusView; // @synthesize statusView=_statusView;
@property(nonatomic) long long tag; // @synthesize tag=mTag;
- (void)dealloc;
- (void)drawRect:(struct CGRect)arg1;
- (struct CGPoint)toPointOfDrawLine;
- (struct CGPoint)fromPointOfDrawLine;
- (void)setDrawLineOffsetY:(double)arg1;
- (void)setDrawLineOffsetX:(double)arg1;
- (void)updateFillColor:(id)arg1;
- (id)strokeColor;

@end

