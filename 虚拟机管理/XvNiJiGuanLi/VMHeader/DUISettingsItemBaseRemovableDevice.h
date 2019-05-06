//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "DUISettingsItemBaseDevice.h"

@class NSLayoutConstraint;

@interface DUISettingsItemBaseRemovableDevice : DUISettingsItemBaseDevice
{
    NSLayoutConstraint *startConnectedHeightConstraint;
    BOOL _isVigorInprogress;
    BOOL _hasCachedEvent;
    BOOL _lastConnected;
}

+ (id)keyPathsAffectingSettingsValueForKey:(id)arg1;
@property(nonatomic) BOOL lastConnected; // @synthesize lastConnected=_lastConnected;
@property(nonatomic) BOOL hasCachedEvent; // @synthesize hasCachedEvent=_hasCachedEvent;
@property(nonatomic) BOOL isVigorInprogress; // @synthesize isVigorInprogress=_isVigorInprogress;
- (BOOL)canEditProperty:(id)arg1;
@property(nonatomic) BOOL currentlyConnected;
@property(nonatomic) BOOL startConnected;
@property(nonatomic) BOOL isConnected;
- (void)doSetIsConnected:(BOOL)arg1;
- (id)removableDevice;
- (void)openView;

@end

