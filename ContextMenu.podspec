Pod::Spec.new do |s|
  s.name             = "ContextMenu"
  s.version          = "1.0.0"
  s.summary          = "Animated menu."
  s.description      = <<-DESC
                        An awesome animated context menu to your iOS app.
                        DESC
  s.homepage         = "http://yalantis.com"
  s.license          = 'Apache'
  s.author           = { "Yalantis" => "maximletushov@gmail.com" }
  s.source           = { :git => "https://github.com/Yalantis/Context-Menu.iOS.git", :tag => s.version.to_s }

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'YALContextMenu/*'

  s.public_header_files = 'YALContextMenu/*.h'
end
