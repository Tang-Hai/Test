//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

#import "NSWindowDelegate.h"

@class NSString;

@interface PLBaseWindowProvider : NSObject <NSWindowDelegate>
{
}

- (void)windowDidDeminiaturize:(id)arg1;
- (void)windowDidChangeOcclusionState:(id)arg1;
- (void)windowDidMove:(id)arg1;
- (void)windowDidResize:(id)arg1;
- (void)windowDidEndLiveResize:(id)arg1;
- (void)windowWillStartLiveResize:(id)arg1;
- (id)windowWillReturnFieldEditor:(id)arg1 toObject:(id)arg2;
- (BOOL)windowShouldZoom:(id)arg1 toFrame:(struct CGRect)arg2;
- (struct CGRect)windowWillUseStandardFrame:(id)arg1 defaultFrame:(struct CGRect)arg2;
- (struct CGSize)window:(id)arg1 willUseFullScreenContentSize:(struct CGSize)arg2;
- (struct CGSize)windowWillResize:(id)arg1 toSize:(struct CGSize)arg2;
- (BOOL)windowShouldClose:(id)arg1;
- (void)closeContent:(id)arg1;
- (id)contentForWindow:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

