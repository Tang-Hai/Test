//
//  THDAsyncSocket.m
//  XvNiJiGuanLi
//
//  Created by apple on 2019/4/13.
//  Copyright © 2019年 Aiwei. All rights reserved.
//

#import "THDAsyncSocket.h"
#import "GCDAsyncSocket.h"
#import "GCDAsyncUdpSocket.h"
@interface THDAsyncSocket()<GCDAsyncUdpSocketDelegate>

// 服务端socket(开放端口,监听客户端socket的连接)
@property (strong, nonatomic) GCDAsyncSocket *serverSocket;
@property (strong,nonatomic) dispatch_queue_t queue_;
@end

@implementation THDAsyncSocket

- (instancetype)init
{
    self = [super init];
    if (self) {
        
        self.queue_ = dispatch_queue_create("GCDAsyncUdpSocketDelegate", nil);
        // 初始化服务端socket
        GCDAsyncUdpSocket *udpSocket = [[GCDAsyncUdpSocket alloc] initWithDelegate:self delegateQueue:self.queue_];
        NSError *error;
        [udpSocket bindToPort:1024 error:&error];
        
    }
    return self;
}

- (void)udpSocket:(GCDAsyncUdpSocket *)sock didReceiveData:(NSData *)data
      fromAddress:(NSData *)address
withFilterContext:(nullable id)filterContext {
    
    NSString *sd = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    NSLog(@"[Plugin]Socket=%@",sd);
}

@end
