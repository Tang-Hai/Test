//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "PLAssistantPanelController.h"

@class NSArray, NSString, NSTextView, VMAutolayoutTextField;

@interface PLCreationAssistantImportEULAPanel : PLAssistantPanelController
{
    NSString *mFileName;
    NSArray *mEulas;
    VMAutolayoutTextField *_label;
    NSTextView *_text;
}

@property(nonatomic) NSTextView *text; // @synthesize text=_text;
@property(nonatomic) VMAutolayoutTextField *label; // @synthesize label=_label;
@property(retain, nonatomic) NSArray *eulas; // @synthesize eulas=mEulas;
@property(copy, nonatomic) NSString *fileName; // @synthesize fileName=mFileName;
- (BOOL)getOutput;
- (void)setInputWithFileName:(id)arg1 eulas:(id)arg2;
- (void)dealloc;
- (id)licenseText;
- (void)viewWillAppear;

@end

