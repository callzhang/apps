//
//  DOUnitConversionUtils.h
//  DOCore
//
//  Created by Adam Kirk on 7/31/13.
//
//

#import <Foundation/Foundation.h>

@interface DOUnitConversionUtils : NSObject

#pragma mark - Weather

// temperature
+ (NSNumber *)celsiusFromFahrenheit:(NSNumber *)fahrenheit;
+ (NSNumber *)fahrenheitFromCelsius:(NSNumber *)celsius;

// wind direction
+ (NSString *)windDirectionFromWindBearing:(NSNumber *)windBearing;
+ (NSNumber *)windBearingFromWindDirection:(NSString *)windDirection;

@end
