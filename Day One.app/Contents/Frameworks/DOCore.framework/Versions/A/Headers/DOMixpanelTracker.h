//
//  MixpanelTracker.h
//  DayOne
//
//  Created by Ben Dolman on 9/30/13.
//  Copyright (c) 2013 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOJournalIndex.h"
#import "DOJournalEntryFile.h"
#import "DOWebEntry.h"

@protocol DOMixpanelTrackerDelegate;

// Keys used in the context dictionary of trackEntryCreate:context:
extern NSString * const DOMixpanelTrackerEntryContextEditTimeKey;     // NSNumber, integral seconds
extern NSString * const DOMixpanelTrackerEntryContextFromAgentKey;    // NSNumber, bool
extern NSString * const DOMixpanelTrackerEntryContextFromReminderKey; // NSNumber, bool

@interface DOMixpanelTracker : NSObject

/**
 * Returns YES unless tracking has been disabled. Defaults to YES.
 */
+ (BOOL)trackingEnabled;

/**
 * Enables or disables tracking. By default, tracking is enabled. Disabling tracking will make every
 * tracking call to any instance of DOMixpanelTracker a no-op.
 */
+ (void)setTrackingEnabled:(BOOL)trackingEnabled;



/**
 * Delegate that supplies app-specific metrics to the tracker. The delegate methods
 * are only invoked when updatePeopleStatsUsingJournalIndex: is called.
 */
@property (nonatomic, strong) id<DOMixpanelTrackerDelegate> delegate;

/**
 * Initializes and returns a singleton instance of the tracker.
 */
+ (DOMixpanelTracker *)sharedInstance;

/**
 * Call this to update the stats for the current user.
 */
- (void)updatePeopleStatsUsingJournalIndex:(DOJournalIndex *)journalIndex;

/**
 * Tracks entry creation. Only call this when an entry is first created.
 * Extra contextual information can be included using the keys defined in this header.
 */
- (void)trackEntryCreate:(DOJournalEntryFile *)entryFile context:(NSDictionary *)context;

/**
 * Tracks entry publishing. Only call this when an entry is first published.
 */
- (void)trackEntryPublish:(DOWebEntry *)publishedEntry;

/**
 * Tracks the launch of the app. Should only be called once per app launch.
 */
- (void)trackAppLaunch;

typedef NS_ENUM(int16_t, DOAppRatingResult) {
    DOAppRatingResultDeclined,
    DOAppRatingResultPostponed,
    DOAppRatingResultAccepted
};

/**
 * Tracks the user response to rating requests.
 */
- (void)trackAppRatingRequestResult:(DOAppRatingResult)result;

@end

typedef NS_ENUM(int16_t, DOSyncMethod) {
    DOSyncMethodNone,
    DOSyncMethodDropbox,
    DOSyncMethodICloud
};

@protocol DOMixpanelTrackerDelegate <NSObject>
@required

- (DOSyncMethod)mixpanelTrackerAppSyncMethod:(DOMixpanelTracker *)tracker;
- (BOOL)mixpanelTrackerAppPasswordEnabled:(DOMixpanelTracker *)tracker;
- (BOOL)mixpanelTrackerAppMarkdownEnabled:(DOMixpanelTracker *)tracker;
- (BOOL)mixpanelTrackerAppRemindersEnabled:(DOMixpanelTracker *)tracker;
- (NSCalendarUnit)mixpanelTrackerAppReminderInterval:(DOMixpanelTracker *)tracker;
- (NSString *)mixpanelTrackerAppFontName:(DOMixpanelTracker *)tracker;
- (NSNumber *)mixpanelTrackerAppFontSize:(DOMixpanelTracker *)tracker;

@optional

- (BOOL)mixpanelTrackerAppAgentEnabled:(DOMixpanelTracker *)tracker;

/**
 * This is called whenever the tracker will track data. It is mostly intended just for use
 * by unit tests.
 */
- (void)mixpanelTracker:(DOMixpanelTracker *)tracker willTrack:(BOOL)willTrack;

@end