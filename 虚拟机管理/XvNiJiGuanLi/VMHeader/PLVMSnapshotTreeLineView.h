//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSView.h"

@class NSArray, PLVMSnapshotNodeView;

@interface PLVMSnapshotTreeLineView : NSView
{
    PLVMSnapshotNodeView *node;
    NSArray *childNodes;
}

@property(retain, nonatomic) NSArray *childNodes; // @synthesize childNodes;
@property(retain, nonatomic) PLVMSnapshotNodeView *node; // @synthesize node;
- (void)drawRect:(struct CGRect)arg1;
- (void)drawLinesForNode:(id)arg1 childNodes:(id)arg2;
- (void)drawLineCapAtPoint:(struct CGPoint)arg1 isStartPoint:(BOOL)arg2;
- (void)dealloc;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)updateLinesForNode:(id)arg1 childNodes:(id)arg2;

@end

