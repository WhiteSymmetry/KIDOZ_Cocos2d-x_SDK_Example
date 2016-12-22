//
//  NSDictionary+GetDefault.h
//  KIDOZ_SDK_SAMPLE
//
//  Created by Ori Kam on 30/11/2015.
//  Copyright © 2015 kidoz. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (KIDOZGetDefault)

-(id ) objectForKey:(NSObject*)aKey defaultValue:(id)defaultValue;

@end
