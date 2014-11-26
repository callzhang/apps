//
//  DOWebAuthToken.h
//  DOCore
//
//  Created by Ben Dolman on 5/16/13.
//
//  A token is comprised of a userID and an auth token string.
//  This is used by DOWebClient to communicate with the server.

#import <Foundation/Foundation.h>

extern NSString * const DOWebAuthTokenDefaultKeychainServiceName;
extern NSString * const DOWebAuthTokenDefaultKeychainAccessGroup;

@interface DOWebAuthToken : NSObject <NSCopying>

@property (nonatomic, copy, readonly) NSString *userID;
@property (nonatomic, copy, readonly) NSString *token;
@property (nonatomic, copy, readonly) NSString *email;

/**
 * Returns the auth token last saved to the keychain using -saveToKeychain.
 * 
 * @param serviceName The service name to use when querying the keychain
 * @param accessGroup The access group to use when querying the keychain (iOS only)
 * @param error Set if there was an error reading from the keychain
 *
 * @return Token found that matches the criteria or nil if none was found. If there was an error
 *         then nil be returned and error will be set.
 */
+ (DOWebAuthToken *)savedTokenWithKeychainServiceName:(NSString *)serviceName
                                          accessGroup:(NSString *)accessGroup
                                                error:(NSError **)error;

/**
 * Deletes a previously saved auth token from the keychain.
 *
 * @param serviceName The service name to use when writing to the keychain
 * @param accessGroup The access group to use when writing to the keychain (iOS only)
 * @param error Set if there was an error deleting from the keychain
 *
 * @return YES if the deletion was successful or there was nothing to delete. NO if there was an error.
 */
+ (BOOL)deleteSavedTokenWithKeychainServiceName:(NSString *)serviceName
                                    accessGroup:(NSString *)accessGroup
                                          error:(NSError **)error;

/**
 * Designated initializer. This creates a new in-memory token. If you want to save it to the keychain you 
 * must call -saveToKeychain.
 *
 * @param userID The User ID (required)
 * @param token The token string (required)
 * @param email The email address (optional)
 *
 * @return A new object
 */
- (instancetype)initWithUserID:(NSString *)userID token:(NSString *)token email:(NSString *)email;

/**
 * Saves the token to the keychain, overwriting any existing token with the same service name and access group.
 * 
 * @param serviceName The service name to use when writing to the keychain
 * @param accessGroup The access group to use when writing to the keychain (iOS only)
 * @param error Populated if there is an error
 *
 * @return YES if the save was successful.
 */
- (BOOL)saveToKeychainWithServiceName:(NSString *)serviceName
                          accessGroup:(NSString *)accessGroup
                                error:(NSError **)error;

@end
