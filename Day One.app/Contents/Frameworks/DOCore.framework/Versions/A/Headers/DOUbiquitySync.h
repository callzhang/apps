//
//  DOUbiquitySync.h
//  DayOne
//
//  Created by Ben Dolman on 4/5/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOSync.h"
#import "DOJournalPackageFile.h"

/**
 * iCloud synchronizer. Use this to make sure that files in the specified journal
 * file are downloaded from iCloud. This class observes metadata for files in the specified
 * journal file and starts downloads for files that have NSMetadataUbiquitousItemIsDownloadedKey.
 */
@interface DOUbiquitySync : DOSync

/**
 * Starts watching the files in the specified journal file. When a new remote file appears
 * in the metadata this class automatically requests that it download.
 * Make sure to call -stopSync before releasing this object.
 */
-(id) initWithJournalFile:(DOJournalPackageFile *)file;

@end
