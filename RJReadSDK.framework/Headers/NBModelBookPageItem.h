//
//  NBModelBookPageItem.h
//  RJRead
//
//  Created by 相颖 on 15/9/21.
//  Copyright © 2015年 Elephant. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBModelBookPageItem : NSObject

// 是否支持点读
@property(nonatomic,assign) BOOL  clickread;
// 音频文件时长
@property(nonatomic,assign) float  duration;
// 音频文件名
@property(nonatomic,strong) NSString * mp3name;
// MP3文件链接
@property(nonatomic,strong) NSString * mp3url;

@property(nonatomic,strong) NSString * mp3url_hiq;
// 页码
@property(nonatomic,assign) NSInteger  page;
// 音频文件内容所占页码索引范围数组: 可能存在跨页音频；该数组中的值是页码索引，从0开始
@property(nonatomic,strong) NSMutableArray * pageindex;
// 标题
@property(nonatomic,strong) NSString * title;
// 单元
@property(nonatomic,strong) NSString * unit;

@end
