#import "_DOShare.h"

typedef NS_ENUM(NSUInteger, DOShareApp) {
    DOShareAppDesktopBrowser,
    DOShareAppMobileBrowser,
    DOShareAppTwitter,
    DOShareAppTweetbot,
    DOShareAppTwitterrific,
    DOShareAppFoursquare
};

@interface DOShare : _DOShare {}

/**
 * Creates a URL appropriate for opening the share in an app. For example, for the Twitter app this
 * creates a URL like this: twitter://status?id=112344235235. 
 * 
 * @param app The app for which you want a URL
 * @return A URL you can use to open the share in an app
 */
- (NSURL *)linkURLForOpeningInApp:(DOShareApp)app;

@end
