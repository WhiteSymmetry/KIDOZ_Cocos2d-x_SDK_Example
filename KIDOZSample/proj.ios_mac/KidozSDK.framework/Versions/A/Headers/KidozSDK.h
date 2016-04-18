//
//  KidozSDK.h
//  KidozSDK
//
//  Created by Ori Kam on 25/10/2015.
//  Copyright © 2015 kidoz. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>
#import "KIDOZInterfaces.h"



/*
 Description:
 the panel object is generated using the generatePanel function, and should not be created manualy

 */
@interface KIDOZPanelObject : NSObject <KIDOZPanelProtocol>
-(id)initWithPanel:(id)panel;
-(id)initWithViewController:(UIViewController *)targetView panelPosition:(KIDOZPanelPosition) panelPosition withHandlePosition:(KIDOZHandlePosition)handlePosition delegate:(id<KIDOZPanelProtocol>)delegate;
-(id)initWithViewController:(UIViewController *)targetView panelPosition:(KIDOZPanelPosition) panelPosition withHandlePosition:(KIDOZHandlePosition)handlePosition delegate:(id<KIDOZPanelProtocol>)delegate  openDelay:(float)openDelay openDuration:(float)openDuration;
/*
 Description:
 Hides the panel including the panel handler.
 
 Parameters:
 BOOL       - YES the panel is hidden. NO the panel is visable.
 */
-(void)hide:(BOOL)hide;
/*
 Description:
 Expend the panel programmatically

 */
-(void)expend;
/*
 Description:
 collapse the panel programmatically
 
 */
-(void)collapse;

/*
 Description:
 returns if the panel is open
 
 */
-(BOOL)getIsPanelExpanded;
@end


//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
/*
 Description:
 the feed object is generated using the generateFeedButtonWithViewController function, and should not be created manualy
 
 */
@interface KIDOZFeedObject : NSObject
-(id)initWithFeed:(id)feed;
-(id)initWithViewController:(UIViewController *)targetView inFrame:(CGRect) frame delegate:(id<KIDOZFeedProtocol>)delegate;
-(void)hide:(BOOL)hide;
/*
 Description:
 Hides the feed button.
 
 Parameters:
 BOOL       - YES the button is hidden. NO the button is visable.
 */
-(void)hideButton:(BOOL)hide;
/*
 Description:
 open the the feed view programmatically.
 
 */
-(void)open;
/*
 Description:
 close the the feed view programmatically
 
 */
-(void)close;
@end

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
@protocol KIDOZSDKProtocol <NSObject>

-(void)KIDOZFeedReady;
-(void)KIDOZPanelReady;

@end

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
@interface KidozSDK : NSObject
{
    UIButton *mFeedButton;
    UIView *mView;
    UIWindow *mWindow;
    NSString *mPublisherID;
    NSString *mSecuretyToken;
    
    
}


+ (KidozSDK *)instance;

/*
 Description:
 Init function must be called before any other SDK function.
 This function should be called from the appdelegate module.
 
 Parameters:
 UIWindow           - the app window
 NSString           - the publisher ID
 NSString           - the securety token
 KIDOZSDKProtocol   - delegate for general SDK notifications
 
 */
-(void) init:(UIWindow *)window publisherID:(NSString *)publisherID securetyToken:(NSString *)securetyToken withDelegate:(id<KIDOZSDKProtocol>)delegate;


/*
 Description:
 Init function must be called before any other SDK function.
 This function should be called from the appdelegate module.
 
 Parameters:
 UIWindow           - the app window
 NSString           - the publisher ID
 NSString           - the securety token
 KIDOZSDKProtocol   - delegate for general SDK notifications
 NSString           - the extension name
 */
-(void) init:(UIWindow *)window publisherID:(NSString *)publisherID securetyToken:(NSString *)securetyToken withDelegate:(id<KIDOZSDKProtocol>)delegate withExtensionType:(NSString *)extensionType;

/*
Description:
 Generate a feed object on top of the targetviewController in the seleced frame.
 The feed is controlled using the object.
 
 Parameters:
 UIViewController   - the targetViewController
 CGRect             - the position and size for the feed button. In case the width and height are equals to 0 then we use the default size.
 KIDOZFeedProtocol  - the delegate to receive the feed notifications. 
 
 */
-(KIDOZFeedObject *) generateFeedButtonWithViewController:(UIViewController *)targetView inFrame:(CGRect) frame delegate:(id<KIDOZFeedProtocol>)delegate;

/*
 Description:
 Generate a panel object on top of the targetviewController in the seleced frame.
 The panel is controlled using the object.
 
 Parameters:
 UIViewController       - the targetViewController
 KIDOZPanelPosition     - the position of the panel relative to screen (possibel values ppTop,ppBottom,ppRight,ppLeft)
 KIDOZHandlePosition    - the panel handler position (left/top side, center/middle, right/bottom)
 KIDOZPanelProtocol     - the delegate to receive the panel notifications.
 
 */
-(KIDOZPanelObject *) generatePanelWithViewController:(UIViewController *)targetView panelPosition:(KIDOZPanelPosition) panelPosition withHandlePosition:(KIDOZHandlePosition)handlePosition delegate:(id<KIDOZPanelProtocol>)delegate;


/*
 Description:
 Generate a panel object on top of the targetviewController in the seleced frame.
 The panel is controlled using the object.
 
 Parameters:
 UIViewController       - the targetViewController
 KIDOZPanelPosition     - the position of the panel relative to screen (possibel values ppTop,ppBottom,ppRight,ppLeft)
 KIDOZHandlePosition    - the panel handler position (left/top side, center/middle, right/bottom)
 KIDOZPanelProtocol     - the delegate to receive the panel notifications.
 float                  - the time in seconds to wait before auto opening the panel.
 float                  - the duration in seconds to keep the panel open.
 */
-(KIDOZPanelObject *) generatePanelWithViewController:(UIViewController *)targetView panelPosition:(KIDOZPanelPosition) panelPosition withHandlePosition:(KIDOZHandlePosition)handlePosition delegate:(id<KIDOZPanelProtocol>)delegate  openDelay:(float)openDelay openDuration:(float)openDuration;

@end




