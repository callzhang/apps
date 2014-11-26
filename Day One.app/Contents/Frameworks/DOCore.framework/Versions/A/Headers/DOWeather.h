//
//  DOWeather.h
//  DOCore
//
//  Created by Adam Kirk on 7/10/13.
//
//

#import "DOMapped.h"

// Converts between the legacy iconName and the new weather code specification
// https://github.com/bloom/DayOne-Documentation/wiki/Weather-Codes
NSString *DOWeatherConvertIconNameToCode(NSString *iconName);
NSString *DOWeatherConvertCodeToIconName(NSString *code);

typedef NSString * DOWeatherService;
extern NSString * const DOWeatherServiceHAM;
extern NSString * const DOWeatherServiceForecast;


@interface DOWeather : NSObject <DOMapped, NSCopying>
- (id)initWithDictionary:(NSDictionary *)dictionary service:(DOWeatherService)service;
@property (nonatomic, copy) NSString         *temperatureCelsius;
@property (nonatomic, copy) NSString         *temperatureFahrenheit;
@property (nonatomic, copy) NSString         *conditionsDescription;
@property (nonatomic, copy) NSString         *iconName;
@property (nonatomic, copy) NSNumber         *relativeHumidity;
@property (nonatomic, copy) NSNumber         *pressureMB;
@property (nonatomic, copy) NSNumber         *windSpeedKPH;
@property (nonatomic, copy) NSNumber         *windBearing;
@property (nonatomic, copy) NSNumber         *windChillCelsius;
@property (nonatomic, copy) NSNumber         *visibilityKM;
@property (nonatomic, copy) NSDate           *sunriseDate;
@property (nonatomic, copy) NSDate           *sunsetDate;
@property (nonatomic, copy) DOWeatherService service;

// Setting this updates iconName to the proper value
@property (nonatomic, copy) NSString *code;

@end
