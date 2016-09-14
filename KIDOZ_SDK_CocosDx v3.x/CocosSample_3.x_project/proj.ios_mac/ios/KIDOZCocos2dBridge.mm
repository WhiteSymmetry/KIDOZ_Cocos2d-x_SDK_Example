#include "KIDOZCocos2dBridge.h"
#include "cocos2d.h"
#import "UIKIT/UIKIT.h"

#import <KidozSDK/KIDOZSDK.h>
#import <KidozSDK/KIDOZUtils.h>





@interface KIDOZCocos2dObjectListners : NSObject <KIDOZFeedProtocol,KIDOZPanelProtocol>
{
    
}
//-(id)initWithContext:(FREContext) ctx;
@end



@implementation KIDOZCocos2dObjectListners





-(void) KIDOZFeedOpened:(int)feedID
{
    KIDOZCocos2dBridge::KIDOZFeedOpened(feedID);
}
-(void) KIDOZFeedClosed:(int)feedID
{
    KIDOZCocos2dBridge::KIDOZFeedClosed(feedID);
}
-(void) KIDOZFeedReady:(int)feedID
{
    KIDOZCocos2dBridge::KIDOZFeedReady(feedID);
}
-(void) KIDOZPanelOpened:(int)panelID
{
    KIDOZCocos2dBridge::KIDOZPanelOpened( panelID);
}
-(void) KIDOZPanelClosed:(int)panelID
{
    KIDOZCocos2dBridge::KIDOZPanelClosed(panelID);
}
-(void) KIDOZPanelReady:(int)panelID
{
    KIDOZCocos2dBridge::KIDOZPanelReady(panelID);
}
-(void) KIDOZPlayerStarted
{
    KIDOZCocos2dBridge::KIDOZPlayerStarted();
}
-(void) KIDOZPlayerEnded
{
    KIDOZCocos2dBridge::KIDOZPlayerEnded();
}
@end



KIDOZPanelObject *mCocos2dPanel;
KIDOZFeedObject *mCocos2dFeed;
KIDOZCocos2dObjectListners  *mCocos2dListnerObject;



int KIDOZCocos2dBridge::addFeedButton(float xPos, float yPos)
{
    
    CGRect rect = CGRectMake(xPos, yPos, 0, 0);
    
    mCocos2dFeed = [[KidozSDK instance]generateFeedButtonWithViewController:[[[UIApplication sharedApplication] keyWindow] rootViewController]  inFrame:rect delegate:mCocos2dListnerObject];
    [mCocos2dFeed retain];
    NSLog(@"oooOri Native in addFeedButton");
    return 0;
}

int KIDOZCocos2dBridge::addFeedButtonWithSize(float xPos, float yPos, float size)
{
    
    CGRect rect = CGRectMake(xPos, yPos, size, size);
    mCocos2dFeed = [[KidozSDK instance]generateFeedButtonWithViewController:[[[UIApplication sharedApplication] keyWindow] rootViewController]  inFrame:rect delegate:mCocos2dListnerObject];
    return 0;
}
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
int KIDOZCocos2dBridge::addPanelView(int panelPosition, int handlePosition){
    
    static UIViewController *rootView;

    dispatch_async(dispatch_get_main_queue(), ^{
    
        
        rootView = [[[UIApplication sharedApplication] keyWindow] rootViewController];
        
        mCocos2dPanel = [[KidozSDK instance]generatePanelWithViewController:rootView panelPosition:(KIDOZPanelPosition)panelPosition withHandlePosition:(KIDOZHandlePosition)handlePosition delegate:mCocos2dListnerObject];
        
        [mCocos2dPanel retain];
    });
    
    
    return 0;
}

int KIDOZCocos2dBridge::setPanelViewColor(char* colorString){
    
    
    
    NSString *colorIn = [NSString stringWithUTF8String:(char*)colorString];
    
//    UIColor *color = [KIDOZUtils getUIColorFromString:colorIn];
    
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
    [mCocos2dPanel expend];
    
    return 0;
}

bool KIDOZCocos2dBridge::isPanelExpanded()
{
    
    return NO;
}

