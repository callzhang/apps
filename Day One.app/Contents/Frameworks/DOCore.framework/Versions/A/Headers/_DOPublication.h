// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOPublication.h instead.

#import <CoreData/CoreData.h>


extern const struct DOPublicationAttributes {
	__unsafe_unretained NSString *publishedURL;
	__unsafe_unretained NSString *visits;
} DOPublicationAttributes;

extern const struct DOPublicationRelationships {
	__unsafe_unretained NSString *publishedEntry;
	__unsafe_unretained NSString *shares;
	__unsafe_unretained NSString *zonedDate;
} DOPublicationRelationships;

extern const struct DOPublicationFetchedProperties {
} DOPublicationFetchedProperties;

@class DOPublishedEntry;
@class DOShare;
@class DOZonedDate;

@class NSURL;


@interface DOPublicationID : NSManagedObjectID {}
@end

@interface _DOPublication : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOPublicationID*)objectID;





@property (nonatomic, strong) NSURL* publishedURL;



//- (BOOL)validatePublishedURL:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* visits;



@property int64_t visitsValue;
- (int64_t)visitsValue;
- (void)setVisitsValue:(int64_t)value_;

//- (BOOL)validateVisits:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOPublishedEntry *publishedEntry;

//- (BOOL)validatePublishedEntry:(id*)value_ error:(NSError**)error_;




@property (nonatomic, strong) NSOrderedSet *shares;

- (NSMutableOrderedSet*)sharesSet;




@property (nonatomic, strong) DOZonedDate *zonedDate;

//- (BOOL)validateZonedDate:(id*)value_ error:(NSError**)error_;





@end

@interface _DOPublication (CoreDataGeneratedAccessors)

- (void)addShares:(NSOrderedSet*)value_;
- (void)removeShares:(NSOrderedSet*)value_;
- (void)addSharesObject:(DOShare*)value_;
- (void)removeSharesObject:(DOShare*)value_;

@end

@interface _DOPublication (CoreDataGeneratedPrimitiveAccessors)


- (NSURL*)primitivePublishedURL;
- (void)setPrimitivePublishedURL:(NSURL*)value;




- (NSNumber*)primitiveVisits;
- (void)setPrimitiveVisits:(NSNumber*)value;

- (int64_t)primitiveVisitsValue;
- (void)setPrimitiveVisitsValue:(int64_t)value_;





- (DOPublishedEntry*)primitivePublishedEntry;
- (void)setPrimitivePublishedEntry:(DOPublishedEntry*)value;



- (NSMutableOrderedSet*)primitiveShares;
- (void)setPrimitiveShares:(NSMutableOrderedSet*)value;



- (DOZonedDate*)primitiveZonedDate;
- (void)setPrimitiveZonedDate:(DOZonedDate*)value;


@end
