//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSWindowController.h"

@interface DUIDlgCustomHelper : NSWindowController
{
    struct DlgCustomDialog *mDialog;
}

@property struct DlgCustomDialog *mDialog; // @synthesize mDialog;
- (void)stopModalWithCode:(long long)arg1;
- (void)runModalWithCompletionHandler:(CDUnknownBlockType)arg1;
- (BOOL)handleButtonPress;
- (void)onDialogDidEnd:(id)arg1 returnCode:(long long)arg2 contextInfo:(void *)arg3;
- (void)windowDidLoad;
- (id)initWithNibNamed:(id)arg1 adaptedDlg:(struct DlgCustomDialog *)arg2 title:(id)arg3;

@end

