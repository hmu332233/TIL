## Singleton

### 개요

- the singleton pattern ensures that only one instance of a class is created.  
- all objects that use an instance of that class use the same instance.


- 싱글톤 패턴은 오직 하나의 클래스 인스턴스가 생성되는 것을 보장합니다.
- 해당 클래스의 인스턴스를 사용하는 모든 객체는 동일한 인스턴스를 사용합니다.

![singleton](http://i.imgur.com/HnnYCvX.png)

- 생성자는 **private** 으로 두고 `getInstance()` 메서드를 두어 항상 클래스의 동일한 인스턴스를 반환하는 정적 메서드를 두는 것으로 만들 수 있다.

```java
public static AudioClipManager getInstance(){

  if( instance == null )
    instance = new AudioClipManager();

  return instance;
}
```

- `Parameterized Factory` 와 잘 어울린다.


- 단, 여러 thread(여러 cpu)에서 객체가 하나를 공유하므로 문제가 생길 수 도 있다.
  - 해결책 : Thread Local(공유되는 인스턴스)에 플래그를 넣어 동시집입 문제를 막는다.

### Java API usage : Runtime

![singleton2](http://i.imgur.com/hM5tkVe.png)

***

### 핵심

- 중요한 자원은 **한 개의 객체로만 강제** 하기 위해 사용
- 시스템 전체에 오직 하나의 instance를 생성하게 함
- 해당 클래스의 인스턴스를 사용하는 모든 객체는 동일한 인스턴스를 사용
