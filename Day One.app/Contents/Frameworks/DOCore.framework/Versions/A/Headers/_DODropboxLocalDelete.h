// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DODropboxLocalDelete.h instead.

#import <CoreData/CoreData.h>


extern const struct DODropboxLocalDeleteAttributes {
	__unsafe_unretained NSString *localDeleted;
	__unsafe_unretained NSString *localPath;
} DODropboxLocalDeleteAttributes;

extern const struct DODropboxLocalDeleteRelationships {
} DODropboxLocalDeleteRelationships;

extern const struct DODropboxLocalDeleteFetchedProperties {
} DODropboxLocalDeleteFetchedProperties;





@interface DODropboxLocalDeleteID : NSManagedObjectID {}
@end

@interface _DODropboxLocalDelete : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DODropboxLocalDeleteID*)objectID;





@property (nonatomic, strong) NSDate* localDeleted;



//- (BOOL)validateLocalDeleted:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* localPath;



//- (BOOL)validateLocalPath:(id*)value_ error:(NSError**)error_;






@end

@interface _DODropboxLocalDelete (CoreDataGeneratedAccessors)

@end

@interface _DODropboxLocalDelete (CoreDataGeneratedPrimitiveAccessors)


- (NSDate*)primitiveLocalDeleted;
- (void)setPrimitiveLocalDeleted:(NSDate*)value;




- (NSString*)primitiveLocalPath;
- (void)setPrimitiveLocalPath:(NSString*)value;




@end
