//
//  VMConfigurationEditing.m
//  篮球辅助
//
//  Created by iobit on 2019/4/11.
//  Copyright © 2019 iobit. All rights reserved.
//

#import "VMConfigurationEditing.h"
#import "BrushCode.h"
#import "Alert.h"

@implementation VMConfigurationEditing

+(BOOL)configurationEditing:(BrushCode *)brushCode macAss:(NSString *)macAss VMConfigurationPath:(NSString *)path {
    
    NSString *vmSetting = [NSString stringWithContentsOfFile:path encoding:NSUTF8StringEncoding error:nil];
    NSArray *array1;
    if ([vmSetting containsString:@"\r"] && [vmSetting containsString:@"\n"]) {
        vmSetting = [vmSetting stringByReplacingOccurrencesOfString:@"\n" withString:@""];
        array1 = [vmSetting componentsSeparatedByString:@"\r"];
    } else if ([vmSetting containsString:@"\r"]) {
        array1 = [vmSetting componentsSeparatedByString:@"\r"];
    } else {
        array1 = [vmSetting componentsSeparatedByString:@"\n"];
    }
    
    if (array1.count < 10) {
        [Alert alertMessage:@"vm配置解析错误"];
        return NO;
    }
    
    NSMutableArray <NSString *>*resutls = [NSMutableArray arrayWithCapacity:array1.count];
    
    [array1 enumerateObjectsUsingBlock:^(NSString * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        if([obj hasPrefix:@"hw.model"] || [obj hasPrefix:@"serialNumber"] || [obj hasPrefix:@"efi.nvram.var.ROM"] || [obj hasPrefix:@"efi.nvram.var.MLB"] || [obj hasPrefix:@"board-id"] || [obj hasPrefix:@"system-id.enable"] || [obj hasPrefix:@"smbios.reflectHost"] || [obj hasPrefix:@"vc.uuid"] || [obj hasPrefix:@"ethernet0.generatedAddress"] || [obj hasPrefix:@"ethernet0.address"] || [obj hasPrefix:@"ethernet0.addressType"]) {
            NSLog(@"%@",obj);
        } else {
            if (obj.length > 5) {
               [resutls addObject:obj];
            }
        }
    }];
    
    [resutls addObject:@"hw.model.reflectHost = \"FALSE\""];
    [resutls addObject:[NSString stringWithFormat:@"hw.model = \"%@\"",brushCode.model]];
    
    [resutls addObject:@"serialNumber.reflectHost = \"FALSE\""];
    [resutls addObject:[NSString stringWithFormat:@"serialNumber = \"%@\"",brushCode.serialNumber]];
    
    [resutls addObject:@"efi.nvram.var.ROM.reflectHost = \"FALSE\""];
    [resutls addObject:[NSString stringWithFormat:@"efi.nvram.var.ROM = \"%@\"",brushCode.vmxRom]];
    
    
    [resutls addObject:@"efi.nvram.var.MLB.reflectHost = \"FALSE\""];
    [resutls addObject:[NSString stringWithFormat:@"efi.nvram.var.MLB = \"%@\"",brushCode.mlb]];
    
    [resutls addObject:@"board-id.reflectHost = \"FALSE\""];
    [resutls addObject:[NSString stringWithFormat:@"board-id = \"%@\"",brushCode.boardID]];
    
    [resutls addObject:@"smbios.reflectHost = \"FALSE\""];
    [resutls addObject:@"system-id.enable = \"TRUE\""];
    
    NSString *add = macAss;
    int offfset = 0;
    NSString *result = @"";
    while (offfset < add.length - 1) {
        NSString *string = [add substringWithRange:NSMakeRange(offfset, 2)];
        result = [result stringByAppendingString:@":"];
        result = [NSString stringWithFormat:@"%@%@",result,string];
        offfset += 2;
    }
    
    NSString *idd = [NSString stringWithFormat:@"00:01:31%@",result];
    [resutls addObject:[NSString stringWithFormat:@"ethernet0.address = \"%@\"",idd]];
    [resutls addObject:@"ethernet0.addressType = \"static\""];
    
    [resutls addObject:@"vc.uuid = \"\""];
    
    NSString *resutlsString = [resutls componentsJoinedByString:@"\r"];
    
    [resutlsString writeToFile:path atomically:YES encoding:NSUTF8StringEncoding error:nil];
    
    return YES;
}

@end
