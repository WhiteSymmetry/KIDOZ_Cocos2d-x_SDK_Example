#ifndef __KIDOZCocos2dBrige__
#define __KIDOZCocos2dBrige__


typedef void (*KIDOZListener)(int value);




class KIDOZCocos2dBridge
{
private:
    
    KIDOZListener mFeedOpenedListener;
    KIDOZListener mFeedClosedListener;
    KIDOZListener mFeedReadyListener;
    KIDOZListener mPanelOpenedListener;
    KIDOZListener mPanelClosedListener;
    KIDOZListener mPanelReadyListener;
    KIDOZListener mPlayerStartedListener;
    KIDOZListener mPlayerEndedListener;

public:
    int addFeedButton(float xPos, float yPos);
    int addFeedButtonWithSize(float xPos, float yPos, float size);
    int showFeedView();
    
    int dismissFeedView();
    
    int changeFeedButtonVisibility(bool visable);
    
    //------------------------
    //------------------------
    int addPanelView(int panelPosition, int handlePosition);
    
    int setPanelViewColor(char* colorString);
    
    int changePanelVisibility(bool visable);
    
    int collapsePanelView();
    
    int expandPanelView();
    
    bool isPanelExpanded();
    //------------------------
    //------------------------
    int addBannerView();
    
    int changeBannerPosition();
    
    int showBannerView();
    
    int hideBannerView();
    
    //------------------------
    //------------------------
    int addFlexiView();
    
    int showFlexiView();
    
    int hideFlexiView();
    
    int getIsFlexiViewVisible();
    
    
    int printToastLog(char *message);
    
    
    int initSDK(char *pubID, char *secToken);
    
    //Listeners function
    void setFeedOpenedListener(KIDOZListener name);
    void setFeedClosedListener(KIDOZListener name);
    void setFeedReadyListener(KIDOZListener name);
    void setPanelOpenedListener(KIDOZListener name);
    void setPanelClosedListener(KIDOZListener name);
    void setPanelReadyListener(KIDOZListener name);
    void setPlayerStartedListener(KIDOZListener name);
    void setPlayerEndedListenerListener(KIDOZListener name);
    
        
    static KIDOZCocos2dBridge *getInstance();
    
    
    
    
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static void KIDOZFeedOpened(int feedID);
    static void KIDOZFeedClosed(int feedID);
    static void KIDOZFeedReady(int feedID);
    static void KIDOZPanelOpened(int feedID);
    static void KIDOZPanelClosed(int feedID);
    static void KIDOZPanelReady(int feedID);
    static void KIDOZPlayerStarted();
    static void KIDOZPlayerEnded();
};

#endif