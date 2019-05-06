//
//  NSAttributedString+BMCategory.m
//  BMBasekit
//
//  Created by DennisDeng on 16/7/22.
//  Copyright © 2016年 DennisDeng. All rights reserved.
//

#import "NSAttributedString+BMCategory.h"
#import <CoreText/CoreText.h>


#pragma mark -
#pragma mark NSAttributedString

@implementation NSAttributedString (BMSize)

- (CGSize)bm_sizeToFitWidth:(CGFloat)width
{
    CGSize maxSize = CGSizeMake(width, CGFLOAT_MAX);
    return [self bm_sizeToFit:maxSize lineBreakMode:NSLineBreakByCharWrapping];
}

- (CGSize)bm_sizeToFitHeight:(CGFloat)height
{
    CGSize maxSize = CGSizeMake(CGFLOAT_MAX, height);
    return [self bm_sizeToFit:maxSize lineBreakMode:NSLineBreakByCharWrapping];
}

- (CGSize)bm_sizeToFit:(CGSize)maxSize lineBreakMode:(NSLineBreakMode)lineBreakMode
{
    NSStringDrawingOptions options = NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading;
    if (lineBreakMode ==  NSLineBreakByTruncatingHead ||
        lineBreakMode ==  NSLineBreakByTruncatingTail ||
        lineBreakMode ==  NSLineBreakByTruncatingMiddle )
    {
        options |= NSStringDrawingTruncatesLastVisibleLine;
    }

    CGRect textRect = [self boundingRectWithSize:maxSize options:options context:nil];
    
    return textRect.size;
}

@end


#pragma mark -
#pragma mark NSMutableAttributedString

@implementation NSMutableAttributedString (BMCategory)




- (void)bm_setFontName:(NSString *)fontName size:(CGFloat)size
{
    [self bm_setFontName:fontName size:size range:NSMakeRange(0, [self length])];
}

//- (void)setFontName:(NSString *)fontName size:(CGFloat)size range:(NSRange)range
//{
//    // kCTFontAttributeName
//    CTFontRef aFont = CTFontCreateWithName((__bridge CFStringRef)fontName, size, NULL);
//    if (aFont)
//    {
//        [self removeAttribute:(__bridge NSString *)kCTFontAttributeName range:range]; // Work around for Apple leak
//        [self addAttribute:(__bridge NSString *)kCTFontAttributeName value:(__bridge id)aFont range:range];
//        CFRelease(aFont);
//    }
//}



//- (void)setFontFamily:(NSString *)fontFamily size:(CGFloat)size bold:(BOOL)isBold italic:(BOOL)isItalic range:(NSRange)range
//{
//    // kCTFontFamilyNameAttribute + kCTFontTraitsAttribute
//    CTFontSymbolicTraits symTrait = (isBold?kCTFontBoldTrait:0) | (isItalic?kCTFontItalicTrait:0);
//    NSDictionary *trait = [NSDictionary dictionaryWithObject:[NSNumber numberWithUnsignedLong:symTrait]
//                                                      forKey:(__bridge NSString *)kCTFontSymbolicTrait];
//    NSDictionary *attr = [NSDictionary dictionaryWithObjectsAndKeys:
//                          fontFamily,kCTFontFamilyNameAttribute,
//                          trait,kCTFontTraitsAttribute,nil];
//    
//    CTFontDescriptorRef desc = CTFontDescriptorCreateWithAttributes((__bridge CFDictionaryRef)attr);
//    if (!desc) return;
//    CTFontRef aFont = CTFontCreateWithFontDescriptor(desc, size, NULL);
//    CFRelease(desc);
//    if (!aFont) return;
//    
//    [self removeAttribute:(__bridge NSString *)kCTFontAttributeName range:range]; // Work around for Apple leak
//    [self addAttribute:(__bridge NSString *)kCTFontAttributeName value:(__bridge id)aFont range:range];
//    CFRelease(aFont);
//}


#pragma mark - Text Baseline

- (void)bm_setBaselineOffset:(CGFloat)offset
{
    [self bm_setBaselineOffset:offset range:NSMakeRange(0, self.length)];
}

- (void)bm_setBaselineOffset:(CGFloat)offset range:(NSRange)range
{
    if (range.location == NSNotFound)
    {
        return;
    }
    
    [self removeAttribute:NSBaselineOffsetAttributeName range:range]; // Work around for Apple leak
    [self addAttribute:NSBaselineOffsetAttributeName value:@(offset) range:range];
}


#pragma mark - Text Color




#pragma mark - Text Underlining

