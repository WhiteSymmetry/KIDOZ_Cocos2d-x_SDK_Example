<a href="url"><img src="https://github.com/Kidoz-SDK/Kidoz_Android_SDK_Example/blob/master/graphics/App%20icon.png" align="left" height="72" width="72" ></a>
[<img src="https://kidoz-cdn.s3.amazonaws.com/wordpress/kidoz_small.gif" width="533px" height="300px">](https://www.youtube.com/watch?v=-ljFjRn7jeM)
KIDOZ SDK + Sample App
=======================================

**KIDOZ SDK and Sample App are compatible with Android 4.0 (API level 14) and above.**
**KIDOZ SDK and Sample App are compatible iOS version 8.2 and above.**

*Updated to KIDOZ SDK (Android) version 0.7.2* 
*Updated to KIDOZ SDK (iOS) version 0.5.7* 

## Include Kidoz SDK (Android) library in your projects For android build(v0.7.1)

On Eclipse ADT you can include the library by doing the following:

* Copy from folder `KIDOZ_SDK_Android/lib` all .JAR files into your android project `lib` folder
* Copy from folder/s `KIDOZ_SDK_Android/lib/armeabi` `libpl_droidsonroids_gif.so` file into your android project `lib/armeabi or/and ` ib/armeabi-v7a (Important! MAke sure the file exisits when compiling final .APK)
* Copy from folder `KIDOZ_SDK_Android` `KIDOZCocos2dBridge.cpp` file into your project `jni`
* Copy from folder `KIDOZ_SDK_Android` `KIDOZCocos2dBridge.h` file into your project cpp game code. `(KIDOZCocos2dBridge.h` is single for IOS and Android)
</br>
<img src="https://s3.amazonaws.com/kidoz-cdn/sdk/GitHub_Tutorial_Img/cocos_tuturoial_image_1.JPG" width="230px" height="420px">
 </br>
 
Add `KIDOZCocos2dBridge.cpp` to compilation source files in` Android.mk` file
 
Example:
```groovy
	LOCAL_SRC_FILES := hellocpp/main.cpp \
	 hellocpp/KIDOZCocos2dBridge.cpp \
         ../../Classes/AppDelegate.cpp \
         ../../Classes/HelloWorldScene.cpp
``` 
 
In Your `Activity` that extends from `Cocos2dxActivity` in `onCreate` method put the folowing line:

```groovy
  // Initiate Kidoz SDK
  KidozSDKCocosDxBridge.init(this);
``` 
Example
```groovy

 public class YourActivity extends Cocos2dxActivity {
  	 protected void onCreate(Bundle savedInstanceState) {
	       super.onCreate(savedInstanceState);

               //Initiate Kidoz SDK bridge
	       KidozSDKCocosDxBridge.init(this);
    }
 }
``` 
##### Update AndroidMainifest.xml file Definitions (IMPORTANT)
For correct flow of the SDK, add the following line in your `AndroidMainifest.xml` file, for each `YourActivity` that uses the SDK functionality.
```groovy
 android:configChanges="screenLayout|screenSize|orientation|keyboardHidden|keyboard"
``` 

Also add the following permissions:

```xml
 <uses-permission android:name="android.permission.INTERNET" />
 
 <!-- android:maxSdkVersion="19" is used to AVOID permission handling in Android 6.0 and above  -->  
 <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" android:maxSdkVersion="19"/>
 
``` 

###### NOTICE!!!
In case external SD access is needed and requiered to apply/handle `Android 6.0` Permissions request flow,
add `WRITE_EXTERNAL_STORAGE` permission in the following format in your application `AndroidMainifest.xml` file:

```xml
 <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE"  tools:node="replace"/>
 <!--  tools:node="replace" is used to replace default libray defenition--> 
``` 
To use `tools:node="replace"` add `xmlns:tools="http://schemas.android.com/tools"` in the `<manifest ...  >` tag of `AndroidMainifest.xml` file. 
 
 Also add the following lines in the `<Application> ... </Application>` tag of the `AndroidMainifest.xml` file
