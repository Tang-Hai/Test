//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class DUIDlgMgr;

@interface DUIOVFTool : DUIAdaptorBase
{
    DUIDlgMgr *dlgMgr;
    BOOL _toolWillDelete;
}

+ (id)autoConfigFromProbeResult:(id)arg1;
@property(nonatomic) BOOL toolWillDelete; // @synthesize toolWillDelete=_toolWillDelete;
- (void)cancel;
- (void)probeFromSource:(id)arg1 abortHandler:(CDUnknownBlockType)arg2 doneHandler:(CDUnknownBlockType)arg3;
- (id)exportVM:(id)arg1 dest:(id)arg2 name:(id)arg3 abortHandler:(CDUnknownBlockType)arg4 doneHandler:(CDUnknownBlockType)arg5;
- (id)importFromSource:(id)arg1 dest:(id)arg2 chosenVMs:(id)arg3 abortHandler:(CDUnknownBlockType)arg4 doneHandler:(CDUnknownBlockType)arg5;
- (id)importFromSource:(id)arg1 dest:(id)arg2 name:(id)arg3 injectProperty:(id)arg4 abortHandler:(CDUnknownBlockType)arg5 doneHandler:(CDUnknownBlockType)arg6;
@property(readonly, nonatomic) struct OVFTool *adaptedOvfTool;
- (void)invalidateAdaptation;
- (id)init;

@end

