//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSButton.h"

@interface VMNavigationControl : NSButton
{
}

+ (Class)cellClass;
- (void)keyDown:(id)arg1;
- (BOOL)isFlipped;
- (long long)clickIndex;
- (void)popLastItem;
- (void)popToFirst;
- (void)popItems;
- (void)pushItemWithTitle:(id)arg1 representedObject:(id)arg2 toolTip:(id)arg3;
- (id)accessibilityFocusedUIElement;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (id)accessibilityAttributeValue:(id)arg1;
- (BOOL)accessibilityIsIgnored;

@end

