// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOZonedDate.h instead.

#import <CoreData/CoreData.h>


extern const struct DOZonedDateAttributes {
	__unsafe_unretained NSString *date;
	__unsafe_unretained NSString *timeZone;
} DOZonedDateAttributes;

extern const struct DOZonedDateRelationships {
	__unsafe_unretained NSString *publicationZonedDate;
} DOZonedDateRelationships;

extern const struct DOZonedDateFetchedProperties {
} DOZonedDateFetchedProperties;

@class DOPublication;


@class NSTimeZone;

@interface DOZonedDateID : NSManagedObjectID {}
@end

@interface _DOZonedDate : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOZonedDateID*)objectID;





@property (nonatomic, strong) NSDate* date;



//- (BOOL)validateDate:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSTimeZone* timeZone;



//- (BOOL)validateTimeZone:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOPublication *publicationZonedDate;

//- (BOOL)validatePublicationZonedDate:(id*)value_ error:(NSError**)error_;





@end

@interface _DOZonedDate (CoreDataGeneratedAccessors)

@end

@interface _DOZonedDate (CoreDataGeneratedPrimitiveAccessors)


- (NSDate*)primitiveDate;
- (void)setPrimitiveDate:(NSDate*)value;




- (NSTimeZone*)primitiveTimeZone;
- (void)setPrimitiveTimeZone:(NSTimeZone*)value;





- (DOPublication*)primitivePublicationZonedDate;
- (void)setPrimitivePublicationZonedDate:(DOPublication*)value;


@end
