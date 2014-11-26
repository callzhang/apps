//
//  DOMusicClient.h
//  DOCore
//
//  Created by Adam Kirk on 8/8/13.
//
//

#import <DOCore/DOCore.h>

@interface DOMusicClient : AFHTTPClient
+ (DOMusicClient *)sharedClient;
- (void)iTunesURLForTrack:(NSString *)track
                    album:(NSString *)album
                   artist:(NSString *)artist
                  success:(void (^)(NSURL *iTunesURL))success
                  failure:(void (^)(NSError *error))failure;
@end
