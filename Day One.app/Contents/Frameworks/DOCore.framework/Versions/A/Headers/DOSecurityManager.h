//
//  DOSecurityManager.h
//  DayOne
//
//  Created by Ben Dolman on 3/21/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOSecureKeyContainer.h"

@interface DOSecurityManager : NSObject {
@private
    NSMutableDictionary *keyContainers;
    NSString *keyUUID;
}

+ (NSData *) generateRandomPrivateKey;

- (id) initWithPropertyList:(id)plist;
- (id) propertyList;

- (id) initWithSecurityFileURL:(NSURL *)fileURL;
- (BOOL) saveToFileURL:(NSURL *)fileURL error:(NSError **)error;

- (DOSecureKeyContainer *) masterContainer;
- (void) setMasterContainer:(DOSecureKeyContainer *)masterContainer;

- (NSString *)keyUUID;

@end
