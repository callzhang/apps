//
//  DOWebBaseURLs.h
//  DOCore
//
//  Created by Ben Dolman on 2/13/14.
//
//

#import <Foundation/Foundation.h>

/**
 * Default base URLs for our different environments. These are provided here for app convenience only;
 * they are not referenced at all within the core project.
 */
@interface DOWebBaseURLs : NSObject

+ (NSURL *)productionURL;
+ (NSURL *)stagingURL;
+ (NSURL *)localhostURL;

@end
