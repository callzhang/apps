//
//  NSArray+CaseInsensitive.h
//  DOCore
//
//  Created by Ben Dolman on 10/18/12.
//
//

#import <Foundation/Foundation.h>

@interface NSArray (CaseInsensitive)

- (NSUInteger)indexOfCaseInsensitiveString:(NSString *)aString;

@end

@interface NSMutableArray (CaseInsensitive)

- (void) removeCaseInsensitiveString:(NSString *)aString;

@end