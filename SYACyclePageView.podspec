
Pod::Spec.new do |s|
  s.name         = "SYACyclePageView"
  s.version      = "0.0.1"
  s.summary      = "iOS图片无限轮播框架,支持三种轮播方式"
  s.homepage     = "https://github.com/geekGetup/SYACyclePageView"
  s.license      = "MIT"
  s.author             = { "geekGetup" => "1044212178@qq.com" }
  s.platform     = :ios
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/geekGetup/SYACyclePageView.git", :tag => "#{s.version}" }
  s.source_files  = "CyclePageView", "CyclePageView/**/*.{h,m}"
  s.framework  = "UIKit"
end
