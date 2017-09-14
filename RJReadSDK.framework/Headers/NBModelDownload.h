//
//  NBModelDownload.h
//  RJRead
//
//  Created by 相颖 on 15/9/25.
//  Copyright © 2015年 Elephant. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RJBookGradeModel.h"
#import "RJReadConstant.h"

@class NBModelDownload;

@protocol NBModelDownloadDelegate <NSObject>
// 下载进度代理
- (void)stateChanged:(NBModelDownload*)download;

@end

@interface NBModelDownload : NSObject<NSCoding>

@property(nonatomic,strong)RJBookItemModel *item;
@property(nonatomic,assign)BOOK_STATE state;
// 已经下载的数据字节数
@property(nonatomic,assign)float currentProgress;
// 此资源的总字节数
@property(nonatomic,assign)float totalProgress;

@property(nonatomic,assign)unsigned long long lastSize;
@property(nonatomic,assign)unsigned long long totalSize;
@property(nonatomic,strong)NSDate *lastDate;
// 下载速度: 300k/s
@property(nonatomic,strong)NSString *speed;

@property(nonatomic,weak)id <NBModelDownloadDelegate>delegate;

@property(nonatomic,assign)ORDER_STATE orderState;

@end
