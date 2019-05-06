//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSPopUpButtonCell.h"

#import "PLFTBThemeButtonCell.h"

@class NSImage, NSString;

@interface PLFTBMenuButtonCell : NSPopUpButtonCell <PLFTBThemeButtonCell>
{
    NSImage *mButtonImage;
    BOOL mShouldDrawRollover;
    BOOL mTemporarilyHidden;
    BOOL mTemporarilyDisabled;
}

@property(nonatomic) BOOL temporarilyDisabled; // @synthesize temporarilyDisabled=mTemporarilyDisabled;
@property(nonatomic) BOOL temporarilyHidden; // @synthesize temporarilyHidden=mTemporarilyHidden;
@property(readonly, nonatomic) BOOL shouldDrawRollover; // @synthesize shouldDrawRollover=mShouldDrawRollover;
@property(retain) NSImage *buttonImage; // @synthesize buttonImage=mButtonImage;
- (BOOL)showsBorderOnlyWhileMouseInside;
- (void)mouseExited:(id)arg1;
- (void)mouseEntered:(id)arg1;
- (long long)interiorBackgroundStyle;
- (void)drawWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (BOOL)isEnabled;
- (void)setShouldDrawRollover:(BOOL)arg1;
- (struct CGRect)imageRectForBounds:(struct CGRect)arg1;
- (id)image;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

