//
//  NBFollowTrackResult.h
//  RJRead
//
//  Created by 相颖 on 16/6/16.
//  Copyright © 2016年 Elephant. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBFollowWords : NSObject

@property(nonatomic,strong)NSString *text;
@property(nonatomic,assign)float score;
@property(nonatomic,assign)NSInteger type;  //0

@end

@interface NBFollowTrackResult : NSObject

@property(nonatomic,assign)float  score;
@property(nonatomic,strong)NSString *sample;
@property(nonatomic,strong)NSString *usertext;
@property(nonatomic,strong)NSArray<NBFollowWords *> *words;
@property(nonatomic,strong)NSString *fluency; ///<NBFollowWords>

@end
