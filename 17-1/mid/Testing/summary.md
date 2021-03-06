### Testing
- 프로그램을 항상 에러가 존재하며 이러한 에러를 찾는게 테스팅이다
- 테스팅은 오류를 찾기 위해 프로그램을 실행하는 프로세스이다
- 좋은 테스트 결과란 에러가 없는 것이 아니라 많은 에러를 찾아냈다는 것

### the economics of testing ( 테스팅의 경제학 )
- is it possible to test a program to find all of tis errors?  
  모든 에러를 찾기위해 프로그램을 테스트 하는 것은 가능한가?
- 사소한 프로그램이라도 대답은 부정적이다.
- 프로그램에서 모든 오류를 발견하는 것은 비현실적이며 종종 불가능하다.


- 그러므로 테스터가 프로그램에 대해 만들어야하는 추정(assumptions)과 테스트케이스를 디자인하는 방식이 필요하다.
- 즉 테스트 전략이 필요하다.

### Software Testing Principles ( 테스팅 원칙 )
##### 1. 테스트케이스에는 예상 출력이나 결과에 대한 정의가 필요하다.
```
- 테스트케이스는 두 가지 구성요소로 구성되어야한다.
  1. 프로그램 입력 데이터에 대한 설명
  2. 해당 입력 데이터 세트의 프로그램의 올바른 출력에 대한 정확한 설명
```
##### 2. 프로그래머는 본인의 프로그램을 테스트하려는 시도를 피해야한다.
##### 3. 프로그래밍 조직은 자신의 프로그램을 테스트하면 안된다.
##### 4. 모든 테스트 과정에는 각 테스트의 결과에 대한 검사가 포함되어야한다.
##### 5. 테스트케이스는 유훃고 예상 가능한 입력조건에 대해 작성할 뿐만 아니라 무효하고 예상치 못한 조건에 대해서도 작성해야한다.
##### 6. 프로그램이 해야 할 일을 수행하는지 확인하는 것은 전체의 절반에 해당하는 것이고 나머지 반에 해당하는 하지 말아야 할 일을 하지 않는지도 확인해야한다.
##### 7. 폐기시킬 프로그램이 아니라면, 폐기할 테스트 케이스를 사용해서는 안된다.
```
- regression test 때문!
```
##### 8. 아무런 오류가 발견되지 않을 것이라는 가정하에 테스트를 계획해서는 안된다.
##### 9. 프로그램의 섹션에서의 오류 존재 가능성은 그 부분에서 발견된 오류의 수에 비례한다.
##### 10. 테스트는 매우 창조적이고 지적인 업무이다.

***

### Static Testing
- 프로그램을 실행하지 않고 테스트
- 프로그램이 수정 될 때 문제가 발생할 수 있는 잠재적인 결함을 발견 할 때 효과적이다.


### Dynamic Testing
- 실제 입력으로 프로그램을 실행하여 테스트

***

### Human Testing
- 3가지 Human Testing은 Code Inspections, walkthroughs(워크쓰루), 사용성 테스트( user(or usability) tesing )이다.
- 워크쓰루와 코드인스펙션은 많은 공통점을 가지고 있다. 그래서 유사점을 알아볼 것이다.
- 코드인스펙션과 워크쓰루는 프로그램을 읽고 시작적으로 검사하는 팀을 참여시킨다.

### Advantage of Inspections and walkthroughs
1. 프로그램 작성자 이외의 사람들이 프로세스에 포함되기 때문에 더 효과적이다.
2. 워크쓰루의 또 다른 장점은 예상하지 못한 결과만을 받는 블랙박스 테스팅과 대조적으로 코드 내에서 오류가 발생했을 때 오류의 위치를 정확하게 알고 있기 때문에 디버깅 비용을 줄여준다는 것이다.
3. 프로세스는 일괄 오류를 자주 노출하므로 에러를 나중에 올바르게 바꿀 수 있다.

