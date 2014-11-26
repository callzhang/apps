//
//  NSMutableAttributedString+DOAdditions.h
//  DOCore
//
//  Created by Ben Dolman on 4/23/13.
//
//

#import "DOVersion.h"

@interface NSMutableAttributedString (DOAdditions)

// write-only properties, reading will return nil
@property (nonatomic, strong) id do_font;                          // NSFont or UIFont
@property (nonatomic, strong) id do_color;                         // NSColor or UIColor
@property (nonatomic, assign) NSTextAlignment do_alignment;        // Sets NSLineBreakByTruncatingTail for truncation.

- (NSRange)do_stringRange;
- (void)do_setFont:(id)font inRange:(NSRange)range;
- (void)do_setColor:(id)color inRange:(NSRange)range;
- (void)do_setAlignment:(NSTextAlignment)alignment lineBreakMode:(NSLineBreakMode)lineBreakMode;

@end
