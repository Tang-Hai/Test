//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSViewController.h"

#import "PLInventoryInfoViewController.h"

@class DUIInventoryNode, NSArrayController, NSTableView;

@interface PLInventoryFolderInfoViewController : NSViewController <PLInventoryInfoViewController>
{
    NSArrayController *arrayController;
    NSTableView *folderContentsView;
    DUIInventoryNode *node;
}

@property(nonatomic) NSTableView *folderContentsView; // @synthesize folderContentsView;
@property(nonatomic) NSArrayController *arrayController; // @synthesize arrayController;
@property(retain, nonatomic) DUIInventoryNode *node; // @synthesize node;
- (void)closeView;
- (void)dealloc;
- (id)initWithInventoryNode:(id)arg1;

@end

