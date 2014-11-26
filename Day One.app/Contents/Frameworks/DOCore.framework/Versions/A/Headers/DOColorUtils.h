//
//  DOColorUtils.h
//  DOCore
//
//  Created by Ben Dolman on 3/22/13.
//  Copyright (c) 2013 Bloom Built, LLC. All rights reserved.
//


#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
#import <UIKit/UIKit.h>
#define Color UIColor
#else
#import <Foundation/Foundation.h>
#define Color NSColor
#endif


Color *RGBA(NSInteger r, NSInteger g, NSInteger b, CGFloat a);
Color *RGB(NSInteger r, NSInteger g, NSInteger b);
Color *RGBAHex(NSUInteger hex, CGFloat a);
Color *RGBHex(NSUInteger hex);
