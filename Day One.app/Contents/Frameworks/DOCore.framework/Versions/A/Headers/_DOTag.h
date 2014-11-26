// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOTag.h instead.

#import <CoreData/CoreData.h>


extern const struct DOTagAttributes {
	__unsafe_unretained NSString *isCanonical;
	__unsafe_unretained NSString *name;
	__unsafe_unretained NSString *normalizedEntryCount;
	__unsafe_unretained NSString *normalizedName;
} DOTagAttributes;

extern const struct DOTagRelationships {
	__unsafe_unretained NSString *entries;
} DOTagRelationships;

extern const struct DOTagFetchedProperties {
} DOTagFetchedProperties;

@class DOEntry;






@interface DOTagID : NSManagedObjectID {}
@end

@interface _DOTag : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOTagID*)objectID;





@property (nonatomic, strong) NSNumber* isCanonical;



@property BOOL isCanonicalValue;
- (BOOL)isCanonicalValue;
- (void)setIsCanonicalValue:(BOOL)value_;

//- (BOOL)validateIsCanonical:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* name;



//- (BOOL)validateName:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* normalizedEntryCount;



@property int64_t normalizedEntryCountValue;
- (int64_t)normalizedEntryCountValue;
- (void)setNormalizedEntryCountValue:(int64_t)value_;

//- (BOOL)validateNormalizedEntryCount:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* normalizedName;



//- (BOOL)validateNormalizedName:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSSet *entries;

- (NSMutableSet*)entriesSet;





@end

@interface _DOTag (CoreDataGeneratedAccessors)

- (void)addEntries:(NSSet*)value_;
- (void)removeEntries:(NSSet*)value_;
- (void)addEntriesObject:(DOEntry*)value_;
- (void)removeEntriesObject:(DOEntry*)value_;

@end

@interface _DOTag (CoreDataGeneratedPrimitiveAccessors)


- (NSNumber*)primitiveIsCanonical;
- (void)setPrimitiveIsCanonical:(NSNumber*)value;

- (BOOL)primitiveIsCanonicalValue;
- (void)setPrimitiveIsCanonicalValue:(BOOL)value_;




- (NSString*)primitiveName;
- (void)setPrimitiveName:(NSString*)value;




- (NSNumber*)primitiveNormalizedEntryCount;
- (void)setPrimitiveNormalizedEntryCount:(NSNumber*)value;

- (int64_t)primitiveNormalizedEntryCountValue;
- (void)setPrimitiveNormalizedEntryCountValue:(int64_t)value_;




- (NSString*)primitiveNormalizedName;
- (void)setPrimitiveNormalizedName:(NSString*)value;





- (NSMutableSet*)primitiveEntries;
- (void)setPrimitiveEntries:(NSMutableSet*)value;


@end
