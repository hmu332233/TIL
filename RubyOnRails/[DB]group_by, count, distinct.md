## rails db district 이용하기

#### DISTINCT란?
- db에서 중복된 결과들 중에 하나만 원할 때 사용하는 명령어

#### 코드
```ruby
Post.create(:user_id => 1, :created_on => '2010-09-29')
Post.create(:user_id => 1, :created_on => '2010-09-29')
Post.create(:user_id => 2, :created_on => '2010-09-29')
Post.create(:user_id => null, :created_on => '2010-09-29')

Post.group(:created_on).count
# => {'2010-09-29' => 4}

Post.group(:created_on).count(:user_id)
# => {'2010-09-29' => 3}

Post.group(:created_on).count(:user_id, :distinct => true) # Rails <= 3
Post.group(:created_on).distinct.count(:user_id) # Rails = 4
# => {'2010-09-29' => 2}
```

```ruby
User.count(:name, :distinct => true)
# => 3
 ________
| name   |
|--------|
| John   |
| John   |
| Jane   |
| Joey   |
|________|
```
would return 3 if you have user with name John, John, Jane, Joey (for example) in the database.

#### 출처
- [(stackoverflow) How can I count the number of records that have a unique value in a particular field in ROR?](http://stackoverflow.com/questions/36608/how-can-i-count-the-number-of-records-that-have-a-unique-value-in-a-particular-f)
- [(stackoverflow) How to count group by rows in rails?](http://stackoverflow.com/questions/1647910/how-to-count-group-by-rows-in-rails)
