//
//  NSBundle+BMResource.m
//  Pods
//
//  Created by DennisDeng on 2018/3/29.
//
//

#import "NSBundle+BMResource.h"


NSString *const kTableDefault = @"Localizable";

static inline NSString *getBundleName(NSString *bundleName)
{
    if ([bundleName rangeOfString:@".bundle"].location != NSNotFound)
    {
        return bundleName;
    }
    
    return [bundleName stringByAppendingPathExtension:@"bundle"];
}

static inline NSString *getAssetsName(NSString *assetsName)
{
    if ([assetsName rangeOfString:@".xcassets"].location != NSNotFound)
    {
        return assetsName;
    }
    
    return [assetsName stringByAppendingPathExtension:@"xcassets"];
}

@implementation NSBundle (BMResource)


#pragma mark localizedString

+ (NSBundle *)bm_mainLocalizedBundle
{
    return [NSBundle bm_localizedBundleWithBundle:[NSBundle mainBundle]];
}

+ (NSBundle *)bm_mainLocalizedBundleWithLanguage:(NSString *)language
{
    return [NSBundle bm_localizedBundleWithBundle:[NSBundle mainBundle] language:language];
}

+ (NSBundle *)bm_localizedBundleWithBundleName:(NSString *)bundleName
{
    return [NSBundle bm_localizedBundleWithBundleName:bundleName language:nil];
}

+ (NSBundle *)bm_localizedBundleWithBundleName:(NSString *)bundleName language:(NSString *)language
{
    NSString *mainBundlePath = [[NSBundle mainBundle] resourcePath];
    NSString *basePath = [mainBundlePath stringByAppendingPathComponent:getBundleName(bundleName)];
    NSBundle *bundle = [NSBundle bundleWithPath:basePath];
    return [NSBundle bm_localizedBundleWithBundle:bundle language:language];
}

+ (NSBundle *)bm_localizedBundleWithBundle:(NSBundle *)bundle
{
    return [NSBundle bm_localizedBundleWithBundle:bundle language:nil];
}

+ (NSBundle *)bm_localizedBundleWithBundle:(NSBundle *)bundle language:(NSString *)language
{
    NSString *systemLanguage = nil;
    if (language)
    {
        systemLanguage = language;
    }
    else
    {
        // 这里返回的是app优先语言环境，NSLocal返回的是系统设置
        NSArray *languages = [[NSBundle mainBundle] preferredLocalizations];
        systemLanguage = languages.firstObject;
        
        if ([systemLanguage hasPrefix:@"zh"])
        {
            if ([systemLanguage rangeOfString:@"CN"].location != NSNotFound || [systemLanguage rangeOfString:@"Hans"].location != NSNotFound)
            {
                systemLanguage = @"zh-Hans"; // 简体中文
            }
            else
            { // zh-Hant\zh-HK\zh-TW
                systemLanguage = @"zh-Hant"; // 繁體中文
            }
        }
        else
        {
            systemLanguage = @"en";
        }
    }
    
    NSString *basePath = [bundle pathForResource:language ofType:@"lproj"];
    return [NSBundle bundleWithPath:basePath];
}

+ (NSString *)bm_localizedStringFromBundleNamed:(NSString *)bundleName forKey:(NSString *)key value:(NSString *)value
{
    return [NSBundle bm_localizedStringFromBundleNamed:bundleName forKey:key value:value table:kTableDefault];
}

+ (NSString *)bm_localizedStringFromBundleNamed:(NSString *)bundleName forKey:(NSString *)key value:(NSString *)value table:(NSString *)table
{
    NSString *mainBundlePath = [[NSBundle mainBundle] resourcePath];
    NSString *basePath = [mainBundlePath stringByAppendingPathComponent:getBundleName(bundleName)];
    NSBundle *bundle = [NSBundle bundleWithPath:basePath];

    return [bundle bm_localizedLanguageStringForKey:key value:value table:table];
}

- (NSString *)bm_localizedLanguageStringForKey:(NSString *)key value:(NSString *)value
{
    return [self bm_localizedLanguageStringForKey:key value:value table:kTableDefault];
}

- (NSString *)bm_localizedLanguageStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)table
{
    NSBundle *localizedBundle = [NSBundle bm_localizedBundleWithBundle:self];
    return [localizedBundle localizedStringForKey:key value:value table:table];
}

@end
