//
//  DOMKHelpers.h
//  DOCore
//
//  Created by BJ Homer on 7/22/13.
//
//

#import <MapKit/MKGeometry.h>

/// Calculates the westmost longitude contained in the region.
/// @return A coordinate in the range [-180, 180)
CLLocationDegrees DOMKCoordinateRegionWestmostLongitude(MKCoordinateRegion region);

/// Calculates the eastmost longitude contained in the region.
/// @return A coordinate in the range [-180, 180)
CLLocationDegrees DOMKCoordinateRegionEastmostLongitude(MKCoordinateRegion region);

/// Calculates the northmost latitude contained in the region.
CLLocationDegrees DOMKCoordinateRegionNorthmostLatitude(MKCoordinateRegion region);

/// Calculates the southmost latitude contained in the region.
CLLocationDegrees DOMKCoordinateRegionSouthmostLatitude(MKCoordinateRegion region);

/// Determines whether a coordinate is contained in the region.
BOOL DOMKCoordinateRegionContainsCoordinate(MKCoordinateRegion region, CLLocationCoordinate2D coordinate);

/// Determines whether two regions are the same.
BOOL DOMKCoordinateRegionEqualsRegion(MKCoordinateRegion region1, MKCoordinateRegion region2);