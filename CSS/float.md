## float
- 붕뜨다?
- **특징1**
  - float 속성을 가진 자식이 있으면 부모는 자식이 집을 나갔다고 생각한다
  - 부모 내의 다른 자식들은 float속성을 가진 아이가 없다고 생각하고 배치되고 부모도 그 아이가 없다고 생각하고 height가 정해진다
- **특징2**
  - float 되는 순간 자동으로 block이 된다
  - block이든 inline이든 자동으로 block이 된다
- **특징3**
  - 길막을 하지 못하는 이상한 block
  - 별도의 width 값이 없으면 자신이 가진 콘텐츠만큼만 늘어나게 된다 ( 원래 block은 별도의 width 값이 없으면 `width: 100%` 였다 )
  - 별도의 width 값이 있어도 자동으로 생기는 margin이 생기지 않는다 ( 원래 block은 별도의 width 값이 있으면 남는 width를 자동으로 margin으로 체워줬다 )
- **특징4**
  - inline 애들은 float 된 애들을 볼 수 있어서 배치에 영향을 받는다
### float 때문에 박살난 마크업 바로잡기
- **방법1**
  - 부모에게 `overflow: hidden` 넣으면 잡힌다
- **방법2**
  - 정석! `clearfix`
  - `clear: left|both|right` : float의 저 속성을 가진 아이는 볼 수 있게 된다

### clearfix의 응용
- 가상요소
  - `::before`, `::after`
![a](/assets/html/clearfix2.PNG)
![a](/assets/html/clearfix.PNG)
