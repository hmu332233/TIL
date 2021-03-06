## White-Box Test ( 화이트박스 테스트 )

### 정의
**화이트박스 테스트** 는 로직 기반(logic-driven) 테스트 라고도 부르며  
프로그램의 내부 구조를 확인하고, 프로그램의 논리적인 경로를 검사하여 테스트 케이스를 만든다.

코드, 구조기반 테스팅

올바른 값이 나오는지를 테스트하는게 아니기 때문에 specification mismatch가 발생해도 알 수 없다.

### 설계방법

#### Statement coverage(문장 커버리지)
- 모든 문장을 실행할 수 있도록 테스트케이스를 설계하는 방법
- 문장은 모두 실행할 수 있으나 path는 모두 실행하지는 않음

#### Decision coverage / Branch coverage (분기 커버리지)
- 모든 path를 지나가도록 테스트케이스를 설계하는 방법

#### Condition coverage(조건 커버리지)
- 각 개별 조건이 만족할 수 있도록 테스트케이스를 설계하는 방법
- 예를들어 조건이 `A>1,B=0,A=2,X>1`이 있을때  
  `A>1,A<= 1`  
  `B=0,B<>0`  
  `A=2,B<>2`  
  `X>1,X<=1`  
  의 테스트케이스를 만들면 된다.
- 모든 조합이 아니라 저것들을 한번씩만 만족하는 테스트케이스가 나오면 된다.

#### Multiple-condition coverage(다중조건 커버리지)

- 조건커버리지와 마찬가지로 각 조건이 만족할 수 있도록 테스트케이스를 설계하나  
  모든 가능한 조합이 나오도록 테스트케이스를 설계한다.
