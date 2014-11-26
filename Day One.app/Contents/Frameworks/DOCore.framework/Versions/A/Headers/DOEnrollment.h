#import "_DOEnrollment.h"
#import "DOWebEnrollment.h"

@interface DOEnrollment : _DOEnrollment {}

/**
 * Formats the label for display according to provider-specific settings.
 * For Twitter, this returns the label prepended with an '@' symbol
 */
@property (nonatomic, copy, readonly) NSString *displayLabel;

+ (DOEnrollment *)userEnrollmentWithID:(NSString *)enrollmentID inContext:(NSManagedObjectContext *)context;

@end
