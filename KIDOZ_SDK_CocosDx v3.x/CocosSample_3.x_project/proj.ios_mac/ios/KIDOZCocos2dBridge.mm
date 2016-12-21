#include "KIDOZCocos2dBridge.h"
#include "cocos2d.h"
#import "UIKIT/UIKIT.h"

#import <KidozSDK/KIDOZSDK.h>
#import <KidozSDK/KIDOZUtils.h>




///////////////////////////////////////////////
#pragma label --callback object from objective c to c++ --

@interface KIDOZCocos2dObjectListners : NSObject <KIDOZFeedProtocol,KIDOZPanelProtocol,KIDOZInterstitialProtocol>
{
    
}
//-(id)initWithContext:(FREContext) ctx;
@end



@implementation KIDOZCocos2dObjectListners





-(void) KIDOZFeedOpened:(int)feedID
{
    KIDOZCocos2dBridge::KIDOZFeedOpened();
}
-(void) KIDOZFeedClosed:(int)feedID
{
    KIDOZCocos2dBridge::KIDOZFeedClosed();
}
-(void) KIDOZFeedReady:(int)feedID
{
    KIDOZCocos2dBridge::KIDOZFeedReady();
}
-(void) KIDOZPanelOpened:(int)panelID
{
    KIDOZCocos2dBridge::KIDOZPanelOpened( );
}
-(void) KIDOZPanelClosed:(int)panelID
{
    KIDOZCocos2dBridge::KIDOZPanelClosed();
}
-(void) KIDOZPanelReady:(int)panelID
{
    KIDOZCocos2dBridge::KIDOZPanelReady();
}
-(void) KIDOZPlayerStarted
{
    KIDOZCocos2dBridge::KIDOZPlayerStarted();
}
-(void) KIDOZPlayerEnded
{
    KIDOZCocos2dBridge::KIDOZPlayerEnded();
    
}

-(void) KIDOZInterstitialOpened:(int)interstitialID
{
    KIDOZCocos2dBridge::KIDOZInterstitialOpened();
}

-(void) KIDOZInterstitialClosed:(int)interstitialID
{
    KIDOZCocos2dBridge::KIDOZInterstitialClosed();
}

-(void) KIDOZInterstitialReady:(int)interstitialID
{
    KIDOZCocos2dBridge::KIDOZInterstitialReady();
}

-(void) KIDOZInterstitialLoadFailed:(int)interstitialID
{
    KIDOZCocos2dBridge::KIDOZInterstitialLoadFailed();
}


-(void) KIDOZInterstitialOnRewarded
{
    KIDOZCocos2dBridge::KIDOZInterstitialRewardedEvent();
}

-(void) KIDOZInterstitialonRewardedVideoStarted
{
    KIDOZCocos2dBridge::KIDOZInterstitialRewardedVideoStarted();
}



@end



KIDOZPanelObject *mCocos2dPanel;
KIDOZInterstitialObject *mCocos2dInterstitial;
KIDOZFeedObject *mCocos2dFeed;
KIDOZCocos2dObjectListners  *mCocos2dListnerObject;

///////////////////////////////////////////////
#pragma label --callback c++ object function implementions --


int KIDOZCocos2dBridge::addFeedButton(float xPos, float yPos)
{
    
    CGRect rect = CGRectMake(xPos, yPos, 0, 0);
    
    mCocos2dFeed = [[KidozSDK instance]generateFeedButtonWithViewController:[[[UIApplication sharedApplication] keyWindow] rootViewController]  inFrame:rect delegate:mCocos2dListnerObject];
    [mCocos2dFeed retain];
    NSLog(@"oooOri Native in addFeedButton");
    
    return 0;
}

//void KIDOZCocos2dBridge::addFeedButtonWithSize(float xPos, float yPos, float size)
//{
//    
//    CGRect rect = CGRectMake(xPos, yPos, size, size);
//    mCocos2dFeed = [[KidozSDK instance]generateFeedButtonWithViewController:[[[UIApplication sharedApplication] keyWindow] rootViewController]  inFrame:rect delegate:mCocos2dListnerObject];
//}
int KIDOZCocos2dBridge::showFeedView()
{
    [mCocos2dFeed open];
    return 0;

}

