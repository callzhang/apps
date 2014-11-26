//
//  DOCreator.h
//  DOCore
//
//  Created by Ben Dolman on 6/28/13.
//
//

#import "DOMapped.h"


@interface DOCreator : NSObject <DOMapped, NSCopying>

+ (DOCreator *)currentCreator;

@property (nonatomic, copy) NSString *OSAgent;
@property (nonatomic, copy) NSString *deviceAgent;
@property (nonatomic, copy) NSString *hostName;
@property (nonatomic, copy) NSString *softwareAgent;
@property (nonatomic, strong) NSDate *generationDate;

@end
