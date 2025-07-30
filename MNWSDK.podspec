#
# Be sure to run `pod lib lint MNWSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MNWSDK'
  s.version          = '1.4.7'
  s.summary          = 'A short description of MNWSDK.'

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/zy765450034/MNWSDK'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'wuweiwei' => 'wuwiewei@mini1.cn' }
  s.source           = { :git => 'https://github.com/zy765450034/MNWSDK.git', :tag => s.version.to_s }

  s.ios.deployment_target = '13.0'
#  s.static_framework = true
#  s.vendored_frameworks = 'MNWSDK/MNWSDK.xcframework'
#  s.resource = 'MNWSDK/MNWSDK.bundle'
#  s.preserve_paths = 'MNWSDK/MNWSDK.bundle'
  
  s.subspec 'Core' do |core|
    core.vendored_frameworks = 'MNWSDK/MNWSDK.xcframework'
    core.resource = 'MNWSDK/MNWSDK.bundle'
    core.preserve_paths = 'MNWSDK/MNWSDK.bundle'
    
  end
  s.default_subspec = 'Core'
  
  s.subspec 'IAP' do |iap|
      iap.vendored_frameworks = 'MNWSDK/IAPComm.xcframework' # 假设你也有 xcframework
      iap.dependency 'MNWSDK/Core'
  end
  
end
