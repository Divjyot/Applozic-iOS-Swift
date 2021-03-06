//
//  ALChatViewController.h
//  ChatApp
//
//  Copyright (c) 2015 AppLozic. All rights reserved.
//
#import "ALMapViewController.h"
#import <UIKit/UIKit.h>
#import "ALMessage.h"
#import "ALBaseViewController.h"
#import <CoreLocation/CoreLocation.h>
#import "DB_CONTACT.h"
#import "ALContact.h"
#import "ALChatCell.h"
#import "ALUserDetail.h"
#import "ALMessageArrayWrapper.h"
#import "ALChannelDBService.h"
#import "ALChannel.h"
#import "ALAudioCell.h"
#import "ALAudioAttachmentViewController.h"

@protocol ALChatViewControllerDelegate <NSObject>

-(void)handleCustomActionFromChatVC:(UIViewController *)chatViewController andWithMessage:(ALMessage *)alMessage;

@end

@interface ALChatViewController : ALBaseViewController<UITableViewDataSource,UITableViewDelegate,UIActionSheetDelegate,UIImagePickerControllerDelegate,UINavigationControllerDelegate,ALMapViewControllerDelegate,ALChatCellDelegate>

@property (strong, nonatomic) ALContact * alContact;
@property (nonatomic, strong) ALChannel * alChannel;
@property (strong, nonatomic) ALMessageArrayWrapper * alMessageWrapper;
@property (strong, nonatomic) NSMutableArray * mMessageListArrayKeyStrings;
@property (strong, nonatomic) NSString * contactIds;
@property (nonatomic, strong) NSNumber * channelKey;
@property (nonatomic, strong) NSString * channelName;
@property (nonatomic, strong) NSNumber * conversationId;
@property (nonatomic) BOOL refreshMainView;
@property (nonatomic) BOOL refresh;
@property (strong, nonatomic) NSString * displayName;

@property (strong, nonatomic) NSString * text;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *tableViewBottomToAttachment;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *tableViewTop2Constraint;

@property (strong, nonatomic) id <ALChatViewControllerDelegate> chatViewDelegate;

-(void)fetchAndRefresh;
-(void)fetchAndRefresh:(BOOL)flag;

-(void)updateDeliveryReport:(NSString*)key withStatus:(int)status;
-(void)updateStatusReportForConversation:(int)status;
-(void)individualNotificationhandler:(NSNotification *) notification;

-(void)updateDeliveryStatus:(NSNotification *) notification;

//-(void) syncCall:(NSString *) contactId updateUI:(NSNumber *) updateUI alertValue: (NSString *) alertValue;
-(void) syncCall:(ALMessage *) alMessage andMessageList:(NSMutableArray*)messageArray;
-(void)showTypingLabel:(BOOL)flag userId:(NSString *)userId;

-(void) updateLastSeenAtStatus: (ALUserDetail *) alUserDetail;
-(void) reloadViewfor3rdParty;
-(void) reloadView;

-(void)markConversationRead;
-(void)markSingleMessageRead:(ALMessage *)almessage;

-(void)handleNotification:(UIGestureRecognizer*)gestureRecognizer;

-(void)googleImage:(UIImage*)staticImage withURL:(NSString *)googleMapUrl withCompletion:(void(^)(NSString *message, NSError *error))completion;

-(void) syncCall:(ALMessage*)AlMessage  updateUI:(NSNumber *)updateUI alertValue: (NSString *)alertValue;
-(void)serverCallForLastSeen;
-(void)processLoadEarlierMessages:(BOOL)isScrollToBottom;
-(NSString*)formatDateTime:(ALUserDetail*)alUserDetail  andValue:(double)value;
-(void)checkUserBlockStatus;

@end
