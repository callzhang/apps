//
//  NSString+Hashtags.h
//  DOCore
//
//  Created by Ben Dolman on 10/26/12.
//
//

#import <Foundation/Foundation.h>

@interface NSString (Hashtags)

/**
 * Returns the set of hashtags found in the string.
 * The return values are NSStrings and do NOT contain the hashtag character.
 */
- (NSSet *)hashtags;

/**
 * Returns an array of ranges identifying hashtags
 * found in the string. The return values are NSValue range objects.
 * The ranges do NOT contain the hashtag character.
 */
- (NSArray *)hashtagRanges;

@end
