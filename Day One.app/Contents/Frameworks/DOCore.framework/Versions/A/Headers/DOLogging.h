//
//  DOLogging.h
//  DayOne
//
//  Created by Ben Dolman on 3/21/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef DLog
    #if defined(DAYONE_DEBUG) || defined(DEBUG)
        #define DLog(...) NSLog(__VA_ARGS__)
        #define ALog(...) [[NSAssertionHandler currentHandler] handleFailureInFunction:[NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding] file:[NSString stringWithCString:__FILE__ encoding:NSUTF8StringEncoding] lineNumber:__LINE__ description:__VA_ARGS__]
    #else
        #define DLog(...) do { } while (0)
        #ifndef NS_BLOCK_ASSERTIONS
        #define NS_BLOCK_ASSERTIONS
        #endif
        #define ALog(...) NSLog(@"%s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__])
    #endif

    #define ZAssert(condition, ...) do { if (!(condition)) { ALog(__VA_ARGS__); }} while(0)
#endif