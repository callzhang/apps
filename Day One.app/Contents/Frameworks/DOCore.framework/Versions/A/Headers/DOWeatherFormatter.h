//
//  WeatherFormatter.h
//  DayOne
//
//  Created by Ben Dolman on 6/29/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOWeather.h"


typedef NS_ENUM(NSInteger, DOTemperatureScale) {
    DOWeatherFormatterCelsiusScale,
    DOWeatherFormatterFarenheitScale
};


@interface DOWeatherFormatter : NSFormatter
- (id)initWithTemperatureScale:(DOTemperatureScale)scale;
- (NSString *)stringFromWeather:(DOWeather *)weather;
- (NSString *)temperatureStringFromWeather:(DOWeather *)weather;
@end
