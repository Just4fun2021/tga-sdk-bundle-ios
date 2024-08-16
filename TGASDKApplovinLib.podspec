# 定义版本号变量
ios_sdk_version = '1.4.0'
version_number = '0.0.2'

# 构建 source 字段中的 URL
source_url = "https://data.just4fun.sg/TGASDKApplovinLib#{ios_sdk_version}-#{version_number}.zip"

# 构建 vendored_frameworks 字段中的路径
vendored_frameworks_path = "TGASDKApplovinLib1.4.0-#{version_number}/TGASDKApplovinLib.xcframework"

# 在 Pod::Spec.new 块中使用变量
Pod::Spec.new do |s|
  s.name             = 'TGASDKApplovinLib'
  s.version          = version_number
  s.summary          = 'AppLovin Advertising Plugin.'
  s.homepage         = 'https://github.com/Just4fun2021/tga-sdk-bundle-ios'
  s.license          = { :type => 'MIT', :text => 'https://github.com/Just4fun2021/tga-sdk-bundle-ios/blob/master/LICENSE' }
  s.author           = { 'oauth2' => 'myplxdm@163.com' }
  s.source           = { :http => source_url, :type => 'zip'}
  
  s.requires_arc = true
  s.static_framework = true
  s.swift_versions = ['5']
  s.ios.deployment_target = '11.0'
  
  s.dependency 'TGAIOSSDK', '~> 1.4.0'
  s.dependency 'AppLovinSDK', '~> 11.5.1'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 armv7s arm64' }
  s.vendored_frameworks = vendored_frameworks_path
end
