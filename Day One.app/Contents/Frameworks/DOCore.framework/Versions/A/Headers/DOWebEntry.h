//
//  DOWebEntry.h
//  DOCore
//
//  Created by Ben Dolman on 5/14/13.
//
//

#import "DOWebObject.h"
#import "DOWebWeather.h"
#import "DOWebLocation.h"
#import "DOJournalEntryFile.h"
#import "DOWebPublication.h"
#import "DOWebDate.h"
#import "DOWebEditRecord.h"

@interface DOWebEntry : DOWebObject <MTLManagedObjectSerializing>

@property (nonatomic, copy) NSString *publishID;
@property (nonatomic, copy) NSNumber *ownerID;
@property (nonatomic, copy) NSString *legacyID;
@property (nonatomic, copy) NSString *clientChecksum;

@property (nonatomic, strong) DOWebDate *date;

@property (nonatomic, strong) DOWebEditRecord *creation;
@property (nonatomic, strong) DOWebEditRecord *edit;

@property (nonatomic, copy) NSString *body;
@property (nonatomic, assign, getter = isStarred) BOOL starred;
@property (nonatomic, copy) NSArray *tags;
@property (nonatomic, assign, getter = isDeleted) BOOL deleted;

// Array of DOWebFile objects
@property (nonatomic, copy) NSArray *files;

@property (nonatomic, strong) DOWebLocation *location;
@property (nonatomic, strong) DOWebWeather *weather;
@property (nonatomic, strong) DOWebPublication *publication;

/**
 * Initializes the object with the contents of the entry file.
 * Returns nil if entryFile is nil.
 */
- (id)initWithEntryFile:(DOJournalEntryFile *)entryFile;

/**
 * Overwrites relevant fields with the values in the entry file
 */
- (void)updateWithEntryFile:(DOJournalEntryFile *)entryFile;

@end