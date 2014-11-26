//
//  DOError.h
//  DayOne
//
//  Created by Ben Dolman on 3/21/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const DOErrorDomain;

enum {
	DOUndefinedError                   = 0,
	DODefaultLocationNotSetError       = 1,
	DOEntryFileMalformedError          = 2,
	DOJournalPackageInvalidError       = 3,
    DOJournalPackageNotFoundError      = 4,
    DOSecurityFileConflictError        = 5,
    DOInvalidJournalEntryFileFormat    = 6,
    DOInvalidAttributesError           = 7,  // Entity was saved with invalid attributes
    DOEntryFileNotDownloadedError      = 8,  // iCloud only. File hasn't downloaded yet. Not safe to read.
    DOWeatherUnavailableError          = 9,
    DOMusiciTunesSearchNotFoundError   = 10
};