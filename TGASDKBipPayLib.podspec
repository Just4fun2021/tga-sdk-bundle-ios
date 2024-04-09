Pod::Spec.new do |s|
  s.name             = 'TGASDKBipPayLib'
  s.version          = '0.0.1'
  s.summary          = 'Bip Pay Plugin'
  s.homepage         = 'https://github.com/Just4fun2021/tga-sdk-bundle-ios'
  s.license          = { :type => 'MIT', :text => 'https://github.com/Just4fun2021/tga-sdk-bundle-ios/blob/master/LICENSE' }
  s.author           = { 'oauth2' => 'myplxdm@163.com' }
  s.source           = { :http => 'https://data.just4fun.sg/TGASDKBipPayLib1.4.0-0.0.1.zip', :type => 'zip'}

  s.requires_arc = true
  s.static_framework = true
  s.swift_versions = ['5']
  s.ios.deployment_target = '11.0'
  
  s.dependency 'TGAIOSSDK', '~> 1.4.0'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 armv7s arm64' }
  s.vendored_frameworks = "TGASDKBipPayLib1.4.0-#{s.version}/TGASDKApplovinLib.xcframework"
end
