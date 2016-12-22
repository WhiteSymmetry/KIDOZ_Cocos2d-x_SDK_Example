//
//  KIDOZInterfaces.h
//  KidozSDK
//
//  Created by Ori Kam on 27/12/2015.
//  Copyright © 2015 kidoz. All rights reserved.
//

#ifndef KIDOZInterfaces_h
#define KIDOZInterfaces_h
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
@protocol KIDOZFeedProtocol <NSObject>

-(void) KIDOZFeedOpened:(int)feedID;
-(void) KIDOZFeedClosed:(int)feedID;
-(void) KIDOZFeedReady:(int)feedID;

@end

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
@protocol KIDOZPanelProtocol <NSObject>

-(void) KIDOZPanelOpened:(int)panelID;
-(void) KIDOZPanelClosed:(int)panelID;
-(void) KIDOZPanelReady:(int)panelID;
-(void) KIDOZPlayerStarted;
-(void) KIDOZPlayerEnded;
@end

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
@protocol KIDOZBannerProtocol <NSObject>

-(void) KIDOZBannerOpened:(int)panelID;
-(void) KIDOZBannerClosed:(int)panelID;
-(void) KIDOZBannerReady:(int)panelID;
-(void) KIDOZBannerPlayerStarted;
-(void) KIDOZBannerPlayerEnded;
@end

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
typedef enum PanelPosition
{
    ppBottom,
    ppTop,
    ppLeft,
    ppRight
    
    
}KIDOZPanelPosition;

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
@protocol KIDOZInterstitialProtocol <NSObject>

-(void) KIDOZInterstitialOpened:(int)interstitialID;
-(void) KIDOZInterstitialClosed:(int)interstitialID;
-(void) KIDOZInterstitialReady:(int)interstitialID;
-(void) KIDOZInterstitialLoadFailed:(int)interstitialID;
-(void) KIDOZInterstitialParentalLockOpend:(int)interstitialID;
-(void) KIDOZInterstitialOnRewarded;
-(void) KIDOZInterstitialonRewardedVideoStarted;
@end

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
typedef enum HandlePosition
{
    hpLeft,
    hpCenter,
    hpRight,
    hpNone
}KIDOZHandlePosition;

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
typedef enum OpenType
{
    otAutomatic,
    otManual
}KIDOZPanelOpenMode;
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
typedef enum BannerPosition
{
    bpTop = 0,
    bpBottom = 1,
    bpTopLeft = 2,
    bpTopRight = 3,
    bpBottomleft = 4,
    bpBottomRight = 5
}KIDOZBannerPosition;

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
typedef enum InterstitialMode
{
    imInterstitial = 0,
    imRewarded = 1
}KIDOZInterstitialMode;


//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
#define KIDOZ_SDK_INIT_DONE_LISTENER_ID @"KIDOZ_SDK_INIT_DONE"
#define KIDOZ_SDK_SHARED_RESOURCES_DONE_LOADING_LISTENER_ID @"KIDOZ_SDK_SHARED_RESOURCES_DONE_LOADING"
#define KIDOZ_SDK_FEED_RESOURCES_DONE_LOADING_LISTENER_ID @"KIDOZ_SDK_FEED_RESOURCES_DONE_LOADING"
#define KIDOZ_SDK_PANEL_RESOURCES_DONE_LOADING_LISTENER_ID @"KIDOZ_SDK_PANEL_RESOURCES_DONE_LOADING"
#define KIDOZ_SDK_BANNER_RESOURCES_DONE_LOADING_LISTENER_ID @"KIDOZ_SDK_BANNER_RESOURCES_DONE_LOADING"
#define KIDOZ_SDK_PLAYER_STARTED_LISTENER_ID @"KIDOZ_SDK_PLAYER_STARTED_LISTENER_ID"
#define KIDOZ_SDK_PLAYER_ENDED_LISTENER_ID @"KIDOZ_SDK_PLAYER_ENDED_LISTENER_ID"

//-----------------------------------------------------------------------
//-----------------------------------------------------------------------

typedef enum KIDOZExtensionType
{
    KIDOZ_EXTENSION_TYPE_ANDROID = 1,
    KIDOZ_EXTENSION_TYPE_ECLIPSE = 2,
    KIDOZ_EXTENSION_TYPE_COCOS_DX = 3,
    KIDOZ_EXTENSION_TYPE_ADOBE_AIR = 4,
    KIDOZ_EXTENSION_TYPE_UNITY = 5,
    KIDOZ_EXTENSION_TYPE_GMS = 6,
    KIDOZ_EXTENSION_TYPE_CORONA = 7,
    KIDOZ_EXTENSION_TYPE_XCODE = 8
}KIDOZExtensionType;



#endif /* KIDOZInterfaces_h */
