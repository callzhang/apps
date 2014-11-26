//
//  DOWebFile.h
//  DOCore
//
//  Created by Ben Dolman on 2/5/14.
//
//

#import <DOCore/DOCore.h>

@interface DOWebFile : DOWebObject <MTLManagedObjectSerializing>

@property (nonatomic, copy) NSString *fileID;
@property (nonatomic, copy) NSDictionary *imageMeta;

@end
