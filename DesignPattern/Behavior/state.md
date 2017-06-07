# State

### 개요


![1](/assets/state/main.PNG)

- Client는 Context에게 동일한 request()를 호출하지만 현재 상태(State)에 따라  
  서로 다른 행위가 수행되도록한다.  
- 이때 객체의 상태에 따라 각각의 행위를 변경할 수 있도록 분리하여 캡슐화한다
<br/>

- 동적으로 행동을 교체할 수 있다

```java
main(){

  context.request(); // ConcreateStateA의 Handle 실행
  context.request(); // ConcreateStateB의 Handle 실행

  //사용하는쪽은 동일한 함수를 호출하지만context.request();
  //상태에 따라 실행되는 동작이 다르다.
  //strategy는 내부에서 실행될 객체를 변경하지 않지만
  //state는 내부에서 실행될 객체(상태)를 변경한다는 점에서 다르다.

}
//-------------
class Context{
  State state;
  request(){
    state.handle();
  }
}
//------------
class ConcreteStateA extends State{
  handle(){
    //do something A
    context.setState(new ConcreateStateB());
  }
}
//------------
class ConcreateStateB extends State{
  handle(){
    //do something B
    context.setState(new ConcreateStateA());
  }
}



```

### 참고사이트

- [상태패턴(여기가 제일 이해 잘되는듯. 예제가)](http://copynull.tistory.com/128)

- [Do it now :: 디자인 패턴 state 패턴과 strategy 패턴에 대해....](http://jongyoungcha.tistory.com/entry/%EB%94%94%EC%9E%90%EC%9D%B8-%ED%8C%A8%ED%84%B4-state-%ED%8C%A8%ED%84%B4%EA%B3%BC-strategy-%ED%8C%A8%ED%84%B4%EC%97%90-%EB%8C%80%ED%95%B4)


### 내용

![1](/assets/state/1.jpg)
![1](/assets/state/2.jpg)
![1](/assets/state/3.jpg)
![1](/assets/state/4.jpg)
![1](/assets/state/5.jpg)
![1](/assets/state/6.jpg)
![1](/assets/state/7.jpg)
![1](/assets/state/8.jpg)
