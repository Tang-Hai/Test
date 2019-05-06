//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUIAdaptorBase.h"

@class DUIOVFTool;

@interface DUIVMUploader : DUIAdaptorBase
{
    DUIOVFTool *mOVFTool;
}

+ (id)vmUploaderWithVM:(id)arg1 ovfTool:(id)arg2 destNode:(id)arg3;
+ (BOOL)canUploadNode:(id)arg1 toDestination:(id)arg2;
+ (BOOL)automaticallyNotifiesObserversForKey:(id)arg1;
@property(retain, nonatomic) DUIOVFTool *ovfTool; // @synthesize ovfTool=mOVFTool;
- (void)listHostsWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (void)loadDatacenterWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (void)validateHostWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
- (id)uploadWithAbortHandler:(CDUnknownBlockType)arg1 doneHandler:(CDUnknownBlockType)arg2;
@property(readonly, nonatomic) struct VMUploader *adaptedVMUploader;
- (void)dealloc;
- (id)initWithVM:(id)arg1 ovfTool:(id)arg2 destNode:(id)arg3;
- (void)setVmName:(id)arg1;
- (id)vmName;
- (void)setDatastore:(id)arg1;
- (id)datastore;
- (void)setHost:(id)arg1;
- (id)host;

@end

