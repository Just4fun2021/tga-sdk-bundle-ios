#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.9.2 (swiftlang-5.9.2.2.56 clang-1500.1.0.2.5)
#ifndef TGASDK_SWIFT_H
#define TGASDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreFoundation;
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="TGASDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)





@class NSCoder;

SWIFT_CLASS("_TtC6TGASDK16JTSegmentControl")
@interface JTSegmentControl : UIControl
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


@interface JTSegmentControl (SWIFT_EXTENSION(TGASDK))
- (void)moveTo:(NSInteger)index;
- (void)moveTo:(NSInteger)index animated:(BOOL)animated;
- (void)layoutSubviews;
@end






@class NSString;

SWIFT_CLASS("_TtC6TGASDK13PurchaseError")
@interface PurchaseError : NSObject
@property (nonatomic) NSInteger resultCode;
@property (nonatomic, copy) NSString * _Nonnull resultDesc;
@property (nonatomic, copy) NSString * _Nonnull transactionId;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UIImage;

/// MARK - TGA configuration
SWIFT_CLASS("_TtC6TGASDK16TGAConfiguration")
@interface TGAConfiguration : NSObject
/// 默认本地语言
@property (nonatomic, copy) NSString * _Nonnull lang;
/// statusBarStyle default ‘lightContent’
@property (nonatomic) UIStatusBarStyle statusBarStyle;
/// 导航栏返回图片
@property (nonatomic, strong) UIImage * _Nullable navigationBackImage;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

/// 日志等级
/// warning:
/// 警告
/// <ul>
///   <li>
///     off: 关闭
///   </li>
///   <li>
///     error: 错误
///   </li>
///   <li>
///     info: 信息
///   </li>
///   <li>
///     debug: debug
///   </li>
///   <li>
///     all: 所有
///   </li>
/// </ul>
typedef SWIFT_ENUM(NSInteger, TGALogLevel, open) {
  TGALogLevelOff = 1,
  TGALogLevelError = 2,
  TGALogLevelInfo = 3,
  TGALogLevelDebug = 4,
  TGALogLevelWarning = 5,
  TGALogLevelAll = 6,
};


SWIFT_PROTOCOL("_TtP6TGASDK18TGAPayInfoDelegate_")
@protocol TGAPayInfoDelegate <NSObject>
- (NSString * _Nonnull)getEncryptedMsisdn SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nonnull)getWsUser SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nonnull)getPassword SWIFT_WARN_UNUSED_RESULT;
@end

@class TGAUserInfo;
@protocol TGASdkDelegate;
@class UIViewController;

