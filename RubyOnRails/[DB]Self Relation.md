## Self Relation

- model이 본인 스스로와 관계를 생성해야 할 때가 있다.  
  ex) user를 멘토, 멘티로 나누어  
  '멘토는 멘티를 가지고있다' 이런 관계를 가지고 싶을 때

- 아래와 같이 하면 된다

**migrate 파일**
```ruby
class DeviseCreateUsers < ActiveRecord::Migration
  def change
    create_table :users do |t|
      ... 생략
      # 외래키
      t.integer    :mentor_user_id
  end
end
```

**models/User.md**
```ruby

belongs_to :mentor, :class_name => "User", :foreign_key => "mentor_user_id"
has_many :mentees, :class_name => "User", :foreign_key => "mentor_user_id"
```
