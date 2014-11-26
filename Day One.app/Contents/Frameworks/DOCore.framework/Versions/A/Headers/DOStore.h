//
//  DOStore.h
//  DOCore
//
//  Created by Ben Dolman on 6/18/13.
//
//  Facilitates the purchasing of Day One premium subscriptions using In-App Purchase.

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
#import "DOWebClient.h"

extern NSString * const DOStoreProductSubscription1Month;
extern NSString * const DOStoreProductSubscription1Year;

@interface DOStore : NSObject <SKProductsRequestDelegate, SKPaymentTransactionObserver>

- (instancetype)initWithClient:(DOWebClient *)client;

/**
 * This should be called so that the store can register itself as a StoreKit observer and process any outstanding transactions.
 */
- (void)prepareStore;

/**
 * Gets the product catalog. The keys in the dictionary will be those defined in this header
 * file (e.g. DOStoreProductSubscription1Month, DOStoreProductSubscription1Year). The values will
 * be SKProduct objects.
 */
- (void)fetchProductCatalog:(void (^)(NSDictionary *products))success failure:(void (^)(NSError *error))failure;

/**
 * Performs the purchase of a product. After successful purchase this method automatically uploads the receipt
 * to the server using [DOWebClient sharedClient]; make sure DOWebClient is properly authenticated before calling
 * this.
 */
- (void)purchaseProduct:(SKProduct *)product success:(void (^)(void))success failure:(void (^)(NSError *error))failure;

@end
