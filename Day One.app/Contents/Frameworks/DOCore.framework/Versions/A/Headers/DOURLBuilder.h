//
//  DOURLBuilder.h
//  DOCore
//
//  Created by Ben Dolman on 2/13/13.
//
//  Adapted from DDURLBuilder: https://github.com/davedelong/Demos/tree/master/DDURLBuilder
//

#import <Foundation/Foundation.h>

@interface DOURLBuilder : NSObject {
@private
    
    NSString *scheme;
    NSString *user;
    NSString *password;
    NSString *host;
    NSNumber *port;
    NSString *path;
    NSMutableDictionary *queryValues;
    NSString *fragment;
}

+ (id) URLBuilderWithURL:(NSURL *)url;
- (id) initWithURL:(NSURL *)url;

@property (nonatomic, retain) NSURL *URL;

@property (nonatomic, retain) NSString *scheme;
@property (nonatomic, retain) NSString *user;
@property (nonatomic, retain) NSString *password;
@property (nonatomic, retain) NSString *host;
@property (nonatomic, retain) NSNumber *port;
@property (nonatomic, retain) NSString *path;
@property (nonatomic, retain) NSString *fragment;

@property (nonatomic, assign) BOOL usesSchemeSeparators;

- (NSArray *) queryValuesForKey:(NSString *)key;
- (void) addQueryValue:(NSString *)value forKey:(NSString *)key;
- (void) removeQueryValue:(NSString *)value forKey:(NSString *)key;
- (void) removeQueryValuesForKey:(NSString *)key;

@end