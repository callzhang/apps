//
//  DOEntryCluster.h
//  DOCore
//
//  Created by BJ Homer on 7/29/13.
//
//

#import <Foundation/Foundation.h>
#import <MapKit/MKAnnotation.h>
#import <CoreData/CoreData.h>

@interface DOEntryCluster : NSObject <MKAnnotation>
@property (readonly) NSArray *entries;
@property (readonly) CLLocation *geographicCentroid;
@property BOOL flagged;

- (void)migrateEntriesToContext:(NSManagedObjectContext *)context;
@end