int KIDOZCocos2dBridge::dismissFeedView()
{
    [mCocos2dFeed close];
    return 0;

}

int KIDOZCocos2dBridge::changeFeedButtonVisibility(bool visable)
{
   
    [mCocos2dFeed hideButton:visable];
    return 0;
}

//------------------------
//------------------------
int KIDOZCocos2dBridge::addPanelView(PanelType panelPosition, PanelHandlePosition handlePosition){
    
    static UIViewController *rootView;

    dispatch_async(dispatch_get_main_queue(), ^{
    
        
        rootView = [[[UIApplication sharedApplication] keyWindow] rootViewController];
        
        mCocos2dPanel = [[KidozSDK instance]generatePanelWithViewController:rootView panelPosition:(KIDOZPanelPosition)panelPosition withHandlePosition:(KIDOZHandlePosition)handlePosition delegate:mCocos2dListnerObject];
        
        [mCocos2dPanel retain];
    });
    return 0;
}



int KIDOZCocos2dBridge::changePanelVisibility(bool visable){
    
    [mCocos2dPanel hide:visable];
    return 0;
}

int KIDOZCocos2dBridge::collapsePanelView()
{
    [mCocos2dPanel collapse];
    
    return 0;
}

int KIDOZCocos2dBridge::expandPanelView()
{
    [mCocos2dPanel expand];
    
    return 0;
}

bool KIDOZCocos2dBridge::getIsPanelExpanded()
{
    
    return NO;
}


//------------------------
//------------------------

//------------------------
//------------------------
int KIDOZCocos2dBridge::addFlexiView(FlexiPosition initialPosition, bool autoShow)
{
    //oooOri todo: implement missing function
    return -1;
}

int KIDOZCocos2dBridge::showFlexiView(){
    //oooOri todo: implement missing function
    return -1;
}

int KIDOZCocos2dBridge::hideFlexiView(){
    //oooOri todo: implement missing function
    return -1;
}

bool KIDOZCocos2dBridge::getIsFlexiViewVisible(){
    //oooOri todo: implement missing function
    return -1;
}



//------------------------
//------------------------
int KIDOZCocos2dBridge::loadInterstitial(InterstitialAdType ad_type, bool autoShowOnLoad)
{
    
    [mCocos2dInterstitial loadAdWithType:(KIDOZInterstitialMode)(ad_type)];
//    if (mInterstitial.isReady == YES)
//    {
//        [mInterstitial showOnParentViewController:self withDelegate:self];
//    }
//    else
//    {
//        
//        [mInterstitial loadAdWithType:imRewarded];
//    }

    return 0;
}

int KIDOZCocos2dBridge::showInterstitial()
{
    [mCocos2dInterstitial showOnParentViewController:[[[UIApplication sharedApplication] keyWindow] rootViewController] withDelegate:mCocos2dListnerObject];
    return 0;
}

bool KIDOZCocos2dBridge::getIsInterstitialLoaded()
{
    return NO;
}

//------------------------
//------------------------
void showVideoUnit()
{
    
}


void KIDOZCocos2dBridge::printToastLog(char *message)
{
    
    NSString *debugMsg = [NSString stringWithUTF8String:(char*)message];
    
    NSLog(@"KIDOZ SDK: %@",debugMsg);
    
}

int KIDOZCocos2dBridge::initSDK(char *pubID, char *secToken){
    
    
    NSString *publisherID = [NSString stringWithUTF8String:(char*)pubID];
    
    
    NSString *secureityToken = [NSString stringWithUTF8String:(char*)secToken];
    
    
    mCocos2dListnerObject = [[KIDOZCocos2dObjectListners alloc]init];
    [mCocos2dListnerObject retain];
//    [[KidozSDK instance]init:nil publisherID:publisherID securetyToken:secureityToken withDelegate:nil withExtensionType:@"Cocos2d"];
    [[KidozSDK instance]init:nil publisherID:publisherID securityToken:secureityToken withDelegate:nil withExtensionType:KIDOZ_EXTENSION_TYPE_COCOS_DX resourceInExternalBundle:YES];
    [KIDOZUtils setResourceInBundle:YES];
    
    static UIViewController *rootView;
    
    rootView = [[[UIApplication sharedApplication] keyWindow] rootViewController];
    
    mCocos2dInterstitial = [[KidozSDK instance]generateInterstitialWithViewController:rootView delegate:mCocos2dListnerObject];
    
    [mCocos2dInterstitial retain];
    
//    dispatch_async(dispatch_get_main_queue(), ^{
//        
//        
//        rootView = [[[UIApplication sharedApplication] keyWindow] rootViewController];
//        
//        mCocos2dInterstitial = [[KidozSDK instance]generateInterstitialWithViewController:rootView delegate:mCocos2dListnerObject];
//        
//        [mCocos2dInterstitial retain];
//    });
    
    
    return 0;
}

