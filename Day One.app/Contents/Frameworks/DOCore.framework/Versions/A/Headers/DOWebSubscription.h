//
//  DOWebSubscription.h
//  DOCore
//
//  Created by Ben Dolman on 6/25/13.
//
//

#import "DOWebObject.h"

// Values of the kind property
extern NSString * const DOWebSubscriptionKindStandard;
extern NSString * const DOWebSubscriptionKindPremium;

@interface DOWebSubscription : DOWebObject

@property (nonatomic, strong) NSDate *expirationDate;
@property (nonatomic, assign) NSUInteger publishQuota;
@property (nonatomic, assign) NSUInteger publishUsed;
@property (nonatomic, copy) NSString *kind;

@property (nonatomic, readonly) BOOL isPremium;

@end
