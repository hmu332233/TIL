## OCP(개방폐쇄의 원칙 : Open/Close Principle)

> **Software entities should be open for extension, but colsed for modification**  
> 소프트웨어 엔티티들은 확장에 대해서는 열고, 수정에 대해서는 닫아야한다.  

#### 정의

소프트웨어의 구성요소(컴포넌트, 클래스, 모듈, 함수)는 확장에는 열려있고, 변경에는 닫혀있어야 한다는 원리.
요구사항의 변경이나 추가사항이 발생하더라도, 기존 구성요소는 수정이 일어나지 말아야 하며, 기존 구성요소를 쉽게 확장해서 재사용할 수 있어야 한다.

- 새로운 기능은 기존 코드 안에서 최소한의 변경만으로 추가되어야 한다.

![OCP](http://i.imgur.com/gxcCbRl.png)
