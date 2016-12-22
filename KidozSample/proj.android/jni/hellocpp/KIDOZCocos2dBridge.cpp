#include "KIDOZCocos2dBridge.h"
#include "cocos2d.h"
#include <iostream>

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>

#define  LOG_TAG    "KidozSDK"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#endif

#define  JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH  "com/kidoz/sdk/api/platforms/KidozSDKCocosDxBridge"

/** Kidoz SDK Bridge local static instance reference */
static KIDOZCocos2dBridge *g_KIDOZBridgeInstance = NULL;

/**
 * Get kidoz cocos2Dx bridge instance
 * */
KIDOZCocos2dBridge *KIDOZCocos2dBridge::getInstance() {
	if (g_KIDOZBridgeInstance != NULL) {
		return g_KIDOZBridgeInstance;
	}
	g_KIDOZBridgeInstance = new KIDOZCocos2dBridge();
	return g_KIDOZBridgeInstance;
}

/**
 * Free cocos2Dx bridge resources
 * */
void KIDOZCocos2dBridge::releaseResources() {
	if (g_KIDOZBridgeInstance != NULL) {
		delete (g_KIDOZBridgeInstance);
		g_KIDOZBridgeInstance = NULL;
	}
}
/**
 * Initiate KIDOZ SDK
 *
 * @param xPos x position of button on screen
 * @param yPos y position of button on screen
 * */
int KIDOZCocos2dBridge::initSDK(char *pubID, char *secToken) {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_initialize", "(Ljava/lang/String;Ljava/lang/String;)V");
	if (isHas)
	{
		jstring publisherId = methodInfo.env->NewStringUTF(pubID);
		jstring token = methodInfo.env->NewStringUTF(secToken);

		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,publisherId,token);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
		methodInfo.env->DeleteLocalRef(publisherId);
		methodInfo.env->DeleteLocalRef(token);
	}
	return 0;
#endif
}

/** Add feed button to view
 *
 * @param xPos x position of button on screen
 * @param yPos y position of button on screen
 * */
int KIDOZCocos2dBridge::addFeedButton(float xPos, float yPos) {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_addFeedButton", "(III)V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,(int)xPos,(int)yPos,-1);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	return 0;
#endif
}

/**
 * Show feed to view
 * */
int KIDOZCocos2dBridge::showFeedView() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_showFeedView", "()V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	return 0;
#endif
}

/**
 * Dismiss feed to view
 * */
int KIDOZCocos2dBridge::dismissFeedView() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_dismissFeedView", "()V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Change feed button visibility
 * */
int KIDOZCocos2dBridge::changeFeedButtonVisibility(bool visible) {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_changeFeedButtonVisibility", "(Z)V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,visible);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Add kidoz panel to view
 * */
int KIDOZCocos2dBridge::addPanelView(PanelType panelType,
		PanelHandlePosition handlePosition) {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_addPanelToView", "(II)V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,static_cast<int>(panelType),static_cast<int>(handlePosition));
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Change panel view visibility state
 * */
int KIDOZCocos2dBridge::changePanelVisibility(bool visible) {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_changePanelVisibility", "(Z)V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,visible);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Collapse (Close) Panel view
 * */
int KIDOZCocos2dBridge::collapsePanelView() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_collapsePanelView", "()V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Expand (Open) Panel view
 * */
int KIDOZCocos2dBridge::expandPanelView() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_expandPanelView", "()V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Get panel expanded or not
 * */
bool KIDOZCocos2dBridge::getIsPanelExpanded() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_getIsPanelExpanded", "()Z");
	jboolean isExpanded = false;
	if (isHas)
	{
		isExpanded = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	return (bool)isExpanded;
#endif
}

/**
 * Get panel expanded state
 * */
int KIDOZCocos2dBridge::addFlexiView(FlexiPosition initialPosition,
		bool autoShow) {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_addFlexiView", "(ZI)V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,autoShow,static_cast<int>(initialPosition));
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Show flexi view (Make it visible)
 * */
int KIDOZCocos2dBridge::showFlexiView() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_showFlexiView", "()V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Hide flexi view (Make it invisible)
 * */
int KIDOZCocos2dBridge::hideFlexiView() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_hideFlexiView", "()V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}

	return 0;
#endif
}

/**
 * Get flexi view visibility state
 * */
bool KIDOZCocos2dBridge::getIsFlexiViewVisible() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_getIsFlexiViewVisible", "()Z");
	jboolean isVisible = false;
	if (isHas)
	{
		isVisible = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	return isVisible;
#endif
}

/**
 * Load interstitial
 *
 * @param ad_type the type of add to load (Interstitial/Rewarded)
 * @bool autoShowOnLoad auto show on load
 * */
