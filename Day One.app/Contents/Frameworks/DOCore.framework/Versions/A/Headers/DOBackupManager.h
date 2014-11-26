//
//  DOBackupManager.h
//  DOCore
//
//  Created by Ben Dolman on 2/24/14.
//
//

#import <Foundation/Foundation.h>

extern NSString * const DOBackupErrorDomain;

typedef NS_ENUM(NSInteger, DOBackupErrorCode)
{
    DOBackupErrorSandboxLostAccess = 1, // OS X Only
};

@class DOBackup;

/**
 * Creates and manages a directory containing backup folders. After adding backups a
 * backup directory looks like this:
 *
 * /2013-12-13_978307200/backupfile1
 *                      /backupfile2
 * /2013-12-14_978323256/backupfile1
 *                      /backupfile2
 * ...
 *
 * The backup manager also optionally enforces a backup cap (maxBackupsToKeep) by 
 * automatically deleting older backups as new ones are added.
 */
@interface DOBackupManager : NSObject

/**
 * The path to the backup folder. On OS X this should be a security-scoped URL.
 */
@property (nonatomic, copy) NSURL *backupDirectoryURL;

/**
 * The maximum number of backups that will be kept. The oldest backups will be deleted
 * to keep the backup count under this number.
 *
 * A value of 0 for this property disables it and an unlimited number of backups
 * will be created.
 */
@property (nonatomic, assign) NSUInteger maxBackupsToKeep;

/**
 * All backups in the backup directory, in ascending order by backup date.
 */
@property (nonatomic, copy, readonly) NSArray *backups;

/**
 * The designated initializer.
 *
 * @param backupDirectoryURL The path to the directory where backups are stored. 
 * On OS X this should be a security-scoped URL.
 * @param maxBackupsToKeep The maximum number of backups to keep. 0 means unlimited.
 */
- (instancetype)initWithBackupDirectoryURL:(NSURL *)backupDirectoryURL
                          maxBackupsToKeep:(NSUInteger)maxBackupsToKeep;

/**
 * Adds a new backup with the specified contents.
 *
 * @param backupContents A file wrapper containing the content to be written. The file wrapper may
 * be a regular file wrapper or a directory wrapper. In the latter case the contents of the directory
 * will be used as the backup (vs. making an additional directory inside the backup directory).
 * Except for a top-level directory wrapper all wrappers and sub-wrappers must have preferredFilename
 * set or an exception will be thrown.
 *
 * @param backupDate The date of the backup. If nil the current date will be used.
 * @param error Will be set if the backup fails
 *
 * @return The backup if successful; nil otherwise.
 *
 */
- (DOBackup *)addBackupWithContents:(NSFileWrapper *)backupContents
                         backupDate:(NSDate *)backupDate
                              error:(NSError **)error;

@end


/**
 * Information associated with an individual backup job.
 */
@interface DOBackup : NSObject

/**
 * The contents of the backup as a directory file wrapper.
 */
@property (nonatomic, strong, readonly) NSFileWrapper *backupContents;

/**
 * The backup date.
 */
@property (nonatomic, copy, readonly) NSDate *backupDate;

@end