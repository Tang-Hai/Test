//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSBox.h"

@class NSColor;

@interface VMBox : NSBox
{
    NSColor *fillColor;
    BOOL isDragTarget;
}

- (void)drawRect:(struct CGRect)arg1;
- (void)dealloc;
- (void)setIsDragTarget:(BOOL)arg1;
- (void)setFillColor:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

