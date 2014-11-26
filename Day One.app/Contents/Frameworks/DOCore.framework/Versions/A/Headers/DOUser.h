#import "_DOUser.h"
#import "DOWebUser.h"
#import "DOWebClient.h"

@interface DOUser : _DOUser {}

/**
 * Returns the current, logged-in user or nil if not logged in.
 */
+ (DOUser *)currentUserInContext:(NSManagedObjectContext *)context;

+ (void)updateCurrentUserWithClient:(DOWebClient *)client
                          inContext:(NSManagedObjectContext *)context
                            success:(void (^)(DOUser *user))success
                            failure:(void (^)(NSError *error))failure;

+ (DOUser *)updateCurrentUserWithWebUser:(DOWebUser *)webUser
                               inContext:(NSManagedObjectContext *)context
                                   error:(NSError **)error;

@end

@interface DOUser (WhiteList)

/**
 * The result of -enrollments with unsupported enrollments removed.
 * @see DOProvider
 */
@property (nonatomic, readonly) NSOrderedSet *whiteListedEnrollments;

@end