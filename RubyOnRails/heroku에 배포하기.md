## Herkou 에 배포(Deploy) 하기.

### What is "Heroku"
https://www.heroku.com/what

### 공식 문서 (rails 4.x)
https://devcenter.heroku.com/articles/getting-started-with-rails4

***

#### Gemfile 수정하기.

1. `Gemfile`의 현재 모습 (가독성을 위해 주석 제거.)

```
source 'https://rubygems.org'

gem 'rails', '4.2.5'
gem 'sass-rails', '~> 5.0'
gem 'sqlite3'
gem 'uglifier', '>= 1.3.0'
gem 'coffee-rails', '~> 4.1.0'
gem 'jquery-rails'
gem 'turbolinks'
gem 'jbuilder', '~> 2.0'
gem 'sdoc', '~> 0.4.0', group: :doc

group :development, :test do
 gem 'byebug'
end

group :development do
 gem 'web-console', '~> 2.0'
 gem 'spring'
end
```

2. `gem 'sqlite3'` 를 `group :devlopment, :test`로 옮긴다.
3. `group :production` 을 만든다.
4. `groupt :production` 에 `gem 'pg'` 와 `gem 'rails_12factor'` 를 추가한다.
5. `Gemfile` 의 최종 모습

```
source 'https://rubygems.org'

gem 'rails', '4.2.5'
gem 'sass-rails', '~> 5.0'
gem 'uglifier', '>= 1.3.0'
gem 'coffee-rails', '~> 4.1.0'
gem 'jquery-rails'
gem 'turbolinks'
gem 'jbuilder', '~> 2.0'
gem 'sdoc', '~> 0.4.0', group: :doc

group :development, :test do
  gem 'byebug'
  gem 'sqlite3'
end

group :development do
  gem 'web-console', '~> 2.0'
  gem 'spring'
end

group :production do
  gem 'pg'
  gem 'rails_12factor'
end
```
`$ bundle install` **-** `Gemfile` 수정 반영하기.

1. 서버가 켜져 있다면 (Run project) 중이라면, 서버를 멈춘다 (Stop).
2. 터미널에 `$ bundle install` 이라고 입력한다.
3. 새로 추가한 gem 들이 설치되고 `undle complete!` 를 포함한 구문이 나오면 성공.

***

### git 사용하기.

#### 처음 할 때.

```
$ git init
$ git add .
$ git commit -m "Jackpot checker first commit."
```

### 두번 째 이후 (수정사항 반영할 때).

```
$ git add .
$ git commit -m "의미있는 메세지를 짧게"
```

***

### Heroku 사용하기.

#### Heroku 가입.

1. https://www.heroku.com/ 가입
2. Log in 이후, https://dashboard.heroku.com/account/billing 에서 카드 등록 (등록하면 1개의 app을 1달 내내 무료로 사용 가능.)

#### Heroku 설치 - 로그인 - app 만들기.

1. `$ sudo apt-get install heroku` (c9 에 자동으로 설치되어 있는것으로 보임)
2. `$ heroku login` (가입한 e-mail 과 password 입력)
3. `$ heroku create` [app_name] ( [app_name].herokuapp.com 이 [root_url] 이 된다. )

#### Heroku 에 배포하기.

1. `$ git push heroku master` ( 수정사항이 있다면 git commit 이후에)
2. `$ heroku run rake db:migrate` (DB 를 사용한다면. 현재 단계에서는 필요 없음)

#### 확인하기.

- [app_name].herokuapp.com 으로 접속.
