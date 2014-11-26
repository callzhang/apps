//
//  DOExportHTMLGenerator.h
//  DOCore
//
//  Created by Leonty Deriglazov on 27/03/2013.
//
//

#import <Foundation/Foundation.h>
#import "DOWeatherFormatter.h"

// Returns YES iff operation should be interrupted
typedef BOOL(^DOPDFExportCancellationBlock)(void);
typedef void(^DOPDFExportHTMLCompletionBlock)(NSString *html);

@class DOJournalIndex;
@class DOTextRenderer;

@interface DOExportHTMLGenerator : NSObject

// Returns a proper html generator for current platform
+ (DOExportHTMLGenerator *)htmlGeneratorWithJournalIndex:(DOJournalIndex *)journalIndex
                                            textRenderer:(DOTextRenderer *)textRenderer
                                        weatherFormatter:(DOWeatherFormatter *)weatherFormatter;

- (void)generateHTMLForEntryIDs:(NSArray *)entryIds
          withCancellationBlock:(DOPDFExportCancellationBlock)cancellationBlock
             andCompletionBlock:(DOPDFExportHTMLCompletionBlock)completionBlock;

@end