/// MARK - TGASDK
SWIFT_CLASS("_TtC6TGASDK6TGASdk")
@interface TGASdk : NSObject
/// 单利
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) TGASdk * _Nonnull shared;)
+ (TGASdk * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
/// 默认配置
@property (nonatomic, strong) TGAConfiguration * _Nonnull configuration;
/// bip支付数据回调
@property (nonatomic, strong) id <TGAPayInfoDelegate> _Nullable bipPayInfoDelegate;
/// 初始化SDK
/// \param env sdk区分环境的唯一值,可以传null或者空字符
///
/// \param appKey app对接密钥
///
/// \param userInfo 用户信息，如果userInfo返回null，游戏平台将以游客的身份登录
///
/// \param delegate 委托
///
- (BOOL)initSdkWithEnv:(NSString * _Nullable)env appKey:(NSString * _Nonnull)appKey userInfo:(TGAUserInfo * _Nullable)userInfo delegate:(id <TGASdkDelegate> _Nonnull)delegate SWIFT_METHOD_FAMILY(none);
/// 是否初始化
- (BOOL)isInited SWIFT_WARN_UNUSED_RESULT;
/// 退出登录
- (void)logout;
/// 打开游戏中心控制器
/// \param secUrl 打开游戏中心的同时再打开该网页，可用于打开游戏中心的同时跳到某一款游戏
///
/// \param secTitle 游戏页面的标题
///
/// \param theme 主题
///
- (BOOL)openGameCenterWithVc:(UIViewController * _Nonnull)vc secUrl:(NSString * _Nullable)secUrl secTitle:(NSString * _Nullable)secTitle theme:(NSString * _Nullable)theme;
- (void)closeAllWindow;
/// 设置日志等级
/// \param level TGALogLevel
///
- (void)setLogLevelWithLevel:(enum TGALogLevel)level;
- (void)onInAppPaySuccessWithOrderNo:(NSString * _Nonnull)orderNo;
- (void)onInAppPayFailureWithError:(PurchaseError * _Nonnull)error;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



@class NSError;
@class TGAShareInfo;

/// MARK - TGASDK Delegate
SWIFT_PROTOCOL("_TtP6TGASDK14TGASdkDelegate_")
@protocol TGASdkDelegate <NSObject>
/// 初始化成功
- (void)tgaSdkInitSucceed;
/// 初始化失败
/// \param error NSError
///
- (void)tgaSdkInitError:(NSError * _Nonnull)error;
/// 获取用户信息
/// 唤起app自身登录界面，当sdk是游客身份登录时，如果要充值，购买钻石等操作页面会弹出提示是否去登录，点击去登录回调
/// \param completion 回传用户Id，用户昵称，用户头像
///
- (void)tgaSdkGetUserInfoWithCompletion:(void (^ _Nonnull)(TGAUserInfo * _Nullable))completion;
/// 关闭游戏中心
- (void)tgaSdkCloseGameCenter;
/// 用户登出
- (void)tgaSdkOnLogout;
/// 用户分享
- (void)tgaOnInAppShareFromVC:(UIViewController * _Nonnull)fromVC shareInfo:(TGAShareInfo * _Nonnull)shareInfo completion:(void (^ _Nonnull)(NSString * _Nonnull, BOOL))completion;
@optional
- (void)tgaOnInAppPayFromVC:(UIViewController * _Nonnull)fromVC orderNo:(NSString * _Nonnull)orderNo;
@end


SWIFT_CLASS("_TtC6TGASDK12TGAShareInfo")
@interface TGAShareInfo : NSObject
@property (nonatomic, copy) NSString * _Nonnull callbackId;
@property (nonatomic, copy) NSString * _Nonnull iconUrl;
@property (nonatomic, copy) NSString * _Nonnull link;
@property (nonatomic, copy) NSString * _Nonnull title;
@property (nonatomic, copy) NSString * _Nonnull type;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// MARK - User Info
SWIFT_CLASS("_TtC6TGASDK11TGAUserInfo")
@interface TGAUserInfo : NSObject
/// 用户Id
@property (nonatomic, copy) NSString * _Nonnull userId;
/// 用户昵称
@property (nonatomic, copy) NSString * _Nonnull nickname;
/// 用户头像
@property (nonatomic, copy) NSString * _Nonnull avatar;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UITraitCollection;
@class UITouch;
@class UIEvent;

/// 布局视图基类，基类不支持实例化对象。在编程时我们经常会用到一些视图，这种视图只是负责将里面的子视图按照某种规则进行排列和布局，而别无其他的作用。因此我们称这种视图为容器视图或者称为布局视图。
/// 布局视图通过重载layoutSubviews方法来完成子视图的布局和排列的工作。对于每个加入到布局视图中的子视图，都会在加入时通过KVO机制监控子视图的center和bounds以及frame值的变化，每当子视图的这些属性一变化时就又会重新引发布局视图的布局动作。同时对每个视图的布局扩展属性的设置以及对布局视图的布局属性的设置都会引发布局视图的布局动作。布局视图在添加到非布局父视图时也会通过KVO机制来监控非布局父视图的frame值和bounds值，这样每当非布局父视图的尺寸变更时也会引发布局视图的布局动作。前面说的引起变动的方法就是会在KVO处理逻辑以及布局扩展属性和布局属性设置完毕后通过调用setNeedLayout来实现的，当布局视图收到setNeedLayout的请求后，会在下一个runloop中对布局视图进行重新布局而这就是通过调用layoutSubviews方法来实现的。布局视图基类只提供了更新所有子视图的位置和尺寸以及一些基础的设置，而至于如何排列和布局这些子视图则要根据应用的场景和需求来确定，因此布局基类视图提供了一个：
/// internal func tgCalcLayoutRect(_ size:CGSize, isEstimate:Bool, hasSubLayout:inout Bool!, sbs:[UIView]!, type:TGSizeClassType) ->CGSize
/// 的方法，要求派生类去重载这个方法，这样不同的派生类就可以实现不同的应用场景，这就是布局视图的核心实现机制。
/// TangramKit布局库根据实际中常见的场景实现了7种不同的布局视图派生类他们分别是：线性布局、表格布局、相对布局、框架布局、流式布局、浮动布局、路径布局。
SWIFT_CLASS("_TtC6TGASDK12TGBaseLayout")
@interface TGBaseLayout : UIView
- (void)safeAreaInsetsDidChange;
- (void)setNeedsLayout;
@property (nonatomic, readonly) CGSize intrinsicContentSize;
- (void)layoutSubviews;
- (void)traitCollectionDidChange:(UITraitCollection * _Nullable)previousTraitCollection;
- (CGSize)sizeThatFits:(CGSize)size SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, getter=isHidden) BOOL hidden;
- (void)awakeFromNib;
- (void)didAddSubview:(UIView * _Nonnull)subview;
- (void)willRemoveSubview:(UIView * _Nonnull)subview;
- (void)willMoveToSuperview:(UIView * _Nullable)newSuperview;
- (void)observeValueForKeyPath:(NSString * _Nullable)keyPath ofObject:(id _Nullable)object change:(NSDictionary<NSKeyValueChangeKey, id> * _Nullable)change context:(void * _Nullable)context;
- (void)touchesBegan:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (void)touchesMoved:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (void)touchesEnded:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (void)touchesCancelled:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end




