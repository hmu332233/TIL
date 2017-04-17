## Proxy Pattern

### 개요

- Proxy 패턴은 다른 객체에 대한 대리자 역할을하는 프록시 객체를 통해  
  객체에 대한 메소드 호출을 간접적으로 발생시키고  
  해당 객체에 대한 메소드 호출을 위임합니다.


- Proxy 객체는 client와 실제 service 중간에서  
  본인의 할 일을 하고 그대로 호출을 넘기는 역할을 한다.  

![proxy](http://i.imgur.com/itvQnwe.png)

- 예를들어 client가 doIt()을 호출하면 ServiceProxy는  
  본인의 할 일(client가 접근이 가능한지 아닌지 판별, 접근 기록 등등)을 수행하고  
  실제 Service에게 doIt()을 그대로 호출시켜준다.


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
- 호출한 대상이 호출이 가능한지 아닌지( 접근가능,불가)
- ex) protection proxy
#### Authorization
- Access control
- 어떠한 동작을 하도록 컨트롤 해주는 역할( 아에 경로를 바꿔버림 )
- 예를들어, 구글에서 야한거 검색해서 클릭했는데 경찰청 홈페이지로 바뀌어버리는 부분!
- Authorization를 하려면 Authentication이 깔려있어야하는 부분이라  
  그렇게 다르지는 않지만 굳이 나누자면 이렇게 나눈다의 느낌
- ex) protection proxy
#### Log/Audit Trall
- Access 기록
- 호출될 때마다 누가 또는 어떤걸 했는지 기록
#### Threading(image)
- 파워포인트의 큰 틀만 미리 로딩하고 나중에 속 내용 로딩하는 거랑 비슷
- ex) virtual proxy
#### Remote Call
- 다른 컴퓨터 또는 프로그램에 있는 Service를 호출하도록 해주는 것
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
