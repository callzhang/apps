#import "_DOPublishedEntry.h"
#import "DOWebClient.h"

@interface DOPublishedEntry : _DOPublishedEntry {}

/**
 * Returns the object with the specified publish ID. If a publication with this ID does not exist, nil is returned.
 */
+ (DOPublishedEntry *)publishedEntryWithPublishID:(NSString *)publishID inContext:(NSManagedObjectContext *)context;

+ (void)updatePublishedEntryWithPublishID:(NSString *)publishID
                               withClient:(DOWebClient *)client
                                inContext:(NSManagedObjectContext *)context
                                  success:(void (^)(DOPublishedEntry *publishedEntry))success
                                  failure:(void (^)(NSError *error))failure;

+ (DOPublishedEntry *)updatePublishedEntryWithWebEntry:(DOWebEntry *)webEntry
                                             inContext:(NSManagedObjectContext *)context
                                                 error:(NSError **)error;

@end
