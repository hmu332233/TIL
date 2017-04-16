## Marker Interface

### 개요

- 아무런 operation이 없이 가능,불가능(Boolean)만 알려주는 Interface
- 말그대로 Marker(표시)용이다.
- IF인 이유
  - 자바에서는 IF의 implementation이 무한대로 가능하기 때문  
    ( 상속은 1개만 가능한 반면에 )


- 클래스 선언의 근본적인 특성을 이용.
- 이것은 특정 클래스의 인스턴스라고 가정하지 않고 객체에 대해 **무엇인가를 결정** 해야하는 유틸리티 클래스에서 특히 잘 작동한다.

### Java API Usage

#### the Serializable interface.

- Instances of the ObjectOutputStream class write objects as a stream of bytes.
- An instance of the ObjectInputStream class can read the stream of bytes and turn it back into an object.
- The ObjectOutputStream class refuses to serialize objects unless their class implements the Serializable interface to indicate that its serialization is allowed.


- ObjectOutputStream 클래스의 인스턴스는 객체를 바이트 스트림으로 씁니다.
- ObjectInputStream 클래스의 인스턴스는 바이트 스트림을 읽고 객체로 되돌릴 수 있습니다.
- ObjectOutputStream 클래스는 해당 클래스가 직렬화가 허용됨을 나타 내기 위해 Serializable 인터페이스를 구현하지 않는 한 객체의 직렬화를 거부합니다.


![marker2](http://i.imgur.com/fOMQcEi.png)


***

![marker](http://i.imgur.com/Suin4xD.png)

```java
if( a instanceof MarkIF ){
  do something
}
// 이런식으로 같은 operation도 marked와 unmarked로 구별하여 수행이 가능하다.
```
