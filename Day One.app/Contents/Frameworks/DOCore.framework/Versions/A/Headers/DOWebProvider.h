//
//  DOWebProvider.h
//  DOCore
//
//  Created by Ben Dolman on 8/7/13.
//
//

#import "DOWebObject.h"

extern NSString * const DOWebProviderIDFacebook;
extern NSString * const DOWebProviderIDTwitter;
extern NSString * const DOWebProviderIDFoursquare;
extern NSString * const DOWebProviderIDTumblr;

/**
 * A provider represents a supported service, such as Twitter.
 */
@interface DOWebProvider : DOWebObject <MTLManagedObjectSerializing>

@property (nonatomic, copy) NSString *providerID;
@property (nonatomic, copy) NSString *providerDescription;
@property (nonatomic, copy) NSString *providerName;
@property (nonatomic, copy) NSArray *enrollmentKinds;   // Array of NSString. Possible values listed in DOWebEnrollment.h
@property (nonatomic, copy) NSDictionary *imageURLs;
@property (nonatomic, copy) NSNumber *sort;
@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, copy) NSString *externalID;

@end