/// *线性布局是一种里面的子视图按添加的顺序从上到下或者从左到右依次排列的单行(单列)布局视图。线性布局里面的子视图是通过添加的顺序建立约束和依赖关系的。
/// *根据排列的方向我们把子视图从上到下依次排列的线性布局视图称为垂直线性布局视图，而把子视图从左到右依次排列的线性布局视图则称为水平线性布局。
/// 垂直线性布局
/// +—––+
/// |   A   |
/// +—––+
/// |   B   |
/// +—––+  ⥥
/// |   C   |
/// +—––+
/// |  …  |
/// +—––+
/// 水平线性布局
/// +—–+—–+—–+—–+
/// |  A  |  B  |  C  | … |
/// +—–+—–+—–+—–+
/// ⥤
SWIFT_CLASS("_TtC6TGASDK14TGLinearLayout")
@interface TGLinearLayout : TGBaseLayout
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)willRemoveSubview:(UIView * _Nonnull)subview;
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
@end



/// *相对布局是一种里面的子视图通过相互之间的约束和依赖来进行布局和定位的布局视图。
/// *相对布局里面的子视图的布局位置和添加的顺序无关，而是通过设置子视图的相对依赖关系来进行定位和布局的。
/// *相对布局提供和AutoLayout等价的功能。
SWIFT_CLASS("_TtC6TGASDK16TGRelativeLayout")
@interface TGRelativeLayout : TGBaseLayout
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end















