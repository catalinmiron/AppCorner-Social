//
//  DKRequest.h
//  DeploydKit
//
//  Created by Denis Berton
//  Copyright (c) 2012 appcorner.it. All rights reserved.
//
//  DeploydKit is based on DataKit (https://github.com/eaigner/DataKit)
//  Created by Erik Aigner
//  Copyright (c) 2012 chocomoko.com. All rights reserved.
//

#import "DKConstants.h"

typedef NS_ENUM(NSInteger, DKResponseStatus) {
  DKResponseStatusSuccess = 200,
  DKResponseStatusError = 400
};

@interface DKRequest : NSObject
@property (nonatomic, copy, readonly) NSString *endpoint;
@property (nonatomic, assign) DKCachePolicy cachePolicy;
@property (readwrite, assign) NSTimeInterval maxCacheAge;

+ (DKRequest *)request;

+ (BOOL)canParseResponse:(NSHTTPURLResponse *)response;
+ (id)parseResponse:(NSHTTPURLResponse *)response withData:(NSData *)data error:(NSError **)error;

- (instancetype)initWithEndpoint:(NSString *)absoluteString NS_DESIGNATED_INITIALIZER;

- (id)sendRequestWithMethod:(NSString *)apiMethod entity:(NSString *)entityName error:(NSError **)error;
- (id)sendRequestWithObject:(id)JSONObject method:(NSString *)apiMethod entity:(NSString *)entityName error:(NSError **)error;
- (id)sendRequestWithData:(NSData *)data method:(NSString *)apiMethod entity:(NSString *)entityName error:(NSError **)error;

@end

@interface DKRequest (Wrapping)

+ (id)iterateJSON:(id)JSONObject modify:(id (^)(id obj))handler;
+ (id)wrapSpecialObjectsInJSON:(id)obj;
+ (id)unwrapSpecialObjectsInJSON:(id)obj;

@end

@interface DKRequest (Logging)

+ (void)logData:(NSData *)data isOut:(BOOL)isOut url:(NSString*)url;

@end


