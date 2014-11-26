//
//  NSObject+Blocks.h
//  DOCore
//
//  Created by Adam Kirk on 7/12/13.
//
//

#import <Foundation/Foundation.h>


@interface NSOperationQueue (Delay)
- (void)addOperationAfterDelay:(NSTimeInterval)delay withBlock:(void (^)(void))block;
@end
