//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

//#import "NSView.h"

//#import "NSAnimationDelegate.h"
//#import "PLVMSnapshotNodeViewDelegate.h"
//NSObject<PLSnapshotDataSource>
@class NSDictionary, NSObject, NSString, NSViewAnimation, PLVMSnapshotTreeLineView;

@interface PLVMSnapshotTreeView : NSView //<PLVMSnapshotNodeViewDelegate, NSAnimationDelegate>
{
    NSObject<PLSnapshotDataSource> *dataSource;
    NSDictionary *nodes;
    PLVMSnapshotTreeLineView *treeLineView;
    NSViewAnimation *currentAnimation;
    BOOL needsLayout;
    BOOL shouldAnimateLayout;
    BOOL enabled;
    BOOL hasPendingReload;
    double scale;
    struct CGRect layoutBounds;
    BOOL mIsPerformingLayout;
}

+ (id)keyPathsForValuesAffectingValueForKey:(id)arg1;
@property(nonatomic) BOOL isPerformingLayout; // @synthesize isPerformingLayout=mIsPerformingLayout;
@property(nonatomic) BOOL hasPendingReload; // @synthesize hasPendingReload;
@property(nonatomic) BOOL shouldAnimateLayout; // @synthesize shouldAnimateLayout;
@property(nonatomic) struct CGRect layoutBounds; // @synthesize layoutBounds;
@property(nonatomic) BOOL enabled; // @synthesize enabled;
@property(nonatomic) double scale; // @synthesize scale;
@property(retain, nonatomic) NSDictionary *nodes; // @synthesize nodes;
@property(nonatomic) id <PLSnapshotDataSource> dataSource; // @synthesize dataSource;
@property(retain, nonatomic) NSViewAnimation *currentAnimation; // @synthesize currentAnimation;
- (id)currentStateNodeView;
- (void)magnifyWithEvent:(id)arg1;
- (unsigned int)treeHeight:(id)arg1;
- (void)rescale;
- (void)resizeWithOldSuperviewSize:(struct CGSize)arg1;
- (void)doubleClickForNodeView:(id)arg1;
- (BOOL)showInfoButtonForNodeView:(id)arg1;
- (void)openInfoPanelForNodeView:(id)arg1;
- (id)contextMenuForNodeView:(id)arg1;
- (BOOL)disableActions;
- (void)nodeView:(id)arg1 setName:(id)arg2;
- (BOOL)nodeView:(id)arg1 shouldEndEditingName:(id)arg2 reason:(int)arg3;
- (BOOL)shouldEditNodeView:(id)arg1;
- (void)reloadNodeView:(id)arg1;
- (void)setSelected:(BOOL)arg1 nodeView:(id)arg2 extendSelection:(BOOL)arg3;
- (void)insertNewline:(id)arg1;
- (void)selectAll:(id)arg1;
- (void)deleteBackward:(id)arg1;
- (void)deleteForward:(id)arg1;
- (void)moveDown:(id)arg1;
- (void)moveUp:(id)arg1;
- (void)moveRight:(id)arg1;
- (void)moveLeft:(id)arg1;
- (void)keyDown:(id)arg1;
- (BOOL)acceptsFirstResponder;
- (void)scrollToItem:(id)arg1;
- (id)selectedNodes;
- (void)stopAnimating;
- (BOOL)hasAnimation;
- (id)rootNodes;
- (id)allNodes;
- (id)itemForNode:(id)arg1;
- (void)closeNodes:(id)arg1;
- (void)buildNodes:(id)arg1 forParentItem:(id)arg2 parentNode:(id)arg3;
- (void)updateNode:(id)arg1 withItem:(id)arg2;
- (void)updateBoundsAndFrame;
- (void)updateTreeLines;
- (void)animation:(id)arg1 didReachProgressMark:(float)arg2;
- (void)animationDidEnd:(id)arg1;
- (void)performAnimatedMoves;
- (void)performLayout;
- (struct CGRect)layoutNode:(id)arg1 atPosition:(struct CGPoint)arg2 maxColumnWidth:(double *)arg3;
- (void)setNeedsLayout:(BOOL)arg1;
- (struct CGRect)screenRectForItem:(id)arg1;
- (id)screenshotViewForItem:(id)arg1;
- (id)selectedItems;
- (void)beginEditingField:(int)arg1 forItem:(id)arg2;
- (void)selectItem:(id)arg1 extendSelection:(BOOL)arg2;
- (void)reloadItem:(id)arg1;
- (void)reloadData:(BOOL)arg1;
- (void)awakeFromNib;
- (void)dealloc;
- (id)accessibilityAttributeValue:(id)arg1;
- (BOOL)accessibilityIsAttributeSettable:(id)arg1;
- (id)accessibilityFocusedUIElement;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (BOOL)accessibilityIsIgnored;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

