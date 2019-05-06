//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSSliderCell.h"

@class DUIStickyMemorySizeSliderTransformer;

@interface VMMemorySliderCell : NSSliderCell
{
    int mMinSizeMB;
    int mRecommendedSizeMB;
    int mMaxSizeMB;
    DUIStickyMemorySizeSliderTransformer *mTransformer;
    long long mNumberOfTickMarksMinToRec;
    long long mTickMarkStartIndexRecToMax;
}

@property(nonatomic) long long tickMarkStartIndexRecToMax; // @synthesize tickMarkStartIndexRecToMax=mTickMarkStartIndexRecToMax;
@property(nonatomic) long long numberOfTickMarksMinToRec; // @synthesize numberOfTickMarksMinToRec=mNumberOfTickMarksMinToRec;
@property(nonatomic) int maxSizeMB; // @synthesize maxSizeMB=mMaxSizeMB;
@property(nonatomic) int recommendedSizeMB; // @synthesize recommendedSizeMB=mRecommendedSizeMB;
@property(nonatomic) int minSizeMB; // @synthesize minSizeMB=mMinSizeMB;
@property(retain, nonatomic) DUIStickyMemorySizeSliderTransformer *transformer; // @synthesize transformer=mTransformer;
- (double)tickMarkValueAtIndex:(long long)arg1;
- (void)dealloc;
- (void)configureWithMinSizeMB:(int)arg1 recommendedSizeMB:(int)arg2 maxSizeMB:(int)arg3;

@end

