//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSWorkspace.h"

@interface NSWorkspace (VMAppKitAdditions)
+ (int)setDefaultHandlerForURLScheme:(id)arg1 toApplicationWithBundleIdentifier:(id)arg2;
+ (id)bundleInfoDictionaryOfApplicationAtURL:(id)arg1;
+ (id)bundleIdentifierOfApplicationAtURL:(id)arg1;
+ (id)bundleIdentifiersOfApplicationsForURLScheme:(id)arg1;
+ (id)bundleIdentifiersOfApplicationsForFileOrURL:(id)arg1;
+ (id)bundleIdentifierOfAssignedApplicationForFileOrURL:(id)arg1;
+ (id)bundleIdentifierOfDefaultApplicationForFileExtension:(id)arg1;
+ (id)bundleIdentifierOfDefaultApplicationForURLScheme:(id)arg1;
- (id)iconForFileTypes:(id)arg1;
- (BOOL)isAppWithBundleIdentifierRunning:(id)arg1;
- (id)runningApplicationWithBundleURL:(id)arg1;
- (int)launchAppWithPath:(id)arg1 activate:(BOOL)arg2 synchronously:(BOOL)arg3 propertiesRecord:(id)arg4 openDocumentURLs:(id)arg5 launchedURL:(id *)arg6;
- (void)openSystemPreferencesPane:(id)arg1 anchor:(id)arg2;
- (BOOL)currentUserSessionIsActive;
@end

