

Pod::Spec.new do |s|

  s.name         = 'RJReadSDK'

  s.version      = '1.2.1'

  s.summary      = '人教点读SDK'

  s.author       = { 'RJReadSDK' => 'PEP' }

  s.platform     =  :ios, '8.0'

  s.homepage     = 'https://github.com/PEPDigitalPublishing/RJReadSDK'

  s.source       = { :git => 'https://github.com/PEPDigitalPublishing/RJReadSDK.git', :tag => s.version }

  s.vendored_frameworks = 'RJReadSDK.framework'

  s.resource = 'RJReadSDK.bundle'

  s.frameworks   = 'AVFoundation', 'Security', 'CoreMotion', 'QuartzCore'

  s.dependency 'LEColorPicker'
  s.dependency 'MRCircularProgressView'
  s.dependency 'MJExtension'
  s.dependency 'MJRefresh'
  s.dependency 'AFNetworking'
  s.dependency 'Masonry'
  s.dependency 'SDWebImage'
  s.dependency 'RegexKitLite-NoWarning'
  s.dependency 'SSZipArchive'


#  此处为讯飞语音SDK，可以不从该地址下载，但是必须保证项目中存在iflyMSC.framework
#  s.dependency 'PEPiFlyMSC', :git => 'https://github.com/PEPDigitalPublishing/PEPiFlyMSC.git'
#  s.dependency 'YIQISpeechEngine', :git => 'https://gitee.com/guxiong/YIQISpeechEngine.git'


  s.requires_arc = true

end



















