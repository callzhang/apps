//
//  JournalIndex.h
//  DayOne
//
//  Created by Ben Dolman on 3/21/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOEntry.h"
#import "DOJournalPackageFile.h"
#import "DOIndexedEntryFile.h"
#import "DOImageCache.h"
#import "DOFileChangeNotifier.h"
#import "DOSearchIndex.h"
#import "DOTag.h"
#import <MapKit/MapKit.h>

typedef void (^DOFetchRequestCompletionBlock)(NSArray *results, NSError *error);
typedef void (^DOBooleanRequestCompletionBlock)(BOOL result, NSError *error);
typedef void (^DOValueRequestCompletionBlock)(NSUInteger result, NSError *error);
typedef void (^DOTwoValuesResultCompletionBlock)(NSUInteger result1, NSUInteger result2, NSError *error);
typedef void(^DOProgressBlock)(float progress, BOOL finished, NSError *fatalError);
typedef void(^DOHashtagProgressBlock)(float progress, BOOL finished, NSString *lastConvertedTag,
                                        NSUInteger tagsConverted, NSError *fatalError);

@interface DOJournalIndex : NSObject <DOImageCacheDelegate> {
    NSManagedObjectContext *managedObjectContext;
    NSManagedObjectContext *refreshContext;
    DOJournalPackageFile *journalFile;
    NSOperationQueue *presenterQueue;
    DOImageCache *imageCache;
    NSPredicate *fileMatchingPredicate;
    DOSearchIndexQueue *searchIndexQueue;
    
    NSConditionLock *dataLock;
    NSThread *refreshThread;
    NSMutableOrderedSet *highPriorityQueue;
    NSMutableOrderedSet *lowPriorityQueue;
    
    id<DOFileChangeNotifier> changeNotifier;
}

@property (strong, readonly) DOImageCache *imageCache;
@property (strong, readonly) DOJournalPackageFile *journalFile;
@property (readonly) NSManagedObjectContext *managedObjectContext;
@property (strong, readonly) DOSearchIndexQueue *searchIndexQueue;

@property (readonly) BOOL indexingInProgress;

/**
 * Configures a persistent store for a journal index at the specified URL.
 * If the store exists it will be validated and migrated as neccessary.
 * If the store does not exist it will be created
 */
+ (NSPersistentStoreCoordinator *)prepareStoreAtURL:(NSURL *)URL bundleContainingModel:(NSBundle *)bundle error:(NSError **)error;

/**
 * Initializes the index by creating a managed object context (available as a property after init) 
 * associated with the main thread. Any managed objects sent to or returned from this object must be 
 * associated with that context.
 */
- (id)initWithPersistentStoreCoordinator:(NSPersistentStoreCoordinator *)coord 
                             journalFile:(DOJournalPackageFile *)file 
                              imageCache:(DOImageCache *)cache
                        searchIndexQueue:(DOSearchIndexQueue *)queue;

- (DOEntry *) createEntryAndReturnFile:(DOIndexedEntryFile **)entryFile error:(NSError **)error;

- (BOOL) deleteEntryFile:(DOJournalEntryFile *)entryFile error:(NSError **)error;
- (BOOL) deleteEntry:(DOEntry *)entry error:(NSError **)error;

- (BOOL) deleteEntryFile:(DOJournalEntryFile *)entryFile error:(NSError **)error deleteFileBlock:(DOFileDeleteBlock)deleteBlock;
- (BOOL) deleteEntry:(DOEntry *)entry error:(NSError **)error deleteFileBlock:(DOFileDeleteBlock)deleteBlock;

- (BOOL) saveEntryFile:(DOJournalEntryFile *)entryFile error:(NSError **)error;

- (DOIndexedEntryFile *) fileForEntry:(DOEntry *)entry error:(NSError **)error;
- (DOIndexedEntryFile *) fileForUuid:(NSString *)uuid error:(NSError **)error;

- (DOEntry *) entryForFile:(DOJournalEntryFile *)file;

- (DOEntry *) entryWithUuid:(NSString *)uuid;

- (DOTag *)tagWithName:(NSString *)tagName;
- (DOTag *)canonicalTagWithName:(NSString *)tagName;
- (NSArray *)tagsBeginningWithString:(NSString *)text;
- (NSArray *)tagsWithEntriesSortedByFrequency:(BOOL)sortByFrequency;
- (NSUInteger)allTagsCount;

