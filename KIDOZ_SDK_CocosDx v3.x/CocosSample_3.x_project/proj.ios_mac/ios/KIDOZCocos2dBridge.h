#ifndef __KIDOZCocos2dBridge__
#define __KIDOZCocos2dBridge__

typedef void (*KIDOZListener)();

class KIDOZCocos2dBridge {
    
public:
    enum PanelType {
        PANEL_TYPE_BOTTOM = 0, PANEL_TYPE_TOP = 1
    };
    
    enum PanelHandlePosition {
        PANEL_HANDLE_START = 0,
        PANEL_HANDLE_CENTER = 1,
        PANEL_HANDLE_END = 2,
        PANEL_HANDLE_NONE = 3
    };
    
    enum InterstitialAdType {
        AD_TYPE_INTERSTIAL = 0,
        AD_TYPE_REWARDED = 1
    };
    
    enum FlexiPosition {
        FLEXI_POSITION_TOP_START = 0,
        FLEXI_POSITION_TOP_CENTER = 1,
        FLEXI_POSITION_TOP_END = 2,
        FLEXI_POSITION_MID_START = 3,
        FLEXI_POSITION_MID_CENTER = 4,
        FLEXI_POSITION_MID_END = 5,
        FLEXI_POSITION_BOTTOM_START = 6,
        FLEXI_POSITION_BOTTOM_CENTER = 7,
        FLEXI_POSITION_BOTTOM_END = 8
    };
    
    struct InnerType {
        enum EventInnerType {
            FEED_CLOSE_EVENT = 0,
            FEED_OPEN_EVENT = 1,
            FEED_READY_EVENT = 2,
            PANEL_OPENED_EVENT = 3,
            PANEL_CLOSED_EVENT = 4,
            PANEL_READY_EVENT = 5,
            PLAYER_OPEN_EVENT = 6,
            PLAYER_CLOSE_EVENT = 7,
            FLEXI_READY_EVENT = 8,
            FLEXI_VISIBLE_EVENT = 9,
            FLEXI_HIDDEN_EVENT = 10,
            INTERSTITIAL_OPENED_EVEN = 11,
            INTERSTITIAL_CLOSED_EVEN = 12,
            INTERSTITIAL_READY_EVEN = 13,
            INTERSTITIAL_FAILED_EVEN = 14,
            INTERSTITIAL_REWARDED_EVEN = 15,
            INTERSTITIAL_REWARDED_VIDEO_START_EVEN = 16,
            VIDEO_UNIT_READY_EVEN = 17,
            VIDEO_UNIT_OPEN_EVEN = 18,
            VIDEO_UNIT_CLOSE_EVEN = 19
        };
    };
    
private:
    
public:
    
    static void KIDOZFeedOpened();
    static void KIDOZFeedClosed();
    static void KIDOZFeedReady();
    static void KIDOZPanelOpened();
    static void KIDOZPanelClosed();
    static void KIDOZPanelReady();
    static void KIDOZPlayerStarted();
    static void KIDOZPlayerEnded();
    static void KIDOZFlexiViewReady();
    static void KIDOZFlexiViewVisible();
    static void KIDOZFlexiViewHidden();
    static void KIDOZInterstitialOpened();
    static void KIDOZInterstitialClosed();
    static void KIDOZInterstitialReady();
    static void KIDOZInterstitialLoadFailed();
    static void KIDOZInterstitialRewardedVideoStarted();
    static void KIDOZInterstitialRewardedEvent();
    static void KIDOZVideoUnitOpen();
    static void KIDOZVideoUnitClose();
    static void KIDOZVideoUnitReady();
    
    KIDOZListener mFeedOpenedListener;
    KIDOZListener mFeedClosedListener;
    KIDOZListener mFeedReadyListener;
    KIDOZListener mPanelOpenedListener;
    KIDOZListener mPanelClosedListener;
    KIDOZListener mPanelReadyListener;
    KIDOZListener mPlayerStartedListener;
    KIDOZListener mPlayerEndedListener;
    KIDOZListener mFlexiViewReadyListener;
    KIDOZListener mFlexiViewVisibleListener;
    KIDOZListener mFlexiViewHiddenListener;
    KIDOZListener mInterstitialOpenedListener;
    KIDOZListener mInterstitialClosedListener;
    KIDOZListener mInterstitialReadyListener;
    KIDOZListener mInterstitialLoadFailedListener;
    KIDOZListener mInterstitialRewardedVideoStartedListener;
    KIDOZListener mInterstitialRewardedEventListener;
    KIDOZListener mVideoUnitOpenListener;
    KIDOZListener mVideoUnitCloseListener;
    KIDOZListener mVideoUnitReadyListener;
    
    static KIDOZCocos2dBridge *getInstance();
    static void releaseResources();
    
    int initSDK(char *pubID, char *secToken);
    
    //------------------------
    //------------------------
    int addFeedButton(float xPos, float yPos);
    
    int showFeedView();
    
    int dismissFeedView();
    
    int changeFeedButtonVisibility(bool visible);
    
    //------------------------
    //------------------------
    int addPanelView(PanelType panelType, PanelHandlePosition handlePosition);
    
    int changePanelVisibility(bool visable);
    
    int collapsePanelView();
    
    int expandPanelView();
    
    bool getIsPanelExpanded();
    
    //------------------------
    //------------------------
    int addFlexiView(FlexiPosition initialPosition, bool autoShow);
    
    int showFlexiView();
    
    int hideFlexiView();
    
    bool getIsFlexiViewVisible();
    
    void printToastLog(char *message);
    
    //------------------------
    //------------------------
    int loadInterstitial(InterstitialAdType ad_type, bool autoShowOnLoad);
    
    int showInterstitial();
    
    bool getIsInterstitialLoaded();
    
    //------------------------
    //------------------------
    int showVideoUnit();
    
    
    void setFeedOpenedListener(KIDOZListener name);
    void setFeedClosedListener(KIDOZListener name);
    void setFeedReadyListener(KIDOZListener name);
    void setPanelOpenedListener(KIDOZListener name);
    void setPanelClosedListener(KIDOZListener name);
    void setPanelReadyListener(KIDOZListener name);
    void setPlayerStartedListener(KIDOZListener name);
    void setPlayerEndedListener(KIDOZListener name);
    void setFlexiViewReadyListener(KIDOZListener name);
    void setFlexiViewVisibleListener(KIDOZListener name);
    void setFlexiViewHiddenListener(KIDOZListener name);
    void setInterstitialOpenedListener(KIDOZListener name);
    void setInterstitialClosedListener(KIDOZListener name);
    void setInterstitialReadyListener(KIDOZListener name);
    void setInterstitialLoadFailedListener(KIDOZListener name);
    void setInterstitialRewardedVideoStartedListener(KIDOZListener name);
    void setInterstitialRewardedEventListener(KIDOZListener name);
    void setVideoUnitOpenListener(KIDOZListener name);
    void setVideoUnitCloseListener(KIDOZListener name);
    void setVideoUnitReadyListener(KIDOZListener name);
};

#endif

