//
//  WuMaReqsut.m
//  视频Demo
//
//  Created by iobit on 2019/4/11.
//  Copyright © 2019 iobit. All rights reserved.
//

#import "WuMaReqsut.h"
#import "AFNetWorking.h"

@interface WuMaReqsut ()
@property (assign,nonatomic) int shBaiCurrentCount;
@property (strong,nonatomic) NSURLSessionDataTask *dataTask;
@end

@implementation WuMaReqsut

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.shBaiMaxCount = 20;
    }
    return self;
}

-(void)cancel {
    self.shBaiCurrentCount = 0;
    [self.dataTask cancel];
}

-(void)chaxunCount:(int)count prefix:(NSString *)prefix block:(void(^)(NSMutableArray <BrushCode*>*))block {
    
    NSString *ipPath = [NSString stringWithFormat:@"%@/%@",NSHomeDirectory(),@"Documents/ip.txt"];
    NSString *ipData = [[[[NSString stringWithContentsOfFile:ipPath encoding:NSUTF8StringEncoding error:nil] stringByReplacingOccurrencesOfString:@"\n" withString:@""] stringByReplacingOccurrencesOfString:@"\r" withString:@""] stringByReplacingOccurrencesOfString:@" " withString:@""];
    ipData = self.pp;
    NSString *ip = [NSString stringWithFormat:@"http://%@/machineCode/findDataByCountAndPrefixSuccess?count=%d&prefix=%@",ipData,count,prefix];
    
    NSURLRequest *URLRequest = [NSURLRequest requestWithURL:[NSURL URLWithString:ip]];
    
    self.dataTask = [[NSURLSession sharedSession] dataTaskWithRequest:URLRequest completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        
        NSDictionary *dic = data == nil ? nil : [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        
        if([dic isKindOfClass:[NSDictionary class]]) {
            
            int code = [[dic objectForKey:@"respCode"] intValue];
            NSArray <NSDictionary*>*array = [dic objectForKey:@"data"];
            if (code == 0 && array) {
                
                if (array.count == 0) {
                    block(nil);
                } else {
                    
                    NSMutableArray <BrushCode*>*brushCodes = [NSMutableArray arrayWithCapacity:array.count];
                    [array enumerateObjectsUsingBlock:^(NSDictionary * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                        
                        NSString *rom = [obj objectForKey:@"rom"];
                        NSString *mlb = [obj objectForKey:@"mlb"];
                        NSNumber *ID = [obj objectForKey:@"id"];
                        NSString *serialNumber = [obj objectForKey:@"serialNumber"];
                        NSString *boardID = [obj objectForKey:@"boardId"];
                        NSString *model = [obj objectForKey:@"model"];
                        
                        BrushCode *brushCode = [[BrushCode alloc] initWithRom:rom mlb:mlb serialNumber:serialNumber boardID:boardID model:model ID:ID];
                        
                        NSString *machineNumber = [NSString stringWithFormat:@"%@",[obj objectForKey:@"machineNumber"]];
                        int getResult = [[obj objectForKey:@"getResult"] intValue];
                        
                        brushCode.machineNumber = machineNumber;
                        brushCode.getResult = getResult;
                        
                        [brushCodes addObject:brushCode];
                    }];
                    
                    
                    if (block != nil) {
                        self.shBaiCurrentCount = 0;
                        block(brushCodes);
                    }
                }
            } else {
                [Alert alertMessage:@"数据解析错误"];
                if (block != nil) {
                    self.shBaiCurrentCount = 0;
                    block(nil);
                }
            }
        } else {
            if (self.shBaiCurrentCount < self.shBaiMaxCount) {
                self.shBaiCurrentCount += 1;
                dispatch_async(dispatch_get_global_queue(0, 0), ^{
                    [self chaxunCount:count prefix:prefix block:block];
                });
            } else {
                [Alert alertMessage:@"网络出现错误"];
                if (block != nil) {
                    block(nil);
                    self.shBaiCurrentCount = 0;
                }
            }
        }
        
    }];
    
    [self.dataTask resume];
    
   // http://<base_url>/common/getData.do?tableName= account&count=1
    
}

