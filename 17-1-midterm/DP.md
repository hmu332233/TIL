### Concepts of Object Orientation
- Abstraction 추상화
- Information Hiding 정보은닉
- Encapsulation 캡슐화
- Pholymorhpism 다형성
  - 계층구조를 몰라도된다
  - 상속구조가 코드에 많은 영향을 주지않는다
- Modulity 모듈화

#### OO의 한계
- 선언부에서 계층구조(상속)을 알아야 사용가능(선언가능)

### Design Principle

- **SRP(Single Responsibility Principle) 단일책임의 원칙**
  - 객체는 한가지 역할만을 가져야한다
  - 한 클래스, 한 역할
  - 하나의 기능을 하나의 클래스에 두어서 수정 시에 한 곳만 고쳐도 되게끔 한다.

- **OCP(Open/Close Principle) 개강폐쇠의 원칙**
  - 확장에는 열고 수정에는 닫아야한다
  - 추가적인 기능 또는 변경사항이 있따면 기존 코드를 수정하는 것보다 확장을 통해 원하는 결과를 얻을수 있도록 해야한다
  - 확장성

- **ISP(Interface Segregation Principle) 인터페이스 분리의 원칙**
  - 하나의 범용 인터페이스보다는 여러개의 구체적인 인터페이스가 낫다
  - 사용 시점에 따라 기능이 아에 분리된다면 인터페이스도 분리해서 관리

- **DIP(Dependency Inversion Principle) 의존 역전의 원칙**
  - 구현 클래스는 자주 변경될 가능성이 높기 때문에, 변화 가능성이 상대적으로 적은 추상 타입이나 메서드에 의존하면 변화에 따른 영향을 최소화 할 수 있다는 것.
  - 같은 개념이면 추상화 클래스를, 다른 개념이면 인터페이스를 넣어 사용하는 입장에서 수정에도 영향을 받지 않도록 만든다
  - 구현 클래스가 아닌 인터페이스 타입을 사용해라

- **LSP(Liskov Substitution Principle) 리스코브 대체의 원칙**
  - 자식이 부모를 완벽하게 대체할 수 있어야한다.
  - 부모 객체를 상속한 자식 객체는 반드시 부모 객체의 인터페이스를 모두 구현해야한다


### Fundamental DesignPattern

- **Delegation**
  - 여러 클래스가 있을 때 중복되는 코드가 있다면 이를 분리하여 별도의 클래스로 만들고 별도의 클래스에게 위임해라
  - 포인트는 '중복코드의 분리'

- **Immutable 변경불가능한**
  - 동시성 문제를 읽기만 가능하고 수정에는 새로운 객체를 리턴하도록 하여 문제를 해결한다
  - 포인트는 '수정시 새로운 객체를 리턴!'

- **Interface**
  - 서로 다른 클래스가 Interface를 통해 엑세스하게 함으로써 코드의 변경에도 클라이언트는 영향을 최소한으로 받는다. 또한 is_a 관계가 아니더라도 누구나 확장이 가능하다
  - 포인트는 '사용방식의 일관성'

- **Marker Interface**
  - 아무런 Operation 없이 가능,불가능(Boolean)만 알려주는 Interface
  - 객체에 대해 무엇인가 결정해야하는 유틸리티 클래스에서 특히 자주 쓰인다.

- **Abstract SuperClass**
  - 포인트는 'child class에게 구현을 위임(강요)'

- **Interface & Abstract Super class**
- clients로부터 숨길 필요성  
  -> Interface pattern을 사용해라

- 유사한 기능을 제공하는 관련된 클래스 집합을 디자인하는 것이 필요하다.  
  -> Abstract SuperClass를 사용해라.

- **Proxy**
  - 프록시 객체의 메소드는 클라이언트가 기대하는 서비스를 직접 제공하지 않습니다.  
    대신 실제 서비스를 제공하는 객체의 메서드를 호출합니다.
  - Proxy 객체는 client와 실제 service 중간에서 본인의 할 일을 하고 그대로 호출을 넘기는 역할을 한다.
  - Authentication 자격 인증
  - Authorization 엑세스 컨트롤
  - Log/Audit Trall 엑세스 기록
  - Threading(image) 이미지 쓰레딩
  - Remote Call 다른 컴퓨터 또는 프로그램에 있는 Service 호출

### Creaitional

- **Factory Method**
  - 구체적인 클래스가 아직 정의되지 않았을 때,  
  - 객체 생성이 서브클래스에 위임되어야 할 때.

  - 객체를 생성하기 위한 인터페이스 메소드를 정의하고 이것을 서브 클래스에 위임시킵니다.
  - 어떠한 개체를 생성할 것인지에 대한 고민은 뒤로 미루고 개체를 사용하는 부분을 구현할 수 있습니다

- **Abstract Factory**
  - 호환성 있는 개체군을 하나의 팩토리 개체를 통해 생성하게 함으로써 사용자 편의성을 증대시킬 수 있다.
  - 추상 팩토리 패턴에서는 서로 호환성 있는 개체들을 생성하는 부분만 담당하는 개체를 제공
  - 생성된 객체의 클래스를 알 필요없이 객체가 다양한 종류의 객체 생성을 시작하는 방법
  - factory of factory
  - factory of factory 란 뜻으로 같은 목적 또는 환경 있는 개체들을 생성하는 팩토리들을 추상화시킴으로써  
    클라이언트는 목적 및 환경에 맞는 팩토리만 선택하면 생성된 객체의 클래스를 알 필요없이 필요한 객체를 생성할 수 있게한다.

- **Builder**
  - 한정된 재료의 조합방법이 다른 경우 사용
  - 객체를 생성하는 방법(과정)과 객체를 구현(표현)하는 방법을 분리한다.  
    따라서 이 패턴은 동일한 생성 절차에서 서로 다른 표현 결과를 만들 수 있다.

- **Prototype**
  - 찍어내기, 비싼 자원을 로딩 후에 복사해서 쓰고 기타정보만 바꿔서 쓴다.

  - Shallow Copy
    - original object와 cloned object가 Reference object를 공유한다.

  - Deep Copy
    - original object와 cloned object 둘 다 각각의 Reference object를 가진다.

- **Singleton**
  - 중요한 자원은 한 개의 객체로만 강제 하기 위해 사용
  - 시스템 전체에 오직 하나의 instance를 생성하게 함
  - 해당 클래스의 인스턴스를 사용하는 모든 객체는 동일한 인스턴스를 사용
  - 생성자는 private 으로 두고 getInstance() 메서드를 두어 항상 클래스의 동일한 인스턴스를 반환하는 정적 메서드를 두는 것으로 만들 수 있다.

- **Object Pool**
  - 여러 개의 인스턴스가 들어 있고 필요한 경우에 넣었다 뺐다.
  - N개의 인스턴스(비싼 자원)를 재사용 ( Socket, Thread )
  - 객체의 유형을 생성하는 데 비용이 많이 드는 경우 객체의 재사용을 관리합니다. - 또한 제한된 수의 개체만 만들 수 있습니다.

  - 자원 및 객체를 효과적으로 관리
  - 자원과 객체를 재사용가능
  - 시스템 성능 향상
