//
//  DOFoursquareVenue.h
//  DOCore
//
//  Created by BJ Homer on 7/8/13.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "DOLocation.h"

@interface DOFoursquareVenue : NSObject

- (instancetype)initWithJSON:(NSDictionary *)json;


/// An opaque identifer, used by Foursquare
@property (nonatomic, readonly) NSString *identifier;

/// Name of the venue
@property (nonatomic, readonly) NSString *name;

/// Address string of the venue
@property (nonatomic, readonly) NSString *address;

/// Distance in meters
@property (nonatomic, readonly) float distance;

/// Coordinate of the venue
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

/// The raw dictionary we got back from the API
@property (readonly) NSDictionary *APIDictionary;

@end


@interface DOFoursquareVenue (DOEntryLocationCompatibility)

/// A dictionary that can be used as the `location` property of a DOJournalEntryFile or DOEntry object.
@property (readonly) DOLocation *location;


@end