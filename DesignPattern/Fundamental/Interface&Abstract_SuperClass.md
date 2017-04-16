## Interface & Abstract Super Class

### 개요
- You need to keep client classes independent of classes that implement a behavior  
and ensure consistency of behavior between the behaviorimplementing classes.  
  클라이언트 클래스는 동작을 구현하는 클래스와 독립적으로 유지해야한다.  
  그리고 클래스를 구현하는 클래스에 동작의 일관성을 보장해야한다.


### 동시 사용?
- **The need to hide from its clients -> Use the Interface pattern.**    
  clients로부터 숨길 필요성 -> Interface pattern을 사용해라

  - Have the client objects access the service-providing object indirectly through an interface.
  - 클라이언트 오브젝트가 인터페이스를 통해 간접적으로 서비스 제공 오브젝트에 액세스하도록 해라
  - The indirection allows the clients to access the service-providing object without having to know what kind of objects they are.  
  - indirection은 클라이언트가 오브젝트의 종류를 알 필요없이 서비스 제공 오브젝트에 액세스 할 수 있게한다.


- **Need to design a set of related classes that provide similar functionality**   
  **-> Use the Abstract Superclass**   
  유사한 기능을 제공하는 관련된 클래스 집합을 디자인하는 것이 필요하다.   
  -> Abstract SuperClass를 사용해라.

![interface&abstract](http://i.imgur.com/lEEjLuc.png)

![inter&ab](http://i.imgur.com/HLdg7Bh.png)
