//
//  DOMNewsletterSignupOperation.h
//  DayOne
//
//  Created by BJ Homer on 10/21/13.
//  Copyright (c) 2013 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DONewsletterSignupOperation : NSOperation

+ (instancetype)operationForSubmittingEmail:(NSString *)email;

@property (readonly) NSString *email;

/// When the operation is finished, if 'error' is set then the operation failed.
@property (readonly) NSError *error;

@end
