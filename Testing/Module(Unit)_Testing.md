## Module(Unit) Testing [모듈(단위) 테스팅]

### 유닛테스팅이란
- 개별적인 서브프로그램, 서브루틴, 클래스, 또는 프로시저를 테스트하는 프로세스
- 프로그램 전체를 테스팅하기 보다 프로그램의 작은 구성 단위를 테스트하는 프로세스

### 유닛테스팅의 이유
1. 테스팅의 결합된 요소를 단순화해서 관리하는 방법
2. 오류 발견 시 어느 모듈에 오류가 있는지를 알 수 있음
3. 발견된 오류를 정확히 찾고 수정하는 디버깅 작업을 쉽게함
4. 다중 모듈을 동시에 테스트할 수 있어 테스팅 프로세스를 병렬화시킴

### 테스트케이스의 설계
- 모듈테스트는 일반적으로 화이트박스 중심
- 모듈의 로직을 화이트박스 방법으로 분석한 후, 모듈의 명세에 블랙박스 방법을 적용해 테스트케이스를 보완하는 방법으로 설계한다.

### 설계방법
1. 프로그램의 분기문을 나열한다.
2. 사용할 화이트박스 설계 방법을 선택한 후 테스트케이스를 작성한다.
3. 명세를 보고 블랙박스 테스트의 테스트케이스를 작성한다.


### 점진적 테스트와 비점진적 테스트
#### 비점진적 테스트
- 각 모듈은 독립적으로 테스트하고 모듈을 묶어서 하나의 프로그램을 만들어야하는가?
- 빅행 테스팅 또는 통합
#### 점진적 테스트
- 모듈을 테스트된 모듈과 결합해가며 테스트하는가?

### 비점진적 테스트
- 특별한 `driver mudule`과 하나 이상의 `stub module`이 필요
#### driver module
- 테스트하려는 module의 위에서 호출해주는 역할을 하는 module
#### stub module
- 테스트하려는 module의 하위에서 return만 해주는 역할을 하는 module
- 테스트하려는 module이 호출될 때 제어를 돕는 무언가의 역할을 하는 module

### 점진적 테스트
- 각 모듈을 분리해 테스트하는 대신 테스트할 모듈을 이미 테스트된 모듈과 결합하여 테스트
#### Top-Down Testing(하양식 테스팅)
- 프로그램의 상단 또는 초기 모듈(가장 큰 틀)부터 시작한다.
- 주요 결함이 프로그램의 상위에서 발생한다면 유리하다
- 초기 프로그램의 구조로 시연 가능하다.


- stub module을 만들어야한다.

#### Bottom-UP Testing(상향식 테스팅)
- 프로그램의 단말 모듈(다른 모듈을 호출하지 않는 모듈)부터 시작한다.
- 초기 프로그램 구조에 대한 개념이 없다.


- driver module을 만들어야한다.
- driver module은 stub module에 비해 만들기 쉽다.