#### Inspections
- it is a step-by-step peer group review of a work product, with each step checked against predetermined criteria.
- 각 단계를 사전에 정의된 기준에 대해 체크해 나가는 것과 함께하는 peer group(신분이 동등한) 리뷰이다.

#### walkthroughs
- it is a review where the author leads the team through a manual or simulated execution of the product using predefined scenarios.
- 미리 정의된 시나리오를 사용하여 수동 또는 시뮬레이션으로 제품의 실행을 통해 작성자가 팀을 이끄는 리뷰이다.

##### 코드 인스펙션과 워크스루의 차이
- **코드인스펙션** : 체크리스트를 통해 사전에 정의된 기준에 대해 체크해 나가는 것으로 결함을 찾아내는 방식

- **워크쓰루** : 미리 정의된 시나리오(테스트케이스)를 이용한다. 생각을 통해 프로그램을 실행하며 과정을 진행하며 프로그램의 상태를 종이나 화이트보드에 기록해 나가면서 결함이 있는지 찾아내는 방식

***

### Code Inspection
- 절차에 따라 참여자가 함께 코드를 읽으며 오류를 찾는 기법.
- 대부분의 논의는 절차와 작성 양식 등에 초점을 맞추고 있다.

- 보통 4명으로 팀을 이룬다
  1. Moderator ( 중재자 )
  2. Programmer
  3. Program's designer
  4. Test specialist

- code inspection은 그룹 코드 리딩을 위한 절차의 세트와 에러 탐지 기술이다.

#### Side Benefits of the Inspection Process 인스펙션 프로세스의 부가적인 효과

- 프로그래머는 프로그래밍 스타일, 알고리즘 선택, 프로그래밍 기법에 대한 피드백을 받을 수 있다.
- 다른 참가자는 다른 사람의 프로그램 오류와 프로그램 스타일을 접함으로써 비슷한 경험을 하게 된다.

#### Error Checklist for Inspections

