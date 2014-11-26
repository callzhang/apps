//
//  DOSync.h
//  DayOne
//
//  Created by Ben Dolman on 5/14/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * Notification sent when sync properties change. Observers
 * can use this notification to update their UI with the current sync status.
 * 
 * Subclasses should not dispatch this notification directly; they should
 * call -scheduleUpdateNotification instead.
 */
extern NSString *const DOSyncUpdatedNotification;

/**
 * Key included in the DOSyncUpdatedNotification.
 * The value of the uploadCount property at the time the notification is dispatched.
 * Value is an NSNumber object.
 */
extern NSString *const DOSyncUploadCountKey;

/**
 * Key included in the DOSyncUpdatedNotification.
 * The value of the downloadCount property at the time the notification is dispatched.
 * Value is an NSNumber object.
 */
extern NSString *const DOSyncDownloadCountKey;

/**
 * Key included in the DOSyncUpdatedNotification.
 * The value of the isSyncing property at the time the notification is dispatched.
 * Value is an NSNumber object representing a boolean value.
 */
extern NSString *const DOSyncIsSyncingKey;

/**
 * Abstract class that encapsulates logic shared by file-based sync services.
 * Subclasses should include the private header and set the properties 
 * below as they change.
 */
@interface DOSync : NSObject

/**
 * Returns YES when the service is sychronizing.
 * The definition of "synchronizing" varies by service. In most cases
 * it means that files are being processed or data is being transferred.
 * Default is NO.
 */
@property (readonly) BOOL isSyncing;

/**
 * Returns the root path on the remote host, if applicable.
 * Default is nil.
 */
@property (readonly, copy) NSString *remotePath;

/**
 * Returns the number of files pending upload.
 */
@property (readonly) NSUInteger uploadCount;

/**
 * Returns the number of files pending download
 */
@property (readonly) NSUInteger downloadCount;

/**
 * Permanently stops synchronization. Object should not be used after calling this.
 * Users of this class are expected to ALWAYS call this before
 * releasing the object.
 *
 * The default implementation does nothing. Subclasses should override this method
 * and stop synchronizing ASAP. Subclasses should stop background activity, \
 * tear down data structures, etc.
 */
-(void)stopSync;

@end
