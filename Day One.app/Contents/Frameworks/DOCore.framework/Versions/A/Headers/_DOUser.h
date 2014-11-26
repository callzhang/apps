// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOUser.h instead.

#import <CoreData/CoreData.h>


extern const struct DOUserAttributes {
	__unsafe_unretained NSString *avatarMediaID;
	__unsafe_unretained NSString *bio;
	__unsafe_unretained NSString *email;
	__unsafe_unretained NSString *realName;
	__unsafe_unretained NSString *userID;
	__unsafe_unretained NSString *websiteURL;
} DOUserAttributes;

extern const struct DOUserRelationships {
	__unsafe_unretained NSString *enrollments;
	__unsafe_unretained NSString *featureEnrollments;
} DOUserRelationships;

extern const struct DOUserFetchedProperties {
} DOUserFetchedProperties;

@class DOEnrollment;
@class DOFeatureEnrollment;






@class NSURL;

@interface DOUserID : NSManagedObjectID {}
@end

@interface _DOUser : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOUserID*)objectID;





@property (nonatomic, strong) NSString* avatarMediaID;



//- (BOOL)validateAvatarMediaID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* bio;



//- (BOOL)validateBio:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* email;



//- (BOOL)validateEmail:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* realName;



//- (BOOL)validateRealName:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* userID;



//- (BOOL)validateUserID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSURL* websiteURL;



//- (BOOL)validateWebsiteURL:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSOrderedSet *enrollments;

- (NSMutableOrderedSet*)enrollmentsSet;




@property (nonatomic, strong) NSOrderedSet *featureEnrollments;

- (NSMutableOrderedSet*)featureEnrollmentsSet;





@end

@interface _DOUser (CoreDataGeneratedAccessors)

- (void)addEnrollments:(NSOrderedSet*)value_;
- (void)removeEnrollments:(NSOrderedSet*)value_;
- (void)addEnrollmentsObject:(DOEnrollment*)value_;
- (void)removeEnrollmentsObject:(DOEnrollment*)value_;

- (void)addFeatureEnrollments:(NSOrderedSet*)value_;
- (void)removeFeatureEnrollments:(NSOrderedSet*)value_;
- (void)addFeatureEnrollmentsObject:(DOFeatureEnrollment*)value_;
- (void)removeFeatureEnrollmentsObject:(DOFeatureEnrollment*)value_;

@end

@interface _DOUser (CoreDataGeneratedPrimitiveAccessors)


- (NSString*)primitiveAvatarMediaID;
- (void)setPrimitiveAvatarMediaID:(NSString*)value;




- (NSString*)primitiveBio;
- (void)setPrimitiveBio:(NSString*)value;




- (NSString*)primitiveEmail;
- (void)setPrimitiveEmail:(NSString*)value;




- (NSString*)primitiveRealName;
- (void)setPrimitiveRealName:(NSString*)value;




- (NSString*)primitiveUserID;
- (void)setPrimitiveUserID:(NSString*)value;




- (NSURL*)primitiveWebsiteURL;
- (void)setPrimitiveWebsiteURL:(NSURL*)value;





- (NSMutableOrderedSet*)primitiveEnrollments;
- (void)setPrimitiveEnrollments:(NSMutableOrderedSet*)value;



- (NSMutableOrderedSet*)primitiveFeatureEnrollments;
- (void)setPrimitiveFeatureEnrollments:(NSMutableOrderedSet*)value;


@end
