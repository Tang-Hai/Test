//
//  BrushCode.m
//  刷码神器
//
//  Created by iobit on 2018/9/30.
//  Copyright © 2018年 iobit. All rights reserved.
//

//#import "eyn.h"
#import "BrushCode.h"

@implementation BrushCode

-(instancetype)initWithRom:(NSString *)rom
                       mlb:(NSString *)mlb
              serialNumber:(NSString *)serialNumber
                   boardID:(NSString *)boardID
                     model:(NSString *)model
                        ID:(NSNumber *)ID {
    self = [super init];
    self.rom = rom;//[self sssssdsdsd:rom];
    self.mlb = mlb;//[self sssssdsdsd:mlb];
    self.serialNumber = serialNumber;//[self sssssdsdsd:serialNumber];
    self.boardID = boardID;//[self sssssdsdsd:boardID];
    self.model = model;//[self sssssdsdsd:model];
    self.ID = ID;
    return self;
}

-(NSString *)vmxRom {
    if([self.rom containsString:@"%"]) {
        return self.rom;
    } else {
        int offfset = 0;
        NSString *result = @"";
        while (offfset < self.rom.length - 1) {
            NSString *string = [self.rom substringWithRange:NSMakeRange(offfset, 2)];
            result = [result stringByAppendingString:@"%"];
            result = [NSString stringWithFormat:@"%@%@",result,string];
            offfset += 2;
        }
        return result;
    }
}

//-(NSString *)sssssdsdsd:(NSString *)item {
//    NSArray *keys = @[@"ss",@"s2",@"(*∆",@"˚˚˙˙",@"dsd=≠"];
//    NSData *ddd = [[NSData alloc] initWithBase64EncodedString:item options:NSDataBase64DecodingIgnoreUnknownCharacters];
//    NSData * ccc = [[[NSString alloc] initWithData:ddd encoding:NSUTF8StringEncoding] dataUsingEncoding:NSISOLatin1StringEncoding];
//    NSString *jieguo = [eyn eynDecryptWithKey:[keys componentsJoinedByString:@""] andData:ccc];
//    return jieguo;
//}

@end
