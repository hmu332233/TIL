# Future

**먼저 교환권을 가져가세요**

### 개요

- client가 다른 쓰레드에 처리를 의뢰하고 그 결과값을 받아야할 때
- 처리를 의뢰한 때에 실행 결과를 기다리고 있다면 응답성이 저하되어 비효율적이다.

- 우선 처리 결과와 같은 인터페이스(API)를 가진 Future를 만들고 처리 개시의 시점에서 Future를 반환값으로 한다.  
 그리고 처리 결과는 나중에 Future에 set한다.  
 이렇게 하면 Client는Future를 경유해서 처리 결과를 좋아하는 타이밍으로 얻는(기다리는)것이 가능한데 이것이 바로 Future 패턴!


---

- 케이크를 사러 빵집에 갔습니다.  
  주문을 하자 주인이 저녁에 찾으러 와주세요 하면서 교환권을 줍니다.  
  저녁이 되어서 교환권을 들고 케이크를 찾으러 갔습니다.  
  주인은 케이크를 건네주었습니다.
  <br/>

- Client는 Requester에게 result를 요청을 합니다.  
  Requester는 Future 객체를 반환합니다.  
  Client가 다른 일을 하는 사이 result를 만들어 Future에 넣어줍니다.  
  Client는 Future 객체를 이용해 나중에 result를 받습니다.  


### 참고

- [Future 패턴 요약](http://starplatina.tistory.com/entry/Future-%ED%8C%A8%ED%84%B4)
- [Future 패턴과 AngularJS](https://okky.kr/article/280628)

### 내용

![1](/assets/future/1.PNG)
![2](/assets/future/2.PNG)
