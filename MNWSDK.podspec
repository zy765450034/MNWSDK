#
#  Be sure to run `pod spec lint MNWSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

# Pod::Spec.new do |spec|

#       = "MNWSDK"
#   spec.version      = "0.0.1"
#   spec.summary      = "A short description of MNWSDK."

#   spec.ios.deployment_target = '12.0'
#   spec.homepage     = "http://EXAMPLE/MNWSDK"


#   spec.author             = { "wuweiwei" => "wuwiewei@mini1.cn" }

#   spec.source       = { :git => "https://github.com/zy765450034/MNWSDK.git", :tag => "#{spec.version}" }
#   spec.source_files  = "Classes", "Classes/**/*.{h,m}"
#   spec.exclude_files = "Classes/Exclude"

 
# end

Pod::Spec.new do |s|
  s.name             = 'MNWSDK'
  s.version          = '0.0.1'

  s.source           = { :git => 'https://github.com/zy765450034/MNWSDK.git', :tag => s.version.to_s }

  s.subspec 'MNWSDK' do |core|
    core.source_files = 'Sources/MNWSDK/**/*'
  end

  s.subspec 'IAP' do |ui|
    ui.source_files = 'Sources/IAP/**/*'
    # ui.dependency 'MySDK/Core'
  end
end