## Builder

한정된 재료의 조합방법이 다른 경우 사용

### 개요
- <U>The Builder pattern allows a client object to construct a complex object</U> by specifying only its type and content.  
- The client is shielded from the details of the object’s construction.


- Builder 패턴을 사용하면 클라이언트 오브젝트가 유형 및 내용 만 지정하여 복합 오브젝트를 작성할 수 있습니다.
- 클라이언트는 객체의 구성 세부 사항으로부터 보호됩니다.


- 프로그래밍하다 보면 여러 요소로 구성되는 개체가 있습니다. 그리고 이와 같은 개체를 생성하는 방법이 목적에 따라 다양한 경우가 생깁니다. 이 경우에 빌더 패턴은 목적에 따라 개체를 생성하는 과정의 약속과 구체적인 알고리즘 구현을 분리하여 개체를 생성하는 패턴입니다.


- 빌더 패턴에서 빌더는 추상 클래스로 개체를 생성하는 과정들을 약속합니다. 빌더를 기반으로 파생한 클래스에서는 생성 과정들에 대해 구체적으로 구현합니다. 이처럼 정의하면 빌더를 사용하는 곳에서는 서로 다른 구조를 갖는 개체를 같은 방법으로 생성할 수 있습니다.

- "개체를 생성하는 과정의 약속과 구체적인 알고리즘 구현을 분리"

![builder](http://i.imgur.com/rkuaCg0.png)

1. convert super class 생성  
  모든 MIME Type 별로 메소드 생성
2. 계층 구조가 생겼으니 Factory를 통해 생성
3. MessageManager -> orchestrator 연주

```java
Converter c = null;

parse(){
  if( MIME == "text/plain" ){
    c = new MAPZ();
  }
  else if( MIME == "text/html" ){
    c = new PROFS();
  }

  c.convert(내용)
}

```

- 복합 객체의 생성 과정과 표현 방법을 분리하여 동일한 생성 절차에서 서로 다른 표현 결과를 만들 수 있게 하는 패턴.

Director : Director 객체는 콘크리트 빌더 객체의 메소드를 호출하여 콘크리트 빌더에 빌드하는 제품 객체의 내용을 제공합니다.

Concrete Builder : 클래스는 AbstrctBuilder 클래스의 구체적 하위 클래스로서 Director 객체의 특정 데이터 표현을 작성하는 데 사용됩니다.

Builder : AbstractBuilder 클래스는 일반적으로 getInstance라고하는 정적 메소드를 정의합니다.이 메소드는 데이터 표현을 지정하는 인수를 취합니다.

Product : 제품 클래스는 데이터 표현 유형을 정의합니다.

### 참고


[Builder pattern 구현](http://ehpub.co.kr/2-%EB%B9%8C%EB%8D%94-%ED%8C%A8%ED%84%B4builder-pattern-%EA%B5%AC%ED%98%84/)
