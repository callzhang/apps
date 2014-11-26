//
//  DOWebClient.h
//  DOCore
//
//  Created by Ben Dolman on 5/7/13.
//
//  Client for connecting to the Day One API.

#import "AFHTTPClient.h"
#import "DOWebUser.h"
#import "DOWebEntry.h"
#import "DOWebAuthToken.h"
#import "DOWebReceipt.h"
#import "DOWebProvider.h"
#import "DOWebEnrollment.h"
#import "DOWebShare.h"
#import <Accounts/Accounts.h>

extern NSString * const DOWebClientErrorDomain;

// Error codes in the DOWebClientErrorDomain represent the HTTP status code if less than 1000
typedef NS_ENUM(NSInteger, DOWebClientErrorCode) {
    DOWebClientErrorInvalidResponse = 1000  // The response contained invalid data.
};

// This key will exist in error objects that are passed to a failure block.
// The corresponding value is a DOWebClientRetryBlock. Invoking this block will
// cause the request to be retried using the original parameters passed into
// the method, including the original success and failure blocks.
extern NSString * const DOWebClientRetryBlockKey;
typedef void (^DOWebClientRetryBlock)(void);

// Some APIs provide field-level error reporting (e.g. user validation, entry publishing).
// For those APIs, a dictionary will be included in the error's userInfo dictionary under
// this key. The documentation for the API will indicate whether you can expect it.
extern NSString * const DOWebClientFieldErrorsDictionaryKey;

@interface DOWebClient : AFHTTPClient

/**
 * The auth token to use for all authenticated requests. This must be set before making
 * any authenticated calls.
 */
@property (nonatomic, strong) DOWebAuthToken *authToken;

/**
 * A convenience property for storing the current user object. This is never set
 * or used internally, it's simply a convenience for users of DOWebClient. If you want
 * to use it, you must set it.
 */
@property (nonatomic, strong) DOWebUser *user;

#pragma mark - Unauthenticated Calls

/**
 * Creates a user on the server. If there are data validation errors, error.userInfo[DOWebClientFieldErrorsDictionaryKey] 
 * will contain a dictionary with errors for the individual user fields. The keys in that dictionary match
 * the property names of DOWebUser.
 */
- (void)createUser:(DOWebUser *)user
           success:(void (^)(DOWebUser *user))success
           failure:(void (^)(NSError *error))failure;

/**
 * Validates that a user can be successfully created. The server checks things like
 * sufficient password strength, valid email, etc. If there are data validation errors,
 * error.userInfo[DOWebClientFieldErrorsDictionaryKey] will contain a dictionary with errors for the individual 
 * user fields. The keys in that dictionary match the property names of DOWebUser.
 */
- (void)validateUser:(DOWebUser *)user
             success:(void (^)(void))success
             failure:(void (^)(NSError *error))failure;

/**
 * Attempts to authenticate using a username and password. If successful, a user object
 * and an auth token will be returned. You will usually want to save the authToken to the
 * keychain and set the client's authToken to this value.
 */
- (void)signInWithEmail:(NSString *)email
              password:(NSString *)password
               success:(void (^)(DOWebUser *user, DOWebAuthToken *authToken))success
               failure:(void (^)(NSError *error))failure;

/**
 * Initiates the process of resetting a users password. The server will accept this request
 * and send the user an e-mail with a link to reset their password. If there are data validation errors,
 * error.userInfo[DOWebClientFieldErrorsDictionaryKey] will contain a dictionary with errors for the individual
 * user fields.
 */
- (void)beginPasswordResetForEmail:(NSString *)email
                           success:(void (^)(void))success
                           failure:(void (^)(NSError *error))failure;


/**
 * Returns the product identifiers used for in-app purchase.
 */
- (void)fetchProductCatalog:(void (^)(NSDictionary *identifiers))success
                    failure:(void (^)(NSError *error))failure;

#pragma mark Authenticated Calls
#pragma mark (Sign Out)

/**
 * Signs out the current user. This invalidates the token on the server side.
 * You will usually want to delete the token from the keychain after this completes
 * and set the client's authToken property to nil.
 */
- (void)signOutCurrentUser:(void (^)(void))completed;

#pragma mark (User)

/**
 * Updates the current user information. If this is successful then the updated user
 * object will be returned. If there are data validation errors,
 * error.userInfo[DOWebClientFieldErrorsDictionaryKey] will contain a dictionary with errors for the individual
 * user fields. The keys in that dictionary match the property names of DOWebUser
 */
- (void)updateCurrentUser:(DOWebUser *)updatedUser
                  success:(void (^)(DOWebUser *user))success
                  failure:(void (^)(NSError *error))failure;

/**
 * A successful password change invalidates all tokens on the server, so you will need
 * to call the signIn method after changing the password to get a new token. If there are data validation errors,
 * error.userInfo[DOWebClientFieldErrorsDictionaryKey] will contain a dictionary with errors for the individual
 * fields.
 */
