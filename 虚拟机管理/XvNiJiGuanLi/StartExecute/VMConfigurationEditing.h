//
//  VMConfigurationEditing.h
//  篮球辅助
//
//  Created by iobit on 2019/4/11.
//  Copyright © 2019 iobit. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class BrushCode;
@interface VMConfigurationEditing : NSObject
+(BOOL)configurationEditing:(BrushCode *)brushCode macAss:(NSString *)macAss VMConfigurationPath:(NSString *)path;
@end

NS_ASSUME_NONNULL_END
