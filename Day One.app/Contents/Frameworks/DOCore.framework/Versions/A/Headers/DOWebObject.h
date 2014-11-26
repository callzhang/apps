//
//  DOWebObject.h
//  DOCore
//
//  Created by Ben Dolman on 6/25/13.
//
//  Abstract class for web objects. Subclasses must implement DOMapped.

#import <Mantle/Mantle.h>

@interface DOWebObject : MTLModel <MTLJSONSerializing>

@end
