//
//  DOIndexedEntryFile.h
//  DayOne
//
//  Created by Ben Dolman on 4/7/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import "DOJournalEntryFile.h"
#import "DOEntry.h"

@class DOJournalIndex;

@interface DOIndexedEntryFile : DOJournalEntryFile {
    DOJournalIndex *journalIndex;
}

@property (strong) DOJournalIndex *journalIndex;

- (id) initWithJournalIndex:(DOJournalIndex *)index;
- (BOOL) saveAndReturnError:(NSError **)error;

@end