#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#elif defined(__x86_64__) && __x86_64__
// Generated by Apple Swift version 5.9.2 (swiftlang-5.9.2.2.56 clang-1500.1.0.2.5)
#ifndef TGASDK_SWIFT_H
#define TGASDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#if defined(__OBJC__)
#include <Foundation/Foundation.h>
#endif
#if defined(__cplusplus)
#include <cstdint>
#include <cstddef>
#include <cstdbool>
#include <cstring>
#include <stdlib.h>
#include <new>
#include <type_traits>
#else
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#endif
#if defined(__cplusplus)
#if defined(__arm64e__) && __has_include(<ptrauth.h>)
# include <ptrauth.h>
#else
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-macro-identifier"
# ifndef __ptrauth_swift_value_witness_function_pointer
#  define __ptrauth_swift_value_witness_function_pointer(x)
# endif
# ifndef __ptrauth_swift_class_method_pointer
#  define __ptrauth_swift_class_method_pointer(x)
# endif
#pragma clang diagnostic pop
#endif
#endif

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...) 
# endif
#endif
#if !defined(SWIFT_RUNTIME_NAME)
# if __has_attribute(objc_runtime_name)
#  define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
# else
#  define SWIFT_RUNTIME_NAME(X) 
# endif
#endif
#if !defined(SWIFT_COMPILE_NAME)
# if __has_attribute(swift_name)
#  define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
# else
#  define SWIFT_COMPILE_NAME(X) 
# endif
#endif
#if !defined(SWIFT_METHOD_FAMILY)
# if __has_attribute(objc_method_family)
#  define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
# else
#  define SWIFT_METHOD_FAMILY(X) 
# endif
#endif
#if !defined(SWIFT_NOESCAPE)
# if __has_attribute(noescape)
#  define SWIFT_NOESCAPE __attribute__((noescape))
# else
#  define SWIFT_NOESCAPE 
# endif
#endif
#if !defined(SWIFT_RELEASES_ARGUMENT)
# if __has_attribute(ns_consumed)
#  define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
# else
#  define SWIFT_RELEASES_ARGUMENT 
# endif
#endif
#if !defined(SWIFT_WARN_UNUSED_RESULT)
# if __has_attribute(warn_unused_result)
#  define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
# else
#  define SWIFT_WARN_UNUSED_RESULT 
# endif
#endif
#if !defined(SWIFT_NORETURN)
# if __has_attribute(noreturn)
#  define SWIFT_NORETURN __attribute__((noreturn))
# else
#  define SWIFT_NORETURN 
# endif
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA 
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA 
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA 
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif
#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif
#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER 
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility) 
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED_OBJC)
# if __has_feature(attribute_diagnose_if_objc)
#  define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
# else
#  define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
# endif
#endif
#if defined(__OBJC__)
#if !defined(IBSegueAction)
# define IBSegueAction 
#endif
#endif
#if !defined(SWIFT_EXTERN)
# if defined(__cplusplus)
#  define SWIFT_EXTERN extern "C"
# else
#  define SWIFT_EXTERN extern
# endif
#endif
#if !defined(SWIFT_CALL)
# define SWIFT_CALL __attribute__((swiftcall))
#endif
#if !defined(SWIFT_INDIRECT_RESULT)
# define SWIFT_INDIRECT_RESULT __attribute__((swift_indirect_result))
#endif
#if !defined(SWIFT_CONTEXT)
# define SWIFT_CONTEXT __attribute__((swift_context))
#endif
#if !defined(SWIFT_ERROR_RESULT)
# define SWIFT_ERROR_RESULT __attribute__((swift_error_result))
#endif
#if defined(__cplusplus)
# define SWIFT_NOEXCEPT noexcept
#else
# define SWIFT_NOEXCEPT 
#endif
#if !defined(SWIFT_C_INLINE_THUNK)
# if __has_attribute(always_inline)
# if __has_attribute(nodebug)
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline)) __attribute__((nodebug))
# else
#  define SWIFT_C_INLINE_THUNK inline __attribute__((always_inline))
# endif
# else
#  define SWIFT_C_INLINE_THUNK inline
# endif
#endif
#if defined(_WIN32)
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL __declspec(dllimport)
#endif
#else
#if !defined(SWIFT_IMPORT_STDLIB_SYMBOL)
# define SWIFT_IMPORT_STDLIB_SYMBOL 
#endif
#endif
#if defined(__OBJC__)
#if __has_feature(objc_modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreFoundation;
@import Foundation;
@import ObjectiveC;
@import UIKit;
#endif

