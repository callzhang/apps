//
//  DOTextRenderer.h
//  DOCore
//
//  Created by Ben Dolman on 9/3/12.
//
//

#import <Foundation/Foundation.h>

typedef enum {
    DOTextRenderOptionMarkdown                 = 1 << 0,
    DOTextRenderOptionAutoBoldTitle            = 1 << 1,
    DOTextRenderOptionAutoEmbedMedia           = 1 << 2,
    DOTextRenderOptionAutoLinkTwitterNames     = 1 << 3,
    DOTextRenderOptionAutoLinkHashtags         = 1 << 4,
} DOTextRenderOptions;

@interface DOTextRenderer : NSObject

- (id) initWithOptions:(DOTextRenderOptions)options;

- (NSString *)renderToHTML:(NSString *)plaintext;


// Utils
+ (NSString *)entryTitleExtractedFromEntryText:(NSString *)entryText;
+ (NSString *)entryBodyExtractedFromEntryText:(NSString *)entryText;

@end
