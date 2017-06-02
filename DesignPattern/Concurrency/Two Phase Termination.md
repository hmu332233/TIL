# Two Phase Termination

### 개요

- 이름 그대로 두 단계 종료라는 뜻으로  
  한 작업을 종료시킬때 바로 종료하는 것이 아닌  
  종료 요청을 먼저하고, 그 다음 종료에 필요한 처리를 한 뒤 종료하는 방식의 패턴이다.
  <br/>

- 아래와 같이 종료 요청을 먼저하고 그 뒤에 flag등에 의해서 종료처리를 하는 방식
  ```java
  //진행중인 작업
  try{
    while(shutdownRequested)
      doWork();
  } catch ( final InterruptedException e ){
  } finally {
    doShutdown();
  }
  //종료 요청 - 종료 1단계
  public void requestShutdown(){
    shutdownRequested = true;
  }

  //종료 처리 - 종료 2단계
  public void doShutdown(){
    //do something
  }
  ```


### 내용

![1](/assets/concurrency/1.jpg)
![2](/assets/concurrency/2.jpg)
![3](/assets/concurrency/3.jpg)
![4](/assets/concurrency/4.jpg)
![5](/assets/concurrency/5.jpg)
![6](/assets/concurrency/6.jpg)
