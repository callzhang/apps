//
//  DOWebPublishSync.h
//  DOCore
//
//  Created by Ben Dolman on 8/22/13.
//
//

#import <Foundation/Foundation.h>
#import "DOWebClient.h"
#import "DOJournalIndex.h"

/**
 * Watches for changes to published entries on the Day One server and updates the
 * the core data store to reflect those changes. Once started, this object checks for changes
 * every 30 seconds.
 *
 * DOWebPublishSync is thread-safe.
 */
@interface DOWebPublishSync : NSObject

@property (nonatomic, strong, readonly) DOWebClient *client;
@property (nonatomic, strong, readonly) NSManagedObjectContext *context;

/**
 * YES if start has been called on the object.
 */
@property (atomic, assign, readonly, getter = isRunning) BOOL running;

/**
 * This resets all metadata (delta and sync date) associated with publish sync.
 *
 * NOTE: This will NOT delete any publication objects. You need to do that yourself.
 * WARNING: You should not call this while a sync is running.
 */
+ (void)resetSyncMetadataUsingContext:(NSManagedObjectContext *)context;

/**
 * Initializes a new publish sync object using the specified client and context.
 *
 * @param client The client that will be used to communicate with the server.
 * @param context The context in which data will be updated and saved when it changes on the server. You should
 *                use a dedicated context as it is reset periodically.
 */
- (instancetype)initWithClient:(DOWebClient *)client context:(NSManagedObjectContext *)context;


/**
 * Schedules an immediate sync and then automatically performs a sync at 30 second intervals.
 * After creating an instance of DOWebPublishSync you must call this to begin the process.
 */
- (void)start;

/**
 * Cancels current and scheduled syncs. No more syncs will happen until start is called again.
 */
- (void)stop;

/**
 * Returns the date of the last successful sync.
 */
- (NSDate *)lastSyncDate;

@end