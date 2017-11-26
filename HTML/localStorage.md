## localStroage

- HTML5에서는 클라이언트에 데이터를 저장하는 2개의 객체를 제공한다.  
하나의 세션 단위로 데이터를 저장하는 SessionStorage 와,  
만료 기간이 없는 LocalStorage 가 있다.  

- 두 가지 모두 key/value 쌍으로 저장하며, 사용 방법은 거의 비슷하다.  

### 사용법
```js
let object = {text:'minung.han'}

//store
localStorage.name = JSON.stringify(object);
//retrieve
JSON.parse(localStorage.name)
//clear
localStorage.clear();
```

- 참고 : [w3schools - html5_webstorage](https://www.w3schools.com/html/html5_webstorage.asp)

- [HTML5 LocalStorage 살펴보기](http://ohgyun.com/417)
