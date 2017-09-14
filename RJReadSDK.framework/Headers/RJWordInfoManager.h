//
//  RJWordInfoManager.h
//  RJReadSDK
//
//  Created by 李沛倬 on 2017/7/31.
//  Copyright © 2017年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RJWordInfoModel;

@interface RJWordInfoManager : NSObject

@property (nonatomic, strong) NSMutableArray<RJWordInfoModel *> *wordInfoList;

@property (nonatomic, copy) NSString *bookID;
/// 阅读页码进度
@property (nonatomic, assign) NSInteger pageNumber;
/// 单元名
@property (nonatomic, copy) NSString *unit;
/// 标题名
@property (nonatomic, copy) NSString *title;

+ (instancetype)shareManager;

- (void)resetStatistics;

- (void)setWordInfoWithWordID:(NSString *)wordID duration:(NSTimeInterval)duration;
@end



@interface RJWordInfoModel : NSObject
/// 教材ID
@property (nonatomic, copy) NSString *bookID;
/// 句子ID：在所属教材中的index
@property (nonatomic, copy) NSString *wordID;
///// 点击次数
//@property (nonatomic, assign) NSUInteger count;
///// 播放总时长：每次播放时长累加和
//@property (nonatomic, assign) NSTimeInterval duration;
/// 每次播放时长列表
@property (nonatomic, strong) NSMutableArray<NSNumber *> *durations;

- (instancetype)initWithWordID:(NSString *)wordID count:(NSUInteger)count duration:(NSTimeInterval)duration;

+ (instancetype)wordWithID:(NSString *)wordID count:(NSUInteger)count duration:(NSTimeInterval)duration;


@end
