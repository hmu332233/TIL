## postion
- `float`는 쥬르르 옆으로 세워둔 느낌이고 `position`은 꽝! 박아두는 느낌
- `position: static|relative|absolute|fixed`
- `top|bottom|left|right: 00px`
- `top|bottom`, `left|right` 각 하나씩만 써주면 된다

#### static
- 모든 요소들의 기본 position
- position이 static이면 움직일 수 없다

#### relative
- 자기가 원래 있었던 위치 기준으로 이동시키는게 가능
![a](/assets/html/position_relative.PNG)

#### absolute
- float와 매우 비슷, 거의 버린자식
- 다른 자식들이 그 아이의 위치를 아에 모름 덮어버림
- **기준점** 을 새로 정할 수 있는 무시무시한 녀석
![a](/assets/html/position_absolute.PNG)

#### fixed
- **viewport** 를 기준으로 배치된다
