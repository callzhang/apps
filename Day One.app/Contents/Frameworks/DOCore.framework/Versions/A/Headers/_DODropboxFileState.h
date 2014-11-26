// DO NOT EDIT. This file is machine-generated and constantly overwritten.
// Make changes to DODropboxFileState.h instead.

#import <CoreData/CoreData.h>


extern const struct DODropboxFileStateAttributes {
	__unsafe_unretained NSString *localModified;
	__unsafe_unretained NSString *remoteBytes;
	__unsafe_unretained NSString *remoteIsDeleted;
	__unsafe_unretained NSString *remoteModified;
	__unsafe_unretained NSString *remotePath;
	__unsafe_unretained NSString *remoteRev;
} DODropboxFileStateAttributes;

extern const struct DODropboxFileStateRelationships {
} DODropboxFileStateRelationships;

extern const struct DODropboxFileStateFetchedProperties {
} DODropboxFileStateFetchedProperties;









@interface DODropboxFileStateID : NSManagedObjectID {}
@end

@interface _DODropboxFileState : NSManagedObject {}
+ (id)insertInManagedObjectContext:(NSManagedObjectContext*)moc_;
+ (NSString*)entityName;
+ (NSEntityDescription*)entityInManagedObjectContext:(NSManagedObjectContext*)moc_;
- (DODropboxFileStateID*)objectID;





@property (nonatomic, strong) NSDate* localModified;



//- (BOOL)validateLocalModified:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* remoteBytes;



@property int64_t remoteBytesValue;
- (int64_t)remoteBytesValue;
- (void)setRemoteBytesValue:(int64_t)value_;

//- (BOOL)validateRemoteBytes:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSNumber* remoteIsDeleted;



@property BOOL remoteIsDeletedValue;
- (BOOL)remoteIsDeletedValue;
- (void)setRemoteIsDeletedValue:(BOOL)value_;

//- (BOOL)validateRemoteIsDeleted:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSDate* remoteModified;



//- (BOOL)validateRemoteModified:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* remotePath;



//- (BOOL)validateRemotePath:(id*)value_ error:(NSError**)error_;





@property (nonatomic, strong) NSString* remoteRev;



//- (BOOL)validateRemoteRev:(id*)value_ error:(NSError**)error_;






@end

@interface _DODropboxFileState (CoreDataGeneratedAccessors)

@end

@interface _DODropboxFileState (CoreDataGeneratedPrimitiveAccessors)


- (NSDate*)primitiveLocalModified;
- (void)setPrimitiveLocalModified:(NSDate*)value;




- (NSNumber*)primitiveRemoteBytes;
- (void)setPrimitiveRemoteBytes:(NSNumber*)value;

- (int64_t)primitiveRemoteBytesValue;
- (void)setPrimitiveRemoteBytesValue:(int64_t)value_;




- (NSNumber*)primitiveRemoteIsDeleted;
- (void)setPrimitiveRemoteIsDeleted:(NSNumber*)value;

- (BOOL)primitiveRemoteIsDeletedValue;
- (void)setPrimitiveRemoteIsDeletedValue:(BOOL)value_;




- (NSDate*)primitiveRemoteModified;
- (void)setPrimitiveRemoteModified:(NSDate*)value;




- (NSString*)primitiveRemotePath;
- (void)setPrimitiveRemotePath:(NSString*)value;




- (NSString*)primitiveRemoteRev;
- (void)setPrimitiveRemoteRev:(NSString*)value;




@end