- (void)changeCurrentPassword:(NSString *)currentPassword
                  newPassword:(NSString *)newPassword
                      success:(void (^)(void))success
                      failure:(void (^)(NSError *error))failure;

/**
  If successful, the user object for the current user will be returned.
 */
- (void)fetchCurrentUser:(void (^)(DOWebUser *user))success
                 failure:(void (^)(NSError *error))failure;

/**
 * Uploads an in-app purchase receipt to the server.
 */
- (void)uploadReceipt:(DOWebReceipt *)receipt
              success:(void (^)(void))success
              failure:(void (^)(NSError *error))failure;


#pragma mark (Publish)

/**
 * Publishes an entry file to the server and returns the published entry object. If there are data validation errors,
 * error.userInfo[DOWebClientFieldErrorsDictionaryKey] will contain a dictionary with errors for the individual
 * entry fields. The keys in that dictionary match the property names of DOWebEntry.
 */
- (void)publishEntry:(DOWebEntry *)entry
             success:(void (^)(DOWebEntry *publishedEntry))success
             failure:(void (^)(NSError *error))failure;

/**
 * Returns a web entry for the given publishID
 */
- (void)fetchEntryWithPublishID:(NSString *)publishID
                        success:(void (^)(DOWebEntry *entry))success
                        failure:(void (^)(NSError *error))failure;

/**
 * Deletes a web entry for the given publishID
 */
- (void)deleteEntryWithPublishID:(NSString *)publishID
                         success:(void (^)(void))success
                         failure:(void (^)(NSError *error))failure;

/**
 * Returns HTML to show in a web view for previewing a published entry before it's actually published.
 */
- (void)previewHTMLForEntry:(DOWebEntry *)entry
                   photoURL:(NSURL *)photoURL
                  photoSize:(CGSize)photoSize
                    success:(void (^)(NSString *html))success
                    failure:(void (^)(NSError *error))failure;

#pragma mark (Media)

/**
 * Uploads data to the media endpoint. You must specify the proper content type (e.g. image/png, image/jpeg).
 *
 * When data is uploaded it is assigned an id (the mediaID in the success callback) by the server and stored
 * in a temporary bucket. If that mediaID is used in subsequent calls, such as the update user call in the
 * avatar property of the user object, then the server "claims" that media object and puts it into a
 * permanent bucket. If it is not claimed after some period of time then it is deleted from the temporary bucket.
 */
- (void)uploadMediaData:(NSData *)data
            contentType:(NSString *)contentType
         clientChecksum:(NSString *)clientChecksum
                success:(void (^)(NSString *mediaID))success
               progress:(void (^)(float fractionCompleted))progress
                failure:(void (^)(NSError *error))failure;

/**
 * Given a media ID, returns a fully resolved URL to that resource
 */
- (NSURL *)resolvedURLWithMediaID:(NSString *)mediaID;

#pragma mark (Sharing)

/**
 * Returns an array of DOWebProvider objects available to the user.
 */
- (void)fetchProviders:(void (^)(NSArray *providers))success
               failure:(void (^)(NSError *error))failure;

/**
 * Shares the entry to the service that has the specified enrollment ID.
 * Returns a share object.
 */
- (void)shareEntryWithPublishID:(NSString *)publishID
                   enrollmentID:(NSString *)enrollmentID
                        success:(void (^)(DOWebShare *share))success
                        failure:(void (^)(NSError *error))failure;

/**
 * Deletes a share.
 */
- (void)deleteShareWithPublishID:(NSString *)publishID
                    enrollmentID:(NSString *)enrollmentID
                         success:(void (^)())success
                         failure:(void (^)(NSError *error))failure;

/**
 * Returns a share object for a particular entry and service.
 */
- (void)fetchShareWithPublishID:(NSString *)publishID
                   enrollmentID:(NSString *)enrollmentID
                        success:(void (^)(DOWebShare *share))success
                        failure:(void (^)(NSError *error))failure;

#pragma mark (Enrollment)

/**
 * Enroll in Facebook using an access token from the Facebook SDK
 */
- (void)enrollInFacebookWithAccessToken:(NSString *)accessToken
                                success:(void (^)(NSString *enrollmentID))success
                                failure:(void (^)(NSError *error))failure;

/**
 * Enroll in Foursquare using an access code from the Foursquare app
 */
- (void)enrollInFoursquareWithAccessCode:(NSString *)accessCode
                                 success:(void (^)(NSString *enrollmentID))success
                                 failure:(void (^)(NSError *error))failure;

/**
 * Enroll in Twitter using a system Twitter account
 */
- (void)enrollInTwitterWithAccount:(ACAccount *)account
                           success:(void (^)(NSString *enrollmentID))success
                           failure:(void (^)(NSError *error))failure;

/**
 * Remove an enrollment from a user.
 */
- (void)deleteEnrollmentWithEnrollmentID:(NSString *)enrollmentID
                                 success:(void (^)(void))success
                                 failure:(void (^)(NSError *error))failure;


@end
