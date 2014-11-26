//
//  DOLocationRepairShop.h
//  DOCore
//
//  Created by BJ Homer on 11/14/13.
//
//

#import <Foundation/Foundation.h>
#import "DOLocation.h"

@interface DOLocationRepairShop : NSObject

typedef void(^DOLocationRepairHandler)(DOLocation *repairedLocation, NSError *error);

/**
 * This method takes a DOLocation with GPS coordinates that are presumed to be incorrect (e.g. 0 N., 0 E.).
 * It will attept to find an appropriate GPS coordinate given the other data available in the location object.
 */
- (void)repairGPSCoordinatesForLocation:(DOLocation *)location handler:(DOLocationRepairHandler)handler;

@end
