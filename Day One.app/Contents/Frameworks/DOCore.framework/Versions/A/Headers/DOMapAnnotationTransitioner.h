//
//  DOMapAnnotationTransitioner.h
//  DOCore
//
//  Created by BJ Homer on 8/20/13.
//
//

#import <Foundation/Foundation.h>
@class MKMapView;

@interface DOMapAnnotationTransitioner : NSObject

- (void)animateAnnotationsInMapView:(MKMapView *)mapView toAnnotations:(NSArray *)updatedAnnotations;

@end
