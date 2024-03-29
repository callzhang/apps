//
//  DOByteCountFormatter.h
//  DOCore
//
//  Created by Ben Dolman on 10/1/12.
//
//

#import <Foundation/Foundation.h>

typedef enum {
    // Specifies display of file or storage byte counts. The actual behavior for this is platform-specific; on OS X 10.8, this uses the decimal style, but that may change over time.
    DOByteCountFormatterCountStyleFile   = 0,
    // Specifies display of memory byte counts. The actual behavior for this is platform-specific; on OS X 10.8, this uses the binary style, but that may change over time.
    DOByteCountFormatterCountStyleMemory = 1,
    // The following two allow specifying the number of bytes for KB explicitly. It's better to use one of the above values in most cases.
    DOByteCountFormatterCountStyleDecimal = 2,    // 1000 bytes are shown as 1 KB
    DOByteCountFormatterCountStyleBinary  = 3     // 1024 bytes are shown as 1 KB
} DOByteCountFormatterCountStyle;

@interface DOByteCountFormatter : NSFormatter

@property DOByteCountFormatterCountStyle countStyle;

+ (NSString *)stringFromByteCount:(long long)byteCount countStyle:(DOByteCountFormatterCountStyle)countStyle;

- (NSString *)stringFromByteCount:(long long)byteCount;

@end