///////////////////////////////////////////////
#pragma label --listeners setting--
void KIDOZCocos2dBridge::setFeedOpenedListener(KIDOZListener name)
{
    mFeedOpenedListener = name;
}
void KIDOZCocos2dBridge::setFeedClosedListener(KIDOZListener name)
{
    mFeedClosedListener = name;
}
void KIDOZCocos2dBridge::setFeedReadyListener(KIDOZListener name)
{
    mFeedReadyListener = name;
}
void KIDOZCocos2dBridge::setPanelOpenedListener(KIDOZListener name)
{
    mPanelOpenedListener = name;
}
void KIDOZCocos2dBridge::setPanelClosedListener(KIDOZListener name)
{
    mPanelClosedListener = name;
}
void KIDOZCocos2dBridge::setPanelReadyListener(KIDOZListener name)
{
    mPanelReadyListener = name;
}
void KIDOZCocos2dBridge::setPlayerStartedListener(KIDOZListener name)
{
    mPlayerStartedListener = name;
}
void KIDOZCocos2dBridge::setPlayerEndedListener(KIDOZListener name)
{
    mPlayerEndedListener = name;
}

void KIDOZCocos2dBridge::setFlexiViewReadyListener(KIDOZListener name)
{
    mFlexiViewReadyListener = name;
}

void KIDOZCocos2dBridge::setFlexiViewVisibleListener(KIDOZListener name)
{
    mFlexiViewVisibleListener = name;
}

void KIDOZCocos2dBridge::setFlexiViewHiddenListener(KIDOZListener name)
{
    mFlexiViewHiddenListener = name;
}

void KIDOZCocos2dBridge::setInterstitialOpenedListener(KIDOZListener name)
{
    mInterstitialOpenedListener = name;
}

void KIDOZCocos2dBridge::setInterstitialClosedListener(KIDOZListener name)
{
    mInterstitialClosedListener = name;
}

void KIDOZCocos2dBridge::setInterstitialReadyListener(KIDOZListener name)
{
    mInterstitialReadyListener = name;
}

void KIDOZCocos2dBridge::setInterstitialLoadFailedListener(KIDOZListener name)
{
    mInterstitialLoadFailedListener = name;
}

void KIDOZCocos2dBridge::setInterstitialRewardedVideoStartedListener(KIDOZListener name)
{
    mInterstitialRewardedVideoStartedListener = name;
}

void KIDOZCocos2dBridge::setInterstitialRewardedEventListener(KIDOZListener name)
{
    mInterstitialRewardedEventListener = name;
}

void KIDOZCocos2dBridge::setVideoUnitOpenListener(KIDOZListener name)
{
    mVideoUnitOpenListener = name;
}

void KIDOZCocos2dBridge::setVideoUnitCloseListener(KIDOZListener name)
{
    mVideoUnitCloseListener = name;
}

void KIDOZCocos2dBridge::setVideoUnitReadyListener(KIDOZListener name)
{
    mVideoUnitReadyListener = name;
}




///////////////////////////////////////////////
#pragma label --function declaration setting--
// not used defined in h file
//KIDOZListener mFeedOpenedListener;
//KIDOZListener mFeedClosedListener;
//KIDOZListener mFeedReadyListener;
//KIDOZListener mPanelOpenedListener;
//KIDOZListener mPanelClosedListener;
//KIDOZListener mPanelReadyListener;
//KIDOZListener mPlayerStartedListener;
//KIDOZListener mPlayerEndedListener;

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
static KIDOZCocos2dBridge *g_KIDOZBridgeInstance= NULL;

