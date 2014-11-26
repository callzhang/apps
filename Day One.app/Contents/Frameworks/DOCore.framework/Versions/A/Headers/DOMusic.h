//
//  DOMusic.h
//  DOCore
//
//  Created by Adam Kirk on 7/25/13.
//
//

#import "DOMapped.h"

@interface DOMusic : NSObject <DOMapped, NSCopying>
@property (nonatomic, copy) NSString *artist;
@property (nonatomic, copy) NSString *album;
@property (nonatomic, copy) NSString *albumYear;
@property (nonatomic, copy) NSString *track;
@end
