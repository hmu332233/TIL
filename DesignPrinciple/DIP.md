## DIP(의존 역전의 원칙 : Dependency Inversion Principle)
<br/>

> **High-level modules should not depend on low-level modules. Both should depend on abstractions.**  
> 하이 레벨 모듈은 로우 레벨 모듈에 종속되어서는 안된다. 둘 다 추상적인 개념에 의존해야 한다.

>  **Abstractions should not depend on detail. Details should depend on abstraction.**  
> 추상화는 세부사항에 의존하면 안되며, 세부사항이 추상화에 의존해야한다.  
> 추상화에 의존해야지 구체화에 의존하면 안된다.

<br/>

고수준의 객체가 보다 하위 수준의 객체에 의존성을 가지지 않아야 하며,  
반대로 하위 수준의 객체가 보다 높은 추상화 수준의 객체에 의존해야 한다는 것을 의미한다.

<br/>

다시 말해 **구현 클래스가 아닌 인터페이스 타입을 사용하라는 규칙이다.**

<br/>

![DIP](http://i.imgur.com/yLSzyc8.png)

***

#### 핵심
- 구현 클래스는 자주 변경될 가능성이 높기 때문에, 변화 가능성이 상대적으로 적은 추상 타입이나 메서드에 의존하면 변화에 따른 영향을 최소화할 수 있다.
- 같은 개념이면 추상화 클래스를, 다른개념이면 인터페이스를 넣어  
  잦은 수정에도 영향을 받지 않는 방파제와 같은 장점을 취한다.
- **DIP의 포인트는 '수정에도 영향을 받지 않음'**
