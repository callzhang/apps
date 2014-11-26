//
//  DOWebPublishPreviewURLProtocol.h
//  DOCore
//
//  Created by Ben Dolman on 1/28/14.
//
//

#import <Foundation/Foundation.h>

/**
 * Register this protocol before loading the preview HTML from -[DOWebClient previewHTMLForEntry...]
 * This class intercepts requests to the font server and adds a header that is required.
 * You should unregister the class when you are finished loading the preview.
 */
@interface DOWebPublishPreviewURLProtocol : NSURLProtocol
@end
