#
#  Be sure to run `pod spec lint MNWSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|

  spec.name         = "MNWSDK"
  spec.version      = "0.0.3"
  spec.summary      = "A short description of MNWSDK."

  spec.ios.deployment_target = '12.0'
  spec.homepage     = "http://EXAMPLE/MNWSDK"

  spec.author             = { "wuweiwei" => "wuwiewei@mini1.cn" }
 
  spec.source       = { :git => "https://github.com/zy765450034/MNWSDK.git", :tag => "#{spec.version}" }



  spec.source_files  = "Classes", "Classes/**/*.{MNWSDK,bundle}"
  spec.exclude_files = "Classes/Exclude"

  spec.subspec 'IAP' do |iap|
    iap.source_files = 'MultiSDK/Classes/IAP/**/*'
  end

end
