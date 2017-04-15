## Interface

### 정의
- You want to keep client classes independent of specific data-and serviceproviding classes  
so you can substitute another data-and-service-providing class with minimal impact on client classes.  
  클라이언트 클래스를 특정 데이터 및 서비스 제공 클래스와 독립적으로 유지하려 한다.
  그래서 클라이언트 클래스에 미치는 영향을 최소화하면서 다른 데이터 및 서비스 제공 클래스로 대체 할 수 있다.


- You accomplish this by having other classes access the data and services through an interface.  
  다른 클래스가 **Interface** 를 통해 데이터 및 서비스에 액세스하게함으로써이 작업을 수행 할 수 있습니다.


- 포인트는 '**사용방식의 일관성**'  
  이를 통해 클라이언트는 Interface만 수정되지 않으면 코드의 변경이 없으며,  
  Service를 제공하는 클래스는 is-a 관계가 아니더라도 Interface를 통해 누구나 확장이 가능하다.

### Related patterns
- Delegation
  - The Delegation and Interface patterns are often used together.  
    Delegation 과 Interface 패턴은 종종 함께 사용된다.
- Adapter
  - The Adapter pattern allows objects that expect another object to implement a particular interface to work with objects that don’t implement the expected interface.  
    어댑터 패턴을 사용하면 다른 개체가 특정 인터페이스를 구현하여 예상되는 인터페이스를 구현하지 않는 개체와 함께 작동하도록 할 수 있습니다.
    > 뭔말이야 이거..

- Strategy
  - The Strategy pattern uses the Interface pattern.
    Strategy 패턴은 Interface 패턴을 사용한다
- Anonymous Adapter
  - The Anonymous Adapter pattern (described in Patterns in Java, Volume 2) uses the Interface pattern.

- Many other patterns use the Interface pattern