#endif
#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="TGASDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

#if defined(__OBJC__)





@class NSCoder;

SWIFT_CLASS("_TtC6TGASDK16JTSegmentControl")
@interface JTSegmentControl : UIControl
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


@interface JTSegmentControl (SWIFT_EXTENSION(TGASDK))
- (void)moveTo:(NSInteger)index;
- (void)moveTo:(NSInteger)index animated:(BOOL)animated;
- (void)layoutSubviews;
@end






@class NSString;

SWIFT_CLASS("_TtC6TGASDK13PurchaseError")
@interface PurchaseError : NSObject
@property (nonatomic) NSInteger resultCode;
@property (nonatomic, copy) NSString * _Nonnull resultDesc;
@property (nonatomic, copy) NSString * _Nonnull transactionId;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UIImage;

/// MARK - TGA configuration
SWIFT_CLASS("_TtC6TGASDK16TGAConfiguration")
@interface TGAConfiguration : NSObject
/// 默认本地语言
@property (nonatomic, copy) NSString * _Nonnull lang;
/// statusBarStyle default ‘lightContent’
@property (nonatomic) UIStatusBarStyle statusBarStyle;
/// 导航栏返回图片
@property (nonatomic, strong) UIImage * _Nullable navigationBackImage;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

/// 日志等级
/// warning:
/// 警告
/// <ul>
///   <li>
///     off: 关闭
///   </li>
///   <li>
///     error: 错误
///   </li>
///   <li>
///     info: 信息
///   </li>
///   <li>
///     debug: debug
///   </li>
///   <li>
///     all: 所有
///   </li>
/// </ul>
typedef SWIFT_ENUM(NSInteger, TGALogLevel, open) {
  TGALogLevelOff = 1,
  TGALogLevelError = 2,
  TGALogLevelInfo = 3,
  TGALogLevelDebug = 4,
  TGALogLevelWarning = 5,
  TGALogLevelAll = 6,
};


SWIFT_PROTOCOL("_TtP6TGASDK18TGAPayInfoDelegate_")
@protocol TGAPayInfoDelegate <NSObject>
- (NSString * _Nonnull)getEncryptedMsisdn SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nonnull)getWsUser SWIFT_WARN_UNUSED_RESULT;
- (NSString * _Nonnull)getPassword SWIFT_WARN_UNUSED_RESULT;
@end

@class TGAUserInfo;
@protocol TGASdkDelegate;
@class UIViewController;

/// MARK - TGASDK
SWIFT_CLASS("_TtC6TGASDK6TGASdk")
@interface TGASdk : NSObject
/// 单利
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong) TGASdk * _Nonnull shared;)
+ (TGASdk * _Nonnull)shared SWIFT_WARN_UNUSED_RESULT;
/// 默认配置
@property (nonatomic, strong) TGAConfiguration * _Nonnull configuration;
/// bip支付数据回调
@property (nonatomic, strong) id <TGAPayInfoDelegate> _Nullable bipPayInfoDelegate;
/// 初始化SDK
/// \param env sdk区分环境的唯一值,可以传null或者空字符
///
/// \param appKey app对接密钥
///
/// \param userInfo 用户信息，如果userInfo返回null，游戏平台将以游客的身份登录
///
/// \param delegate 委托
///
- (BOOL)initSdkWithEnv:(NSString * _Nullable)env appKey:(NSString * _Nonnull)appKey userInfo:(TGAUserInfo * _Nullable)userInfo delegate:(id <TGASdkDelegate> _Nonnull)delegate SWIFT_METHOD_FAMILY(none);
/// 是否初始化
- (BOOL)isInited SWIFT_WARN_UNUSED_RESULT;
/// 退出登录
- (void)logout;
/// 打开游戏中心控制器
/// \param secUrl 打开游戏中心的同时再打开该网页，可用于打开游戏中心的同时跳到某一款游戏
///
/// \param secTitle 游戏页面的标题
///
/// \param theme 主题
///
- (BOOL)openGameCenterWithVc:(UIViewController * _Nonnull)vc secUrl:(NSString * _Nullable)secUrl secTitle:(NSString * _Nullable)secTitle theme:(NSString * _Nullable)theme;
- (void)closeAllWindow;
/// 设置日志等级
/// \param level TGALogLevel
///
- (void)setLogLevelWithLevel:(enum TGALogLevel)level;
- (void)onInAppPaySuccessWithOrderNo:(NSString * _Nonnull)orderNo;
- (void)onInAppPayFailureWithError:(PurchaseError * _Nonnull)error;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



