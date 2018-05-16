//
//  RJBookManager.h
//  RJReadSDK
//
//  Created by 李沛倬 on 2017/4/14.
//  Copyright © 2017年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RJBookGradeModel.h"
#import "NBModelClickRead.h"
#import "NBModelDownload.h"
#import "PEPHTTPRequestOperation.h"
#import "RJWordInfoManager.h"

@interface RJBookManager : NSObject

#pragma mark - SDK Config

/**
 SDK认证
 
 @param appKey 对接时分配的appKey，用于区别不同平台
 */
+ (void)setAppKey:(NSString *)appKey;



/**
 设置评测引擎类型：默认在线讯飞

 @param type 详见 FOLLOW_ENGINE_TYPE 枚举
 */
+ (void)setEvaluateEngineType:(FOLLOW_ENGINE_TYPE)type;


/**
 设置讯飞SDK的AppID。如果不设置或者传空，SDK内部将会设置默认的AppID
 注意：目前版本的讯飞SDK不支持一个App中使用两个不同的AppID，而且AppID跟讯飞SDK的静态库文件绑定，不同的AppID无法正常初始化讯飞SDK。
 如果对接平台的App中已经使用了讯飞SDK，请务必在此处传入讯飞给你们分配的AppID，并且将Pods中的iflyMSC.framework替换为你们从讯飞开放平台下载的iflyMSC.framework，以保证不会跟人教点读SDK中依赖的讯飞SDK产生冲突
 
 @param appID AppID
 */
+ (void)setiFlyMSCAppID:(NSString *)appID;


/**
 第三方用户鉴权、绑定设备.
 对接平台可在APP启动或用户订单状态发生变化时调用该方法
 
 @param userID 第三方用户ID
 @param finishedBolck 网络请求结束后回调的block（包括当前用户购买过的书本和绑定的设备列表）
 */
+ (void)userAuthWithUserID:(NSString *)userID finished:(void(^)(PEPHTTPRequestOperation *operation, id data))finishedBolck;


/**
 解绑设备。
 一个用户只能在最多6台设备上登录，如果超过这个上限，可在其他已绑定的设备上调用该方法解绑指定的设备
 
 @param userID 用户ID
 @param deviceIDs 设备ID数组
 @param finishedBolck 网络请求结束后回调的block（errno == 110 为解绑成功）
 */
+ (void)unbindDeviceWithUserID:(NSString *)userID
                     deviceIDs:(NSArray<NSString *> *)deviceIDs
                      finished:(void(^)(PEPHTTPRequestOperation *operation, id data))finishedBolck;


#pragma mark - Reader

/**
 请求书本列表
 
 @param finishedBolck 网络请求结束后回调的block
 */
+ (void)getBookList:(void(^)(PEPHTTPRequestOperation *operation, NSArray<RJBookGrade *> *bookList))finishedBolck;


/**
 通过bookID获取book对象
 
 @param bookID 教材ID
 @param finishedBlock 网络请求结束后回调的block
 */
+ (void)getBookItemWithBookID:(NSString *)bookID finished:(void(^)(RJBookItemModel *bookItem))finishedBlock;


/**
 获取指定教材目录结构
 
 @param bookitem 教材模型实例
 @param finishBlock 网络请求结束后回调的block
 */
+ (void)getBookCatalogWith:(RJBookItemModel *)bookitem finished:(void(^)(NBModelClickRead *catalog))finishBlock;


/**
 根据传入的bookID获取该教材的购买状态
 
 @param bookID bookID
 */
+ (RJBOOkAUTH)checkAuthStateWithBookID:(NSString *)bookID;


/**
 打开点读页面: 如果教材认证通过（已购买），阅读器会自动记录阅读进度
 
 @param bookitem bookitem
 @param experience 是否是体验模式：默认为YES
 @return 教材认证状态
 */
+ (RJBOOkAUTH)openBook:(RJBookItemModel *)bookitem isExperience:(BOOL)experience;


