// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOShare.h instead.

#import <CoreData/CoreData.h>


extern const struct DOShareAttributes {
	__unsafe_unretained NSString *createdDate;
	__unsafe_unretained NSString *externalID;
	__unsafe_unretained NSString *linkURL;
	__unsafe_unretained NSString *refreshedDate;
	__unsafe_unretained NSString *stats;
} DOShareAttributes;

extern const struct DOShareRelationships {
	__unsafe_unretained NSString *enrollment;
	__unsafe_unretained NSString *publication;
} DOShareRelationships;

extern const struct DOShareFetchedProperties {
} DOShareFetchedProperties;

@class DOEnrollment;
@class DOPublication;



@class NSURL;

@class NSDictionary;

@interface DOShareID : NSManagedObjectID {}
@end

@interface _DOShare : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOShareID*)objectID;





@property (nonatomic, strong) NSDate* createdDate;



//- (BOOL)validateCreatedDate:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* externalID;



//- (BOOL)validateExternalID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSURL* linkURL;



//- (BOOL)validateLinkURL:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSDate* refreshedDate;



//- (BOOL)validateRefreshedDate:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSDictionary* stats;



//- (BOOL)validateStats:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOEnrollment *enrollment;

//- (BOOL)validateEnrollment:(id*)value_ error:(NSError**)error_;




@property (nonatomic, strong) DOPublication *publication;

//- (BOOL)validatePublication:(id*)value_ error:(NSError**)error_;





@end

@interface _DOShare (CoreDataGeneratedAccessors)

@end

@interface _DOShare (CoreDataGeneratedPrimitiveAccessors)


- (NSDate*)primitiveCreatedDate;
- (void)setPrimitiveCreatedDate:(NSDate*)value;




- (NSString*)primitiveExternalID;
- (void)setPrimitiveExternalID:(NSString*)value;




- (NSURL*)primitiveLinkURL;
- (void)setPrimitiveLinkURL:(NSURL*)value;




- (NSDate*)primitiveRefreshedDate;
- (void)setPrimitiveRefreshedDate:(NSDate*)value;




- (NSDictionary*)primitiveStats;
- (void)setPrimitiveStats:(NSDictionary*)value;





- (DOEnrollment*)primitiveEnrollment;
- (void)setPrimitiveEnrollment:(DOEnrollment*)value;



- (DOPublication*)primitivePublication;
- (void)setPrimitivePublication:(DOPublication*)value;


@end
