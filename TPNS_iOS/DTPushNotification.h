//
//  DTPushNotification.h
//  DTPushNotification
//
//  Created by Deutsche Telekom AG on 12.02.16.
//  Copyright © 2016 Deutsche Telekom AG. All rights reserved.
//

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT NSString * __nonnull const DTPNSURLStringProduction;
FOUNDATION_EXPORT NSString * __nonnull const DTPNSURLStringPreProduction;

NS_ASSUME_NONNULL_BEGIN

@interface DTPushNotification : NSObject

/**
 Creates and returns an `DTPushNotification` object.
 */
+ (DTPushNotification *)sharedInstance;

/**
 Registers the device with TPNS

 @param url The URL string of the TPNS server
 @param appKey The app key used to connect to TPNS
 @param pushToken The pushToken genarted by UIApplication, when registering for remote notifications
 @param additionalParameters An array containing any additional parameters as NSDictionaries like @{@"key" : @"SomeAdditionalID", @"value" : @4711};
 @param sandbox Defines wether or not to use the TPNS sandbox feature
 @param completion A block object to be executed when registration is completed. This block has no return value and takes two arguments: The deviceID returned by TPNS, if registration was successful and nil otherwise as well as an NSError object which is returned, if registration failed and nil otherwise.

 */
- (void)registerWithURL:(NSURL *)url
                 appKey:(NSString *)appKey
              pushToken:(NSData *)pushToken
   additionalParameters:(nullable NSArray *)additionalParameters
                sandbox:(BOOL)sandbox
             completion:(void(^)(NSString *deviceID, NSError * _Nullable error))completion;

/**
 Unregisters the device with TPNS

 @param A block object to be executed when unregistration is completed. This block has no return value and takes one arguments: An an NSError object which is returned, if unregistration failed and nil otherwise.

 */
- (void)unregisterWithCompletion:(void(^)(NSError * _Nullable error)) completion;

NS_ASSUME_NONNULL_END

@end
