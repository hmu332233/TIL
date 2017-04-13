## SRP(단일책임의 원칙 : Single Responsibility Principle)


> **A class should have only one reason to change**
> 한 클래스는 변화에 오직 한가지 이유만을 가져야한다.

#### 정의
작성된 클래스는 하나의 기능만 가지며 클래스가 제공하는 모든 서비스는 그 하나의 책임(변화의 축: axis of change)을 수행하는 데 집중되어 있어야 한다는 원칙

**객체는 단 한가지 역할만을 가져야한다는 원칙**
- 클래스는 자신의 이름이 나타내는 일을 해야한다.
- 클래스는 하나의 개념을 나타내어야한다.

#### SRP의 이유
- 요구사항의 변화 -> 책임(responsibility)의 변화

 Violation of SRP causes spurious transitive dependencies between modules that are hard to anticipate.

 SRP원리를 적용하면 책임 영역이 확실해지기 때문에 `한 책임의 변경에서 다른 책임의 변경으로의 연쇄작용에서 자유로울 수 있습니다.` 뿐만 아니라 책임을 적절히 분배함으로써 코드의 가독성 향상, 유지보수 용이라는 이점까지 누릴 수 있으며 객체지향 원리의 대전제 격인 OCP원리뿐 아니라 다른 원리들을 적용하는 기초가 된다.

#### 적용방법

단일 클래스에 많은 역할이 있으면 모든 변경이 다른 변경에 영향을 미치므로
이를 분리하도록한다.

**이 클래스의 역할이 여기에 있어야 하는가?** 에 대한 질문에 대답을 할 수 있도록 설계한다.
