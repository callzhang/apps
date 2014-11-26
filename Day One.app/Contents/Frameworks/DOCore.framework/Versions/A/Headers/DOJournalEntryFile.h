//
//  JournalEntryFile.h
//  DayOne
//
//  Created by Ben Dolman on 3/21/12.
//  Copyright (c) 2012 Bloom Built, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DOCreator.h"


@class DOJournalPackageFile;
@class DOWeather;
@class DOLocation;
@class DOMusic;


extern NSString * const DOEntryFileExtension;
extern NSString * const DOEntryFileDirectoryName;

extern NSString * const DOPhotoAttachmentName;
extern NSString * const DOPhotoAttachmentFileExtension;
extern NSString * const DOPhotoAttachmentDirectoryName;

extern NSString * const DOActivityStateStationary;
extern NSString * const DOActivityStateWalking;
extern NSString * const DOActivityStateRunning;
extern NSString * const DOActivityStateBiking;
extern NSString * const DOActivityStateEating;
extern NSString * const DOActivityStateAutomotive;
extern NSString * const DOActivityStateFlying;
extern NSString * const DOActivityStateTrain;




// Notification to be used when working around a file coordination error.
extern NSString * const DODidWorkAroundFileCoordinationReadingErrorNotification;

typedef BOOL(^DOFileDeleteBlock)(NSURL *fileURL, NSError **error);

enum {
    /* Files (entry properties, attachments) are only saved if their
     * affecting properties have been changed on the entry file object.*/
    DOJournalEntryFileSaveOptionOnlyIfDirty = 1 << 0
};
typedef NSUInteger DOJournalEntryFileSaveOptions;

@interface DOJournalEntryFile : NSObject {
	NSString *uuid;
	NSDate *creationDate;
	NSString *string;
	BOOL isStarred;
    DOJournalPackageFile *lastSaveJournalFile;
    NSMutableString *collapsedString;
    NSMutableDictionary *wrappers;
    NSMutableSet *dirtyFiles;
    NSDate *entryLastSaved;

    DOLocation *location;
    DOWeather *weather;
    NSTimeZone *timeZone;
    NSArray *tags;
    DOCreator *creator;
    DOMusic *music;
    NSInteger stepCount;
    BOOL ignoreStepCount;
    NSURL *publishURL;
}

@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, copy) NSDate *creationDate;
@property (nonatomic, copy) NSString *string;
@property (nonatomic, strong) DOJournalPackageFile *lastSaveJournalFile;
@property (nonatomic) BOOL isStarred;
@property (nonatomic, copy) DOLocation *location;
@property (nonatomic, strong) DOWeather *weather;
@property (nonatomic, copy) NSTimeZone *timeZone;
@property (nonatomic, copy) NSArray *tags;
@property (nonatomic, strong) DOCreator *creator;
@property (nonatomic, strong) DOMusic *music;
@property (nonatomic, strong) NSString *activity;
@property (nonatomic) NSInteger stepCount;
@property (nonatomic) BOOL ignoreStepCount;
@property (nonatomic, copy) NSURL *publishURL;


/**
 * Returns a new in-memory journal file. It does not exist on
 * disk until it is saved.
 */
+ (DOJournalEntryFile *)emptyJournalEntry;

/**
 * Reads a specific journal entry from a journal file on disk.
 */
+ (DOJournalEntryFile *)journalEntryByReadingEntry:(NSString *)entryID 
                                         inJournal:(DOJournalPackageFile *)journalFile 
                                             error:(NSError **)error 
                                  attachmentErrors:(NSDictionary **)errors;

/**
 * Removes an entry from a journal file on disk.
 */
+ (BOOL) removeEntry:(NSString *)entryID 
           inJournal:(DOJournalPackageFile *)journalFile 
               error:(NSError **)error 
    attachmentErrors:(NSDictionary **)errors;

/**
 * Removes an entry from a journal file on disk.
 * Allows the caller to specify the code to use for deletion in fileDeleteBlock.
 * This last param exists to allow OS X to move entries to the trash can instead
 * of permanently deleting them.
 */
+ (BOOL) removeEntry:(NSString *)entryID 
           inJournal:(DOJournalPackageFile *)journalFile 
               error:(NSError **)error 
    attachmentErrors:(NSDictionary **)errors
     fileDeleteBlock:(DOFileDeleteBlock)fileDeleteBlock;

/**
 * Returns the last modified date of an entry in a journal.
 * NOTE: This does not use file coordination
 */
+ (NSDate *) entryPropertiesLastModified:(NSString *)entryID inJournal:(DOJournalPackageFile *)journalFile;

/**
 * Returns the last modified date of an entry attachment in a journal.
 * NOTE: This does not use file coordination
 */
+ (NSDate *) entryAttachmentLastModified:(NSString *)entryID attachmentName:(NSString *)name inJournal:(DOJournalPackageFile *)journalFile;

/**
 * Returns YES if the specified entry exists in the journal file on disk.
 */
+ (BOOL) existsEntry:(NSString *)entryID inJournal:(DOJournalPackageFile *)journalFile;

