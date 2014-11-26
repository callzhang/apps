//
//  DOPhotoProcessor.h
//  DOCore
//
//  Created by Ben Dolman on 8/1/12.
//
//

#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>
#import <CoreLocation/CoreLocation.h>

extern const CGFloat DOEntryPhotoCompressionFactor;
extern const NSInteger DOEntryPhotoMaxSizePixels;

@interface DOPhotoProcessor : NSObject

/// Returns an NSData containing JPEG data processed for attachment to a journal entry
/// @param metadataOrNil If nil, metadata will be read from the image source.
+ (NSData *)entryImageDataForSource:(CGImageSourceRef)source metadata:(NSDictionary *)metadataOrNil;

+ (NSData *)entryImageDataForSource:(CGImageSourceRef)source;
+ (NSData *)entryImageDataForImageFile:(NSURL *)imageFileURL;
+ (NSData *)entryImageDataForImageData:(NSData *)imageData;
+ (NSData *)entryImageDataForCGImage:(CGImageRef)imageRef withMetadata:(NSDictionary *)metadata;

+ (CLLocation *)locationForImageSource:(CGImageSourceRef)source;
+ (CLLocation *)locationForImageFile:(NSURL *)imageFileURL;
+ (CLLocation *)locationForImageData:(NSData *)imageData;

+ (NSDate *)photoDateForImageSource:(CGImageSourceRef)imageSource;
+ (NSDate *)photoDateForImageFile:(NSURL *)imageFileURL;
+ (NSDate *)photoDateForImageData:(NSData *)photoData;

@end
