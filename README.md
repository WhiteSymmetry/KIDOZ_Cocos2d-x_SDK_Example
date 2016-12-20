<a href="url"><img src="https://github.com/Kidoz-SDK/Kidoz_Android_SDK_Example/blob/master/graphics/App%20icon.png" align="left" height="72" width="72" ></a>
[<img src="https://kidoz-cdn.s3.amazonaws.com/wordpress/kidoz_small.gif" width="533px" height="300px">](https://www.youtube.com/watch?v=-ljFjRn7jeM)
KIDOZ SDK Cocos2Dx Sample App (android)
=======================================

**KIDOZ SDK and the sample App are compatible with Android 4.0 (API level 14) and above.**
*Updated to KIDOZ SDK (Android) version 0.7.1* 

### Include Kidoz SDK (Android) library in your projects (v0.7.1)

On Eclipse ADT you can include the library by doing the following:

 - Import `KIDOZ_SDK_Android` library project from `KIDOZ_SDK_CocosDx v3.x` folder to your Eclipse workspace.
 - Right click on your project, select `Properties`, in the window that appears select `Android`:
 - In the library section add KIDOZ SDK as a Library project.
 
In Your `Activity` that extends from `Cocos2dxActivity` in `onCreate` method put the folowing line:

```groovy
  // Initiate Kidoz SDK
  KidozSDKCocosDxBridge.init(this);
}
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
  
  <activity android:name="com.kidoz.sdk.api.ui_views.video_unit.VideoUnitActivity"
                  android:theme="@android:style/Theme.Black.NoTitleBar.Fullscreen"
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
                  
        <activity android:name="com.kidoz.sdk.api.ui_views.video_unit.VideoUnitActivity"
                  android:theme="@android:style/Theme.Black.NoTitleBar.Fullscreen"
                  android:configChanges="keyboard|keyboardHidden|orientation|screenLayout|uiMode|screenSize|smallestScreenSize"/>
        ...
    </application>
</manifest>
``` 
 
 
 
### Include Kidoz SDK (IOS) library in your projects (v0.5.8)








KIDOZ SDK Cocos2Dx Sample App (iOS)
=======================================

### Sample App
The sample app can be found in the following directory: /KIDOZSample/proj.ios_mac

The app shows the feed button and the panel widget.


### Adding KIDOZ SDK to your app

1. Copy and add the KidozSDK.bundle and Kidoz.framework files to your project into the Frameworks section in xcode.
2. Select Add Files to the project while selecting the ios folder (make sure that the copy option is checked) and select the KIDOZCocos2dBridge.h and KIDOZCocos2dBridge.mm files.
3. In  AppDelegate.cpp add the following lines: <br>
```#include "KIDOZCocos2dBridge.h"``` <br>
Add the following function calls to AppDelegate::applicationDidFinishLaunching()
 ```KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();```
```KIDOZBridge->initSDK(<your publisher id>,<security token>);```
4. In your app scene file (in the demo code HellowWorldScene.cpp) add the following lines: according to your selected KIDOZ widgets. Add the following include file: #include "KIDOZCocos2dBridge.h"
 ```KIDOZCocos2dBridge *KIDOZBridge = KIDOZCocos2dBridge::getInstance();```
   For panel use: ```KIDOZBridge->addPanelView(<panel position>, <handle position>);```
   For feed button use" ```KIDOZBridge->addFeedButton(<x position>, <y position>);```
5. You can add listeners by calling ```KIDOZBridge->setPanelReadyListener(panelReady);```
6. Other listeners can be found in KIDOZCocos2dBridge.h file

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
