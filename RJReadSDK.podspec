

Pod::Spec.new do |s|

  s.name         = 'RJReadSDK'

  s.version      = '1.2.0'

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

# 以下分别为【讯飞语音SDK】和【一起作业语音SDK】，二者必须依赖其一，也可同时存在
#  s.dependency 'iflyMSC/ifly', :git => 'https://gitlab.com/PEP_Public/iflyMSC.git'
#  s.dependency 'YIQISpeechEngine', :git => 'https://gitee.com/guxiong/YIQISpeechEngine.git'


  s.requires_arc = true

end









