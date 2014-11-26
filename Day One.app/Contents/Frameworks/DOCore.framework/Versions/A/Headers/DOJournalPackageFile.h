//
//  JournalPackage.h
//  DayOne
//
//  Created by Ben Dolman on 3/21/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOSecurityManager.h"
#import "DOJournalEntryFile.h"

extern NSString * const DOJournalPackageFileExtension;

@interface DOJournalPackageFile : NSObject {
    NSURL *packageURL;
    NSURL *entriesFolderURL;
    NSURL *securityURL;
}

+ (NSArray *) findJournalURLsInDirectory:(NSURL *)directoryURL;

+ (BOOL) existsValidJournalPackageAtPath:(NSString *)path;
+ (BOOL) fixJournalPackageAtPath:(NSString *)path error:(NSError **)error;

/**
 * The name of the journal, not including the extension or suffix
 */
+ (NSString *) journalNameFromPackageURL:(NSURL *)url;

/**
 * Given a proposed directory for a package or a package URL itself, returns the full 
 * journal package URL that should be used. This method takes into account the proposed 
 * destination and crafts the URL appropriately depending on whether the URL is in iCloud or not.
 *
 * If url is a file package URL, the name of that package will be used when constructing
 * the final URL. Otherwise, if url is a directory a default package name will be used.
 */
+ (NSURL *) packageURLAppropriateForURL:(NSURL *)url;

/**
 * Given the location of an existing package and a proposed directory for a package or a 
 * package URL itself, returns the full journal package URL of the destination that should 
 * be used when moving the package. This method has similar behavior to pacakgeURLAppropriateForURL:
 * 
 * If toURL is a package URL then that journal name will be used when constructing the
 * final URL. Otherwise, the name of the package at fromURL is used.
 */
+ (NSURL *) packageURLAppropriateForMovingFromPackageURL:(NSURL *)fromURL toURL:(NSURL *)toURL;

//+ (DOJournalPackageFile *) defaultPackage;

- (id) initWithURL:(NSURL *)aPackageURL createPackage:(BOOL)create error:(NSError **)error;

/**
 * The name of the journal, not including the extension or suffix
 */
- (NSString *) journalName;

- (NSURL *) packageURL;
- (NSURL *) entriesFolderURL;
- (NSURL *) securityURL;

/**
 * Scans the entries folder of the journal package and returns all of the entry IDs
 */
- (NSArray *) entryIDs;

- (BOOL) isUbiquitous;

- (DOSecurityManager *) securityManager;

- (BOOL) mergeContentsOfFileVersion:(NSFileVersion *)versionToMergeFrom
                              error:(NSError **)error 
                         errorCount:(NSUInteger *)errorCount;

/**
 * Merges the contents of packageToMergeFrom into this journal package. If either of
 * the packages is the iCloud container you must not call this on the main thread, because
 * calls are made to -[NSFileManager setUbiquitous:itemAtURL:destinationURL:error:].
 * In general it's probably safest to perform this in an asynchronous background queue.
 * If the same file exists in both journals the newer (by file modification date) wins.
 */
- (BOOL) mergeContentsOfOtherPackage:(DOJournalPackageFile *)packageToMergeFrom 
                       progressBlock:(void(^)(NSUInteger completeCnt, NSUInteger totalCnt))progressBlock
                               error:(NSError **)error 
                          errorCount:(NSUInteger *)errorCount;

@end
