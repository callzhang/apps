//
//  DOWebSync.h
//  DOCore
//
//  Created by Ben Dolman on 1/2/14.
//
//

#import <Foundation/Foundation.h>
#import "DOWebClient.h"

/**
 * Keeps the local data model in sync with the server. This is a one-way sync from the server to the client.
 *
 * Published entries are synced on a 30 second interval.
 * The user and provider objects are updated periodically.
 */
@interface DOWebSync : NSObject

/**
 * YES if start has been called on the object.
 */
@property (atomic, assign, readonly, getter = isRunning) BOOL running;

/**
 * Deletes all synced data from the local data store. Call this whenever a user logs out to reset everything.
 * @warning Make sure that you stop the sync process before doing this!
 */
+ (void)resetLocalDataInContext:(NSManagedObjectContext *)context;

/**
 * Initializes a new web sync object using the specified client and context.
 *
 * @param client The client that will be used to communicate with the server. You should pass in a dedicated client
 *               object as the web sync process will sometimes cancel all requests on this client.
 * @param context The context in which data will be updated and saved when it changes on the server.
 */
- (instancetype)initWithClient:(DOWebClient *)client context:(NSManagedObjectContext *)context;

/**
 * Begins syncing.
 */
- (void)start;

/**
 * Stops syncing
 */
- (void)stop;

@end
