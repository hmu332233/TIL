## Immutable

Immutable : 변경불가능한

### 개요
#### 동시성 문제

![IMMUTABLE](http://i.imgur.com/v31WSmI.png)

- x,y를 동시에 읽어야하는데 x를 읽고 y를 읽는 순간 x,y와 갱신이 되어  
  x와 y의 싱크가 맞지 않는 문제


#### 해결책

1. sync -> 속도 ↓
2. **읽기만 가능하게 변경 -> 새로운 객체 생성**
    - 동기화 문제 해결
    - 단, Garbage가 생성됨


### Immutable이란?

- organizes a class so that the state information of its instances never changes after they are constructed.  
  인스턴스 생성시 상태 정보가 변경되지 않도록 클래스를 구성합니다.


- **다른 여러 오브젝트가 사용하는 값 오브젝트에 대한 변경 사항 동기화를 관리하지 않으려면,**
  - 공유 객체를 불변으로 만들고, 생성 된 후에 상태에 대한 변경을 허용하지 않습니다.
  - 상태 정보를 수정하는 클래스에 생성자 이외의 메소드를 포함하지 않음으로써이 타스크를 수행 할 수 있습니다.


- 포인트는 '**수정시 새로운 객체를 리턴**'

***

![IMMUTABLe2](http://i.imgur.com/Cd6My8Z.png)

- 값을 얻는 `getX()`, `getY()`에 대해서는 허용
- 값을 변경하는 `offset()`에 대해서는 허용하지 않고 새로운 객체를 생성하도록 함 
