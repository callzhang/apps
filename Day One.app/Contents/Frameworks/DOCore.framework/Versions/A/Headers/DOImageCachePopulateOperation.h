//
//  DOImageCacheOperation.h
//  DayOne
//
//  Created by Ben Dolman on 4/11/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class DOImageCache;

@interface DOImageCachePopulateOperation : NSOperation

@property (strong) DOImageCache *imageCache;
@property (copy) NSURL *cacheDir;
@property (strong) NSURL *imageFile;
@property (copy) NSString *identifier;
@property (copy) void(^completionBlock)(BOOL success);

@end

@interface DOImageCacheEvictOperation : NSOperation

@property (strong) DOImageCache *imageCache;
@property (copy) NSURL *cacheDir;
@property (copy) NSString *identifier;

@end