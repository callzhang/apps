// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOFeatureEnrollment.h instead.

#import <CoreData/CoreData.h>


extern const struct DOFeatureEnrollmentAttributes {
	__unsafe_unretained NSString *createDate;
	__unsafe_unretained NSString *enrollmentID;
	__unsafe_unretained NSString *feature;
	__unsafe_unretained NSString *isActive;
} DOFeatureEnrollmentAttributes;

extern const struct DOFeatureEnrollmentRelationships {
	__unsafe_unretained NSString *user;
} DOFeatureEnrollmentRelationships;

extern const struct DOFeatureEnrollmentFetchedProperties {
} DOFeatureEnrollmentFetchedProperties;

@class DOUser;






@interface DOFeatureEnrollmentID : NSManagedObjectID {}
@end

@interface _DOFeatureEnrollment : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOFeatureEnrollmentID*)objectID;





@property (nonatomic, strong) NSDate* createDate;



//- (BOOL)validateCreateDate:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* enrollmentID;



@property int64_t enrollmentIDValue;
- (int64_t)enrollmentIDValue;
- (void)setEnrollmentIDValue:(int64_t)value_;

//- (BOOL)validateEnrollmentID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* feature;



//- (BOOL)validateFeature:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* isActive;



@property BOOL isActiveValue;
- (BOOL)isActiveValue;
- (void)setIsActiveValue:(BOOL)value_;

//- (BOOL)validateIsActive:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOUser *user;

//- (BOOL)validateUser:(id*)value_ error:(NSError**)error_;





@end

@interface _DOFeatureEnrollment (CoreDataGeneratedAccessors)

@end

@interface _DOFeatureEnrollment (CoreDataGeneratedPrimitiveAccessors)


- (NSDate*)primitiveCreateDate;
- (void)setPrimitiveCreateDate:(NSDate*)value;




- (NSNumber*)primitiveEnrollmentID;
- (void)setPrimitiveEnrollmentID:(NSNumber*)value;

- (int64_t)primitiveEnrollmentIDValue;
- (void)setPrimitiveEnrollmentIDValue:(int64_t)value_;




- (NSString*)primitiveFeature;
- (void)setPrimitiveFeature:(NSString*)value;




- (NSNumber*)primitiveIsActive;
- (void)setPrimitiveIsActive:(NSNumber*)value;

- (BOOL)primitiveIsActiveValue;
- (void)setPrimitiveIsActiveValue:(BOOL)value_;





- (DOUser*)primitiveUser;
- (void)setPrimitiveUser:(DOUser*)value;


@end
