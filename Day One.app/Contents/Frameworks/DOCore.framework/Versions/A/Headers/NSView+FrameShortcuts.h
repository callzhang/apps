//
//  NSView+FrameShortcuts.h
//  DOCore
//
//  Created by Adam Kirk on 4/15/13.
//
//

#if (TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE)
#import <UIKit/UIKit.h>
#define View UIView
#else
#import <Foundation/Foundation.h>
#define View NSView
#endif

@interface View (FrameShortcuts)

@property (nonatomic) CGPoint origin;
@property (nonatomic) CGSize  size;
@property (nonatomic) CGFloat x;
@property (nonatomic) CGFloat y;
@property (nonatomic) CGFloat height;
@property (nonatomic) CGFloat width;

@end
