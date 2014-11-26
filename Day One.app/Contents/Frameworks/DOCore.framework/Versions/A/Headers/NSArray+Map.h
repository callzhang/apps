//
//  NSArray+Map.h
//  DOCore
//
//  Created by Leonty Deriglazov on 27/11/2012.
//
//

#import <Foundation/Foundation.h>

typedef id (^MappingBlock)(id);

@interface NSArray (Map)

- (NSArray *)mapWithBlock:(MappingBlock)mappingBlock;

@end
