//
//  DOImageCache.h
//  DayOne
//
//  Created by Ben Dolman on 4/11/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOEntry.h"

enum DOImageCacheRetrievalOptions {
    /**
     * The result of the cache retrieval is saved in the
     * in-memory cache.
     */
    DOImageCacheResultSavedInMemCacheOption = 1 << 0,
    /**
     * If a cache population operation is underway for this
     * identifier the method will block until it's finished.
     */
    DOImageCacheWaitForInProgressPopulate = 1 << 1,
    /**
     * If a matching image is found in the memory cache
     * then it will be returned.
     */
    DOImageCacheTryMemCache = 1 << 2,
    /**
     * If a matching image is found on disk then it
     * will be read and returned.
     */
    DOImageCacheTryDiskCache = 1 << 3,
    /**
     * If the image is not found in memory or on disk
     * then the cache will try to generate it.
     */
    DOImageCachePopulate = 1 << 4
};
typedef NSUInteger DOImageCacheRetrievalOptions;

/**
 * Original size image
 */
extern NSString *const DOOriginalImageType;

@protocol DOImageCacheDelegate;
@protocol DOImageCacheDatasource;

@interface DOImageCache : NSObject {
    NSURL *cacheDir;
    NSCache *memCache;
    NSOperationQueue *imageProcessingQueue;
    NSMutableDictionary *inProcessOps;
}

@property (unsafe_unretained) id<DOImageCacheDelegate> delegate;
@property (unsafe_unretained) id<DOImageCacheDatasource> datasource;

/**
 * Initializes the cache and sets the location for where the images
 * will be kept on disk.
 */
- (id) initWithDirectoryURL:(NSURL *)directoryURL;

/**
 * Returns an image for an identifier. The exact retreival behavior depends on
 * the options specified.
 */
- (id)imageForIdentifier:(NSString *)identifier andImageType:(NSString *)imageType 
                 options:(DOImageCacheRetrievalOptions)options;

/**
 * Returns an image for an identifier. This method uses the following
 * short-circuited logic:
 *  1. Check for image in the in-memory cache
 *  2. Check for image in the disk cache
 *  3. Ask the delegate to provide an image, then cache it and return it.
 *
 * Calling this method is the same as calling imageForIdentifier:andImagetype:options
 * with all options set.
 */
- (id)imageForIdentifier:(NSString *)identifier andImageType:(NSString *)imageType;

/**
 * A convenience method that can yield dramatically improved performance.
 * If you are using DOEntry in conjunction with DOJournalIndex you should
 * prefer this method to imageForIdentifier:andImageType.
 */
- (id)imageForEntry:(DOEntry *)entry andImageType:(NSString *)imageType;

/**
 * Pre-caches an image
 */
- (void)setImageFile:(NSURL *)imageFile withIdentifier:(NSString *)identifier;

/**
 * Returns YES if the image is already in the in-memory cache
 */
- (BOOL)imageIsCachedInMemory:(NSString *)identifier imageType:(NSString *)imageType;

@end


@protocol DOImageCacheDelegate <NSObject>
@required
- (NSURL *)imageCache:(DOImageCache *)imageCache imageFileForIdentifier:(NSString *)identifier;

@end

@protocol DOImageCacheDatasource <NSObject>
@required
- (BOOL)imageCache:(DOImageCache *)imageCache 
        writeImage:(id)image 
         imageType:(NSString *)imageType 
             toURL:(NSURL *)fileURL 
             error:(NSError **)error;

- (id)imageCache:(DOImageCache *)imageCache readImageAtURL:(NSURL *)fileURL;

- (NSUInteger)imageCache:(DOImageCache *)imageCache calculateCacheCostForImage:(id)image;

- (NSArray *)imageCacheDiskCachedImageTypes:(DOImageCache *)imageCache;

- (id)imageCache:(DOImageCache *)imageCache 
produceImageForIdentifier:(NSString *)identifier 
    andImageType:(NSString *)imageType;

@end