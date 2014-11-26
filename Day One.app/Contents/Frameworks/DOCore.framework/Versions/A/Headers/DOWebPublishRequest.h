//
//  DOWebPublishRequest.h
//  DOCore
//
//  Created by Ben Dolman on 8/23/13.
//
//

#import <Foundation/Foundation.h>
#import "DOWebClient.h"
#import "DOJournalIndex.h"

/**
 * This notification is dispatched whenever anything changes in the request. This includes state changes, 
 * upload progress changes, changes to share status, etc. No information about what changed is included
 * in the notification. It is expected that users of DOWebPublishRequest will listen for this notification and then 
 * go through and update their own state based on whatever the current values of the request are.
 */
extern NSString * const DOWebPublishRequestUpdatedNotification;

typedef NS_ENUM(NSInteger, DOWebPublishRequestState) {
    DOWebPublishRequestStateCancelled = -2,     // Cancel has been called
    DOWebPublishRequestStateError = -1,         // An error occurred during photo upload or entry publishing
    DOWebPublishRequestStateNotStarted = 0,     // The state when the object is first created
    DOWebPublishRequestStatePhotoUploading,     // The photo is currently uploading
    DOWebPublishRequestStatePhotoUploaded,      // The photo has finished uploading but startPublish hasn't been called.
    DOWebPublishRequestStateEntryPublishing,    // The entry is publishing
    DOWebPublishRequestStateSharing,            // The entry has published and is now being shared
    DOWebPublishRequestStateFinished            // The entry has finished publishing and sharing.
};                                              //    NOTE: Individual shares may have failed.

/**
 * Encapsulates the entire process of publishing an entry including photo upload and sharing.
 * This is a one-shot object and cannot be reused for multiple requests. To re-publish an entry due
 * to failure, create a new request.
 */
@interface DOWebPublishRequest : NSObject

/**
 * The entry to publish. Once startPublish is called, the request assumes management of this entry
 * and may change properties on it, such as setting photo information after photo upload completes.
 */
@property (nonatomic, strong) DOWebEntry *entry;

/**
 * Contains enrollmentIDs as NSString objects. After the entry has been published, the request will
 * attempt to share the entry to each of these enrollments. You can check the state of shares using
 * isShareFinishedForEnrollmentID:error.
 *
 * @note This value will never be nil.
 */
@property (nonatomic, copy) NSArray *shareEnrollments;

/**
 * The photo data to upload to the server. If you set this you must also set photoContentType.
 */
@property (nonatomic, copy) NSData *photoData;

/**
 * The content type of the photo (e.g. "image/jpeg"). You must set this if you set photoData.
 */
@property (nonatomic, copy) NSString *photoContentType;

/**
 * The client-provided checksum of the photo
 */
@property (nonatomic, copy) NSString *photoChecksum;

/**
 * After the entry has been successfully published, this will contain the published entry returned by the server.
 * Shares will be added to this entry as they successfully complete. The object will not be modified anymore once
 * the request is in the DOWebPublishRequestStateFinished state.
 */
@property (nonatomic, strong, readonly) DOWebEntry *publishedEntry;

/**
 * If the request is in the error state this will contain the error object
 */
@property (nonatomic, copy, readonly) NSError *error;


/**
 * Convenience initializer. This extracts baseURL and authToken from the client
 * and passes them to the designated initializer.
 */
- (instancetype)initWithClient:(DOWebClient *)client;

/**
 * Initializes the request with a baseURL and an authToken. These may not be nil. 
 * This is the designated intializer.
 */
- (instancetype)initWithBaseURL:(NSURL *)baseURL
                      authToken:(DOWebAuthToken *)authToken;

/**
 * Begins uploading the photo in the background to a temporary location on the server. You can call this 
 * before setting an entry or shareEnrollments to get the photo upload started while waiting for the user to
 * finish setting preferences for their publish.
 *
 * This method does nothing if photoData is nil.
 */
- (void)startPhotoUpload;

/**
 * Begins the publish process. When this is called, the following happens:
 * 
 * 1. If a photo has been set, it is uploaded (if not already in progress via beginPhotoUpload.)
 * 2. Once photo has uploaded, the entry is published.
 * 3. Once the entry has been published, it is shared to any enrollments that have been set.
 *
 * Anytime the state of the request changes a notification is dispatched.
 */
- (void)startPublish;

/**
 * Cancels the publish process. Once cancelled no further notifications will be sent.
 * Because this is a one-shot object, once cancelled it cannot be reused.
 */
- (void)cancel;

/**
 * The current state of the request.
 */
- (DOWebPublishRequestState)state;

/**
 * The percentage of photo data uploaded so far, as a number between 0 and 1.
 * This will always be zero if there is no photo.
 */
- (float)photoProgress;

/**
 * Returns YES if the share has finished. If the share failed, this returns YES and sets the error pointer.
 * If it succeeded, this returns YES with no error pointer set.
 *
 * If the share has not completed (or the enrollmentID is not recognized) then this returns NO.
 */
- (BOOL)isShareFinishedForEnrollmentID:(NSString *)enrollmentID error:(NSError **)error;

@end