@class NSError;
@class TGAShareInfo;

/// MARK - TGASDK Delegate
SWIFT_PROTOCOL("_TtP6TGASDK14TGASdkDelegate_")
@protocol TGASdkDelegate <NSObject>
/// 初始化成功
- (void)tgaSdkInitSucceed;
/// 初始化失败
/// \param error NSError
///
- (void)tgaSdkInitError:(NSError * _Nonnull)error;
/// 获取用户信息
/// 唤起app自身登录界面，当sdk是游客身份登录时，如果要充值，购买钻石等操作页面会弹出提示是否去登录，点击去登录回调
/// \param completion 回传用户Id，用户昵称，用户头像
///
- (void)tgaSdkGetUserInfoWithCompletion:(void (^ _Nonnull)(TGAUserInfo * _Nullable))completion;
/// 关闭游戏中心
- (void)tgaSdkCloseGameCenter;
/// 用户登出
- (void)tgaSdkOnLogout;
/// 用户分享
- (void)tgaOnInAppShareFromVC:(UIViewController * _Nonnull)fromVC shareInfo:(TGAShareInfo * _Nonnull)shareInfo completion:(void (^ _Nonnull)(NSString * _Nonnull, BOOL))completion;
@optional
- (void)tgaOnInAppPayFromVC:(UIViewController * _Nonnull)fromVC orderNo:(NSString * _Nonnull)orderNo;
@end


SWIFT_CLASS("_TtC6TGASDK12TGAShareInfo")
@interface TGAShareInfo : NSObject
@property (nonatomic, copy) NSString * _Nonnull callbackId;
@property (nonatomic, copy) NSString * _Nonnull iconUrl;
@property (nonatomic, copy) NSString * _Nonnull link;
@property (nonatomic, copy) NSString * _Nonnull title;
@property (nonatomic, copy) NSString * _Nonnull type;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


/// MARK - User Info
SWIFT_CLASS("_TtC6TGASDK11TGAUserInfo")
@interface TGAUserInfo : NSObject
/// 用户Id
@property (nonatomic, copy) NSString * _Nonnull userId;
/// 用户昵称
@property (nonatomic, copy) NSString * _Nonnull nickname;
/// 用户头像
@property (nonatomic, copy) NSString * _Nonnull avatar;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UITraitCollection;
@class UITouch;
@class UIEvent;

