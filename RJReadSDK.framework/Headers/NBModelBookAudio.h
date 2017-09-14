//
//  NBModelBookAudio.h
//  RJRead
//
//  Created by 相颖 on 15/9/21.
//  Copyright © 2015年 Elephant. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBModelBookPageItem.h"

@interface NBModelBookAudio : NSObject
// 教材ID
@property(nonatomic,strong) NSString * bookid;
// 页面信息数组
@property(nonatomic,strong) NSMutableArray<NBModelBookPageItem *> * bookitem;
// 教材名称：书架显示的书名
@property(nonatomic,strong) NSString * bookname;
// 年级学科名：《三年级英语（上）》
@property(nonatomic,strong) NSString * itemname;
// 出版时间
@property(nonatomic,strong) NSString * memo;
// 出版版本
@property(nonatomic,strong) NSString * subtitle;

@property(nonatomic,strong) NSString * thumb_url;

- (NSMutableArray*)transSections:(BOOL)ignorePageIndex;

@property(nonatomic,strong) NSString * booktype;//判断是否是fake书

@end
