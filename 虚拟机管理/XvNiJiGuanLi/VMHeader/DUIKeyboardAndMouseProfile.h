//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@class NSMutableArray, NSMutableDictionary, NSString;

@interface DUIKeyboardAndMouseProfile : NSObject
{
    NSMutableDictionary *cachedMappings;
    NSMutableArray *sortedCachedKeyMappings;
    NSMutableArray *sortedCachedMouseShortcuts;
    NSMutableArray *sortedCachedApplicationShortcuts;
    NSMutableArray *sortedCachedApplicationVisibleShortcuts;
    id <DUIKeyboardAndMousePrefsProxy> mPrefsProxy;
    NSString *_profileKey;
}

+ (void)initialize;
@property(retain, nonatomic) NSString *profileKey; // @synthesize profileKey=_profileKey;
@property(retain) id <DUIKeyboardAndMousePrefsProxy> prefsProxy; // @synthesize prefsProxy=mPrefsProxy;
- (void)clearKeyMappings;
- (void)onProfileChanged:(id)arg1;
- (void)onKeyBoardTypeChanged:(id)arg1;
- (void)onInputSourceChanged:(id)arg1;
- (void)replaceMappings:(id)arg1 withMappings:(const struct MappingDefault *)arg2 count:(int)arg3 enableKeyMappings:(BOOL)arg4;
- (int)maxMappingKey;
- (void)importOldPreferences:(struct KMProfile *)arg1;
- (BOOL)hasProfileWithName:(id)arg1;
- (id)generateUniqueProfileNameWithType:(int)arg1;
- (id)generateUniqueProfileKey;
- (BOOL)updateCurrentLanguageKeyboardMappings;
- (void)commonInitializerUpdateLegacy;
- (BOOL)addNewMappings:(const struct MappingDefault *)arg1 count:(int)arg2 mappingKeyStart:(int)arg3 toProfile:(struct KMProfile *)arg4;
- (BOOL)replaceLegacyMappings:(const struct MappingDefault *)arg1 count:(int)arg2 withMappings:(const struct MappingDefault *)arg3 count:(int)arg4 inProfile:(struct KMProfile *)arg5;
- (void)commonInitializerReadPreferences;
- (void)commonInitializer;
- (void)updateSortedLists;
- (void)addMappings:(const struct MappingDefault *)arg1 count:(int)arg2 mappingKeyStart:(int)arg3 toProfile:(struct KMProfile *)arg4;
- (void)removeMappings:(id)arg1;
- (id)generateUniqueMappingKey;
- (BOOL)isEqual:(id)arg1;
- (id)description;
- (void)dealloc;
- (id)languageSpecificKeyMappings;
- (id)languageSpecificKeyMappingsLanguageKeyboardID;
@property(nonatomic) BOOL languageSpecificKeyMappingsEnabled;
- (void)applicationShortcutsRestoreDefaults;
- (id)applicationVisibleShortcuts;
- (id)applicationShortcuts;
- (void)mouseShortcutsRestoreDefaults;
- (id)mouseShortcuts;
- (void)removeKeyMapping:(id)arg1;
- (id)mappingByAddingNewKeyMapping:(id)arg1 toGuest:(id)arg2 enabled:(BOOL)arg3;
- (void)keyMappingsRestoreDefaults;
- (id)keyMappings;
@property(nonatomic) BOOL keyMappingsEnabled;
@property(nonatomic) int cmdKeyFilterType;
@property(nonatomic) BOOL osShortcutsEnabled;
@property(nonatomic) int profileType;
@property(retain, nonatomic) NSString *profileName;
- (int)profileTypeFromKey;
- (id)mappingForKey:(int)arg1;
- (id)mappingForCommandID:(id)arg1;
- (id)initByDuplicatingProfile:(id)arg1 withPrefsProxy:(id)arg2;
- (id)initAsNewProfile:(BOOL)arg1 ofType:(int)arg2 withPrefsProxy:(id)arg3;
- (id)initWithExistingProfileKey:(id)arg1 withPrefsProxy:(id)arg2;

@end