int KIDOZCocos2dBridge::loadInterstitial(InterstitialAdType ad_type,
		bool autoShowOnLoad) {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_loadInterstitial", "(IZ)V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,static_cast<int>(ad_type),autoShowOnLoad);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	return 0;
#endif
}

/**
 * Show interstitial (Should be already loaded)
 * */
int KIDOZCocos2dBridge::showInterstitial() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_showInterstitial", "()V");
	if (isHas)
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	return 0;
#endif
}

/**
 * Get is interstitial has been loaded
 * */
bool KIDOZCocos2dBridge::getIsInterstitialLoaded() {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_getIsInterstitialLoaded", "()Z");
	jboolean loaded = false;
	if (isHas)
	{
		loaded = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	return loaded;
#endif
}

/**
 * Show video unit ( Currently unavailable )
 * */
int KIDOZCocos2dBridge::showVideoUnit() {
	/*
	 #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	 cocos2d::JniMethodInfo methodInfo;
	 bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_showVideoUnit", "()V");
	 if (isHas)
	 {
	 methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	 methodInfo.env->DeleteLocalRef(methodInfo.classID);
	 }
	 #endif
	 */
	return -1;
}

/**
 * Print toast , testing function
 * */
void KIDOZCocos2dBridge::printToastLog(char* message) {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	cocos2d::JniMethodInfo methodInfo;
	bool isHas = cocos2d::JniHelper::getStaticMethodInfo(methodInfo,JAVA_NATIVE_KIDOZ_BRIGDE_CLASS_PATH, "cdx_printToastLog", "(Ljava/lang/String;)V");
	if (isHas)
	{
		jstring encoding = methodInfo.env->NewStringUTF(message);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID,encoding);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
		methodInfo.env->DeleteLocalRef(encoding);
	}
#endif
}

