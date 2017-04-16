## Proxy Pattern

### 개요

- Proxy 패턴은 다른 객체에 대한 대리자 역할을하는 프록시 객체를 통해  
  객체에 대한 메소드 호출을 간접적으로 발생시키고  
  해당 객체에 대한 메소드 호출을 위임합니다.


- 프록시 객체의 클래스는 대개 프록시를 처리한다는 클라이언트 객체의 인식을 제거하는 방식으로 선언됩니다.


### 내용

**프록시 객체는 다른 객체를 대신하여 메소드 호출을받는 객체입니다.**

- 클라이언트 오브젝트가 프록시 오브젝트의 메소드를 호출합니다.
- 프록시 객체의 메소드는 클라이언트가 기대하는 서비스를 직접 제공하지 않습니다.  
  대신 실제 서비스를 제공하는 객체의 메서드를 호출합니다.

![proxy3](http://i.imgur.com/A5j0nBH.png)

#### proxy object
- 해당 서비스를 일부 관리합니다.
- 서비스 제공 객체와 공통 인터페이스를 공유합니다.

#### client object
- 특정 클래스의 인스턴스가 아닌 공통 인터페이스를 통해 서비스 객체에 액세스합니다.

### 사용

#### Authentication
- 자격확인(인증)
- 호출한 대상이 호출이 가능한지 아닌지
- ex) protection proxy
#### Authorization
- Access control
- ex) protection proxy
#### Log/Audit Trall
- Access 기록
- 호출될 때마다 누가 또는 어떤걸 했는지 기록
#### Threading(image)
- 파워포인트의 큰 틀만 미리 로딩하고 나중에 속 내용 로딩하는 거랑 비슷
- ex) virtual proxy
#### Remote Call
- ex) remote proxy

### Related Pattern

#### Protection Proxy.
- The Protection Proxy pattern uses a proxy to enforce a security policy on access to a service-providing
object.

#### Facade.
- The Façade pattern uses a single object as a front end to a set of interrelated objects rather than as a
front end to a single object.

#### Object Request Broker.
- The Object Request Broker pattern uses a proxy to hide the fact that a service object is located on a
different machine than the client objects that want to use it.

#### Virtual Proxy.
- The Virtual Proxy pattern uses a proxy to create the illusion that a service-providing object exists
before it has actually been created.

#### Decorator.
- The Decorator pattern is structurally similar to the Proxy pattern in that it forces access to a serviceproviding
object to be done indirectly through another object. The difference is a matter of intent.

***

![proxy2](http://i.imgur.com/HIl22Ht.png)
