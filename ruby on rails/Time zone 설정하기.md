## Time zone 설정하기

- Ruby on Rails의 Timezone defauls 값은 UTC(협정세계시)이다.
- 이는 우리나라 보다 9시간이 느리다.( 한국은 UTC+9 )
<br/>
- `config/application.rb`에 `config.time_zone = 'Seoul'`을 추가하는 것으로 간단하게 변경 가능!

#### 전체코드

**config/application.rb**
```ruby
require File.expand_path('../boot', __FILE__)

require 'rails/all'

# Require the gems listed in Gemfile, including any gems
# you've limited to :test, :development, or :production.
Bundler.require(*Rails.groups)

module Workspace
  class Application < Rails::Application
    # Settings in config/environments/* take precedence over those specified here.
    # Application configuration should go into files in config/initializers
    # -- all .rb files in that directory are automatically loaded.

    # Set Time.zone default to the specified zone and make Active Record auto-convert to this zone.
    # Run "rake -D time" for a list of tasks for finding time zone names. Default is UTC.
    # config.time_zone = 'Central Time (US & Canada)'
    # The default locale is :en and all translations from config/locales/*.rb,yml are auto loaded.
    # config.i18n.load_path += Dir[Rails.root.join('my', 'locales', '*.{rb,yml}').to_s]
    # config.i18n.default_locale = :de

    # Do not swallow errors in after_commit/after_rollback callbacks.
    config.active_record.raise_in_transactional_callbacks = true
    
    config.time_zone = 'Seoul' #애가 추가 되었다
  end
end

```
