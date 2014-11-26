#import "_DOFeatureEnrollment.h"

@interface DOFeatureEnrollment : _DOFeatureEnrollment {}

+ (DOFeatureEnrollment *)userFeatureEnrollmentForFeature:(NSString *)feature
                                               inContext:(NSManagedObjectContext *)context;

@end
