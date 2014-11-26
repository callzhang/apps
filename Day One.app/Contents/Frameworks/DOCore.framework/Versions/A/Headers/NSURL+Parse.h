//
//  NSURL+Parse.h
//  DOCore
//
//  Created by Ben Dolman on 7/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (Parse)

/**
 * Method: parseURLParameters:
 * Takes a NSURL and parses out all the parameters into a NSDictionary of key/values
 * Currently doesn't handle all error cases
 */
+ (NSDictionary *)parseURLParameters:(NSURL *)url;

@end
