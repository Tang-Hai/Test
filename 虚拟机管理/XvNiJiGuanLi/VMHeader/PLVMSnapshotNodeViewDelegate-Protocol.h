//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMenu, NSString, PLVMSnapshotNodeView;

@protocol PLVMSnapshotNodeViewDelegate <NSObject>
- (BOOL)disableActions;
- (BOOL)showInfoButtonForNodeView:(PLVMSnapshotNodeView *)arg1;
- (void)openInfoPanelForNodeView:(PLVMSnapshotNodeView *)arg1;
- (void)doubleClickForNodeView:(PLVMSnapshotNodeView *)arg1;
- (NSMenu *)contextMenuForNodeView:(PLVMSnapshotNodeView *)arg1;
- (void)nodeView:(PLVMSnapshotNodeView *)arg1 setName:(NSString *)arg2;
- (BOOL)nodeView:(PLVMSnapshotNodeView *)arg1 shouldEndEditingName:(NSString *)arg2 reason:(int)arg3;
- (BOOL)shouldEditNodeView:(PLVMSnapshotNodeView *)arg1;
- (void)reloadNodeView:(PLVMSnapshotNodeView *)arg1;
- (void)setSelected:(BOOL)arg1 nodeView:(PLVMSnapshotNodeView *)arg2 extendSelection:(BOOL)arg3;
@end

