//
//  DOWebEnrollment.h
//  DOCore
//
//  Created by Ben Dolman on 8/8/13.
//
//

#import "DOWebObject.h"

extern NSString * const DOWebEnrollmentKindOAuth;

/**
 * An enrollment represents a specific authorization with a provider.
 * Enrollments allow for a person to have, for example, two different twitter accounts.
 */
@interface DOWebEnrollment : DOWebObject <MTLManagedObjectSerializing>

/**
 * Formats an enrollment label for display according to provider-specific settings.
 * For Twitter, this returns the label prepended with an '@' symbol
 */
+ (NSString *)formatLabelForDisplay:(NSString *)label forProvider:(NSString *)providerID;

@property (nonatomic, copy) NSString *providerID;
@property (nonatomic, copy) NSString *enrollmentID;
@property (nonatomic, copy) NSString *kind;
@property (nonatomic, copy) NSString *externalID;
@property (nonatomic, copy) NSString *label;
@property (nonatomic, copy) NSURL *avatarURL;
@property (nonatomic, copy) NSURL *profileURL;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *statusMessage;
@property (nonatomic, copy, readonly) NSString *displayLabel;

@end
