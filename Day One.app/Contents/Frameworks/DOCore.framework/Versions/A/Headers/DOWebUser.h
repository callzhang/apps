//
//  DOWebUser.h
//  DOCore
//
//  Created by Ben Dolman on 5/7/13.
//
//

#import "DOWebObject.h"
#import "DOWebSubscription.h"
#import "DOWebEnrollment.h"

@interface DOWebUser : DOWebObject <MTLManagedObjectSerializing>

@property (nonatomic, copy) NSString *userID;
@property (nonatomic, copy) NSString *realName;
@property (nonatomic, copy) NSString *email;
@property (nonatomic, copy) NSString *password;
@property (nonatomic, strong) DOWebSubscription *subscription;
@property (nonatomic, copy) NSArray *enrollments;
@property (nonatomic, copy) NSArray *featureEnrollments;
@property (nonatomic, copy) NSString *avatarMediaID;
@property (nonatomic, copy) NSString *bio;
@property (nonatomic, copy) NSURL *websiteURL;

@end