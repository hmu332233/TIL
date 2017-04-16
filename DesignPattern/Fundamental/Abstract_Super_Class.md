## Abstract Super Class

### 개요
- Ensure consistent behavior of conceptually related classes by giving them a common abstract superclass.
  공통의 Abstract super class를 제공함으로써 개념적으로 관련된 클래스에게 일관된 행동을 보장한다.


- You want to ensure that logic common to related classes is implemented consistently for each class.  
  관련 클래스에 공통된 로직이 각 클래스에 대해 일관되게 구현되도록 보장하고자한다.


- You want to avoid the runtime and maintenance overhead of redundant code.  
  중복 코드의 런타임 및 유지 관리 오버 헤드를 피하려고한다.


- Methods whose signature and logic are common to the related classes are put into the superclass  
so their logic can be inherited by the related classes that extend the superclass.  
  관련된 클래스들의 공통적인 logic과 signature를 가진 메소스들은 superclass에 배치된다.  
  그래서 그들의 logic은 superclass를 확장하는 관련 클래스에 상속 될 수 있다.

### 핵심

- 포인트는 '**child class 에게 구현을 위임(강요) -> Abstract**'  
  `child의 공통적인 행위` + `parent class에서 구현`을 동시에 상속 시킬 수 있다.


- 즉 child는 parent에서 위임(강요)받은 method를 구현해야하며,  
  parent에서 abstract이 아닌 구현되어 있는 부분은 그대로 상속받아 쓰거나  
  필요한 경우 오버라이드하여 사용한다.
