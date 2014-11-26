//
//  DOUTTypes.h
//  DayOne
//
//  Created by Ben Dolman on 3/30/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/* ================================================================================ *
 *  Day One UTIs                                                                    *
 * ================================================================================ */
/*
 *  DOUTTypeJournal
 *
 *    Package file that contains entries.
 *
 *    UTI: com.dayoneapp.journal
 *    conforms to: com.apple.package, public.composite-content
 *
 *  DOUTTypeEntry
 *
 *    XML property list containing entry properties.
 *
 *    UTI: com.dayoneapp.entry
 *    conforms to:com.apple.xml-property-list
 *
 */
extern NSString * const DOUTTypeJournal;
extern NSString * const DOUTTypeEntry;