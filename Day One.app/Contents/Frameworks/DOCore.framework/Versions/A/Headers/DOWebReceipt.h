//
//  DOWebReceipt.h
//  DOCore
//
//  Created by Ben Dolman on 6/19/13.
//
//

#import "DOWebObject.h"

// Values of the store property
extern NSString *const DOWebReceiptStoreMacAppStore;
extern NSString *const DOWebReceiptStoreIOSAppStore;

// Values of the format property
extern NSString *const DOWebReceiptFormatOpaque;
extern NSString *const DOWebReceiptFormatPKCS7;

@interface DOWebReceipt : DOWebObject

/**
 * Returns DOWebReceiptStoreMacAppStore on OS X, DOWebReceiptStoreIOSAppStore on iOS
 */
+ (NSString *)currentAppStore;

@property (nonatomic, copy) NSString *store;
@property (nonatomic, copy) NSString *format;
@property (nonatomic, copy) NSData *data;

@end