#ifdef __cplusplus
extern "C" {
#endif

/** JAVA to JNI Callback invocation listener */
JNIEXPORT
void Java_com_kidoz_sdk_api_platforms_KidozSDKCocosDxBridge_callbackInvoke(
		JNIEnv *env, jobject, jint eventType) {

	switch (eventType) {

		case KIDOZCocos2dBridge::InnerType::FEED_CLOSE_EVENT: {
			if (g_KIDOZBridgeInstance->mFeedClosedListener != NULL) {
				g_KIDOZBridgeInstance->mFeedClosedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::FEED_OPEN_EVENT: {
			if (g_KIDOZBridgeInstance->mFeedOpenedListener != NULL) {
				g_KIDOZBridgeInstance->mFeedOpenedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::FEED_READY_EVENT: {
			if (g_KIDOZBridgeInstance->mFeedReadyListener != NULL) {
				g_KIDOZBridgeInstance->mFeedReadyListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::FLEXI_HIDDEN_EVENT: {
			if (g_KIDOZBridgeInstance->mFlexiViewHiddenListener != NULL) {
				g_KIDOZBridgeInstance->mFlexiViewHiddenListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::FLEXI_READY_EVENT: {
			if (g_KIDOZBridgeInstance->mFlexiViewReadyListener != NULL) {
				g_KIDOZBridgeInstance->mFlexiViewReadyListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::FLEXI_VISIBLE_EVENT: {
			if (g_KIDOZBridgeInstance->mFlexiViewVisibleListener != NULL) {
				g_KIDOZBridgeInstance->mFlexiViewVisibleListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::INTERSTITIAL_CLOSED_EVEN: {
			if (g_KIDOZBridgeInstance->mInterstitialClosedListener != NULL) {
				g_KIDOZBridgeInstance->mInterstitialClosedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::INTERSTITIAL_FAILED_EVEN: {
			if (g_KIDOZBridgeInstance->mInterstitialLoadFailedListener != NULL) {
				g_KIDOZBridgeInstance->mInterstitialLoadFailedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::INTERSTITIAL_OPENED_EVEN: {
			if (g_KIDOZBridgeInstance->mInterstitialOpenedListener != NULL) {
				g_KIDOZBridgeInstance->mInterstitialOpenedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::INTERSTITIAL_READY_EVEN: {
			if (g_KIDOZBridgeInstance->mInterstitialReadyListener != NULL) {
				g_KIDOZBridgeInstance->mInterstitialReadyListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::INTERSTITIAL_REWARDED_EVEN: {
			if (g_KIDOZBridgeInstance->mInterstitialRewardedEventListener != NULL) {
				g_KIDOZBridgeInstance->mInterstitialRewardedEventListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::INTERSTITIAL_REWARDED_VIDEO_START_EVEN: {
			if (g_KIDOZBridgeInstance->mInterstitialRewardedVideoStartedListener
					!= NULL) {
				g_KIDOZBridgeInstance->mInterstitialRewardedVideoStartedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::PANEL_CLOSED_EVENT: {
			if (g_KIDOZBridgeInstance->mPanelClosedListener != NULL) {
				g_KIDOZBridgeInstance->mPanelClosedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::PANEL_OPENED_EVENT: {
			if (g_KIDOZBridgeInstance->mPanelOpenedListener != NULL) {
				g_KIDOZBridgeInstance->mPanelOpenedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::PANEL_READY_EVENT: {
			if (g_KIDOZBridgeInstance->mPanelReadyListener != NULL) {
				g_KIDOZBridgeInstance->mPanelReadyListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::PLAYER_CLOSE_EVENT: {
			if (g_KIDOZBridgeInstance->mPlayerEndedListener != NULL) {
				g_KIDOZBridgeInstance->mPlayerEndedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::PLAYER_OPEN_EVENT: {
			if (g_KIDOZBridgeInstance->mPlayerStartedListener != NULL) {
				g_KIDOZBridgeInstance->mPlayerStartedListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::VIDEO_UNIT_CLOSE_EVEN: {
			if (g_KIDOZBridgeInstance->mVideoUnitCloseListener != NULL) {
				g_KIDOZBridgeInstance->mVideoUnitCloseListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::VIDEO_UNIT_OPEN_EVEN: {
			if (g_KIDOZBridgeInstance->mVideoUnitOpenListener != NULL) {
				g_KIDOZBridgeInstance->mVideoUnitOpenListener();
			}
			break;
		}

		case KIDOZCocos2dBridge::InnerType::VIDEO_UNIT_READY_EVEN: {
			if (g_KIDOZBridgeInstance->mVideoUnitReadyListener != NULL) {
				g_KIDOZBridgeInstance->mVideoUnitReadyListener();
			}
			break;
		}
	}
}

#ifdef __cplusplus
}
#endif

/** Event listener setters*/
void KIDOZCocos2dBridge::setFeedOpenedListener(KIDOZListener name) {
	mFeedOpenedListener = name;
}
void KIDOZCocos2dBridge::setFeedClosedListener(KIDOZListener name) {
	mFeedClosedListener = name;
}
void KIDOZCocos2dBridge::setFeedReadyListener(KIDOZListener name) {
	mFeedReadyListener = name;
}
void KIDOZCocos2dBridge::setPanelOpenedListener(KIDOZListener name) {
	mPanelOpenedListener = name;
}
void KIDOZCocos2dBridge::setPanelClosedListener(KIDOZListener name) {
	mPanelClosedListener = name;
}
void KIDOZCocos2dBridge::setPanelReadyListener(KIDOZListener name) {
	mPanelReadyListener = name;
}
void KIDOZCocos2dBridge::setPlayerStartedListener(KIDOZListener name) {
	mPlayerStartedListener = name;
}
void KIDOZCocos2dBridge::setPlayerEndedListener(KIDOZListener name) {
	mPlayerEndedListener = name;
}

void KIDOZCocos2dBridge::setFlexiViewReadyListener(KIDOZListener name) {
	mFlexiViewReadyListener = name;
}

void KIDOZCocos2dBridge::setFlexiViewVisibleListener(KIDOZListener name) {
	mFlexiViewVisibleListener = name;
}

void KIDOZCocos2dBridge::setFlexiViewHiddenListener(KIDOZListener name) {
	mFlexiViewHiddenListener = name;
}

void KIDOZCocos2dBridge::setInterstitialOpenedListener(KIDOZListener name) {
	mInterstitialOpenedListener = name;
}

void KIDOZCocos2dBridge::setInterstitialClosedListener(KIDOZListener name) {
	mInterstitialClosedListener = name;
}

void KIDOZCocos2dBridge::setInterstitialReadyListener(KIDOZListener name) {
	mInterstitialReadyListener = name;
}

void KIDOZCocos2dBridge::setInterstitialLoadFailedListener(KIDOZListener name) {
	mInterstitialLoadFailedListener = name;
}

void KIDOZCocos2dBridge::setInterstitialRewardedVideoStartedListener(
		KIDOZListener name) {
	mInterstitialRewardedVideoStartedListener = name;
}

void KIDOZCocos2dBridge::setInterstitialRewardedEventListener(
		KIDOZListener name) {
	mInterstitialRewardedEventListener = name;
}

/*void KIDOZCocos2dBridge::setVideoUnitOpenListener(KIDOZListener name) {
	mVideoUnitOpenListener = name;
}

void KIDOZCocos2dBridge::setVideoUnitCloseListener(KIDOZListener name) {
	mVideoUnitCloseListener = name;
}

void KIDOZCocos2dBridge::setVideoUnitReadyListener(KIDOZListener name) {
	mVideoUnitReadyListener = name;
}*/

