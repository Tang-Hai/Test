//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIDlgCustomHelper.h"

@class NSButton, NSImageView, NSScrollView, NSTextField, NSTextView;

@interface DUIDlgEULAHelper : DUIDlgCustomHelper
{
    NSImageView *appIconView;
    NSButton *okButton;
    NSButton *cancelButton;
    NSTextField *informativeText;
    NSTextView *textView;
    NSScrollView *scrollView;
}

- (struct DlgEULA *)adaptedDlgEULA;
- (void)doDecline:(id)arg1;
- (void)doAccept:(id)arg1;
- (void)configureConstraints;
- (id)initWithNibNamed:(id)arg1 adaptedDlg:(struct DlgCustomDialog *)arg2 title:(id)arg3 label:(id)arg4 text:(id)arg5 declineText:(id)arg6 acceptText:(id)arg7;

@end

