//
//  DOWebEditRecord.h
//  DOCore
//
//  Created by Ben Dolman on 10/2/13.
//
//

#import "DOWebObject.h"
#import "DOWebDate.h"

@interface DOWebEditRecord : DOWebObject

@property (nonatomic, copy) NSNumber *userID;
@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, strong) DOWebDate *date;

@end