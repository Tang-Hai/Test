//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSFormatter.h"

@class NSCharacterSet, NSString;

@interface VMSerialFormatter : NSFormatter
{
    id <VMSerialFormatterDelegate> delegate;
    NSCharacterSet *validCharSet;
    NSCharacterSet *delimiters;
    NSString *separator;
    unsigned long long charsInGroup;
    unsigned long long dashCount;
    unsigned long long altDashCount;
}

@property(nonatomic) id <VMSerialFormatterDelegate> delegate; // @synthesize delegate;
- (id)stringForObjectValue:(id)arg1;
- (BOOL)getObjectValue:(id *)arg1 forString:(id)arg2 errorDescription:(id *)arg3;
- (void)postDelegateMethodForString:(id)arg1;
- (BOOL)isPartialStringValid:(id *)arg1 proposedSelectedRange:(struct _NSRange *)arg2 originalString:(id)arg3 originalSelectedRange:(struct _NSRange)arg4 errorDescription:(id *)arg5;
- (void)dealloc;
- (id)init;
- (id)initForMACAddress;
- (id)initForWindows;
- (id)initWithValidChars:(id)arg1 charsInGroup:(unsigned long long)arg2 dashCount:(unsigned long long)arg3 altDashCount:(unsigned long long)arg4 separator:(id)arg5;

@end

