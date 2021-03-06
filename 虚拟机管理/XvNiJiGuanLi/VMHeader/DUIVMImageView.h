//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSImageView.h"

#import "NSDraggingSource.h"
#import "NSPasteboardItemDataProvider.h"

@class NSString, NSURL;

@interface DUIVMImageView : NSImageView <NSDraggingSource, NSPasteboardItemDataProvider>
{
    NSURL *mVmPath;
    NSString *mVmTitle;
}

@property(copy, nonatomic) NSString *vmTitle; // @synthesize vmTitle=mVmTitle;
@property(retain, nonatomic) NSURL *vmPath; // @synthesize vmPath=mVmPath;
- (void)pasteboard:(id)arg1 item:(id)arg2 provideDataForType:(id)arg3;
- (unsigned long long)draggingSession:(id)arg1 sourceOperationMaskForDraggingContext:(long long)arg2;
- (void)mouseDragged:(id)arg1;
- (void)setVMPath:(id)arg1 vmTitle:(id)arg2;
- (void)dealloc;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

