//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSTextFieldCell.h"

@class NSTextView;

@interface VMGrowingTextFieldCell : NSTextFieldCell
{
    NSTextView *mTextView;
}

@property(retain, nonatomic) NSTextView *textView; // @synthesize textView=mTextView;
- (id)fieldEditorForView:(id)arg1;
- (void)dealloc;

@end