/**
 打开点读页面: 如果教材认证通过（已购买），阅读器会自动记录阅读进度
 
 @param bookitem bookitem
 @param experience 是否是体验模式：默认为YES
 @param page 跳转页码。从0开始的下标，并非教材页码
 @return 教材认证状态
 */
+ (RJBOOkAUTH)openBook:(RJBookItemModel *)bookitem isExperience:(BOOL)experience pageNumber:(NSUInteger)page;


/**
 关闭阅读器：可在用户点击【立即购买】按钮的回调里调用该方法，先关闭阅读器，然后进入购买页面
 */
+ (void)closeReader;


/**
 *  书本状态回调，状态详见BOOK_STATE枚举
 *
 *  @param statesBlock parmers 状态NBModelDownload，评测上报数据NSDictionary
 *  体验结束上报数据NSDictionary
 */
+ (void)bookState:(void(^)(NSString *bookid, BOOK_STATE state, id parmers))statesBlock;


/**
 设置书本状态
 
 @param bookid 书本ID
 @param state 状态类型
 @param params 参数
 */
+ (void)setBookStateWithBookID:(NSString *)bookid state:(BOOK_STATE)state params:(id)params;


/**
 点读页面关闭回调
 
 @param closedBlock wordInfoManager中包含本次阅读的bookID、书本打开时间、关闭时间、阅读进度、点读记录、评测记录等信息，具体详见RJWordInfoManager类。
 wordInfoManager中只包含本次打开的书本的信息，其中的统计数据会在下次打开书时清除，调用者请自行保存
 */
+ (void)bookClosed:(void(^)(RJWordInfoManager *wordInfoManager))closedBlock;


/**
 *  更新书本状态。如需在阅读器打开的过程中更改书本状态（如已购买），则可调用此方法修改。
 *
 *  @param bookid     bookid description
 *  @param experience 是否是体验模式，YES为体验模式
 */
+ (void)updateBookState:(NSString*)bookid experience:(BOOL)experience;


#pragma mark - Download

/**
 获取所有已下载教材列表
 
 @return return value description
 */
+ (NSArray<NSString *> *)getlocalBooklist;


/**
 下载教材
 
 @param itemModel itemModel description
 */
+ (void)downloadItem:(RJBookItemModel *)itemModel;


/**
 通过bookid从下载队列中获取下载实例
 
 @param bookid bookid description
 @return 该bookID对应教材的下载实例
 */
+ (NBModelDownload *)getDownloadModelWithBookID:(NSString *)bookid;


/**
 暂停或继续下载
 
 @param task 下载请求实例
 */
+ (void)pauseOrContinueDownloadWithTask:(NBModelDownload *)task;


/**
 *  根据bookid获取当前下载任务书的状态
 *
 *  @param bookid 书本id
 *
 *  @return 书本状态
 */
+ (BOOK_STATE)getTaskState:(NSString *)bookid;


/**
 *  移除某个下载任务
 *
 *  @param itemModel itemModel description
 */
+ (void)removeTask:(RJBookItemModel *)itemModel;


/**
 *  取消所有下载任务
 */
+ (void)cancelAllTask;


/**
 *  删除某本书
 *
 *  @param itemModel itemModel description
 *
 */
+ (void)deleteBook:(RJBookItemModel *)itemModel;


/**
 删除所有下载教材（包括下载中的）
 */
+ (void)deleteAllLocalBooks;


/**
 *  是否有下载在执行
 *  用于判断是否需要进行后台下载
 *
 *  @return yes 有 no没有
 */
+ (BOOL)isOperationTaskRunning;




#pragma mark - Caches Manager

/**
 *  计算可清除的缓存大小
 *
 *  @return size(byte)
 */
+ (NSInteger)cachesize;


/**
 *  计算所有已下载书本的大小
 *
 *  @return size(byte)
 */
+ (NSInteger)docsize;


/**
 清除缓存：清除在线阅读产生的缓存文件
 
 @return 是否清除成功
 */
+ (BOOL)clearCache;


/**
 清除某本书的缓存
 
 @param bookID 书本ID
 @return 是否清除成功
 */
+ (BOOL)clearOnlineBookCacheWithBookID:(NSString *)bookID;



@end






















