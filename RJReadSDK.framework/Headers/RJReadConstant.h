//
//  RJReadConstant.h
//  RJReadSDK
//
//  Created by 李沛倬 on 2017/4/18.
//  Copyright © 2017年 pep. All rights reserved.
//

#ifndef RJReadConstant_h
#define RJReadConstant_h


#pragma mark - ENUM

typedef enum {
    BOOK_STATE_UNDOWNLOAD,       //没有加入下载列表中
    BOOK_STATE_DOWNLOADING,      //下载中
    BOOK_STATE_PAUSE,            //暂停中
    BOOK_STATE_WAITING,          //等待中
    BOOK_STATE_FINISH,           //已下载
    BOOK_STATE_UNZIP,            //解压资源中
    BOOK_STATE_FAILED,           //下载失败
    BOOK_STATE_UPDATE,           //有更新
    BOOK_STATE_DELETE,           //已删除
    BOOK_STATE_DOWNLOAD_START  , //开始下载
    BOOK_STATE_CANCELALL,        //取消所有任务
    BOOK_STATE_DOWNLOAD_ALL,     //所有书本下载的任务类型
    
    BOOK_STATE_EXPERIENCEEND,       //体验结束
    BOOK_STATE_EVALUATION,          //跟读结束
}BOOK_STATE;

typedef enum {
    ORDER_STATE_UNORDERED,  //未订购
    ORDER_STATE_FREE,       //免费
    ORDER_STATE_EXPIRED,    //已过期
    ORDER_STATE_ORDERED,    //已订购
}ORDER_STATE;


typedef enum {
    FOLLOW_ENGINE_TYPE_OFFLINE_CS, //离线驰声
    FOLLOW_ENGINE_TYPE_ONLINE_XF,  //在线讯飞
    FOLLOW_ENGINE_TYPE_ONLINE_CS,  //在线驰声
    //    FOLLOW_ENGINE_TYPE_ONLINE_YZS, //云知声在线
}FOLLOW_ENGINE_TYPE;


typedef NS_ENUM(NSUInteger, RJBOOkAUTH) {
    RJBOOkAUTH_EXPERIENCE,                  // 未授权：体验模式
    RJBOOkAUTH_PASS,                        // 验证通过
    RJBOOkAUTH_EXPIRED,                     // 授权过期
};





/*********************************************************URLs****************************************************************/









#endif /* RJReadConstant_h */






















