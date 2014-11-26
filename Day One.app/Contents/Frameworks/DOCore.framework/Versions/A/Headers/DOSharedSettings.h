//
//  DOSharedSettings.h
//  DOCore
//
//  Created by Ben Dolman on 6/27/13.
//

#import <Foundation/Foundation.h>
#import "DOWeather.h"

/**
 * Settings that are stored in iCloud and shared between the Mac and iOS apps using NSUbiquitousKeyValueStore.
 * These properties are all KVO-compliant.
 *
 * You should always use the defaultSettings instance.
 *
 * DOSharedSettings is currently designed to be used only on the main thread.
 */
@interface DOSharedSettings : NSObject

/**
 * Always use this default instance
 */
+ (DOSharedSettings *)defaultSettings;

/**
 * The user's email address used for newsletter signup.
 */
@property (nonatomic, copy) NSString *emailAddress;

/**
 * The email address used for the user's Day One account.
 */
@property (nonatomic, copy) NSString *dayOneAccountEmailAddress;

/**
 * The date the user was last prompted to subscribe to the Day One newsletter.
 */
@property (nonatomic, strong) NSDate *lastPromptedForNewsletter;

/**
 * The date the user was last prompted to buy Day One for Mac.
 */
@property (nonatomic, strong) NSDate *lastPromptedForMacApp;

/**
 * The date a Day One Mac app (on any device) was last run. Returns nil if Day One has never run on Mac.
 * This value is updated by the Day One Mac app at launch.
 * 
 * NOTE: This began being recorded in Day One (Mac) v1.8
 */
@property (nonatomic, strong) NSDate *lastRunOnMac;

/**
 * The date a Day One iOS app (on any device) was last run. Returns nil if Day One has never run on iOS.
 * This value is updated by the Day One iOS app at launch.
 *
 * NOTE: This began being recorded in Day One (iOS) v1.11
 */
@property (nonatomic, strong) NSDate *lastRunOnIOS;

/**
 * The weather service that the weather manager should use.
 */
@property (nonatomic, copy) DOWeatherService defaultWeatherService;

/**
 * A unique identifier that we have assigned to this iCloud account. This is used to track
 * the same user across devices.
 */
@property (nonatomic, copy) NSString *distinctID;


@end
