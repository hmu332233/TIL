## LSP(리스코브 대체의 원칙 : The Liskov Substitution Principle)


> **Subtypes must be substitutable for their base types**  
> *서브타입이 그들의 베이스 타입을 대체할 수 있어야 한다.*  
> 자식이 부모를 완벽하게 대체 할 수 있어야한다.  

#### 정의

서브 타입은 언제나 베이스 타입과 호환될 수 있어야 한다.  
다시 말해서, **서브 타입은 기반 타입이 약속한 규약(public 인터페이스, 물론 메소드가 던지는 예외까지 포함됩니다.)을 지켜야 한다.**

다형성과 확장성을 극대화 하려면 하위 클래스를 사용하는 것보다는 상위의 클래스(인터페이스)를 사용하는 것이 더 좋다.

![LSP](http://i.imgur.com/C9rl7Nj.png)
