## route path name 지정하기

rails에서는 route를 `/user/new`와 같이 되어있는 부분을 `as`라는 키워드를 통해 알기 쉽게 이름을 지정할 수 있다

```ruby
# routes.rb
get 'posts/new' as 'create_post'
```
이렇게 하면
```
<%= link_to '작성', '/posts/new' %>
<%= link_to '작성', create_post_path %>
```
와 같이 사용이 가능해진다.
