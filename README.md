<a href="url"><img src="https://github.com/Kidoz-SDK/Kidoz_Android_SDK_Example/blob/master/graphics/App%20icon.png" align="left" height="72" width="72" ></a>

KIDOZ SDK Cocos2Dx Sample App (android)
=======================================


### Including SDK in projects using CocosDx version 2.2.x

This Sample Application is Strickly based on the Original `SimpleGame` application that exists in the `samples` directory of `cocos2d-x-2.2.6`library. 

####Include the library (CocosDx 2.2.x)
On Eclipse ADT you can include the library by doing the folowing:

 - Import `KidozSDK` library project to your Eclipse workspace.
 - Import `recyclerview` library project to your Eclipse workspace.
 - Right click on your project select `Properties`,in appeared window select `Android`:
 - In the library section add KIDOZ SDK as a Library project.
 
  
### Including SDK in projects using CocosDx version 3.x

####Include the library  (CocosDx 3.x)
On Eclipse ADT you can include the library by doing the folowing:

 - Copy all `.jar` files form KidozSDK/libs folder to your_project/libs folder:
 - Copy all `.so`. files from KidozSDK/libs/armeabi folder to  your_project/libs/armeabi folder:
 - Import `recyclerview` library project to your Eclipse workspace.
 - Right click on your project select `Properties`,in appeared window select `Android` in the library section add `recyclerview` as a library project:
 
##### Sample application base on CocosDx 3.x download here:
 **https://s3.amazonaws.com/kidoz.test.bucket/CocosSample_3.x_project.zip**

####	Eclipse ADT

**How to use Kidoz SDK and it to Eclipse ADT please refer to https://github.com/Kidoz-SDK/KIDOZ_Android_SDK_Example-Eclipse-ADT **



KIDOZ SDK Cocos2Dx Sample App (iOS)
=======================================

### Sample App
The sample app can be found in the following directory: /KIDOZSample/proj.ios_mac

The app shows the feed button and the panel widget.


### Adding KIDOZ SDK to your app

1. Copy and add the KidozSDK.bundle and Kidoz.framework files to your project into the Frameworks section in xcode.
2. Select add files to the project while selecting the ios folder (make sure that the copy option is checked) and select the KIDOZCocos2dBridge.h and KIDOZCocos2dBridge.mm files.
3. In  AppDelegate.cpp add the following lines: <br>
```#include "KIDOZCocos2dBridge.h"``` <br>
Add the following functions calls to AppDelegate::applicationDidFinishLaunching()
 ```KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();```
```KIDOZBridge->initSDK(<your publisher id>,<security token>);```
4. In your app scene file (in the demo code HellowWorldScene.cpp add the following lines: according to your selected KIDOZ widgets. Add the following include file: #include "KIDOZCocos2dBridge.h"
5. ```KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();```
   For panel use: ```KIDOZBridge->addPanelView(<panel position>, <handle position>);```
   For feed button use" ```KIDOZBridge->addFeedButton(<x position>, <y position>);```
6. You can add listeners by calling ```KIDOZBridge->setPanelReadyListener(panelReady);```
7. Other listeners can be found in KIDOZCocos2dBridge.h file


