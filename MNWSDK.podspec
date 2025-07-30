#
# Be sure to run `pod lib lint MNWSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'MNWSDK'
  s.version          = '1.4.10'
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
      iap.vendored_frameworks = 'MNWSDK/IAPComm.xcframework'
      iap.dependency 'MNWSDK/Core'
  end
  
  s.subspec 'AppleSignIn' do |appleSignIn|
    appleSignIn.vendored_frameworks = 'MNWSDK/AppleComm.xcframework'
    appleSignIn.dependency 'MNWSDK/Core'
  end
  
  s.subspec 'JVerification' do |jVerification|
    jVerification.vendored_frameworks = 'MNWSDK/JVerificationComm.xcframework'
    jVerification.resource = 'MNWSDK/JVerificationComm.bundle'
    jVerification.preserve_paths = 'MNWSDK/JVerificationComm.bundle'
    jVerification.dependency 'MNWSDK/Core'
    jVerification.dependency 'JCore',"5.0.2"
    jVerification.dependency 'JVerification','3.4.2'
  end
  
  s.subspec 'QQSignIn' do |qqSignIn|
    qqSignIn.vendored_frameworks = 'MNWSDK/QQComm.xcframework'
    qqSignIn.dependency 'MNWSDK/Core'
    qqSignIn.dependency 'TencentOpenAPI',"1.0.0"
  end
  
  s.subspec 'WechatSignIn' do |wechatSignIn|
    wechatSignIn.vendored_frameworks = 'MNWSDK/WeChatComm.xcframework'
    wechatSignIn.dependency 'MNWSDK/Core'
    wechatSignIn.dependency 'WechatOpenSDK',"2.0.4"
  end
  
  s.subspec 'GoogleSignIn' do |googleSignIn|
    googleSignIn.vendored_frameworks = 'MNWSDK/GooglePlusComm.xcframework'
    googleSignIn.dependency 'MNWSDK/Core'
    googleSignIn.dependency 'GoogleSignIn',"8.0.0"
  end
  
  s.subspec 'FacebookSignIn' do |facebookSignIn|
    facebookSignIn.vendored_frameworks = 'MNWSDK/FacebookComm.xcframework'
    facebookSignIn.dependency 'MNWSDK/Core'
    facebookSignIn.dependency 'FBSDKLoginKit','17.4.0'
  end
  
  s.subspec 'VKIDSignIn' do |vkIdSignIn|
    vkIdSignIn.vendored_frameworks = 'MNWSDK/VKIDComm.xcframework'
    vkIdSignIn.dependency 'MNWSDK/Core'
    vkIdSignIn.dependency 'VK-ios-sdk','1.6.4'
  end
  
  s.subspec 'YandexSignIn' do |yandexSignIn|
    yandexSignIn.vendored_frameworks = 'MNWSDK/YandexComm.xcframework'
    yandexSignIn.dependency 'MNWSDK/Core'
    yandexSignIn.dependency 'YandexLoginSDK','3.0.2'
  end
  s.subspec 'FIRPush' do |firPush|
    firPush.vendored_frameworks = 'MNWSDK/FIRPushComm.xcframework'
    firPush.dependency 'MNWSDK/Core'
    firPush.dependency 'FirebaseAnalytics','11.14.0'
    firPush.dependency 'FirebaseMessaging','11.14.0'
  end
  
end
