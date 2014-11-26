//
//  DOWebContext.h
//  DOCore
//
//  Created by Ben Dolman on 1/8/14.
//
//

#import <Foundation/Foundation.h>
#import "DOWebAuthToken.h"
#import "DOWebClient.h"

extern NSString *const DOWebContextDidSignInNotification;
extern NSString *const DOWebContextDidSignOutNotification;

/**
 * A web context encapsulates configuration information and sign in state for connecting to the Day One web service.
 * You would typically pass a single copy of this context around your app. Your app can use it to create clients
 * and to react to sign in/out events.
 */
@interface DOWebContext : NSObject

@property (nonatomic, copy) NSURL *baseURL;
@property (nonatomic, copy, readonly) DOWebAuthToken *authToken;
@property (nonatomic, assign, readonly, getter = isSignedIn) BOOL signedIn;

/**
 * Creates a new instance.
 *
 * @param baseURL The base URL to use when creating new clients
 * @param serviceName The keychain service name to use for token persistence (optional)
 * @param accessGroup The keychain access group to use for token persistence (optional, iOS-only)
 *
 * @return A new instance
 */
- (instancetype)initWithBaseURL:(NSURL *)baseURL
            keychainServiceName:(NSString *)serviceName
                    accessGroup:(NSString *)accessGroup;

/**
 * Creates a new client instance with the configured host and auth token.
 */
- (DOWebClient *)createClient;

/**
 * Updates the authToken property. If keychain information was included in the init call then the context
 * will automatically attempt to persist the token to the keychain.
 *
 * If token is different than the current authToken then a DOWebContextDidSignInNotification notification will
 * be dispatched.
 *
 * @param token The new auth token
 */
- (void)signInWithToken:(DOWebAuthToken *)token;

/**
 * Sets authToken to nil and dispatches DOWebContextDidSignOutNotification.
 */
- (void)signOut;

@end
