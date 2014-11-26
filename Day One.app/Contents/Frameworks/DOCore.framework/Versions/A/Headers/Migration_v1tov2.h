//
//  Migration_v1tov2.h
//  DayOne
//
//  Created by Ben Loveridge on 4/22/11.
//  Copyright 2011 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Migration_v1tov2 : NSEntityMigrationPolicy {

}

- (NSNumber *) creationYearForCreationDate:(NSDate *)creationDate;

@end
