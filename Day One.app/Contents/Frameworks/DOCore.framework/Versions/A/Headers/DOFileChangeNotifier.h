//
//  DOFileChangeNotifier.h
//  DOCore
//
//  Created by Ben Dolman on 7/30/12.
//
//

#import <Foundation/Foundation.h>

typedef void(^DOFileChangeNotifyBlock)(NSArray *);

@protocol DOFileChangeNotifier <NSObject>
@required
@property (copy, readonly) DOFileChangeNotifyBlock notifyBlock;
@property (copy, readonly) NSURL *rootFileURL;

-(id)initWithRootFileURL:(NSURL *)rootFileURL notifyBlock:(DOFileChangeNotifyBlock)notifyBlock;

-(void)startWatching;
-(void)stopWatching;

@end
