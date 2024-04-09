Pod::Spec.new do |s|
  s.name             = 'TGASDKApplovinLib'
  s.version          = '0.0.1'
  s.summary          = 'A short description of TGASDKApplovinLib.'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/Just4fun2021/tga-sdk-bundle-ios'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'oauth2' => 'myplxdm@163.com' }
  s.source           = { :http => 'https://data.just4fun.sg/TGASDKApplovinLib1.4.0-0.0.1.zip' :type => 'zip'}
  
  s.requires_arc = true
  s.static_framework = true
  s.swift_versions = ['5']
  s.ios.deployment_target = '11.0'
  
  s.dependency 'TGAIOSSDK', '~> 1.4.0'
  s.vendored_frameworks = "TGASDKApplovinLib1.4.0-0.0.1/TGASDKApplovinLib.xcframework"
end
