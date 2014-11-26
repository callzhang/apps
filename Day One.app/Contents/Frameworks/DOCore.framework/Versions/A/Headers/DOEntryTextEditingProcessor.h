//
//  DOEntryTextEditingProcessor.h
//  DOCore
//
//  Created by BJ Homer on 5/23/13.
//
//

#import <Foundation/Foundation.h>

@interface DOTextEditingResult : NSObject
@property (nonatomic, strong) NSString *fullEditedText;
@property (nonatomic, assign) NSRange selectionRange;
@property (nonatomic, assign) NSRange editedRange;
@property (nonatomic, strong) NSString *replacementText;
@end


/**
 * The entry text editing processor handles our custom text editing behavior in
 * journal entries. Specifically, it handles things like automatic list insertion
 * and tabbing to indent a list.
 * 
 * You will generally use it in a textview delegate's -shouldChangeTextInRange:
 * method. The main interface is -editingResultForOldText:editedRange:replacementText:,
 * which returns a DOTextEditingResult describing what changes, if any, should be made.
 * See the documentation on that method for more information.
 *
 **/
@interface DOEntryTextEditingProcessor : NSObject


/**
 * Quickly determines whether there is a possibility of the processor providing custom
 * behavior for a given replacement string. If not, the caller can avoid asking the
 * text view for the full text, a potentially memory-intensive operation to be doing
 * on every keypress.
 * 
 * If this method returns YES, you should call -editingResultForOldText:editedRange:replacementText:
 * to determine what, if any, changes are required.
 **/
- (BOOL)wantsToProcessReplacementText:(NSString *)replacementText;


/**
 * Call this from within a text view delegate's -textView:shouldChangeTextInRange: method to
 * determine if we have any custom behavior implemented for that operation.
 * 
 * This method only returns a DOTextEditingResult object if it requests custom behavior.
 * If the default editing behavior is correct (i.e. "accept the change as proposed"),
 * the return value will be nil. The -textView:shouldChangeTextInRange: method should return
 * YES
 *
 * If the return value is not nil, the result object will contain the editing operation
 * that should be performed. This includes both the text changes that should be made and
 * the new range that should be selected in the UI. You should perform these changes,
 * and then return NO from -textView:shouldChangeTextInRange:.
 **/
- (DOTextEditingResult *)editingResultForOldText:(NSString *)oldText
                                     editedRange:(NSRange)editedRange
                                 replacementText:(NSString *)replacementText;

@end
