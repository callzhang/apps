//
//  DOWebTransformers.h
//  DOCore
//
//  Created by Ben Dolman on 5/15/13.
//
//

#import <Foundation/Foundation.h>

extern NSString * const DOWebDateToStringTransformerName;
extern NSString * const DOWebDataToBase64TransformerName;
extern NSString * const DOWebNumberToStringTransformerName;
extern NSString * const DOWebURLToStringTransformerName;
extern NSString * const DOWebFahrenheitToCelsiusTransformerName;
extern NSString * const DOWebDateToTimestampNumberTransformerName;

@interface DOWebTransformers : NSObject

@end
