//
//  Utils.h
//  KidozSDK
//
//  Created by Ori Kam on 26/10/2015.
//  Copyright © 2015 kidoz. All rights reserved.
//

#ifndef Utils_h
#define Utils_h
#import <UIKit/UIKit.h>
#import "KIDOZinterfaces.h"
@interface KIDOZUtils : NSObject

+(long) getTimeStemp;
+(long long)getTimeInMiliseconds;
+(long long)convertTimeFromDouble:(double)timeStamp;
+(NSString*) getTimeStempAsString;
+(NSString*) sha1:(NSString*)input;
+(NSString *) getNSStringFromDic:(NSDictionary *)dic;
+(NSString *) getNSStringFromArray:(NSArray *)array;
+(NSDictionary *) getDictionaryFromJSONData:(NSData *)data;
+(UIColor *) getUIColorFromString:(NSString *)strColor;
+(NSString *)getStringFromNSData:(NSData *)data;
+(NSString *)getKidozDirPath;
+(NSString *)getResourceFullName:(NSString *)resourceName;
+(void)setResourceInBundle:(BOOL)inBundle;
+(void)setExtensionName:(KIDOZExtensionType)extensionName;
+(NSString *)getExtensionName;
+(NSString *)getSDKVersion;
+(NSDictionary *)getDicFromNSString:(NSString *)input;
@end

#endif /* Utils_h */
