/*                                                                            
  Copyright (c) 2014-2015, GoBelieve     
    All rights reserved.		    				     			
 
  This source code is licensed under the BSD-style license found in the
  LICENSE file in the root directory of this source tree. An additional grant
  of patent rights can be found in the PATENTS file in the same directory.
*/

#import <Foundation/Foundation.h>
#import "IMessage.h"
#import "FileMessageDB.h"
#import "ConversationIterator.h"
#import "IMessageIterator.h"


@interface FilePeerMessageDB : FileMessageDB

+(FilePeerMessageDB*)instance;

@property(nonatomic, copy) NSString *dbPath;

-(id<IMessageIterator>)newMessageIterator:(int64_t)uid;
-(id<IMessageIterator>)newMessageIterator:(int64_t)uid last:(int)lastMsgID;
-(id<ConversationIterator>)newConversationIterator;

-(BOOL)insertMessage:(IMessage*)msg uid:(int64_t)uid;
-(BOOL)removeMessage:(int)msgLocalID uid:(int64_t)uid;
-(BOOL)clearConversation:(int64_t)uid;
-(BOOL)clear;
-(BOOL)acknowledgeMessage:(int)msgLocalID uid:(int64_t)uid;
-(BOOL)markMessageFailure:(int)msgLocalID uid:(int64_t)uid;
-(BOOL)markMesageListened:(int)msgLocalID uid:(int64_t)uid;
-(BOOL)eraseMessageFailure:(int)msgLocalID uid:(int64_t)uid;
@end
