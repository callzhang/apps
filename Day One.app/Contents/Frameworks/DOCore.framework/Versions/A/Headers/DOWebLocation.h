//
//  DOWebLocation.h
//  DOCore
//
//  Created by Ben Dolman on 5/23/13.
//
//

#import "DOWebObject.h"
#import "DOWebWeather.h"
#import "DOLocation.h"

@interface DOWebLocation : DOWebObject

@property (nonatomic, copy) NSString *localityName;
@property (nonatomic, copy) NSString *administrativeArea;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSString *placeName;
@property (nonatomic, copy) NSNumber *latitude;
@property (nonatomic, copy) NSNumber *longitude;
@property (nonatomic, copy) NSString *foursquareID;

/**
 * Initializes the object with the contents of the location object
 * from DOJournalEntryFile. Returns nil if location is nil.
 */
- (id)initWithEntryLocation:(DOLocation *)location;

/**
 * Returns a dictionary that can be used for the location property of a DOJournalEntryFile.
 */
- (DOLocation *)entryLocation;

@end
