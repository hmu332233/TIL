## Redux

- 컴포넌트끼리 데이터 교류 및 state 관리를 쉽고 효율적으로 할 수 있게 해주는 라이브러리
- [이해를 돕는 카툰 - redux](http://bestalign.github.io/2015/10/26/cartoon-intro-to-redux/)
- flux 아키텍처를 좀 더 편하게 사용할 수 있도록 만들어주는 라이브러리
  - flux란
  ```
  Action -> Dispatcher -> Store -> View
  ```
  - Dispatcher가 받은 action을 통제하여  
    store에 있는 데이터를 업데이트하고  
    변경된 데이터가 있다면 view를 reRendering 한다
  - [이해를 돕는 카툰 - flux](ttp://bestalign.github.io/2015/10/06/cartoon-guide-to-flux/)


### 3가지 원칙
- **Single Source of Truth**
  - 어플리케이션의 state를 위해 단 한 개의 store를 사용한다.
  - flux와의 주요 차이점
  - flux에서는 여러 store를 사용

- **state is Read-only**
  - 어플리케이션에서 store의 state를 직접 변경할 수 없다.
  - state를 변경하기 위해선 무조건 action이 Dispatch 되어야 한다.

- **changes are made with pure Functions**
  - `action객체`를 처리하는 함수를 `reducer` 라고 한다.
  - `reducer`는 정보를 받아서 상태를 어떻게 업데이트 할 지 정의한다.
  - `reducer`는 '순수 함수'로 작성되어야한다.
    - 네트워크 및 데이터베이스 접근x, 인수 변경 x
    - 같은 인수로 실행된 함수는 언제나 같은 결과를 반환
    - 순수하지 않은 api 사용 불가 (Data.now(), Math,random())등
