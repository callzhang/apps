// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOEnrollment.h instead.

#import <CoreData/CoreData.h>


extern const struct DOEnrollmentAttributes {
	__unsafe_unretained NSString *avatarURL;
	__unsafe_unretained NSString *enrollmentID;
	__unsafe_unretained NSString *externalID;
	__unsafe_unretained NSString *kind;
	__unsafe_unretained NSString *label;
	__unsafe_unretained NSString *profileURL;
	__unsafe_unretained NSString *providerID;
	__unsafe_unretained NSString *status;
	__unsafe_unretained NSString *statusMessage;
} DOEnrollmentAttributes;

extern const struct DOEnrollmentRelationships {
	__unsafe_unretained NSString *provider;
	__unsafe_unretained NSString *shares;
	__unsafe_unretained NSString *user;
} DOEnrollmentRelationships;

extern const struct DOEnrollmentFetchedProperties {
} DOEnrollmentFetchedProperties;

@class DOProvider;
@class DOShare;
@class DOUser;

@class NSURL;




@class NSURL;




@interface DOEnrollmentID : NSManagedObjectID {}
@end

@interface _DOEnrollment : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOEnrollmentID*)objectID;





@property (nonatomic, strong) NSURL* avatarURL;



//- (BOOL)validateAvatarURL:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* enrollmentID;



//- (BOOL)validateEnrollmentID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* externalID;



//- (BOOL)validateExternalID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* kind;



//- (BOOL)validateKind:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* label;



//- (BOOL)validateLabel:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSURL* profileURL;



//- (BOOL)validateProfileURL:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* providerID;



//- (BOOL)validateProviderID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* status;



//- (BOOL)validateStatus:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* statusMessage;



//- (BOOL)validateStatusMessage:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOProvider *provider;

//- (BOOL)validateProvider:(id*)value_ error:(NSError**)error_;




@property (nonatomic, strong) NSSet *shares;

- (NSMutableSet*)sharesSet;




@property (nonatomic, strong) DOUser *user;

//- (BOOL)validateUser:(id*)value_ error:(NSError**)error_;





@end

@interface _DOEnrollment (CoreDataGeneratedAccessors)

- (void)addShares:(NSSet*)value_;
- (void)removeShares:(NSSet*)value_;
- (void)addSharesObject:(DOShare*)value_;
- (void)removeSharesObject:(DOShare*)value_;

@end

@interface _DOEnrollment (CoreDataGeneratedPrimitiveAccessors)


- (NSURL*)primitiveAvatarURL;
- (void)setPrimitiveAvatarURL:(NSURL*)value;




- (NSString*)primitiveEnrollmentID;
- (void)setPrimitiveEnrollmentID:(NSString*)value;




- (NSString*)primitiveExternalID;
- (void)setPrimitiveExternalID:(NSString*)value;




- (NSString*)primitiveKind;
- (void)setPrimitiveKind:(NSString*)value;




- (NSString*)primitiveLabel;
- (void)setPrimitiveLabel:(NSString*)value;




- (NSURL*)primitiveProfileURL;
- (void)setPrimitiveProfileURL:(NSURL*)value;




- (NSString*)primitiveProviderID;
- (void)setPrimitiveProviderID:(NSString*)value;




- (NSString*)primitiveStatus;
- (void)setPrimitiveStatus:(NSString*)value;




- (NSString*)primitiveStatusMessage;
- (void)setPrimitiveStatusMessage:(NSString*)value;





- (DOProvider*)primitiveProvider;
- (void)setPrimitiveProvider:(DOProvider*)value;



- (NSMutableSet*)primitiveShares;
- (void)setPrimitiveShares:(NSMutableSet*)value;



- (DOUser*)primitiveUser;
- (void)setPrimitiveUser:(DOUser*)value;


@end
