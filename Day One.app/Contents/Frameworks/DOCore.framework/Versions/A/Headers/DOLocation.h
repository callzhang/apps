//
//  DOLocation.h
//  DOCore
//
//  Created by Adam Kirk on 7/18/13.
//
//

#import "DOMapped.h"
#import "DOVersion.h"
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MKAnnotation.h>



@interface DOLocation : NSObject <DOMapped, NSCopying, MKAnnotation>
@property (nonatomic, copy) NSString *placeName;
@property (nonatomic, copy) NSString *localityName;
@property (nonatomic, copy) NSString *administrativeArea;
@property (nonatomic, copy) NSString *country;
@property (nonatomic, copy) NSNumber *latitude;
@property (nonatomic, copy) NSNumber *longitude;
@property (nonatomic, copy) NSString *foursquareID;
#if TARGET_IOS
@property (nonatomic, copy) CLCircularRegion *region;
#else
@property (nonatomic, copy) CLRegion *region;
#endif
@end


@interface DOLocation (MapKitConvenience)

+ (instancetype)locationForCoordinate:(CLLocationCoordinate2D)coordinate;
+ (instancetype)locationForPlacemark:(CLPlacemark *)placemark;
+ (instancetype)locationForPlacemark:(CLPlacemark *)placemark withCoordinate:(CLLocationCoordinate2D)coordinate;
- (void)applyMetadataFromPlacemark:(CLPlacemark *)placemark;
- (CLLocation *)CLLocationObject;

@end
