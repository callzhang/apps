//
//  NSFileManager+FileNameSequence.h
//  DayOne
//
//  Created by Leonty Deriglazov on 04/12/2012.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (FileNameSequence)

- (NSString *)do_nextFileNameWithPrefix:(NSString *)prefix inDirectory:(NSString *)dirPath;

@end
