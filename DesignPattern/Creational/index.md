## Creational Design Patterns

생성이 필요할 때 객체를 생성하는 방법에 대한 지침을 제공하는 패턴.

### Factory Method pattern
- 일반적으로 가장 많이 사용됨
- **생성된 객체의 클래스를 알 필요없이** 객체가 다른 객체의 생성을 시작하는 방법

### Abstract Factory pattern
- a way for objects to initiate the creation of a variety of different kinds of objects without knowing the classes of the objects created  
  객체가 생성 된 객체의 클래스를 모른 채 다양한 종류의 객체를 생성하는 방법
-  The Factory of a factory

### Prototype pattern
- 찍어내기, 비싼 자원을 로딩 후에 복사해서 쓰고 기타정보만 바꿔서 쓴다.
- allows an object to create customized objects without knowing their exact class or the details of how to create them.  
  개체가 정확한 클래스 또는 개체를 만드는 방법에 대한 세부 정보없이 개체를 만들 수 있습니다.
### Singleton pattern
- 중요한 자원은 한 개의 객체로만 강제하기 위함
- a way for multiple objects to share a common object without having to know whether it already exists.
  여러 객체가 이미 존재하는지 여부를 알 필요없이 공통 객체를 공유하는 방법.

### Object Pool pattern
- a way to reuse objects rather than create new objects  
  새로운 객체를 만드는 대신 객체를 재사용하는 방법
