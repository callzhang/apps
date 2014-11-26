//
//  NSData+DOCrypto.h
//  DayOne
//
//  Created by Ben Dolman on 3/22/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOVersion.h"

@interface NSData (DOCrypto)

+ (NSData *)dataWithRandomBytesOfLength:(NSUInteger)length;

- (NSData *)AES128EncryptWithKey:(NSData *)key;
- (NSData *)AES128DecryptWithKey:(NSData *)key;

@end
