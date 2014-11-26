//
//  LocationManager.h
//  DayOne
//
//  Created by Stephen Lynn on 4/25/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


@class DOLocation;


//set to 50 miles in meters
extern const CLLocationDistance BIG_DISTANCE_CHANGE_THRESHOLD;

extern NSString * const kDOLocationUpdateNotification;
extern NSString * const REVERSE_GEO_LOOKUP_DONE;
extern NSString * const ADDRESS_LOOKUP_DONE;
extern NSString * const ADDRESS_DATA_KEY;


@interface DOLocationManager : NSObject <CLLocationManagerDelegate>
@property (nonatomic, strong) DOLocation        *location;
@property (nonatomic, strong) NSTimer           *timer;
@property (nonatomic        ) double            horzAccuracy;
@property (nonatomic, strong) CLLocationManager *locationManager;
@property (nonatomic, readonly, getter = isSearching) BOOL searching;

+ (DOLocationManager *)sharedManager;

/**
 If the user has given the app permission to use their location.
 */
+ (BOOL)isAuthorized;

/**
 Forward lookup. When done, posts a notification with placemarks matching the search string.
 */
- (void)addressLookup:(NSString*)searchString;

/**
 Given a latitude and longitude, it will post a notification when complete with a dictionary of the locations info.
 */
- (void)reverseGeoLookupLongitude:(double)theLong latitude:(double)theLat;

typedef void(^DOLocationManagerCallback)(DOLocation *location, BOOL finalValue);
/// When using the handler: variant, the block may be called multiple times as location information is refined.
- (void)startWithTimeout:(double)timeout handler:(DOLocationManagerCallback)handler;
                                                
- (void)startWithTimeout:(double)timeout;
- (void)start;
- (void)stop;
@end
