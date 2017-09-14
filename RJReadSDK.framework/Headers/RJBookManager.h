//
//  RJBookManager.h
//  RJReadSDK
//
//  Created by 李沛倬 on 2017/4/14.
//  Copyright © 2017年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RJBookGradeModel.h"
#import "NBModelBookPageItem.h"
#import "NBModelDownload.h"
#import "PEPHTTPRequestOperation.h"

typedef void(^RequestFinished)(PEPHTTPRequestOperation *operation, NSArray<RJBookGradeModel *> *bookList);

typedef void(^RequestBookListFinished)(PEPHTTPRequestOperation *operation, NSArray<RJBookGrade *> *bookList);


@interface RJBookManager : NSObject

#pragma mark - SDK Config

/**
 SDK认证

 @param appKey 对接时分配的appKey，用于区别不同平台
 */
+ (void)setAppKey:(NSString *)appKey;

/**
 第三方平台用户登录成功之后请调用该接口，在人教点读用户平台创建用户副本

 @param userID 第三方用户ID
 */
+ (void)loginAndSyncUserWithUserId:(NSString *)userID finished:(void(^)(PEPHTTPRequestOperation *operation, id data))finishedBolck;

/**
 第三方平台用户退出之后请调用该接口
 */
+ (void)logout;

/**
 是否是登录状态

 @return 如果返回false，对接平台可调用login和getAuthenticatedBookList方法，以便SDK鉴权功能可正常使用。
 */
+ (BOOL)isLogin;

/**
 获取当前用户绑定设备列表：每个用户最多绑定6台设备。该接口需要的userID等参数已在内部处理，第三方平台请确保用户已经登录并调用过loginAndSyncUserWithUserId方法之后再调用该方法，否则将无法得到正确内容
 返回值示例：
 {
 "devlist":[
 {
 "dev_id":"0102",                           // 设备ID: iOS平台为UDID
 "create_time":"2017-08-09 18:01:38",       // 绑定该设备的时间
 "dev_name":"xiaomi2"                       // 设备名称
 },
 {
 "dev_id":"0106",
 "create_time":"2017-08-09 18:24:36",
 "dev_name":"xiaomi6"
 }
 ],
 "crrudevid":"0106",                        // 当前设备ID
 "errcode":0,                               // 状态码：0为成功
 "errmsg":"success"
 }
 
 @param finishedBolck 网络请求结束后回调的block
 */
+ (void)getDeviceListFromCurrentUserDidLogin:(void(^)(PEPHTTPRequestOperation *operation, id data))finishedBolck;


/**
 解绑设备

 @param deviceIDList 需要解绑的设备ID数组
 @param finishedBolck 网络请求结束后回调的block
 解绑成功返回值示例：
 {"errcode":0," errmsg":"success"}

 */
+ (void)removeDevicesWithDeviceIDList:(NSArray<NSString *> *)deviceIDList finished:(void(^)(PEPHTTPRequestOperation *operation, id data))finishedBolck;


#pragma mark - Reader
/**
 获取教材列表，方法内部已将json数据解析并转化为model

 @param finishBlock 网络请求结束后回调的block
 */
+ (void)getBookList:(RequestFinished)finishBlock;


/**
 *（新接口）获取教材列表，方法内部已将json数据解析并转化为model

 @param finishBlock 网络请求结束后回调的block
 */
+ (void)getBookListGroupByGrade:(RequestBookListFinished)finishBlock;


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
+ (void)getBookCatalogWith:(RJBookItemModel *)bookitem finished:(void(^)(NSArray<NBModelBookPageItem *> *catalog))finishBlock;

/**
 获取当前用户订购的教材，方法内部已将json数据解析并转化为model。
 该方法需要调用loginAndSyncUserWithUserId方法并登录成功之后调用才会返回正确数据

 @param finishBlock 网络请求结束后回调的block
 */
+ (void)getMyOrderBooks:(RequestFinished)finishBlock;

/**
 获取当前用户已购买并授权的教材列表
 第三方平台可在【购买教材成功之后】、【退款成功之后】和【获取当前用户购买教材之后】等调用该接口，以便SDK完成教材鉴权

 @param result result description
 */
+ (void)getAuthenticatedBookList:(void(^)(id description))result;

/**
 根据传入的bookID获取该教材的购买状态

 @param bookID bookID
 */
+ (RJBOOkAUTH)checkAuthStateWithBookID:(NSString *)bookID;

/**
 打开点读页面: 该方法没有跳转页码参数，如果教材认证通过（已购买），阅读器会自动记录阅读进度

 @param bookitem bookitem
 @param experience 是否是体验模式：默认为YES
 @return 教材认证状态
 */
+ (RJBOOkAUTH)openBook:(RJBookItemModel *)bookitem isExperience:(BOOL)experience;

/**
 打开点读页面
 
 @param bookitem bookitem
 @param experience 是否是体验模式：默认为YES
 @param page 跳转页码。从0开始的页码，并非教材页码
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

 @param closedBlock 对应的bookid和页面打开时间(playtime)、持续时间(duration)、句子的点击次数及播放时长等统计信息([info[@"wordInfoCount"], 数据类型为：NSArray<RJWordInfoModel *>)
 */
+ (void)bookClosed:(void(^)(NSDictionary *info))closedBlock;


/**
 *  更新书本体验模式。如需在阅读器打开的过程中更改体验模式，则可调用此方法修改。
 *
 *  @param bookid     bookid description
 *  @param experience 是否是体验模式
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

@end
