/**
 * Reads a specific journal entry from a journal file on disk.
 */
- (id) initByReadingEntry:(NSString *)entryID 
                inJournal:(DOJournalPackageFile *)journalFile 
                    error:(NSError **)error 
         attachmentErrors:(NSDictionary **)errors;

/**
 * Resets the entry to the contents of an entry in a journal file.
 */
- (BOOL)revertByReadingEntry:(NSString *)entryID 
                   inJournal:(DOJournalPackageFile *)journalFile 
                       error:(NSError **)error 
            attachmentErrors:(NSDictionary **)errors;

/**
 * Rests the entry to the contents of the file to which it was last saved.
 * If the entry has not yet been saved this does nothing and returns YES.
 * This is a convenience wrapper around revertByReadingEntry.
 */
-(BOOL)revertToLastSavedAndReturnError:(NSError **)error 
                      attachmentErrors:(NSDictionary **)errors;

/**
 * Writes the entry and attachments to a journal.
 */
- (BOOL)saveToJournal:(DOJournalPackageFile *)journalFile
              options:(DOJournalEntryFileSaveOptions)options
                error:(NSError **)error
     attachmentErrors:(NSDictionary **)errors;

/**
 * This is a convenience method for saveToJournal:options:error:attachmentErrors
 * that passes 0 for the options argument.
 */
- (BOOL)saveToJournal:(DOJournalPackageFile *)journalFile
                error:(NSError **)error
     attachmentErrors:(NSDictionary **)errors;

/**
 * Returns the date the entry properties (everything but the attachments)
 * were last saved to disk. Returns nil if the properties have not been 
 * saved to disk yet.
 */
- (NSDate *)entryPropertiesLastSaved;

/**
 * Returns the date a particular attachment was last saved to disk.
 * Returns nil if the attachment does not exist or has not yet been saved to disk.
 */
- (NSDate *)entryAttachmentLastSaved:(NSString *)attachmentName;

/**
 * Returns the MD5 checksum (as a hex string) of the file to which the entry 
 * was last saved. If the entry has not yet been saved this returns nil.
 */
- (NSString *)lastSavedEntryFileChecksum;

/**
 * Returns a copy of entry string with all extra newlines between paragraphs
 * and trailing whitespace removed.
 */
- (NSString *)collapsedString;

- (NSUInteger)characterCount;
- (NSUInteger)wordCount;

/**
 * Returns an dictionary of file wrappers. The dictionary will be empty if
 * there are no attachments or the file does not support attachments.
 */
- (NSDictionary *)allAttachments;

/**
 * Returns the attachment with a given name.
 * Attachment names are specified as consts in this header file.
 */
- (NSFileWrapper *)attachmentNamed:(NSString *)name;

/**
 * Returns whether an attachment with a given name exists.
 * Attachment names are specified as consts in this header file.
 */
- (BOOL)hasAttachmentNamed:(NSString *)name;

/**
 * Creates, edits or deletes an attachment. Passing nil for the attachment
 * will cause the attachment to be deleted.
 * Changes are not written to the file system until the entry is saved.
 */
- (void)setAttachment:(NSFileWrapper *)attachment attachmentName:(NSString *)name;

/**
 * Convenience method for retrieving the underlying data of an attachment.
 * Will return nil if there is no attachment of that name.
 */
- (NSData *)contentOfAttachmentNamed:(NSString *)name;

/**
 * Convenience method for setting the data of an attachment.
 */
- (void)setContentOfAttachment:(NSData *)contents attachmentName:(NSString *)name;

/**
 * Returns a fully qualified file URL to the attachment.
 * Returns nil if the entry does not have the attachment or if it has
 * not yet been saved to disk.
 */
- (NSURL *)fileURLForAttachmentNamed:(NSString *)name;

/**
 * Returns a fully qualified file URL to the entry properties file.
 * Returns nil if the entry has not yet been saved to disk.
 */
- (NSURL *)fileURLForEntryProperties;

/**
 * Indicates whether the contents of this entry match those of another.
 * The contents of files are not compared; matching of files is based on file modification dates.
 * -[NSFileWrapper matchesContentsOfURL:] is used for the comparison.
 */
- (BOOL)matchesContentsOfEntry:(NSString *)entryID inJournal:(DOJournalPackageFile *)journalFile;

/**
 * Indicates whether this entry matches what's on disk at the last save
 * location. Returns NO if the entry hasn't yet been saved. This is a convenience
 * wrapper around matchesContentsOfEntry:inJournal:.
 */
- (BOOL)matchesLastSavedEntry;

/**
 * Returns YES if the entry properties or any attachments have been modified
 * on this object since the last save.
 */
- (BOOL)isDirty;

/**
 * Returns YES if the entry properties have been modified on this object
 * since the last save.
 */
- (BOOL)entryPropertiesAreDirty;

/**
 * Returns YES if the specified attachment has been modified on this object 
 * since the last save. If the attachment does not exist, returns NO.
 */
- (BOOL)attachmentIsDirty:(NSString *)attachmentName;

@end
