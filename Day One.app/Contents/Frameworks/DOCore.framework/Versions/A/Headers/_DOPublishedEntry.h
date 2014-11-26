// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOPublishedEntry.h instead.

#import <CoreData/CoreData.h>


extern const struct DOPublishedEntryAttributes {
	__unsafe_unretained NSString *clientChecksum;
	__unsafe_unretained NSString *legacyID;
	__unsafe_unretained NSString *publishID;
} DOPublishedEntryAttributes;

extern const struct DOPublishedEntryRelationships {
	__unsafe_unretained NSString *entry;
	__unsafe_unretained NSString *files;
	__unsafe_unretained NSString *publication;
} DOPublishedEntryRelationships;

extern const struct DOPublishedEntryFetchedProperties {
} DOPublishedEntryFetchedProperties;

@class DOEntry;
@class DOPublishedFile;
@class DOPublication;





@interface DOPublishedEntryID : NSManagedObjectID {}
@end

@interface _DOPublishedEntry : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOPublishedEntryID*)objectID;





@property (nonatomic, strong) NSString* clientChecksum;



//- (BOOL)validateClientChecksum:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* legacyID;



//- (BOOL)validateLegacyID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* publishID;



//- (BOOL)validatePublishID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOEntry *entry;

//- (BOOL)validateEntry:(id*)value_ error:(NSError**)error_;




@property (nonatomic, strong) NSOrderedSet *files;

- (NSMutableOrderedSet*)filesSet;




@property (nonatomic, strong) DOPublication *publication;

//- (BOOL)validatePublication:(id*)value_ error:(NSError**)error_;





@end

@interface _DOPublishedEntry (CoreDataGeneratedAccessors)

- (void)addFiles:(NSOrderedSet*)value_;
- (void)removeFiles:(NSOrderedSet*)value_;
- (void)addFilesObject:(DOPublishedFile*)value_;
- (void)removeFilesObject:(DOPublishedFile*)value_;

@end

@interface _DOPublishedEntry (CoreDataGeneratedPrimitiveAccessors)


- (NSString*)primitiveClientChecksum;
- (void)setPrimitiveClientChecksum:(NSString*)value;




- (NSString*)primitiveLegacyID;
- (void)setPrimitiveLegacyID:(NSString*)value;




- (NSString*)primitivePublishID;
- (void)setPrimitivePublishID:(NSString*)value;





- (DOEntry*)primitiveEntry;
- (void)setPrimitiveEntry:(DOEntry*)value;



- (NSMutableOrderedSet*)primitiveFiles;
- (void)setPrimitiveFiles:(NSMutableOrderedSet*)value;



- (DOPublication*)primitivePublication;
- (void)setPrimitivePublication:(DOPublication*)value;


@end
