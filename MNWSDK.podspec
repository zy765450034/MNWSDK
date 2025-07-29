#
# Be sure to run `pod lib lint MNWSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MNWSDK'
  s.version          = '1.3.1'
  s.summary          = 'A short description of MNWSDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/zy765450034/MNWSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'wuweiwei' => 'wuwiewei@mini1.cn' }
  s.source           = { :git => 'https://github.com/zy765450034/MNWSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '13.0'
  s.static_framework = true
  s.vendored_frameworks = 'MNWSDK/Assets/MNWSDK.xcframework'
  
  
  # s.resource_bundles = {
  #   'MNWSDK' => ['MNWSDK/Assets/*.png']
  # }

   
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
#  s.source_files = 'MNWSDK/Classes/**/*'
#  s.public_header_files = 'Pod/Classes/**/*.h'
#  s.pod_target_xcconfig = {
#      'ARCHS[sdk=iphoneos*]' => 'arm64 x86_64',
#      'ARCHS[sdk=iphonesimulator*]' => 'arm64 x86_64', # 模拟器不包含任何架构
#      'VALID_ARCHS' => 'arm64 x86_64',
#      
#    }
#    
#    # 确保主项目也应用这些设置
#    s.user_target_xcconfig = {
#      'ARCHS[sdk=iphoneos*]' => 'arm64',
#      'ARCHS[sdk=iphonesimulator*]' => '',
#      'VALID_ARCHS' => 'arm64'
#    }
#s.pod_target_xcconfig = {
#   'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' # 如果不想支持模拟器 arm64
# }
#s.pod_target_xcconfig = {
#  'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 x86_64' # 完全排除模拟器
#}
end
