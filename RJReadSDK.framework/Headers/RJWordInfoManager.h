//
//  RJWordInfoManager.h
//  RJReadSDK
//
//  Created by 李沛倬 on 2017/7/31.
//  Copyright © 2017年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBFollowTrackResult.h"

@class RJWordInfoModel;


#pragma mark - RJWordInfoManager

@interface RJWordInfoManager : NSObject

/** 句子点读信息统计列表 */
@property (nonatomic, strong) NSMutableArray<RJWordInfoModel *> *wordInfoList;

/** 教材ID */
@property (nonatomic, copy) NSString *bookID;

/** 阅读页码进度 */
@property (nonatomic, assign) NSInteger pageNumber;

/** 单元名 */
@property (nonatomic, copy) NSString *unit;

/** 标题名 */
@property (nonatomic, copy) NSString *title;

/** 书本打开时间 */
@property (nonatomic, strong) NSDate *bookOpenDate;

/** 书本关闭时间 */
@property (nonatomic, strong) NSDate *bookCloseDate;


/** 构造单例 */
+ (instancetype)shareManager;

/** 重置统计信息 */
- (void)resetStatistics;


/**
 增加一条句子的点读信息
 
 @param wordID 句子ID
 @param wordContent 句子内容
 @param duration 点读时间
 */
- (void)setWordInfoWithWordID:(NSString *)wordID
                  wordContent:(NSString *)wordContent
                     duration:(NSTimeInterval)duration;


/**
 增加一条句子的评测结果记录
 
 @param wordID 句子ID
 @param result 评测结果对象
 */
- (void)setWordEvaluateWithWordID:(NSString *)wordID evaluateResult:(NBFollowTrackResult *)result;


@end





#pragma mark - RJWordInfoModel


/**
 获取此类中的属性不会得到nil
 */
@interface RJWordInfoModel : NSObject

/** 教材ID */
@property (nonatomic, copy) NSString *bookID;

/** 句子ID：在所属教材中的index */
@property (nonatomic, copy) NSString *wordID;

/** 句子内容 */
@property (nonatomic, copy) NSString *wordContent;

/** 单元名 */
@property (nonatomic, copy) NSString *unit;

/** 每次播放时长列表 */
@property (nonatomic, strong) NSMutableArray<NSNumber *> *durations;

/** 每次测评得分数组 */
@property (nonatomic, strong) NSMutableArray<NBFollowTrackResult *> *scores;


- (instancetype)initWithWordID:(NSString *)wordID
                   wordContent:(NSString *)wordContent
                         count:(NSUInteger)count
                      duration:(NSTimeInterval)duration
                          unit:(NSString *)unit;


+ (instancetype)wordWithID:(NSString *)wordID
               wordContent:(NSString *)wordContent
                     count:(NSUInteger)count
                  duration:(NSTimeInterval)duration
                      unit:(NSString *)unit;


@end













