//
//  DOMapped.h
//  DOCore
//
//  Created by Ben Dolman on 6/3/13.
//
//  DOMapped is a protocol that can facilitate the mapping of model objects by coupling the
//  the instructions for mapping to the class itself. A conforming class implements both importMap
//  and exportMap. Mapping can then be performed using DOMappedImport and DOMappedExport instead of
//  having to deal with the maps directly.
//
//  IMPORTANT: DOMapped conforming classes should be able to be instantiated using `init`. This allows
//             them to be used with DOMappedImport and DOMappedExport.
//

#import <Foundation/Foundation.h>
#import "DOObjectMap.h"

@protocol DOMapped <NSObject>

@required

/**
 * Returns the map that is used to map values from another object to this object
 */
+ (DOObjectMap *)importMap;

/**
 * Returns the map that is used to map values from this object to another object.
 */
+ (DOObjectMap *)exportMap;

@end

/**
 * Simplifies the common use case of mapping into a new instance of a DOMapped object.
 *
 * fromObj can be any KVC-compatible object.
 * toClass must be a class that implements the DOMapped protocol and can be instantiated with `init`.
 * 
 * A new instance of toClass will be created, then fromObj will be mapped to the new instance using toClass's importMap.
 *
 * NOTE: If fromObj is nil then nil will be returned.
 */
id DOMappedImport(id fromObj, Class<DOMapped> toMappedClass);

/**
 * Simplifies the common use case of mapping out of a DOMapped object into an instance of a new class.
 *
 * fromObj must be an object that implements the DOMapped protocol.
 * toClass can be any KVC-compatible class that can be instantiated with `init`.
 *
 * A new instance of toClass will be created, then fromObj will be mapped to the new instance using fromObj's exportMap.
 *
 * NOTE: If fromObj is nil then nil will be returned.
 */
id DOMappedExport(id<DOMapped> fromMappedObj, Class toClass);