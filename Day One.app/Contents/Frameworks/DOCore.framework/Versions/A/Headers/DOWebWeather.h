//
//  DOWebWeather.h
//  DOCore
//
//  Created by Ben Dolman on 5/23/13.
//
//

#import "DOWebObject.h"
#import "DOWeather.h"


@interface DOWebWeather : DOWebObject

@property (nonatomic, copy) NSString *weatherDescription;
@property (nonatomic, copy) NSString *code;
@property (nonatomic, copy) NSNumber *tempCelsius;
@property (nonatomic, copy) NSString *service;

/**
 * Initializes the object with the contents of the weather dictionary
 * from DOJournalEntryFile. Returns nil if dict is nil.
 */
- (id)initWithEntryWeather:(DOWeather *)weather;

/**
 * Returns a dictionary that can be used for the weather property of a DOJournalEntryFile.
 */
- (DOWeather *)entryWeather;

@end
