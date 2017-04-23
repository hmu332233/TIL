## Prototype

### 개요
- The Prototype pattern allows an object to create customized objects without knowing their exact class or the details of how to create them.
- It works by giving prototypical objects to an object that initiates the creation of objects.
- The creation-initiating object then creates objects by asking the prototypical objects to make copies of themselves.


- Prototype 패턴을 사용하면 객체가 정확한 클래스 또는 객체 작성 방법에 대한 세부 정보없이 객체를 생성 할 수 있습니다.
- 그것은 객체 생성을 시작하는 객체에 프로토 타입 객체를 제공함으로써 작동합니다.
- creation-initiating 객체는 프로토 타입 객체가 자신의 복사본을 만들도록 요청함으로써 객체를 만듭니다.



### 스토리
- 슈팅 게임을 만들고 싶다고 가정 해 봅시다.
- 당신은 많은 몬스터를 만들어야합니다.
- 적 몬스터의 이미지, 크기 및 속도는 같습니다.
- 그러나 각각의 몬스터의 x, y 위치는 서로 다릅니다.


- **How to design this game effectively?**  
  어떻게 이 게임을 효과적으로 설계할 것인가?


![prototype](http://i.imgur.com/o2Dqnrl.png)


### Shallow & Deep Copy

![prototype2](http://i.imgur.com/jhRptnt.png)

- **Shallow Copy**
  - A copy of a data structure which shares any linked structures with the original
  - 원래 구조와 연결된 구조를 공유하는 데이터 구조의 사본
  - original object와 cloned object가 Reference object를 공유한다.


  ```java
    static Image img = null;

    Monster(){
      if(img == null)
        img = new Image();
    }
  ```



- **Deep Copy**
  - A copy of a data structure duplicating not only the structure itself, but all structures to which it is linked
  - 구조체 자체뿐만 아니라 연결된 모든 구조체를 복제하는 데이터 구조체의 사본
  - original object와 cloned object 둘 다 각각의 Reference object를 가진다.

```java
  Monster(){
    new Image();
  }

  clone(){
    return new Monster();
  }
```
