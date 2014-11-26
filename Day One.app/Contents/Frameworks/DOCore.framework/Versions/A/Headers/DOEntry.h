#import "_DOEntry.h"

@interface DOEntry : _DOEntry {}

@property (nonatomic, readonly) BOOL hasPhoto;

- (NSString *)collapsedEntryText;
- (NSArray *)orderedTags;

+ (DOEntry *)entryForUUID:(NSString *)uuid inContext:(NSManagedObjectContext *)context;

/**
 * Queries for matching published entries whose legacyID matches this entry's uuid. If one is found
 * the relationship is updated.
 *
 * Returns YES if the entry needed to be updated.
 */
- (BOOL)refreshPublishedEntryRelation;

@end
