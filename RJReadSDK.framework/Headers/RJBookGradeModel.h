//
//  RJBookListModel.h
//  RJReadSDK
//
//  Created by 李沛倬 on 2017/4/14.
//  Copyright © 2017年 pep. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RJBookItemModel;

/*********************************************RJBookGradeModel***************************************************/

@interface RJBookGradeModel : NSObject

@property (nonatomic, strong)   NSArray<RJBookItemModel *> *item;
// 年级
@property (nonatomic, copy)     NSString *sectionname;
// 出版社
@property (nonatomic, copy)     NSString *publishing;

@end



/***********************************************RJBookItemModel*****************************************************/
@interface RJBookItemModel : NSObject<NSCoding>

//阅读数
@property(nonatomic,assign) NSInteger  readcount;

//路径 比如：/v/menu/1a
@property(nonatomic,strong) NSString * path;

//item名称  比如：一年级（上）
@property(nonatomic,strong) NSString * itemname;

//年级信息
@property(nonatomic,strong) NSString * grade;

//显示的subtitle名称
@property(nonatomic,strong) NSString * subtitle;

//icon 的url地址
@property(nonatomic,strong) NSString * icon;

//书籍ID
@property(nonatomic,strong) NSString * bookid;

//虚拟目录
@property(nonatomic,strong) NSString * vdir;

//下载地址（原始地址）
@property(nonatomic,strong) NSString * downloadurl;

//差分url，下载地址已这个为准
@property(nonatomic,strong) NSString * diffurl;

@property(nonatomic,strong) NSString * backup;

//修改时间
@property(nonatomic,strong) NSString * modifytime;

//书籍名称
@property(nonatomic,strong) NSString * bookname;

//是否支持点读
@property(nonatomic,assign) BOOL clickread;

//更新标志
@property(nonatomic,assign) BOOL updateflag;

@property(nonatomic,assign) BOOL hiq;

@property(nonatomic,strong) NSString * catalogueurl;

@property(nonatomic,strong) NSString *clicktype;

//出版社信息
@property(nonatomic,strong)NSMutableArray<NSString*> *publisher;
@property(nonatomic,assign)NSInteger selectPublish;
@property(nonatomic,strong)NSString *selectPublishString;

@property(nonatomic,assign)BOOL selected;

- (instancetype)copyFrom:(RJBookItemModel *)item;

#pragma mark -新增
//是否支持点读评测
@property(nonatomic,assign) BOOL evaluation;

// 要求app支持的最低版本，默认0
@property(nonatomic,strong)NSString *app_limit_version;

// 是否要求付费
@property(nonatomic,assign)BOOL charge;

//体验是否要求登录
@property(nonatomic,assign)BOOL islogin_experience;

//下载是否要求登录
@property(nonatomic,assign)BOOL islogin_download;

//出版社的bookid
@property(nonatomic,strong)NSString *publish_bookid;

//付费书SDK的ID
@property(nonatomic,strong)NSString *sdk_id;

//书支持磁带或点读   0:磁带 1.点读 2磁带和点读
@property(nonatomic,strong)NSString *tape_click;

//token更新时间
@property(nonatomic,strong)NSDate *tokenUpdatetime;

@end


/***********************************************新结构*****************************************************/


/**
 学期
 */
@interface RJBookTerm : NSObject
/// 学期名。如：上
@property (nonatomic, copy) NSString *sectionname;
/// 教材数组
@property (nonatomic, strong) NSArray<RJBookItemModel *> *section;

@end




/**
 年级
 */
@interface RJBookGrade : NSObject
/// 年级名
@property (nonatomic, copy) NSString *gradename;
/// 学期数组：上、下学期
@property (nonatomic, strong) NSArray<RJBookTerm *> *grade;

@end

















