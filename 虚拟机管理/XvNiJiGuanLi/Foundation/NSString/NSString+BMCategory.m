//
//  NSString+BMCategory.m
//  BMBasekit
//
//  Created by DennisDeng on 12-1-6.
//  Copyright (c) 2012年 DennisDeng. All rights reserved.
//

#import "NSString+BMCategory.h"
#import "NSDate+BMCategory.h"
#import "NSDecimalNumber+BMCategory.h"
#import "NSObject+BMCategory.h"
//#import "UIDevice+Category.h"
#import "NSString+BMRegEx.h"


@implementation NSString (BMCategory)

+ (NSString *)bm_stringTrim:(NSString *)str
{
    NSString *string1;
    
    string1 = [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    
    return string1;
}

+ (NSString *)bm_stringTrimStart:(NSString *)str
{
    NSString *string1;
    
    string1 = [[str stringByAppendingString:@"a"] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    
    return [string1 substringToIndex:[string1 length]-1];
}

+ (NSString *)bm_stringTrimEnd:(NSString *)str
{
    NSString *string1;
    
    string1 = [[@"a" stringByAppendingString:str] stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    
    return [string1 substringFromIndex:1];
}

+ (NSString *)bm_stringTrimAllSpace:(NSString *)trimmingStr
{
    return [trimmingStr bm_trimAllSpace];
}

- (NSString *)bm_trim
{
    return [self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
}

- (NSString *)bm_trimSpace
{
    return [self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
}

// @"@／：；（）¥「」＂、[]{}#%-*+=_\\|~＜＞$€^•'@#$%^&*()_+'\""
- (NSString *)bm_trimWithCharacters:(NSString *)characters
{
    if ([characters bm_isNotEmpty])
    {
        // 定义一个特殊字符的集合
        NSCharacterSet *set = [NSCharacterSet characterSetWithCharactersInString:characters];
        // 过滤字符串的特殊字符
        return [self stringByTrimmingCharactersInSet:set];
    }
    else
    {
        return self;
    }
}

- (NSString *)bm_trimAllSpace
{
    NSString *resultStr;
    
    resultStr = [self stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
    
    NSArray *components = [resultStr componentsSeparatedByCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
    components = [components filteredArrayUsingPredicate:[NSPredicate predicateWithFormat:@"SELF != ' ' AND SELF != '\t'"]];
    resultStr = [components componentsJoinedByString:@""];
    
    return resultStr;
}

- (BOOL)bm_containString:(NSString *)string
{
    return ([self rangeOfString:string].location == NSNotFound) ? NO : YES;
}

- (BOOL)bm_containString:(NSString *)string options:(NSStringCompareOptions)mask
{
    NSUInteger location = [self rangeOfString:string options:mask].location;
    return (location == NSNotFound) ? NO : YES;
}

// 添加随机数
+ (NSString *)bm_string:(NSString *)str appendRandom:(NSUInteger)ram
{
    int randValue = arc4random();
    if (randValue < 0)
    {
        randValue = randValue * -1;
    }
    randValue = randValue % (ram+1);
    return [NSString stringWithFormat:@"%@%d", str, randValue];
}

+ (NSString *)bm_string:(NSString *)str appendRandom:(NSUInteger)ram startFrom:(NSUInteger)start
{
    NSUInteger randValue = arc4random();
    randValue = randValue % (ram+1-start) + start;
    return [NSString stringWithFormat:@"%@%lu", str, (unsigned long)randValue];
}

- (NSInteger)bm_indexOfCharacter:(char)character
{
    for (NSUInteger i = 0; i < [self length]; i++)
    {
        if ([self characterAtIndex:i] == character)
        {
            return i;
        }
    }
    
    return NSNotFound;
}

- (NSString *)bm_subStringFromCharacter:(char)character
{
    NSInteger index = [self bm_indexOfCharacter:character];
    if (index != NSNotFound)
    {
        return [self substringFromIndex:(NSUInteger)index];
    }
    else
    {
        return nil;
    }
}

- (NSString *)bm_subStringToCharacter:(char)character
{
    NSInteger index = [self bm_indexOfCharacter:character];
    if (index != NSNotFound)
    {
        return [self substringToIndex:(NSUInteger)index];
    }
    else
    {
        return nil;
    }
}

- (NSString *)bm_subStringFromChar:(char)charStart toChar:(char)charEnd
{
    NSUInteger startIndex = 0, endIndex = 0;
    NSUInteger length = 0;
    
    for (NSUInteger i = 0; i < [self length]; i++)
    {
        if ([self characterAtIndex:i] == charStart && startIndex == 0)
        {
            startIndex = i+1;
            i += 1;
            continue;
        }
        if ([self characterAtIndex:i] == charEnd)
        {
            endIndex = i;
            break;
        }
    }
    
    if (endIndex != 0)
    {
        length = endIndex - startIndex;
    }
    if (length != 0)
    {
        NSRange rang = NSMakeRange(startIndex, length);
        
        return [self substringWithRange:rang];
    }
    
    return nil;
}

+ (NSString *)bm_storeStringWithBitSize:(double)bsize
{
    if (bsize < 1024)
    {
        return [NSString stringWithFormat:@"%ldB", (long)bsize];
    }
    else if (bsize < 1024*1024)
    {
        double kbsize = (CGFloat)bsize / 1024;
        return [NSString stringWithFormat:@"%0.2fKB", kbsize];
    }
    else if (bsize < 1024*1024*1024)
    {
        double kbsize = (CGFloat)bsize / (1024*1024);
        return [NSString stringWithFormat:@"%0.2fMB", kbsize];
    }
    else
    {
        double kbsize = (CGFloat)bsize / (1024*1024*1024);
        return [NSString stringWithFormat:@"%0.2fGB", kbsize];
    }
}

+ (NSString *)bm_countStringWithCount:(NSUInteger)count
{
    if (count < 999)
    {
        return [NSString stringWithFormat:@"%ld", (long)count];
    }
    else if (count < 99000)
    {
        NSUInteger kcount = count / 1000;
        return [NSString stringWithFormat:@"%ldK", (long)kcount];
    }
    else
    {
        return @"99k+";
    }
}

// 得到一个时间格式为:02天 14时 49分 16秒
+ (NSString *)bm_dayHourMinuteSecondStringWithSecond:(NSUInteger)second
{
    NSUInteger days = second / SECONDS_IN_DAY;
    NSUInteger hours = (second / SECONDS_IN_HOUR) % 24;
    NSUInteger minutes = (second / SECONDS_IN_MINUTE) % 60;
    NSUInteger seconds = second % 60;
    
    return [NSString stringWithFormat:@"%@天 %@时 %@分 %@秒", @(days), @(hours), @(minutes), @(seconds)];
}

// 判断是否为整形
- (BOOL)bm_isPureInt
{
    NSScanner* scan = [NSScanner scannerWithString:self];
    
    int val;
    
    return [scan scanInt:&val] && [scan isAtEnd];
}

// 判断是否为浮点形
- (BOOL)bm_isPureFloat
{
    NSScanner* scan = [NSScanner scannerWithString:self];
    
    float val;
    
    return [scan scanFloat:&val] && [scan isAtEnd];
}

+ (NSUInteger)bm_integerFromStr:(NSString *)string withBase:(NSInteger)base
{
    return (NSUInteger)strtoull([string UTF8String], NULL, (int)base);
}

// 转换16进制字符串为10进制数字
+ (NSUInteger)bm_integerFromHexStr:(NSString *)hexString
{
    return (NSUInteger)strtoull([hexString UTF8String], 0, 16);
}

- (NSUInteger)bm_hexStrToInteger
{
    return [NSString bm_integerFromHexStr:self];
}

// 转换10进制数字为16进制字符串
+ (NSString *)bm_hexStrFromInteger:(NSUInteger)intNum
{
    NSString *nLetterValue;
    NSString *str = @"";
    
    NSUInteger ttmpig;
    for (NSUInteger i = 0; i < 9; i++)
    {
        ttmpig = intNum%16;
        intNum = intNum/16;
        switch (ttmpig)
        {
            case 10:
                nLetterValue =@"A"; break;
            case 11:
                nLetterValue =@"B"; break;
            case 12:
                nLetterValue =@"C"; break;
            case 13:
                nLetterValue =@"D"; break;
            case 14:
                nLetterValue =@"E"; break;
            case 15:
                nLetterValue =@"F"; break;
            default:nLetterValue=[[NSString alloc] initWithFormat:@"%@", @(ttmpig)];
                
        }
        
        str = [nLetterValue stringByAppendingString:str];
        
        if (intNum == 0)
        {
            break;
        }
    }
    
    return str;
}

- (NSString *)bm_toJsonString;
{
    return [NSString stringWithFormat:@"\"%@\"",
            [[self stringByReplacingOccurrencesOfString:@"\n" withString:@"\\n"] stringByReplacingOccurrencesOfString:@"\""withString:@"\\\""]
            ];
}

- (NSString *)bm_escapeHTML
{
    NSMutableString *result = [[NSMutableString alloc] initWithString:self];
    
    [result replaceOccurrencesOfString:@"&" withString:@"&amp;" options:NSLiteralSearch range:NSMakeRange(0, [result length])];
    [result replaceOccurrencesOfString:@"<" withString:@"&lt;" options:NSLiteralSearch range:NSMakeRange(0, [result length])];
    [result replaceOccurrencesOfString:@">" withString:@"&gt;" options:NSLiteralSearch range:NSMakeRange(0, [result length])];
    [result replaceOccurrencesOfString:@"\"" withString:@"&quot;" options:NSLiteralSearch range:NSMakeRange(0, [result length])];
    [result replaceOccurrencesOfString:@"'" withString:@"&#39;" options:NSLiteralSearch range:NSMakeRange(0, [result length])];
    return result;
}

- (NSURL *)bm_toURL
{
    if ([self bm_isNotEmpty])
    {
        return [NSURL URLWithString:self];
    }
    return nil;
}

+ (NSString *)bm_convertUnicode:(NSString *)aString
{
    //NSString *ret = [aString replace:RX(@"\\\\[uU]\\w{4}")
    NSString *ret = [aString bm_replace:RX(@"\\\\?\\\\[uU]\\w{4}")
                              withBlock:^NSString *(NSString *match) {
                                  NSString *str = [NSString stringWithCString:[match cStringUsingEncoding:NSUTF8StringEncoding]
                                                                     encoding:NSNonLossyASCIIStringEncoding];
                                  return str ?: match;
                              }];

    return ret;
}

- (NSString *)bm_convertUnicode
{
    return [NSString bm_convertUnicode:self];
}

@end


#pragma mark Size

@implementation NSString (BMSize)




@end


#pragma mark -
#pragma mark paths

@implementation NSString (BMpaths)

#pragma mark Standard Paths

- (NSString *)bm_getFullFileExtension
{
    NSString *extension = [self pathExtension];
    if (![extension isEqualToString:@""])
    {
        extension = [NSString stringWithFormat:@".%@", extension];
    }
    
    return extension;
}

+ (NSString *)bm_cachesPath
{
    static dispatch_once_t onceToken;
    static NSString *cachedPath;
    
    dispatch_once(&onceToken, ^{
        cachedPath = [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject];
    });
    
    return cachedPath;
}

+ (NSString *)bm_documentsPath
{
    static dispatch_once_t onceToken;
    static NSString *cachedPath;
    
    dispatch_once(&onceToken, ^{
        cachedPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
    });
    
    return cachedPath;
}

+ (NSString *)bm_libraryPath
{
    static dispatch_once_t onceToken;
    static NSString *cachedPath;
    
    dispatch_once(&onceToken, ^{
        cachedPath = [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) lastObject];
    });
    
    return cachedPath;
}

+ (NSString *)bm_bundlePath
{
    return [[NSBundle mainBundle] bundlePath];
}

+ (NSString *)bm_applicationPath
{
    return [NSBundle mainBundle].executablePath;
}

+ (NSString *)bm_applicationName
{
    return [NSString bm_applicationPath].lastPathComponent;
}


#pragma mark - Temporary Paths

+ (NSString *)bm_temporaryPath
{
    static dispatch_once_t onceToken;
    static NSString *cachedPath;
    
    dispatch_once(&onceToken, ^{
        cachedPath = NSTemporaryDirectory();
    });
    
    return cachedPath;
}

+ (NSString *)bm_pathForTemporaryFile
{
    CFUUIDRef newUniqueId = CFUUIDCreate(kCFAllocatorDefault);
    CFStringRef newUniqueIdString = CFUUIDCreateString(kCFAllocatorDefault, newUniqueId);
    NSString *tmpPath = [[NSString bm_temporaryPath] stringByAppendingPathComponent:(__bridge NSString *)newUniqueIdString];
    CFRelease(newUniqueId);
    CFRelease(newUniqueIdString);
    
    return tmpPath;
}

#pragma mark Working with Paths

// sdfds123 --> sdfds124
- (NSString *)bm_pathByIncrementingSequenceNumber
{
    NSString *baseName = [self stringByDeletingPathExtension];
    NSString *extension = [self pathExtension];
    
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"\\(([0-9]+)\\)$" options:0 error:NULL];
    __block NSInteger sequenceNumber = 0;
    
    [regex enumerateMatchesInString:baseName options:0 range:NSMakeRange(0, [baseName length]) usingBlock:^(NSTextCheckingResult *match, NSMatchingFlags flags, BOOL *stop){
        
        NSRange range = [match rangeAtIndex:1]; // first capture group
        NSString *substring= [self substringWithRange:range];
        
        sequenceNumber = [substring integerValue];
        *stop = YES;
    }];
    
    NSString *nakedName = [baseName bm_pathByDeletingSequenceNumber];
    
    if ([extension isEqualToString:@""])
    {
        return [nakedName stringByAppendingFormat:@"(%ld)", (long)sequenceNumber+1];
    }
    
    return [[nakedName stringByAppendingFormat:@"(%ld)", (long)sequenceNumber+1] stringByAppendingPathExtension:extension];
}

// sdfds123 --> sdfds
- (NSString *)bm_pathByDeletingSequenceNumber
{
    NSString *baseName = [self stringByDeletingPathExtension];
    
    NSRegularExpression *regex = [NSRegularExpression regularExpressionWithPattern:@"\\([0-9]+\\)$" options:0 error:NULL];
    __block NSRange range = NSMakeRange(NSNotFound, 0);
    
    [regex enumerateMatchesInString:baseName options:0 range:NSMakeRange(0, [baseName length]) usingBlock:^(NSTextCheckingResult *match, NSMatchingFlags flags, BOOL *stop) {
        
        range = [match range];
        
        *stop = YES;
    }];
    
    if (range.location != NSNotFound)
    {
        return [self stringByReplacingCharactersInRange:range withString:@""];
    }
    
    return self;
}

@end


