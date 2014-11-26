//
//  DOWebPublishRequestQueue.h
//  DOCore
//
//  Created by Ben Dolman on 8/29/13.
//
//

#import <Foundation/Foundation.h>
#import "DOWebPublishRequest.h"
#import "DOJournalIndex.h"

/**
 * This class provides a queue to manage publish requests and to update the core data representation
 * once those requests have succcessfully completed.
 */
@interface DOWebPublishRequestQueue : NSObject

/**
 * Returns an array of unfinished requests. Requests are included in this array until finishRequest is called.
 */
@property (nonatomic, readonly) NSArray *requests;

/**
 * Initializes the request queue with the index's managed object context and also updates entry files
 * after a successful publish.
 */
- (instancetype)initWithIndex:(DOJournalIndex *)index;

/**
 * Creates a request queue that will update the specified managed object context when each request successfully
 * completes. This is the designated initializer.
 */
- (instancetype)initWithUpdateContext:(NSManagedObjectContext *)context;

/**
 * Adds a request to the queue. The queue will automatically call startPublish on the request at an appropriate
 * time, so do not add a request to the queue until you are ready to actually start publishing it.
 *
 * NOTE: DOWebPublishRequestQueue assigns itself as the delegate of the request.
 */
- (void)addRequest:(DOWebPublishRequest *)request;

/**
 * Indicates that a publish request can be removed from the queue. You would only usually do this once the request
 * has finished or you have cancelled the request. Note that this does NOT cancel a request, it simply removes
 * it from the queue. If you want to cancel an individual request, cancel it manually then call finishRequest:
 */
- (void)finishRequest:(DOWebPublishRequest *)request;

/**
 * A convenience method for cancelling all requests and removing them from the queue.
 */
- (void)cancelAndFinishAllRequests;

@end
