#import "_DOProvider.h"
#import "DOWebProvider.h"
#import "DOWebClient.h"

@interface DOProvider : _DOProvider {}

+ (NSArray *)allProvidersInContext:(NSManagedObjectContext *)context;
+ (DOProvider *)providerWithID:(NSString *)providerID inContext:(NSManagedObjectContext *)context;

+ (NSArray *)updateAllProvidersWithWebProviders:(NSArray *)webProviders
                                      inContext:(NSManagedObjectContext *)context
                                          error:(NSError **)error;

+ (void)updateAllProvidersWithClient:(DOWebClient *)client
                           inContext:(NSManagedObjectContext *)context
                             success:(void (^)(NSArray *providers))success
                             failure:(void (^)(NSError *error))failure;

@end

/**
 * The client apps may not support all the providers supported on the server. Apps can pass in the set
 * of supported provider IDs into +setWhiteListedProviderIDs: and unsupported providers, enrollments
 * and shares will be filtered out of the white list calls on each of those objects.
 */
@interface DOProvider (WhiteList)

/**
 * YES if the providerID of this object is in the white list or if no white list has been set
 */
@property (nonatomic, readonly) BOOL isWhiteListed;

/**
 * Returns the array of white listed provider IDs. nil by default
 */
+ (NSArray *)whiteListedProviderIDs;

/**
 * Set the white listed provider IDs. A nil value disables white listing.
 */
+ (void)setWhiteListedProviderIDs:(NSArray *)providerIDs;

/**
 * The result of -allProvidersInContext: with unsupported providers removed.
 */
+ (NSArray *)allWhiteListedProvidersInContext:(NSManagedObjectContext *)context;

@end
