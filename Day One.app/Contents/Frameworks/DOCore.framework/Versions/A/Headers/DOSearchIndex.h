//
//  DOSearchIndex.h
//  DOCore
//
//  Created by Ben Dolman on 9/21/12.
//
//

#import <Foundation/Foundation.h>

@interface DOSearchIndex : NSObject

+(BOOL)prepareIndexAtFileURL:(NSURL *)fileURL error:(NSError **)outError;

+(NSString *)stringByAppendingPrefixCharToTokensInSearchString:(NSString *)searchString;
+(NSString *)stringByAppendingPrefixCharToCurrentTokenInSearchString:(NSString *)searchString
                                                          currentPos:(NSUInteger)currentPos;


@property (readonly, copy) NSURL *indexFileURL;


-(id)initWithIndexFileURL:(NSURL *)fileURL;

-(NSString *)snippetForEntryID:(NSString *)entryID
                  searchString:(NSString *)searchString
               highlightRanges:(NSArray **)ranges;

-(NSString *)snippetForEntryID:(NSString *)entryID
                  searchString:(NSString *)searchString
               highlightRanges:(NSArray **)highlightRanges
                 snippetLength:(NSInteger)snippetLength;

-(NSArray *)uuidsForSearchString:(NSString *)searchString;

-(BOOL)openAndReturnError:(NSError **)outError;
-(BOOL)closeAndReturnError:(NSError **)outError;

-(BOOL)updateEntryWithID:(NSString *)entryID entryText:(NSString *)entryText lastModified:(NSDate *)lastModified error:(NSError **)outError;
-(BOOL)deleteEntryWithID:(NSString *)entryID error:(NSError **)outError;

-(BOOL)optimizeAndReturnError:(NSError **)outError;

@end

@interface DOSearchIndexQueue : NSObject

@property (readonly, copy) NSURL *indexFileURL;

-(id)initWithIndexFileURL:(NSURL *)fileURL;
-(void)close;

- (void)inSearchIndex:(void (^)(DOSearchIndex *index))block;

@end