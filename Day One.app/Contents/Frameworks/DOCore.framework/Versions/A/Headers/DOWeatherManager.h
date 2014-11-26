//
//  WeatherManager.h
//  DayOne
//
//  Created by Stephen Lynn on 5/7/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOWeather.h"


typedef enum {
    kCelsius,
    kFarenheit
}  DOTemperatureUnit;


@interface DOWeatherManager : NSObject

/**
 *	Fetches weather data from a service and passed a DOWeather object to the completion block.
 *
 *	@param	latitude    The latitude of the location.
 *	@param	longitude   The longitude of the location.
 *	@param	date        The date to get the weather of.
 *	@param	service     The source of the weather data.
 */
+ (void)weatherAtLatitude:(double)latitude
                longitude:(double)longitude
                     date:(NSDate *)date
                  service:(DOWeatherService)service
                  success:(void (^)(DOWeather *weather))success
                  failure:(void (^)(NSError *error))failure;

/**
 *	Convenience for weatherAtLatitude:longitude:date:service:success:failue: but passes a default weather service.
 *
 *	@param	latitude    The latitude of the location.
 *	@param	longitude   The longitude of the location.
 *	@param	date        The date to get the weather of.
 */
+ (void)weatherAtLatitude:(double)latitude
                longitude:(double)longitude
                     date:(NSDate *)date
                  success:(void (^)(DOWeather *weather))success
                  failure:(void (^)(NSError *error))failure;


/**
 *    The suggested service to use for obtaining the weather on `date`.
 *
 *    @param    date    The date you want to obtain the weather on. Usually this is an entry file's creation date.
 *
 *    @return    The weather service best suited to provide the weather information for `date`.
 */
+ (DOWeatherService)suggestedWeatherServiceForDate:(NSDate *)date;


@end