- (void)bm_setTextIsUnderlined:(BOOL)underlined
{
    [self bm_setTextIsUnderlined:underlined range:NSMakeRange(0, [self length])];
}

- (void)bm_setTextIsUnderlined:(BOOL)underlined range:(NSRange)range
{
    int32_t style = underlined ? (kCTUnderlineStyleSingle|kCTUnderlinePatternSolid) : kCTUnderlineStyleNone;
    [self bm_setTextUnderlineStyle:style range:range];
}






#pragma mark - Text Deletelining

- (void)bm_setTextIsDeletelined:(BOOL)underlined
{
    [self bm_setTextIsDeletelined:underlined range:NSMakeRange(0, [self length])];
}

- (void)bm_setTextIsDeletelined:(BOOL)underlined range:(NSRange)range
{
    int32_t style = underlined ? (NSUnderlineStyleSingle|NSUnderlinePatternSolid) : NSUnderlineStyleNone;
    [self bm_setTextDeletelineStyle:style range:range];
}





#pragma mark - LinkURL

- (void)bm_setLinkURL:(NSURL *)linkURL
{
    [self bm_setLinkURL:linkURL range:NSMakeRange(0, [self length])];
}

- (void)bm_setLinkURL:(NSURL *)linkURL range:(NSRange)range
{
    if (range.location == NSNotFound)
    {
        return;
    }
    
    [self removeAttribute:NSLinkAttributeName range:range]; // Work around for Apple leak
    [self addAttribute:NSLinkAttributeName value:linkURL range:range];
}


#pragma mark - Character Spacing

- (void)bm_setCharacterSpacing:(CGFloat)characterSpacing
{
    [self bm_setCharacterSpacing:characterSpacing range:NSMakeRange(0, [self length])];
}

- (void)bm_setCharacterSpacing:(CGFloat)characterSpacing range:(NSRange)range
{
    if (range.location == NSNotFound)
    {
        return;
    }
    
    [self addAttribute:NSKernAttributeName value:@(characterSpacing) range:range];
//    [self addAttribute:(NSString *)kCTKernAttributeName
//                 value:@(characterSpacing) // http://stackoverflow.com/a/17067994
//                 range:range];
}


#pragma mark - ParagraphStyle

- (void)bm_setParagraphStyle:(NSParagraphStyle *)paragraphStyle
{
    [self bm_setParagraphStyle:paragraphStyle range:NSMakeRange(0, self.length)];
}

// TODO: Check the behavior when applying a paragraph style only to some
//       characters in the middle of an actual paragraph.
- (void)bm_setParagraphStyle:(NSParagraphStyle *)paragraphStyle range:(NSRange)range
{
    if (range.location == NSNotFound)
    {
        return;
    }
    
    [self removeAttribute:NSParagraphStyleAttributeName range:range]; // Work around for Apple leak
    [self addAttribute:NSParagraphStyleAttributeName value:paragraphStyle range:range];
}

- (void)bm_setAttributeAlignmentStyle:(NSTextAlignment)textAlignment
                       lineSpaceStyle:(CGFloat)linesSpacing
                  paragraphSpaceStyle:(CGFloat)paragraphSpacing
                       lineBreakStyle:(NSLineBreakMode)lineBreakMode
{
    [self bm_setAttributeAlignmentStyle:textAlignment lineSpaceStyle:linesSpacing paragraphSpaceStyle:paragraphSpacing lineBreakStyle:lineBreakMode range:NSMakeRange(0, self.length)];
}

- (void)bm_setAttributeAlignmentStyle:(NSTextAlignment)textAlignment
                       lineSpaceStyle:(CGFloat)linesSpacing
                  paragraphSpaceStyle:(CGFloat)paragraphSpacing
                       lineBreakStyle:(NSLineBreakMode)lineBreakMode
                                range:(NSRange)range
{
    if (range.location == NSNotFound)
    {
        return;
    }
    
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc] init];
    paragraphStyle.alignment = textAlignment;
    paragraphStyle.lineSpacing = linesSpacing;
    paragraphStyle.paragraphSpacing = paragraphSpacing;
    paragraphStyle.lineBreakMode = lineBreakMode;
    //paragraphStyle.hyphenationFactor = 0.0f;
    //paragraphStyle.firstLineHeadIndent = 0.0f;
    //paragraphStyle.headIndent = 0.0f;

    [self bm_setParagraphStyle:paragraphStyle range:range];
}

@end


//#pragma mark -
//#pragma mark MQ
//
//@implementation NSMutableAttributedString (MQ)
//
//@end