void KIDOZCocos2dBridge::hidePanel(bool hide)
{
    
    [mCocos2dPanel hide:hide];
}
//------------------------
//------------------------
int KIDOZCocos2dBridge::addBannerView(){
    //oooOri todo: implement missing function
    return -1;
}

int KIDOZCocos2dBridge::changeBannerPosition(){
    //oooOri todo: implement missing function
    return -1;
}

int KIDOZCocos2dBridge::showBannerView(){
    //oooOri todo: implement missing function
    return -1;
}

int KIDOZCocos2dBridge::hideBannerView(){
    //oooOri todo: implement missing function
    return -1;
}

//------------------------
//------------------------
int KIDOZCocos2dBridge::addFlexiView(){
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

int KIDOZCocos2dBridge::getIsFlexiViewVisible(){
    //oooOri todo: implement missing function
    return -1;
}


int KIDOZCocos2dBridge::printToastLog(char *message)
{
    
    NSString *debugMsg = [NSString stringWithUTF8String:(char*)message];
    
    NSLog(@"KIDOZ SDK: %@",debugMsg);
    return 0;
}


int KIDOZCocos2dBridge::initSDK(char *pubID, char *secToken){
    
    
    NSString *publisherID = [NSString stringWithUTF8String:(char*)pubID];
    
    
    NSString *secureityToken = [NSString stringWithUTF8String:(char*)secToken];
    
    
    mCocos2dListnerObject = [[KIDOZCocos2dObjectListners alloc]init];
    [mCocos2dListnerObject retain];
//    [[KidozSDK instance]init:nil publisherID:publisherID securetyToken:secureityToken withDelegate:nil withExtensionType:@"Cocos2d"];
    [[KidozSDK instance]init:nil publisherID:publisherID securityToken:secureityToken withDelegate:nil withExtensionType:KIDOZ_EXTENSION_TYPE_COCOS_DX resourceInExternalBundle:YES];
    [KIDOZUtils setResourceInBundle:YES];
    return 0;
}

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
void KIDOZCocos2dBridge::setPlayerEndedListenerListener(KIDOZListener name)
{
    mPlayerEndedListener = name;
}

KIDOZListener mFeedOpenedListener;
KIDOZListener mFeedClosedListener;
KIDOZListener mFeedReadyListener;
KIDOZListener mPanelOpenedListener;
KIDOZListener mPanelClosedListener;
KIDOZListener mPanelReadyListener;
KIDOZListener mPlayerStartedListener;
KIDOZListener mPlayerEndedListener;

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

void KIDOZCocos2dBridge::KIDOZFeedOpened(int feedID)
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFeedOpenedListener != NULL)
    {
        g_KIDOZBridgeInstance->mFeedOpenedListener(feedID);
    }
}
void KIDOZCocos2dBridge::KIDOZFeedClosed(int feedID)
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFeedClosedListener != NULL)
    {
        g_KIDOZBridgeInstance->mFeedClosedListener(feedID);
    }
}
void KIDOZCocos2dBridge::KIDOZFeedReady(int feedID)
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mFeedReadyListener != NULL)
    {
        g_KIDOZBridgeInstance->mFeedReadyListener(feedID);
    }
}
void KIDOZCocos2dBridge::KIDOZPanelOpened(int feedID)
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mPanelOpenedListener != NULL)
    {
        g_KIDOZBridgeInstance->mPanelOpenedListener(feedID);
    }
}
void KIDOZCocos2dBridge::KIDOZPanelClosed(int feedID)
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mPanelClosedListener != NULL)
    {
        g_KIDOZBridgeInstance->mPanelClosedListener(feedID);
    }
}
void KIDOZCocos2dBridge::KIDOZPanelReady(int feedID)
{
    if (g_KIDOZBridgeInstance==NULL)
    {
        return;
    }
    
    if (g_KIDOZBridgeInstance->mPanelReadyListener != NULL)
    {
        g_KIDOZBridgeInstance->mPanelReadyListener(feedID);
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
        g_KIDOZBridgeInstance->mPlayerStartedListener(0);
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
        g_KIDOZBridgeInstance->mPlayerEndedListener(0);
    }
}



