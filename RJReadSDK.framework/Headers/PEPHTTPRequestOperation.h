//
//  PEPHTTPRequestOperation.h
//  nbUtil
//
//  Created by 相颖 on 16/7/9.
//  Copyright © 2016年 相颖. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PEPHTTPRequestOperation : NSObject

@property(nonatomic,weak)NSURLSessionTask *sessionTask;
@property (nonatomic,weak)NSURLRequest *request;
@property (nonatomic,weak)NSHTTPURLResponse *response;
@property (assign, nonatomic, getter = isCancelled) BOOL cancelled;
@property (assign, nonatomic, getter = isExecuting) BOOL executing;
@property (nonatomic,assign)BOOL canResume;
@property (nonatomic,strong)NSError *error;
//设置失败后重试的次数，默认3次
@property(nonatomic,assign)NSInteger failedTime;

//requesturl不要取sessionTASK的requset的url，有可能运营商劫持，有些是302，url地址会变，另外cancel后再继续，原先的断点续传已之前的url为key，而原先的url地址是不请求数据的，导致resumedata失败（正确的resume数据是302跳转后的数据，这样会导致断点续传问题，并且第二次的url肯定不与前面的url相同，匹配url不成功会导致请求一直发生），这仅仅针对下载，普通的请求不存在断点续传问题，因此没有问题
@property(nonatomic,strong)NSURL *requestUrl;

- (instancetype)initWithTask:(NSURLSessionTask*)task;

- (void)cancel;

- (void)start;

+ (void)removeSessionDataByUrl:(NSURL*)url;

@end
