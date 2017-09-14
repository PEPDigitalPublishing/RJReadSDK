

Pod::Spec.new do |s|

  s.name         = 'RJReadSDK'

  s.version      = '1.1.0'

  s.summary      = '人教点读SDK'

  s.author       = { 'RJReadSDK' => 'PEP' }

  s.platform     =  :ios, '7.0'

  s.homepage     = 'https://gitlab.com/PEP_Public/RJReadSDK'

  s.source       = { :git => 'https://gitlab.com/PEP_Public/RJReadSDK.git', :tag => s.version }

  s.vendored_frameworks = 'RJReadSDK.framework'

  s.resource = 'RJReadSDK.bundle'

  s.frameworks   = 'AVFoundation', 'Security', 'CoreMotion', 'QuartzCore'

  s.dependency 'LEColorPicker', '~>1.0.3'
  s.dependency 'MRCircularProgressView', '~> 0.3.0'
  s.dependency 'MJExtension', '~>2.5.16'
  s.dependency 'MJRefresh'
#  s.dependency 'iflyMSC/ifly', :git => 'https://gitlab.com/PEP_Public/iflyMSC.git'
#  s.dependency 'chivox', :git => 'https://gitlab.com/PEP_Public/chivox.git'
  s.dependency 'AFNetworking', '~>3.1.0'
  s.dependency 'Masonry', '~> 1.0.2'
  s.dependency 'SDWebImage', '~> 3.8.2'
  s.dependency 'RegexKitLite-NoWarning', '~> 1.1.0'
  s.dependency 'ZipArchive', '~> 1.4.0'

  s.requires_arc = true

end









