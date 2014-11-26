//
//  DOWebShare.h
//  DOCore
//
//  Created by Ben Dolman on 8/8/13.
//
//

#import "DOWebObject.h"
#import "DOWebEnrollment.h"

extern NSString * const DOWebShareStatsTwitterFavoritesKey;
extern NSString * const DOWebShareStatsTwitterRetweetsKey;

/**
 * A share object gives information about a shared entry. You can find out when it was shared,
 * get a link to the share on the provider's website (e.g. a tweet URL) and find out provider-specific stats.
 */
@interface DOWebShare : DOWebObject <MTLManagedObjectSerializing>

@property (nonatomic, copy) DOWebEnrollment *enrollment;
@property (nonatomic, copy) NSURL *linkURL;
@property (nonatomic, copy) NSDate *createdDate;
@property (nonatomic, copy) NSDate *refreshedDate;
@property (nonatomic, copy) NSString *externalID;
@property (nonatomic, copy) NSDictionary *stats; // Values are provider-specific. Keys are listed at top of file.

@end