/// 布局视图基类，基类不支持实例化对象。在编程时我们经常会用到一些视图，这种视图只是负责将里面的子视图按照某种规则进行排列和布局，而别无其他的作用。因此我们称这种视图为容器视图或者称为布局视图。
/// 布局视图通过重载layoutSubviews方法来完成子视图的布局和排列的工作。对于每个加入到布局视图中的子视图，都会在加入时通过KVO机制监控子视图的center和bounds以及frame值的变化，每当子视图的这些属性一变化时就又会重新引发布局视图的布局动作。同时对每个视图的布局扩展属性的设置以及对布局视图的布局属性的设置都会引发布局视图的布局动作。布局视图在添加到非布局父视图时也会通过KVO机制来监控非布局父视图的frame值和bounds值，这样每当非布局父视图的尺寸变更时也会引发布局视图的布局动作。前面说的引起变动的方法就是会在KVO处理逻辑以及布局扩展属性和布局属性设置完毕后通过调用setNeedLayout来实现的，当布局视图收到setNeedLayout的请求后，会在下一个runloop中对布局视图进行重新布局而这就是通过调用layoutSubviews方法来实现的。布局视图基类只提供了更新所有子视图的位置和尺寸以及一些基础的设置，而至于如何排列和布局这些子视图则要根据应用的场景和需求来确定，因此布局基类视图提供了一个：
/// internal func tgCalcLayoutRect(_ size:CGSize, isEstimate:Bool, hasSubLayout:inout Bool!, sbs:[UIView]!, type:TGSizeClassType) ->CGSize
/// 的方法，要求派生类去重载这个方法，这样不同的派生类就可以实现不同的应用场景，这就是布局视图的核心实现机制。
/// TangramKit布局库根据实际中常见的场景实现了7种不同的布局视图派生类他们分别是：线性布局、表格布局、相对布局、框架布局、流式布局、浮动布局、路径布局。
SWIFT_CLASS("_TtC6TGASDK12TGBaseLayout")
@interface TGBaseLayout : UIView
- (void)safeAreaInsetsDidChange;
- (void)setNeedsLayout;
@property (nonatomic, readonly) CGSize intrinsicContentSize;
- (void)layoutSubviews;
- (void)traitCollectionDidChange:(UITraitCollection * _Nullable)previousTraitCollection;
- (CGSize)sizeThatFits:(CGSize)size SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, getter=isHidden) BOOL hidden;
- (void)awakeFromNib;
- (void)didAddSubview:(UIView * _Nonnull)subview;
- (void)willRemoveSubview:(UIView * _Nonnull)subview;
- (void)willMoveToSuperview:(UIView * _Nullable)newSuperview;
- (void)observeValueForKeyPath:(NSString * _Nullable)keyPath ofObject:(id _Nullable)object change:(NSDictionary<NSKeyValueChangeKey, id> * _Nullable)change context:(void * _Nullable)context;
- (void)touchesBegan:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (void)touchesMoved:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (void)touchesEnded:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (void)touchesCancelled:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end




/// *线性布局是一种里面的子视图按添加的顺序从上到下或者从左到右依次排列的单行(单列)布局视图。线性布局里面的子视图是通过添加的顺序建立约束和依赖关系的。
/// *根据排列的方向我们把子视图从上到下依次排列的线性布局视图称为垂直线性布局视图，而把子视图从左到右依次排列的线性布局视图则称为水平线性布局。
/// 垂直线性布局
/// +—––+
/// |   A   |
/// +—––+
/// |   B   |
/// +—––+  ⥥
/// |   C   |
/// +—––+
/// |  …  |
/// +—––+
/// 水平线性布局
/// +—–+—–+—–+—–+
/// |  A  |  B  |  C  | … |
/// +—–+—–+—–+—–+
/// ⥤
SWIFT_CLASS("_TtC6TGASDK14TGLinearLayout")
@interface TGLinearLayout : TGBaseLayout
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)willRemoveSubview:(UIView * _Nonnull)subview;
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
@end



/// *相对布局是一种里面的子视图通过相互之间的约束和依赖来进行布局和定位的布局视图。
/// *相对布局里面的子视图的布局位置和添加的顺序无关，而是通过设置子视图的相对依赖关系来进行定位和布局的。
/// *相对布局提供和AutoLayout等价的功能。
SWIFT_CLASS("_TtC6TGASDK16TGRelativeLayout")
@interface TGRelativeLayout : TGBaseLayout
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end















#endif
#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#if defined(__cplusplus)
#endif
#pragma clang diagnostic pop
#endif

#else
#error unsupported Swift architecture
#endif