- **Data Reference Errors( 데이터 참조 오류 )**
```
1. 참조된 변수가 설정되어 있지 않거나, 초기화되어 있지 않은가?
2. 배열의 참조에서 경계 값 내 첨자 값이 있는가?
3. 배열의 참조에서 각 첨자는 정수인가?
4. 포인터나 참조 변수를 사용한 모든 참조에서 참조 메모리는 할당되어 있는가?(허 상참조)
5. Correct attributes when aliasing?
6. 변수의 값은 컴파일러가 예측하는 type이나 atrribute인가?
7. 비트 문자열 주소? 비트 문자열 인수 전달
8. 포인터나 참조 변수를 사용하는 경우 메모리의 참조 위치는 컴파일러가 예상하는 속성인가?
9. 데이터 구조를 여러 프로시저나 서브루틴에서 참조하는 경우 각 절차에서 동일하게 정의 되어있는가?
10. 문자열 인덱싱에서 인덱싱 조작이나 배열철자를 참조할 때 문자열 하나를 하나씩 벗어나는 오류가 있는가?
11. 객체지향 언어에서 모든 상속 요구를 구현 클래스가 만족하는가?
```
- **Input/Output Errors**
```
1. 파일의 올바른 속성
2. 올바른 OPEN 구문
3. I/O 구문에서 FORMAT은 명세와 일치하는가?
4. 프로그램이 읽기 위한 파일을 저장하는 메모리는 충분한가?
5. 사용하기 전에 모든 파일을 열었는가?
6. 사용 후에 모든 파일을 닫았는가?
7. end-of-file 조건을 검출하고 올바르게 처리하는가?
8. 프로그램이 인쇄하거나 표시하는 모든 글자에서 철자와 문법에 오류는 없는가?
9. 프로그램이 "FileNotFound" 오류를 정상적으로 처리하는가?
```
- **Data Declaration Errors( 데이터 선언 오류 )**
```
1. 모든 변수는 명시적으로 선언되어 있는가?
2. 모든 변수의 속서이 선언부에 명시되어 있지 않다면 기본 값은 적절하게 이해되는가?
3. 선언문에서 변수가 초기화될 곳에서 제대로 초기화되는가? ( 특히, 배열과 문자열 초기화 )
4. 각 변수는 올바른 길이 및 데이터 유형을 지정하는가?
5. 변수의 초기화는 메모리 타입과 일관성이 있는가?
6. 비슷한 이름의 변수가 있는가?
```
- **Computation Errors( 연산 오류 )**
```
1. 데이터 타입이 일치하지 않는( 연산할 수 없는 ) 변수를 사용한 연산이 있는가?
2. 혼합모드 연산이 있는가? ( 실수형 변수에 정수형 변수를 더하는 것들, 오류는 아니지만 어떻게 변환되는지 주의깊게 봐야함 )
3. 같은 데이터 타입이지만 길이가 다른 변수를 사용한 연산이 있는가?
4. 할당문 좌변 변수의 데이터 타입이 우변의 데이터 타입보다 작은가?
5. 연산하는 동안 오버플로우나 언더플로우 수식이 가능한가?
6. 0으로 나누게 될 가능성이 있는가?
7. 컴퓨터가 변수를 base-2형태의 바이너리로 표현한다면, 잘못되었음을 보고하는 절차가 있는가?
8. 의미 있는 범위 밖에 변수 값이 있는 경우는 아닌가?( probability(확률)이라는 변수에 할당 값이 양수이고 1.0보다 크지않음을 확인하는 것 )
9. 하나 이상의 연산자가 포함된 연산식에서 연산자의 순서와 평가 순서는 올바르가?
10. 정수연산에서 잘못사용된 부분이 있는가?
```
- **Comparison Erros( 비교 오류 )**
```
1. 서로 다른 데이터 타입의 변수를 비교하는가?
2. 혼합모드를 비교하거나 길이가 다른 변수를 비교하는가?
3. 연산자 비교는 정확한가?( <, <=, >, >= )
4. Boolean 표현의 각 상태는 의도된 것인가?
5. 2<i<10 과 같이 표현하진 않았는가?
6. i>x||y와 같이 표현하진 않았는가? ( i>x || i>y )
7. if(a==b==c) 와 같이 표현하진 않았는가?
8. x>y>z 와 같이 표현하진 않았는가?
9. 컴퓨터가 2진으로 표현된 분수나 실수를 비교하는가?
10. 하나 이상의 Boolean 연산자를 사용한 표현식에서, 평가 순서와 연산자 선후관계는 정확한가?( and or 와 같이 무엇이 먼저 수행되는가 )
11. 컴파일러가 Boolean 표현식을 평가하는 방법이 프로그램에 영향을 주는가?
```
- **Control-Flow Errors( 제어 흐름 오류 )**
```
1. GOTO와 같은 다중분기가 있는 경우, 인덱스 변수는 분기 가능수를 초과할 수 있는가?
2. 모든 루프는 최종적으로 종료되는가?
3. 프로그램, 모듈 또는 서브루틴은 최종적으로 종료되는가?
4. 시작 조건 때문에 루프가 실행되지 않는 것이 가능한가?
5. 반복과 불린 조건으로 제어되는 루프에서 완료되지 않는 루프의 결과는 무엇인가?
6. 한번씩 많거나 적은 반복과 같이 하나씩 벗어나는 오류가 있는가?( for문에서 0~9 해서 10번 연산하려했는데 0~10으로 되어서 11번 연산하는 경우 )
7. do-end,{}과 같이 표현식이 명확한가? 또는 열기 괄호에 닫기 괄호가 있는가?
8. 누락된 결정이 있지는 않는가?( 1,2,3이 넘어오는 파라미터가 있는데 3의 경우 로직이 빠져있지는 않은가? )
```
- **Interface Errors( 인터페이스 오류 )**
```
1. 모듈이 받는 파라미터 수는 호출하는 모듈이 보낸 인수의 수와 일치하는가? 또한 순서는 맞는가?
2. 파라미터의 속성은 해당 인수의 속성과 일치하는가?
3. 각 파라미터의 단위는 해당 인수의 단위가 일치하는가?( 파라미터는 라디안으로 되어있으나 인수는 각도로 표시되어 있지는 않은가? )
4. 모듈에서 전송되는 인수는 상대 모듈의 파라미터의 수와 일치하는가?
5. 다른 모듈로 전송하는 인수의 속성은 상대 모듈의 파라미터 속성과 일치하는가?
6. 다른 모듈로 전송하는 인수의 속성은 상대 모듈의 파라미터 속성과 일치하는가?
7. 다른 모듈로 전송하는 인수의 단위 시스템은 상대모듈의 파라미터 단위 시스템과 일치하는가?
8. 내장 함수를 호출하는 경우 수,속성,순서는 올바른가?
9. 모듈이나 클래스가 여러 시작 포인트를 갖고 있다면, 현재 시작 포인트와 관련 없는 파라미터를 참조하지는 않는가?
10. 서부루틴이 입력된 값으로 의도된 파라미터를 바꾸는가?
11. 전역 변수가 있다면, 그들을 참조하는 모든 모듈에서 같은 정의와 속성을 갖는가?
12. 상수를 인수로 전달하는가?
```
- **기타 체크**
```
1. 컴파일러가 식별자의 상호 참조 리스트를 생성하는 경우 참조되지 않은 변수나 한번만 참조하는 변수를 검사해라
2. 컴파일러가 속성 리스트를 생성하는 경우, 기본 속성이 할당되지 않은 변수가 있는지 변수의 특성을 확인하라
3. 프로그램이 성공적으로 컴파일되었지만 컴퓨터가 하나 이상의 경고나 정보 메세지를 생산하는 경우 모든 메세지를 신중히 혹인하라
4. 프로그램이나 모듈은 강력한가? 즉, 입력 값의 유효성을 체크하는가?
5. 프로그램에 누락된 기능은 없는가?
```

