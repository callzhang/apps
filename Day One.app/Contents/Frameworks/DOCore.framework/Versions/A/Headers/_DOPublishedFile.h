// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DOPublishedFile.h instead.

#import <CoreData/CoreData.h>


extern const struct DOPublishedFileAttributes {
	__unsafe_unretained NSString *fileID;
	__unsafe_unretained NSString *imageMeta;
} DOPublishedFileAttributes;

extern const struct DOPublishedFileRelationships {
	__unsafe_unretained NSString *publishedEntry;
} DOPublishedFileRelationships;

extern const struct DOPublishedFileFetchedProperties {
} DOPublishedFileFetchedProperties;

@class DOPublishedEntry;


@class NSDictionary;

@interface DOPublishedFileID : NSManagedObjectID {}
@end

@interface _DOPublishedFile : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DOPublishedFileID*)objectID;





@property (nonatomic, strong) NSString* fileID;



//- (BOOL)validateFileID:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSDictionary* imageMeta;



//- (BOOL)validateImageMeta:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) DOPublishedEntry *publishedEntry;

//- (BOOL)validatePublishedEntry:(id*)value_ error:(NSError**)error_;





@end

@interface _DOPublishedFile (CoreDataGeneratedAccessors)

@end

@interface _DOPublishedFile (CoreDataGeneratedPrimitiveAccessors)


- (NSString*)primitiveFileID;
- (void)setPrimitiveFileID:(NSString*)value;




- (NSDictionary*)primitiveImageMeta;
- (void)setPrimitiveImageMeta:(NSDictionary*)value;





- (DOPublishedEntry*)primitivePublishedEntry;
- (void)setPrimitivePublishedEntry:(DOPublishedEntry*)value;


@end
