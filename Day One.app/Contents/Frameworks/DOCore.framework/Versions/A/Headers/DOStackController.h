//
//  DOStackController.h
//  DayOne
//
//  Created by Ben Dolman on 5/10/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//
//  Last-in-first-out stack controller class
//  Adapted from http://stackoverflow.com/questions/7567827/last-in-first-out-stack-with-gcd
//

#import <objc/runtime.h>
#import <Foundation/Foundation.h>

@interface DOStackController : NSObject {
    NSMutableArray *stack;
}

- (void) addBlock:(void (^)(void))block;
- (void) startNextBlock;
+ (void) performBlock:(void (^)(void))block;

@end
