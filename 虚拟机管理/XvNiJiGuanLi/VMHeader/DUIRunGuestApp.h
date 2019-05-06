//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSArray, NSDictionary, NSString;

@interface DUIRunGuestApp : NSObject
{
    id <DUITrackableProxy> trackableProxyImpl;
    BOOL mWaitForDockerQuit;
    NSDictionary *mFileHandlers;
    NSArray *mFileLocations;
    NSString *mGuestAppURI;
    NSArray *mUrlLocations;
    NSDictionary *mUrlHandlers;
}

+ (void)registerSubclass;
+ (id)combineGuestAppActions:(id)arg1 withActions:(id)arg2;
+ (id)actionsForLocations:(id)arg1 withHandlers:(id)arg2 forActionName:(id)arg3 treatAsFiles:(BOOL)arg4 defaultActionURI:(id)arg5;
+ (void)runGuestAppWithUserInfo:(id)arg1 vmUUID:(id)arg2;
@property(readonly, nonatomic) BOOL waitForDockerQuit; // @synthesize waitForDockerQuit=mWaitForDockerQuit;
@property(readonly, retain, nonatomic) NSDictionary *urlHandlers; // @synthesize urlHandlers=mUrlHandlers;
@property(readonly, retain, nonatomic) NSArray *urlLocations; // @synthesize urlLocations=mUrlLocations;
@property(readonly, copy, nonatomic) NSString *guestAppURI; // @synthesize guestAppURI=mGuestAppURI;
@property(readonly, retain, nonatomic) NSArray *fileLocations; // @synthesize fileLocations=mFileLocations;
@property(readonly, retain, nonatomic) NSDictionary *fileHandlers; // @synthesize fileHandlers=mFileHandlers;
- (void)dealloc;
- (id)initWithUserInfo:(id)arg1 vmUUID:(id)arg2;
- (void)invalidateTrackableProxy;
- (id)trackableProxy;

@end

