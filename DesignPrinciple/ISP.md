## ISP(인터페이스 분리의 원칙 : Interface-Segregation Principle)

>  **Clients should not be forced to depend upon methods that they do not use**
> 클라이언트들은 그들이 사용하지 않는 메소드에 의존하는 것이 강제되지 않아야한다.
> 클라이언트들는 그들이 사용하지 않는 메소드에 의존 관계를 맺으면 안된다.

많은 클라이언트 특정 인터페이스가 하나의 범용 인터페이스보다 낫다.
하나의 일반적인 인터페이스보다는, 여러 개의 구체적인 인터페이스가 낫다.

- 사용하지 않는 인터페이스 변경에 의해 발생하는 문제점이 존재
- 클라이언트 입장에서 사용하는 기능만 제공하도록 인터페이스가 분리

사용지점 분리
Many client specific interfaces are better than one general purpose
- no 'fat' interfaces
- no non-cohesive interfaces

#### 예
E.g., Input and Output interfaces

***

#### 핵심

- 하나의 일반적인 인터페이스보다는, 여러 개의 구체적인 인터페이스가 낫다.
- **ISP의 포인트는 범용보다는 '특정 목적'의 인터페이스**
