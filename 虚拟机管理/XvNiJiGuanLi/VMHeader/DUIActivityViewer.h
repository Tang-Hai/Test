//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIActivityStackWindowController.h"

@class NSString;

@interface DUIActivityViewer : DUIActivityStackWindowController
{
    NSString *mPreferredViewControllerNibName;
}

@property(copy, nonatomic) NSString *preferredViewControllerNibName; // @synthesize preferredViewControllerNibName=mPreferredViewControllerNibName;
- (id)viewControllerForProgress:(id)arg1;
- (void)removeProgress:(id)arg1;
- (void)addProgress:(id)arg1 withViewController:(id)arg2;
- (void)showWithProgress:(id)arg1 detailText:(id)arg2;
- (void)replaceViewController:(id)arg1 forProgress:(id)arg2;
- (void)replaceProgress:(id)arg1 withProgress:(id)arg2 withViewController:(id)arg3;
- (id)autosaveFrameName;
- (void)windowDidLoad;
- (void)dealloc;
- (void)onProgressDone:(id)arg1;
- (id)init;
- (id)initWithWindowNibName:(id)arg1;
- (id)initWithWindowNibName:(id)arg1 subviewNibName:(id)arg2;

@end

