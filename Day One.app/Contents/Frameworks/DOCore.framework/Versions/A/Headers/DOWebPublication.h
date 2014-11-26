//
//  DOWebPublication.h
//  DOCore
//
//  Created by Ben Dolman on 8/27/13.
//
//

#import "DOWebObject.h"
#import "DOWebShare.h"
#import "DOWebDate.h"

@interface DOWebPublication : DOWebObject <MTLManagedObjectSerializing>

@property (nonatomic, strong) DOWebDate *publicationDate;
@property (nonatomic, copy) NSNumber *visits;
@property (nonatomic, copy) NSArray *shares;    // Contains DOWebShare objects
@property (nonatomic, copy) NSURL *publishedURL;

@end
