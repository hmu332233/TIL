## Object Pool

### 개요
- 여러 개의 인스턴스가 들어 있고 필요한 경우에 넣었다 뺐다.
- N개의 인스턴스(비싼 자원)를 재사용
- 비싼 자원의 대상
  1. Socket과 같은 네트워크
  2. Thread
<br/>
- Manage the reuse of objects when a type of object is expensive to create.
- And also only a limited number of a kind of object can be created.
- 객체의 유형을 생성하는 데 비용이 많이 드는 경우 객체의 재사용을 관리합니다.
- 또한 제한된 수의 개체만 만들 수 있습니다.

### 스토리
- 독점적인 데이터베이스에 대한 액세스를 제공하는 클래스 라이브러리 작성 과제를 부 여 받았다고 가정 해 보겠습니다.  
클라이언트는 네트워크 연결을 통해 데이터베이스에 쿼리를 보냅니다.  
데이터베이스 서버는 연결을 통해 쿼리를 수신하고 동일한 연결을 통해 결과를 반환합니다.  
이 경우 JDBC와 데이터베이스 연결을 사용합니다.

- 데이터베이스 연결은 종종 비용이 많이 듭니다.  
JDBC 드라이버를로드하고 JDBC에서 연결을 얻으려면 : 몇 초가 걸릴 수 있습니다.  
JDBC를 사용하면 JDBC를 사용하여 데이터베이스에 연결하여 작업을 수행 할 수 있습니다.  
When finish do something, you will close connection  
작업이 완료되었을 때, 너는 커넥션을 닫을 것입니다.  
당신이 데이터베이스를 사용해야 할 때 그주기를 반복하십시오.  
**이것은 자원의 낭비!**

- 커넥션 재사용  
커넥션이 생성되면 재사용해라. (연결을 닫지 마십시오)  
사용자가 빌려서 사용하고 반환합니다.  
Something manages the connection’s recycle  
**무언가** 가 커넥션의 라이프사이클을 관리합니다.

- 바로 이 무언가가 **Object Pool Pattern** 이다!

***

![objectPool](http://i.imgur.com/VWlgsJ8.png)
![objectPool2](http://i.imgur.com/q343IaF.png)

- **Client**
  - borrows 'Connection Object' from Connection Pool.

- **Connection Pool**
  - manages 'Connection Object'.
  - Lends 'Connection Object' to Clients.
  - Receives 'Connection Object' from Client.

- **ConnectionImpl**
  - Instance of Connection from Connection Pool.


### 정리

![objectPoll](http://i.imgur.com/bxJ4nnI.png)


### Benefit
- Effectively manage resource and object.
- Reusable of resource and object.
- Increased to performance of System
- 자원 및 객체를 효과적으로 관리
- 자원과 객체를 재사용가능
- 시스템 성능 향상
