//
//  NBModelPageInfo.h
//  RJRead
//
//  Created by 相颖 on 15/9/21.
//  Copyright © 2015年 Elephant. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NBModelTrackInfo.h"

@interface NBModelPageInfo : NSObject

@property(nonatomic,strong) NSString *page_name;

@property(nonatomic,strong) NSString *page_url;

@property(nonatomic,strong) NSMutableArray *track_info;

@end
