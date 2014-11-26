//
//  NSURL+Subpath.h
//  DOCore
//
//  Created by Ben Dolman on 7/7/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (Subpath)

- (BOOL)isSubpathOfURL:(NSURL *)url;

@end
