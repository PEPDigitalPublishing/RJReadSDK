//
//  NBModelTrackInfo.h
//  RJRead
//
//  Created by 相颖 on 15/9/21.
//  Copyright © 2015年 Elephant. All rights reserved.
//

#import <Foundation/Foundation.h>

@class NBModelFollowTrack;

@interface NBModelTrackInfo : NSObject

@property(nonatomic,strong) NSString * mp3name;

@property(nonatomic,strong) NSString * mp3url;

@property(nonatomic,strong) NSString * mp3url_hiq;

@property(nonatomic,strong) NSString * track_auend;

@property(nonatomic,strong) NSString * track_austart;

@property(nonatomic,assign) CGFloat  track_bottom;

@property(nonatomic,strong) NSString * track_genre;

@property(nonatomic,assign) NSInteger track_id;

@property(nonatomic,assign) CGFloat  track_left;

@property(nonatomic,assign) CGFloat  track_right;

@property(nonatomic,assign) CGFloat  track_top;

//user
@property(nonatomic,assign) int pageIndex;

@property(nonatomic,assign)NSInteger trackIndex;

//跟读评测扩展
@property(nonatomic,strong) NSString * track_txt;

@property(nonatomic,weak) NBModelFollowTrack *followTrack;

//点读方式拓展mp4、gif
@property(nonatomic,strong) NSString *extend_type;
//mp4或gif的地址
@property(nonatomic,strong) NSString *extend_url;
//资源的比例大小（视频为宽高比，gif为放大倍数）
@property(nonatomic,strong) NSString *extend_ratio;
//git展示模式
//normal          标准播放
//original        原地播放（如随文识字笔画播放）
@property(nonatomic,strong) NSString *extend_gif_mode;

@end
