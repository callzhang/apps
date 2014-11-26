//
//  DOWebFeatureEnrollment.h
//  DOCore
//
//  Created by Ben Dolman on 3/3/14.
//
//

#import <DOCore/DOWebObject.h>

extern NSString * const DOWebFeaturePublish;

@interface DOWebFeatureEnrollment : DOWebObject <MTLManagedObjectSerializing>

@property (nonatomic, copy) NSNumber *enrollmentID;
@property (nonatomic, copy) NSString *feature;
@property (nonatomic, copy) NSDate *createDate;
@property (nonatomic, assign) BOOL isActive;

@end
