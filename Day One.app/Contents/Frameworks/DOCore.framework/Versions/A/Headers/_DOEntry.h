// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOEntry.h instead.

#import <CoreData/CoreData.h>


extern const struct DOEntryAttributes {
	__unsafe_unretained NSString *activity;
	__unsafe_unretained NSString *creationDate;
	__unsafe_unretained NSString *creationYear;
	__unsafe_unretained NSString *entryText;
	__unsafe_unretained NSString *ignoreStepCount;
	__unsafe_unretained NSString *isEntryDeleted;
	__unsafe_unretained NSString *latitude;
	__unsafe_unretained NSString *location;
	__unsafe_unretained NSString *longitude;
	__unsafe_unretained NSString *modified;
	__unsafe_unretained NSString *monthSection;
	__unsafe_unretained NSString *music;
	__unsafe_unretained NSString *photoModified;
	__unsafe_unretained NSString *publishURL;
	__unsafe_unretained NSString *starred;
	__unsafe_unretained NSString *stepCount;
	__unsafe_unretained NSString *uuid;
	__unsafe_unretained NSString *weather;
} DOEntryAttributes;

extern const struct DOEntryRelationships {
	__unsafe_unretained NSString *publishedEntry;
	__unsafe_unretained NSString *tags;
} DOEntryRelationships;

extern const struct DOEntryFetchedProperties {
} DOEntryFetchedProperties;

@class DOPublishedEntry;
@class DOTag;








@class DOLocation;



@class DOMusic;

@class NSURL;



@class DOWeather;

@interface DOEntryID : NSManagedObjectID {}
@end

@interface _DOEntry : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOEntryID*)objectID;





@property (nonatomic, strong) NSString* activity;



//- (BOOL)validateActivity:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSDate* creationDate;



//- (BOOL)validateCreationDate:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* creationYear;



@property int16_t creationYearValue;
- (int16_t)creationYearValue;
- (void)setCreationYearValue:(int16_t)value_;

//- (BOOL)validateCreationYear:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* entryText;



//- (BOOL)validateEntryText:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* ignoreStepCount;



@property BOOL ignoreStepCountValue;
- (BOOL)ignoreStepCountValue;
- (void)setIgnoreStepCountValue:(BOOL)value_;

//- (BOOL)validateIgnoreStepCount:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* isEntryDeleted;



@property BOOL isEntryDeletedValue;
- (BOOL)isEntryDeletedValue;
- (void)setIsEntryDeletedValue:(BOOL)value_;

//- (BOOL)validateIsEntryDeleted:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* latitude;



@property double latitudeValue;
- (double)latitudeValue;
- (void)setLatitudeValue:(double)value_;

//- (BOOL)validateLatitude:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOLocation* location;



//- (BOOL)validateLocation:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* longitude;



@property double longitudeValue;
- (double)longitudeValue;
- (void)setLongitudeValue:(double)value_;

//- (BOOL)validateLongitude:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSDate* modified;



//- (BOOL)validateModified:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* monthSection;



//- (BOOL)validateMonthSection:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOMusic* music;



//- (BOOL)validateMusic:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSDate* photoModified;



//- (BOOL)validatePhotoModified:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSURL* publishURL;



//- (BOOL)validatePublishURL:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* starred;



@property BOOL starredValue;
- (BOOL)starredValue;
- (void)setStarredValue:(BOOL)value_;

//- (BOOL)validateStarred:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* stepCount;



@property int64_t stepCountValue;
- (int64_t)stepCountValue;
- (void)setStepCountValue:(int64_t)value_;

//- (BOOL)validateStepCount:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* uuid;



//- (BOOL)validateUuid:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOWeather* weather;



//- (BOOL)validateWeather:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOPublishedEntry *publishedEntry;

//- (BOOL)validatePublishedEntry:(id*)value_ error:(NSError**)error_;




@property (nonatomic, strong) NSSet *tags;

- (NSMutableSet*)tagsSet;





@end

@interface _DOEntry (CoreDataGeneratedAccessors)

- (void)addTags:(NSSet*)value_;
- (void)removeTags:(NSSet*)value_;
- (void)addTagsObject:(DOTag*)value_;
- (void)removeTagsObject:(DOTag*)value_;

@end

@interface _DOEntry (CoreDataGeneratedPrimitiveAccessors)


- (NSString*)primitiveActivity;
- (void)setPrimitiveActivity:(NSString*)value;




- (NSDate*)primitiveCreationDate;
- (void)setPrimitiveCreationDate:(NSDate*)value;




- (NSNumber*)primitiveCreationYear;
- (void)setPrimitiveCreationYear:(NSNumber*)value;

- (int16_t)primitiveCreationYearValue;
- (void)setPrimitiveCreationYearValue:(int16_t)value_;




- (NSString*)primitiveEntryText;
- (void)setPrimitiveEntryText:(NSString*)value;




- (NSNumber*)primitiveIgnoreStepCount;
- (void)setPrimitiveIgnoreStepCount:(NSNumber*)value;

- (BOOL)primitiveIgnoreStepCountValue;
- (void)setPrimitiveIgnoreStepCountValue:(BOOL)value_;




- (NSNumber*)primitiveIsEntryDeleted;
- (void)setPrimitiveIsEntryDeleted:(NSNumber*)value;

- (BOOL)primitiveIsEntryDeletedValue;
- (void)setPrimitiveIsEntryDeletedValue:(BOOL)value_;




- (NSNumber*)primitiveLatitude;
- (void)setPrimitiveLatitude:(NSNumber*)value;

- (double)primitiveLatitudeValue;
- (void)setPrimitiveLatitudeValue:(double)value_;




- (DOLocation*)primitiveLocation;
- (void)setPrimitiveLocation:(DOLocation*)value;




- (NSNumber*)primitiveLongitude;
- (void)setPrimitiveLongitude:(NSNumber*)value;

- (double)primitiveLongitudeValue;
- (void)setPrimitiveLongitudeValue:(double)value_;




- (NSDate*)primitiveModified;
- (void)setPrimitiveModified:(NSDate*)value;




- (NSString*)primitiveMonthSection;
- (void)setPrimitiveMonthSection:(NSString*)value;




- (DOMusic*)primitiveMusic;
- (void)setPrimitiveMusic:(DOMusic*)value;




- (NSDate*)primitivePhotoModified;
- (void)setPrimitivePhotoModified:(NSDate*)value;




- (NSURL*)primitivePublishURL;
- (void)setPrimitivePublishURL:(NSURL*)value;




- (NSNumber*)primitiveStarred;
- (void)setPrimitiveStarred:(NSNumber*)value;

- (BOOL)primitiveStarredValue;
- (void)setPrimitiveStarredValue:(BOOL)value_;




- (NSNumber*)primitiveStepCount;
- (void)setPrimitiveStepCount:(NSNumber*)value;

- (int64_t)primitiveStepCountValue;
- (void)setPrimitiveStepCountValue:(int64_t)value_;




- (NSString*)primitiveUuid;
- (void)setPrimitiveUuid:(NSString*)value;




- (DOWeather*)primitiveWeather;
- (void)setPrimitiveWeather:(DOWeather*)value;





- (DOPublishedEntry*)primitivePublishedEntry;
- (void)setPrimitivePublishedEntry:(DOPublishedEntry*)value;



- (NSMutableSet*)primitiveTags;
- (void)setPrimitiveTags:(NSMutableSet*)value;


@end
