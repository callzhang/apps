//
//  DOFoursquareClient.h
//  DOCore
//
//  Created by BJ Homer on 7/8/13.
//
//

#import <DOCore/DOCore.h>

extern NSString *const DOFoursquareClientID;
extern NSString *const DOFoursquareClientSecret;

@interface DOFoursquareClient : AFHTTPClient

@property (nonatomic, copy) NSString *clientID;
@property (nonatomic, copy) NSString *clientSecret;

+ (instancetype)sharedClient;

- (void)listLocalVenuesForLatitude:(double)lat longitude:(double)lng query:(NSString*)query withHandler:(void (^)(NSArray * venues))handler;


@end
