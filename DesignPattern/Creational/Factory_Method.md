## Factory Method

### 개요
- 프로그래밍하다 보면 같은 방법으로 사용할 수 있는 여러 종류의 개체를 일반화하여 기반 클래스를 정의하고 이를 기반으로 파생 클래스로 정의하는 것은 매우 흔합니다. 이 경우에 사용하는 곳에서 구체적으로 어떠한 개체를 생성해서 사용할 지에 대하여 개발 초기 단계에서 결정할 수 없다면 어떻게 하면 좋을까요? 팩토리 메서드 패턴을 이용하면 이러한 고민을 해결할 수 있습니다.


- 추상 팩토리 클래스에서는 사용할 개체(추상 클래스)를 생성하는 것에 대해 약속만 합니다. 대신 파생 팩토리 클래스에서 구체적으로 어떠한 개체를 생성할 것인지 구현합니다. 이처럼 구체적인 개체를 생성하는 부분을 분리하면 추상 팩토리 클래스에서는 어떠한 개체를 생성할 것인지에 대한 고민은 뒤로 미루고 개체를 사용하는 부분을 구현할 수 있습니다. 팩토리 메서드란 추상 팩토리 클래스에 약속된 개체를 생성하는 메서드입니다.


![factorymethod](http://i.imgur.com/3Lb4RFP.png)


#### 의도(Intent)
- Define the interface method for creating an object, and delegate it into the subclasses.
  객체를 생성하기 위한 인터페이스 메소드를 정의하고 이것을 서브 클래스에 위임시킵니다.
#### Also Known As
- Virtual Constructor

#### 적용가능성( Applicability )
use this pattern when
- The concrete classes are not defined yet.
- The object creation should be delegated into the subclasses.

언제 이패턴을 사용하는가
- 구체적인 클래스가 아직 정의되지 않았을 때.
- 객체 생성이 서브클래스에 위임되어야 할 때.


```java
class Application
{
  ...생략
  {
    Document doc = createDocument();
  }
}


class DrawingApplication
{
  @override
  Document createDocument(){
    return new DrawingDocument();
  }
}


```