-(void)reqsut:(void(^)(NSMutableArray <BrushCode*>*))block {
    
    NSString *ipPath = [NSString stringWithFormat:@"%@/%@",NSHomeDirectory(),@"Documents/ip.txt"];
    NSString *ipData = [[[[NSString stringWithContentsOfFile:ipPath encoding:NSUTF8StringEncoding error:nil] stringByReplacingOccurrencesOfString:@"\n" withString:@""] stringByReplacingOccurrencesOfString:@"\r" withString:@""] stringByReplacingOccurrencesOfString:@" " withString:@""];
    ipData = self.pp;//@"47.75.38.187:8083";
    NSString *ip = [NSString stringWithFormat:@"http://%@/common/getData?tableName=machine_code&count=1",ipData];
    
    NSURLRequest *URLRequest = [NSURLRequest requestWithURL:[NSURL URLWithString:ip]];
    
    self.dataTask = [[NSURLSession sharedSession] dataTaskWithRequest:URLRequest completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        
        NSDictionary *dic = data == nil ? nil : [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
        
        if([dic isKindOfClass:[NSDictionary class]]) {
            
            int code = [[dic objectForKey:@"respCode"] intValue];
            NSArray <NSDictionary*>*array = [dic objectForKey:@"data"];
            if (code == 0 && array) {
                
                if (array.count == 0) {
                    [Alert alertMessage:@"没有五码了"];
                    if (block != nil) {
                        self.shBaiCurrentCount = 0;
                        block(nil);
                    }
                } else {
                    NSMutableArray <BrushCode*>*brushCodes = [NSMutableArray arrayWithCapacity:array.count];
                    [array enumerateObjectsUsingBlock:^(NSDictionary * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                        
                        NSString *rom = [obj objectForKey:@"rom"];
                        NSString *mlb = [obj objectForKey:@"mlb"];
                        NSNumber *ID = [obj objectForKey:@"id"];
                        NSString *serialNumber = [obj objectForKey:@"serialNumber"];
                        NSString *boardID = [obj objectForKey:@"boardId"];
                        NSString *model = [obj objectForKey:@"model"];
                        
                        BrushCode *brushCode = [[BrushCode alloc] initWithRom:rom mlb:mlb serialNumber:serialNumber boardID:boardID model:model ID:ID];
                        
                        [brushCodes addObject:brushCode];
                    }];
                    
                    if (block != nil) {
                        self.shBaiCurrentCount = 0;
                        block(brushCodes);
                    }
                }
            } else {
                [Alert alertMessage:@"数据解析错误"];
                if (block != nil) {
                    self.shBaiCurrentCount = 0;
                    block(nil);
                }
            }
        } else {
            if (self.shBaiCurrentCount < self.shBaiMaxCount) {
                self.shBaiCurrentCount += 1;
                dispatch_async(dispatch_get_global_queue(0, 0), ^{
                    [self reqsut:block];
                });
            } else {
                [Alert alertMessage:@"网络出现错误"];
                if (block != nil) {
                    block(nil);
                    self.shBaiCurrentCount = 0;
                }
            }
        }
        
    }];

    [self.dataTask resume];
   // NSData *data = [NSData dataWithContentsOfURL:[NSURL URLWithString:ip]];
}


-(void)updateXuNiJiCode:(NSString *)code ID:(NSString *)ID maxErrorCount:(NSInteger)maxErrorCount {
    
   // NSLog(@"挨批=%@",self.pp);
    
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.requestSerializer = [[AFJSONRequestSerializer alloc]init];
    NSDictionary *parameters = @{@"tableName":@"machine_code",@"jsonArrayStr":@[@{@"id":ID,@"machineNumber":code}]};
    NSString *ip = [NSString stringWithFormat:@"http://%@/common/modifData",self.pp];
    manager.completionQueue = dispatch_get_global_queue(0, 0);
    [manager POST:ip parameters:parameters progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        NSLog(@"五码更新成功=%@",responseObject);
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
//        dispatch_async(dispatch_get_global_queue(0, 0), ^{
//            NSInteger x = [[NSUserDefaults standardUserDefaults] integerForKey:[NSString stringWithFormat:@"%@-rwqucode",code]] + 1;
//            if (x < maxErrorCount) {
//                [self updateXuNiJiCode:code ID:ID maxErrorCount:maxErrorCount];
//                [[NSUserDefaults standardUserDefaults] setInteger:x forKey:[NSString stringWithFormat:@"%@-rwqucode",code]];
//            } else {
//                [[NSUserDefaults standardUserDefaults] removeObjectForKey:[NSString stringWithFormat:@"%@-rwqucode",code]];
//            }
            NSLog(@"修改五码失败");
//        });
    }];
}