### Walkthroughs
-  인스펙션과 같이 워크쓰루는 참여자와 함께 그룹을 이루어 코드를 읽기 위한 절차와 오류 검출 기법이다.
- 절차가 약간 다르고 사용하는 오류 검출 기법이 다르다.
- 팀은 4명에서 5명으로 구성된다.
    1. Moderator 중재자
    2. Secretary 서기
    3. Tester
    4. +Programmers

- 참가자는 "컴퓨터 역할"을 한다.
- 테스터로 지정된 사람은 프로그램이나 모듈의 입력 값(과 예상되는 출력 값)을 대표하는 문서로 된 테스트 케이스를 준비한다.
- 회의 중에 각 테스트 케이스는 생각을 통해 실행된다. 즉 테스트 데이터는 프로그램의 논리를 실행하게 된다.
- 프로그램의 상태( 변수의 값 )은 종이나 화이트보드에 기록한다.

### Desk Checking
- For most people, desk checking is relatively unproductive  
  대부분의 사람들에게 탁상검사는 비생산적이다.

### Peer Ratings 동료 평가
- 익명의 프로그램에 대해 전반적인 품질, 유지보수성, 확장성, 사용성, 명확성을 평가하는 기법
- 이것의 목적은 프로그래머 자신에 대한 평가를 제공하는 것이다

#### Process
1. 한 프로그래머에게 프로세스 관리자 역할을 부여한다.
2. 관리자는 6명에서 20명 정도의 참가자를 선정한다.
3. 참가자는 자신의 프로그램 중에서 리뷰를 할 2개를 선택한다. 하나는 잘 되었다고 생각하는 것이고, 다른 하나는 품질적 측면에서 가장 부족한 프로그램이어야한다.
4. 프로그램이 모이고 난 뒤 그것을 무작위로 참가자들에게 배포한다.
5. 프로그램 당 30분간 리뷰하고, 리뷰가 끝나면 4개 프로그램의 품질에 대해 상대 평가를 한다.

#### 테스트 레벨
```
Low

Informal
Walkthrough
Technical Review
Inspection

High
```
