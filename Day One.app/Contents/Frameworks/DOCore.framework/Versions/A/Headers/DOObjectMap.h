//
//  DOObjectMap.h
//  DOCore
//
//  Created by Ben Dolman on 5/15/13.
//
//  Maps the properties from one object to another object using KVC.
//
//  You create a map and then add individual mappings to instruct the
//  map how to convert each property.

#import <Foundation/Foundation.h>

@interface DOObjectMap : NSObject

/**
 * Convenience methods for adding a set of mappings that don't require
 * transformations. The key is the sourceKey, the value is the destKey.
 * The key and value must be strings.
 */
+ (id)mapWithDictionary:(NSDictionary *)dict;
- (id)initWithDictionary:(NSDictionary *)dict;

/**
 * Adds a mapping to instruct how to convert from a source property
 * to a destination property when -mapObject is called. The transform block
 * provides a way to modify the source property value before it's set
 * on the destination (e.g. convert a string to a date).
 */
- (void)addMappingForSourceKey:(NSString *)sourceKey
                     toDestKey:(NSString *)destKey
            withTransformBlock:(id (^)(id value))transformBlock;

/**
 * Removes an individual mapping.
 */
- (void)removeMappingForSourceKey:(NSString *)sourceKey toDestKey:(NSString *)destKey;

/**
 * Removes all mappings.
 */
- (void)removeAllMappings;

/**
 * Performs the mapping operation using the mapping instructions previously
 * defined with addMappingForSourceKey.
 */
- (void)mapObject:(id)sourceObj toObject:(id)destObj;

/**
 * Perform the mapping operation with the option to disable transforms.
 */
- (void)mapObject:(id)sourceObj toObject:(id)destObj performTransforms:(BOOL)transforms;

/**
 * Builds a new map object that reverses the source and destination mappings.
 * NOTE: The new object map does not have any transformations.
 */
- (DOObjectMap *)reverseMap;

@end

@interface DOObjectMap (Convenience)

/**
 * A convenience method for when you want to use an NSValueTransformer.
 * This method simply creates a transform block that wraps the calls to the named NSValueTransformer.
 */
- (void)addMappingForSourceKey:(NSString *)sourceKey
                     toDestKey:(NSString *)destKey
          withTransformerNamed:(NSString *)transformerName
                 usingReversed:(BOOL)reversed;


/**
 * A convenience method for mapping nested objects. You would use this when the property
 * itself contains an object that needs to be mapped. This method creates a transform block
 * that creates a new destClass object and then maps values from source to that new object.
 *
 * NOTE: If the source object is nil at mapping time then the dest object will also be nil
 *       (i.e. no instance of destClass will be created).
 */
- (void)addMappingForSourceKey:(NSString *)sourceKey
                     toDestKey:(NSString *)destKey
                     destClass:(Class)destClass
                      usingMap:(DOObjectMap *)map;

/**
 * A convenience method for mapping an array of objects that themselves need to be transformed.
 * The destination must be an NSArray. The source object would usually be an NSArray but any object
 * that conforms to NSFastEnumeration will work.
 *
 * This method creates a transform block that creates a new array, then creates an instance of
 * destClass for each item in the source array. Each item in the source array is then mapped
 * to the destination object using the specified map and inserted into the new array.
 *
 * NOTE: If the source property is nil the dest object will also be set to nil.
 */
- (void)addMappingForArraySourceKey:(NSString *)sourceKey
                     toArrayDestKey:(NSString *)destKey
                          destClass:(Class)destClass
                           usingMap:(DOObjectMap *)map;

@end