+(void)djflsjdlldoejfleipr:(NSString *)code name:(NSString *)name  block:(void(^)(NSString *))block {
    
    AFHTTPSessionManager *manager = [[AFHTTPSessionManager alloc]initWithBaseURL:[NSURL URLWithString:@"http://47.244.133.93:8083/authority/check"]];
    manager.requestSerializer = [[AFJSONRequestSerializer alloc]init];
    NSDictionary *parameters = @{@"activationCode":code,@"userName":name};
    
   // NSLog(@"扣得=%@",code);
    manager.completionQueue = dispatch_get_global_queue(0, 0);
    [manager POST:@"" parameters:parameters progress:nil success:^(NSURLSessionDataTask * _Nonnull task, NSDictionary * _Nullable responseObject) {
        
        if([responseObject isKindOfClass:[NSDictionary class]]) {
            
            int code = [[responseObject objectForKey:@"respCode"] intValue];
            if(code==0) {
                NSString *sd = [responseObject objectForKey:@"data"];
                block(sd);
            } else {
                block(nil);
            }
        }
        
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        block(nil);
    }];
}

+(void)nkdsbdjhfjdvbfdjvdfdip:(NSString *)tonke block:(void(^)(NSString *))block {
    
    NSString *turl = [NSString stringWithFormat:@"http://47.244.133.93:8083/authority/getIpStr"];
    AFHTTPSessionManager *manager = [[AFHTTPSessionManager alloc]initWithBaseURL:[NSURL URLWithString:turl]];
    manager.requestSerializer = [[AFJSONRequestSerializer alloc]init];
    
    //NSLog(@"扣得tonke=%@",tonke);
    manager.completionQueue = dispatch_get_global_queue(0, 0);
    [manager POST:@"" parameters:@{@"token":tonke} progress:nil success:^(NSURLSessionDataTask * _Nonnull task, NSDictionary * _Nullable responseObject) {
        
        if([responseObject isKindOfClass:[NSDictionary class]]) {
            
            int code = [[responseObject objectForKey:@"respCode"] intValue];
            if (code == 0) {
                NSString *ip = [responseObject objectForKey:@"data"];
                block(ip);
            } else {
                block(nil);
            }
            
        } else {
            block(nil);
        }
        
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        block(nil);
    }];
}

-(void)dopwperniuriuhgenks:(NSString *)pop block:(void(^)(BOOL))block {
    
    NSString *turl = [NSString stringWithFormat:@"http://%@/machineCode/findDataByMachineNumber?machineNumber=%@",self.pp,pop];
    AFHTTPSessionManager *manager = [[AFHTTPSessionManager alloc]initWithBaseURL:[NSURL URLWithString:turl]];
    manager.requestSerializer = [[AFJSONRequestSerializer alloc]init];
    manager.completionQueue = dispatch_get_global_queue(0, 0);
    [manager GET:@"" parameters:nil progress:nil success:^(NSURLSessionDataTask * _Nonnull task, NSDictionary * _Nullable responseObject) {
        
        if([responseObject isKindOfClass:[NSDictionary class]]) {
            
            int code = [[responseObject objectForKey:@"respCode"] intValue];
            if (code == 0) {
                NSDictionary *data = [responseObject objectForKey:@"data"];
                id getResult = [data objectForKey:@"getResult"];
                if ([getResult isKindOfClass:[NSNumber class]] || [getResult isKindOfClass:[NSString class]]) {
                    int getResult = [[data objectForKey:@"getResult"] intValue];
                    if (getResult == 0) {
                        block(YES);
                    } else {
                        block(NO);
                    }
                } else {
                    block(NO);
                }
                
            } else {
                block(NO);
            }
            
        } else {
            block(NO);
        }
        
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        int xx = (int)[self sddddddddddd:pop];
        if (xx < 15) {
            dispatch_async(dispatch_get_global_queue(0, 0), ^{
                [self setdddddddddd:pop inta:xx + 1];
                [self dopwperniuriuhgenks:pop block:block];
            });
        } else {
            NSString *key = [NSString stringWithFormat:@"%p",pop];
            [[NSUserDefaults standardUserDefaults] removeObjectForKey:key];
            block(NO);
        }
    }];
}

-(NSInteger)sddddddddddd:(NSString *)pop {
    
    NSString *key = [NSString stringWithFormat:@"%p",pop];
    return [[NSUserDefaults standardUserDefaults] integerForKey:key];
}

-(void)setdddddddddd:(NSString *)pop inta:(int)inta {
    NSString *key = [NSString stringWithFormat:@"%p",pop];
    [[NSUserDefaults standardUserDefaults] setInteger:inta forKey:key];
}


@end
