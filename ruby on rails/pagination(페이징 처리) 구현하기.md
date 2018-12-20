### 페이징 처리 구현하기
- [kaminari](https://github.com/kaminari/kaminari)라는 gem을 이용하면 쉽게 구현이 가능하다.

#### 사용법
사용법은 매우 간단하다.  
다음과 같이 controller와 view에 추가해 주기만 하면  
기본적인 페이징처리는 바로 해준다.
- **controller**
```ruby
@posts = Post.page params[:page]
```
- **view**
```
<% @posts.each do |post| %>
<p><%= post.title%> : <%= post.content%></p>
<% end %>
<%= paginate @posts %>
```
<br/>

**config 변경**
  - page당 25개가 default로 되어있는데 이러한 default 값들을 수정하는 방법은 다음과 같다
```bash
$ rails g kaminari:config
```
- 하면 다음과 같은 파일이 추가되고 여기서 각 종 설정을 변경할 수 있다
```ruby
# config/initializers/kaminari_config.rb

# frozen_string_literal: true
Kaminari.configure do |config|
  config.default_per_page = 5
  # config.max_per_page = nil
  # config.window = 4
  # config.outer_window = 0
  # config.left = 0
  # config.right = 0
  # config.page_method_name = :page
  # config.param_name = :page
  # config.params_on_first_page = false
end
```
```
페이지 당 model 갯수
config.default_per_page = 5

config.max_per_page = nil

현재페이지를 기준으로 양옆에 나오는 숫자 갯수
config.window = 4

 시작과 끝 페이지 보여주는 갯수 1,2 .. 567 .. 9,10
config.outer_window = 0

시작 페이지 보여주는 갯수 1,2 ...
config.left = 2

끝 페이지 보여주는 갯수 ... 8,9,10
config.right = 3

config.page_method_name = :page
config.param_name = :page
config.params_on_first_page = false
```

#### 직접구현
- 간단한 페이징은 사실 직접 구현도 어렵지 않다
- `default_per_page=5` 기준으로 코드를 짜보자면
```ruby
@posts = Post.page(6)
# 은
@posts = Post.offset(25).limit(5)
# 와 같은 역활을 해준다
```

#### locale 설정
- `Rails.root/config/locales`에서 아래와 같은 내용을 수정해주면 된다
- [참고](https://github.com/kaminari/kaminari#i18n-and-labels)
```
en:
  views:
    pagination:
      first: "&laquo; First"
      last: "Last &raquo;"
      previous: "&lsaquo; Prev"
      next: "Next &rsaquo;"
      truncate: "&hellip;"
  helpers:
    page_entries_info:
      one_page:
        display_entries:
          zero: "No %{entry_name} found"
          one: "Displaying <b>1</b> %{entry_name}"
          other: "Displaying <b>all %{count}</b> %{entry_name}"
      more_pages:
        display_entries: "Displaying %{entry_name} <b>%{first}&nbsp;-&nbsp;%{last}</b> of <b>%{total}</b> in total"
```
- 예시
```
views:
  pagination:
    first: "시작"
    last: "마지막"
    previous: "이전"
    next: "다음"
    truncate: "헤헤"
```
