## Delegation Pattern

### 정의
- 여러 클래스가 있을 때 중복되는 코드가 있다면,  
  이를 분리하여 별도의 클래스로 만들고  
  별도의 클래스에게 위임( **Delegation** )하는 방식의 패턴

### Java API Usage
- java.util이 이러한 Delegation Pattern이 적용된 모습이다.

### Inheritance Vs Delegation
#### 공통점
- 두 방식 모두 중복되는 코드를 관리하는 방법
#### 차이점
코드가 중복될 때 해결방법
- 중복되는 코드가 있는 클래스 간의 관계가 동질의 것이라면(is-a)
  상속( **Inheritance** )을 통해 문제를 해결한다.
- 중복되는 코드가 있는 클래스 간의 관계가 동질의 것이 아니라면(상속 관계가 될 수 없다면)
  중복되는 코드를 분리하여 위임( **Delegation** )시켜 문제를 해결한다.

### Related Patterns
- 거의 대부분의 패턴들이 **Delegation** 을 사용한다.
- Some of the patterns that rely most clearly on delegation are the Decorator pattern and the Proxy pattern
  Delegation을 가장 명확하게 의존하는 패턴은 `Proxy pattern`과 `Decorator pattern`이다
