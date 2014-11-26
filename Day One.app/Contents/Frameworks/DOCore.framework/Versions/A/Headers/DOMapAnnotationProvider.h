//
//  DOMapAnnotationProvider.h
//  DOCore
//
//  Created by BJ Homer on 7/23/13.
//
//

#import <Foundation/Foundation.h>
#import "DOJournalIndex.h"
#import <MapKit/MapKit.h>

@interface DOMapAnnotationProvider : NSObject

- (instancetype)initWithJournalIndex:(DOJournalIndex *)index;

typedef void(^DOMapAnnotationHandler)(NSArray *annotations);

/**
 * Provides an array of annotations that can be displayed in the given region.
 * @param coordinateRegion   The region from which entries should be clustered.
 * @param zoomScale          The zoom scale, defined as the map view's frame width divided by the map view's mapRect's width.
 * @param existingClusters   An array of annotation objects, which will be preserved if possible.
 * @param handler            A block that will be invoked when annotations have been fetched.
 **/
- (void)fetchAnnotationsForCoordinateRegion:(MKCoordinateRegion)coordinateRegion
                                  zoomScale:(MKZoomScale)zoomScale
                        existingAnnotations:(NSArray *)existingAnnotations
                                    handler:(DOMapAnnotationHandler)handler;



/// This will return the class of the returned annotation objects. Clients can use this to filter when
/// updating annotations.
- (Class)annotationClass;
@end
