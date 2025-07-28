
# Pod::Spec.new do |spec|

#   spec.name         = "MNWSDK"
#   spec.version      = "0.0.8"
#   spec.summary      = "A short description of MNWSDK."

#   spec.ios.deployment_target = '12.0'
#   spec.homepage     = "http://EXAMPLE/MNWSDK"

#   spec.author             = { "wuweiwei" => "wuwiewei@mini1.cn" }
 
#   spec.source       = { :git => "https://github.com/zy765450034/MNWSDK.git", :tag => "#{spec.version}" }

#   spec.vendored_frameworks = 'MNWSDK.framework'
#   spec.resources = 'MNWSDK.bundle'
 

#   spec.subspec 'IAP' do |iap|
#     iap.vendored_frameworks = 'IAPComm.framework'
#   end

# end
Pod::Spec.new do |spec|

  spec.name         = "MNWSDK"
  spec.version      = "0.0.8"
  spec.summary      = "A short description of MNWSDK."

  spec.ios.deployment_target = '12.0'
  spec.homepage     = "https://github.com/zy765450034/MNWSDK"

  spec.author       = { "wuweiwei" => "wuwiewei@mini1.cn" }
  spec.source       = { :git => "https://github.com/zy765450034/MNWSDK.git", :tag => spec.version.to_s }

  spec.vendored_frameworks = 'MNWSDK.framework'
  spec.resources = 'MNWSDK.bundle'

  spec.subspec 'IAP' do |iap|
    iap.vendored_frameworks = 'IAPComm.framework'
  end

end