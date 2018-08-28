

Pod::Spec.new do |s|

  s.name         = 'RJReadSDK'

  s.version      = '1.3.4'

  s.summary      = '人教点读SDK'

  s.author       = { 'PEP' => 'lipz@pep.com.cn' }

  s.platform     =  :ios, '7.0'

  s.homepage     = 'https://github.com/PEPDigitalPublishing/RJReadSDK'

  s.source       = { :git => 'https://github.com/PEPDigitalPublishing/RJReadSDK.git', :tag => s.version }

  s.vendored_frameworks = 'RJReadSDK.framework'

  s.resource = 'RJReadSDK.bundle'

  s.frameworks   = 'AVFoundation', 'Security', 'CoreMotion', 'QuartzCore'

  s.dependency 'MRCircularProgressView'
  s.dependency 'MJExtension'
  s.dependency 'MJRefresh'
  s.dependency 'AFNetworking'
  s.dependency 'Masonry'
  s.dependency 'SDWebImage'
#  s.dependency 'SSZipArchive'

#  s.dependency 'PEPBigData', :git => 'https://github.com/PEPDigitalPublishing/PEPBigData.git'

#  此处为讯飞语音SDK，可以不从该地址下载，但是必须保证项目中存在iflyMSC.framework
#  s.dependency 'PEPiFlyMSC', :git => 'https://github.com/PEPDigitalPublishing/PEPiFlyMSC.git'

#  此处为一起作业语音SDK，仅提供给一起作业使用，其他对接方请勿使用此SDK
#  s.dependency 'YIQISpeechEngine', :git => 'https://gitee.com/guxiong/YIQISpeechEngine.git'


  s.requires_arc = true

end



















