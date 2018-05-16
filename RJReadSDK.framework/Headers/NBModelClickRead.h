//
//  NBModelClickRead.h
//  RJRead
//
//  Created by 相颖 on 15/9/21.
//  Copyright © 2015年 Elephant. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBModelBookAudio.h"
#import "NBModelPageInfo.h"

@interface NBModelClickRead : NSObject

@property(nonatomic,strong)NBModelBookAudio      *bookaudio;

@property(nonatomic,strong)NSMutableArray<NBModelPageInfo *> *bookpage;

//微信分享对象
@property(nonatomic,strong)NSDictionary   *wxshare;

@property(nonatomic,strong)NSString       *updateUrl;

@end
