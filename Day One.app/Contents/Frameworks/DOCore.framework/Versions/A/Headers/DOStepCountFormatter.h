//
//  DOStepCountFormatter.h
//  DOCore
//
//  Created by BJ Homer on 11/25/13.
//
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(int, DOCapitalizationType) {
    DOCapitalizationTypeLowercase,
    DOCapitalizationTypeCapitalized,
    DOCapitalizationTypeUppercase
};

@interface DOStepCountFormatter : NSFormatter

@property (nonatomic, assign) DOCapitalizationType capitalizationType;

@end