- (void)fetchEntriesStarting:(NSDate *)startDate
                        till:(NSDate *)endDate
             matchingAnyTags:(NSArray *)tags
                 onlyStarred:(BOOL)onlyStarred
               onlyPublished:(BOOL)onlyPublished
                   ascending:(BOOL)ascending
             completionBlock:(DOFetchRequestCompletionBlock)completionBlock;

- (void)fetchEntriesStarting:(NSDate *)startDate
                        till:(NSDate *)endDate
             matchingAllTags:(NSArray *)tags
                 onlyStarred:(BOOL)onlyStarred
               onlyPublished:(BOOL)onlyPublished
                   ascending:(BOOL)ascending
             completionBlock:(DOFetchRequestCompletionBlock)completionBlock;


- (NSPredicate *)predicateWithStartDate:(NSDate *)startDate
                                endDate:(NSDate *)endDate
                            onlyStarred:(BOOL)onlyStarred
                          onlyPublished:(BOOL)onlyPublished
                      matchingAnyTagIds:(NSArray *)tagIds;

- (NSPredicate *)predicateWithStartDate:(NSDate *)startDate
                                endDate:(NSDate *)endDate
                            onlyStarred:(BOOL)onlyStarred
                          onlyPublished:(BOOL)onlyPublished
                      matchingAllTagIds:(NSArray *)tagIds;

/**
 * Returns the number of entries within the given date range, matching *any* provided tags.
 * (The 'any' tag matching behavior is relied upon by the PDF exporter).
 */
- (void)calculateNumberOfEntriesStarting:(NSDate *)startDate
                                    till:(NSDate *)endDate
                         matchingAnyTags:(NSArray *)tags
                         completionBlock:(DOValueRequestCompletionBlock)completionBlock;

/**
 * Returns the number of entries and photos within the given date range, matching *any* provided tags.
 */
- (void)calculateNumberOfEntriesAndNumberOfPhotosStarting:(NSDate *)startDate
                                                     till:(NSDate *)endDate
                                          matchingAnyTags:(NSArray *)tags
                                              onlyStarred:(BOOL)onlyStarred
                                            onlyPublished:(BOOL)onlyPublished
                                          completionBlock:(DOTwoValuesResultCompletionBlock)completionBlock;

/**
 * Returns whether there are published entries in the journal
 */
- (void)calculateHasPublishedEntries:(DOBooleanRequestCompletionBlock)completionBlock;

/**
 * Returns an array of NSDate objects for the beginning of each year that contains entries
 */
- (void)fetchYearsWithEntries:(DOFetchRequestCompletionBlock)completionBlock;

/**
 * Fetches entries contained within the coordinate region.
 *
 * Note: the completion block will be invoked on a private queue.
 */
- (void)fetchEntriesInCoordinateRegion:(MKCoordinateRegion)region
                       completionBlock:(DOFetchRequestCompletionBlock)completionBlock;

/**
 * Returns a MKCoordinateRegion containing all entries with location
 */
- (MKCoordinateRegion)boundingRegionForEntries;

/**
 * Returns the location of the most recent entry
 */
- (DOLocation *)locationOfMostRecentEntry;

/**
 * Returns a fetch request targeting entries in the given region, ordered newest first
 */
- (NSFetchRequest *)fetchRequestForEntriesInCoordinateRegion:(MKCoordinateRegion)region;

/**
 * Scans text for hashtags. Found hashtags are converted to the canonical case.
 * Found tags that are also in the ignoredTagNames set are not included in the final result.
 * NOTE: Ignore list comparison is case-insensitive.
 *
 * Returns a set of tag names (NSString objects)
 */
-(NSSet *)convertHashtagsInText:(NSString *)text ignoringTagNames:(NSSet *)ignoredTagNames;

/**
 * Refreshes the index to match the state of the journal file contents.
 * If forceUpdate is NO then entries in the index are only updated if the file
 * on disk has changed since the last update. If YES then all entries are updated
 * from disk regardless of when they were last updated.
 */
-(void)performFullRefreshAndForceUpdate:(BOOL)forceUpdate;

/**
 * Drops the data from the current search index and repopulates it asynchronously
 * with each entry in the journal index. Does nothing if a search index is not
 * currently configured on the journal
 */
-(void)rebuildSearchIndexWithProgressBlock:(DOProgressBlock)progressBlock;

/**
 * Goes through all entries and converts hashtags found in the
 * entry text to real tags.
 */
-(void)convertAllEntriesHashtagsWithProgressBlock:(DOHashtagProgressBlock)progressBlock;

/**
 * Stops the indexing thread in preparation for the object being released.
 */
- (void) closeIndex;

@end
