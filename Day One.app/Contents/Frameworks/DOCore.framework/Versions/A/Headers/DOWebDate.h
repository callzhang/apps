//
//  DOWebDate.h
//  DOCore
//
//  Created by Ben Dolman on 10/2/13.
//
//

#import "DOWebObject.h"

@interface DOWebDate : DOWebObject <MTLManagedObjectSerializing>

@property (nonatomic, copy) NSDate *date;
@property (nonatomic, copy) NSTimeZone *timeZone;

@end
