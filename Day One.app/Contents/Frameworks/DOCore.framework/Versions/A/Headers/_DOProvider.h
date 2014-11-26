// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOProvider.h instead.

#import <CoreData/CoreData.h>


extern const struct DOProviderAttributes {
	__unsafe_unretained NSString *enrollmentKinds;
	__unsafe_unretained NSString *externalID;
	__unsafe_unretained NSString *imageURLs;
	__unsafe_unretained NSString *isEnabled;
	__unsafe_unretained NSString *providerDescription;
	__unsafe_unretained NSString *providerID;
	__unsafe_unretained NSString *providerName;
	__unsafe_unretained NSString *sort;
} DOProviderAttributes;

extern const struct DOProviderRelationships {
	__unsafe_unretained NSString *enrollments;
} DOProviderRelationships;

extern const struct DOProviderFetchedProperties {
} DOProviderFetchedProperties;

@class DOEnrollment;

@class NSArray;

@class NSDictionary;






@interface DOProviderID : NSManagedObjectID {}
@end

@interface _DOProvider : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOProviderID*)objectID;





@property (nonatomic, strong) NSArray* enrollmentKinds;



//- (BOOL)validateEnrollmentKinds:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* externalID;



//- (BOOL)validateExternalID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSDictionary* imageURLs;



//- (BOOL)validateImageURLs:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* isEnabled;



@property BOOL isEnabledValue;
- (BOOL)isEnabledValue;
- (void)setIsEnabledValue:(BOOL)value_;

//- (BOOL)validateIsEnabled:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* providerDescription;



//- (BOOL)validateProviderDescription:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* providerID;



//- (BOOL)validateProviderID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* providerName;



//- (BOOL)validateProviderName:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* sort;



@property int16_t sortValue;
- (int16_t)sortValue;
- (void)setSortValue:(int16_t)value_;

//- (BOOL)validateSort:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSSet *enrollments;

- (NSMutableSet*)enrollmentsSet;





@end

@interface _DOProvider (CoreDataGeneratedAccessors)

- (void)addEnrollments:(NSSet*)value_;
- (void)removeEnrollments:(NSSet*)value_;
- (void)addEnrollmentsObject:(DOEnrollment*)value_;
- (void)removeEnrollmentsObject:(DOEnrollment*)value_;

@end

@interface _DOProvider (CoreDataGeneratedPrimitiveAccessors)


- (NSArray*)primitiveEnrollmentKinds;
- (void)setPrimitiveEnrollmentKinds:(NSArray*)value;




- (NSString*)primitiveExternalID;
- (void)setPrimitiveExternalID:(NSString*)value;




- (NSDictionary*)primitiveImageURLs;
- (void)setPrimitiveImageURLs:(NSDictionary*)value;




- (NSNumber*)primitiveIsEnabled;
- (void)setPrimitiveIsEnabled:(NSNumber*)value;

- (BOOL)primitiveIsEnabledValue;
- (void)setPrimitiveIsEnabledValue:(BOOL)value_;




- (NSString*)primitiveProviderDescription;
- (void)setPrimitiveProviderDescription:(NSString*)value;




- (NSString*)primitiveProviderID;
- (void)setPrimitiveProviderID:(NSString*)value;




- (NSString*)primitiveProviderName;
- (void)setPrimitiveProviderName:(NSString*)value;




- (NSNumber*)primitiveSort;
- (void)setPrimitiveSort:(NSNumber*)value;

- (int16_t)primitiveSortValue;
- (void)setPrimitiveSortValue:(int16_t)value_;





- (NSMutableSet*)primitiveEnrollments;
- (void)setPrimitiveEnrollments:(NSMutableSet*)value;


@end
