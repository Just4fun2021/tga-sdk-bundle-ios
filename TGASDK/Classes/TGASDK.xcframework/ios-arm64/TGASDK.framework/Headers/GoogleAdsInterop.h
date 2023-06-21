//
//  GoogleAdsInterop.h
//  TGASDK
//
//  Created by ljh on 2023/6/21.
//
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface GoogleAdsInterop : NSObject
+ (void)googleAdsStart;
+ (void)registerWebView:(WKWebView *)web;
@end

NS_ASSUME_NONNULL_END