```xml
 <receiver android:name="com.kidoz.sdk.api.receivers.SdkReceiver" >
       <intent-filter>
            <action android:name="android.intent.action.PACKAGE_ADDED" android:enabled="true"/>
            <data android:scheme="package" />
       </intent-filter>
  </receiver>
  
  <activity android:name="com.kidoz.sdk.api.ui_views.interstitial.KidozAdActivity"
                  android:configChanges="keyboard|keyboardHidden|orientation|screenLayout|uiMode|screenSize|smallestScreenSize"/>
  
 
``` 

Example:
```xml
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="your.package.name">
    
    <uses-permission android:name="android.permission.INTERNET" />
    
     <!-- android:maxSdkVersion="19" is used to avoid permission handling in Android 6.0 and above (For developer convenience) --> 
    <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" android:maxSdkVersion="19"/>
   
    <application>
        <!-- Your main activity-->
        <activity
            ...
            android:configChanges="screenLayout|screenSize|orientation|keyboardHidden|keyboard"
            ...
          >
	</activity>
        ...
	        <receiver android:name="com.kidoz.sdk.api.receivers.SdkReceiver" android:enabled="true">
            <intent-filter>
                <action android:name="android.intent.action.PACKAGE_ADDED" />
                <data android:scheme="package" />
            </intent-filter>
        </receiver>
        
         <activity android:name="com.kidoz.sdk.api.ui_views.interstitial.KidozAdActivity"
                  android:configChanges="keyboard|keyboardHidden|orientation|screenLayout|uiMode|screenSize|smallestScreenSize"/>
                 
        ...
    </application>
</manifest>
``` 
</br>
 
## Include Kidoz SDK (IOS) library in your projects for IOS build (v0.5.7)
1. Copy and add the KidozSDK.bundle and Kidoz.framework files to your project into the Frameworks section in xcode.
2. Select Add Files to the project while selecting the ios folder (make sure that the copy option is checked) and select the KIDOZCocos2dBridge.h and KIDOZCocos2dBridge.mm files.



### Adding KIDOZ SDK to your app


1. In  AppDelegate.cpp add the following lines: 
</br>
Add the following function calls to AppDelegate::applicationDidFinishLaunching()
```groovy
    #include "KIDOZCocos2dBridge.h"  
``` 

</br>
Add the following function calls to AppDelegate::applicationDidFinishLaunching()
```groovy
   KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();   
   KIDOZBridge->initSDK(<your publisher id>,<security token>); 
``` 
 

2. Interstitial / Rewarded  - In your app scene file (in the demo code HellowWorldScene.cpp) add the following lines: 
```groovy
   KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();   
   KIDOZBridge->setInterstitialReadyListener(interstitialReady); // set interstitial listener
   KIDOZBridge->loadInterstitial(KIDOZCocos2dBridge::InterstitialAdType::AD_TYPE_INTERSTIAL, false); //request interstitial/rewarded ad.
   
   KIDOZBridge->showInterstitial(); //show the interstitial/rewarded ad. must be called after the load succedded
   
``` 

3. Panel - In your app scene file (in the demo code HellowWorldScene.cpp) add the following lines:
```groovy
   KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();
   KIDOZBridge->setPlayerStartedListener(playerStarted);
   KIDOZBridge->setPanelReadyListener(panelReady);
   KIDOZBridge->setPanelOpenedListener(panelOpen);
   KIDOZBridge->setPanelClosedListener(panelClose);
   KIDOZBridge->addPanelView(<panel position>, <handle position>);
   
``` 

4. Other listeners and widget can be found in KIDOZCocos2dBridge.h file.

For any question or assistance, please contact us at SDK@kidoz.net.
</br>







License
--------

    Copyright 2015 KIDOZ, Inc.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
