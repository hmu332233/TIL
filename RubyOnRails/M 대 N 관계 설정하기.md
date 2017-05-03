## M : N 관계 설정하기

![has_many_through](http://i.imgur.com/af7ZDmV.jpg)

- M : N 관계는 다음과 같이 이 둘을 이어주는 매개체인 model을 하나 더 만들어야한다.

#### 적용법

위의 예제 사진을 기준으로 코드를 작성해보면

**app/models/Physician.rb**
```ruby
class Physician < ActiveRecord::Base

has_many :patients, through: :appointments
has_many :appointments

end
```

**app/models/Patient.rb**
```ruby
class Patient < ActiveRecord::Base

has_many :physicians, through: :appointments
has_many :appointments

end
```

**app/models/Appointment.rb**
```ruby
class Appointment < ActiveRecord::Base

belongs_to :physician
belongs_to :patient

end
```

다음으로 migration 파일에서

**db/migrate/~~~_create_ducks.rb**
```ruby
class CreateAppointments < ActiveRecord::Migration
  def change
    create_table :appointments do |t|

    t.integer :physician_id
    t.integer :patient_id

    t.timestamps null: false
    end
  end
end
```

#### 사용

```ruby
physician = Physician.create

patient = Patient.create

physician.patients << patient

patient.physicians << physician

```
