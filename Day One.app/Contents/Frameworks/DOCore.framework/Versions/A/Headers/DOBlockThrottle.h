//
//  DOBlockThrottle.h
//  DayOne
//
//  Created by Ben Dolman on 5/17/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Throttles the execution of a block by making sure that it
 * executes no more than once in the specified time interval.
 * Useful to prevent an expensive, repetitive operation such as
 * a query from executing back-to-back, over and over again.
 *
 * To use, you create a block that performs the expensive work
 * and decide the acceptable interval between calls. When you
 * need that work performed you call -scheduleWork.
 */
@interface DOBlockThrottle : NSObject {
    void(^workBlock)(void);
    dispatch_queue_t dispatchQueue;
    NSTimeInterval timeInterval;
    NSDate *lastRun;
    BOOL isScheduled;
}

-(id)initWithDispatchQueue:(dispatch_queue_t)queue 
              workInterval:(NSTimeInterval)interval
                 workBlock:(void(^)(void))block;

-(void)scheduleWork;

@end
