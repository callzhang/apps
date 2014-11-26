//
//  DOSearchOperation.h
//  DOCore
//
//  Created by Ben Dolman on 9/26/12.
//
//

#import <Foundation/Foundation.h>
#import "DOSearchIndex.h"
#import "DOJournalIndex.h"

@protocol DOSearchOperationDelegate;

@interface DOSearchOperation : NSOperation

@property (strong) id<DOSearchOperationDelegate> delegate;
@property (copy) NSPredicate *filterPredicate;
@property (copy) NSArray *resultSortDescriptors;
@property (copy) NSString *sectionNameKeyPath;

@property (readonly, copy) NSString *searchText;
@property (readonly, strong) DOSearchIndex *searchIndex;
@property (readonly, strong) DOJournalIndex *journalIndex;

@property (readonly, copy) NSArray *sections;
@property (readonly, copy) NSArray *fetchedObjectIDs;

- (id) initWithSearchText:(NSString *)searchText
              searchIndex:(DOSearchIndex *)searchIndex
             journalIndex:(DOJournalIndex *)journalIndex;

- (NSManagedObjectID *)objectIDAtIndexPath:(NSIndexPath *)indexPath;
- (NSIndexPath *)indexPathForObjectID:(NSManagedObjectID *)objectID;

@end

@protocol DOSearchOperationDelegate <NSObject>

- (void) searchOperationDidComplete:(DOSearchOperation *)searchOperation;

@end

@interface DOSearchResultsSectionInfo : NSObject

-(id)initWithName:(NSString *)name objects:(NSArray *)objects;

@property (readonly) NSString *name;
@property (readonly) NSUInteger numberOfObjects;
@property (readonly) NSArray *objects;

@end
