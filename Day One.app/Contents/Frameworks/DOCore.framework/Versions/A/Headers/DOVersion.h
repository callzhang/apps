//
//  DOFeatureAvailability.h
//  DayOne
//
//  Created by Ben Dolman on 3/21/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef TARGET_OSX
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#define TARGET_OSX 0
#define TARGET_IOS 1
#elif TARGET_OS_MAC && !TARGET_OS_IPHONE
#define TARGET_OSX 1
#define TARGET_IOS 0
#endif
#endif


#ifndef FILE_COORD_SUPPORTED
// Macro to determine if file coordination is supported
#define FILE_COORD_SUPPORTED (NSClassFromString(@"NSFileCoordinator") != nil)
#define FILE_COORD_CLASS NSClassFromString(@"NSFileCoordinator")
// Macro to determine if iCloud is supported on this OS
#define ICLOUD_SUPPORTED !TARGET_IPHONE_SIMULATOR && FILE_COORD_SUPPORTED
#endif

#if TARGET_OSX
// Function to determine if native full screen is supported on this OS
BOOL HasNativeFullScreenSupport();
#endif

#ifndef CFSafeRelease
#define CFSafeRelease( cfobj )                if ( cfobj != NULL )        CFRelease( cfobj );
#endif

/**
 * The product name and version, as set by the application.
 * Apps should set this as early in app launch as possible. If not set, these will
 * still always return non-nil defaults based on the current bundle or process.
 */
void DOSetProductName(NSString *productName);           // e.g. "Day One Mac"
void DOSetProductVersion(NSString *productVersion);     // e.g. "1.7.3"
void DOSetProductBuildNumber(NSString *buildNumber);    // e.g. "273"
NSString *DOProductName();
NSString *DOProductVersion();
NSString *DOProductBuildNumber();

/**
 * Various methods to simplify runtime OS version checking. The passed in version
 * should be of the form "10.8.3". These work on both iOS and OS X.
 */
BOOL DOOpSystemVersionEqualTo(NSString *v);
BOOL DOOpSystemVersionGreaterThan(NSString *v);
BOOL DOOpSystemVersionGreaterThanOrEqualTo(NSString *v);
BOOL DOOpSystemVersionLessThan(NSString *v);
BOOL DOOpSystemVersionLessThanOrEqualTo(NSString *v);

/**
 * Returns a string representing the system version (e.g. 10.8.3 on OS X, 6.1.1 on iOS)
 */
NSString *DOOpSystemVersion();

/**
 * Returns a string representing the operating system name. (Either "iOS" or "Mac OS X")
 */
NSString *DOOpSystemName();

/**
 * Returns a string representing the general device type.
 * E.g. Macintosh, iPhone, iPod touch, iPad
 */
NSString *DODeviceType();

/**
 * Returns a string representing the specific model of the device
 * E.g. MacBookPro10,1, iPad3,1
 */
NSString *DODeviceModel();

/**
 * Returns the user-specified host name
 * E.g. Ben Dolman's Macbook Pro
 */
NSString *DOHostName();

/**
 * Builds a string appropriate for a HTTP User-Agent header.
 * E.g. DayOneiOS/1.13 (en_US; iOS/6.1; iPad; iPad3,1; Debug/273)
 * 
 */
NSString *DOUserAgent();
