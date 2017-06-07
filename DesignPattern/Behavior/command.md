## Command

### 개요
  - 각 클래스들마다 공통된 기능을 분리하여 관리하고  
    이들의 실행을 관리하는 애를 하나 두어 그 히스토리를 기록해서  
    undo나 redo 같은 기능을 사용할 수 있게하는 패턴
    <br/>

  - 명령어를 처리하는 부분을 객체로 캡슐화 함으로써 실제 내부 구현을 다른 객체로부터 분리하는 것.
  - 명령의 전달 과정에서 여러 다른 요구 사항을 집어 넣을 수 있다.
  - 요청 내역을 큐에 저장하거나 로그로 기록하여(history 관리) 작업취소 등의 기능을 지원 할 수 있게 된다.

### 참고

- [커맨드 패턴(Command Pattern)](http://copynull.tistory.com/142)

### 내용

![1](/assets/command/1.png)
![2](/assets/command/2.png)
![3](/assets/command/3.png)
![4](/assets/command/4.png)
![5](/assets/command/5.png)
![6](/assets/command/6.png)
![7](/assets/command/7.png)
![8](/assets/command/8.png)
![9](/assets/command/9.png)