KIDOZCocos2dBridge *KIDOZCocos2dBridge::getInstance()
{
    if (g_KIDOZBridgeInstance != NULL) {
        return g_KIDOZBridgeInstance;
    }
    g_KIDOZBridgeInstance = new KIDOZCocos2dBridge();
    return g_KIDOZBridgeInstance;
}


///////////////////////////////////////////////
#pragma label --callback c++ object function implementions --

void KIDOZCocos2dBridge::KIDOZFeedOpened()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFeedOpenedListener != NULL)
    {
        g_KIDOZBridgeInstance->mFeedOpenedListener();
    }
}
void KIDOZCocos2dBridge::KIDOZFeedClosed()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFeedClosedListener != NULL)
    {
        g_KIDOZBridgeInstance->mFeedClosedListener();
    }
}
void KIDOZCocos2dBridge::KIDOZFeedReady()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFeedReadyListener != NULL)
    {
        g_KIDOZBridgeInstance->mFeedReadyListener();
    }
}
void KIDOZCocos2dBridge::KIDOZPanelOpened()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mPanelOpenedListener != NULL)
    {
        g_KIDOZBridgeInstance->mPanelOpenedListener();
    }
}
void KIDOZCocos2dBridge::KIDOZPanelClosed()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mPanelClosedListener != NULL)
    {
        g_KIDOZBridgeInstance->mPanelClosedListener();
    }
}
void KIDOZCocos2dBridge::KIDOZPanelReady()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mPanelReadyListener != NULL)
    {
        g_KIDOZBridgeInstance->mPanelReadyListener();
    }
}
void KIDOZCocos2dBridge::KIDOZPlayerStarted()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mPlayerStartedListener != NULL)
    {
        g_KIDOZBridgeInstance->mPlayerStartedListener();
    }
}
void KIDOZCocos2dBridge::KIDOZPlayerEnded()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mPlayerEndedListener != NULL)
    {
        g_KIDOZBridgeInstance->mPlayerEndedListener();
    }
}

void KIDOZCocos2dBridge::KIDOZFlexiViewReady()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFlexiViewReadyListener != NULL)
    {
        g_KIDOZBridgeInstance->mPlayerEndedListener();
    }
}

void KIDOZCocos2dBridge::KIDOZFlexiViewVisible()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFlexiViewVisibleListener != NULL)
    {
        g_KIDOZBridgeInstance->mFlexiViewVisibleListener();
    }
}

void KIDOZCocos2dBridge::KIDOZFlexiViewHidden()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFlexiViewHiddenListener != NULL)
    {
        g_KIDOZBridgeInstance->mFlexiViewHiddenListener();
    }
}



void KIDOZCocos2dBridge::KIDOZInterstitialOpened()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mInterstitialOpenedListener != NULL)
    {
        g_KIDOZBridgeInstance->mInterstitialOpenedListener();
    }
}

void KIDOZCocos2dBridge::KIDOZInterstitialClosed()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mInterstitialClosedListener != NULL)
    {
        g_KIDOZBridgeInstance->mInterstitialClosedListener();
    }
}


void KIDOZCocos2dBridge::KIDOZInterstitialReady()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mInterstitialReadyListener != NULL)
    {
        g_KIDOZBridgeInstance->mInterstitialReadyListener();
    }
}

void KIDOZCocos2dBridge::KIDOZInterstitialLoadFailed()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mInterstitialLoadFailedListener != NULL)
    {
        g_KIDOZBridgeInstance->mInterstitialLoadFailedListener();
    }
}

void KIDOZCocos2dBridge::KIDOZInterstitialRewardedVideoStarted()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mInterstitialRewardedVideoStartedListener != NULL)
    {
        g_KIDOZBridgeInstance->mInterstitialRewardedVideoStartedListener();
    }
}

void KIDOZCocos2dBridge::KIDOZInterstitialRewardedEvent()
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mInterstitialRewardedEventListener != NULL)
    {
        g_KIDOZBridgeInstance->mInterstitialRewardedEventListener();
    }
}




