//
//  DOAnalytics.h
//  DOCore
//
//  Created by Ben Dolman on 2/11/13.
//
//

#import <Foundation/Foundation.h>

@interface DOAnalytics : NSObject

+ (NSString *) bucketNameForEntryCount:(NSUInteger)entryCount;
+ (NSString *) bucketNameForCharCount:(NSUInteger)charCount;
+ (NSString *) bucketNameForWordCount:(NSUInteger)wordCount;
+ (NSString *) bucketNameForTagCount:(NSUInteger)tagCount;
+ (NSString *) bucketNameForExportFileSize:(long long)fileSizeBytes;
+ (NSString *) bucketNameForPercentage:(float)fraction;

+ (NSString *) paramNameForBool:(BOOL)boolVal;

@end
