//
//  DOSecureKeyContainer.h
//  DayOne
//
//  Created by Ben Dolman on 3/22/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DOSecureKeyContainer : NSObject {
@private
    NSString *passwordHint;
    NSData *salt;
    NSData *payload;
    NSDate *lastModDate;
}

// Designated initializer
- (id) initWithPayload:(NSData *)encryptedPayload 
                  salt:(NSData *)saltData
          passwordHint:(NSString *)hint 
           lastModDate:(NSDate *)date;

- (id) initWithPassword:(NSString *)password 
           passwordHint:(NSString *)hint 
             privateKey:(NSData *)keyData 
            lastModDate:(NSDate *)date;

- (id) initWithPassword:(NSString *)password 
           passwordHint:(NSString *)hint 
             privateKey:(NSData *)keyData;

- (id) initWithPropertyList:(id)plist;

- (id) propertyList;

- (BOOL) verifyPassword:(NSString *)testPassword;
- (BOOL) changePassword:(NSString *)oldPassword newPassword:(NSString *)newPassword newHint:(NSString *)newHint;
- (NSString *)passwordHint;
- (NSDate *)lastModDate;
- (NSData *)salt;
- (NSData *)decryptKeyWithPassword:(NSString *)password;

@end
