#include "HelloWorldScene.h"
#include "KIDOZCocos2dBridge.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label);

    
    
    
    
    KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();
    KIDOZBridge->setPanelReadyListener(panelReady);
    KIDOZBridge->setInterstitialReadyListener(interstitialReady);
    KIDOZBridge->addPanelView(KIDOZCocos2dBridge::PANEL_TYPE_BOTTOM, KIDOZCocos2dBridge::PANEL_HANDLE_CENTER);
    KIDOZBridge->addFeedButton(0, 0);
    KIDOZCocos2dBridge::getInstance()->loadInterstitial(KIDOZCocos2dBridge::InterstitialAdType::AD_TYPE_INTERSTIAL, false);
    
    
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    KIDOZBridge->addFlexiView(KIDOZCocos2dBridge::FlexiPosition::FLEXI_POSITION_TOP_END,true);
#endif
    
    
    
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::panelReady()
{
    printf("panel ready c++");
    KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();
   
}


void HelloWorld::interstitialReady()
{
    printf("interstitial ready c++");
    KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();
    KIDOZBridge->showInterstitial();
}

