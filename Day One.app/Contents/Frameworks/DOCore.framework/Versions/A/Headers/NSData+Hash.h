//
//  NSData+Hash.h
//  DOCore
//
//  Created by Ben Dolman on 3/3/14.
//
//

#import <Foundation/Foundation.h>

@interface NSData (Hash)

/**
 * Returns the MD5 hash of the data as a hex string.
 * Example: "d61742f85d69b396691a18fbf153998e"
 */
- (NSString *)do_MD5;

@end
