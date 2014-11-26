//
//  DOSQLiteBackupProcessor.h
//  DOCore
//
//  Created by Ben Dolman on 2/25/14.
//
//

#import <Foundation/Foundation.h>

extern NSString *const DOSQLiteBackupErrorDomain;

@interface DOSQLiteBackupProcessor : NSObject

/**
 * Uses native SQLite backup functions to synchronously backup a database.
 *
 * @param sourceURL The filesystem path of the database to backup
 * @param destURL The filesytem path of the resulting backup file
 * @param error This will be set if there is an error
 * @param progress A block that will be called periodically to report progress (0-1 values).
 *
 * @return Whether or not the backup succeeded.
 */
+ (BOOL)backupFrom:(NSURL *)sourceURL
                to:(NSURL *)destURL
             error:(NSError **)error
          progress:(void (^)(float progress))progress;

@end
