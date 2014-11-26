#import "_DOPublication.h"
#import "DOWebEntry.h"
#import "DOWebClient.h"

@interface DOPublication : _DOPublication {}

- (DOShare *)shareWithEnrollmentID:(NSString *)enrollmentID
                         inContext:(NSManagedObjectContext *)context
                             error:(NSError **)error;

@end

@interface DOPublication (WhiteList)

/**
 * The result of -shares with unsupported shares removed.
 * @see DOProvider
 */
@property (nonatomic, readonly) NSOrderedSet *whiteListedShares;

@end