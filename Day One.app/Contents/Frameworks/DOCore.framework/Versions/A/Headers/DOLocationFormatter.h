//
//  LocationFormatter.h
//  DayOne
//
//  Created by Ben Dolman on 6/29/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@class DOEntryCluster;
@class DOLocation;

@interface DOLocationFormatter : NSFormatter

/// This will return a string like "Riverton and Herriman"
- (NSString *)localLocationStringForLocation:(DOLocation *)location;

/// This will return a string like "Riverton and Herriman"
- (NSString *)localLocationStringForLocations:(NSArray *)locations;

/// This will return a string like "Riverton and Herriman"
- (NSString *)localLocationStringForPlacemarks:(NSArray *)placemarks;

/// This will return a string like "Riverton and Herriman"
- (NSString *)localLocationStringForCluster:(DOEntryCluster *)cluster;



/// This will return a string like "Utah, United States"
- (NSString *)contextStringForLocation:(DOLocation *)location;

/// This will return a string like "Utah, United States"
- (NSString *)contextStringForLocations:(NSArray *)locations;

/// This will return a string like "Utah, United States"
- (NSString *)contextStringForPlacemarks:(NSArray *)placemarks;

/// This will return a string like "Utah, United States"
- (NSString *)contextStringForCluster:(DOEntryCluster *)cluster;


/// This will return a string like "Riverton and Herriman, Utah, United States"
- (NSString *)locationStringForLocation:(DOLocation *)location;

/// This will return a string like "Riverton and Herriman, Utah, United States"
- (NSString *)locationStringForLocations:(NSArray *)locations;

/// This will return a string like "Riverton and Herriman, Utah, United States"
- (NSString *)locationStringForPlacemarks:(NSArray *)locations;

/// This will return a string like "Riverton and Herriman, Utah, United States"
- (NSString *)locationStringForCluster:(DOEntryCluster *)locations;

@end
